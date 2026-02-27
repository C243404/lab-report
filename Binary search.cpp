#include <iostream>
using namespace std;

int main() {
    int n, key;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter elements in ascending order:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter number to search: ";
    cin >> key;

    int low = 0, high = n - 1, mid;
    bool found = false;

    while(low <= high) {
        mid = (low + high) / 2;

        if(arr[mid] == key) {
            cout << "Element found at position " << mid + 1;
            found = true;
            break;
        } else if(arr[mid] < key) {
            low = mid + 1; // search in the right half
        } else {
            high = mid - 1; // search in the left half
        }
    }

    if(!found) {
        cout << "Element not found";
    }

    return 0;
}
