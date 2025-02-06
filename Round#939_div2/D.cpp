//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <algorithm>

using namespace std;

static vector<vector<pair<int, int>>> tb{[] {
	const int mv{18};
	vector<vector<pair<int, int>>> t(mv + 1);
	for (int i{1}; i <= mv; ++i) {
		for (int j{i - 1}; j >= 0; --j) {
			for (auto& [x, y] : t[j]) t[i].emplace_back(x, y);
			t[i].emplace_back(0, j);
		}
	}
	return t;
}()};

bool solve() {
	auto sq{[](int x) { return x * x; }};

	int n;
	if (!(cin >> n)) return false;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	vector<int> ps(n + 1);
	for (int i{0}; i < n; ++i) ps[i + 1] = ps[i] + v[i];

	vector<int> dp(n + 1);
	for (int i{0}; i < n; ++i)
		for (int j{0}; j <= i; ++j) {
			dp[i + 1] = max(dp[i + 1], dp[j] + max(sq(i + 1 - j), ps[i + 1] - ps[j]));
		}

	vector<pair<int, int>> ans{};
	for (int k{n - 1}; k >= 0; ) {
		int j;
		for (j = 0; j <= k; ++j)
			if (dp[k + 1] == dp[j] + max(sq(k + 1 - j), ps[k + 1] - ps[j])) {
				cerr << "(" << j << ", " << k << ")" << endl;
				if (dp[k + 1] == dp[j] + ps[k + 1] - ps[j]) ;
				else {
					for (int i{0}; i < k + 1 - j; ++i) {
						if (v[j + i] == i) ans.emplace_back(j + i, j + i);
					}
					for (auto& [x, y] : tb[k + 1 - j]) ans.emplace_back(j + x, j + y);
					ans.emplace_back(j, k);
				}
				break;
			}
		k = j - 1;
	}

	cout << dp[n] << ' ' << ans.size() << '\n';
	for (auto& [x, y] : ans) cout << x + 1 << ' ' << y + 1 << '\n';
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (solve()) ;
}
