//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

void solve() {
	int n, m, p;
	array<int, 2> s, t;
	cin >> n >> m >> s[0] >> s[1] >> t[0] >> t[1] >> p;

	array<int, 2> d{1, 1};

	int k{100};
	while (k--) {
		if (n > 10 || m > 10) return ;
		for (int i{1}; i <= n; ++i) {
			for (int j{1}; j <= m; ++j) cout << (i == s[0] && j == s[1] ? 'x' : '-');
			cout << '\n';
		}
		cout << endl;

		if (s[0] == 1) d[0] = 1;
		if (s[0] == n) d[0] = -1;
		if (s[1] == 1) d[1] = 1;
		if (s[1] == m) d[1] = -1;
		s[0] += d[0], s[1] += d[1];
	}
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
