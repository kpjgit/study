//-1
#include <bits/stdc++.h>

void unordered_set_example() {
    std::unordered_set<int> s ;
    s.insert(-10); s.insert(100); s.insert(15);
    s.insert(-10); //unique
    std::cout << s.erase(100) << '\n';
    std::cout << s.erase(20) << '\n';
    if(s.find(15) != s.end()) std::cout << "15 in s\n";
    else std::cout << "15 is not in s\n";
    std::cout << s.size() << '\n';
    std::cout << s.count(50) << '\n';
    for(auto e : s) std::cout << e << ' ';
    std::cout << "\n\n";
}

void unordered_multiset_example() {
    std::unordered_multiset<int> ms;
    ms.insert(-10); ms.insert(100); ms.insert(15);
    ms.insert(-10); ms.insert(15);
    std::cout << ms.size() << '\n';
    for(auto e : ms) std::cout << e << ' ';
    std::cout << '\n';
    std::cout << ms.erase(15) << '\n';
    ms.erase(ms.find(-10));
    ms.insert(100);
    std::cout << ms.count(100) << "\n\n";
}

void unordered_map_example() {
    std::unordered_map<std::string, int> m;
    m["hi"] = 123;
    m["bkd"] = 1000;
    m["gogo"] = 165;
    std::cout << m.size() << '\n';
    m["hi"] = -7;
    if(m.find("hi") != m.end()) std::cout << "hi in m\n";
    else std::cout << "hi not in m\n";
    m.erase("bkd");
    for(auto e : m)
        std::cout << e.first << ' ' << e.second << '\n';
    std::cout << '\n';
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    unordered_set_example();
    unordered_multiset_example();
    unordered_map_example();
}