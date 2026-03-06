#include <iostream>
using namespace std;

template<typename T>
int binarySearch(T arr[], int size, T target) {
    int mid = 0;
    int low = 0;
    int high = size - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        else if (arr[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }

    }
    return -1;
}
int main() {
    int arr[] = { 10, 25, 30, 45, 50 };
    int size = sizeof(arr) / sizeof(arr[0]);
    int find;

    cout << "Enter number to search: ";
    cin >> find;

    int binaryResult = binarySearch(arr, size, find);
    cout << endl;
    if (binaryResult != -1)
        cout << "Element found at index: " << binaryResult;
    else
        cout << "Element not found";

    float floatArray[4] = { 0.57, 1.62, 2.71, 3.14 };
    float floatKey = 2.71;
    int floatIndex = binarySearch(floatArray, 4, floatKey);

    // Test with a string array (sorted) of size 4
    string stringArray[4] = { "apple", "banana", "grape", "orange" };
    string stringKey = "grape";
    int stringIndex = binarySearch(stringArray, 4, stringKey);
    
    cout <<endl;
    return 0;
};
