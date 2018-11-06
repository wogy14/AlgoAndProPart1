#include <iostream>
using namespace std;
typedef struct complex{
	int real;
	int imagine;
}complex;
int Dmult(int a,int b) {
	return a * b;
}
complex Dmult(complex a,complex b) {
	complex mult;
	mult.real = a.real*b.real - a.imagine*b.imagine;
	mult.imagine = a.real*b.imagine + b.real*a.imagine;
	return mult;
}
int main() {
	complex a,b,mult;
	a.real = 2;
	a.imagine = 3;
	b.real = 6;
	b.imagine = 5;
	mult = Dmult(a, b);
	cout << "Complex: " << mult.real << " + " << mult.imagine << "i \n" << "Decimal number: " << Dmult(10,5) << "\n";
	system("pause");
	return 0;
}