//Bridge design pattern:
//A mechanism that decouple interface from implementation

#include <iostream>

struct Renderer
{
	virtual void render_circle(float x, float y, float radius) = 0;
};

struct Vector_renderer : Renderer
{
	void render_circle(float x, float y, float radius) override
	{
		std::cout << "drawind a vector circle of radius " << radius << std::endl;
	}
};

struct Raster_renderer : Renderer
{
    void render_circle(float x, float y, float radius) override
	{
	    std::cout << "rasterizing a vector circle of radius " << radius << std::endl;
	}
};

struct Shape
{
protected:
   Renderer &renderer;

   Shape(Renderer &renderer) : renderer{renderer}{}

public:
    virtual void render() = 0;
    virtual void resize(float factor) = 0;
};

struct Circle : Shape
{
    float x, y, radius;

    void render() override
    {
        renderer.render_circle(x, y, radius);
    }
    void resize(float factor) override
    {
        radius *= factor;
    }

    Circle(Renderer& renderer, float x, float y, float radius)
        : Shape(renderer),
          x(x),
          y(y),
          radius(radius)
    {
    }
};


