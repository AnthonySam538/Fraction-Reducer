#include <iostream>

using namespace std;

int num1, num2, negativeOne = -1;

void printNegative()
{
	cout << '-';
}

int main()
{
	cout << "Enter the numerator: ";
	cin >> num1;
	cout << "Enter the denominator: ";
	cin >> num2;
	cout << num1 << '/' << num2 << " = "; //display what the user entered

	_asm
	{
		//Check if the numerator is 0
		mov eax, num1;
		cmp eax, 0;
		je LeaveAsIs; //leave the fraction as-is
		//Check if the denominator is 0
		mov eax, num2;
		cmp eax, 0;
		je LeaveAsIs; //leave the fraction as-is
		//Check if the fraction is negative
		mov eax, num1;
		imul num2;
		cmp eax, 0;
		jge NotNegative;
		call printNegative; //print a negative sign in the console
	NotNegative:

		//store the absolute value of the numerator in num1
		cmp num1, 0;
		jge NumeratorIsPositive;
		mov eax, num1;
		imul negativeOne;
		mov num1, eax;
	NumeratorIsPositive:
		//store the absolute value of the denominator in num2
		cmp num2, 0;
		jge DenominatorIsPositive;
		mov eax, num2;
		imul negativeOne;
		mov num2, eax;
	DenominatorIsPositive:
		//now determine the smaller of the two numbers, and store it in ecx
		mov eax, num1;
		cmp eax, num2;
		jg NumeratorIsLarger;
		mov ecx, num1; //ecx will eventually hold the greatest common divisor/factor
		jmp ForLoop;
	NumeratorIsLarger:
		mov ecx, num2;

	ForLoop:
		//if the GCD is 1, then leave the fraction as-is
		cmp ecx, 1;
		je LeaveAsIs;

		//Check if eax divides cleanly into the numerator
		mov eax, num1;
		cdq;
		div ecx;
		cmp edx, 0; //check if the remainder is 0
		jne Decrement;

		//Check if eax divides cleanly into the denominator
		mov eax, num2;
		cdq;
		div ecx;
		cmp edx, 0; //check if the remainder is 0
		jne Decrement;

		jmp ExitLoop; //if we haven't jumped to Decrement, then we've found the GCD

	Decrement: //decrement ecx, then jump back up
		dec ecx;
		jmp ForLoop;
	ExitLoop:
		//divide the numerator by the GCD
		mov eax, num1;
		cdq;
		div ecx;
		mov num1, eax;
		//divide the denominator by the GCD
		mov eax, num2;
		cdq;
		div ecx;
		mov num2, eax;
	LeaveAsIs:
	}

	cout << num1 << '/' << num2; //display the result

	return 0;
}