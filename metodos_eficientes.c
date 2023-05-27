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
            array[i] = size - i - 1;
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

//Usar como "end" no quicksort o tamanho do vetor, e nao a indice de sua posicao final.

// void quickSort(int array[], int start, int end) {

//     int i, j, pivot, aux;
// 	i = start;
// 	j = end-1;
// 	pivot = array[(start + end) / 2];

// 	while (i <= j) {
    
// 		while (array[i] < pivot && i < end) {
// 			i++;
// 		}

// 		while (array[j] > pivot && j > start) {
// 			j--;
// 		}

// 		if (i <= j) {
// 			aux = array[i];
// 			array[i] = array[j];
// 			array[j] = aux;
// 			i++;
// 			j--;
// 		}
// 	}

// 	if (j > start) {
// 		quickSort(array, start, j+1);
//     }

// 	if (i < end) {
// 		quickSort(array, i, end);
//     }
// }


int partition(int array[], int start, int end) {
    int posPivot = end;
    int k = start;
    int swap;
    for(int i = start; i <= end; i++) {
        if(array[i] <= array[posPivot]) {
            swap = array[i];
            array[i] = array[k];
            array[k] = swap;
            k++;
        }
    }
    return k - 1;
}

void quickSort(int array[], int start, int end) {
    if(start < end) {
        int posPivot = partition(array, start, end);
        quickSort(array, start, posPivot - 1);
        quickSort(array, posPivot + 1, end);
    }
}


void merge(int array[], int start, int middle, int end) {

    int auxArray[end - start + 1];
    int i = start;
    int j = middle + 1;
    int k = 0;

    while (i <= middle && j <= end) {
        if (array[i] <= array[j]) {
            auxArray[k] = array[i];
            i++;
        } else {
            auxArray[k] = array[j];
            j++;
        }
        k++;
    }

    while (i <= middle) {
        auxArray[k] = array[i];
        k++;
        i++;
    }

    while (j <= end) {
        auxArray[k] = array[j];
        k++;
        j++;
    }

    for (k = start; k <= end; k++) {
        array[k] = auxArray[k - start];
    }

    free(auxArray);

}

void mergeSort(int array[], int start, int end) {

    if (start < end) {
        int middle = (start + end) / 2;
        mergeSort(array, start, middle);
        mergeSort(array, middle + 1, end);
        merge(array, start, middle, end);
    }

}


void createHeap(int array[], int i, int size) {

    int max = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && array[left] > array[i]) {
        max = left;
    }
    if (right < size && array[right] > array[max]) {
        max = right;
    }

    if (max != i) {
        int aux = array[i];
        array[i] = array[max];
        array[max] = aux;
        createHeap(array, max, size);
    }
}


void heapSort(int array[], int size) {

    for (int k = size/2-1; k >= 0; k--) {
        createHeap(array, k, size);
    }

    for (int k = size-1; k > 0; k--) {
        int aux = array[0];
        array[0] = array[k];
        array[k] = aux;
        createHeap(array, 0, k);
    }
}


int main(void) {

    int array[1000];

    createArray(array, 1000, 3);

    quickSort(array, 0, 1000);

    for(int z = 0; z < 1000; z++) {
        printf("%d ", array[z]);
    }

    return 0;
}