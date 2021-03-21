/**
 * Cubes.
 */

#include "olap/VCube.hpp"
#include "olap/ECube.hpp"
#include "olap/op/slicing.hpp"
#include "olap/op/UniformTemporalDiscretization.hpp"
#include "olap/time.hpp"
#include "networks/Network.hpp"
#include "core/attributes/conversion.hpp"

using namespace uu::net;
using namespace uu::core;



void
vcube_example()
{
    auto V = std::make_unique<VCube>("V");
    
    // Set functionality
            
    auto v1 = V->add("v1"); // v1 has type const Vertex*
    V->size(); // 1
    V->contains(v1); // true
    V->contains("v1"); // true
    V->at(0); // v1
    V->get("v1"); // v1
    V->get_at_random(); // v1
    V->index_of(v1); // 0
    V->erase(v1); // true
    V->erase("v1"); // false

    auto v2_sharedptr = std::make_shared<const Vertex>("v2");
    auto v2 = v2_sharedptr.get();
    V->add(v2); // v2
    
    // Attribute functionality
    
    auto attr = V->attr(); // AttributeStore<Vertex>*
    attr->add("A", AttributeType::DOUBLE); // const Attribute*
    attr->set_double(v2, "A", 3.14); // void
    attr->get_double(v2, "A"); // object of type Value<double>
    
    // Cube functionality
    
    V->order(); // 0
    V->dsize(); // {}
    V->dimensions(); // {}
    V->members(); // {}
    
    V->add_dimension("d1", {"m11", "m12", "m13"});
    V->add_dimension("d2", {"m21", "m22"});
    V->order(); // 2
    V->dsize(); // {3, 2}
    V->dimensions(); // {"d1", "d2"}
    V->members(); // {{"m11", "m12", "m13"}, {"m21", "m22"}}
    
    auto index = std::vector<std::string>({"m12", "m21"});
    V->cell(index)->add("v3");
    V->cell(index)->add("v4");
    V->size(); // 3 (v2, v3, v4)
    
}



void
ecube_example()
{
    // creating two vertex cubes
    auto vc1_up = std::make_unique<VCube>("V1");
    auto vc2_up = std::make_unique<VCube>("V2");
    auto vc1 = vc1_up.get(); // VCube*
    auto vc2 = vc2_up.get(); // VCube*

    auto d = EdgeDir::DIRECTED; // or UNDIRECTED (default)
    auto nl = LoopMode::DISALLOWED; // or ALLOWED (default)
    auto E = std::make_unique<ECube>("E", vc1, vc2, d, nl);

    auto v1 = vc1->add("v1");
    vc2->add(v1);
    
    auto e1 = E->add(v1, vc1, v1, vc2);
    E->size(); // 1
    E->contains(e1); // true
    E->contains(v1, vc1, v1, vc2); // true
    E->get(v1, vc1, v1, vc2); // e1
    E->get_at_random(); // e1
    E->at(0); // e1
    E->index_of(e1); // 0
    E->erase(e1); // true
}

void
model_definition_example()
{
    /******************************************/
    /** simple graph                         **/
    /******************************************/
    {
        auto V = std::make_unique<VCube>("V");
        auto E = std::make_unique<ECube>("E", V.get(), V.get(), EdgeDir::UNDIRECTED, LoopMode::DISALLOWED);
        
        // adding vertices
        auto v1 = V->add("v1");
        auto v2 = V->add("v2");
        auto v3 = V->add("v3");
        
        //adding edges
        E->add(v1, v3);
        E->add(v2, v3);
        
        auto g = std::make_unique<Network>("G", std::move(V), std::move(E));
        
        // summary
        std::cout << "Simple graph with " << g->vertices()->size() << " vertices and " << g->edges()->size() << " edges:" << std::endl;
        std::cout << "V: { ";
        for (auto v: *g->vertices()) std::cout << v->name << " ";
        std::cout << "}" << std::endl;
        std::cout << "E: { ";
        for (auto e: *g->edges()) std::cout << (*e) << " ";
        std::cout << "}" << std::endl;
        std::cout << std::endl;
    }
    
    /******************************************/
    /** (undirected) multiplex network       **/
    /******************************************/
    {
        auto A = std::make_unique<VCube>("A");
        auto E = std::make_unique<ECube>("E", A.get(), A.get());
        E->add_dimension("rel-type", {"friend", "work", "coauthor"});
        
        // adding actors
        auto alice = A->add("Alice");
        auto bob = A->add("Bob");
        auto mirka = A->add("Mirka");
        
        // adding edges
        E->cell({"friend"})->add(alice, bob);
        E->cell({"work"})->add(alice, bob);
        E->cell({"coauthor"})->add(alice, bob);
        E->cell({"friend"})->add(alice, mirka);
        
        // summary
        std::cout << "Multiplex network with " << A->size() << " actors and " << E->size() << " edges:" << std::endl;
        std::cout << "A: { ";
        for (auto a: *A) std::cout << a->name << " ";
        std::cout << "}" << std::endl;
        for (std::string edge_type: E->members("rel-type"))
        {
            std::cout << "E (" << edge_type << "): { ";
            for (auto e: *E->cell({edge_type})) std::cout << (*e) << " ";
            std::cout << "}" << std::endl;
        }
        std::cout << std::endl;
    }
    
    /******************************************/
    /** (undirected) multirelational network **/
    /******************************************/
    auto A = std::make_unique<VCube>("A");
    auto E_friend = std::make_unique<ECube>("friend", A.get(), A.get());
    auto E_work = std::make_unique<ECube>("work", A.get(), A.get());
    auto E_coauthor = std::make_unique<ECube>("coauthor", A.get(), A.get());
    
    
    /******************************************/
    /** generalized multiplex network        **/
    /******************************************/
    {
        auto A = std::make_unique<VCube>("A");
        A->add_dimension("actor-type", {"facebook", "offline"});
        auto facebook = vslice("facebook", A.get(), {{0}});
        auto offline = vslice("offline", A.get(), {{1}});
        auto E_work = std::make_unique<ECube>("work", offline.get(), offline.get());
        auto E_friend = std::make_unique<ECube>("friend", offline.get(), offline.get());
        auto E_fbfriend = std::make_unique<ECube>("facebook", facebook.get(), facebook.get());
        
        // adding actors
        auto alice2 = A->add("Alice");
        auto bob2 = A->add("Bob");
        auto mirka2 = A->cell({"offline"})->add("Mirka");
        
        // adding edges
        E_friend->add(alice2, bob2);
        E_friend->add(alice2, mirka2);
        E_fbfriend->add(alice2, bob2);
        
        // summary
        std::cout << "Generalized multiplex network with " << A->size() << " actors" << std::endl;
        std::cout << "A: { ";
        for (auto a: *A) std::cout << a->name << " ";
        std::cout << "} of which:" << std::endl;
        for (std::string actor_type: A->members("actor-type"))
        {
            std::cout << " (" << actor_type << "): { ";
            for (auto a: *A->cell({actor_type})) std::cout << a->name << " ";
            std::cout << "}" << std::endl;
        }
        auto edges = {E_friend.get(), E_work.get(), E_fbfriend.get()};
        for (auto E: edges)
        {
            std::cout << "E (" << E->name << "): { ";
            for (auto e: *E) std::cout << (*e) << " ";
            std::cout << "}" << std::endl;
        }
        std::cout << std::endl;
    
        /******************************************/
        /** general multilayer network       **/
        /******************************************/
        // making it a general multilayer
        auto IE = std::make_unique<ECube>("friend", offline.get(), facebook.get());
        
        auto e1 = IE->add(alice2, offline.get(), bob2, facebook.get());
        auto e2 = IE->add(bob2, offline.get(), alice2, facebook.get());
        auto e3 = IE->add(mirka2, offline.get(), bob2, facebook.get());

        std::cout << "Interlayer edges: {";
        for (auto e: *IE) std::cout << (*e) << " ";
        std::cout << "}" << std::endl;
        std::cout << std::endl;
        
        
        /******************************************/
        /** general. temporal multilayer network **/
        /******************************************/
        
        // making it a temporal multilayer
        make_temporal(IE.get());
        add_time(IE.get(), e1, to_time("1970-01-01 01:01:07+0000"));
        add_time(IE.get(), e1, to_time("1970-01-02 07:21:07+0000"));
        add_time(IE.get(), e2, to_time("1970-01-02 13:09:05+0000"));
        add_time(IE.get(), e3, to_time("1970-01-03 14:01:07+0000"));
        
        Time min = to_time("1970-01-01 00:00:00+0000");
        Time max = to_time("1970-01-03 23:59:59+0000");
        auto d = UniformTemporalDiscretization<ECube>(IE.get(), min, max, 3);
        // with temporal slices @todo add discretizaion function
        IE->add_dimension("time-slice", {"day1", "day2", "day3"}, d);
        
        for (size_t i = 0; i < 3; i++)
        {
            std::cout << "day " << (i+1) << ": " << IE->cell({i})->size() << std::endl;
        }
        
    }
    
    /******************************************/
    /** general. temporal multilayer network **/
    /******************************************/
}

int
main()
{
    
    vcube_example();
    ecube_example();
    model_definition_example();
    
    
    return 0;
}

