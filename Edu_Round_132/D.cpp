//#pragma GCC optimize ("O3")

#include <ios>
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
	int n, m;
	cin >> n >> m;
	vector<int> b(m);
	for (auto& x : b) cin >> x;

	ST st{b, [](const int& x, const int& y){ return max(x, y); }};

	int q;
	cin >> q;
	while (q--) {
		int xs, ys, xt, yt, k;
		cin >> xs >> ys >> xt >> yt >> k;

		xs += (n - xs) / k * k;

		if (ys > yt) swap(ys, yt);
		if ((yt - ys) % k) {
			cout << "NO\n";
			continue;
		}
		if (yt - 1 - ys >= 1 && st.query(ys, yt - 1) >= xs) {
			cout << "NO\n";
			continue;
		}

		if ((xs - xt) % k) {
			cout << "NO\n";
			continue;
		}

		cout << "YES\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();
}
