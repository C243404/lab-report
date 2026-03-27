#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of items: ";
    cin >> n;

    float weight[n], value[n], ratio[n];

    cout << "Enter weights: ";
    for(int i = 0; i < n; i++) {
        cin >> weight[i];
    }

    cout << "Enter values: ";
    for(int i = 0; i < n; i++) {
        cin >> value[i];
        ratio[i] = value[i] / weight[i];
    }

    float capacity;
    cout << "Enter capacity of knapsack: ";
    cin >> capacity;

    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(ratio[i] < ratio[j]) {

                float temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;

                temp = weight[i];
                weight[i] = weight[j];
                weight[j] = temp;

                temp = value[i];
                value[i] = value[j];
                value[j] = temp;
            }
        }
    }

    float totalValue = 0;

    for(int i = 0; i < n; i++) {
        if(capacity >= weight[i]) {
            totalValue += value[i];
            capacity -= weight[i];
        } else {
            totalValue += ratio[i] * capacity;
            break;
        }
    }

    cout << "Maximum value: " << totalValue;

    return 0;
}
