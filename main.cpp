#include <iostream>
#include "sorting.h"
#include "helperfuncs.h"

int main(){
    std::cout << "-------------------------------" << std::endl; 
    std::cout << "   Sorting Algorithms Tester   " << std::endl; 
    std::cout << "-------------------------------" << std::endl << std::endl; 

    std::cout << "This program lets you: "<< std::endl 
                                           << "- Choose a Sorting Algorithm. " << std::endl
                                           << "- Choose the size of the array. " << std::endl
                                           << "- Choose the type of an array. " << std::endl << std::endl; 

    std::cout << "It will then: " << std::endl
              << "- Run the algorithm." << std::endl
              << "- Show how long it took." << std::endl << std::endl; 

    std::cout << "Let's start!" << std::endl << std::endl; 

    int algorithmType, size, type; 

    std::cout << std::endl << "Enter the number of your preferred sorting algorithm: " << std::endl; 
    std::cout << "1. Bubble Sort" << std::endl
              << "2. Insertion Sort" << std::endl
              << "3. Selection Sort" << std::endl
              << "4. Merge Sort" << std::endl
              << "5. Quick Sort" << std::endl
              << "6. Heap Sort" << std::endl
              << std::endl << std::endl;

    std::cout << "Waiting for your choice: "; 
    std::cin >> algorithmType; 

    std::cout << std::endl << "Enter the array size: "; 
    std::cin >> size; 

    std::cout << std::endl << "Enter the number of your preferred array type: " << std::endl; 
    std::cout << "1. Sorted" << std::endl
              << "2. Random" << std::endl
              << "3. Reversed" << std::endl
              << std::endl << std::endl; 

    std::cout << "Waiting for your choice: "; 
    std::cin >> type; 

    int *arr = new int[size]; 
    generateArray(arr, size, type); 
    long long swapCount = 0; 
    switch(algorithmType){
        case 1: benchmark(bubbleSort, arr, size, swapCount,"Bubble Sort"); break; 
        case 2: benchmark(insertionSort, arr, size, swapCount, "Insertion Sort"); break; 
        case 3: benchmark(selectionSort, arr, size, swapCount, "Selection Sort"); break; 
        case 4: benchmark(mergeSort, arr, size, swapCount, "Merge Sort"); break; 
        case 5: benchmark(quickSort, arr, size, swapCount, "Quick Sort"); break; 
        case 6: benchmark(heapSort, arr, size, swapCount, "Quick Sort"); break; 
        default: std::cout << "Invalid choice! "; 
    }

    delete [] arr; 
    
    return 0; 
}

