#include <iostream>
#include <algorithm>
#include <string>

int N;
std::string arr[1000];

bool cmp(std::string& left, std::string& right) {
	if (left == right) return false;
	
	std::string lr = left + right;
	std::string rl = right + left;
	
	return lr > rl;
}

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> N;
	for (int i = 0; i < N; i++) std::cin >> arr[i];
	std::sort(arr, arr + N, cmp);

	if (arr[0][0] == '0') {
		std::cout << '0';
		return 0;
	}
	for (int i = 0; i < N; i++) {
		std::cout << arr[i];
	}
}