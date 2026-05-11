#include <stdio.h>


//input validity checker
static int invalidInput(const float *arrGradebook, const int *arrWeights, int aSize, float *cummGrade){
    if (arrGradebook == NULL || arrWeights == NULL || aSize <= 0 || cummGrade == NULL)
        return 1;
    return 0; 
}

//returns total cummulative grade
void cummulativeGrade(const float *arrGradebook, const int *arrWeights, int aSize, float *cummGrade){
    if (invalidInput(arrGradebook, arrWeights, aSize, cummGrade))
        return;

    *cummGrade = 0; //hard reset

    for (int i = 0; i < aSize; i++){ 
        *cummGrade += (arrGradebook[i] * (float) arrWeights[i] / 100);
    } return;
}

//simple letter grade function
char letterGrade(const float *cummGrade){
    if (cummGrade == NULL){
        return 'E'; //error
    } else if (*cummGrade >= 90){
        return 'A';
    } else if (*cummGrade >= 80){
        return 'B';
    } else if (*cummGrade >= 70){
        return 'C';
    } else if (*cummGrade >= 60){
        return 'D';
    } return 'F';
}

float GPA(const float *cummGrade){
    if (cummGrade == NULL)
        return -1;
    
    int header; //header is related to the letter grade (pretty much just exactly high school grading)
    float tail; //tail is the +/-/neutral relation to the letter grade. +-0.3 gpa ponits
        switch (letterGrade(cummGrade)){
            case 'A': 
                header = 4;
                tail = *cummGrade - 90;
                if (tail >= 7)
                    return 4;
                break;
            case 'B':
                header = 3;
                tail = *cummGrade - 80;
                break;
            case 'C':
                header = 2;
                tail = *cummGrade - 70;
                break;
            case 'D':
                header = 1;
                tail = *cummGrade - 60;
                break;
            default:
                return 0; //all of these switch cases are self explanatory.
        }

        if (tail < 3){ //this is the part that figures out the decimal section of the GPA
            return (header - 0.3);
        } else if (tail >= 7){
            return (header + 0.3);
        } return header;
}

//this function prints the current cumulative grade and gradebook of the user.
void printGrade(const float *cummGrade){
    if (cummGrade == NULL)
        return;
    
    printf("\nCummulative grade: %.4f\n", *cummGrade);
    printf("Letter grade: %c\n", letterGrade(cummGrade));
    printf("GPA: %.2f\n\n", GPA(cummGrade));
}

//this is a helper function for the first half of sortGradebook. this is how indexes are not repeatedly stored
static int isNotElement (const int *indexes, int aSize, int key){
    for (int i = 0; i < aSize; i++){
        if (*(indexes + i) == key)
            return 0;
    } return 1;
}

//this is a helper function for the second half of sortGradebook. this is how the weight totals get capped to 100%
static int weightsTotal (const int *arrWeights, int aSize){
    int sum = 0;

    for (int i = 0; i < aSize; i++){
        sum += *(arrWeights + i); //summation loop
    } return sum;
}

//the meat and potatoes. first "sorts" the indexes of the gradebook into so that the indexes of the largest elements are first/smallest last.
//then adjusts the weight array based off of the "indexes" array
void sortGradebook(const float *arrGradebook, int *arrWeights, int aSize, int *indexes){
    if (invalidInput(arrGradebook, arrWeights, aSize, (float *) indexes))
        return;
    
    int largest;

    for (int j = 0; j < aSize; j++){    
        int max = -1; //this variable is very important.
        for (int i = 0; i < aSize; i++){
            if (*(arrGradebook + i) > max && isNotElement(indexes, aSize, i)){ //large grade AND this element hasn't been stored yet
                max = *(arrGradebook + i); //through the loop, this ensures that the maximum, unstored element is next to be stored
                largest = i; //largest index. pretty simple
            } 
        } *(indexes + j) = largest; //stores the index. 
    }

    /***** temporary print section for me to figure out the section beforehand *****/
    // for (int i = 0; i < aSize; i++){
    //     printf("%d", *(indexes + i));
    // } printf("\n");

    //this line really just resets weights down to their minimum values, so that the highest gradebook elements can have maximized weights. we're trying to get the highest grade out here.
    arrWeights[0] = 5, arrWeights[1] = 20; arrWeights[5] = 10; arrWeights[6] = 15;
    //maxWeights are the maximum weights allowed by the instructor. (aka, can't shoot the easy lab scores incredibly high)
    int maxWeights[7] = {15, 40, 5, 10, 15, 20, 25};

    for (int i = 0; i < aSize; i++){
        while (*(arrWeights + *(indexes + i)) < maxWeights[*(indexes + i)] && weightsTotal(arrWeights, aSize) < 100){ //this sucks to read. pretty much just keeps weights in the defined bounds
            *(arrWeights + *(indexes + i)) += 5; //all weight minimums and maximums are in multiples of 5. this is really just the maximum efficiency scalar
        }
    }

    return;
}

//prints the weights at a given time. really just used before and after weights are adjusted
void printWeights(const int *arrWeights, int aSize){
    if (arrWeights == NULL || aSize <= 0)
        return;

    printf("Weights are as follows: ");
    for (int i = 0; i < aSize; i++){
        printf("%d ", *(arrWeights + i)); //easy print loop
    } printf("\n");
    return;
}
