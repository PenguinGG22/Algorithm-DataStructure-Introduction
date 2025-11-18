#include <stdio.h>
#include <stdlib.h>

void rotate(int arr[], int size, int k){
    if(k == 0) return;
    if(k < 0) k += size;
    k %= size;

    int *temp = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        int index = (i + k) % size;
        temp[index] = arr[i];
    }

    for (int i = 0; i < size; i++) {
        arr[i] = temp[i];
    }

    free(temp);
}

int main(){
    int size = 0, k = 0;
    printf("배열의 크기 입력 : ");
    scanf("%d", &size);

    int *arr = (int*)malloc(size * sizeof(int));
    printf("배열 입력 : ");
    for(int i = 0; i < size; i++){
        scanf("%d", arr + i);
    }

    printf("회전 계수(k) 입력 : ");
    scanf("%d", &k);

    rotate(arr, size, k);

    for(int i = 0; i < size; i++){
        printf("%d ", *(arr + i));
    }

    free(arr);
    return 0;
}
