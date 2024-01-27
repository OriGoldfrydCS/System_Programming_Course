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
    return n == armstrongSum(n, nDigits);
}

///////// Auxiliary Function /////////

/*This function recursively reverses a given integer (n), using reverse as an accumulator for the reversed number.*/
int assistanceFun(int n, int reverse)
{
    if(n == 0)
    {
        return reverse;
    }
    return assistanceFun(n / 10, (n % 10) + (reverse * 10));        /*We recursively call that functio without the lsd of n,
                                                                    and the sum of the lsd and the reverse number multiplied by 10 to increase the number in check*/
}

/*This function recursively counts the number of digits in an integer n.*/
int numberOfDigits(int n)
{
    if(n == 0)
    {
        return 1;
    }

    if (n < 0)                  /*Convert negative numbers to positive. We should not do that process in this assigment since n are not less than one*/
    {                           /*This check is added for future needs of that function (it will be necessary), and reuse of code*/
        n = -n;            
    }
    
    return 1 + numberOfDigits(n / 10);
}

/*This function recursively calculates the Armstrong sum of a number, 
 where each digit of shorterNumber is raised to the nth power (using myPowRec)..*/
int armstrongSum(int shorterNumber,int n)
{
    if(shorterNumber == 0)
    {
        return FALSE;
    }
    return (int) myPowRec(shorterNumber % 10, n) + armstrongSum(shorterNumber / 10, n); /*Calculate the n power of shorterNumber's lsd and add it to the result*/

}

/*This function recursively computes base raised to the power of exp.*/
long myPowRec(int base, int exp) 
{
    if (exp == 0) {
        return 1;
    }
    long long halfPow = myPowRec(base, exp / 2);  /*Divide the exponent by 2 and call he function with this halved exponent*/
    if (exp % 2 == 0) {
        return halfPow * halfPow;                 /*If the exponent is even -> return halfPow * halfPow. For example: 3^4 = (3^2)^2 = 81*/
    }
    return base * halfPow * halfPow;              /*If the exponent is odd -> return base * halfPow * halfPow. For exampe: 2^3 = 2 * (2^(3-1)/2)^2 = 2 * (2^1)^2 = 2 * 4 = 8*/
}