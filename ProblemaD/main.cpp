#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> in;
vector<vector<int>> sum;

int path(int i, int j)
{
    if (j > i)
        return 0;

    else if (sum[i][j] > 0 || i == 0)
        return sum[i][j];

    else if (j == 0)
        sum[i][j] = in[i][j] + path(i - 1, j);

    else
        sum[i][j] = in[i][j] + max(path(i - 1, j - 1), path(i - 1, j));

    return sum[i][j];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, n_rows;
    vector<int> row;

    cin >> n;

    while (n != 0)
    {
        cin >> n_rows;

        int res = 0;
        in = vector<vector<int>>(n_rows, vector<int>(n_rows));
        sum = vector<vector<int>>(n_rows, vector<int>(n_rows));

        for (int i = 0; i < n_rows; i++)
            for (int j = 0; j <= i; j++)
                cin >> in[i][j];

        sum[0][0] = in[0][0];

        for (int i = 0; i < n_rows; i++)
            path(n_rows - 1, i);

        for (int i = 0; i < n_rows; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (sum[i][j] > res)
                    res = sum[i][j];
            }
        }

        cout << res << "\n";

        n--;
    }

    return 0;
}