#include <iostream>

using namespace std;

int numerator, denominator, negativeOne = -1;

void printNegative()
{
  cout << '-';
}

int main()
{
  cout << "Enter the numerator: ";
  cin >> numerator;
  cout << "Enter the denominator: ";
  cin >> denominator;
  cout << numerator << '/' << denominator << " = "; //display what the user entered

  _asm
  {
    //Check if the numerator is 0
    mov eax, numerator;
    cmp eax, 0;
    je LeaveAsIs; //leave the fraction as-is
    //Check if the denominator is 0
    mov eax, denominator;
    cmp eax, 0;
    je LeaveAsIs; //leave the fraction as-is
    //Check if the fraction is negative
    mov eax, numerator;
    imul denominator;
    cmp eax, 0;
    jge NotNegative;
    call printNegative; //print a negative sign in the console
  NotNegative:

    //get the absolute value of numerator
    cmp numerator, 0;
    jge NumeratorIsPositive;
    mov eax, numerator;
    imul negativeOne;
    mov numerator, eax;
  NumeratorIsPositive:
    //get the absolute value of denominator
    cmp denominator, 0;
    jge DenominatorIsPositive;
    mov eax, denominator;
    imul negativeOne;
    mov denominator, eax;
  DenominatorIsPositive:
    //now determine the smaller of the two numbers, and store it in ecx
    mov eax, numerator;
    cmp eax, denominator;
    jg NumeratorIsLarger;
    mov ecx, numerator; //ecx will eventually hold the greatest common divisor/factor
    jmp ForLoop;
  NumeratorIsLarger:
    mov ecx, denominator;

  ForLoop:
    //if the GCD is 1, then leave the fraction as-is
    cmp ecx, 1;
    je LeaveAsIs;

    //Check if eax divides cleanly into the numerator
    mov eax, numerator;
    cdq;
    div ecx;
    cmp edx, 0; //check if the remainder is 0
    jne Decrement;

    //Check if eax divides cleanly into the denominator
    mov eax, denominator;
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
    mov eax, numerator;
    cdq;
    div ecx;
    mov numerator, eax;
    //divide the denominator by the GCD
    mov eax, denominator;
    cdq;
    div ecx;
    mov denominator, eax;
  LeaveAsIs:
  }

  cout << numerator << '/' << denominator; //display the result

  return 0;
}
