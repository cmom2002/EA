#include <iostream>
#include <vector>

using namespace std;

int members, best;
vector<int> v;
vector<vector<bool>> connections;


void resolve(int ind,  int size){
    if(size > best)
        best = size;

    if(ind == members)
        return;

    int aux = 0;
    for(int i = ind + 1; i < members; i++){
        if(v[i] == 0)
            aux++;
    }

    if(size + aux <= best)
        return;

    for(int i = ind + 1; i < members; i++){
        if(connections[ind][i])
            v[i]++;
    }
    for(int i = ind + 1; i < members; i++){
        if(v[i] == 0)
            resolve(i, size + 1);
    }
    for(int i = ind + 1; i < members; i++){
        if(connections[ind][i])
            v[i]--;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n_members, n_connect;
    cin >> n_members >> n_connect;
    members = n_members;
    
    v = vector<int>(n_members);
    connections = vector<vector<bool>>(n_members, vector<bool>(n_members));
    int i, j;
    while (n_connect){
        cin >> i >> j;
        connections[i][j] = true;
        connections[j][i] = true;
        n_connect--;
    }
    best = 0;
    for(int p = 0; p < n_members; p++)
        resolve(p, 1);

    cout << best << '\n';
    return 0;
}
