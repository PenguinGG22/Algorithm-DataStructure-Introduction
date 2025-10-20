#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char subjectName[100];
    char chapterName[100];
    int daysRemaining;
    int subjectImportance;
    int studyProgress;
    double priority;
} Chapter;

void merge(Chapter arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Chapter* L = (Chapter*)malloc(n1 * sizeof(Chapter));
    Chapter* R = (Chapter*)malloc(n2 * sizeof(Chapter));

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0; j = 0; k = left;
    while (i < n1 && j < n2) {
        if (L[i].priority >= R[j].priority) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++; k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++; k++;
    }

    free(L);
    free(R);
}

void mergeSort(Chapter arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    int n;

    printf("=====================================\n");
    printf("    시험 공부 순서 계획 프로그램\n");
    printf("=====================================\n");

    printf("계획할 총 챕터의 개수를 입력하세요: ");
    scanf("%d", &n);
    clearInputBuffer();

    Chapter* chapters = (Chapter*)malloc(n * sizeof(Chapter));
    for (int i = 0; i < n; i++) {
        printf("\n--- %d번째 챕터 정보 입력 ---\n", i + 1);

        printf("과목명: ");
        scanf(" %s", chapters[i].subjectName);

        printf("챕터명: ");
        scanf(" %s", chapters[i].chapterName);

        printf("시험까지 남은 일수: ");
        scanf("%d", &chapters[i].daysRemaining);

        printf("과목 중요도 (1~10): ");
        scanf("%d", &chapters[i].subjectImportance);

        printf("현재 공부한 정도 (1~10, 숫자가 낮을수록 공부 안 함): ");
        scanf("%d", &chapters[i].studyProgress);

        clearInputBuffer();
        
        chapters[i].priority = (1.0 / chapters[i].daysRemaining) * (1.0 / chapters[i].studyProgress) * chapters[i].subjectImportance;
    }

    mergeSort(chapters, 0, n - 1);

    printf("\n");
    printf("=====================================\n");
    printf("           추천 공부 순서\n");
    printf("=====================================\n");

    for (int i = 0; i < n; i++) {
        printf("%d. 과목: %s - 챕터: %s (우선도: %f)\n", i + 1, chapters[i].subjectName, chapters[i].chapterName, chapters[i].priority);
    }

    printf("=====================================\n");

    free(chapters);
    return 0;
}