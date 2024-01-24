#include "NumClass.h"

/* This function recursively checks if a given integer (n) is a palindrome number by reversing its digits and comparing the reversed
 number with the original. It returns 1 (true) if the two number are idential, and otherwise 0 (false).*/
int isPalindrome (int n)
{
    return n >= 0 && n == assistanceFun(n, 0);
}

/* This function recursively checks if an integer (n) is an Armstrong number by calculating the sum of its digits each raised
 to the power of the number of digits in n; It returns 1 (true) if the sum is equal to n, and otherwise 0 (false).*/
int isArmstrong(int n)
{
    if(n < 0){
        return FALSE;
    } 
    int nDigits = numberOfDigits(n);
    return n == armstrongSum(n, nDigits);
}

///////// Auxiliary Function /////////

/*This function recursively reverses a given integer (n), using reverse as an accumulator for the reversed number.*/
int assistanceFun(int n, int reverse){
    if(n == 0)
    {
        return reverse;
    }
    return assistanceFun(n / 10, n % 10 + reverse * 10);
}

/*This function recursively counts the number of digits in an integer n.*/
int numberOfDigits(int n){
    if(n == 0)
    {
        return FALSE;
    }
    return 1 + numberOfDigits(n / 10);
}

/*This function recursively calculates the Armstrong sum of a number, 
 where each digit of shorterNumber is raised to the nth power (using myPowRec)..*/
int armstrongSum(int shorterNumber,int n){
    if(shorterNumber == 0)
    {
        return FALSE;
    }
    return (int) myPowRec(shorterNumber % 10, n) + armstrongSum(shorterNumber / 10, n);

}

/*This function recursively computes base raised to the power of exp.*/
long long myPowRec(int base, int exp) {
    if (exp == 0) {
        return 1;
    }
    long long halfPow = myPowRec(base, exp / 2);
    if (exp % 2 == 0) {
        return halfPow * halfPow;
    }
    return base * halfPow * halfPow;
}