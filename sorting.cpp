#include "sorting.h"
#include "helperfuncs.h"

void bubbleSort(int* arr, int size, long long &swapCount){
    swapCount = 0; 
    int temp, pass, i; 

    for(pass = 0; pass < size - 1; ++pass){
        bool swapped = false; 

        for(i = 0; i < size - 1 - pass; ++i)
            if(arr[i] > arr[i + 1]){
                swap(arr[i], arr[i + 1]); 
                swapped = true; 
                swapCount++; 
            }
        
        if(!swapped) break; 
    }
}

void insertionSort(int* arr, int size, long long &swapCount){
    swapCount = 0; 
    int temp, i, j; 

    for(i = 1; i < size; ++i){
        temp = arr[i]; 
        j = i - 1; 

        while(j >= 0 && arr[j] > temp){
            arr[j + 1] = arr[j]; 
            --j; 
        }

        arr[j + 1] = temp; 
        swapCount++; 
    }
        
} 

void selectionSort(int* arr, int size, long long &swapCount){
    swapCount = 0; 
    int min_index, curr, temp, i, j;  
    for(i = 0; i < size; ++i){
        curr = arr[i]; 
        min_index = i; 
        for(j = i + 1; j < size; ++j)
            if(arr[j] < arr[min_index]) min_index = j; 

        if(min_index != i){
            swap(arr[min_index], arr[i]); 
            swapCount++; 
        }
        
    }
}

void merge(int* arr, int* leftArr, int* rightArr, int leftSize, int rightSize, long long &swapCount){
    int i = 0, j = 0, k = 0; 

    while(i < leftSize && j < rightSize){
        if(leftArr[i] < rightArr[j]) arr[k++] = leftArr[i++]; 
        else arr[k++] = rightArr[j++]; 
        swapCount++; 
    }

    while(i < leftSize)
        arr[k++] = leftArr[i++], swapCount++; 
        

    while(j < rightSize)
        arr[k++] = rightArr[j++], swapCount++; 
}

void mergeSort(int* arr, int size, long long &swapCount){
    if(size <= 1) return; 

    int leftSize = size / 2; 
    int rightSize = size - size / 2; 
    int *leftArr = new int[leftSize], *rightArr = new int[rightSize]; 
    for(int i = 0; i < leftSize; ++i)
        leftArr[i] = arr[i]; 

    for(int i = 0; i < rightSize; ++i)
        rightArr[i] = arr[leftSize + i]; 

    mergeSort(leftArr, leftSize, swapCount); 
    mergeSort(rightArr, rightSize, swapCount); 

    merge(arr,leftArr, rightArr, leftSize, rightSize, swapCount); 

    delete [] leftArr; 
    delete [] rightArr; 
}

int partition(int* arr, int size, long long &swapCount){
    int temp, pivot, i = 0, j = size - 2; 

    if(arr[0] < arr[size/2])
        swap(arr[0], arr[size/2]), swapCount++;  

    if(arr[0] < arr[size - 1])
        swap(arr[0], arr[size - 1]), swapCount++;  

    if(arr[size/2] < arr[size - 1])
        swap(arr[size/2], arr[size - 1]), swapCount++;  

    pivot = arr[size/2]; 

    swap(arr[size/2], arr[size - 1]), swapCount++; 

    while(i < j){
        while(arr[i] < pivot)
            ++i; 

        while(arr[j] > pivot)
            --j;

        if(i < j)
            swap(arr[i], arr[j]), swapCount++; 
    }

    swap(arr[i], arr[size - 1]), swapCount++; 

    return i; 
}

void quickSort(int* arr, int size, long long &swapCount){
    if(size <= 1) return; 

    int pivotIndex = partition(arr, size, swapCount); 

    quickSort(arr, pivotIndex, swapCount); 
    quickSort(arr + pivotIndex + 1, size - pivotIndex - 1, swapCount); 

}

void percolateDown(int* arr, int curr, int size, long long &swapCount){
    while(true){
        int maxIndex = curr;
        int left = 2 * curr + 1;
        int right = 2 * curr + 2;

        if(left < size && arr[left] > arr[maxIndex]) maxIndex = left;
        if(right < size && arr[right] > arr[maxIndex]) maxIndex = right;

        if(maxIndex == curr) break;

        swap(arr[curr], arr[maxIndex]), swapCount++; 

        curr = maxIndex;
    }
}

void heapify(int* arr, int size, long long &swapCount){
    for(int k = size / 2 - 1; k >= 0; --k) 
        percolateDown(arr, k, size, swapCount);
}

void heapSort(int* arr, int size, long long &swapCount){
    if(size <= 1) return;
    swapCount = 0; 

    heapify(arr, size, swapCount);

    for(int i = size - 1; i > 0; --i){
        swap(arr[0], arr[i]); 
        swapCount++;
        percolateDown(arr, 0, i, swapCount);
    }
}
