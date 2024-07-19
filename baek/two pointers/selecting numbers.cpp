//2230
#include <bits/stdc++.h>

int n, m;
int arr[100001];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> m;
    for(int i = 0; i < n; i++) std::cin >> arr[i];
    std::sort(arr, arr + n);

    int ans = arr[n - 1];
    int p0 = 0;
    int p1 = 0;

    while(p1 < n) {
        if(m > arr[p1] - arr[p0]) {
            p1++;
        } else if(m < arr[p1] - arr[p0]) {
            ans = std::min(ans, arr[p1] - arr[p0]);
            p0++;
        } else {
            ans = m;
            break;
        }
    }

    /*
    int mn = 0x7fffffff;
    int en = 0;
    for(int st = 0; st < n; st++) {
        while(en < n && arr[en] - arr[st] < m) en++;
        if(en == n) break;
        mn = std::min(mn, arr[en] - arr[st]);    
    }
    */

    std::cout << ans;
}