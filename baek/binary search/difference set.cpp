//1822
#include <bits/stdc++.h>

int na, nb;
int A[500000], B[500000];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> na >> nb;
    for(int i = 0 ; i < na; i++) std::cin >> A[i];
    for(int i = 0 ; i < nb; i++) std::cin >> B[i];
    std::sort(B, B + nb);

    int cnt = 0;
    std::vector<int> v;
    for(int i = 0; i < na; i++) { //nlogn
        if(!std::binary_search(B, B + nb, A[i])) {
            cnt++;
            v.push_back(A[i]);
        }
    }
    std::sort(v.begin(), v.end());

    if(cnt == 0) std::cout << 0;
    else {
        std::cout << cnt << '\n';
        for(int i : v) std::cout << i << ' ';
    }
}