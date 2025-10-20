#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char Name[10];
    int ID;
    int Score; 
} Student;

// Sort function
void swap(Student* a, Student* b) {
    Student temp = *a;
    *a = *b;
    *b = temp;
}
int partition(Student arr[], int low, int high) {
    int pivotScore = arr[high].Score; 
    int i = (low - 1); 

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].Score <= pivotScore) {
            i++; 
            swap(&arr[i], &arr[j]); 
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
// QuickSort function
void quickSort(Student arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
// BubbleSort function
void bubbleSort(Student arr[], int n) {
    int i, j;
    
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j].Score > arr[j + 1].Score) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}
// SelectionSort function
void selectionSort(Student arr[], int n) {
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j].Score < arr[min_idx].Score) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(&arr[min_idx], &arr[i]);
        }
    }
}

// SquentialSearch function
int sequentialSearch(Student arr[], int size, char key[], int searchType) {
    for (int i = 0; i < size; i++) {
        if (searchType == 1) {
            if (arr[i].ID == atoi(key)) {
                return i;
            }
        } else if (searchType == 2) {
            if (strcmp(arr[i].Name, key) == 0) {
                return i;
            }
        }
    }
    return -1;
}

// Save-Load File function
void saveToFile(const Student arr[], int size) {
    FILE* fp = fopen("students.txt", "w");
    if (fp == NULL) {
        printf("\n[오류] 파일을 여는 데 실패했습니다.\n");
        return;
    }
    fprintf(fp, "%d\n", size);
    for (int i = 0; i < size; i++) {
        fprintf(fp, "%s %d %d\n", arr[i].Name, arr[i].ID, arr[i].Score);
    }
    fclose(fp);
    printf("\n[성공] 'students.txt' 파일에 정보가 저장되었습니다.\n");
}
void loadFromFile(Student** arr_ptr, int* count_ptr) {
    FILE* fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("[알림] 저장된 학생 파일이 없습니다. 새로 시작합니다.\n");
        return;
    }
    fscanf(fp, "%d", count_ptr);
    if (*count_ptr <= 0) {
        *count_ptr = 0;
        fclose(fp);
        return;
    }
    *arr_ptr = (Student*)malloc(*count_ptr * sizeof(Student));
    if (*arr_ptr == NULL) {
        printf("[오류] 메모리 할당 실패\n");
        *count_ptr = 0;
        fclose(fp);
        return;
    }
    for (int i = 0; i < *count_ptr; i++) {
        fscanf(fp, "%9s %d %d", (*arr_ptr)[i].Name, &(*arr_ptr)[i].ID, &(*arr_ptr)[i].Score);
    }
    fclose(fp);
    printf("[성공] 'students.txt' 파일에서 %d명의 학생 정보를 불러왔습니다.\n", *count_ptr);
}

int main() {
    Student* students = NULL;
    int Count = 0;

    loadFromFile(&students, &Count);

    if (Count == 0) {
        printf("입력할 학생의 수 : ");
        scanf("%d", &Count);

        if (Count > 0) {
            students = (Student*)malloc(Count * sizeof(Student));
            if (students == NULL) {
                printf("메모리 할당에 실패했습니다.\n");
                return 1;
            }
                for(int i = 0; i < Count; i++) {
                printf("학생%d의 정보 입력(이름, 학번, 점수) : ", i + 1);
                scanf("%9s", students[i].Name);
                scanf("%d", &students[i].ID);
                scanf("%d", &students[i].Score);
            }
        }
    }

    int commandSort = 0;
    printf("---------------------\n");
    printf("1: BubbleSort\n");
    printf("2: SelectionSort\n");
    printf("3: QuickSort\n");
    printf("---------------------\n");
    printf("정렬할 방식을 선택하세요 : ");
    scanf("%d", &commandSort);
    if(commandSort == 1){
        bubbleSort(students, Count);
    }
    else if(commandSort == 2){
        selectionSort(students, Count);
    }
    else {
        quickSort(students, 0, Count - 1);
    }
    
    while(1){
        printf("\n--- [학생 성적 관리 프로그램] ---\n");
        printf("0: 학생 검색\n");
        printf("1: 최고/최저 성적 학생 보기\n");
        printf("2: 성적 범위 검색\n");
        printf("3: 성적 통계 보기\n");
        printf("4: 파일에 저장하기\n");
        printf("5: 프로그램 종료\n");
        printf("----------------------------------\n");

        int Command;
        printf("명령어를 입력하세요: ");
        scanf("%d", &Command);

        if(Command == 0){ // 0.학생 검색
            int searchType;
            char searchKey[20];
            printf("\n탐색 방법을 선택하세요 (1: 학번, 2: 이름): ");
            scanf("%d", &searchType);

            if (searchType == 1) {
                printf("검색할 학번을 입력하세요: ");
                scanf("%s", searchKey);
            }
            else if (searchType == 2) {
                printf("검색할 이름을 입력하세요: ");
                scanf("%s", searchKey);
            }
            
            int foundIndex = sequentialSearch(students, Count, searchKey, searchType);

            if (foundIndex != -1) { 
            printf("\n---- 검색 결과 ----\n");
            printf("학생을 찾았습니다.\n");
            printf("이름: %s\n", students[foundIndex].Name);
            printf("학번: %d\n", students[foundIndex].ID);
            printf("점수: %d\n", students[foundIndex].Score);
            printf("--------------------");
            } 
            else {
                printf("해당 학생을 찾을 수 없습니다.\n");
            }
        }
        else if(Command == 1){ // 1.최고/최저 성적 학생 보기
            printf("--------------------\n");
            printf("성적이 가장 높은 학생\n");
            printf("이름: %s\n", students[Count - 1].Name);
            printf("학번: %d\n", students[Count - 1].ID);
            printf("점수: %d\n", students[Count - 1].Score);
            printf("--------------------\n");
            printf("성적이 가장 낮은 학생\n");
            printf("이름: %s\n", students[0].Name);
            printf("학번: %d\n", students[0].ID);
            printf("점수: %d\n", students[0].Score);
            printf("--------------------");
        }
        else if(Command == 2){ // 2.성적 범위 검색
            int rangeMin, rangeMax;
            printf("검색 성적 범위 입력(최소, 최대) : ");
            scanf("%d %d", &rangeMin, &rangeMax);
            for(int i = 0; i < Count; i++){
                int Score = students[i].Score;
                if(Score >= rangeMin && Score <= rangeMax) {
                    printf("이름: %s\n", students[i].Name);
                    printf("학번: %d\n", students[i].ID);
                    printf("점수: %d\n", students[i].Score);
                }
            }
        }
        else if(Command == 3){ // 3.성적 통계 보기
            double sum = 0;
            for(int i = 0; i < Count; i++) {
                sum += students[i].Score;
            }
            double average = sum / Count;

            double median;
            if (Count % 2 == 1) {
                median = students[Count / 2].Score;
            } else {
                median = (students[Count / 2 - 1].Score + students[Count / 2].Score) / 2.0;
            }

            int mode = students[0].Score;
            int maxFreq = 1;
            int currentFreq = 1;

            for (int i = 1; i < Count; i++) {
                if (students[i].Score == students[i-1].Score) {
                    currentFreq++;
                } else {
                    if (currentFreq > maxFreq) {
                        maxFreq = currentFreq;
                        mode = students[i-1].Score;
                    }
                    currentFreq = 1;
                }
            }
            if (currentFreq > maxFreq) {
                maxFreq = currentFreq;
                mode = students[Count - 1].Score;
            }

            printf("\n---- 성적 통계 ----\n");
            printf("평균 점수: %.2f\n", average);
            printf("중앙값: %.1f\n", median);

            if (maxFreq > 1) {
                printf("최빈값: %d (%d회 등장)\n", mode, maxFreq);
            } else {
                printf("최빈값: 없음\n");
            }
            printf("--------------------");
        }
        else if(Command == 4) { // 4.파일에 저장하기
            saveToFile(students, Count);
        }
        else { // Program Escape
            printf("프로그램을 종료합니다.\n");
            break;
        }
    }

    free(students);
    return 0;
}
