#include <bits/stdc++.h>

int N;

int ans[10];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::cin >> N;
    
    int digit = 1;
    while(digit <= N) {
        int left = N / (digit * 10);
        int cur = (N / digit) % 10; //현재 자릿수
        int right = N % digit;
        
        for(int i = 0; i < 10; i++) {
            if(i == 0) ans[i] -= digit; //가장 앞에는 0이 올 수 없기 때문에 i가 0일때는 매번 digit만큼 뺀다
            
            if(cur > i) ans[i] += (left + 1) * digit; //cur이 i보다 클 경우 0~left까지
            else if(cur == i) ans[i] += left * digit + right + 1; //0~left-1+뒤에 올 수 있는 숫자 0~right
            else ans[i] += left * digit; //cur이 i보다 작을 경우 0~left-1까지
        }
        
        digit *= 10;
    }
    
    for(int i = 0; i < 10; i++) std::cout << ans[i] << ' ';
}