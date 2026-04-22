#include <iostream>

int N, k;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::cin >> N >> k;
    
    //정렬됐을 때 B[k]보다 작거나 같은 값은 적어도 k개만큼 존재한다.
    long long st = 1;
    long long en = (long long)N * N;
    while(st < en) {
        long long mid = (st + en) / 2;
        
        long long cnt = 0;
        //row 하나에 최대 N개, i*j이므로 mid/row를 하면 갯수인 j
        for(int row = 1; row <= N; row++) {
            long long temp = mid / row;
            if(temp > N) temp = N;
            cnt += temp;
        }
        
        if(cnt < k) {
            st = mid + 1;
        } else {
            en = mid;
        }
    }
    
    std::cout << st;
}