#include <iostream>
#include <string>
using namespace std;

template<typename T>
int linearSearch(T arr[], int size, T key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int main() {
    // Integer array
    int arr[] = { 10, 25, 30, 45, 50 };
    int size = sizeof(arr) / sizeof(arr[0]);
    int find;

    cout << "Enter number to search: ";
    cin >> find;

    int result = linearSearch(arr, size, find);

    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found" << endl;

    // Float array
    float floatArray[4] = { 3.14, 2.71, 1.62, 0.57 };
    float floatKey = 1.62;
    int floatIndex = linearSearch(floatArray, 4, floatKey);
    cout << "Float element " << floatKey;
    if (floatIndex != -1)
        cout << " found at index: " << floatIndex << endl;
    else
        cout << " not found" << endl;

    // String array
    string stringArray[4] = { "apple", "orange", "banana", "grape" };
    string stringKey = "banana";
    int stringIndex = linearSearch(stringArray, 4, stringKey);
    cout << "String element \"" << stringKey << "\"";
    if (stringIndex != -1)
        cout << " found at index: " << stringIndex << endl;
    else
        cout << " not found" << endl;

    return 0;
}