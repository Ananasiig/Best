#pragma once
#include <cmath>
#include <vector>

// Function to perform Fast Discrete Fourier Transform
void ogg_fdrfftf(int n, double* x, double* wsave, int* ifac) {
    // Ensure the input parameters are valid
    if (n <= 0 || x == nullptr || wsave == nullptr || ifac == nullptr) {
        return;
    }

    // Initialize variables
    int i, j, k, m;
    double t1, t2, u1, u2, z;

    // Perform the FDFT
    for (i = 0; i < n; ++i) {
        wsave[i] = x[i];
    }

    for (i = 0; i < n; ++i) {
        x[i] = 0.0;
    }

    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            t1 = 2.0 * M_PI * i * j / n;
            x[i] += wsave[j] * cos(t1) - wsave[j] * sin(t1);
        }
    }

    // Store the factors
    for (i = 0; i < n; ++i) {
        ifac[i] = i;
    }
}
