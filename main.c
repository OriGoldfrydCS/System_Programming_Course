#include<stdio.h>
#include "NumClass.h"

/*Main program*/
int main(){
    int n1, n2;

    printf("Please insert two non-negative numbers: ");
    scanf("%d %d", &n1, &n2);

    if(n1 > n2)             // A check in case that the user inserts his numbers in a reverse order
    {
        int tmp;
        tmp = n1;
        n1 = n2;
        n2 = tmp;
    }

    /*Print all armstrong numbers between n1 and n2.*/
    printf("The Armstrong numbers are:");
    for(int i = n1; i <= n2; i++)
    {
        if(isArmstrong(i))
        {
            printf(" %d", i);
        }
    }
    printf("\n");
    
    /*Print all palindrome numbers between n1 and n2.*/
    printf("The Palindromes are:");
    for(int i = n1; i <= n2; i++)
    {
        if(isPalindrome(i))
        {
            printf(" %d", i);
        }
    }
    printf("\n");

    /*Print all prime numbers between n1 and n2.*/
    printf("The Prime numbers are:");
    for(int i = n1; i <= n2; i++)
    {
        if(isPrime(i))
        {
            printf(" %d", i);
        }
    }
    printf("\n");

    /*Print all strong numbers between n1 and n2.*/
    printf("The Strong numbers are:");
    for(int i = n1; i <= n2; i++)
    {
        if(isStrong(i))
        {
            printf(" %d", i);
        }
    }
    printf("\n");

    return 0;
}