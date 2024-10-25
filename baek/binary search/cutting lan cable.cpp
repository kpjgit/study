//1654 pharametric
#include <bits/stdc++.h>

int K, N;
int arr[10000];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> K >> N;
    long long st = 1;
    long long en = 0x7fffffff;
    for(int i = 0; i < K; i++) std::cin >> arr[i];

    while(st < en) {
        long long mid = (st + en + 1) / 2;
        
        int cnt = 0;
        for(int i = 0; i < K; i++) cnt += arr[i] / mid;

        if(cnt >= N) st = mid;
        else en = mid - 1;
    }
    
    std::cout << st;
}