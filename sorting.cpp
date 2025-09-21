#include "sorting.h"

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
void quickSort(){}
void heapSort(){}