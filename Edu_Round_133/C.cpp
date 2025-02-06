//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

// sparse table
template<typename value_t, class merge_t>
class ST {
	int n;
	vector<int> log2;
	vector<vector<value_t>> t;
	merge_t merge; // associative & idempotent function for ST
public:
	explicit ST(const vector<value_t>& v, const merge_t& _merge = merge_t{})
		: n{v.size()}, log2(n + 1), merge{_merge} {
		log2[1] = 0;
		for (int i{2}; i <= n; ++i) log2[i] = log2[i / 2] + 1;

		t.assign(n, vector<value_t>(log2[n] + 1));
		for (int i{n - 1}; i >= 0; --i) {
			t[i][0] = v[i];
			for (int j{1}; i + (1 << j) <= n; ++j)
				t[i][j] = merge(t[i][j - 1], t[i + (1 << (j - 1))][j - 1]);
		}
	}
	value_t query(int l, int r) { // [l:r)
		int j{log2[r - l]};
		return merge(t[l][j], t[r - (1 << j)][j]);
	}
};

template<typename T>
struct MAX {
	const T& operator()(const T& x, const T& y) { return max(x, y); }
};

void solve() {
	int m;
	cin >> m;
	vector<vector<int>> g(2, vector<int>(m));
	for (auto& v : g)
		for (auto& x : v) cin >> x, ++x;
	g[0][0] = 0;

	auto g1{g};
	for (int j{0}; j < m; ++j) g1[0][j] += (m - 1 - j) + m, g1[1][j] += j;
	vector<int> v1(m);
	for (int j{0}; j < m; ++j) v1[j] = max(g1[0][j], g1[1][j]);
	ST<int, MAX<int>> st1{v1};

	auto g2{g};
	for (int j{0}; j < m; ++j) g2[1][j] += (m - 1 - j) + m, g2[0][j] += j;
	vector<int> v2(m);
	for (int j{0}; j < m; ++j) v2[j] = max(g2[0][j], g2[1][j]);
	ST<int, MAX<int>> st2{v2};

	int mx{0}, ans{numeric_limits<int>::max()};
	for (int j{0}; j < m; ++j) {
		if (j % 2 == 0) {
			ans = min(ans, max(mx, st1.query(j, m) - j));

			mx = max(mx, g[0][j] + 2 * m - (2 * j + 1));
			mx = max(mx, g[1][j] + 2 * m - (2 * j + 2));
		} else {
			ans = min(ans, max(mx, st2.query(j, m) - j));

			mx = max(mx, g[1][j] + 2 * m - (2 * j + 1));
			mx = max(mx, g[0][j] + 2 * m - (2 * j + 2));
		}
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
