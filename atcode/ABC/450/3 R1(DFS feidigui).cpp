#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;

    vector<string> s(h);
    for (int i = 0; i < h; i++) {
        cin >> s[i];
    }

    vector<vector<int>> vis(h, vector<int>(w, 0));
    int answer = 0;

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (s[i][j] == '#' || vis[i][j]) continue;

            bool touches_border = false;
            stack<pair<int, int>> st;
            st.push({i, j});
            vis[i][j] = 1;

            while (!st.empty()) {
                pair<int, int> cur = st.top();
                st.pop();

                int x = cur.first;
                int y = cur.second;

                if (x == 0 || x == h - 1 || y == 0 || y == w - 1) {
                    touches_border = true;
                }

                for (int dir = 0; dir < 4; dir++) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];

                    if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                    if (s[nx][ny] == '#') continue;
                    if (vis[nx][ny]) continue;

                    vis[nx][ny] = 1;
                    st.push({nx, ny});
                }
            }

            if (!touches_border) {
                answer++;
            }
        }
    }

    cout << answer << '\n';
    return 0;
}