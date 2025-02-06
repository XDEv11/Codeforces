#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

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
	vector<long long> v(n);
	for (auto& x : v) cin >> x;

	if (n == 1) return cout << "1\n"s, []{}();

	for (int i{0}; i + 1 < n; ++i) v[i] = abs(v[i + 1] - v[i]);
	v.pop_back();

	struct merge_t {
		long long operator()(long long x, long long y) { return gcd(x, y); }
	};
	ST<long long, merge_t> st{v};

	int ans{1};
	for (int i{0}; i < n - 1; ++i) {
		int l{i - 1}, r{n - 1};
		while (r - l > 1) {
			int m{(l + r) / 2};
			if (st.query(i, m + 1) != 1) l = m;
			else r = m;
		}

		ans = max(ans, r - i + 1);
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
