//Ana Gabrila Argüello, Laura Isabel Olivero, Kevin Perez, Juan Diego Rojas
#include <stdio.h>
#include <iostream>
#include <omp.h>
#include <vector>
using namespace std;


int main(){
    vector<int> vec = {1,2,4,3,7,6,5};
    int i, j,tmp;
    int N = 7;
    bool sorted = false;
    while (sorted == false){
        sorted = true;
        #pragma omp parallel for
        for (j=1;j< N-1;j+=2){
            if (vec[j] > vec[j+1]){
                swap(vec[j], vec[j+1]);
                sorted = false;
            
            }
        }

        #pragma omp parallel for
        for (j=0; j < N-1;j+=2){
            if (vec[j] > vec[j+1]){
                swap(vec[j], vec[j+1]);
                sorted = false;
            }
        }
        
    }

    for (i=0;i< N;i++){
        cout << vec[i];
    }

    return 0;
}
