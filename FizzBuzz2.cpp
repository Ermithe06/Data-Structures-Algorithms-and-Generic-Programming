/* Name: Ermithe Tilusca
Date: 5/19/2025
Assignment: #0
Due Date: 5/28/2025
About this project: A program that has configurable calculations. 
It will should take three numbers from the user. The first is the (inclusive) maximum bound 
of the loop. The program should then present the user numbers from 0 up 
to (and including) that maximum bound replacing any number divisible by 
the second number given  by the user with "Fizz," any number 
divisible by the third number given by the user with "Buzz," and 
any number divisible by the multiplication of those two numbers with 
"FizzBuzz". 
       
All work below was performed by Ermithe Tilusca */
       
       
#include <iostream> 
using namespace std;
       
int main()
{
	int num1, num2, num3; //declare variables for three numbers

	//get user input to initialized the three numbers variables
	cout << "The first number: ";
	cin >> num1;
	cout << "The second number: "; 
	cin >> num2;
	cout << "The third number: "; 
	cin >> num3;

	int multi = num2 * num3; // store the result of num1 multiply by num2 in a variable call multi

	//Title for the result
	cout << endl << "Your FizzBuzz Sequence" << endl;

	//Use for loop to present the user numbers from 0 up to num1 inclusive
	for(int i = 0; i <= num1; i++)
	{
		if(i != 0 && i%multi == 0)//if any number is divisible by num1 times num2, print out "FizzBuzz"   
                {
                        cout << "FizzBuzz" << endl;
                }

		else if(i%num2 == 0 && i != 0) //if any number is not 0 and is divisible by num2, print out "Fizz" 
		{
			cout << "Fizz" << endl;
		}else if(i%num3 == 0 && i != 0) //if any number is not 0 and is divisible by num3, print out "Buzz"
		{
			cout << "Buzz" << endl;
		}
		else //if any number is not divisible by any of the above, print out the number
		{
			cout <<  i << endl;
		}
	}

	return 0;
}
