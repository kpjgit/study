//15685
#include <bits/stdc++.h>

int N;
bool arr[101][101];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

int mx_x = 0;
int mx_y = 0;

int ans = 0;

void func(int cnt, int gen, std::vector<std::pair<int, int>>& v) {
    if(cnt == gen) return;

    int x_end, y_end;
    std::tie(x_end, y_end) = v.back();
    for(int i = v.size() - 2; i >= 0; i--) {
        int x, y;
        std::tie(x, y) = v[i];
        
        x -= x_end;
        y -= y_end;
        std::swap(x, y);
        x *= -1;
        x += x_end;
        y += y_end;
        
        arr[y][x] = true;
        v.push_back({x, y});
        mx_x = std::max(mx_x, x);
        mx_y = std::max(mx_y, y);
    }
    func(cnt + 1, gen, v);
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int x, y, d, g; //(y, x) 우상좌하
    std::cin >> N;
    for(int i = 0; i < N; i++) {
        std::cin >> x >> y >> d >> g;
        std::vector<std::pair<int, int>> v;

        arr[y][x] = true;
        v.push_back({x, y});
        mx_x = std::max(mx_x, x);
        mx_y = std::max(mx_y, y);

        x += dx[d];
        y += dy[d];
        arr[y][x] = true;
        v.push_back({x, y});
        mx_x = std::max(mx_x, x);
        mx_y = std::max(mx_y, y);
        
        func(0, g, v);
    }

    for(int i = 0; i < mx_y; i++) {
        for(int j = 0; j < mx_x; j++) {
            if(arr[i][j] && arr[i + 1][j] && arr[i][j + 1] && arr[i + 1][j + 1]) ans++;
        }
    }

    std::cout << ans;
}