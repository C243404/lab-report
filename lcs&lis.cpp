#include <iostream>
#include <string>
using namespace std;

// Function for LCS
void LCS(string s1, string s2) {
    int m = s1.length();
    int n = s2.length();

    int dp[100][100];
    for(int i = 0; i <= m; i++) {
        for(int j = 0; j <= n; j++) {

            if(i == 0 || j == 0)
                dp[i][j] = 0;

            else if(s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;

            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    cout << "Length of LCS: " << dp[m][n] << endl;
}

// Function for LIS
void LIS(int arr[], int n) {

    int lis[100];

    for(int i = 0; i < n; i++)
        lis[i] = 1;

    for(int i = 1; i < n; i++) {

        for(int j = 0; j < i; j++) {

            if(arr[i] > arr[j] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
            }
        }
    }

    int maximum = 0;

    for(int i = 0; i < n; i++) {

        if(lis[i] > maximum)
            maximum = lis[i];
    }

    cout << "Length of LIS: " << maximum << endl;
}

int main() {

    string s1, s2;

    cout << "Enter first string: ";
    cin >> s1;

    cout << "Enter second string: ";
    cin >> s2;

    LCS(s1, s2);

    int n;

    cout << "\nEnter number of elements: ";
    cin >> n;

    int arr[100];

    cout << "Enter array elements: ";

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    LIS(arr, n);

    return 0;
}
