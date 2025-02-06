//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	vector<pair<int, int>> tmp(n);
	for (int i{0}; i < n; ++i) tmp[i] = {v[i], i};
	sort(tmp.rbegin(), tmp.rend());

	vector<int> ans(n);
	for (int i{0}; i < n; ++i) ans[tmp[i].se] = i + 1;

	for (auto& x : ans) cout << x << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
