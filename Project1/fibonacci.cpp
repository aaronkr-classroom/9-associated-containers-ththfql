// fibonacci.cpp
#include <iostream>
using namespace std;
int fibonacci(int n) {
		// 기본 사례: n이 0 또는 1일 때
		if (n == 0) return 0;
		if (n == 1) return 1;

		// 재귀 호출을 통해 피보나치 수열 계산
		return fibonacci(n - 1) + fibonacci(n - 2);
	}



int main() {
	int num;
	cout << "Enter n for a Fibbonaci series: ";
	cin >> num;
	cout << "Fibonacci at " << num << " is "\
		<< fibonacci(num) << endl;
	return 0;

}