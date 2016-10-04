#include "composite_shapes.h"
#include "test.h"

using namespace composite_shapes;
//each level will contain at max 2 circles and a group
//if circles left they will be put in the last subgroup
struct shape_tree_draw_test
{
    std::vector < std::shared_ptr<Group> >   m_groups;
    std::vector < std::shared_ptr<Circle> >  m_circles;
    std::shared_ptr<Group> m_root;

    shape_tree_draw_test()
    {
        m_root = Build_shape<Group>("root");
    }

    void  build_shape_tree(int nbr_subgroups, int nbr_circles);
    bool is_rendered()
    {
        for (auto& g:m_groups)
        {
            if (g->m_rendered == false)
            {
                return false;
            }
        }

        for (auto& c:m_circles)
        {
            if (c->m_rendered == false)
            {
                return false;
            }
        }

        return true;
    }

};

void 
shape_tree_draw_test::build_shape_tree(int nbr_subgroups, int nbr_circles)
{
    m_groups.push_back(m_root);

    if (nbr_subgroups < 1)
        return;

    for (auto i=1; i < nbr_subgroups;i++)
    {
        std::string name{"sub"};
        name.append(std::to_string(i));
        auto subroot = Build_shape <Group>(name);
        m_groups.push_back(subroot);
    }

    for (auto i=0; i < nbr_circles;i++)
    {
        std::string name{"Circle"};
        name.append(std::to_string(i));
        auto circle = Build_shape <Circle>(name);
        m_circles.push_back(circle);
    }

    for (unsigned i = 0; i < (m_groups.size() - 1); i++)
    {
        m_groups[i]->add_object(m_groups[i + 1]);
    }

    unsigned circle_added = 0;
    for (unsigned i = 0; i< m_groups.size(); i++)
    {
        unsigned circle_per_group = 2;
        while (circle_added < m_circles.size() && (circle_per_group > 0))
        {
            m_groups[i]->add_object(m_circles[circle_added++]);
            circle_per_group--;
        }
    }

    while (circle_added < m_circles.size())
    {
        m_groups.back()->add_object(m_circles[circle_added++]);
    }
}

TEST(draw_test, draw_tree)
{
    shape_tree_draw_test tree;

    tree.build_shape_tree(5, 20);
    tree.m_root->draw();
    EXPECT_EQ(true, tree.is_rendered());
}