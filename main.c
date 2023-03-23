#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **allocate(int rows, int cols);
void generateValues(int **matrix, int rows, int cols);
void deallocate(int **matrix, int rows);
void printMatrix(int **matrix, int rows, int cols);
int findValue(int **matrix, int rows, int cols, int value);
void swapMinMax(int **matrix, int rows, int cols);
int maxColumnSum(int **matrix, int rows, int cols);
void setEvenToZero(int **matrix, int rows, int cols);


int main() {
    int rows, cols, value, maxCol;
    int **matrix;

    // prompt user to enter matrix size
    printf("Zadejte počet řádků matice: ");
    scanf("%d", &rows);
    printf("Zadejte počet sloupců matice: ");
    scanf("%d", &cols);

    // allocate memory for matrix
    matrix = allocate(rows, cols);

    // generate values for matrix
    generateValues(matrix, rows, cols);

    // print out the values in the matrix
    printf("Hodnoty matice jsou:\n");
    printMatrix(matrix, rows, cols);

    // find a value in the matrix
    printf("\nZadejte hledanou hodnotu: ");
    scanf("%d", &value);
    if (findValue(matrix, rows, cols, value)) {
        printf("Hodnota %d byla v matici nalezena :)\n", value);
    } else {
        printf("Hodnota %d se v matici nenachazi :/\n", value);
    }

    // swap the minimum and maximum values in the matrix
    swapMinMax(matrix, rows, cols);
    printf("\nMinimální a maximální prvek byly prohozeny.\n");
    printMatrix(matrix, rows, cols);

    // set even elements in the matrix to zero
    setEvenToZero(matrix, rows, cols);
    printf("\nSudé prvky nastaveny na 0\n");
    printMatrix(matrix, rows, cols);

    // find the column with the maximum sum
    maxCol = maxColumnSum(matrix, rows, cols);
    printf("Sloupe č. %d má maximální součet prvků.\n", (maxCol + 1));

    // free dynamically allocated memory
    deallocate(matrix, rows);

    return 0;
}


int **allocate(int rows, int cols) {
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }
    return matrix;
}

void generateValues(int **matrix, int rows, int cols) {
    srand(time(NULL));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 100;  // generate random integer between 0-99
        }
    }
}

void deallocate(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void printMatrix(int **matrix, int rows, int cols) {
    printf("\n---------------------\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("---------------------\n");
}

int findValue(int **matrix, int rows, int cols, int value) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == value) {
                return 1;
            }
        }
    }
    return 0;
}

void swapMinMax(int **matrix, int rows, int cols) {
    int max_row = 0, max_col = 0, min_row = 0, min_col = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] > matrix[max_row][max_col]) {
                max_row = i;
                max_col = j;
            }
            if (matrix[i][j] < matrix[min_row][min_col]) {
                min_row = i;
                min_col = j;
            }
        }
    }
    int temp = matrix[max_row][max_col];
    matrix[max_row][max_col] = matrix[min_row][min_col];
    matrix[min_row][min_col] = temp;
}

void setEvenToZero(int **matrix, int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(matrix[i][j] % 2 == 0) {
                matrix[i][j] = 0;
            }
        }
    }
}

int maxColumnSum(int **matrix, int rows, int cols) {
    int maxSum = 0;
    int maxColumn = 0;

    for(int j = 0; j < cols; j++) {
        int sum = 0;
        for(int i = 0; i < rows; i++) {
            sum += matrix[i][j];
        }
        if(sum > maxSum) {
            maxSum = sum;
            maxColumn = j;
        }
    }

    return maxColumn;
}