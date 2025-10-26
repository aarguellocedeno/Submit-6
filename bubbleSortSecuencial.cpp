//Ana Gabrila Argüello, Laura Isabel Olivero, Kevin Perez, Juan Diego Rojas
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;


int main(){
    vector<int> vec = {38, 27, 43, 3, 9, 82, 10};
    int i, j,tmp;
    int N = vec.size();
    for (i=0;i< N;i++){
        for (j=0; j < N;j++){
            if (vec[j] > vec[j+1]){
                tmp = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = tmp;
            }
        }
    }
    for (i=0;i< N;i++){
        cout << vec[i];
    }
    return 0;
}

