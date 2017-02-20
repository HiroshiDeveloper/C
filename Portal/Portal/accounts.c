//
//  accounts.c
//  Portal
//
//  Created by Hiroshi Tokutomi on 2017-02-10.
//  Copyright © 2017 Hiroshi. All rights reserved.
//

#include "header.h"

struct account *loginMenu(struct account *account, char *studentId, char *password);
struct account *AccountFile(struct account *account, char *fileName, char *studentId, char *password);
char *extractWords(char *line);

struct account * loginMenu(struct account *account, char *studentId, char *password){
    
    printf("******************************************************\n");
    printf("Please enter your account to login:\n");
    printf("******************************************************\n");
    printf("StudentId: ");
    scanf("%s", studentId);
    printf("Password: ");
    scanf("%s", password);
    
    account = AccountFile(account, ACCOUNTSPATH, studentId, password);
    sleep(2);
    if(account->studentId == NULL || account->password == NULL){
        printf("\n******************************************************\n");
        printf("Your account does not exist. Please try again.\n");
        printf("******************************************************\n\n");
        return NULL;
    }else{
        printf("\n******************************************************\n");
        printf("Welcome to CICCC\n");
        printf("******************************************************\n\n");
    }
    return account;
}

struct account *AccountFile(struct account *account, char *fileName, char *studentId, char *password){
    
    FILE *fp;
    size_t len = 0;
    ssize_t read;
    char *line = NULL, *words;
    int idFlg = 0, counter = 1;
    
    // file open
    fp=fopen(fileName, "r");
    
    // error if the file is not found
    if (fp == NULL){
        printf("Cannot find the text file in this URL: %s\n", fileName);
        free(studentId);
        free(password);
        exit(0);
    }
    
    // read the file line by line
    while ((read = getline(&line, &len, fp)) != -1) {
        words = extractWords(line);             // extract words e.g.) StudentId, Pass
        if(strcmp(words, studentId) == 0){
            idFlg = 1;
        }else if(idFlg == 1 && strcmp(words, password) == 0){   // check studentId and pass
            account->studentId = studentId;     // copy the id to account structure
            account->password = password;
            return account;
        }else if(counter == ACCOUNTLAST){
            idFlg = 0;
        }
        counter++;
        free(words);
    }
    fclose(fp);
    return account;
}

char *extractWords(char *line){
    
    char *words = malloc(sizeof(char) * CHARLENGTH);
    int length = (int)(strlen(line) - 2);   // subtract '"' + '\n'
    int checkPoint = -1;
    
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
