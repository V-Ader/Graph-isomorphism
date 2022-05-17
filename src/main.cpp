#include <iostream>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <omp.h>

#include "graph.hpp"
#include "utils.hpp"


Graph make_isomorfic_graph(Graph const &g){
    Graph ret = Graph(g.getSize(), false);

    std::vector<int> ids;
    std::vector<int> permutation;

    for(int i = 0; i < g.getSize(); ++i){
        ids.push_back(i);
    }

    permutation = nth_permutation(ids, rand() % fatorial(ids.size())); //change that 1.

    for(int i = 0; i < g.getSize(); ++i){
        for(int j = 0; j < g.getSize(); ++j){
            ret.setConnection(permutation.at(i), permutation.at(j), g.getConnection(i, j));
        }
    }

    return ret;
}

int main(){
    srand(time(NULL));

    double pswtime, pewtime;
    bool ans;

    int N = 10;
    Graph g1 = Graph(N);
    Graph g2 = make_isomorfic_graph(g1);

    g1.printGraph();
    g2.printGraph();

    pswtime = omp_get_wtime();
    ans = g1.isIsomorfic(g2);
    pewtime = omp_get_wtime();   

    std::cout << "czas szeregowy: " << pewtime-pswtime <<std::endl;


    pswtime = omp_get_wtime();
    ans = g1.isIsomorficParallel(g2);
    pewtime = omp_get_wtime();   

    std::cout << "czas równoległy: " << pewtime-pswtime <<std::endl;

    
    if(ans){
        std::cout << "ok" << std::endl;
    }

    




    // #pragma omp parallel num_threads(4) private(permutation) shared(ids)
    // {
    //     #pragma omp for
    //     for(int k = 0; k < fatorial(ids.size()); ++k){
    //         permutation = nth_permutation(ids, k);

    //         Graph g3 = g2;

    //         for(int i = 0; i < N; ++i){
    //             for(int j = 0; j < N; ++j){
    //                 g3.setConnection(permutation.at(i), permutation.at(j), g2.getConnection(i, j));
    //             }
    //         }


            
    //     }
    // }
}