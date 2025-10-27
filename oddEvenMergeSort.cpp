#include <iostream>
#include <algorithm>

void oddEven_merge(int A[], int low, int n, int r){
    int step = r * 2;
    if (step < n)
    {
        oddEven_merge(A, low, n, step);
        oddEven_merge(A, low + r, n, step);
        for (int i = low + r; i + r < low + n; i += step)
        {
            if (A[i] > A[i + r]){
                std::swap(A[i], A[i + r]);
            }
        }
    }
    else{
        if (A[low] > A[low + r])
        {
            std::swap(A[low], A[low + r]);
        }
    }
}

void oddEven_mergeSort(int A[], int low, int high){
    int n = high - low + 1;
    if (n > 1){
        int mid = (low + high) / 2;
        oddEven_mergeSort(A, low, mid);
        oddEven_mergeSort(A, mid + 1, high);
        oddEven_merge(A, low, high - low + 1, 1);

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
    
    oddEven_mergeSort(A, 0, n - 1);

    for(int i = 0; i < n; i++)
    {
        std::cout << A[i] << " ";
    }
}