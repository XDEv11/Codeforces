//#pragma GCC optimize ("O3")

#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	using ll = long long;
	const int mx_len{50};
	using map = array<array<int, 2>, mx_len>;
	int n;
	vector<ll> ans{}, a{};
	array<map, 2> dac(int r, int d = 0) {
		array<map, 2> mp;
		if (r == 0) {
			mp[0][0][0] = mp[1][0][0] = 0;
			return mp;
		} else if (r == 1) {
			mp[0][0] = mp[1][0] = {1, 1};
			mp[0][1][0] = mp[1][1][0] = 0;
			return mp;
		}

		int m{(1 + r) / 2};
		a[n - (m - 1)] += (1 << d), a[n - (r - m)] += (1 << d), a[n] -= (2 << d);
		if (r == 2) {
			mp[0][0] = {1, 2}, mp[0][1][0] = 0;
			mp[1][0] = {1, 1}, mp[1][1] = {2, 1}, mp[1][2][0] = 0;
			return mp;
		}

		if (r - m == m - 1) {
			mp = dac(m - 1, d + 1);
			for (int i{0}; mp[1][i][0]; ++i)
				for (int j{0}; mp[0][j][0]; ++j) {
					ans[n - (mp[1][i][0] + mp[0][j][0])] += ((ll(mp[1][i][1]) * mp[0][j][1]) << d);
				}
			for (int k{0}; k < 2; ++k) {
				int i{0};
				for (; mp[k][i][0]; ++i) mp[k][i][1] <<= 1;
				mp[k][i++] = {m, 1}, mp[k][i][0] = 0;
			}
		} else {
			array<map, 2> ml{dac(m - 1, d)}, mr{dac(r - m, d)};
			for (int i{0}; ml[1][i][0]; ++i)
				for (int j{0}; mr[0][j][0]; ++j) {
					ans[n - (ml[1][i][0] + mr[0][j][0])] += ((ll(ml[1][i][1]) * mr[0][j][1]) << d);
				}

			for (int k{0}; k < 2; ++k) {
				int i{0}, j{0}, p{0};
				while (ml[k][i][0] && mr[k][j][0]) {
					if (ml[k][i][0] == mr[k][j][0]) {
						mp[k][p++] = {ml[k][i][0], ml[k][i][1] + mr[k][j][1]}, ++i, ++j;
					} else if (ml[k][i][0] < mr[k][j][0]) mp[k][p++] = ml[k][i++];
					else mp[k][p++] = mr[k][j++];
				}
				while (ml[k][i][0]) mp[k][p++] = ml[k][i++];
				while (mr[k][j][0]) mp[k][p++] = mr[k][j++];
				if (k == 0) mp[0][p++] = {m, 1}, mp[0][p][0] = 0;
				else mp[1][p++] = {r - m + 1, 1}, mp[1][p][0] = 0;
			}
		}
		return mp;
	}
	bool solve() {
		if (!(cin >> n)) return false;

		ans.assign(n + 1, 0), a = ans, dac(n);
		for (int i{1}; i <= n; ++i) a[i] += a[i - 1];
		for (int i{0}; i <= n; ++i) ans[i] += a[i];

		for (int i{0}; i <= n; ++i) cout << ans[i] << ' ';
		cout << '\n';
		return true;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (solve()) ;
}
