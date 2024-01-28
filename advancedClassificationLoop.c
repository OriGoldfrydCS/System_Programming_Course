#include "NumClass.h"

/*This function checks iteratively if a given integer (n) is a palindrome number by reversing its digits and comparing the reversed
 number with the original. It returns 1 (true) if the two number are idential, and otherwise 0 (false).
 For example: 6, 11, 141, 5005, 12321*/
int isPalindrome (int n)
{
    if(n < 0)
    {
        return FALSE;       /*A negative number cannot considered as a palindrome*/
    }
    int reverseNumber = 0;
    int originalN = n;
    while(n > 0)
    {
        int lsd = n % 10;                               /*lsd means Last Significant Digit*/
        reverseNumber = (reverseNumber * 10) + lsd;     
        n /= 10;
    }
    return reverseNumber == originalN;  
}

/*This function checks iteratively if an integer (n) is an Armstrong number by calculating the sum of its digits each raised
 to the power of the number of digits in n; It returns 1 (true) if the sum is equal to n, and otherwise 0 (false).
 For example: 407 = 4^3 + 0^3 + 7^3 = 407*/
int isArmstrong(int n)
{
    if(n < 0)               /*A negative number cannot considered as an Armstrong number*/
    {
        return FALSE;
    }

    int sum = 0;
    int originalN = n;
    int nDigits = numberOfDigits(n);        /*See function in: Auxiliary Functions below*/

    while(n > 0)
    {
        int lsdDigit = n % 10;
        sum += myPow(lsdDigit, nDigits);    /*See function in: Auxiliary Functions below*/
        n /= 10;
    }
    return sum == originalN;
}

///////// Auxiliary Function /////////

/*This function counts the number of digits in an integer n.*/
int numberOfDigits(int n)
{
    if (n < 0)                  /*Convert negative numbers to positive. We should not do that process in this assigment since n are not less than one*/
    {                           /*This check is added for future needs of that function (it will be necessary), and reuse of code*/
        n = -n;            
    }

    int counter;
    if (n == 0)                 /*Check if the number is zero -> it has one digit*/
    {
        counter = 1;
    } 
    else                        /*Check if the number is not zero -> start counting from zero*/
    {
        counter = 0;
    }
    
    while (n != 0)
    {
        counter++;
        n /= 10;
    }
    return counter;
}

/*This function computes base raised to the power of exp.*/
int myPow(int base, int exp)
{
    if(exp == 0)
    {
        return 1;
    }
    int result = 1;
    while (exp > 0)
    {
        result *= base;
        exp--;
    }
    return result;
}