//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>

using namespace std;

namespace {
	void solve() {
		int n;
		cin >> n;
		vector<vector<char>> g(2, vector<char>(n));
		for (auto& v : g)
			for (auto& x : v) cin >> x;

		int ans{};
		for (int i{0}; i < 2; ++i)
			for (int j{1}; j + 1 < n; ++j) {
				if (
					g[i][j - 1] == 'x' && g[i ^ 1][j - 1] == '.'
					&& g[i][j] == '.'
					&& g[i][j + 1] == 'x' && g[i ^ 1][j + 1] == '.'
				) ++ans;
			}

		cout << ans << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
