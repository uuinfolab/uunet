#ifndef UU_TEST_CORE_OLAP_DISCRETIZATION_H_
#define UU_TEST_CORE_OLAP_DISCRETIZATION_H_

#include "objects/Vertex.hpp"
#include "objects/Edge.hpp"

class CustomEdgeDiscretization
{
  public:
    std::vector<bool>
    operator()(const uu::net::Edge* e) const
    {
        if (e->v1->name == "v1" && e->v2->name == "v1") return std::vector<bool>({false, true});
        else if (e->v1->name == "v1" && e->v2->name == "v2") return std::vector<bool>({true, true});
        else return std::vector<bool>({false, false});
    }
};

class CustomVertexDiscretization
{
  public:
    std::vector<bool>
    operator()(const uu::net::Vertex* v) const
    {
        if (v->name == "v1") return std::vector<bool>({false, true});
        else if (v->name == "v2") return std::vector<bool>({true, true});
        else return std::vector<bool>({false, false});
    }
};


#endif
