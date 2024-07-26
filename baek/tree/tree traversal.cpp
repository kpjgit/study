//1991
#include <bits/stdc++.h>

int n;
char lc[27];
char rc[27];

void preorder(char cur) {
    std::cout << cur << ' ';
    if(lc[cur - 'A']) preorder(lc[cur - 'A']);
    if(rc[cur - 'A']) preorder(rc[cur - 'A']);
}

void inorder(char cur) {
    if(lc[cur - 'A']) inorder(lc[cur - 'A']);
    std::cout << cur << ' ';
    if(rc[cur - 'A']) inorder(rc[cur - 'A']);
}

void postorder(char cur) {
    if(lc[cur - 'A']) postorder(lc[cur - 'A']);
    if(rc[cur - 'A']) postorder(rc[cur - 'A']);
    std::cout << cur << ' ';
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n;
    for(int i = 0; i < n; i++) {
        char root, l, r;
        std::cin >> root >> l >> r;
        if(l != '.') lc[root - 'A'] = l;
        if(r != '.') rc[root - 'A'] = r;
    }

    preorder('A');
    std::cout << '\n';
    inorder('A');
    std::cout << '\n';
    postorder('A');
    std::cout << '\n';
}