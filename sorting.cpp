#include "sorting.h"
// implement swap function because it is used a lot; 
void bubbleSort(int* arr, int size){
    int temp, pass, i; 
    for(pass = 0; pass < size - 1; ++pass){
        bool swapped = false; 
        for(i = 0; i < size - 1 - pass; ++i)
            if(arr[i] > arr[i + 1]){
                temp = arr[i]; 
                arr[i] = arr[i + 1]; 
                arr[i + 1] = temp; 

                swapped = true; 
            }
        
        if(!swapped) break; 
    }
}


void insertionSort(int* arr, int size){
    int temp, i, j; 
    for(i = 1; i < size; ++i){
        temp = arr[i]; 
        j = i - 1; 

        while(j >= 0 && arr[j] > temp){
            arr[j + 1] = arr[j]; 
            --j; 
        }

        arr[j + 1] = temp; 
    }
        
} 


void selectionSort(int* arr, int size){
    int min_index, curr, temp, i, j;  
    for(i = 0; i < size; ++i){
        curr = arr[i]; 
        min_index = i; 
        for(j = i + 1; j < size; ++j)
            if(arr[j] < arr[min_index]) min_index = j; 

        temp = arr[min_index]; 
        arr[min_index] = arr[i]; 
        arr[i] = temp; 
    }
}

void merge(int* arr, int* leftArr, int* rightArr, int leftSize, int rightSize){
    int i = 0, j = 0, k = 0; 

    while(i < leftSize && j < rightSize){
        if(leftArr[i] < rightArr[j]) arr[k++] = leftArr[i++]; 
        else arr[k++] = rightArr[j++]; 
    }

    while(i < leftSize)
        arr[k++] = leftArr[i++]; 

    while(j < rightSize)
        arr[k++] = rightArr[j++]; 
}

void mergeSort(int* arr, int size){
    if(size <= 1) return; 

    int leftSize = size / 2; 
    int rightSize = size - size / 2; 
    int *leftArr = new int[leftSize], *rightArr = new int[rightSize]; 
    for(int i = 0; i < leftSize; ++i)
        leftArr[i] = arr[i]; 

    for(int i = 0; i < rightSize; ++i)
        rightArr[i] = arr[leftSize + i]; 

    mergeSort(leftArr, leftSize); 
    mergeSort(rightArr, rightSize); 

    merge(arr,leftArr, rightArr, leftSize, rightSize); 

    delete [] leftArr; 
    delete [] rightArr; 
}

int partition(int* arr, int size){
    int temp, pivot, i = 0, j = size - 2; 

    if(arr[0] < arr[size/2]){
        temp = arr[0]; 
        arr[0] = arr[size/2]; 
        arr[size/2] = temp; 
    }

    if(arr[0] < arr[size - 1]){
        temp = arr[0]; 
        arr[0] = arr[size - 1]; 
        arr[size - 1] = temp; 
    }

    if(arr[size/2] < arr[size - 1]){
        temp = arr[size/2]; 
        arr[size/2] = arr[size - 1]; 
        arr[size - 1] = temp; 
    }

    pivot = arr[size/2]; 

    temp = arr[size/2]; 
    arr[size/2] = arr[size - 1]; 
    arr[size - 1] = temp; 

    while(i < j){
        while(arr[i] < pivot){
            ++i; 
        }

        while(arr[j] > pivot){
            --j;
        }

        if(i < j){
            temp = arr[i]; 
            arr[i] = arr[j]; 
            arr[j] = temp; 
        }
    }

    temp = arr[i]; 
    arr[i] = arr[size - 1]; 
    arr[size - 1] = temp; 

    return i; 
}
void quickSort(int* arr, int size){
    if(size <= 1) return; 

    int pivotIndex = partition(arr, size); 

    quickSort(arr, pivotIndex); 
    quickSort(arr + pivotIndex + 1, size - pivotIndex - 1); 

}

void percolateDown(int* arr, int curr, int size){
    while(true){
        int maxIndex = curr;
        int left = 2 * curr + 1;
        int right = 2 * curr + 2;

        if(left < size && arr[left] > arr[maxIndex]) maxIndex = left;
        if(right < size && arr[right] > arr[maxIndex]) maxIndex = right;

        if(maxIndex == curr) break;

        int temp = arr[curr];
        arr[curr] = arr[maxIndex];
        arr[maxIndex] = temp;

        curr = maxIndex;
    }
}

void heapify(int* arr, int size){
    for(int k = size / 2 - 1; k >= 0; --k) 
        percolateDown(arr, k, size);
}


void heapSort(int* arr, int size){
    if(size <= 1) return;

    heapify(arr, size);

    for(int i = size - 1; i > 0; --i){
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        percolateDown(arr, 0, i);
    }
}
