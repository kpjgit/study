#include <bits/stdc++.h>

int N;

bool escape = false;

bool chk(std::string& str) {
	std::string left, right;
	for (int cmp_len = 1; cmp_len <= str.length() / 2; cmp_len++) {
		for (int st = 0; st <= str.length() - cmp_len * 2; st++) {
			left = str.substr(st, cmp_len);
			right = str.substr(st + cmp_len, cmp_len);
			if (left == right) return false;
		}
	}

	return true;
}

void func(int cnt, std::string& str) {
	if (cnt == N) {
		if (chk(str)) escape = true;
		return;
	}

	for (int i = 1; i <= 3; i++) {
		str.push_back(i + '0');
		if (chk(str)) func(cnt + 1, str);
		if (escape) return;
		str.pop_back();
	}
}

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> N;
	std::string str;

	func(0, str);
	
	std::cout << str;
}
