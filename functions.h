#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define MAX 1000

struct Student {
    int roll_number;
    char name[50];
    int ISA1[3];
    int ISA2[3];
    int ISA3[3];
    int totalMarks;
};

void options(int p);
void addStudent();
void deleteStudent();
void printStudentDetails();
void printOneStudentDetails();
void calculateAndPrintDetails();
void calculateRank();

#endif
