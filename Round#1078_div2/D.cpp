//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

namespace {
	template<typename T>
	using matrix = vector<vector<T>>;
	void solve() {
		int n, m;
		cin >> n >> m;
		matrix<int> g(n + 1, vector<int>(m + 1));
		long long t{};
		for (int i{0}; i < n; ++i)
			for (int j{0}; j < m; ++j) cin >> g[i][j], t += g[i][j];
		cout << ((t / 2) * ((t + 1) / 2)) << '\n';

		vector<char> ans{};
		t /= 2;
		if (!t) {
			for (int j{0}; j < m; ++j) ans.push_back('R');
		}
		for (int i{0}; i < n; ++i) {
			if (t) {
				int j;
				for (j = m - 1; j >= 0 && t; --j) t -= g[i][j];
				if (!t) {
					for (int k{0}; k <= j; ++k) ans.push_back('R');
				}
				ans.push_back('D');
				if (!t) {
					for (int k{j + 1}; k < m; ++k) ans.push_back('R');
				}
			} else ans.push_back('D');
		}

		for (auto& x : ans) cout << x;
		cout << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
