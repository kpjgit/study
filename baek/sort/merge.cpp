//11728
#include <bits/stdc++.h>

int n, m;
int a[1000001];
int b[1000001];
int c[2000001];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> m;
    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for(int i = 0; i < m; i++) {
        std::cin >> b[i];
    }

    int idxa = 0;
    int idxb = 0;
    for(int i = 0; i < n + m; i++) {
        if(idxa == n) c[i] = b[idxb++];
        else if(idxb == m) c[i] = a[idxa++];
        else if(a[idxa] >= b[idxb]) c[i] = b[idxb++];
        else c[i] = a[idxa++];

        std::cout << c[i] << ' ';
    }
}