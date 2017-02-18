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
#include "transcript.h"

// account
struct account *loginMenu(struct account *account, char *studentId, char *password);

// main menu 1.
struct student *studentFile(char *studentId, char *fileName);
void createCertificate(struct student *student);

// main menu 2.
// main menu 6.
void courseFile(struct student *student, char *fileName, int offeredFlg);

// main menu 3.
void transcript(struct student *student, char *fileName);

// main menu 4.
// main menu 5.
void gpa(struct student *student, char *fileName, int rankFlg);

// main menu 7.
void studentIdAndName(char *fileName);

// main
int mainMenu();
int switchMenu(int number, char *studentId);

int main(int argc, const char * argv[]) {
    char *studentId = malloc(sizeof(char) * CHARLENGTH);
    char *password = malloc(sizeof(char) * CHARLENGTH);
    int number = 0, flg = 1;
    
    // Account check
    struct account *account = NULL;
    
    // Main menu
    while(flg){
        if(flg == 2 || account == NULL){
            account = (struct account*)malloc(sizeof(struct account));
            account = loginMenu(account, studentId, password);
        }else{
            number = mainMenu();
            flg = switchMenu(number, account->studentId);
            if(flg == 2 || flg == 0){
                free(account);
            }
        }
    }

    free(studentId);
    free(password);
    return 0;
}

int mainMenu(){
    int number = 0;
    int flg = 1;
    
    while(flg){
        printf("******************************************************\n");
        printf("Select from the options:\n");
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
        printf("Enter the number corresponding to each item to procees: ");
        scanf("%d", &number);
        printf("\n");
        if(number < 10 && number > 0){
            flg = 0;
        }else{
            printf("Error. Choose a number between 1 and 9\n");
        }
    }
    return number;
}

int switchMenu(int number, char *studentId){
    if(number >= 1 && number <= 6){
        struct student *student = studentFile(studentId, STUDENTSPATH);
        
        if(number == 1){
            createCertificate(student);
        }
        else if(number == 2){
            courseFile(student, COURSESPATH, 0);
        }
        else if(number == 3){
            transcript(student, STUDENTSCOURSESPATH);
        }
        else if(number == 4){
            gpa(student, STUDENTSCOURSESPATH, 0);
        }
        else if(number == 5){
            gpa(student, STUDENTSCOURSESPATH, 1);
        }
        else if(number == 6){
            courseFile(student, COURSESPATH, 1);
        }
        free(student);
    }else if(number == 7){
        studentIdAndName(STUDENTSPATH);
    }else if(number == 8){
        return 2;
    }else{
        printf("See you!\n");
        return 0;
    }
    return 1;
}
