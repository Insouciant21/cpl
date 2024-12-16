#include <stdbool.h>
#include <stdio.h>

typedef struct Matrix {
    double data[5][7];
    int r, c;
} Matrix;

double determinant(Matrix A) {
    Matrix tmp = A;
    double result = 1;
    for (int i = 0; i < tmp.r; i++) {
        if (tmp.data[i][i] == 0) {
            bool swapped = false;
            for (int k = i + 1; k < tmp.r; k++) {
                if (tmp.data[k][i] != 0) {
                    double arr[5];
                    for (int o = 0; o < tmp.c; o++) arr[o] = tmp.data[k][o];
                    for (int o = 0; o < tmp.c; o++) tmp.data[k][o] = tmp.data[i][o];
                    for (int o = 0; o < tmp.c; o++) tmp.data[i][o] = arr[o];
                    result = -result;
                    swapped = true;
                    break;
                }
            }
            if (!swapped) return 0;
        }
        for (int j = i + 1; j < tmp.r; j++) {
            double ratio = tmp.data[j][i] / tmp.data[i][i];
            for (int k = i; k < tmp.c; k++) {
                tmp.data[j][k] = tmp.data[j][k] - ratio * tmp.data[i][k];
            }
        }
    }
    for (int i = 0; i < tmp.r; i++) {
        result = result * tmp.data[i][i];
    }
    return result;
}

void print(Matrix x) {
    for (int i = 0; i < x.r; i++) {
        for (int j = 0; j < x.c; j++)printf("%f ", x.data[i][j]);
        printf("\n");
    }
}

int main() {
    Matrix A, D[4] = {};
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 4; j++)
            scanf("%lf", &A.data[i][j]);
    A.r = 3, A.c = 4;
    for (int k = 0; k < 4; k++) {
        for (int j = 0; j < 3; j++) {
            for (int i = 0; i < 3; i++) {
                if (k != j) D[k].data[i][j] = A.data[i][j];
                else D[k].data[i][j] = A.data[i][3];
            }
        }
        D[k].r = 3, D[k].c = 3;
    }
    double d = determinant(D[3]);
    for (int i = 0; i < 3; i++) {
        printf("%.2lf ", determinant(D[i]) / d);
    }
    return 0;
}