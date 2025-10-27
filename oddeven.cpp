#include <iostream>
#include <omp.h>

int main(){
    int n;
    std::cin >> n;
    int A[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> A[i];
    }
    bool sorted = false;
    
    while (!sorted){
        sorted = true;
        bool mark = false;
        //odd
        #pragma parallel for shared(A)
        for (int i = 1; i < n; i+=2){
            if (A[i] > A[i + 1]){
                int tmp = A[i];
                A[i] = A[i + 1];
                A[i + 1] = tmp;
                mark = true;
            }
        }
        //even
        #pragma parallel for shared(A)
        for (int i = 0; i < n; i+=2){
            if (A[i] > A[i + 1]){
                int tmp = A[i];
                A[i] = A[i + 1];
                A[i + 1] = tmp;
                mark = true;
            }
        }
        if (mark){
            sorted = false;
        }
    }

    for(int i = 0; i < n; i++)
    {
        std::cout << A[i];
    }
}