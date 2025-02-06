//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

// fast disjoint set union
class LDSU {
    vector<int> pa, sz, mn;
    int find(int x) { // collapsing find
        return pa[x] == -1 ? x : pa[x] = find(pa[x]);
    }
    void unionn(int x, int y) { // weighted union
        auto rx{find(x)}, ry{find(y)};
        if (rx == ry) return ;
        if (sz[rx] < sz[ry]) swap(rx, ry);
        pa[ry] = rx, sz[rx] += sz[ry], mn[rx] = min(mn[rx], mn[ry]);
    }
public:
    explicit LDSU(int n) : pa(n, -1), sz(n, 1), mn(n) { iota(mn.begin(), mn.end(), 0); }
	void remove(int i) { if (i + 1 < pa.size()) unionn(i, i + 1); }
	int left(int i) { return mn[find(i)] - 1; }
};

// fast disjoint set union
class RDSU {
    vector<int> pa, sz, mx;
    int find(int x) { // collapsing find
        return pa[x] == -1 ? x : pa[x] = find(pa[x]);
    }
    void unionn(int x, int y) { // weighted union
        auto rx{find(x)}, ry{find(y)};
        if (rx == ry) return ;
        if (sz[rx] < sz[ry]) swap(rx, ry);
        pa[ry] = rx, sz[rx] += sz[ry], mx[rx] = max(mx[rx], mx[ry]);
    }
public:
    explicit RDSU(int n) : pa(n, -1), sz(n, 1), mx(n) { iota(mx.begin(), mx.end(), 0); }
	void remove(int i) { if (i) unionn(i - 1, i); }
	int right(int i) { return mx[find(i)] + 1; }
};


void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (auto& x : a) cin >> x;
	for (auto& x : b) cin >> x;

	LDSU lf{n};
	RDSU ri{n};
	auto check{[&](int i) {
		if (!(0 <= i && i < n)) return false;
		int l{lf.left(i)}, r{ri.right(i)};
		return b[i] < (l == -1 ? 0 : a[l]) + (r == n ? 0 : a[r]);
	}};

	vector<int> ans(n);
	vector<bool> d(n);
	vector<int> t{};
	for (int i{0}; i < n; ++i) if (check(i)) d[i] = true, t.push_back(i);
	for (int j{0}; j < n; ++j) {
		ans[j] = t.size();
		for (auto& i : t) lf.remove(i), ri.remove(i);
		vector<int> nt{};
		for (auto& i : t) {
			int l{lf.left(i)}, r{ri.right(i)};
			if (check(l) && !d[l]) d[l] = true, nt.push_back(l);
			if (check(r) && !d[r]) d[r] = true, nt.push_back(r);
		}
		t = move(nt);
	}
	
	for (auto& x : ans) cout << x << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
