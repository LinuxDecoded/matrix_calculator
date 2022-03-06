// #define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<ctype.h>

struct dimensions{
    int row;
    int col;
};

//User Defined Function Declaration
struct dimensions readTwoIdenticalDimensions();
void readDimentions(struct dimensions *dimensions, char name[]);
void readMatrix(int array[10][10], int rows, int colums);
void readMatrixWithInstructions(int matrix[10][10], char name[],int rows,int cols);
void printMatrix(int array[10][10], int rows, int colums);
void matrixAddSub(int arrayone[10][10], int arraytwo[10][10], int rows, int colums, int mul);
void matrixMultiply(int arrayone[10][10], int arraytwo[10][10], int rowsA, int columsA, int columsB);

int main(void){

    /* int i, j, k; //used in for loops */

    int matrixA[10][10]; // initialized at 10 just to have it initialized
    int matrixB[10][10];
    /* int rowA, colA; */
    /* int rowB, colB; */
    int operation;//used in swtich statements
    char again = 'Y';
    int scalar = 0;
    int add = 1;
    int sub = -1;

    while (again == 'Y'){


        //this is the operation menu just type A, B, C or D to calculate
        printf("\nOperation Menu\n");
        printf("\t1. to Add\n");
        printf("\t2. to Subtract\n");
        printf("\t3. to Multiply two matrices\n");
        printf("Enter yout choice: ");
        scanf(" %d", &operation);

        struct dimensions d;
        struct dimensions da,db;

        switch (operation){

        case 1:
            d = readTwoIdenticalDimensions();
            readMatrixWithInstructions(matrixA,"A",d.row,d.col);
            readMatrixWithInstructions(matrixB,"B",d.row,d.col);

            printf("\nThe Sum of matrixA + matrixB is : \n");
            matrixAddSub(matrixA, matrixB, d.row,d.col, add);

            break;

        case 2:

            d = readTwoIdenticalDimensions();
            readMatrixWithInstructions(matrixA,"A",d.row,d.col);
            readMatrixWithInstructions(matrixB,"B",d.row,d.col);

            printf("\nThe Sum of matrixA + matrixB is : \n");
            matrixAddSub(matrixA, matrixB, d.row,d.col, sub);

            break;

        case 3:
            //when mulotiplying arrays matrixA colum # has to equal matrixB row #
            readDimentions(&da, "A");
            readDimentions(&db, "B");

            // Column of first matrix should be equal to column of second matrix and
            while (da.col != db.row)
            {
                printf("\n\nError! column of first matrix not equal to row of second.\n\n");
                readDimentions(&da, "A");
                readDimentions(&db, "B");
            }
            readMatrixWithInstructions(matrixA,"A",da.row,da.col);
            readMatrixWithInstructions(matrixB,"B",db.row,db.col);

            //multiplyng arrays
            matrixMultiply(matrixA, matrixB, da.row, da.col, db.col);

            break;

        default:
            printf("\nIncorrect option! Please choose a number 1-4.");
            break;
        }

        printf("\n\nDo you want to calculate again? Y/N\n");
        scanf(" %c", &again);
        again = toupper(again);
    }
    printf("\n\nGoodbye!\n\n");

    return 0;
}
struct dimensions readTwoIdenticalDimensions(){
    struct dimensions da,db;
    readDimentions(&da, "A");
    readDimentions(&db, "B");

    while ((da.row != db.row) || (da.col != db.col)){ // fixed from && to ||
        printf("\nMatrices must be the same size\n");

        readDimentions(&da, "A");
        readDimentions(&db, "B");
    }
    return da;
}

void readDimentions(struct dimensions* d, char name[]){
    printf("\nEnter the #rows and #cols for matrix %s: ",name);
    scanf("%d%d",&( d->row ), &( d->col ));
}

void readMatrixWithInstructions(int matrix[10][10], char name[],int rows,int cols){
    printf("\n\tEnter elements of Matrix %s a %d x %d matrix.\n",name, rows, cols); // with the %d we remember the user the dimentions of the array
    readMatrix(matrix, rows, cols);
    printf("\n\t\tMatrix %s\n\n",name);
    printMatrix(matrix, rows, cols);
}

//User Defined Function Definition
void readMatrix(int array[10][10], int rows, int colums){
    int i, j;
    for (i = 0; i < rows; i++){
        printf("\t%d entries for row %d: ", colums, i + 1);
        for (j = 0; j < colums; j++){
            scanf("%d", &array[i][j]);
        }
    }

    return;
}

void printMatrix(int array[10][10], int rows, int colums){
    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < colums; j++){
            printf("\t%d", array[i][j]);
        }
        printf("\n");
    }
}


void matrixAddSub(int arrayone[10][10], int arraytwo[10][10], int rows, int colums, int mul){
    int i, j;
    int sumM[10][10];
    int scaM[10][10];
    for (i = 0; i < rows; i++){
        for (j = 0; j < colums; j++){
            scaM[i][j] = mul * arraytwo[i][j];
        }
    }


    for (i = 0; i < rows; i++){
        for (j = 0; j < colums; j++){
            sumM[i][j] = arrayone[i][j] + scaM[i][j];
            printf("\t%d", sumM[i][j]);
        }
        printf("\n");
    }
}

void matrixMultiply(int arrayone[10][10], int arraytwo[10][10], int rowsA, int columsA,int columsB){
    int i, j, k;
    int mulM[10][10];

    // Initializing all elements of result matrix to 0
    for (i = 0; i<rowsA; ++i)
        for (j = 0; j<columsB; ++j)
        {
            mulM[i][j] = 0;
        }

    // Multiplying matrices a and b and
    // storing result in result matrix
    for (i = 0; i<rowsA; ++i)
        for (j = 0; j<columsB; ++j)
            for (k = 0; k<columsA; ++k)
            {
                mulM[i][j] += arrayone[i][k] * arraytwo[k][j];
            }
    printf("\nOutput Matrix:\n");
    for (i = 0; i<rowsA; ++i) {
        for (j = 0; j<columsB; ++j)
        {
            printf("\t%d ", mulM[i][j]);
            if (j == columsB - 1)
                printf("\n\n");
        }
    }
}