#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

void createArray(int array[], int size, int type) {
    switch (type) {
        case 1:
        for (int i = 0; i < size; i++) {
            array[i] = i;
        }
        break;

        case 2:
        for (int i = 0; i < size; i++) {
            array[i] = size - 1 - i;
        }
        break;

        case 3:
        srand(time(NULL));
        for (int i = 0; i < size; i++) {
            array[i] = rand () % size;
        }
        break;
    }
}

void selectionSort(int array[], int size) {

    int swap;
    int indexMin;
    
    for (int i = 0; i < size - 1; i++) {
        indexMin = i;
        for (int j = i + 1; j < size; j++) {
            if (array[indexMin] > array[j]) {
                indexMin = j;
            }
        }
        swap = array[indexMin];
        array[indexMin] = array[i];
        array[i] = swap;  
    }
}

void insertionSort(int array[], int size) {

    int temp;
    int i, j;

    for (i = 1; i < size; i++) {
        temp = array[i];
        for (j = i; j >= 1 && temp < array[j-1]; j--) {
            array[j] = array[j-1];
        }
        array[j] = temp;
    }
}

void bubbleSort(int array[], int size) {

    typedef enum {false, true} bool;
    int temp;
    
    for (int i = size - 1; i > 0; i--) {
        bool flag = false;
        for (int j = 0; j < i; j++) {
            if (array[j] > array[j+1]) {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
                flag = true;
            }
        }
        if (flag == false) {break;}
    }
}

int main(void) {

    int array[5000];

    createArray(array, 5000, 2);

    bubbleSort(array, 5000);

    for(int i = 0; i < 5000; i++) {
        printf("%d ", array[i]);
    }

    getch();
    return 0;
}