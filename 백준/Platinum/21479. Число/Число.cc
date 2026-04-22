#include <iostream>
#include <string>
#include <utility>
#include <algorithm>

std::string arr[100];

bool cmp(std::string& left, std::string& right) {
	auto lr = left + right;
	auto rl = right + left;

	return lr > rl;
}

int main(void) {
	std::cin.tie(nullptr);
	std::ios::sync_with_stdio(false);

	int num = 0;
	while (std::cin >> arr[num]) {
		num++;
	}

	std::sort(arr, arr + num, cmp);

	int st = 0;
	bool flag = false;
	if (arr[st] == "0") {
		std::cout << 0;
		return 0;
	}
	while (arr[st][0] == '0' && flag == false) {
		for (char c : arr[st]) {
			if (c != '0') flag = true;
			if (flag) std::cout << c;
		}
		st++;
	}

	for (int i = st; i < num; i++) std::cout << arr[i];
}