#include <iostream>
#include <omp.h>

int main() {
    int n;
    std::cin >> n;
    int A[n];
    
    for (int i = 0; i < n; i++) {
        std::cin >> A[i];
    }

    bool sorted = false;

    while (!sorted) {
        sorted = true;
        bool mark = false;

        //odd
        #pragma omp parallel for shared(A) reduction(||:mark)
        for (int i = 1; i < n - 1; i += 2) {
            if (A[i] > A[i + 1]) {
                std::swap(A[i], A[i + 1]);
                mark = true;
            }
        }

        //even
        #pragma omp parallel for shared(A) reduction(||:mark)
        for (int i = 0; i < n - 1; i += 2) {
            if (A[i] > A[i + 1]) {
                std::swap(A[i], A[i + 1]);
                mark = true;
            }
        }

        if (mark) sorted = false;
    }

    for (int i = 0; i < n; i++) {
        std::cout << A[i] << " ";
    }

    return 0;
}
