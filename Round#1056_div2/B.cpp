//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>

using namespace std;

namespace {
	void solve() {
		int n, m;
		cin >> n >> m;

		m = n * n - m;
		if (m == 1) return cout << "NO\n", []{}();

		vector<vector<char>> a(n, vector<char>(n, 'R'));
		if (m) a[0][1] = 'L', m -= 2;

		int i{0}, j{1};
		while (m--) {
			++j;
			if (j == n) ++i, j = 0;
			a[i][j] = i ? 'U' : 'L';
		}

		cout << "YES\n";
		for (auto& v : a) {
			for (auto& x : v) cout << x;
			cout << '\n';
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
