#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter rod length: ";
    cin >> n;

    int price[n + 1];

    cout << "Enter prices: ";
    for(int i = 1; i <= n; i++) {
        cin >> price[i];
    }

    int dp[n + 1];

    dp[0] = 0;

    for(int i = 1; i <= n; i++) {
        int maxVal = -1;

        for(int j = 1; j <= i; j++) {
            if(price[j] + dp[i - j] > maxVal)
                maxVal = price[j] + dp[i - j];
        }

        dp[i] = maxVal;
    }

    cout << "Maximum profit: " << dp[n];

    return 0;
}
