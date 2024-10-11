//1912
#include <bits/stdc++.h>

int n;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n;
    
    int ans = -1000 * 100000;
    int sum = 0;
    for(int i = 0; i < n; i++) { //카데인, i까지의 합이 음수만 아니면 최댓값 후보가 될 수 있다
        int temp;
        std::cin >> temp;

        sum += temp;
        ans = std::max(ans, sum);

        if(sum < 0) sum = 0;
    }

    std::cout << ans;
}