#pragma once

double norm_fun(double x, double mean, double sd)
{
	// Value of normal distribution function
	// with mean and standard deviation

	if (sd < 0)
		return 0.0; // TODO: error or NAN

	// Нормируем x:
	if (sd == 0)
		sd = 1E-10;
	x = (x - mean) / sd;

	// code from http://www.johndcook.com/cpp_phi.html
	// constants
	double a1 = 0.254829592;
	double a2 = -0.284496736;
	double a3 = 1.421413741;
	double a4 = -1.453152027;
	double a5 = 1.061405429;
	double p = 0.3275911;

	// Save the sign of x
	int sign = 1;
	if (x < 0)
		sign = -1;
	x = fabs(x) / sqrt(2.0);

	// A&S formula 7.1.26 [A&S = Abramowitz & Stegun?]
	double t = 1.0 / (1.0 + p * x);
	double y = 1.0 - (((((a5 * t + a4) * t) + a3) * t + a2) * t + a1) * t * exp(-x * x);

	return 0.5 * (1.0 + sign * y);
}