//-1
#include <bits/stdc++.h>

const int root = 1;
int unused = 2;
const int max = 10000 * 500 + 5;
bool chk[max];
int nxt[max][26];

int c2i(char c) {
    return c - 'A';
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

void erase(std::string& s) {
    int cur = root;
    for(auto c : s) {
        if(nxt[cur][c2i(c)] == -1) {
            return;
        }
        cur = nxt[cur][c2i(c)];
    }

    chk[cur] = false;
}

int main(void) {
    for(int i = 0; i < max; i++) std::fill(nxt[i], nxt[i] + 26, -1);

}