//-1
#include <bits/stdc++.h>

void set_example() {
    std::set<int> s;
    s.insert(-10); s.insert(100); s.insert(15);
    s.insert(-10);
    std::cout << s.erase(100) << '\n';
    std::cout << s.erase(20) << '\n';
    if(s.find(15) != s.end()) std::cout << "15 in s\n";
    else std::cout << "15 no in s\n";
    std::cout << s.size() << '\n';
    std::cout << s.count(50) << '\n';
    for(auto e : s) std::cout << e << ' ';
    std::cout << '\n';
    s.insert(-40); 
    std::set<int>::iterator iter = s.begin();
    iter++;
    auto iter2 = prev(iter);
    iter2 = next(iter);
    std::advance(iter2, -2);
    auto iter3 = s.lower_bound(-20);
    auto iter4 = s.find(15);
    std::cout << *iter << '\n';
    std::cout << *iter2 << '\n';
    std::cout << *iter3 << '\n';
    std::cout << *iter4 << '\n';
    std::cout << '\n';
}

void multiset_example() {
    std::multiset<int> ms;
    ms.insert(-10); ms.insert(100); ms.insert(15);
    ms.insert(-10); ms.insert(15);
    std::cout << ms.size() <<'\n';
    for(auto e : ms) std::cout << e << ' ';
    std::cout << '\n';
    std::cout << ms.erase(15) << '\n';
    ms.erase(ms.find(-10));
    ms.insert(100);
    std::cout << ms.count(100) << '\n';
    auto iter = ms.begin();
    auto iter2 = ms.upper_bound(100);
    auto iter3 = ms.find(100);
    std::cout << *iter << '\n';
    std::cout << (iter2 == ms.end()) << '\n';
    std::cout << *iter3 << '\n';
    std::cout << '\n';
}

void map_example() {
    std::map<std::string, int> m;
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
    auto iter = m.find("gogo");
    std::cout << iter->first << ' ' << iter->second << '\n';
    std::cout << '\n';
}

int main(void) {
    set_example();
    multiset_example();
    map_example();
}