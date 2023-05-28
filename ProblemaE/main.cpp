#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> t;
vector<vector<bool>> dp;

int pizza(int n, int s){

    for (int i = 0; i < n; i++) {
        dp[i][0] = true;
    }
    for (int j = 1; j <= s; j++) {
        dp[0][j] = false;
    }
    for (int i = 1; i < n; i++){
        for (int j = 1; j <= s; j++){
            if (t[i] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - t[i]];
        }
    }
    for (int i = s; i >= 0; i--) {
        if (dp[n-1][i]) {
            return i;
        }
    }

    return 0;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while(cin >> n){
        n = n + 1;
        t = vector<int>(n + 1);
        int count = 0;
        for (int i = 1; i < n; i++){
            cin >> t[i];
            count += t[i];
        }
        int s = floor(count/2);
        dp = vector<vector<bool>>(n, vector<bool>(s + 1));

        int p = pizza(n , s);
        cout << abs(p - (count - p)) << '\n';
    }
    return 0;
}
