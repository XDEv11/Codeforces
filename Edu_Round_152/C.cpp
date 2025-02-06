//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <algorithm>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<char> v(n);
	for (auto& x : v) cin >> x;
	vector<pair<int, int>> p(m);
	for (auto& [l, r] : p) cin >> l >> r, --l, --r;

	vector<int> p0(n), n1(n);
	for (int i{0}, j{-1}; i < n; ++i) {
		if (v[i] == '0') j = i;
		p0[i] = j;
	}
	for (int i{n - 1}, j{n}; i >= 0; --i) {
		if (v[i] == '1') j = i;
		n1[i] = j;
	}

	for (auto& [l, r] : p) {
		l = n1[l], r = p0[r];
		if (r < l) l = n, r = -1;
	}
	sort(p.begin(), p.end());
	p.erase(unique(p.begin(), p.end()), p.end());

	cout << p.size() << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
