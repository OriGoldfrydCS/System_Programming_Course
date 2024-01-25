#include "NumClass.h"

/*This function checks if a given integer (n) is a prime number by checking divisibility with numbers up to its
 square root. It returns 1 (true) if prime, and otherwise 0 (false)*/
int isPrime(int n)
{
    if(n < 1)               /*Prime number is not less than 1 (according to the test files given)*/
    {
        return FALSE;
    }

    if(n == 1 || n == 2)
    {
        return TRUE;
    }
    
    if(n % 2 == 0)
    {
        return FALSE;
    }

    int root = mySqrt(n);               /*See function in: Auxiliary Functions below*/
    for(int i = 3; i <= root; i += 2)
    {
        if(n % i == 0)
        {
            return FALSE;
        }
    }
    return TRUE;
}

/*This number checks if a given integer (n) is a strong number, meaning the sum of the factorials
 of its digits equals the number itself. It returns 1 (true) if strong, and otherwise 0 (false)*/
int isStrong(int n)
{
    if (n < 0)
    {
        return FALSE;      /*Strong numbers must be non-negative*/
    }
    int sum = 0;
    int originalN = n;

    while(n > 0)
    {
        int lsd  = n % 10;         /*lst means Last Significant Digit*/
        sum += factorial(lsd);     /*See function in: Auxiliary Functions below*/
        n /= 10;
    }
    return originalN == sum;
}

///////// Auxiliary Functions /////////

/*This function calculates recursively the factorial of a given integer (n) by using an iterative approach.
 It returns the factorial value as a long long*/
long factorial(int n)
{
    if (n < 0)              /*Factorial of negative numbers is not defined*/        
    {
        return FALSE;           
    }

    if(n == 0 || n == 1)
    {
        return TRUE;
    }   
    return n * factorial(n - 1);
}   

/*This function computes the square root of a given non-negative integer (n) by
 using the binary search method. It returns the integer part of the square root.*/
int mySqrt(double n)
{
    if (n < 0) 
    {
        return FALSE;       /*Square root of negative numbers is not defined*/ 
    }
    if(n == 0 || n == 1)
    {
        return n;
    }
    int start = 1;
    int end = n;
    int result;

    while(start <= end)
    {
        int middle = (start + end) / 2;
        if(middle <= n / middle)
        {
            start = middle + 1;
            result = middle;
        }
        else
        {
            end = middle - 1;
        }
    }
    return result;
}