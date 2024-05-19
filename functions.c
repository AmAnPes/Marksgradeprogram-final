#include "functions.h"
#include <stdio.h>
#include <stdlib.h>

void options(int p) 
{
    switch (p) {
        case 1:
            addStudent();
            break;
        case 2:
            deleteStudent();
            break;
        case 3:
            printStudentDetails();
            break;
        case 4:
            printOneStudentDetails();
            break;
        case 5:
            calculateAndPrintDetails();
            break;
        case 6:
            calculateRank();
            break;
        default:
            printf("Invalid option\n");
            break;
    }
}

void addStudent() 
{
    FILE *fp;
    fp = fopen("studentdetails.txt", "a");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    struct Student newStudent;
    printf("Enter the roll number: ");
    scanf("%d", &newStudent.roll_number);

    printf("Enter the name: ");
    scanf("%s", newStudent.name);

    printf("Enter marks for ISA1, ISA2, and ISA3: ");
    scanf("%d %d %d %d %d %d %d %d %d", 
          &newStudent.ISA1[0], &newStudent.ISA1[1], &newStudent.ISA1[2], 
          &newStudent.ISA2[0], &newStudent.ISA2[1], &newStudent.ISA2[2], 
          &newStudent.ISA3[0], &newStudent.ISA3[1], &newStudent.ISA3[2]);

    fprintf(fp, "%d %s %d %d %d %d %d %d %d %d %d\n", 
            newStudent.roll_number, newStudent.name, 
            newStudent.ISA1[0], newStudent.ISA1[1], newStudent.ISA1[2], 
            newStudent.ISA2[0], newStudent.ISA2[1], newStudent.ISA2[2], 
            newStudent.ISA3[0], newStudent.ISA3[1], newStudent.ISA3[2]);

    fclose(fp);
}

void deleteStudent() {
    int rollNumberToDelete;
    printf("Enter the roll number of the student to delete: ");
    scanf("%d", &rollNumberToDelete);

    FILE *originalFile, *tempFile;
    originalFile = fopen("studentdetails.txt", "r");
    if (originalFile == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        printf("Error opening temp file.\n");
        fclose(originalFile);
        exit(1);
    }

    struct Student student;
    int found = 0;
    while (fscanf(originalFile, "%d %s %d %d %d %d %d %d %d %d %d",&student.roll_number, student.name,&student.ISA1[0], &student.ISA1[1], &student.ISA1[2], &student.ISA2[0], &student.ISA2[1], &student.ISA2[2],&student.ISA3[0], &student.ISA3[1], &student.ISA3[2]) != EOF) {
        if (student.roll_number != rollNumberToDelete) {
            fprintf(tempFile, "%d %s %d %d %d %d %d %d %d %d %d\n",student.roll_number, student.name,student.ISA1[0], student.ISA1[1], student.ISA1[2],student.ISA2[0], student.ISA2[1], student.ISA2[2],student.ISA3[0], student.ISA3[1], student.ISA3[2]);
        } else {
            found = 1;
        }
    }

    fclose(originalFile);
    fclose(tempFile);

    if (!found) {
        printf("Student with roll number %d not found.\n", rollNumberToDelete);
        remove("temp.txt");
    } else {
        remove("studentdetails.txt");
        rename("temp.txt", "studentdetails.txt");
        printf("Student with roll number %d deleted successfully.\n", rollNumberToDelete);
    }
}

void printStudentDetails() {
    FILE *fp;
    fp = fopen("studentdetails.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    struct Student student;
    printf("\n-------------------------------------------------\n");
    
    while (fscanf(fp, "%d %s %d %d %d %d %d %d %d %d %d",&student.roll_number, student.name,&student.ISA1[0], &student.ISA1[1], &student.ISA1[2],&student.ISA2[0], &student.ISA2[1], &student.ISA2[2],&student.ISA3[0], &student.ISA3[1], &student.ISA3[2]) != EOF) {
        printf("Roll Number: %d\n", student.roll_number);
        printf("Name: %s\n", student.name);
        printf("ISA1 Marks: %d %d %d\n", student.ISA1[0], student.ISA1[1], student.ISA1[2]);
        printf("ISA2 Marks: %d %d %d\n", student.ISA2[0], student.ISA2[1], student.ISA2[2]);
        printf("ISA3 Marks: %d %d %d\n", student.ISA3[0], student.ISA3[1], student.ISA3[2]);
    }
    printf("\n-------------------------------------------------\n");
    fclose(fp);
}

void printOneStudentDetails()
{
    FILE *fp;
    fp = fopen("studentdetails.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    int rollNumber;
    printf("Enter the roll number of the student: ");
    scanf("%d", &rollNumber);
    printf("\n-------------------------------------------------\n");
    struct Student student;
    int found = 0;
    while (fscanf(fp, "%d %s %d %d %d %d %d %d %d %d %d",&student.roll_number, student.name,&student.ISA1[0], &student.ISA1[1], &student.ISA1[2],&student.ISA2[0], &student.ISA2[1], &student.ISA2[2],&student.ISA3[0], &student.ISA3[1], &student.ISA3[2]) != EOF) {
        if (student.roll_number == rollNumber) {
            printf("\nRoll Number: %d\n", student.roll_number);
            printf("Name: %s\n", student.name);
            printf("ISA1 Marks: %d %d %d\n", student.ISA1[0], student.ISA1[1], student.ISA1[2]);
            printf("ISA2 Marks: %d %d %d\n", student.ISA2[0], student.ISA2[1], student.ISA2[2]);
            printf("ISA3 Marks: %d %d %d\n", student.ISA3[0], student.ISA3[1], student.ISA3[2]);
            found = 1;
            break;
        }
    }
    printf("\n-------------------------------------------------\n");
    if (!found) {
        printf("Student not found.\n");
    }
    
    fclose(fp);
}

void calculateAndPrintDetails() 
{
    FILE *fp;
    fp = fopen("studentdetails.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    printf("\n-------------------------------------------------\n");
    struct Student student;
    while (fscanf(fp, "%d %s %d %d %d %d %d %d %d %d %d",&student.roll_number, student.name,&student.ISA1[0], &student.ISA1[1], &student.ISA1[2],&student.ISA2[0], &student.ISA2[1], &student.ISA2[2],&student.ISA3[0], &student.ISA3[1], &student.ISA3[2]) != EOF) {
        printf("\nRoll Number: %d\n", student.roll_number);
        printf("Name: %s\n", student.name);

        int totalMarks = 0;
        for (int i = 0; i < 3; i++) {
            totalMarks += student.ISA1[i] + student.ISA2[i] + student.ISA3[i];
        }
        double avgMarks = totalMarks / 9.0;
        printf("Total Marks: %d\n", totalMarks);
        printf("Average Marks: %.2f\n", avgMarks);
    }
    printf("\n-------------------------------------------------\n");
    fclose(fp);
}

void calculateRank() 
{
    struct Student students[MAX];
    int numStudents = 0;
    
    FILE *fp;
    fp = fopen("studentdetails.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fscanf(fp, "%d %s %d %d %d %d %d %d %d %d %d",&students[numStudents].roll_number, students[numStudents].name,&students[numStudents].ISA1[0], &students[numStudents].ISA1[1], &students[numStudents].ISA1[2],&students[numStudents].ISA2[0], &students[numStudents].ISA2[1], &students[numStudents].ISA2[2],&students[numStudents].ISA3[0], &students[numStudents].ISA3[1], &students[numStudents].ISA3[2]) != EOF) {
        students[numStudents].totalMarks = 0;
        for (int i = 0; i < 3; i++) {
            students[numStudents].totalMarks += students[numStudents].ISA1[i] + students[numStudents].ISA2[i] + students[numStudents].ISA3[i];
        }
        numStudents++;
    }
    fclose(fp);

    
    for (int i = 0; i < numStudents - 1; i++) {
        for (int j = 0; j < numStudents - i - 1; j++) {
            if (students[j].totalMarks < students[j + 1].totalMarks) {
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
    printf("\n-------------------------------------------------\n");
    printf("\nRankings:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Rank %d: %s (Roll Number: %d) - Total Marks: %d\n", i + 1, students[i].name, students[i].roll_number, students[i].totalMarks);
    }
    printf("\n-------------------------------------------------\n");
}
