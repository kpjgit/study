//4796
#include<bits/stdc++.h>

int L, P, V;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int num = 1;
    while(true) {
        std::cin >> L >> P >> V;
        if(L == 0 && P == 0 && V == 0) break;
    
        int ans = (V / P) * L + std::min(V % P, L);
        std::cout << "Case " << num << ": " << ans << '\n';

        num++;
    }
}