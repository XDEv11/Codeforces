//#pragma GCC optimize ("O3")

#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <deque>
#include <algorithm>

using namespace std;

void solve() {
	string _s{};
	cin >> _s;
	int n{_s.size()};
	vector<char> s(n);
	for (int i{0}; i < n; ++i) s[i] = _s[i];

	int m;
	cin >> m;
	vector<char> l(m), r(m);
	for (auto& x : l) cin >> x;
	for (auto& x : r) cin >> x;

	array<deque<int>, 10> p{};
	for (int i{0}; i < n; ++i) p[s[i] - '0'].push_back(i);

	for (int i{0}; i < m; ++i) {
		int mx{-1};
		for (int k{l[i] - '0'}; k <= r[i] - '0'; ++k) {
			if (p[k].empty()) return cout << "YES\n", []{}();
			mx = max(mx, p[k].front());
		}
		for (int k{0}; k <= 9; ++k) {
			while (!p[k].empty() && p[k].front() <= mx) p[k].pop_front();
		}
	}
	cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
