#include <iostream>
#include <string>
#include <unordered_map>
#include <iomanip>

std::unordered_map<std::string, float> table;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    table["A+"] = 4.5;
    table["A0"] = 4.0;
    table["B+"] = 3.5;
    table["B0"] = 3.0;
    table["C+"] = 2.5;
    table["C0"] = 2.0;
    table["D+"] = 1.5;
    table["D0"] = 1.0;
    table["F"] = 0.0;
    
    std::string str;
    float fp;
    float sum = 0;
    float total = 0;
    for(int i = 0; i < 20; i++) {
        std::cin >> str;
        std::cin >> fp;
        std::cin >> str;
        
        if(str == "P") continue;
        
        sum += fp;
        total += fp * table[str];
    }
    
    std::cout << std::fixed << std::setprecision(6) << std::showpoint;
    std::cout << total / sum;
}