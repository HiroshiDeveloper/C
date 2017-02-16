//
//  header.h
//  Portal
//
//  Created by Hiroshi Tokutomi on 2017-02-10.
//  Copyright © 2017 Hiroshi. All rights reserved.
//

#ifndef header_h
#define header_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define ACCOUNTSPATH "/Users/hiroshi/Documents/Github/C/Portal/Portal/Accounts.txt"
#define STUDENTSPATH "/Users/hiroshi/Documents/Github/C/Portal/Portal/Students.txt"
#define COURSESPATH "/Users/hiroshi/Documents/Github/C/Portal/Portal/Courses.txt"
#define STUDENTSCOURSESPATH "/Users/hiroshi/Documents/Github/C/Portal/Portal/StudentsCourses.txt"
#define ACCOUNTLAST 2
#define COURSESLAST 6
#define STUDENTSLAST 7
#define STUDENTSCOURSESLAST 3
#define CHARLENGTH 256
#define MAXARRAY 20
#define LISTOFSTUDENT 100
#define STUDENTIDLENGTH 10

struct account{
    char *studentId;
    char *password;
};

struct student{
    char *studentId;
    char *name;
    char *gender;
    char *gender2;  // Mr or Ms
    char *gender3;  // He or She
    char *grade;
    char *address;
    char *admission_year;
    char *courses;
};

struct course{
    char *courseId;
    char *name;
};

#endif /* header_h */
