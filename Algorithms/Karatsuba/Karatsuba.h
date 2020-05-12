#ifndef __KARATSUBA_H__
#define __KARATSUBA_H__

#include <algorithm>

template <typename T>
int getDecimalCount(T a) {
	int c = 0;
	while (a > 0) {
		a /= 10;
		++c;
	}
	return c;
}

template <typename T>
T karatsuba(T a, T b) {
	if (a < 10 && b < 10)
		return a * b;

	T n = std::max(getDecimalCount(a), getDecimalCount(b)) / 2;
	T m = (T)pow(10, n);

	T aH = a / m;
	T aL = a % m;

	T bH = b / m;
	T bL = b % m;

	T H = karatsuba(aH, bH);
	T L = karatsuba(aL, bL);
	T R = karatsuba(aH + aL, bH + bL) - H - L;

	return H * (T)pow(10, 2 * n) + R * m + L;
}

#endif
