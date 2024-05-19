#include <stdio.h>
#include "functions.h"

int main() 
{
    int choice;
    
    do {
        printf("\n*************************************************\n");
        printf("\t\tMENU\n");
        printf("1. Add Student\n");
        printf("2. Delete Student\n");
        printf("3. Print All Student Details\n");
        printf("4. Print Details of One Student\n");
        printf("5. Calculate and Print Details of All Students\n");
        printf("6. Calculate and Print Rank of Students\n");
        printf("7. Exit\n");
        printf("*************************************************\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        if (choice != 7) {
            options(choice);
        }
    } while (choice != 7);
    
    return 0;
}
