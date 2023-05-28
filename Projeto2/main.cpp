#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
using namespace std;

int n, d, k, r;
vector<vector<int>> v;
long long int total = 0;
vector<vector<long long int>> dp;
vector<vector<int>> followtrans;
vector<int> savepath;
vector<int> counts;
vector<vector<int>> matriz;
//(v*3) - (c*3+r*3)

struct output{
    long long int profit;
    vector<int> path;
};

output profitcalc(int comp) {
    int current = v[comp][0];
    int count = 0;
    
    for (int i = 0; i < d; i++){
        if (v[comp][i] == current) {
            count++;
        } else {
            counts.push_back(count);
            current = v[comp][i];
            count = 1;
        }

        if(i == 0){
            dp[0][1] = 0-(v[comp][0] + r) * k;
            followtrans[0][1] = k;
        }
        else{
            //sell
            if(dp[i-1][1] + v[comp][i] * k > dp[i-1][0]){
                dp[i][0] = dp[i-1][1] + v[comp][i] * k;
                followtrans[i][0] = -k;
            }
            else{
                dp[i][0] = dp[i-1][0];
                followtrans[i][0] = 0;
            }
            //buy
            if(dp[i-1][0] - (v[comp][i] + r) * k > dp[i-1][1]){
                dp[i][1] = dp[i-1][0] - (v[comp][i] + r) * k;
                followtrans[i][1] = k;
            }
            else{
                dp[i][1] = dp[i-1][1];
                followtrans[i][1] = 0;
            }
        }

    }
    counts.push_back(count);
    int j = 0;

    for (int i = d-1; i >= 0; i--)
    {
        if(followtrans[i][j] != 0){
            savepath[i] = followtrans[i][j];
            j = (j+1) % 2;
        }
        else{
            savepath[i] = 0;
        }
    }

    struct output o;
    o.profit = dp[d-1][0];
    o.path = savepath;
    return o;
}

void calc_table(){
    for (int i = 0; i < k + 1; i++) {
        matriz[i][0] = 1;
    }
    for (int i = 0; i < d; i++) {
        matriz[0][i] = 1;
    }

    for (int i = 1; i < k + 1; i++) {
        for (int j = 1; j < d; j++) {
            matriz[i][j] = matriz[i-1][j] + matriz[i][j-1];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int task;
    cin >> task;
    cin >> n >> d >> k >> r;
    
    v.resize(n, vector<int>(d));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < d; j++) {
            cin >> v[i][j];
        }
    }
    if(task == 1){
        for (int i = 0; i < n; i++){
            dp.resize(d, vector<long long int>(2, 0));
            followtrans.resize(d, vector<int>(2));
            savepath.resize(d, 0);
            cout << profitcalc(i).profit << endl;
        }
    }   
    if (task == 2){
        for (int i = 0; i < n; i++)
        {
            dp.resize(d, vector<long long int>(2, 0));
            followtrans.resize(d, vector<int>(2));
            savepath.resize(d, 0);
            
            struct output o = profitcalc(i);
            cout << o.profit << endl;
            for (int i = 0; i < d; i++)
            {
                cout << o.path[i] << " ";
            }
            cout << endl;
            
        }
    }
    if(task == 3){
        matriz = vector<vector<int>>(k + 1, vector<int>(d));
        calc_table();
        for (int i = 0; i < n; i++){
            dp.resize(d, vector<long long int>(2, 0));
            followtrans.resize(d, vector<int>(2));
            savepath.resize(d, 0);
            cout << profitcalc(i).profit << " ";
            int options = 0;
            for (int j = 0; j < counts.size(); j++) {
                if (counts[j] > 1) {
                    options += matriz[k][counts[j] - 1];
                }
            }
            if(options == 0){
                options = 1;
            }
            
            cout << options % int((pow(10, 9) + 7)) << endl;
            counts.clear();
        }
    }

    return 0;
}