//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> g(n, vector<int>(n));
	for (auto& v : g)
		for (auto& x : v) {
			char c;
			cin >> c;
			x = (c == '1');
		}

	int ans{};
	vector<int> c(n), l(n), r(n);
	for (auto& v : g) {
		for (int j{0}; j < n; ++j) c[j] ^= l[j] ^ r[j];
		for (int j{0}; j < n; ++j) v[j] ^= c[j];

		for (int j{0}; j <= n - 2; ++j) l[j] = l[j + 1];
		l[n - 1] = 0;
		for (int j{n - 1}; j >= 1; --j) r[j] = r[j - 1];
		r[0] = 0;
		for (int j{0}; j < n; ++j) {
			if (!v[j]) continue;
			++ans;
			c[j] ^= 1;
			if (j - 1 >= 0) l[j - 1] ^= 1;
			if (j + 1 < n) r[j + 1] ^= 1;
		}
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
