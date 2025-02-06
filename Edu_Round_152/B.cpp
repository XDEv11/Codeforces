//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	vector<pair<int, int>> t(n);
	for (int i{0}; i < n; ++i) {
		int x{v[i] % k};
		if (!x) x = k;
		t[i] = {-x, i};
	}
	sort(t.begin(), t.end());

	for (auto& [x, y] : t) cout << y + 1 << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
