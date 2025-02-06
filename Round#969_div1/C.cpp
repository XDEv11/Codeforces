//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

namespace {
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
	void solve() {
		int n;
		cin >> n;
		vector<int> v(n);
		for (auto& x : v) cin >> x;
		if (n == 1) return cout << "1\n", []{}();

		vector<int> nx(n);
		nx[n - 1] = n - 1;
		for (int i{n - 2}; i >= 0; --i) nx[i] = (v[i] == v[i + 1] ? nx[i + 1] : i);

		struct M { int operator()(int x, int y) { return gcd(x, y); } };
		vector<int> d(n - 1);
		for (int i{0}; i + 1 < n; ++i) d[i] = v[i + 1] - v[i];
		ST<int, M> st{d};

		long long ans{};
		for (int i{0}, j{0}; i < n; ++i) {
			ans += nx[i] - i + 1;
			j = max(nx[i] + 1, j);
			while (j < n && __builtin_popcount(st.query(i, j)) > 1) ++j;
			ans += n - j;
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
