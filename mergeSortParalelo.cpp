//Ana Gabrila Argüello, Laura Isabel Olivero, Kevin Perez, Juan Diego Rojas
#include <iostream>
#include <vector>
#include <omp.h>
using namespace std;

void merge(vector<int>& A, const vector<int>& L, const vector<int>& R) {
    vector<int> result;
    int i = 0;
    int j = 0;

    while (i < L.size() && j < R.size()) {
        if (L[i] <= R[j]) {
            result.push_back(L[i]);
            i = i + 1;
        } else {
            result.push_back(R[j]);
            j = j + 1;
        }
    }

    while (i < L.size()) {
        result.push_back(L[i]);
        i = i + 1;
    }

    while (j < R.size()) {
        result.push_back(R[j]);
        j = j + 1;
    }
    A = result;
}

void mergeSort(vector<int>& A) {
    if (A.size() > 1) {
        int mid = A.size() / 2;
        vector<int> left_half(A.begin(), A.begin() + mid);
        vector<int> right_half(A.begin() + mid, A.end());

        #pragma omp parallel sections
        {
            #pragma omp section
            {mergeSort(left_half);}

            #pragma omp section
            {mergeSort(right_half);}
        }
        merge(A, left_half, right_half);
    }
}

int main() {
    vector<int> A = {38, 27, 43, 3, 9, 82, 10};
    mergeSort(A);
    for (int x : A)
        cout << x << " ";
    cout << endl;

    return 0;
}
