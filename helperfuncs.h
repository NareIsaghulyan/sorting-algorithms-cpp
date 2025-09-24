#include <string>
#pragma once

void swap(int &, int &); 
void benchmark(void (*sortingFunc)(int*, int, long long &), int*, int, long long &, const std::string &); 
void generateArray(int*, int, int); 
void printArray(int*, int); 