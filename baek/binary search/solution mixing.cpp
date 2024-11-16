//14921 투포인터
#include <bits/stdc++.h>

int N;
int arr[100000];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    for(int i = 0; i < N; i++) std::cin >> arr[i];
    
    int ans = 200000001;
    
    int st = 0;
    int en = N - 1;
    while(st < en) {
        int sum = arr[st] + arr[en];

        if(std::abs(ans) > std::abs(sum)) ans = sum;

        if(sum > 0) en--;
        else st++;
    }

    std::cout << ans;
}