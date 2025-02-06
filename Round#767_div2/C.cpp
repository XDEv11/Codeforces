//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	vector<int> cnt(n + 2, 0);
	for (auto& x : v) ++cnt[x];

	vector<int> b{};
	int i{0};
	while (i < n) {
		int m{0};
		while (cnt[m]) ++m;
		int c{0};
		vector<bool> ck(m, false);
		int j{i};
		for ( ; ; ++j) {
			if (v[j] < m && !ck[v[j]]) ck[v[j]] = true, ++c;
			--cnt[v[j]];
			if (c == m) break;
		}
		i = j + 1;
		b.push_back(m);
	}

	cout << b.size() << '\n';
	for (auto& x : b) cout << x << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
