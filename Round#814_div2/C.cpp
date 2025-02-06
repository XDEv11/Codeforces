//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n, q;
	cin >> n >> q;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	vector<int> w(n, 0);
	int mx, mxi;
	if (v[0] > v[1]) ++w[0], mx = v[0], mxi = 0;
	else ++w[1], mx = v[1], mxi = 1;
	for (int i{2}; i < n; ++i) {
		if (mx < v[i]) ++w[i], mx = v[i], mxi = i;
		else ++w[mxi];
	}

	while (q--) {
		int i, k;
		cin >> i >> k, --i;

		int c{max(0, k - max(0, i - 1))};
		if (v[i] == n) cout << c << '\n';
		else cout << min(c, w[i]) << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
