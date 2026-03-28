#include <bits/stdc++.h>
using namespace std;

int h, w;
vector<string> s;
vector<vector<int>> vis;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool touches_border;

void dfs(int x, int y) {
    vis[x][y] = 1;
    
    if (x == 0 || x == h - 1 || y == 0 || y == w - 1) {
        touches_border = true;
    }

    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
        if (s[nx][ny] == '#') continue;
        if (vis[nx][ny]) continue;

        dfs(nx, ny);
    }
}

int main() {
    cin >> h >> w;
    s.resize(h);//这里就是对全局变量的好处
    for (int i = 0; i < h; i++) {
        cin >> s[i];
    }

    vis.assign(h, vector<int>(w, 0));

    int answer = 0;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (s[i][j] == '#' || vis[i][j]) continue;

            touches_border = false;
            dfs(i, j);

            if (!touches_border) {
                answer++;
            }
        }
    }

    cout << answer << '\n';
    return 0;
}

//////////状态的visited设置，访问过没有是这道题目的精髓