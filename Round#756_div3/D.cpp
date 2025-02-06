#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> b(n), p(n);
	for (auto& x : b) cin >> x, --x;
	for (auto& x : p) cin >> x, --x;

	if (b[p[0]] != p[0]) return cout << "-1\n"s, []{}();

	vector<bool> vis(n, false);
	vector<int> w(n), d(n);
	vis[p[0]] = true;
	int mn{0};
	for (int i{1}; i < n; ++i) {
		const auto& x{p[i]};
		if (!vis[b[x]]) return cout << "-1\n"s, []{}();
		d[x] = ++mn;
		w[x] = d[x] - d[b[x]];
		vis[x] = true;
	}

	for (auto& x : w) cout << x << ' ';
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
