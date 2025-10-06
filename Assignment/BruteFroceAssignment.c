#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(){
    srand(time(NULL));
    char Alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    int Alpha_len = strlen(Alphabet);
    char all_chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!#&*";
    int chars_len = strlen(all_chars);

    char password[6];
    char password_guess[6];
    int cnt = 0;

    clock_t start, end;
    double elapsed_time;

    password[0] = Alphabet[rand() % strlen(Alphabet)];
    for(int i=1; i < 5; i++){
        password[i] = all_chars[rand() % strlen(all_chars)];
    }
    password[5] = '\0';
    printf("설정 비밀번호 : %s\n", password);

    start = clock();
    for(int c5=0; c5 < chars_len; c5++){
        for(int c4=0; c4 < chars_len; c4++){
            for(int c3=0; c3 < chars_len; c3++){
                for(int c2=0; c2 < chars_len; c2++){
                    for(int c1=0; c1 < chars_len; c1++){
                        for(int c0=0; c0 < Alpha_len; c0++){
                            password_guess[0] = Alphabet[c0];
                            password_guess[1] = all_chars[c1];
                            password_guess[2] = all_chars[c2];
                            password_guess[3] = all_chars[c3];
                            password_guess[4] = all_chars[c4];
                            password_guess[5] = '\0';
                            
                            printf("시도 비밀번호 : %s\n", password_guess);
                            cnt++;

                            if(strcmp(password, password_guess) == 0){
                                end = clock();
                                elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;

                                printf("찾은 비밀번호 : %s\n", password_guess);
                                printf("시도된 횟수 : %d\n", cnt);
                                printf("걸린 시간 : %.2f초", elapsed_time);

                                return 0;
                            }
                        }
                    }
                }   
            }
        }
    }
}