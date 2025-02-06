//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

template<typename T>
using matrix = vector<vector<T>>;
template<typename T>
using tensor = matrix<vector<T>>;

void solve() {
	using pi = array<int, 2>;

	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (auto& x : a) cin >> x;
	vector<pi> s(m);
	for (int ii{0}; ii < m; ++ii) cin >> s[ii][0], s[ii][1] = ii;

	matrix<int> ans(m);
	sort(s.begin(), s.end());
	vector<bool> usd(n);
	for (int ii{0}; ii < m - 1; ++ii) {
		tensor<int> dp(n + 1, matrix<int>(n + 1, vector<int>(s[ii][0], -1)));
		dp[0][0][0] = 0;
		for (int i{0}; i < n; ++i)
			for (int j{0}; j <= i; ++j)
				for (int k{0}; k < s[ii][0]; ++k) {
					if (dp[i][j][k] == -1) continue;
					dp[i + 1][j][k] = 0;
					if (!usd[i]) dp[i + 1][j + 1][(k + a[i]) % s[ii][0]] = 1;
				}
		int j{s[ii][0]}, k{0};
		for (int i{n - 1}; i >= 0; --i) {
			if (dp[i + 1][j][k] == 0) continue;
			ans[s[ii][1]].push_back(a[i]), usd[i] = true;
			j -= 1, k = ((k - a[i]) % s[ii][0] + s[ii][0]) % s[ii][0];
		}
	}
	int k{0};
	for (int i{0}; i < n; ++i) {
		if (usd[i]) continue;
		ans[s[m - 1][1]].push_back(a[i]);
		k = (k - a[i]) % s[m - 1][0];
	}
	k += s[m - 1][0];
	ans[s[m - 1][1]].push_back(k);

	cout << k << '\n';
	for (int ii{0}; ii < m; ++ii) {
		for (auto& x : ans[ii]) cout << x << ' ';
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();
}
