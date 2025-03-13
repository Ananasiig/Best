#pragma once

void  __ogg_fdrffti(int n, double* wsave, int* ifac);
void  __ogg_fdrfftf(int n, double* X, double* wsave, int* ifac);

double spect(string& x) {
	double	p_value, upperBound, percentile, N_l, N_o, d, * m = NULL, * X = NULL, * wsave = NULL;
	int		i, count, ifac[15], n = x.length();

	try {
		X = new double[n]();      // Выделение памяти и инициализация нулями
		wsave = new double[2 * n]();
		m = new double[n / 2 + 1]();
	}
	catch (const bad_alloc& e) {
		cerr << "\t\tUnable to allocate working arrays for the DFT: " << e.what() << std::endl;
		delete[] X;     // Освобождение памяти, если она была выделена
		delete[] wsave;
		delete[] m;
		return -1;
	}
	for (i = 0; i < n; i++)
		X[i] = 2 * (x[i]-'0') - 1;

	__ogg_fdrffti(n, wsave, ifac);		/* INITIALIZE WORK ARRAYS */
	__ogg_fdrfftf(n, X, wsave, ifac);	/* APPLY FORWARD FFT */

	m[0] = sqrt(X[0] * X[0]);	    /* COMPUTE MAGNITUDE */

	for (i = 0; i < n / 2; i++)
		m[i + 1] = sqrt(pow(X[2 * i + 1], 2) + pow(X[2 * i + 2], 2));
	count = 0;				       /* CONFIDENCE INTERVAL */
	upperBound = sqrt(3 * n);
	for (i = 0; i < n / 2; i++) {
		if (m[i] < upperBound)
			count++;
	}
//	percentile = (double)count / (n / 2) * 100;
	N_l = (double)count;       /* number of peaks less than h = sqrt(3*n) */
	N_o = (double)0.95 * n / 2.0;
	d = sqrt(N_o*0.05);

	//cout << N_l << ' ' << N_o << ' ' << d << ' ' << (N_l - N_o) / d << endl;
	p_value = 2*(1 - norm_fun(fabs(N_l - N_o)/d, 0, 1));


	delete[] X;     // Освобождение памяти, если она была выделена
	delete[] wsave;
	delete[] m;

	return p_value;
}