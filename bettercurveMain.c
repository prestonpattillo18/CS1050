#include <stdio.h>
#include "bettercurve.h"

int main(void){
    #define size 7 //size of all arrays
    float grades[size] = {0}; //gradebook array


    //big block that gets the users gradebook
    printf("Enter your grades in the following sections up to 4 decimal places (ie, 95.1234)\n");
        printf("Interactive checkpoints: ");
            scanf("%f", &grades[0]);
        printf("Labs: ");
            scanf("%f", &grades[1]);
        printf("Mini-Exams: ");
            scanf("%f", &grades[2]);
        printf("Exam 1: ");
            scanf("%f", &grades[3]);
        printf("Exam 2: "); 
            scanf("%f", &grades[4]);
        printf("Exam 3: ");
            scanf("%f", &grades[5]);
        printf("Final Exam: ");
            scanf("%f", &grades[6]);
    
    float const * const ptrGrades = &grades[0];
    int weights[size] = {15, 30, 5, 5, 10, 15, 20}; //weighted sections array
    int *ptrWeights = &weights[0];
    float cumm;
    float *ptrCumm = &cumm;

    //sets the current cummulative grade
    cummulativeGrade(ptrGrades, ptrWeights, size, ptrCumm);

    //prints gradebook as confirmation
    printf("\nYour current gradebook is as follows: ");
        for (int i = 0; i < size; i++){
            printf("%.4f ", grades[i]);
        }
    printWeights(ptrWeights, size);
    printGrade(ptrCumm);

    //this section sorts the weights based off of the highest grades
    int indexArray[size] = {-1, -1, -1, -1, -1, -1, -1};
    int *ptrIndexes = &indexArray[0];
    sortGradebook(ptrGrades, ptrWeights, size, ptrIndexes);

    //this section just goes back and presents the user with after-adjustment weights, grade, letter, and GPA
    cummulativeGrade(ptrGrades, ptrWeights, size, ptrCumm);
    printWeights(ptrWeights, size);
    printGrade(ptrCumm);

    int selection;
    //user menu
    do {
        printf("\n    --- Menu ---\n(1) Reset Grades\n(2) Change a grade\n(3) Calculate curve\n(4) Print Grades\n(-1) Exit\nEnter your selection (integer input): ");
        scanf("%d", &selection);

        switch (selection){
            case 1: // the user re-enters each section's grade
                printf("Enter your grades in the following sections up to 4 decimal places (ie, 95.1234)\n");
                printf("Interactive checkpoints: ");
                    scanf("%f", &grades[0]);
                printf("Labs: ");
                    scanf("%f", &grades[1]);
                printf("Mini-Exams: ");
                    scanf("%f", &grades[2]);
                printf("Exam 1: ");
                    scanf("%f", &grades[3]);
                printf("Exam 2: "); 
                    scanf("%f", &grades[4]);
                printf("Exam 3: ");
                    scanf("%f", &grades[5]);
                printf("Final Exam: ");
                    scanf("%f", &grades[6]);
                cummulativeGrade(ptrGrades, ptrWeights, size, ptrCumm); //readjusts cummulative grade value
                break;
            case 2: //program prompts the user to change one section's grade
                do{
                    printf("Enter the number of which section you would like to change: (1) Interactive Checkpoints    (2) Labs  (3) Mini-Exams  (4) Exam 1  (5) Exam 2  (6) Exam 3  (7) Final Exam\n");
                        scanf("%d", &selection);
                } while (selection < 1 || selection > 7);
                printf("Enter the fixed grade: ");
                switch (selection){
                    case 1:
                        scanf("%f", &grades[0]);
                        break;
                    case 2:
                        scanf("%f", &grades[1]);
                        break;
                    case 3:
                        scanf("%f", &grades[2]);
                        break;
                    case 4:
                        scanf("%f", &grades[3]);
                        break;
                    case 5:
                        scanf("%f", &grades[4]);
                        break;
                    case 6:
                        scanf("%f", &grades[5]);
                        break;
                    case 7:
                        scanf("%f", &grades[6]);
                        break;
                } cummulativeGrade(ptrGrades, ptrWeights, size, ptrCumm); //readjusts the cummulative grade value
                break;
            case 3: //this selection prints only the weights that a user should adjust to
                for (int i = 0; i < size; i++){
                    indexArray[i] = -1;
                }
                sortGradebook(ptrGrades, ptrWeights, size, ptrIndexes);
                printWeights(ptrWeights, size);
                break;
            case 4: //this function prints the user's gradebook with new weights
                printf("\nYour current gradebook is as follows: ");
                    for (int i = 0; i < size; i++){
                        printf("%.4f ", grades[i]);
                    }
                sortGradebook(ptrGrades, ptrWeights, size, ptrIndexes);
                printGrade(ptrCumm);
                break;
        }
    } while (selection != -1);

    return 0;
}
