//1431
#include <bits/stdc++.h>

int n;
std::vector<std::string> guitar;

bool cmp(const std::string& a, const std::string& b) {
    if(a.size() < b.size()) return true;
    else if(a.size() > b.size()) return false;
    int lena = 0;
    int lenb = 0;

    for(int i = 0; i < a.size(); i++) {
        if(a[i] >= '0' && a[i] <= '9') lena = lena + a[i] - '0';
        if(b[i] >= '0' && b[i] <= '9') lenb = lenb + b[i] - '0';
    }
    if(lena < lenb) return true;
    else if(lena > lenb) return false;

    for(int i = 0; i < a.size(); i++) {
        if(a[i] < b[i]) return true;
        else if(a[i] > b[i]) return false;
    }

    return false;
}

int main(void) {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;
    for(int i = 0; i < n; i++) 
    {   
        std::string s;
        std::cin >> s;
        guitar.push_back(s);
    }

    std::sort(guitar.begin(), guitar.end(), cmp);
    for(int i = 0; i < n; i++) std::cout << guitar[i] << '\n';
}