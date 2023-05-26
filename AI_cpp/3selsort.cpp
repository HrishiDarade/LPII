#include <iostream>
#include <vector>

using namespace std;

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr;
    cout << "Enter the values:\n";
    for (int i = 0; i < n; i++) {
        int x;
        cout << "Element " << i + 1 << ": ";
        cin >> x;
        arr.push_back(x);
    }

    cout << "\nThe array you entered is: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << "\n\nPerforming Selection Sort on the given array...\n";
    selectionSort(arr);

    cout << "\nThe sorted array is: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
