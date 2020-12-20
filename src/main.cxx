#include "io/read_multilayer_network.hpp"
#include "community/glouvain2.hpp"
#include "community/mimag_approximation/mimag_approx.hpp"
#include "community/ml-cpm.hpp"
#include "community/mimag_approximation/mimag_approx_mlcpm.hpp"
#include <typeinfo>
#include <chrono>
using namespace std::chrono;


int
main()
{

    std::cout << "Reading network..." << std::endl;
    auto z = uu::net::read_attributed_homogeneous_multilayer_network("../community/mimag_approximation/test_sets/aucs.txt", "aucs", ',');

    std::cout << "Running a clustering algorithm from the library..." << std::endl;


    std::cout << "Start test: " << std::endl;
    auto start = high_resolution_clock::now();

    //auto clustering = uu::net::glouvain2(z.get(), 1.0);
    //auto clustering = uu::net::mlcpm(z.get(),4,2);
    auto clustering = uu::net::mimag_approx_mlcpm(z.get(),3,3);
    size_t c_id = 0;
    for (auto cluster: *clustering)
    {
        std::cout << std::endl << "COMNUNITY " << (c_id++) << std::endl;

        for (auto vl: *cluster)
        {
            std::cout << (vl.v->name) << "@" << (vl.l->name) << std::endl;
        }
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    std::cout << "End test " << std::endl;
    std::cout << "Time: " << duration.count() << "microseconds" << std::endl;


    //auto m = uu::net::read_attributed_homogeneous_multilayer_network("../aucs.txt", "aucs", ',');
    //auto m = uu::net::read_attributed_homogeneous_multilayer_network("../testy.txt", "testy", ',');


    std::cout << "mimag_approx" << std::endl;
    std::cout << "---" << std::endl;


    auto cliquez = uu::net::mimag_approx(z.get(),3,3);
    // print cliques


    for (auto c: cliquez)
    {
        std::cout << c->to_string() << std::endl;

    };

    std::cout << cliquez.size() << std::endl;



    return 0;
}
