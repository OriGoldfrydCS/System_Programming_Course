#include "NumClass.h"

/*This function checks if a given integer (n) is a palindrome number by reversing its digits and comparing the reversed
 number with the original. It returns 1 (true) if the two number are idential, and otherwise 0 (false).*/
int isPalindrome (int n){
    int reverseNumber = 0;
    int originalN = n;
    while(n > 0){
        int lsdDigit = n % 10;
        reverseNumber = (reverseNumber * 10) + lsdDigit;
        n /= 10;
    }
    return reverseNumber == originalN;  
}

/*This function checks if an integer (n) is an Armstrong number by calculating the sum of its digits each raised
 to the power of the number of digits in n; It returns 1 (true) if the sum is equal to n, and otherwise 0 (false).*/
int isArmstrong(int n){
    int sum = 0;
    int originalN = n;
    int nDigits = numberOfDigits(n);

    while(n > 0)
    {
        int lsdDigit = n % 10;
        sum += myPow(lsdDigit, nDigits);
        n /= 10;
    }
    return sum == originalN;
}

///////// Auxiliary Function /////////

/*This function counts the number of digits in an integer n.*/
int numberOfDigits(int n){
    int counter = 0;
    while (n != 0){
        counter++;
        n /= 10;
    }
    return counter;
}

/*This function computes base raised to the power of exp.*/
int myPow(int base, int exp){
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

