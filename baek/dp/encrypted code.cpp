//2011
#include <bits/stdc++.h>

std::string s;
int arr[5001];

int table[5001]; //table[i], 앞에서 i자리까지 가능한 모든 조합

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> s;
    for(int i = 1; i <= s.size(); i++) arr[i] = s[i - 1] - '0';
    
    table[0] = 1;
    for(int i = 1; i <= s.size(); i++) {
        if(arr[i] > 0) table[i] = table[i - 1] % 1000000; //i자리가 추가되는건 i-1까지의 조합과 같음
        
        int temp = arr[i - 1] * 10 + arr[i];
        if(temp >= 10 && temp <= 26) {
            table[i] = (table[i] + table[i - 2]) % 1000000; //i의 앞자리와 붙일 수 있는 경우 i-2까지의 조합을 더함
        }
    }

    std::cout << table[s.size()];
}