/* Name: Ermithe Tilusca
Date: 4/2/2025
Assignment: #2
Due Date: 6/23/2025
About this project: This program is used to model complex numbers. 
A complex number is a number  that can be written in the form: z=a+bi 

All work below was performed by Ermithe Tilusca */

#include "complexNum.h"

int main(){
    	// Set both the real number and imaginary number to 0
    	Complex c1;
   	cout << "The default real and imaginary numbers: " << c1 << endl;

    	// Change the real number and leave the imaginary number at 0
    	double imaginaryOnly;
    	cout << "Change the imaginary number: ";
    	cin >> imaginaryOnly;
    	Complex c2(imaginaryOnly);
    	cout << "The imaginary numbers after conversion constructor: " << c2 << endl;

    	// Change the real and imaginary numbers, two new complex numbers
	double real1;
	double imaginary1;
	double real2;
	double imaginary2;

	cout << "The first real number: ";
	cin >> real1;
	cout << "The first imaginary number: ";
	cin >> imaginary1;
	Complex c3(real1, imaginary1);

	cout << "The second real number: ";
	cin >> real2;
	cout << "The second imaginary number: ";
	cin >> imaginary2;
	Complex c4(real2, imaginary2);
    
	cout << "Two parameterized constructor complex numbers: " << c3 << ", " << c4 << endl;

    	// The different operations of the two parameterzed constructors
    	cout << "The sum of the parameterized constructor complex numbers: " << c3 + c4 << endl;
    	cout << "The difference of the parameterized constructor complex numbers: " << c3 - c4 << endl;
    	cout << "The negation of the first parameterized constructor complex number: " << -c3 << endl;
    	cout << "The negation of the second parameterized constructor complex number: " << -c4 << endl;
    	cout << "The product of the parameterized constructor complex numbers: " << c3 * c4 << endl;
    	cout << "The conjugate of the first parameterized complex number: " << c3.conjugate() << endl;
    	cout << "The conjugate of the second parameterized complex number: " << c4.conjugate() << endl;

    	// Equality check, if the two parameterized constructors equal print "yes", else "no"
	cout << "Are the two parameterized contructors equal? " <<  endl;    
	if (c3 == c4){
      	cout << "Yes" << endl;
    	}else{
      	cout << "No" << endl;
    	}
    
    return 0;
}

