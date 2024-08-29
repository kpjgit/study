//1406
#include <bits/stdc++.h>

std::string s;
std::list<char> l;
int M;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> s >> M;
    for(int i = 0; i < s.size(); i++) l.push_back(s[i]);

    std::list<char>::iterator cursor = l.end();
    for(int i = 0; i < M; i++) {
        char input;
        std::cin >> input;
        if(input == 'L') {
            if(cursor != l.begin()) cursor--;
        } else if(input == 'D') {
            if(cursor != l.end()) cursor++;
        } else if(input == 'B') {
            if(cursor != l.begin()) {
                cursor--;
                cursor = l.erase(cursor);
            }
        } else {
            char word;
            std::cin >> word;
            l.insert(cursor, word);
        }
    }

    for(auto i = l.begin(); i != l.end(); i++) {
        std::cout << *i;
    }
}