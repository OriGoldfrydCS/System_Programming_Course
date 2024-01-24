#ifndef NUMCLASS_H
#define NUMCLASS_H
#define TRUE 1
#define FALSE 0

int isPrime(int);
int isStrong(int);
int isPalindrome (int);
int isArmstrong(int);

// Declarations for auxiliary functions within the functions above
int numberOfDigits(int);
int myPow(int, int);
long long myPowRec(int, int);
long long factorial(int);
int mySqrt(double);
int armstrongSum(int,int);
int assistanceFun(int, int);

#endif