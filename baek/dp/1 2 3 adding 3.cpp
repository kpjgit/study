//15988
#include <bits/stdc++.h>

int T;
std::vector<int> v;

long long table[1000001];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> T;
    int mx = 0;
    int temp;
    for(int i = 0; i < T; i++) {
        std::cin >> temp;
        mx = std::max(mx, temp);
        v.push_back(temp);
    }

    table[1] = 1; //1
    table[2] = 2; //11 2
    table[3] = 4; //111 12 21 3
    table[4] = table[1] + table[2] + table[3]; //1111 112 121 211 22 13 31
                                               //(111)1 (12)1 (21)1 (3)1 (11)2 (2)2 (1)3
    //table[i]는 table[i-1], table[i-2], table[i-3]을 만들기 위한 수 조합의 뒤에 각각 1, 2, 3을 붙인 것과 같다 

    for(int i = 4; i <= mx; i++) table[i] = (table[i - 1] + table[i - 2] + table[i - 3]) % 1000000009;

    for(int i : v) std::cout << table[i] << '\n';
}