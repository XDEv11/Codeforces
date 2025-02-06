#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void solve() {
	int n, m, q;
	cin >> n >> m >> q;
	vector<vector<bool>> mtx(n, vector<bool>(m, true));

	long long ans{0};
	for (int i{0}; i < n; ++i) {
		int c{min(m, (n - i)) * 2 - 1};
		ans += static_cast<long long>(c) * (c - 1) / 2 + c;
		if (c != 1) ans += static_cast<long long>(c) * (c - 1) / 2 + c;
	}
	for (int j{1}; j < m; ++j) {
		int c{min(n, (m - j)) * 2 - 1};
		ans += static_cast<long long>(c) * (c - 1) / 2 + c;
		if (c != 1 && j != 1) ans += static_cast<long long>(c) * (c - 1) / 2 + c;
	}

	while (q--) {
		int x, y;
		cin >> x >> y, --x, --y;
		mtx[x][y] = !mtx[x][y];

		{
			int c1{1}, c2{1}, a{x}, b{y};
			bool f{true};
			while (a >= 0 && b >= 0 && mtx[a][b]) ++c1, f ? --a : --b, f = !f;
			a = x, b = y, f = false;
			while (a < n && b < m && mtx[a][b]) ++c2, f ? ++a : ++b, f = !f;
			if (mtx[x][y]) ans += static_cast<long long>(c1) * c2;
			else ans -= static_cast<long long>(c1) * c2;
		}
		{
			int c1{1}, c2{1}, a{x}, b{y};
			bool f{false};
			while (a >= 0 && b >= 0 && mtx[a][b]) ++c1, f ? --a : --b, f = !f;
			a = x, b = y, f = true;
			while (a < n && b < m && mtx[a][b]) ++c2, f ? ++a : ++b, f = !f;
			if (mtx[x][y]) ans += static_cast<long long>(c1) * c2;
			else ans -= static_cast<long long>(c1) * c2;
		}

		cout << ans << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
