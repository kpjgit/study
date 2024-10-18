//1744
#include <bits/stdc++.h>

int N;

std::vector<int> positive;
std::vector<int> negative;

int sum(std::vector<int>& v) {
    int temp = 0;
    while(v.size() > 1) {
        temp += *(v.end() - 1) * *(v.end() - 2);
        v.pop_back();
        v.pop_back();
    }

    if(v.size() > 0) temp += v[0];

    return temp;
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    long long ans = 0;
    int temp;
    for(int i = 0; i < N; i++) {
        std::cin >> temp;
        if(temp == 1) ans++;
        else if(temp > 0) positive.push_back(temp);
        else negative.push_back(temp);
    }
    std::sort(positive.begin(), positive.end());
    std::sort(negative.begin(), negative.end(), std::greater<>());

    ans += sum(positive);
    ans += sum(negative);

    std::cout << ans;
}