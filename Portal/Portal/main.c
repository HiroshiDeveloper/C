//
//  main.c
//  Portal
//
//  Created by Hiroshi Tokutomi on 2017-02-05.
//  Copyright © 2017 Hiroshi. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ACCOUNTSPATH "/Users/hiroshi/Documents/Github/C/Portal/Portal/Accounts.txt"
#define STUDENTSPATH "/Users/hiroshi/Documents/Github/C/Portal/Portal/Students.txt"

#define CHARLENGTH 256

void loginMenu();
void AccountFile(char *fileName, char *studentId, char *password);
char *extractWords(char *line);

int main(int argc, const char * argv[]) {
    loginMenu();
    
    return 0;
}

void loginMenu(){
    char *studentId = malloc(sizeof(char) * CHARLENGTH);
    char *password = malloc(sizeof(char) * CHARLENGTH);
    int storeSize = 0;
    
    printf("******************************************\n");
    printf("Please enter your account to login:\n");
    printf("******************************************\n");
    printf("StudentId: ");
    scanf("%s", studentId);
    printf("Password: ");
    scanf("%s", password);
    
    storeSize = 2;
    AccountFile(ACCOUNTSPATH, studentId, password);
    free(studentId);
    free(password);
}

void AccountFile(char *fileName, char *studentId, char *password){
    FILE *fp;
    size_t len = 0;
    ssize_t read;
    char *line = NULL, *words;
    int idFlg = 0;
    
    // file open
    fp=fopen(fileName, "r");
    
    // error if the file is not found
    if (fp == NULL){
        printf("Cannot find the text file in this URL: %s\n", fileName);
        exit(0);
    }
    
    // read the file line by line
    while ((read = getline(&line, &len, fp)) != -1) {
        if((int)strlen(line) != 1){
            words = extractWords(line);             // extract words e.g.) StudentId, Pass
            if(strcmp(words, studentId) == 0){
                idFlg = 1;
            }else if(idFlg == 1 && strcmp(words, password) == 0){   // check studentId and pass
                printf("WELCOME\n");
            }
            free(words);
        }else{
            idFlg = 0;
        }
    }
}

char *extractWords(char *line){
    int length = (int)(strlen(line) - 2);   // subtract '"' + '\n'
    int checkPoint = -1;
    char *words = malloc(sizeof(char) * length);
    
    for(int i = 0; i < length; i++){
        
        if(checkPoint != -1){
            words[checkPoint] = line[i];    // copy characters one by one
            checkPoint++;
        }else if(line[i] == '\"'){          // find this character '"'
            checkPoint = 0;
        }
    }
    return words;
}
