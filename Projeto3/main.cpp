#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

vector<int> balance;
vector<vector<int>> adj;
vector<int> low;
vector<int> dfs;
vector<int> S;
vector<vector<int>> Scc;

void Tarjan(int v, int& t) {
    low[v] = dfs[v] = t;
    t = t + 1;
    S.push_back(v);
    for (auto w : adj[v]) {
        if (dfs[w] == 0) {
            Tarjan(w, t);
            low[v] = min(low[v], low[w]);
        }
        else if (find(S.begin(), S.end(), w) != S.end()) {
            low[v] = min(low[v], dfs[w]);
        }
    }
    if (low[v] == dfs[v]) {
        vector<int> C;
        int w;
        do {
            w = S.back();
            S.pop_back();
            C.push_back(w);
        } while (w != v);
        Scc.push_back(C);
    }
}


int main() {
    int num_banks;
    while (cin >> num_banks) {
        balance = vector<int>(num_banks + 1);
        adj = vector<vector<int>> (num_banks + 1);
        low = vector<int>(num_banks + 1, 0);
        dfs = vector<int>(num_banks + 1, 0);

        int t = 1;
        for (int i = 0; i < num_banks; i++) {
            int bank_id, amount, lender;
            cin >> bank_id;
            while (cin >> amount) {
                if(amount == 0){
                    break;
                }
                cin >> lender;
                balance[bank_id] -= amount;
                balance[lender] += amount;
                adj[bank_id].push_back(lender);
            }
        }

        for (int i = 1; i < num_banks + 1; i++) {
            if (dfs[i] == 0) {
                Tarjan(i, t);
            }
        }

        bool verifyCluster = false;
        int maxEntitled = INT_MIN;

        for (auto clusters : Scc) {
            if (clusters.size() > 1) {
                verifyCluster = true;
                int count = 0;
                for (auto num : clusters){
                    count += balance[num];
                }
                if (count > maxEntitled) {
                    maxEntitled = count;
                }
            }
        }

        if (verifyCluster){
            cout << maxEntitled << '\n';
        } else {
            cout << "No cluster\n";
        }
        S.clear();
        Scc.clear();
        
    }
    return 0;
}
