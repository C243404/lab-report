#include <iostream>
using namespace std;

int main() {
    int n, c;

    cout << "Enter number of items: ";
    cin >> n;

    int w[n], v[n];

    cout << "Enter weights: ";
    for(int i = 0; i < n; i++)
        cin >> w[i];

    cout << "Enter values: ";
    for(int i = 0; i < n; i++)
        cin >> v[i];

    cout << "Enter capacity: ";
    cin >> c;

    int dp[50][50];

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= c; j++) {

            if(i == 0 || j == 0)
                dp[i][j] = 0;

            else if(w[i-1] <= j) {
                int a = v[i-1] + dp[i-1][j-w[i-1]];
                int b = dp[i-1][j];

                if(a > b)
                    dp[i][j] = a;
                else
                    dp[i][j] = b;
            }

            else
                dp[i][j] = dp[i-1][j];
        }
    }

    cout << "Maximum value: " << dp[n][c];

    return 0;
}
