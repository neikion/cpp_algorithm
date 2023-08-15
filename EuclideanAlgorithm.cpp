#include "EuclideanAlgorithm.h"
using namespace EUCLIDEAN_ALGORITHM;
int Euclidean::getGreatestCommonDivisor(int a, int b) {
	int result;
	if (b > a) {
		result = a;
		a = b;
		b = result;
	}
	while (b != 0) {
		result = a % b;
		a = b;
		b = result;
	}
	return a;
}