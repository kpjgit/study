#include <iostream>
#include <string>

std::string str;

int alp[26];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::cin >> str;
    for(char c : str) {
        alp[c - 'A']++;
    }
    
    int odd_cnt = 0;
    int odd_idx = -1;
    for(int i = 0; i < 26; i++) {
        if(alp[i] % 2 == 1) {
            odd_cnt++;
            odd_idx = i;
        }
    }
    
    std::string ans;
    if(str.size() % 2 == 0 && odd_cnt == 0) {
        for(int i = 0; i < 26; i++) {
            for(int j = 0; j < alp[i] / 2; j++) {
                ans.push_back(i + 'A');
            }
            alp[i] /= 2;
        }
        
        for(int i = 25; i >= 0; i--) {
            for(int j = 0; j < alp[i]; j++) {
                ans.push_back(i + 'A');
            }
        }
        
        std::cout << ans;
    } else if(str.size() % 2 == 1 && odd_cnt == 1) {
        for(int i = 0; i < 26; i++) {
            for(int j = 0; j < alp[i] / 2; j++) {
                ans.push_back(i + 'A');
            }
            alp[i] /= 2;
        }
        
        ans.push_back(odd_idx + 'A');
        
        for(int i = 25; i >= 0; i--) {
            for(int j = 0; j < alp[i]; j++) {
                ans.push_back(i + 'A');
            }
        }
        
        std::cout << ans;
    } else {
        std::cout << "I'm Sorry Hansoo";
    }
}