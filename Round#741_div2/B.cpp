#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

void solve() {
	int k;
	string n;
	cin >> k >> n;

	set<char> s{'1', '4', '6', '8', '9'};
	for (auto& d : n)
		if (s.count(d)) return cout << "1\n"s << d << '\n', []{}();

	vector<int> cnt(10, 0);
	for (auto& d : n) {
		++cnt[d - '0'];
		if (cnt[d - '0'] == 2) return cout << "2\n"s << d << d << '\n', []{}();
	}

	auto isNotPrime = [](int x) {
		for (int i{2}; i * i <= x; ++i)
			if (x % i == 0) return true;
		return false;
	};
	for (int i{0}; i < k; ++i)
		for (int j{i + 1}; j < k; ++j) {
			int x{(n[i] - '0') * 10 + (n[j] - '0')};
			if (isNotPrime(x)) return cout << "2\n"s << x << '\n', []{}();
		}
	for (int i{0}; i < k; ++i)
		for (int j{i + 1}; j < k; ++j)
			for (int l{j + 1}; l < k; ++l) {
				int x{(n[i] - '0') * 100 + (n[j] - '0') * 10 + (n[l] - '0')};
				if (isNotPrime(x)) return cout << "3\n"s << x << '\n', []{}();
			}
	cout << "4\n"s << n << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
