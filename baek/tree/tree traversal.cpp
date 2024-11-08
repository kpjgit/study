//1991
#include <bits/stdc++.h>

int N;
int left[26];
int right[26];

void preorder(int root) {
    std::cout << static_cast<char>(root + 'A');
    if(left[root]) preorder(left[root]);
    if(right[root]) preorder(right[root]);
}

void inorder(int root) {
    if(left[root]) inorder(left[root]);
    std::cout << static_cast<char>(root + 'A');
    if(right[root]) inorder(right[root]);
}

void postorder(int root) {
    if(left[root]) postorder(left[root]);
    if(right[root]) postorder(right[root]);
    std::cout << static_cast<char>(root + 'A');
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    char cur, l, r;
    for(int i = 1; i <= N; i++) {
        std::cin >> cur >> l >> r;
        if(l != '.') left[cur - 'A'] = l - 'A';
        if(r != '.') right[cur - 'A'] = r - 'A';
    }

    preorder(0);
    std::cout << '\n';
    inorder(0);
    std::cout << '\n';
    postorder(0);
}