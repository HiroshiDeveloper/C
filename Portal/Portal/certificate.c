//
//  certificate.c
//  Portal
//
//  Created by Hiroshi Tokutomi on 2017-02-10.
//  Copyright © 2017 Hiroshi. All rights reserved.
//

#include "header.h"
#include "certificate.h"

char *extractWords(char *line);
int getNumberOfWords(char *string, char *mark);

struct student *studentFile(char *studentId, char *fileName){
    FILE *fp;
    size_t len = 0;
    ssize_t read;
    char *line = NULL, *words;
    int flg = 0;
    struct student *student = (struct student*)malloc(sizeof(struct student));

    
    // file open
    fp=fopen(fileName, "r");
    
    // error if the file is not found
    if (fp == NULL){
        printf("Cannot find the text file in this URL: %s\n", fileName);
        exit(0);
    }
    
    // read the file line by line
    while ((read = getline(&line, &len, fp)) != -1) {
        words = extractWords(line);             // extract words e.g.) StudentId, Pass
        if(strcmp(words, studentId) == 0 || flg != 0){
            switch(flg){
                case 0:
                    student->studentId = words;
                    break;
                case 1:
                    student->name = words;
                    break;
                case 2:
                    student->gender = words;
                    if(strcmp(student->gender, "male") == 0){
                        student->gender2 = "Mr.";
                        student->gender3 = "he";
                    }else{
                        student->gender2 = "Ms.";
                        student->gender3 = "she";
                    }
                    break;
                case 3:
                    student->grade = words;
                    break;
                case 4:
                    student->address = words;
                    break;
                case 5:
                    student->admission_year = words;
                    break;
                case 6:
                    student->courses = words;
                    break;
            }
            flg++;
        }
    }
    return student;
}

void createCertificate(struct student *student){
    int number = getNumberOfWords(student->courses, ",");
    
    printf("Dear Sir/Madam,\n\n");
    printf("This is to certify that %s %s with student id %s is a student at grade %s at CICCC.\n", student->gender2, student->name, student->studentId, student->grade);
    printf("He was admitted to our college in %s and taken %d course(s). Currently %s resides at %s.\n\n", student->admission_year, number, student->gender3, student->address);
    printf("If you have any questions, please don't hesitate to contact us.\n\n");
    printf("Thanks,\nWilliam\n\n\n");
}

// char *string : target line
// char *mark : deivded mark e.g.) ","
int getNumberOfWords(char *string, char *mark){
    int number = 0;
    char *tok;
    
    tok = strtok(string, mark);
    while(tok != NULL){
        tok = strtok(NULL, mark);   // after twice
        number++;
    }
    return number;
}

