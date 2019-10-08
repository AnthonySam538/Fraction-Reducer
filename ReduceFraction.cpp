#include <iostream>

using namespace std;

int num1, num2;

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

	//_asm
	//{
	//	//Check if the numerator is 0
	//	mov eax, num1;
	//	cmp eax, 0;
	//	je BreakOut;

	//	//Check if the denominator is 0
	//	mov eax, num2;
	//	cmp eax, 0;
	//	je BreakOut;
	//	
	//	//Check if the fraction is negative
	//	mov eax, num1;
	//	imul num2;
	//	cmp eax, 0;
	//	jge NotNegative;
	//	call printNegative;
	//NotNegative:

	//	//initialize ecx, depending on which is smaller
	//	fld num1; //get the absolute value of the numerator using num1num1*sqrt
	//	fld num1;
	//	fmul;
	//	fsqrt;
	//	fstp num1;
	//	fld num2; //get the absolute value of the denominator using num2num2*sqrt
	//	fld num2;
	//	fmul;
	//	fsqrt;
	//	fstp num2;
	//	mov eax, num1;
	//	mov ebx, num2;
	//	cmp eax, ebx;
	//	jg NumeratorIsLarger;
	//	mov ecx, num1; //ecx will be the greatest common divisor/factor
	//	jmp ForLoop;
	//NumeratorIsLarger:
	//	mov ecx, num2;

	//ForLoop:
	//	cmp ecx, 1;
	//	je ExitLoop;

	//	//Check if eax divides cleanly into the numerator
	//	mov eax, num1;
	//	cdq;
	//	div ecx;
	//	cmp edx, 0; //check if the remainder is 0
	//	jne Decrement;

	//	//Check if eax divides cleanly into the denominator
	//	mov eax, num2;
	//	cdq;
	//	div ecx;
	//	cmp edx, 0; //check if the remainder is 0
	//	jne Decrement;

	//	jmp ExitLoop; //if we haven't jumped to Decrement, then we've found the GCD

	//Decrement: //decrement ecx, then jump back up
	//	dec ecx;
	//	jmp ForLoop;
	//ExitLoop:
	//	//divide the numerator by the GCD
	//	mov eax, num1;
	//	cdq;
	//	div ecx;
	//	mov num1, eax;
	//	//divide the denominator by the GCD
	//	mov eax, num2;
	//	cdq;
	//	div ecx;
	//	mov num2, eax;
	//BreakOut:
	//}
	
	cout << num1 << '/' << num2; //display the result

	return 0;
}

