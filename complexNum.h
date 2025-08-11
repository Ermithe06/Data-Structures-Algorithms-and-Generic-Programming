#include <iostream>

using namespace std;

class Complex {
	friend Complex operator-(const Complex& a);
	friend Complex operator*(const Complex& a, const Complex& b);
	friend ostream& operator<<(ostream& o, const Complex& myComplex);
	friend bool operator==(const Complex& a, const Complex& b);
	
	
	public:
		Complex();
		Complex(double real);
		Complex(double real, double imaginary);
		Complex operator+(const Complex& other)const;
		Complex operator-(const Complex& other) const;
		Complex conjugate() const;
		

	private:
		double real;
		double imaginary;
};
