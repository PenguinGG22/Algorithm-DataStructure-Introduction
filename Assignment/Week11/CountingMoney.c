#include <stdio.h>

int main(){
    int money;
    printf("거스름돈을 입력하세요 : ");
    scanf("%d", &money);

    int arr[8] = {50000, 10000, 5000, 1000, 500, 100, 50, 10};
    int count[8] = {0};

    for(int i = 0; i < 7; i++){
        count[i] = money / arr[i];
        money -= arr[i] * count[i];
    }

    printf("5만원 개수 : %d\n", count[0]);
    printf("1만원 개수 : %d\n", count[1]);
    printf("5천원 개수 : %d\n", count[2]);
    printf("1천원 개수 : %d\n", count[3]);
    printf("500원 개수 : %d\n", count[4]);
    printf("100원 개수 : %d\n", count[5]);
    printf("50원 개수 : %d\n", count[6]);
    printf("10원 개수 : %d", count[7]);
    
    return 0;
}