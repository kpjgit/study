#include <iostream>
#include <algorithm>
#include <string>

int N, K;
std::string str[100];

bool cmp(std::string& left, std::string& right) {
	return (left + right) > (right + left);
}

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> N >> K;
	for (int i = 0; i < N; i++) std::cin >> str[i];
	std::sort(str, str + N, cmp);

	std::string* target = &str[0];
	for (int i = 1; i < N; i++) {
		if (target->size() == str[i].size()) {
			if (str[i] > *target) target = &str[i];
		}
		else {
			if (str[i].size() > target->size()) target = &str[i];
		}
	}

	for (int i = N; i < K; i++) str[i] = *target;
	std::sort(str, str + K, cmp);

	for (int i = 0; i < K; i++) std::cout << str[i];
}