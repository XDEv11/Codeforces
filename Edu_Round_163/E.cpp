//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> table{[] {
	vector<int> t(81);
	for (int s{1}; s <= 40; ++s) {
		vector<int> v(s);
		int i{0}, j{s - 1}, x{s / 2}, y{x + 1};
		while (i <= j) v[i++] = x--, v[j--] = y++;
		int mx{0};
		for (i = 0; i < s; ++i)
			for (j = i + 1; j < s; ++j) {
				mx = max(mx, j - i + abs(v[j] - v[i]));
			}
		for (int k{mx}; k <= 80; ++k) t[k] = s;
	}
	return t;
}()};

void solve() {
	int n, k;
	cin >> n >> k;

	int m{min(n, table[k])};

	int ans0{0};
	vector<int> ans1(n), ans2(n);
	for (int ii{0}; ii < n; ii += m, ++ans0) {
		if (ii + m > n) m = n - ii;
		vector<int> v(m);
		int i{0}, j{m - 1}, x{m / 2}, y{x + 1};
		while (i <= j) v[i++] = x--, v[j--] = y++;
		for (int jj{ii}; jj < ii + m; ++jj) ans1[jj] = ii + v[jj - ii], ans2[jj] = ans0 + 1;
	}

	for (auto& x : ans1) cout << x << ' ';
	cout << '\n';
	cout << ans0 << '\n';
	for (auto& x : ans2) cout << x << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
