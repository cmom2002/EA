#include <iostream>
#include <algorithm>

using namespace std;

int visit [400][400];


int chess (int x, int y, int m){
    int total_moves = 0;

    if (visit[x + 200][y + 200] == 0) {
        total_moves = 1;
        visit[x + 200][y + 200] = 1;
    }
    if (m > 0){
        total_moves = total_moves
                      + chess (x + 2, y + 1, m - 1)
                      + chess (x + 2, y - 1, m - 1)
                      + chess (x - 2, y + 1, m - 1)
                      + chess (x - 2, y - 1, m - 1)
                      + chess (x + 1, y + 2, m - 1)
                      + chess (x + 1, y - 2, m - 1)
                      + chess (x - 1, y + 2, m - 1)
                      + chess (x - 1, y - 2, m - 1);
    }

    return total_moves;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 0; i < 400; i++){
        for( int j = 0; j < 400; j++){
            visit[i][j] = 0;
        }
    }
    int tam;
    cin >> tam;

    int total_moves = 0;

    for(int i = 0; i < tam; i++){
        int x, y, m;
        cin >> x >> y >> m;
        total_moves += chess(x, y, m);

    }

    cout << total_moves << "\n";
    return 0;
}