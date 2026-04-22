#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <unordered_map>

int N;
std::string str[10];

std::pair<int, char> w[26];
std::unordered_map<char, int> table;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::cin >> N;
    for(char i = 'A'; i <= 'Z'; i++) w[i - 'A'].second = i;
    for(int i = 0; i < N; i++) {
        std::cin >> str[i];
        
        int x = 1;
        for(int j = str[i].size(); j >= 0; j--) {
            w[str[i][j] - 'A'].first += x;
            x *= 10;
        }
    }
    std::sort(w, w + 26, std::greater<std::pair<int, char>>());
    int num = 9;
    for(int i = 0; i < 10; i++) table[w[i].second] = num--;
    
    int ans = 0;
    for(int i = 0; i < N; i++) {
        int temp = 0;
        for(auto iter = str[i].begin(); iter != str[i].end(); iter++) {
            temp *= 10;
            temp += table[*iter];
        }
        ans += temp;
    }
    
    std::cout << ans;
}