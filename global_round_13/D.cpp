#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int q;
	cin >> q;
	while (q--) {
		int u, v;
		cin >> u >> v;

		bool ans{true};
		int cnt{0};
		for (int i{0}; i <= 30; ++i) {
			if (u & (1 << i)) ++cnt;
			if (v & (1 << i)) --cnt;
			if (cnt < 0) ans = false;
		}

		if (u <= v && ans) cout << "YES\n";
		else cout << "NO\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	// cin >> t;
	while (t--) solve();

	return 0;
}
