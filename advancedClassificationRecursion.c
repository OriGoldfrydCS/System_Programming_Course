#include "NumClass.h"

/*This function recursively checks if a given integer (n) is a palindrome number by reversing its digits and comparing the reversed
 number with the original. It returns 1 (true) if the two number are idential, and otherwise 0 (false).
 For example: 6, 11, 141, 5005, 12321*/
int isPalindrome (int n)
{
    if(n < 0)
    {
        return FALSE;                       /*A negative number cannot considered as a palindrome*/
    }
    return n == assistanceFun(n, 0);        /*See function in: Auxiliary Functions below*/
}

/*This function recursively checks if an integer (n) is an Armstrong number by calculating the sum of its digits each raised
 to the power of the number of digits in n; It returns 1 (true) if the sum is equal to n, and otherwise 0 (false).
 For example: 407 = 4^3 + 0^3 + 7^3 = 407*/
int isArmstrong(int n)
{
    if(n < 0)                               /*A negative number cannot considered as an Armstrong number*/
    {
        return FALSE;
    } 
    int nDigits = numberOfDigits(n);        /*See function in: Auxiliary Functions below*/
    return n == armstrongRec(n, nDigits);
}

///////// Auxiliary Function /////////

/*This function recursively reverses a given integer (n), using reverse as an accumulator for the reversed number.*/
int assistanceFun(int n, int reverse)
{
    if(n == 0)
    {
        return reverse;
    }
    return assistanceFun(n / 10, reverse * 10 + (n % 10));        /*We recursively call that functio without the lsd of n,
                                                                  and the sum of the lsd and the reverse number multiplied by 10 to increase the number in check*/
}

/*This function recursively counts the number of digits in an integer n.*/
int numberOfDigits(int n)
{
    if (n < 10) 
    {
        return 1;
    }
    return 1 + numberOfDigits(n / 10);
}

/*This function recursively calculates the Armstrong sum of a number, 
 where each digit of shorterNumber is raised to the nth power (using myPowRec).*/
int armstrongRec(int n, int nDigits) {
    if (n == 0) 
    {
        return 0;
    }
    int digit = n % 10;
    return myPowRec(digit, nDigits) + armstrongRec(n / 10, nDigits); /*This line returns the power of the lsd of the current n,
                                                                     and the Armstrong sum of the remaining digits.*/
}

/*This function recursively computes base raised to the power of exp.*/
long myPowRec(int base, int exp) {
    if (exp == 0)
    {
        return 1;
    }
    return base * myPowRec(base, exp - 1);
}



