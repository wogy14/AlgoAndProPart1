#include <iostream>
#include <stdarg.h>
using namespace std;
int sum(int n, ...) {
	va_list ptr;
	va_start(ptr, n);
	int sum = 0, dob = va_arg(ptr, int);
	for (int i = 1; i < n;i++ ) {
		int a = va_arg(ptr, int);
		dob *= a;
		sum += dob;
		dob = a;
	}
	va_end(ptr);
	return sum;
}

int main() {
	cout << "Sum1: " << sum(5,1,2,3,4,5) << "\n" << "Sum2: " << sum(10, 1,2,3,4,5,6,7,8,9,10) << "\n" << "Sum3: " << sum(12, 10, 2, 3, 4, 5,8,9,15,45,12,14,18) << "\n";
	system("pause");
	return 0;
}