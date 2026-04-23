void cummulativeGrade(const float *arrGradebook, const int *arrWeights, int aSize, float *cummGrade);
char letterGrade(const float *cummGrade);
float GPA(const float *cummGrade);
void printGrade(const float *cummGrade);
void sortGradebook(const float *arrGradebook, int *arrWeights, int aSize, const int *indexes);
void printWeights(const int *arrWeights, int aSize);