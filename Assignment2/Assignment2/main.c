//
//  main.c
//  Assignment2
//
//  Created by Hiroshi Tokutomi on 2017-01-28.
//  Copyright © 2017 Hiroshi. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

// probrem3
void probrem3();

int main(int argc, const char * argv[]) {
    probrem3();
    return 0;
}

//****************************************
// Probrem1, Probrem2 and Bonus Pribrem
//****************************************
//  Same as Assignment1

//****************************************
// Probrem3
//****************************************
void probrem3(){
    
    int age = 0;        // number1
    int gender = 0;     // number1
    char yourName[30];  // number2
    int digit = 0;      // number3
    int counter = 0;    // number3
    int number = 0;     // number4
    
    // number1
    printf("Please type your age : \n");
    scanf("%d", &age);
    
    // error message
    if(age < 0 || age > 120){
        printf("Error. Type your age between 0 and 120\n");
        return;
    }
    
    if(age < 20){
        printf("Your age is less than 20\n");
    }else{
        printf("Your age is greater than or eaqual to 20\n");
    }
    
    // number2
    printf("If you are a girl, please type 1\nIf you are a boy, please type 2\n");
    scanf("%d", &gender);
    
    // error message
    if(gender < 1 || gender > 2){
        printf("Error. Type 1(girl) or 2(boy).\n");
        return;
    }
    
    printf("Type your name : \n");
    scanf("%s", yourName);
    printf("Your name is %s\n", yourName);
    
    // number3
    printf("Type a number between 0 and 9999\n");
    scanf("%d", &digit);
    
    // error message
    if(digit < 0 || digit > 9999){
        printf("Error. Type your age between 0 and 9999\n");
        return;
    }
    
    for(int i = digit; i > 0; i /= 10){
        counter++;
    }
    printf("The digit is %d\n", counter);
    
    // number4
    printf("Type a number between 0 and 200\n");
    scanf("%d", &number);
    
    // error message
    if(number > 200){
        printf("Your number is bigger than 200\n");
    }else if(number < 0){
        printf("Your number is less than 0\n");
    }else{
        if(number % 2 == 0){    //even
            printf("The number is even\n");
        }else{                  //odd
            printf("The number is odd\n");
        }
    }
    
    return;
}
