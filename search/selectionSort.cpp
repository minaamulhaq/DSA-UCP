#include <iostream>
#include <string>
using namespace std;

template<typename T>
void printArray(T arr[], int size) {
    cout << "Array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

template<typename T>
void selectionSort(T A[], int N) {
    for (int i = 0; i < N - 1; i++) {
        int SmallSub = i;

        for (int j = i + 1; j < N; j++) {
            if (A[j] < A[SmallSub]) {
                SmallSub = j;
            }
        }

        T temp = A[i];   // FIXED
        A[i] = A[SmallSub];
        A[SmallSub] = temp;
    }
}

int main() {

    int arr[] = { 21, 25, 30, 45, 50 };
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original int array: ";
    printArray(arr, size);

    selectionSort(arr, size);

    cout << "Sorted int array: ";
    printArray(arr, size);

    string stringArray[4] = { "apple", "orange", "banana", "grape" };

    cout << "\nOriginal string array: ";
    printArray(stringArray, 4);  

    selectionSort(stringArray, 4);

    cout << "Sorted string array: ";
    printArray(stringArray, 4);  

    return 0;
}