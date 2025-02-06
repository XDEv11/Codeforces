//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (auto& x : v) cin >> x, --x;

	vector<vector<int>> t(k);
	for (int i{0}; i < n; ++i) t[v[i]].push_back(i);

	int l{0}, r{n - 1};
	vector<bool> ck(n, false);
	for (int i{0}; i < k; ++i) {
		cout << (t[i].empty() ? 0 : (2 * (r - l + 1))) << ' ';
		for (auto& idx : t[i]) ck[idx] = true;
		while (l < n && ck[l]) ++l;
		while (r >= 0 && ck[r]) --r;
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
