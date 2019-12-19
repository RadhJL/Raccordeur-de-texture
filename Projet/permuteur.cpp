#include "permuteur.h"
#include <iterator>
#include <algorithm>
#include <iostream>

Permuteur::Permuteur(int max){
    for(int i =0; i < max; ++i)
        indices.push_back(i);
    this->i_perm = 0;
    this->max = max;
}   

Permuteur::~Permuteur() {
    delete this;

}

int Permuteur::suivant(){
    if(i_perm >= max-1){
        std::next_permutation(indices.begin(),indices.end());
        this->i_perm = 0;
    }
    int r = indices.at(i_perm);
    this->i_perm++;
    return r;
}



