#pragma once

double mdu2(int l, string &x) {
	//”—Ћќ¬»я ѕ–»ћ≈Ќ≈Ќ»я: n >= 20 * 2^l (l <= log2(n/20))

	int u = pow(2, l), u2 = u / 2, k;

	if (x.length() < 20 * u) { cout << x.length() << ' ' << 20 * u << '\n'; return -1; }

	vector<int> vec(u), vec1(u2);
	string sub;
	double svalue = 0, gvalue = 0,gvalue2 = 0, n2_l = 1.0 * x.length() / u, n2_l1 = 1.0 * x.length() / u2;

	x = x + x.substr(0, l);

	if (x.length() < 20 * u) { return -1; }
	///частоты l-фрагментов
	//частоты (l-1)-фрагментов
	for (int t = 0; t < x.length()-l+1; t++) {
		k = 0;
		for (int j = 0; j < l; j++) {
			k <<= 1;
			if (x[t + j] == '1')
				k++;
		}
		vec[k]++;

		k = 0;
		for (int j = 0; j < l - 1; j++) {
			k <<= 1;
			if (x[t + j] == '1')
				k++;
		}
		vec1[k]++;
	}


	//вычисление статистики

	for (int i = 0; i < u; i++) {
		gvalue += 1.0 * pow(vec[i] - n2_l, 2);
		//		cout << vec[i]<< ' ' << vec1[i] << endl;
	}
	gvalue /= n2_l;

	for (int i = 0; i < u2; i++) {
		gvalue2 += 1.0 * pow(vec1[i] - n2_l1, 2);
	}
	gvalue2 /= n2_l1;

	svalue = gvalue - gvalue2;
		//возвращаем P-значение
	return 1 - gamain(svalue/2, 0.5*u2, 1);
}
