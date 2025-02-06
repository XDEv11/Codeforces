//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

void solve() {
	string s{};
	cin >> s;
	int n{s.size()};

	vector<char> mn(n);
	mn[n - 1] = s[n - 1];
	for (int i{n - 2}; i >= 0; --i) mn[i] = min(mn[i + 1], s[i]);

	vector<char> ans{};
	array<int, 10> cnt{};
	for (int i{0}; i < n; ++i) {
		if (s[i] == mn[i]) {
			for (int k{0}; k <= s[i] - '0'; ++k) {
				while (cnt[k]) ans.push_back('0' + k), --cnt[k];
			}
			ans.push_back(s[i]);
		} else ++cnt[min(9, s[i] - '0' + 1)];
	}
	for (int k{0}; k <= 9; ++k) {
		while (cnt[k]) ans.push_back('0' + k), --cnt[k];
	}

	for (auto& x : ans) cout << x;
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
