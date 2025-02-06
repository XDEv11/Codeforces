//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
using matrix = vector<vector<T>>;
template<typename T>
using tensor = vector<matrix<T>>;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	for (auto& x : v) cin >> x, --x;

	auto minimize{[](int& a, int b) {
		return a = min(a, b);
	}};

	tensor<int> dp1(n, matrix<int>(n, vector<int>(m, n + 1))), dp2{dp1};
	for (int l{0}; l < n; ++l)
		for (int k{0}; k < m; ++k) {
			dp1[l][l][k] = (v[l] == k ? 0 : 1);
			dp2[l][l][k] = (v[l] == k ? 1 : 0);
		}
	for (int len{2}; len <= n; ++len)
		for (int l{0}, r{len - 1}; r < n; ++l, ++r) {
			for (int k{0}; k < m; ++k) {
				if (v[r] == k) continue;
				minimize(dp1[l][r][k], dp2[l][r - 1][k] + 1);
				for (int i{l + 1}; i <= r; ++i) minimize(dp1[l][r][k], dp1[l][i - 1][k] + dp1[i][r][k]);
			}
			{
				int k{v[r]};
				for (int nk{0}; nk < m; ++nk) {
					if (nk == k) continue;
					minimize(dp2[l][r][k], dp1[l][r][nk]);
				}
				for (int i{l + 1}; i <= r; ++i) minimize(dp2[l][r][k], dp2[l][i - 1][k] + dp2[i][r][k]);

				minimize(dp1[l][r][k], dp2[l][r][k] + 1);
				for (int i{l + 1}; i <= r; ++i) minimize(dp1[l][r][k], dp1[l][i - 1][k] + dp1[i][r][k]);
			}
			for (int k{0}; k < m; ++k) {
				if (v[r] == k) continue;
				for (int nk{0}; nk < m; ++nk) {
					if (nk == k) continue;
					minimize(dp2[l][r][k], dp1[l][r][nk]);
				}
				for (int i{l + 1}; i <= r; ++i) minimize(dp2[l][r][k], dp2[l][i - 1][k] + dp2[i][r][k]);
			}
		}

	cout << *min_element(dp1[0][n - 1].begin(), dp1[0][n - 1].end()) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
