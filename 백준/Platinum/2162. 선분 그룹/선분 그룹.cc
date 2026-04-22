#include <iostream>
#include <tuple>
#include <algorithm>

int N;
std::pair<std::pair<int, int>, std::pair<int, int>> line[3000];

int p[3000];
int size[3000];

int find(int x) {
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool uni(int u, int v) {
    u = find(u);
    v = find(v);
    
    if(u == v) return false;
    if(p[v] < p[u]) std::swap(u, v);
    if(p[u] == p[v]) p[u]--;
    p[v] = u;
    size[u] += size[v];
    
    return true;
}

int ccw(std::pair<int, int> p1, std::pair<int, int> p2, std::pair<int, int> p3) {
    int s = p1.first * p2.second + p2.first * p3.second + p3.first * p1.second;
    s -= p1.second * p2.first + p2.second * p3.first + p3.second * p1.first;
    
    if(s > 0) return 1;
    else if(s == 0) return 0;
    else return -1;
}

bool is_intersect(std::pair<std::pair<int, int>, std::pair<int, int>>& l1, std::pair<std::pair<int, int>, std::pair<int, int>>& l2) {
    std::pair<int, int> p1 = l1.first;
    std::pair<int, int> p2 = l1.second;
    std::pair<int, int> p3 = l2.first;
    std::pair<int, int> p4 = l2.second;
    
    long long p1p2 = (long long)ccw(p1, p2, p3) * ccw(p1, p2, p4);
    long long p3p4 = (long long)ccw(p3, p4, p1) * ccw(p3, p4, p2);
    
    if(p1p2 == 0 && p3p4 == 0) {
        if(p1 > p2) std::swap(p2, p1);
        if(p3 > p4) std::swap(p3, p4);
        
        return p3 <= p2 && p1 <= p4;
    }
    
    return p1p2 <= 0 && p3p4 <= 0;
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::cin >> N;
    for(int i = 0; i < N; i++) {
        std::cin >> line[i].first.first >> line[i].first.second >> line[i].second.first>> line[i].second.second;
    }
    
    std::fill(p, p + N, -1);
    std::fill(size, size + N, 1);
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            if(is_intersect(line[i], line[j])) {
                uni(i, j);
            }
        }
    }
    
    int size_ans = 0;
    int ans = 0;
    for(int i = 0; i < N; i++) {
        size_ans = std::max(size_ans, size[i]);
        if(p[i] < 0) ans++;
    }
    std::cout << ans << '\n' << size_ans;
}