//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n;
	cin >> n;

	vector<vector<int>> m(n, vector<int>(n));
	int x{1}, y{n * n}, z{0};
	for (int i{0}; i < n; i += 2) {
		for (int j{0}; j < n; ++j) {
			if (!z) m[i][j] = x++, z = 1;
			else m[i][j] = y--, z = 0;
		}
		if (i + 1 < n) {
			for (int j{n - 1}; j >= 0; --j) {
				if (!z) m[i + 1][j] = x++, z = 1;
				else m[i + 1][j] = y--, z = 0;
			}
		}
	}

	for (auto& v : m) {
		for (auto& x : v) cout << x << ' ';
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
