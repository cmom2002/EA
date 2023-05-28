#include <iostream>
#include <vector>

using namespace std;

int n, k, m;
vector<bool> ligado;
vector<int> nLig;
vector<vector<int>> cost;

int best = 10000;

void ze(int v, int c){
    if (v == n-1) {
        if (c < best)
            best = c;
        return;
    }
    if (c >= best)
        return;

    for (int i = 0; i < n; i++){
        if (ligado[i]){
            for (int j = 0; j < n; j++){
                if (!ligado[j]) {
                    if (cost[i][j] > 0 && nLig[i] < k) {
                        nLig[i] += 1;
                        nLig[j] += 1;
                        ligado[j] = true;
                        ze(v + 1, c + cost[i][j]);
                        nLig[i] += -1;
                        nLig[j] += -1;
                        ligado[j] = false;
                    }
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while(cin >> n){
        cin >> m >> k;

        nLig= vector<int>(n);

        for (int i = 0; i < n; i++) {
            if (i == 0)
                ligado.push_back(true);
            else
                ligado.push_back(false);
        }

        cost = vector<vector<int>>(n, vector<int>(n));

        int x, y, c;
        for (int j = 0; j < m; j++) {
            cin >> x >> y >> c;
            cost[x - 1][y - 1] = c;
            cost[y - 1][x - 1] = c;
        }

        ze(0, 0);

        if (best < 10000)
            cout << best << "\n";
        else
            cout << "NO WAY!\n";

        best = 10000;
    }

    return 0;
}
