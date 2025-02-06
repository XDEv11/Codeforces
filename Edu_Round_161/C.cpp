//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	vector<int> a(n), b(n);
	for (int i{1}; i < n; ++i) {
		if (i - 1 == 0 || (v[i] - v[i - 1] <= v[i - 1] - v[i - 2])) a[i] = 1;
		else a[i] = v[i] - v[i - 1];
		a[i] += a[i - 1];
	}
	for (int i{n - 2}; i >= 0; --i) {
		if (i + 1 == n - 1 || (v[i + 1] - v[i] <= v[i + 2] - v[i + 1])) b[i] = 1;
		else b[i] = v[i + 1] - v[i];
		b[i] += b[i + 1];
	}

	int q;
	cin >> q;
	while (q--) {
		int i, j;
		cin >> i >> j, --i, --j;

		if (i < j) cout << (a[j] - a[i]) << '\n';
		else cout << (b[j] - b[i]) << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
