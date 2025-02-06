//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool solve() {
	int n;
	if (!(cin >> n)) return false;
	vector<int> v(n);
	for (auto& x : v) cin >> x, --x;

	vector<int> cnt(n);
	for (int i{0}; i < n; ++i) ++cnt[v[i]];

	vector<int> s(n);
	queue<int> qu{};
	for (int i{0}; i < n; ++i) {
		if (!cnt[i]) qu.push(i);
	}
	while (!qu.empty()) {
		auto i{qu.front()}; qu.pop(); int j{v[i]};
		if (s[i] == 2) return cout << "-1\n", true;
		s[i] = 1; // take
		if (s[j] == 1) return cout << "-1\n", true;
		else if (s[j] == 0) {
			s[j] = 2; // not take
			if (!--cnt[v[j]]) qu.push(v[j]);
		}
	}

	for (int i{0}; i < n; ++i) {
		if (s[i]) continue;
		int j{i};
		do {
			s[j] = 1, j = v[j];
			if (s[j]) return cout << "-1\n", true;
			s[j] = 2, j = v[j];
		} while (j != i);
	}

	vector<int> ans{};
	for (int i{0}; i < n; ++i) {
		if (s[i] == 1) ans.push_back(v[i]);
	}

	cout << ans.size() << '\n';
	for (auto& x : ans) cout << (x + 1) << ' ';
	cout << '\n';
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (solve()) ;
}
