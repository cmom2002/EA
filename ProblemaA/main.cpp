#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> set;
vector<int> ranking;

int find(int a){
    if (set[a] != a){
        set[a] = find(set[a]);
    }
    return set[a];
}

void link(int a, int b){
    if (ranking[a] > ranking[b]){
        set[b] = a;
    }
    else{
        set[a] = b;
    }
    if(ranking[a] == ranking[b]){
        ranking[b]++;
    }
}

void union_banks(int a, int b){
    link(find(a), find(b));
}

void make_set(int i){
    set[i] = i;
    ranking[i] = 0;
}

int main(){
    int num_banks, bank_id, amount, lender;

    while (cin >> num_banks){
        if (num_banks == 0){
            break;
        }
        set = vector<int>(num_banks);
        ranking = vector<int>(num_banks);
        for(int i = 0; i < num_banks; i ++){
            make_set(i);
        }

        for (int i = 0; i < num_banks; i++){
            cin >> bank_id;
            while(cin >> amount){
                if(amount == 0){
                    break;
                }
                cin >> lender;
                union_banks(bank_id, lender);
            }
        }
        for(int i = 0; i < num_banks; i++){
            cout << set[i] << " ";
        }
    }
}