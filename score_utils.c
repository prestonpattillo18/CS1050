#include <stdio.h>

//helper function to keep score values within realistic ranges -- assumes that professors keep grade ranges within 0-100%
static int clampScore(int score){
    if (score < -1){
        return 0;
    } else if (score > 100){
        return 100;
    } 
    return score;
}

//this function counts how many times scores have been put through, tied to "isPassing"
//enter -1 to display the counter
void scoresProcessed(int score){
    if (score == -1){
        printf("Scores processed: %d\n\n", counter);
        return;
    }
    counter++;
    return;
}

//this function simply checks to see if a given score is within passing boundaries
//returns simple t/f values where essentially 1 = 'is passing' and 0 = 'is not passing'
int isPassing(int score){
    scoresProcessed(score);

    if (score >= 60){
        return 1;
    } else
        return 0;
}

//this function returns the letter grade corresponding to the input score using trickle-down if else statements
char letterGrade(int score){
    score = clampScore(score);
    
    if (isPassing(score)){
        if (score >= 90){
            return 'A';
        } else if (score >= 80){
            return 'B';
        } else if (score >= 70){
            return 'C';
        } else
            return 'D';
    } else
        return 'F';
}
