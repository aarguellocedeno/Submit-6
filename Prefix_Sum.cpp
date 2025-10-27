//Ana Gabrila Argüello, Laura Isabel Olivero, Kevin Perez, Juan Diego Rojas

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/*
2️. Pseudo codigo:

Upsweep: Durante el upsweep, se acumulan sumas parciales hacia la raíz del árbol.

for d = 0 to log2(n) - 1 do in parallel
    for k = 0 to n-1 by 2^(d+1) do
        A[k + 2^(d+1) - 1] = A[k + 2^d - 1] + A[k + 2^(d+1) - 1]

Downsweep: se redistribuyen los resultados acumulados para construir la suma prefija final.

A[n - 1] = 0
for d = log2(n) - 1 downto 0 do in parallel
    for k = 0 to n-1 by 2^(d+1) do
        t = A[k + 2^d - 1]
        A[k + 2^d - 1] = A[k + 2^(d+1) - 1]
        A[k + 2^(d+1) - 1] = t + A[k + 2^(d+1) - 1]

3️. Synchronization steps:
----------------------------------
Cada nivel del árbol de reducción requiere una sincronización entre los hilos antes de pasar al siguiente nivel.
Como el árbol tiene log₂(N) niveles, el número total de pasos de sincronización necesarios es:
Total steps = O(log N)
------------------------------------------------------------
*/

void parallelPrefixSum(vector<int>& A) {
    int n = A.size();
    int levels = log2(n);
    for (int d = 0; d < levels; d++) {
        int step = 1 << (d + 1);
        #pragma omp parallel for  
        for (int i = step - 1; i < n; i += step) {
            A[i] += A[i - (step >> 1)];
        }
    }

    A[n - 1] = 0;

    for (int d = levels - 1; d >= 0; d--) {
        int step = 1 << (d + 1);

        #pragma omp parallel for  
        for (int i = step - 1; i < n; i += step) {
            int t = A[i - (step >> 1)];
            A[i - (step >> 1)] = A[i];
            A[i] += t;
        }
    }
}

int main() {
    vector<int> A = {2, 4, 1, 7, 3, 0, 4, 2};

    cout << "Input array A: ";
    for (int x : A) cout << x << " ";
    cout << endl;

    parallelPrefixSum(A);

    cout << "Prefix sum P:  ";
    for (int x : A) cout << x << " ";
    cout << endl;

    return 0;
}