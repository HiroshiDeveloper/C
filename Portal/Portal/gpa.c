//
//  gpa.c
//  Portal
//
//  Created by Hiroshi Tokutomi on 2017-02-16.
//  Copyright © 2017 Hiroshi. All rights reserved.
//

#include "header.h"
#include "gpa.h"

char *extractWords(char *line);
char startingNumber(char *line);
float getGpa(FILE *fp, size_t len, ssize_t read, char *line, char *studentId);
int listOfStudent(char *fileName, char **listOfStudent, char *studentId);

void gpa(struct student *student, char *fileName, int rankFlg){
    FILE *fp;
    size_t len = 0;
    ssize_t read;
    char *line = NULL;
    float myGpa = 0, tmpGpa = 0;
    char **studentsList;
    int sizeOfStudent = 0, rank = 1;
    
    // file open
    fp=fopen(fileName, "r");
    
    // error if the file is not found
    if (fp == NULL){
        printf("Cannot find the text file in this URL: %s\n", fileName);
        exit(0);
    }
    
    myGpa = getGpa(fp, len, read, line, student->studentId);
    fclose(fp);
    
    if(myGpa == -1){
        printf("Error. %s doesn't have gpa\n", student->studentId);
    }
    
    // introduction
    printf("Hi %s %s,\n", student->gender2, student->name);
    printf("Your GPA is %f ", myGpa);
    
    // print my GPA with my rank
    // get the list of student
    if(rankFlg == 1){
        
        sizeOfStudent = listOfStudent(STUDENTSPATH, studentsList, student->studentId);
        for(int i = 0; i < sizeOfStudent; i++){
            fp=fopen(fileName, "r");
            tmpGpa = getGpa(fp, len, read, line, studentsList[i]);
            fclose(fp);
            if(tmpGpa > myGpa){
                rank++;
            }
            free(studentsList[i]);
        }
        printf("and therefore your rank is %d.\n", rank);
    }
    printf("\n");
    return;
}

int listOfStudent(char *fileName, char **listOfStudent, char *studentId){
    FILE *fp;
    size_t len = 0;
    ssize_t read;
    char *line = NULL, *words;
    char firstCharacter;
    int counter = 0;
    
    // file open
    fp=fopen(fileName, "r");
    
    // error if the file is not found
    if (fp == NULL){
        printf("Cannot find the text file in this URL: %s\n", fileName);
        exit(0);
    }
    
    // read the file line by line
    while ((read = getline(&line, &len, fp)) != -1) {
        words = extractWords(line);
        firstCharacter = startingNumber(line);
        if(firstCharacter == '1' && strcmp(words, studentId) != 0){
            listOfStudent[counter] = malloc(sizeof (char) * STUDENTIDLENGTH);
            listOfStudent[counter] = words;
            counter++;
        }
    }
    fclose(fp);
    return counter;
}

float getGpa(FILE *fp, size_t len, ssize_t read, char *line, char *studentId){
    char *words, firstCharacter;
    int flg = 0, index = 0;
    float gpa = 0;
    
    // read the file line by line
    while ((read = getline(&line, &len, fp)) != -1) {
        words = extractWords(line);                         // extract words e.g.) StudentId, Pass
        firstCharacter = startingNumber(line);
        
        // finish reading marks
        if(flg == 1 && strcmp(words, studentId) != 0 && firstCharacter == '1'){
            break;
        }
        
        // index 1
        if(firstCharacter == '1'){
            if(strcmp(words, studentId) == 0){
                flg = 1;                                  // my Id
            }
        }
        // index 3
        else if(firstCharacter == '3'){
            if(flg == 1){
                flg = 0;
                gpa += atof(words);
                index++;
            }
        }
    }
    
    if(gpa == 0){
        return -1;
    }else{
        return gpa / index;
    }
}
