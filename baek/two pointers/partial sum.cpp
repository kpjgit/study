//1806
#include <bits/stdc++.h>

int n, s;
int arr[100001];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> s;
    for(int i = 0; i < n; i++) std::cin >> arr[i];
    std::sort(arr, arr + n);

    int temp = arr[0];
    int cnt = 1;
    int ans = 200000;
    int st = 0;
    int en = 0;

    while(en < n && st <= en) {
        if(temp < s) {
            en++;
            cnt++;
            temp += arr[en];
        } else if(temp == s) {
            ans = std::min(ans, cnt);
            en++;
            cnt++;
            temp += arr[en];
        } else if(temp > s) {
            ans = std::min(ans, cnt);
            temp -= arr[st];
            st++;
            cnt--;
        }
    }

    /*
    for(int st = 0; st < n; st++) {
        while(en < n && temp < s){
            en++;
            if(en != n) temp += arr[en];
        }

        if(en == n) break;
        ans = std::min(ans, en - st + 1);
        temp -= arr[st];
    }
    */

    if(ans == 200000) ans = 0;

    std::cout << ans;
}