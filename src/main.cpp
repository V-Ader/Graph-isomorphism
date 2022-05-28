#include <iostream>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <omp.h>
#include <fstream>

#include <sstream>


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

int main(int argc, char** argv){

    if(argc < 3){
        std::cout << "user arguments: N, num_threads" << std::endl;
        return 0;
    }

    srand(time(NULL));

    double pswtime, pewtime;
    bool ans;

    std::ofstream file;
    file.open("measurements.txt", std::ios::app | std::ios::out);

    std::istringstream ss(argv[1]);
    int N;
    ss >> N;

    std::istringstream ss2(argv[2]);
    int num_th;
    ss2 >> num_th;
    
    Graph g1 = Graph(N, num_th);
    Graph g2 = make_isomorfic_graph(g1);

    g1.printGraph();
    g2.printGraph();

    pswtime = omp_get_wtime();
    ans = g1.isIsomorfic(g2);
    pewtime = omp_get_wtime();   

    file << "Config: " << N << " " << num_th << std::endl;
    std::cout << "czas szeregowy: " << pewtime-pswtime <<std::endl;
    file << pewtime-pswtime << std::endl;

    pswtime = omp_get_wtime();
    ans = g1.isIsomorficParallel(g2);
    pewtime = omp_get_wtime();   

    std::cout << "czas równoległy: " << pewtime-pswtime <<std::endl;
    file << pewtime-pswtime << std::endl;
    
    if(ans){
        std::cout << "ok" << std::endl;
    }

    file.close();

    return 0;
}