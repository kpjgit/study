#include <bits/stdc++.h>

int N, M, K;
long long arr[1000000];

constexpr int mx = 1 << 21;
long long tree[mx]; //idx가 1일때 루트
int leaf;

void build(long long* arr) {
    int height = 0;
    while ((1 << height) < N) height++;
    leaf = 1 << height;

    for (int i = 0; i < N; i++) {
        tree[leaf + i] = arr[i];
    }

    for (int i = leaf - 1; i >= 1; i--) {
        tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }
}

void update(int idx, long long val) {
    idx = leaf + idx;

    tree[idx] = val;
    while (idx > 1) {
        idx /= 2;
        tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
    }
}

long long query(int left, int right) {
    left += leaf;
    right += leaf;

    long long res = 0;
    while (left <= right) {
        if (left % 2 == 1) res += tree[left++];
        if (right % 2 == 0) res += tree[right--];

        left /= 2;
        right /= 2;
    }

    return res;
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> M >> K;

    for (int i = 0; i < N; i++) std::cin >> arr[i];
    build(arr);

    int op;
    long long val1, val2;
    for (int num = 0; num < M + K; num++) {
        std::cin >> op >> val1 >> val2;
        if (op == 1) {
            update(val1 - 1, val2);
        }
        else {
            std::cout << query(val1 - 1, val2 - 1) << '\n';
        }
    }
}