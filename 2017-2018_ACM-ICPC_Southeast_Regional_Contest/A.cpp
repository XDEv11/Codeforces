//#pragma GCC optimize ("O3")

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
using matrix = vector<vector<T>>;
template<typename T>
using tensor = vector<matrix<T>>;

bool solve() {
	int m, c;
	if (!(cin >> m >> c)) return false;
	string s{};
	cin >> s;
	int n{s.size()};
	if (c * m + c - 1 > n) return cout << "-1\n", true;

	tensor<int> dp0(n + 1, matrix<int>(c + 1, vector<int>(m + 1, n + 1))), dp1{dp0};
	auto min_assign{[](int& x, const int& y) { x = min(x, y); }};
	dp0[0][0][0] = 0;
	for (int i{0}; i < n; ++i) {
		for (int j{0}; j < c; ++j) {
			if (s[i] == 'D') {
				for (int k{0}; k < m; ++k) {
					min_assign(dp0[i + 1][j][k + 1], min(dp0[i][j][k], dp1[i][j][k]));
					min_assign(dp1[i + 1][j][0], min(dp0[i][j][k] + 1, dp1[i][j][k]));
				}
				min_assign(dp0[i + 1][j][m], min(dp0[i][j][m], dp1[i][j][m]));
				min_assign(dp1[i + 1][j + 1][0], min(dp0[i][j][m] + 1, dp1[i][j][m]));
			} else {
				for (int k{0}; k < m; ++k) {
					min_assign(dp0[i + 1][j][0], min(dp0[i][j][k], dp1[i][j][k]));
					min_assign(dp1[i + 1][j][k + 1], min(dp0[i][j][k] + 1, dp1[i][j][k]));
				}
				min_assign(dp0[i + 1][j + 1][0], min(dp0[i][j][m], dp1[i][j][m]));
				min_assign(dp1[i + 1][j][m], min(dp0[i][j][m] + 1, dp1[i][j][m]));
			}
		}
		min_assign(dp0[i + 1][c][0], min(dp0[i][c][0], dp1[i][c][0]));
		min_assign(dp1[i + 1][c][0], min(dp0[i][c][0] + 1, dp1[i][c][0]));
	}

	cout << min({dp0[n][c - 1][m], dp1[n][c - 1][m], dp0[n][c][0], dp1[n][c][0]}) << '\n';
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (solve()) ;
}
