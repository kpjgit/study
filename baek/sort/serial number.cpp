//1431
#include <bits/stdc++.h>

int N;
std::vector<std::string> guitar;

bool cmp(const std::string& a, const std::string& b) {
    if(a.size() != b.size()) return a.size() < b.size();
    else {
        int sum_a = 0;
        int sum_b = 0;

        for(int i = 0; i < a.size(); i++) {
            if(a[i] > '0' && a[i] <= '9') sum_a += a[i] - '0';
            if(b[i] > '0' && b[i] <= '9') sum_b += b[i] - '0';
        }

        if(sum_a < sum_b) return true;
        else if(sum_a > sum_b) return false; 
    }

    return a < b;
}

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    for(int i = 0; i < N; i++) {
        std::string s;
        std::cin >> s;
        guitar.push_back(s);
    }

    std::sort(guitar.begin(), guitar.end(), cmp);
    for(int i = 0; i < N; i++) std::cout << guitar[i] << '\n';
}