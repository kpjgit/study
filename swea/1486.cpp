#include <bits/stdc++.h>

int T;
int N, B;
int arr[20];

int ans;

void func(int sum, int cnt) {
    if(cnt == N) {
        if(sum >= B) ans = std::min(ans, sum);
        return;
    }
    
    func(sum + arr[cnt], cnt + 1);
    func(sum, cnt + 1);
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::cin >> T;
    for(int num = 1; num <= T; num++) {
        std::cin >> N >> B;
        ans = 20 * 10000 + 1;
        for(int i = 0; i < N; i++) {
            std::cin >> arr[i];
        }
        
        func(0, 0);
        
        std::cout << '#' << num << ' ' << ans - B << '\n';
    }
}