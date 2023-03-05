
#include<iostream>
using namespace std;
const int MAXN = 20;
const int MAXM = 20;

const int dx[] = { -1,0,0,1 };
const int dy[] = { 0,-1,1,0 };

int n, m;
char G[MAXN + 5][MAXM + 5];

bool dfs(int x, int y) {
    if (G[x][y] != '0') return false;
    G[x][y] = '*';
    if (x == n && y == m) return true;
    for (int i = 0; i < 4; ++i)
        if (dfs(x + dx[i], y + dy[i])) return true;
    G[x][y] = '0';
    return false;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> G[i][j];
    for (int i = 0; i <= n + 1; ++i)
        G[i][0] = G[i][m + 1] = '1';
    for (int i = 0; i <= m + 1; ++i)
        G[0][i] = G[n + 1][i] = '1';
    if (dfs(1, 1)) {
        cout << endl;
        cout << "----- * is the way -----" << endl;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; j++)
            {
                cout << G[i][j];
            }
            cout << endl;
        }
    }
    else cout << "误解" << endl;
    return 0;
}
/*
5 5
01000
00010
01100
01001
00100
*/

