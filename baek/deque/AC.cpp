//5430
#include <bits/stdc++.h>

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::deque<int> d;
    std::cin >> T;
    std::string func, arr;
    int num;
    bool rev;
    bool error;
    for(int i = 0; i < T; i++) {
        error = false;
        rev = false;
        std::cin >> func >> num >> arr;

        int cur = 0;
        for(int j = 1; j + 1 < arr.size(); j++) {
            if(arr[j] == ',') {
                d.push_back(cur);
                cur = 0;
            } else {
                cur = 10 * cur + (arr[j] - '0');
            }
        }
        if(cur != 0) d.push_back(cur);

        for(int j = 0; j < func.size(); j++) {
            if(func[j] == 'R') {
                rev = 1 - rev;
                continue;
            }

            if(d.empty()) {
                error = true;
                break;
            }

            if(rev == false) {
                d.pop_front();
            } else {
                d.pop_back();
            }
        }

        if(error) {
            std::cout << "error\n";
            continue;
        }  
        if(rev) std::reverse(d.begin(), d.end());
        std::cout << '[';
        while(!d.empty()) {
            if(d.size() == 1) {
                std::cout << d.front() << ']';
            } else {
                std::cout << d.front() << ',';
            }
            d.pop_front();
        }
        std::cout << '\n';
    }
}