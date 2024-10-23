//1038
#include <bits/stdc++.h>

int N;
//0 1 2 3 4 5 6 7 8 9 10 21 20 32 31 30 43 42 41 40 54 53 52 51 50 ... 210 321 320 310 432 431 430 421 420 410
//9876543210 마지막 감소수
//int arr[11][10]; //자릿수, 앞자리수, i자리수 감소수인데 앞자리가 j로 고정됐을 경우 arr[i][j]=arr[i-1][j-1]+arr[i-1][j-2]... or arr[i][j]=arr[i][j-1]+arr[i-1][j-1]
//dp로 풀면 복잡해짐

std::vector<long long> v;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    for(int num = 1; num < (1 << 10); num++) { //0~9는 중복 불가, 0~9의 조합 중 하나는 조건을 만족함
        int brute = num;
        long long temp = 0;
        for(int i = 9; i >= 0; i--) {
            if(brute % 2 == 1) temp = temp * 10 + i;
            brute /= 2;

            if(brute == 0) break;
        }
        v.push_back(temp);
    }
    std::sort(v.begin(), v.end());
    
    if(N >= v.size()) std::cout << -1;
    else std::cout << v[N];
}