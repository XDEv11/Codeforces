//#pragma GCC optimize ("O3")

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int k;
	string s{};
	cin >> k >> s;
	int n{s.size()};

	vector<int> pa(n);
	int p{-1};
	for (int i{0}; i < n; ++i) {
		if (s[i] == '(') pa[i] = p, p = i;
		else p = pa[p];
	}
	vector<int> sz(n, 1);
	for (int i{n - 1}; i >= 0; --i) {
		if (s[i] == ')') continue;
		if (pa[i] == -1) continue;
		sz[pa[i]] += sz[i];
	}

	while (k--) {
		int mx{0}, idx;
		for (int i{0}; i < n; ++i) {
			if (s[i] == ')') continue;
			if (pa[i] != -1) continue;
			if (sz[i] > mx) mx = sz[i], idx = i;
		}
		for (int i{0}; i < n; ++i) {
			if (s[i] == ')') continue;
			if (pa[i] != idx) continue;
			pa[i] = -1;
		}
		sz[idx] = 1;
	}

	long long ans{0};
	for (int i{0}; i < n; ++i) {
		if (s[i] == ')') continue;
		ans += sz[i] - 1;
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
