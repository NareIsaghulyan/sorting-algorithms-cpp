#include <iostream>
#include <chrono>
#include <string>
#include "sorting.h"
#include "helperfuncs.h"

void swap(int &num1, int &num2){
    int temp = num1; 
    num1 = num2; 
    num2 = temp; 
}

void generateArray(int *arr, int size, int type){
    long long swapCount = 0; 
    for(int i = 0; i < size; ++i)
        arr[i] = rand() % 100 + 1; 

    if(type == 2)
        quickSort(arr, size, swapCount);

    if(type == 3){
        quickSort(arr, size, swapCount); 
        for(int i = 0; i < size; ++i)
            swap(arr[i], arr[size - 1 - i]); 
    }
}

void printArray(int *arr, int size){
    if(size <= 1000)
        for(int i = 0; i < size; ++i)
            std::cout << arr[i] << ' '; 
    else{
        for(int i = 0; i < 10; ++i) 
            std::cout << arr[i] << ' ';

        std::cout << "... ";

        for(int i = size - 10; i < size; ++i) 
            std::cout << arr[i] << ' ';
    }

    std::cout << std::endl; 
}

void benchmark(void (*sortingFunc)(int* arr, int size, long long &swapCount), int *arr, int size, long long &swapCount, const std :: string &name){
    int *arrCopy = new int[size]; 

    for(int i = 0; i < size; ++i)
        arrCopy[i] = arr[i]; 

    swapCount = 0; 

    auto start = std::chrono::steady_clock::now(); 
    sortingFunc(arrCopy, size, swapCount); 
    auto end = std::chrono::steady_clock::now(); 

    double sec = std::chrono::duration<double>(end - start).count(); 

    std::cout << std::endl << "-------------------------------" << std::endl;
    std::cout << name << std::endl << std::endl; 

    std::cout << "The original array:" << std::endl; 
    printArray(arr, size); 

    std::cout << std::endl << std::endl << "The sorted array:" << std::endl; 
    printArray(arrCopy, size);  

    std::cout << std::endl << std::endl << "Array size: " << size << std::endl;
    std::cout << std::endl << "Moves taken: " << swapCount << " swaps" << std::endl; 
    std::cout << std::endl << "Time taken: " << sec << " seconds" <<std::endl; 
    

    std::cout << "-------------------------------" << std::endl;  

    
    delete [] arrCopy; 
}
