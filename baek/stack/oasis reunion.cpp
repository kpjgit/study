//3015
#include <bits/stdc++.h>

int N;
std::stack<std::pair<int, int>> s; //키, 같은 키를 가진 사람의 수

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    
    long long ans = 0;
    int input;
    for(int i = 0; i < N; i++) {
        std::cin >> input;

        int cnt = 1;
        //input을 기준으로 스택 안의 사람을 볼때
        while(!s.empty() && s.top().first <= input) { //현재 입력받은 키가 앞 사람보다 크면 앞에 있는 사람들은 그 이후의 사람을 절대 볼 수 없다, 스택은 항상 내림차순을 유지한다
            ans += s.top().second;
            if(s.top().first == input) cnt += s.top().second;
            s.pop();
        }

        //스택의 가장 위에 있는 사람을 기준으로 input을 볼때
        if(!s.empty()) ans++; //인접한 사람은 키와 상관 없이 항상 볼 수 있으므로 스택이 비어있지 않으면 매번 입력마다 1을 더해준다

        s.push({input, cnt});
    }

    std::cout << ans;
}