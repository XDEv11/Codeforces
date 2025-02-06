//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <set>
#include <numeric>
#include <algorithm>

using namespace std;

namespace {
	ostream& operator<<(ostream& os, const vector<int>& v) {
		for (auto& x : v) os << x << ' ';
		return os << '\n';
	}
	void solve() {
		int n, k;
		cin >> n >> k;
		if (k == 1) return cout << (n == 1 ? "YES\n1\n" : "NO\n"), []{}();

		vector<int> v(n); iota(v.begin(), v.end(), 1);
		if (k % 2 == 0 || n % 2) {
			int c{1};
			for (int i{2}; i <= n; ++i) {
				c *= i;
				if (c >= k + 3 * (k % 2)) break;
			}
			if (c >= k + 3 * (k % 2)) {
				cout << "YES\n";
				set<vector<int>> st{};
				if (k & 1) {
					k -= 3;
					cout << v, st.insert(v);

					int m{n / 2};
					vector<int> t{};
					for (int i{0}; i < m; ++i) {
						t.push_back(m + 1 - i);
						t.push_back(m * 2 + 1 - i);
					}
					t.push_back(1);
					cout << t, st.insert(t);

					rotate(t.begin(), t.begin() + 1, t.end());
					cout << t, st.insert(t);
				}
				for (int i{0}; i < k / 2; next_permutation(v.begin(), v.end())) {
					auto t{v};
					for (auto& x : t) x = n + 1 - x;
					if (st.count(v) || st.count(t)) continue;

					cout << v << t, ++i;
				}
			} else cout << "NO\n";
		} else cout << "NO\n";
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
