#pragma once
#include <iostream>
#include <memory>
#include <vector>

struct GraphicShape
{
    std::string shape_name;
    bool m_rendered;

    explicit GraphicShape (const std::string& name)
        :shape_name{name}
        ,m_rendered{false}
    {
    }
    GraphicShape()
        :m_rendered{false}
    {}
    virtual void draw() = 0;

};

struct Circle : GraphicShape
{
    explicit Circle(const std::string &name)
        :GraphicShape(name)
    {}

    Circle()
        :GraphicShape("circle")
    {}


    void draw() override
    {
        std::cout << " draw " << shape_name.c_str();
        m_rendered = true;
    }

};

struct Group : GraphicShape
{
    std::vector<std::shared_ptr<GraphicShape>> v;

    explicit Group(const std::string &name)
          :GraphicShape(name)
    {}

    Group()
      :GraphicShape("")
    {}

    template<typename T>
    void add_object(std::shared_ptr<T> &p)
    {
        v.push_back(p);
    }


    void draw() override
    {
       for (auto& a : v)
        {
//Bug here            a->draw();
        }
       std::cout << std::endl << "------" << std::endl;
        m_rendered = true;
    }
};

template<typename T>
std::shared_ptr<T> Build_shape(const std::string& name)
{
    return{ std::make_shared<T>(T(name)) };
}



