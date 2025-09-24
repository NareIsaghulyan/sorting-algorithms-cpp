#include <iostream>
#include <chrono>
#include <string>
#include "sorting.h"

void benchmark(void (*sortingFunc)(int* arr, int size), int *arr, int size, const std :: string &name){
    int *arrCopy = new int[size]; 

    for(int i = 0; i < size; ++i)
        arrCopy[i] = arr[i]; 

    auto start = std::chrono::steady_clock::now(); 
    sortingFunc(arrCopy, size); 
    auto end = std::chrono::steady_clock::now(); 

    double sec = std::chrono::duration<double>(end - start).count(); 

    std::cout << "-------------------------------" << std::endl;
    std::cout << std::endl << name << std::endl << std::endl; 
    std::cout << "The original array:" << std::endl; 
    printArray(arr, size); 
    std::cout << std::endl << std::endl << "The sorted array:" << std::endl; 
    printArray(arrCopy, size);  
    std::cout << std::endl << std::endl << "Array size: " << size << std::endl;
    std::cout << std::endl << std::endl << "Time taken: " << sec << " seconds" <<std::endl; 
    std::cout << "-------------------------------" << std::endl;  

    
    delete [] arrCopy; 
}

void generateArray(int *arr, int size, int type){
    for(int i = 0; i < size; ++i)
        arr[i] = rand(); 
    if(type == 2)
        quickSort(arr, size); 
    if(type == 3){
        quickSort(arr, size); 
        for(int i = 0; i < size; ++i){
            int temp = arr[i]; 
            arr[i] = arr[size - 1 - i]; 
            arr[size - 1 - i] = temp; 
        }
    }
}

void printArray(int *arr, int size){
    for(int i = 0; i < size; ++i)
        std::cout << arr[i] << ' '; 
    std::cout << std::endl;
}