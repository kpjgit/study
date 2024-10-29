//13144
#include <bits/stdc++.h>

int N;
int arr[100000];

bool used[100001];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    for(int i = 0; i < N; i++) std::cin >> arr[i];

    int st = 0;
    used[arr[0]] = true;
    int en = 1;
    long long ans = 1;
    while(st < N && en < N) {
        if(used[arr[en]]) {
            used[arr[st]] = false;
            st++;
        } else {
            ans += en - st + 1;
            used[arr[en]] = true;
            en++;
        }
    }

    std::cout << ans;
}