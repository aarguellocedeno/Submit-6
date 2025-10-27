#include <iostream>
#include <algorithm>

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

void quickSort(int A[], int low, int high){
    int pivotIndex;
    if (low < high){
        pivotIndex = partition(A, low, high);
        quickSort(A, low, pivotIndex - 1);
        quickSort(A, pivotIndex + 1, high);
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
    
    quickSort(A, 0, n);

    for(int i = 0; i < n; i++)
    {
        std::cout << A[i];
    }
}