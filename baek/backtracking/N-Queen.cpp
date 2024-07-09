//9663
#include <bits/stdc++.h>

int n;
int num = 0;
bool used1[20];
bool used2[20];
bool used3[20];

void func(int cur) {
    if(cur == n) {
        num++;
        return;
    }

    for(int i = 0; i < n; i++) {
        if(used1[i] || used2[i + cur] || used3[cur + n - i -1]) continue;
        used1[i] = 1;
        used2[i + cur] = 1;
        used3[cur + n - i - 1] = 1;
        func(cur + 1);
        used1[i] = 0;
        used2[i + cur] = 0;
        used3[cur + n - i - 1] = 0;
    }
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n;
    func(0);
    std::cout << num;
}