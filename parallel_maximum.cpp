#include <iostream>
#include <vector>
#include <omp.h>
using namespace std;

int parallel_max(vector<int>& A) {
    int N = A.size();
    int step = 1;

    while (step < N) {
        #pragma omp parallel for
        for (int i = 0; i < N; i += 2 * step) {
            if (i + step < N) {
                A[i] = max(A[i], A[i + step]);
            }
        }
        step *= 2;
    }

    return A[0];
}

int main() {
    vector<int> A = {3, 7, 5, 6, 3, 1, 2, 4};

    int max_value = parallel_max(A);

    cout << "El valor máximo es: " << max_value << endl;

    return 0;
}
