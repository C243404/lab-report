#include <iostream>
using namespace std;

int divide(int arr[], int start, int end) {
    int last = arr[end];
    int i = start - 1;

    for(int j = start; j < end; j++) {
        if(arr[j] < last) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[end];
    arr[end] = temp;

    return i + 1;
}

void quickSort(int arr[], int start, int end) {
    if(start < end) {
        int position = divide(arr, start, end);

        quickSort(arr, start, position - 1);
        quickSort(arr, position + 1, end);
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
