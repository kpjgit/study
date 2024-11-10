//2250
#include <bits/stdc++.h>

int N;
int lc[10001], rc[10001];

int root;
bool not_root[10001];
int col_no;
std::pair<int, int> row_pair[10001]; //왼쪽 끝, 오른쪽 끝

void inorder(int cur, int depth) {
    if(cur == -1) return;

    inorder(lc[cur], depth + 1);

    col_no++; //중위순회로 열 크기를 늘려가면서 각 깊이의 왼쪽, 오른쪽 쌍을 저장
    auto& row = row_pair[depth];
    if(!row.first || col_no < row.first) row.first = col_no;
    if(!row.second || row.second < col_no) row.second = col_no;

    inorder(rc[cur], depth + 1);
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    int p, l, r;
    for(int i = 0; i < N; i++) {
        std::cin >> p >> l >> r;
        lc[p] = l;
        rc[p] = r;

        if(l != -1) not_root[l] = true;
        if(r != -1) not_root[r] = true;
    }

    for(int i = 1; i <= N; i++) {
        if(not_root[i] == false) {
            root = i;
            break;
        }
    }

    inorder(root, 1);

    int width = 0;
    int height = 0;
    for(int i = 1; i <= N; i++) {
        auto row = row_pair[i];
        if(row.first == 0 && row.second == 0) break;

        int temp = row.second - row.first + 1;
        if(temp > width) {
            width = temp;
            height = i;
        }
    }

    std::cout << height << ' ' << width;
}