//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <algorithm>

using namespace std;

namespace {
	using ll = long long;
	template<typename T>
	using matrix = vector<vector<T>>;
	template<typename T>
	using tensor = vector<matrix<T>>;

	void solve() {
		int n;
		cin >> n;
		matrix<ll> m(n, vector<ll>(n));
		for (auto& v : m)
			for (auto& x : v) cin >> x;

		vector<int> t{};
		for (int i{0}; i < n; ++i) {
			int c{};
			for (int j{n - 1}; j >= 0; --j) {
				if (m[i][j] != 1) break;
				++c;
			}
			t.push_back(c);
		}
		sort(t.begin(), t.end());

		int ans{};
		for (auto& x : t) {
			if (x < ans) continue;
			++ans;
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
