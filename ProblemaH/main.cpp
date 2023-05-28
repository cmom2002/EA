#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

map <int,vector <int>> M;
vector <int> values;

bool insere(int n, int m){
    int a, b;
    bool ver = true;
    while (m){
        cin >> a >> b;
        if (a > n || b > n || a == b){
            ver = false;
        }
        M[a].push_back(b);
        M[b].push_back(a);
        m--;
    }
    return ver;
}

bool solve (int n){
    
    for (int i = 1; i<=n; ++i){
        if (values[i]==-1){
            queue<int> pilha;

            values[i]=1;
            pilha.push(i);

            while(!pilha.empty()){
                int t = pilha.front();
                pilha.pop();
                
                for(int ind : M[t]){
                    if(values[ind] == -1){
                        values[ind] = 1 - values[t];
                        pilha.push(ind);
                    }
                    else if(values[ind] == values[t])
                        return false;
                }
            }
        }    
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;

    while (cin >> n >> m){
        M.clear();
        
        if (!insere(n, m)){
            cout << "NO" << endl;
        }
        else{
            values.clear();
            values.resize(n + 1, -1);
            if (solve(n))
                cout << "NOT SURE" << endl;
            else
                cout << "NO" << endl;
        }        
    }
    return 0;
}