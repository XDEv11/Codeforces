#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// segment tree
template<typename value_t, class merge_t>
class SGT {
	int n;
	vector<value_t> t; // root starts at 1
	merge_t merge; // associative function for SGT
public:
	explicit SGT(int _n, const merge_t& _merge = merge_t{})
		: n{_n}, t(2 * n), merge{_merge} {}
	void modify(int p, const value_t& x) {
		for (t[p += n] = x; p > 1; p >>= 1) t[p >> 1] = merge(t[p], t[p ^ 1]);
	}
	value_t query(int l, int r, value_t init) { // [l:r)
		for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if (l & 1) init = merge(init, t[l++]);
			if (r & 1) init = merge(init, t[--r]);
		}
		return init;
	}
};

void solve() {
	int n;
	cin >> n;
	long long s;
	cin >> s;
	vector<long long> v(n + 1);
	for (int i{1}; i <= n; ++i) cin >> v[i];

	vector<long long> ps(n + 1);
	for (int i{1}; i <= n; ++i) ps[i] = ps[i - 1] + v[i];

	vector<pair<long long, int>> t{};
	for (int i{0}; i <= n; ++i) t.emplace_back(ps[i], i);
	sort(t.begin(), t.end());

	for (auto& [fi, se] : t) cout << "(" << fi << ", " << se << ") ";
	cout << '\n';

	vector<int> idx(n + 1);
	for (int i{0}; i <= n; ++i) idx[t[i].second] = i;

	struct M {
		int operator()(const int& x, const int& y) const {return min(x, y);}
	};
	SGT<int, M> sgt{n + 1};
	for (int i{0}; i <= n; ++i) sgt.modify(i, t[i].second);

	int ans{0}, l, r;
	for (int i{0}; i <= n; ++i) {
		sgt.modify(idx[i], n + 1);
		int bl{0}, br{n + 1};
		while (br - bl > 1) {
			int bm{(bl + br) / 2};
			if (t[bm].first + s < ps[i]) bl = bm;
			else br = bm;
		}
		int q{sgt.query(0, br, n + 1)};
		if (q - 1 - i > ans) {
			ans = q - 1 - i;
			l = i + 1, r = q - 1;
		}
	}

	if (ans) cout << l << ' ' << r << '\n';
	else cout << "-1\n"s;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
