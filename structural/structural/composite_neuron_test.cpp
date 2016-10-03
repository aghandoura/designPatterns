#include "composite_neuron.h"
#include "test.h"



TEST(neuron_test, connection)
{
    Neuron n1, n2, n3;
    Neuron_layer l1{ 4 };
    Neuron_layer l2{ 5 };
    Neuron_layer l3{ 6 };
    Neuron_layer l4{ 5 };
    Neuron_layer l5{ 5 };

    //neuron to neuron
    n1.connect_to(n2);

    EXPECT_EQ(n1.out[0]->id, n2.id);
    EXPECT_EQ(n2.in[0]->id, n1.id);

    //neuron to layer 
    n3.connect_to(l3);

    int count = 0;
    for (auto& n:l3)
    {
        EXPECT_EQ(n3.out[count]->id, n.id);
        EXPECT_EQ(n.in[0]->id, n3.id);
        count++;
    }

    //layer to layer 
    l4.connect_to(l5);
    for (auto& n:l4)
    {
        count = 0;
        for (auto& m:l5)
        {
            EXPECT_EQ(n.out[count]->id, m.begin()->id);
            count++;
            //......
        }
    }
}
