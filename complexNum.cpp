#include "complexNum.h"

Complex::Complex(){
    real = 0;
    imaginary = 0;
}

Complex::Complex(double real){
    this->real = real;   // fix this line
    imaginary = 0;
}

Complex::Complex(double real, double imaginary){
    this->real = real;
    this->imaginary = imaginary;
}

Complex Complex::operator+(const Complex& other) const {
    return Complex(real + other.real, imaginary + other.imaginary);
}

Complex Complex::operator-(const Complex& other) const{
    return Complex(real - other.real, imaginary - other.imaginary);
}

Complex operator-(const Complex& a){
    return Complex(-a.real, -a.imaginary);
}

Complex operator*(const Complex& a, const Complex& b){
    double sameTypeNum = a.real * b.real - a.imaginary * b.imaginary;
    double diffTypeNum = a.real * b.imaginary + a.imaginary * b.real;
    return Complex(sameTypeNum, diffTypeNum);
}

Complex Complex::conjugate() const {
    return Complex(real, -imaginary);
}

ostream& operator<<(ostream& o, const Complex& myComplex){
    o << myComplex.real;
    if (myComplex.imaginary < 0)
        o << " - " << -myComplex.imaginary << "i";
    else
        o << " + " << myComplex.imaginary << "i";
    return o;
}

bool operator==(const Complex& a, const Complex& b) {
    return a.real == b.real && a.imaginary == b.imaginary;
}

