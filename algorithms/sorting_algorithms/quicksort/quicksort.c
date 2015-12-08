#include <stdio.h>
#include <stdlib.h>
#include "quicksort.h"


/*
* Implements quick sort algorithm between two index given array.
*
* @param int *list, represents array to sort
* @param int left, small index of array
* @param int right, big index of array
* @param int (*find_pivot)(int *, int, int) determines which element will be pivot.
*/
void quicksort(int *list, int left, int right, int (*find_pivot)(int *, int, int)) {

    int s;

    if (left < right) {
        s = partition(list, left ,right, find_pivot);
        /*printf("---------\n");
        printf("Pivot: %d\n", list[s]);

        for (int i=left; i<=right; i++) {
            printf(" %d ", list[i]);
        }
        printf("\n---------\n");
        */

        quicksort(list, left, s-1, find_pivot);
        quicksort(list, s+1, right, find_pivot);
    }
}


/*
* Splits the array logically around the pivot between two index
* @param int *list, represents array to split
* @param int left, small index of array
* @param int right, big index of array
* @param int (*find_pivot)(int *, int, int) determines which element will be pivot.
*/
int partition (int *list, int left, int right, int (*find_pivot)(int *, int, int)) {

    int pivot, i, j;

    pivot = (*find_pivot)(list, left, right);

    i = left;
    j = right + 1;

    do {
        do {
            i++;
        } while ( (i < j) && (list[i] <= pivot));

        do {
            j--;
        } while (list[j] > pivot);

        #if DEBUG
        printf("\n----------Swap Öncesi\n");
        printf("Pivot: %d\n", pivot);

        for (int k=left; k<=right; k++) {
            printf(" %d ", list[k]);
        }
        printf("\n---------\n");
        #endif

        swap(list, i, j);

        #if DEBUG
        printf("\n---------Swap sonrası\n");
        printf("Pivot: %d\n", pivot);

        for (int k=left; k<=right; k++) {
            printf(" %d ", list[k]);
        }
        printf("\n---------\n");
        #endif

    }while (i < j);

    swap(list, i, j);
    swap(list, j, left);

    return j;
}


/*
* Swaps two element of array
* @param int *list
* @param int first_elm
* @param int second_elm
*/
void swap(int *list, int first_elm, int second_elm) {
    int tmp;

    tmp = list[first_elm];
    list[first_elm] = list[second_elm];
    list[second_elm] = tmp;
}
