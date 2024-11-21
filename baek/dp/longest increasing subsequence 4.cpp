//14002
#include <bits/stdc++.h>

int N;
int A[1000];

int table[1000], pre[1000];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        table[i] = 1;
    }
    std::fill(pre, pre + N, -1);

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < i; j++) {
            if(A[j] < A[i] && table[i] < table[j] + 1) {
                table[i] = table[j] + 1;
                pre[i] = j;
            }
        }
    }

    int idx = 0;
    int len = table[0];
    for(int i = 1; i < N; i++) {
        if(len < table[i]) {
            idx = i;
            len = table[i];
        }
    }

    std::vector<int> ans;
    while(idx >= 0) {
        ans.push_back(A[idx]);
        idx = pre[idx];
    }

    std::cout << ans.size() << '\n';
    for(auto i = ans.rbegin(); i != ans.rend(); i++) std::cout << *i << ' ';
}