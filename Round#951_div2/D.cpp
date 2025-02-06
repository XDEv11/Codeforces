//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		int n, m;
		cin >> n >> m;
		vector<char> v(n);
		for (auto& x : v) cin >> x;

		int k{n - 2};
		while (k >= 0 && v[k] == v[n - 1]) --k;
		if ((n - 1 - k) > m) return cout << "-1\n", []{}();

		int j{1};
		while (j < n && (v[j] == v[0]) == (j % (2 * m) < m)) ++j;
		if (j == n) return cout << n << '\n', []{}();

		if (v[0] == v[n - 1]) {
			int t{j + (n - 1 - k)};
			if (t < m) return cout << "-1\n", []{}();
			t %= (2 * m);
			if (t < m) t += 2 * m;
			j -= t - m;
		} else {
			int t{j + (n - 1 - k)};
			if (t < 2 * m) return cout << "-1\n", []{}();
			t %= (2 * m);
			j -= t;
		}

		for (int i{k}; i >= j; --i) {
			if ((v[i] != v[n - 1]) != ((k - i) % (2 * m) < m)) return cout << "-1\n", []{}();
		}
		cout << j << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
