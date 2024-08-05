//14425
#include <bits/stdc++.h>

const int root = 1;
int unused = 2;
const int max = 10000 * 500 + 5;
bool chk[max];
int nxt[max][26];

int n, m;

int c2i(char c) {
    return c - 'a';
}

void insert(std::string& s) {
    int cur = root;
    for(auto c : s) {
        if(nxt[cur][c2i(c)] == -1) {
            nxt[cur][c2i(c)] = unused++;
        }
        cur = nxt[cur][c2i(c)];
    }
    chk[cur] = true;
}

bool find(std::string& s) {
    int cur = root;
    for(auto c : s) {
        if(nxt[cur][c2i(c)] == -1) {
            return false;
        }
        cur = nxt[cur][c2i(c)];
    }

    return chk[cur];
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    for(int i = 0; i < max; i++) std::fill(nxt[i], nxt[i] + 26, -1);

    std::cin >> n >> m;
    for(int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;
        insert(s);
    }

    int ans = 0;
    for(int i = 0; i < m; i++) {
        std::string s;
        std::cin >> s;
        ans += find(s);
    }

    std::cout << ans;
}