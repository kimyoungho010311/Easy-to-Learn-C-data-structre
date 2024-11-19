#include <stdio.h>

void delete(int A[], int items, int loc){
    for (int i = items ; i > loc ; i--){
        A[i] = A[i+1];
    }
}