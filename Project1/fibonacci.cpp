// fibonacci.cpp
#include <iostream>
using namespace std;
int fibonacci(int n) {
		// �⺻ ���: n�� 0 �Ǵ� 1�� ��
		if (n == 0) return 0;
		if (n == 1) return 1;

		// ��� ȣ���� ���� �Ǻ���ġ ���� ���
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