#include <iostream>
using namespace std;

int main() {
    int n, key, i;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter elements:\n";
    for(i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter number to search: ";
    cin >> key;

    for(i = 0; i < n; i++) {
        if(arr[i] == key) {
            cout << "Element found at position " << i + 1;
            return 0;
        }
    }

    cout << "Element not found";

    return 0;
}
