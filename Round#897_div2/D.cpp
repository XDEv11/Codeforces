//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <algorithm>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (auto& x : v) cin >> x, --x;
	if (k == 1) {
		for (int i{0}; i < n; ++i) {
			if (v[i] != i) return cout << "NO\n", []{}();
		}
		return cout << "YES\n", []{}();
	}

	vector<bool> vis(n);
	for (int i{0}; i < n; ++i) {
		if (vis[i]) continue;
		int t{i}, h{i}, mu{0}, lam{0};
		do {
			t = v[t], h = v[v[h]];
			if (vis[t] || vis[h]) goto CONT;
		} while (t != h);
		t = i;
		while (t != h) t = v[t], h = v[h], ++mu;
		do { h = v[h], ++lam; } while (t != h);
		if (lam != k) return cout << "NO\n", []{}();
		t = i;
		for (int k{0}; k < mu + lam; ++k, t = v[t]) vis[t] = true;
CONT:
		;
	}
	cout << "YES\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
