#include <stdio.h>
#define SIZE 10

int arr[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

void recursiveInsertSort(int N){
    if(N <= 1){
        return;
    }
    recursiveInsertSort(N - 1);
    
    int key = arr[N - 1];
    int i = N - 2;
    while(i >= 0 && arr[i] > key){
        arr[i + 1] = arr[i];
        i--;
    }
    arr[i + 1] = key;
}

int main(){
    int N = SIZE;

    recursiveInsertSort(N);

    return 0;
}