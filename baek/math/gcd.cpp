//-1
#include <bits/stdc++.h>

gcd(int a, int b) {
    if(a == 0) return b;
    return gcd(b % a, a);
}

lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

int main(void) {

}