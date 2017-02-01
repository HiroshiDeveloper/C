//
//  main.c
//  Assignment3
//
//  Created by Hiroshi Tokutomi on 2017-01-29.
//  Copyright © 2017 Hiroshi. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXNAME 20
#define MAXSIZE 7

// problem1
void printInt(int intNum);                                      // number1
void printFloat(float floatNum);                                // number2

// problem2
int sum(int numA, int numB);                                    // number1
int compare(int numA, int numB);                                // number2

// problem3
int middleNumber(int numA, int numB);                           // number1
void printAllNumbers(int numA, int numB);                       // number2
void average(int numA, int numB);                               // number3

// problem4
float calculator(int numA, int numB, char operator);            // number1

// problem6
void swap(int numA);

// problem7
int prime(int numA);
void allPrimeNumbers(int numA, int numB);

// problem8
void checkNumber();

// bonus problem
void printName(char *name, int length);

int main(int argc, const char * argv[]) {
    
    //*** problem1 ***
    /*
    printInt(23);
    printFloat(25.55);
     */
    
    //*** problem2 ***
    /*
    int resultSum = sum(13, 15);
    printf("The sum is %d\n", resultSum);
    int resultCmp = compare(13, 10);
    printf("The result is %d\n", resultCmp);
    */
    
    //*** problem3 ***
    /*
    int numA = 22;
    int numB = 26;
    int resultMiddle = middleNumber(numA, numB);
    if(resultMiddle < 0){
        printf("Error. Middle Number is none\n");
    }else{
        printf("The middole number is %d\n", resultMiddle);
    }
    printAllNumbers(numA, numB);
    average(numA, numB);
     */
    
    //*** problem4 ***
    /*
    int numC = 20;
    int numD = 30;
    char operator = '*';
    float resultCalc = resultCalc = calculator(numC, numD, operator);
    printf("The result is %f\n", resultCalc);
    */
    
    //*** problem6 ***
    /*
    swap(57);
     */
    
    //*** problem7 ***
    /*
    allPrimeNumbers(1, 30);
     */
    
    //*** problem8 ***
    /*
    checkNumber();
    */
    
    //*** bonus problem ***
    // pass the parameters name and length(that is the length of the name)
    /*
    char name[MAXNAME] = "HiroHiro";
    printName(name, 8);     // second paremeter must be matched with the name length
    */
    return 0;
}

//**********************
// Problem1
//**********************
void printInt(int intNum){
    printf("The integer number is %d\n", intNum);
}

void printFloat(float floatNum){
    printf("The float number is %f\n", floatNum);
}

//**********************
// Problem2
//**********************
int sum(int numA, int numB){
    return numA + numB;
}

int compare(int numA, int numB){
    if(numA > numB){
        return numA;
    }else if(numA == numB){
        return numA;
    }else{
        return numB;
    }
}

//**********************
// Problem3
//**********************
// number1
int middleNumber(int numA, int numB){
    int middle = 0;
    // get the bigger number
    int bigNum = compare(numA, numB);
    
    // if the input two numbers are same, the result is error
    // as the assignment says "excluding the input numbers"
    if(numA == numB){
        middle = -1;
    }else if(bigNum == numA){
        middle = ((numA - 1) + (numB + 1)) / 2;
    }else{
        middle = ((numA + 1) + (numB - 1)) / 2;
    }
    
    return middle;
}

// number2
void printAllNumbers(int numA, int numB){
    int bigNum = 0;
    int smallNum = 0;
    
    if(numA == numB || numA -1 == numB || numA == numB - 1){
        printf("Error. Type the numbers that is defference more than two. e.g.) 10 and 12\n");
        return;
    }
    
    // check which number is bigger numA or numB
    if(numA > numB){
        bigNum = numA;
        smallNum = numB;
    }else{
        bigNum = numB;
        smallNum = numA;
    }
    
    for(int i = smallNum + 1; i < bigNum; i++){
        printf("%d ", i);
    }
    printf("\n");
}

// number3
void average(int numA, int numB){
    float average = (numA + numB) / 2;
    printf("The average number between %d and %d is %f\n", numA, numB, average);
}

//**********************
// Problem4
//**********************
float calculator(int numA, int numB, char operator){
    float result = 0;
    
    if(operator == '+'){
        result = numA + numB;
    }else if(operator == '-'){
        result = numA - numB;
    }else if(operator == '*'){
        result = numA * numB;
    }else if(operator == '/'){
        result = numA / numB;
    }else if(operator == '%'){
        result = numA % numB;
    }else{
        printf("Error. Type a operator such as +, -, *, / or %%\n");
        exit(0);
    }
    
    return result;
}

//**********************
// Problem5
//**********************
// Same as Assignment1 problem3

//**********************
// Problem6
//**********************
void swap(int numA){
    if(numA < 10 || numA > 99){
        printf("Error. Type the number is between 10 and 99\n");
        return;
    }
    printf("The swap number is ");
    for(int i = numA; i > 0; i /= 10){
        printf("%d", i % 10);
    }
    printf("\n");
}

//**********************
// Problem7
//**********************
// check whether the number is prime number or not
int prime(int numA){
    int flg = 1;
    for(int i = 2; i <= numA/2; ++i)
    {
        // condition for nonprime number
        if(numA % i==0)
        {
            // flg = -1 : the number is not a prime number
            return flg = -1;
        }
    }
    return flg;
}

void allPrimeNumbers(int numA, int numB){
    int resultFlg = 0;
    
    // The nubers must be bigger than 0
    if(numA < 0 || numB < 0){
        printf("Error. Type numbers bigger than 0\n");
        return;
    }
    
    printf("The prime numbers between %d and %d :\n", numA, numB);
    for(int i = numA; i <= numB; i++){
        resultFlg = prime(i);
        // success
        if(resultFlg > 0){
            printf("%d ", i);
        }
    }
    printf("\n");
}

//**********************
// Problem8
//**********************
void checkNumber(){
    int number = 0;
    int resultFlg = 0;
    
    printf("Type a number\n");
    scanf("%d", &number);
    
    // check the number (bigger than 0)
    if(number < 0){
        printf("Please type a number bigger than 0\n");
        return;
    }
    
    // number1
    if(number % 2 == 0){
        printf("The number is even\n");
    }else{
        printf("The number is odd\n");
    }
    
    // number2
    if(number % 3 == 0){
        printf("The number is dividend of 3\n");
    }
    
    // number3
    if(number % 7 == 0){
        printf("The number is dividend of 7\n");
    }
    
    // number4
    resultFlg = prime(number);
    if(resultFlg > 0){
        printf("The number is a prime number\n");
    }
}

//**********************
// Bonus Problem
//**********************
void printName(char *name, int length){
    int maxSize = MAXSIZE;      // the width
    int flg = 0;                // check flag whether the template is printed out already or not
    
    char* template[5] = {
        "Hello", name, "Welcome", "To", "CICCC"
    };
    
    // "Welcome" is the longest word(the length is 7) except input name
    if(length > MAXSIZE){
        maxSize = length;
    }
    
    // BonusProblem1
    // row
    for(int i = 0; i < 7; i++){
        // colum
        for(int j = 0; j < maxSize + 4; j++){   // maxsize + "*" * 4
            if(i == 0 || i == 6){               // the first and last row
                printf("*");
            }else{
                if(strlen(template[i - 1]) >= j && flg == 0){
                    printf("**%s", template[i - 1]);
                    flg = 1;
                }else if(strlen(template[i - 1]) < j - 1){
                    printf("*");
                }
            }
        }
        flg = 0;
        printf("\n");
    }
    
    // BonusProblem2
    for(int k = 0; k < 7; k++){
        // colum
        for(int l = 0; l < maxSize + 3; l++){     // maxsize + "*" * 4
            if(k == 0 || k == 6){                 // the first and last row
                printf("*");
            }else{
                if(strlen(template[k - 1]) >= l && flg == 0){
                    printf("* %s", template[k - 1]);
                    flg = 1;
                }else if(strlen(template[k - 1]) < l - 1){
                    printf(" ");
                }
            }
        }
        flg = 0;
        printf("*\n");
    }
}
