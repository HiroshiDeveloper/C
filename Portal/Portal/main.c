//
//  main.c
//  Portal
//
//  Created by Hiroshi Tokutomi on 2017-02-05.
//  Copyright © 2017 Hiroshi. All rights reserved.
//

#include "header.h"
#include "accounts.h"
#include "certificate.h"
#include "courses.h"

// account
struct account *loginMenu(struct account *account, char *studentId, char *password);

// main menu 1.
struct student *studentFile(char *studentId, char *fileName);
void createCertificate(struct student *student);

// main menu 2.
void courseFile(struct student *student, char *fileName);

// main
int mainMenu();
void switchMenu(int number, char *studentId);

int main(int argc, const char * argv[]) {
    char *studentId = malloc(sizeof(char) * CHARLENGTH);
    char *password = malloc(sizeof(char) * CHARLENGTH);
    
    // Account check
    struct account *account = (struct account*)malloc(sizeof(struct account));
    account = loginMenu(account, studentId, password);
    printf("StudentId : %s\n", account->studentId);
    printf("Password : %s\n", account->password);
    
    // Main menu
    int number = mainMenu();
    printf("The number is %d\n\n\n", number);
    switchMenu(number, account->studentId);
    
    free(account);
    free(studentId);
    free(password);
    return 0;
}

int mainMenu(){
    int number = 0;
    int flg = 1;
    
    while(flg){
        printf("******************************************************\n");
        printf("Select from the optiosn:\n");
        printf("******************************************************\n");
        printf("-[1] Print my enrolment certificate\n");
        printf("-[2] Print my courses\n");
        printf("-[3] Print my transcript\n");
        printf("-[4] Print my GPA\n");
        printf("-[5] Print my ranking among all studednts in the college\n");
        printf("-[6] List all available courses\n");
        printf("-[7] List all students\n");
        printf("-[8] Logout\n");
        printf("-[9] Exit\n");
        printf("******************************************************\n");
        printf("Enter the number corresponding to each item to procees:\n");
        scanf("%d", &number);
        if(number < 10 && number > 0){
            flg = 0;
        }else{
            printf("Error. Choose a number between 1 and 9\n");
        }
    }
    return number;
}

void switchMenu(int number, char *studentId){
    if(number == 1 || number == 2){
        struct student *student = studentFile(studentId, STUDENTSPATH);
        if(number == 1){
            createCertificate(student);
        }else if(number == 2){
            courseFile(student, COURSESPATH);
        }
        free(student);
    }else if(number == 3){
    
    }else if(number == 4){
        
    }else if(number == 5){
        
    }else if(number == 6){
        
    }else if(number == 7){
        
    }else if(number == 8){
        
    }else{
        
    }
}
