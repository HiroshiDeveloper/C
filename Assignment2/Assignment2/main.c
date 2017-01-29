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

//************************
// Probrem1 and Probrem2
//************************
//  Same as Assignment1

//************************
// Probrem3
//************************
void probrem3(){
    
    int age = 0;        // number1
    int gender = 0;     // number1
    char yourName[30];  // number2
    
    // number1
    printf("Please type your age : \n");
    scanf("%d", &age);
    
    // error message
    if(age < 0 || age > 120){
        printf("Error. Type your age between 0 and 120.\n");
        return;
    }
    
    if(age < 20){
        printf("Your age is less than 20\n");
    }else{
        printf("Your age is greater than or eaqual to 20\n");
    }
    
    // number2
    printf("If you are a girl, please type 1.\nIf you are a boy, please type 2.\n");
    scanf("%d", &gender);
    
    // error message
    if(gender < 1 || gender > 2){
        printf("Error. Type 1(girl) or 2(boy).\n");
        return;
    }
    
    printf("Type your name : \n");
    scanf("%s", yourName);
    printf("Your name is %s", yourName);
    
    // number3
    //printf("Type a number between 0 and 9999\n");
    
    
    return;
}
