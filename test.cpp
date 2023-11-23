#include <iostream>
#include <cstdlib>
using namespace std;

// Function to partition the array with the search key as the pivot and return its final position
int partition(int arr[], int low, int high, int searchKey) {
    // Find the index of the search key
    int pivotIndex;
    for (pivotIndex = low; pivotIndex <= high; pivotIndex++) {
        if (arr[pivotIndex] == searchKey) {
            break;
        }
    }

    // Move the search key to the end of the array
    swap(arr[pivotIndex], arr[high]);

    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Function to perform QuickSort and return the index of the search key
int findIndex(int arr[], int size, int searchKey) {
    int index = partition(arr, 0, size - 1, searchKey);

    if (arr[index] == searchKey) {
        return index;
    } else {
        return -1; // Search key not found
    }
}

int main() {
    int arr[] = {12, 3, 11, 6, 7, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    int searchKey = 11;

    int result = findIndex(arr, size, searchKey);

    if (result != -1)
        std::cout << "The index of the search key " << searchKey << " is: " << result << std::endl;
    else
        std::cout << "Search key not found." << std::endl;

    return 0;
}

