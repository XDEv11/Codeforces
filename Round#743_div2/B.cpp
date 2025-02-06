#include <iostream>
#include <vector>
#include <algorithm>

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

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (auto& x : a) cin >> x;
	for (auto& x : b) cin >> x;

	vector<int> v(2 * n + 1, n);
	for (int i{0}; i < n; ++i) v[a[i]] = i;

	int ans{2 * n};
	ST st{v, [](const int& x, const int& y){ return min(x, y); }};
	for (int i{0}; i < n; ++i) ans = min(ans, i + st.query(0, b[i]));

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
