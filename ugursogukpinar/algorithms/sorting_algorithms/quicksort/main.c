#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "quicksort.h"
#include "main.h"



int main(){
    srand(time(NULL));
    char selection;
    int n, tmp_int;
    int (*fp)(int *, int, int);
    int *list;
    int random;
    clock_t begin, end;
    double time_spent;

    do
    {
        printf("\n-----------------------------\n");
        printf("0- Çıkış\n");
        printf("1- Pivot baştaki eleman olsun\n");
        printf("2- Pivot rastgele seçilsin\n");
        printf("3- Pivot ortanca eleman olsun\n");
        printf("\n-----------------------------\n");

        scanf("%c", &selection);
    } while(selection < '0' || selection > '3');

    switch (selection) {
        case '0':
            exit(0);
            break;
        case '1':
            fp = &pivot_first_element;
            break;
        case '2':
            fp = &pivot_random;
            break;
        case '3':
            fp = &pivot_second_big;
            break;
        default:
            fp = &pivot_first_element;
            break;
    }
    fseek(stdin,0,SEEK_SET);
    do
    {
        printf("\n-----------------------------\n");
        printf("1- Elemanlar sıralı olsun\n");
        printf("2- Elemanlar sırasız olsun\n");
        printf("3- Elemanları kendim girecegim\n");
        printf("\n-----------------------------\n");

        scanf("%c", &selection);

    } while(selection < '0' || selection > '3');

    printf("Lütfen eleman sayısını giriniz: ");
    scanf("%d", &n);

    list = (int *) malloc(sizeof(int) * n);
    //printf("Liste olusturuldu\n");
    switch (selection) {
        case '1':
            for (int i=0; i < n; i++) {
                list[i] = i;
            }
            break;
        case '2':
            for (int i=0; i < n; i++) {
                random = (rand() % (MAX_RAND - MIN_RAND + 1))  + MIN_RAND;
                list[i] = random;
            }
            break;
        case '3':
            for (int i=0; i < n; i++) {
                printf("%d. elemanı giriniz: ", i+1);
                scanf("%d", &list[i]);
            }
    }


    printf("\n------------------------------------------------\n");
    for (int i=0; i<n; i++) {
        printf("%d\n", list[i]);
    }
    printf("\n------------------------------------------------\n");


    begin = clock();
    quicksort(list, 0, n-1, fp);
    end = clock();

    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("\n------------------------------------------------\n");
    for (int i=20; i<30; i++) {
        printf("%d\n", list[i]);
    }
    printf("\n------------------------------------------------\n");

    printf("\n---------------- SONUCLAR --------------------\n");
    printf("--- Eleman sayısı: %d\n", n);
    switch (selection) {
        case '1':
            printf("--- Eleman sıra durumu: Sıralı\n");
            break;
        case '2':
            printf("--- Eleman sıra durumu: Sırasız\n");
            break;
    }

    printf("--- İşlem süresi : %lf\n", time_spent);
    printf("\n----------------------------------------------\n");

    return 0;

}

int pivot_first_element(int *list, int left, int right) {
    return list[left];
}

int pivot_random(int *list, int left, int right) {
    int random;
    // Find random number between left and right
    random = (rand() % (right - left + 1)) + left;

    printf("\n-------PIVOT SECIMI------\n");
    printf("Pivot Index: %d, Pivot: %d",random, list[random] );
    printf("\n-------PIVOT SECIMI------\n");

    swap(list, left, random);
    return list[left];
}

int pivot_second_big(int *list, int left, int right) {
    int mid_index = (left + right) / 2;
    float mid_point = (list[mid_index] + list[left] + list[right]) / 3.0;

    int less_diff_index;
    float less_diff;

    less_diff_index = left;
    less_diff = fabs(list[left] - mid_point);

    if (less_diff > fabs(list[mid_index] - mid_point)) {
        less_diff_index = mid_index;
        less_diff = fabs(list[mid_index] - mid_point);
    }

    if (less_diff > fabs(list[right] - mid_point)) {
        less_diff_index = right;
    }

    #if DEBUG
        printf("\n-------PIVOT SECIMI------\n");
        printf("Left: %d, Right: %d, Mid: %d, Pivot: %d",list[left], list[right], list[mid_index], list[less_diff_index] );
        printf("\n-------PIVOT SECIMI------\n");
    #endif

    swap(list, less_diff_index, left);

    return list[left];
}
