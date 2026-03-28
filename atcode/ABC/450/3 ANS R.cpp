#include <bits/stdc++.h>
#include <atcoder/dsu>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;

    vector<string> s(h);
    for (int i = 0; i < h; i++) {
        cin >> s[i];
    }

    auto id = [&](int i, int j) {
        return i * w + j;
    };

    atcoder::dsu d(h * w);

    // 横向合并
    for (int i = 0; i < h; i++) {
        for (int j = 0; j + 1 < w; j++) {
            if (s[i][j] == '.' && s[i][j + 1] == '.') {
                d.merge(id(i, j), id(i, j + 1));
            }
        }
    }

    // 纵向合并
    for (int i = 0; i + 1 < h; i++) {
        for (int j = 0; j < w; j++) {
            if (s[i][j] == '.' && s[i + 1][j] == '.') {
                d.merge(id(i, j), id(i + 1, j));
            }
        }
    }

    set<int> all_white_components;
    set<int> border_white_components;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (s[i][j] == '.') {
                int leader = d.leader(id(i, j));
                all_white_components.insert(leader);

                if (i == 0 || i == h - 1 || j == 0 || j == w - 1) {
                    border_white_components.insert(leader);
                }
            }
        }
    }
    /////////////////相当于标过号，相同的地块就标了相同的号。
                   //可能A不在边界，总体有一个编号加入；B在边界，总体也有一个相同编号加入，反正set加不进去。
                                                    //反而B还会加入另外一个

    cout << (int)all_white_components.size() - (int)border_white_components.size() << '\n';
    return 0;
}