//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	using ll = long long;

	int n;
	ll x, y;
	cin >> n >> x >> y;
	vector<char> a(n), b(n);
	for (auto& e : a) cin >> e;
	for (auto& e : b) cin >> e;

	vector<int> d{};
	for (int i{0}; i < n; ++i) {
		if (a[i] != b[i]) d.push_back(i);
	}
	if (d.size() & 1) return cout << "-1\n", []{}();

	if (d.size() == 0) cout << "0\n";
	else if (d.size() == 2) cout << min((d[1] - d[0]) * x, d[0] + 1 == d[1] ? 2 * y : y) << '\n';
	else if (x >= y) cout << (d.size() / 2 * y) << '\n';
	else {
		int m{d.size()};
		vector<ll> dpx(m + 1), dpy(m + 1);
		dpx[1] = dpy[1] = y;
		for (int i{2}; i <= m; ++i) {
			dpx[i] = (d[i - 1] - d[i - 2]) * 2 * x + min(dpx[i - 2], dpy[i - 2]);
			dpy[i] = y + min(dpx[i - 1], dpy[i - 1]);
		}
		cout << (min(dpx[m], dpy[m]) / 2) << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
