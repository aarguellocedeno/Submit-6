#include <iostream>
#include <algorithm>
#include <omp.h>

int partition(int A[], int low, int high){
    int pivot;
    int i;
    pivot = A[high];
    i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (A[j] <= pivot)
        {
            i += 1;
            std::swap(A[i], A[j]);
        }
    }
    std::swap(A[i + 1], A[high]);
    return i + 1;
}

void parallelQuickSort(int A[], int low, int high){
    int pivotIndex;
    if (low < high){
        pivotIndex = partition(A, low, high);

        #pragma omp task shared(A)
        parallelQuickSort(A, low, pivotIndex - 1);
        
        #pragma omp task shared(A)
        parallelQuickSort(A, pivotIndex + 1, high);

        #pragma omp taskwait
    }
}

int main(){
    int n;
    std::cin >> n;
    int A[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> A[i];
    }
    
    #pragma omp parallel
    {
        #pragma omp single
        parallelQuickSort(A, 0, n);
    }

    for(int i = 0; i < n; i++)
    {
        std::cout << A[i] << " ";
    }
}