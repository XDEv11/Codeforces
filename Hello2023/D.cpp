//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

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
	vector<int> a(n), b(n);
	for (auto& x : a) cin >> x;
	for (auto& x : b) cin >> x;
	int m;
	cin >> m;
	multiset<int> ms{};
	for (int i{0}; i < m; ++i) {
		int x;
		cin >> x;
		ms.insert(x);
	}

	for (int i{0}; i < n; ++i) {
		if (a[i] < b[i]) return cout << "NO\n", []{}();
	}

	struct M { int operator()(int a, int b) { return max(a, b); }; };
	SGT<int, M> sgt{n};
	for (int i{0}; i < n; ++i) sgt.modify(i, b[i]);
	map<int, vector<int>> mp{};
	for (int i{0}; i < n; ++i) {
		if (a[i] != b[i]) {
			mp[b[i]].push_back(i);
		}
	}
	for (auto& [k, v] : mp) {
		for (int i{0}; i < v.size(); ++i) {
			auto it{ms.find(k)};
			if (it == ms.end()) return cout << "NO\n", []{}();
			ms.erase(it);
			while (i + 1 < v.size()) {
				if (sgt.query(v[i], v[i + 1] + 1, k) > k) break;
				++i;
			}
		}
	}

	cout << "YES\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
