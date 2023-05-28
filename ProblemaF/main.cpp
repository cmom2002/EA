#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;

int guarda(vector<int> p){
    sort(p.begin(), p.end());
    int i = 0;

    vector<int> g = vector<int>(n);
    g[i] = p[0] + m;
    for(int j = 1; j < n; j++){
        if(g[i] + m < p[j]){
            i += 1;
            g[i] = p[j] + m;
        }
    }
    return i + 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int testes, fim = 0;
    cin >> testes;

    while(testes != fim){

        cin >> n >> m;
        vector<int> p = vector<int>(n);
        for (int i = 0; i < n; i++)
            cin >> p[i];

        cout << guarda(p) << '\n';
        fim ++;
    }
    return 0;
}
