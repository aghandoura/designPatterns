#pragma once
#include <memory>
#include <vector>
#include <ostream>


struct Neuron
{
    std::vector<Neuron*> in, out;
    int id;
    //static for testing only could be in constructor

    Neuron()
    {
        static int count;
        this->id = count++;
    }

    Neuron* begin() { return this; }
    Neuron* end() { return this + 1; }
    void connect_to(Neuron& other_neuron)
    {
        out.push_back(&other_neuron);
        other_neuron.in.push_back(this);
    }

    template <typename T>
    void connect_to(T& other)
    {
        for (Neuron& target : other)
            connect_to(target);
    }

    friend std::ostream& operator<<(std::ostream& os, const Neuron& other)
    {
        for (Neuron* n : other.in)
            os << n->id << "\t-->\t[" << other.id << "]" << std::endl;

        for (Neuron* n : other.out)
            os << "["<< other.id << "]" <<"\t-->\t" << n->id << std::endl;

        return os;
    }
};

struct Neuron_layer : std::vector<Neuron>
{
   Neuron_layer(int count)
   {
      while(count --> 0)
      {
          emplace_back(Neuron{});
      }
   }

   template<typename T>
   void connect_to(T& other)
   {
       for (Neuron& from : *this)
           for (Neuron& to : other)
               from.connect_to(to);
   }

    friend std::ostream& operator<<(std::ostream& os, const Neuron_layer& other)
    {
        for (auto& n : other)
            os << n;

        return os;
    }
};