#include "utils.hpp"

int fatorial(int number){
    return (number==0) || (number==1) ? 1 : number* fatorial(number-1);
}

std::vector<int> nth_permutation(std::vector<int> elements, int perm_num) {
    if(elements.size() == 1)
        return elements;

    long int sizeGroup = fatorial(elements.size()-1);
    int q = (int) perm_num / sizeGroup;
    int r = perm_num % sizeGroup;

    int v = elements.at(q);
    elements.erase(elements.begin()+q);

    std::vector<int> vec = nth_permutation(elements, r);
    vec.push_back(v);

    return vec;

}
