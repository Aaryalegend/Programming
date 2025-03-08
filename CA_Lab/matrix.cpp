#include <iostream>
#include <omp.h>
#include <vector>

#define SIZE 1024

using namespace std;

int main() {
    vector<vector<double>> A(SIZE, vector<double>(SIZE));
    vector<vector<double>> B(SIZE, vector<double>(SIZE));
    vector<vector<double>> C(SIZE, vector<double>(SIZE, 0.0));

    // Initialize matrices A and B
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            A[i][j] = static_cast<double>(i + j);
            B[i][j] = static_cast<double>(i - j);
        }
    }

    double start_time, end_time;

    // Matrix-Matrix Multiplication using OpenMP
    for (int threads = 1; threads <= 16; threads += 2) {
        omp_set_num_threads(threads);

        start_time = omp_get_wtime();

        #pragma omp parallel for
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int k = 0; k < SIZE; k++) {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }

        end_time = omp_get_wtime();
        cout << "Threads: " << threads << " Time: " << end_time - start_time << " seconds" << endl;
    }

    return 0;
}