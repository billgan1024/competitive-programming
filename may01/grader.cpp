#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include"factories.h"

int main(){
    int N, Q;
    assert(scanf("%i %i", &N, &Q) == 2);
    int *A = (int*)malloc(sizeof(int) * (N - 1));
    int *B = (int*)malloc(sizeof(int) * (N - 1));
    int *D = (int*)malloc(sizeof(int) * (N - 1));
    for(int a = 0; a < N - 1; a++){
        assert(scanf("%i %i %i", A + a, B + a, D + a) == 3);
    }
    Init(N, A, B, D);
    for(int a = 0; a < Q; a++){
        int S, T;
        assert(scanf("%i %i", &S, &T) == 2);
        int *X = (int*)malloc(sizeof(int) * S);
        int *Y = (int*)malloc(sizeof(int) * T);
        for(int b = 0; b < S; b++){
            assert(scanf("%i", X + b) == 1);
        }
        for(int b = 0; b < T; b++){
            assert(scanf("%i", Y + b) == 1);
        }
        printf("%i\n", Query(S, X, T, Y));
        free(X);
        free(Y);
    }
    free(A);
    free(B);
    free(D);
}