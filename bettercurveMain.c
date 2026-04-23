#include <stdio.h>
#include "bettercurve.h"

void main(void){
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


    return;
}