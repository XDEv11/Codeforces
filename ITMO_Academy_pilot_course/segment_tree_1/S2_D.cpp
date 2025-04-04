#include <iostream>
#include <vector>
#include <functional>

using namespace std;

// segment tree
template<typename T>
class SGT {
    int n;
    vector<T> t;
    inline int left(int tv) { return tv + 1; }
    // [ tv+1 : tv+2*(tm-tl)-1 ) -> left subtree
    inline int right(int tv, int tl, int tm) { return tv + 2 * (tm - tl); }

    // associative function for SGT
    function<T(const T&, const T&)> merge;
    void modify(int p, const T& x, int tv, int tl, int tr) {
        if (tl == tr - 1) t[tv] = x;
        else {
            int tm{(tl + tr) / 2}, lc{left(tv)}, rc{right(tv, tl, tm)};
            if (p < tm) modify(p, x, lc, tl, tm);
            else modify(p, x, rc, tm, tr);
            t[tv] = merge(t[lc], t[rc]);
        }
    }
    T query(int l, int r, int tv, int tl, int tr) {
        if (l == tl && r == tr) return t[tv];
        int tm{(tl + tr) / 2};
        if (r <= tm) return query(l, r, left(tv), tl, tm);
        else if (l >= tm) return query(l, r, right(tv, tl, tm), tm, tr);
        else return merge(query(l, tm, left(tv), tl, tm)
                , query(tm, r, right(tv, tl, tm), tm, tr));
    }
public:
    explicit SGT(int _n, const decltype(merge)& m) : n{_n}, t(2 * n - 1), merge(m) {}
    explicit SGT(int _n, decltype(merge)&& m) : n{_n}, t(2 * n - 1), merge(m) {}
    void modify(int p, const T& x) { modify(p, x, 0, 0, n); };
    T query(int l, int r) { return query(l, r, 0, 0, n); } // [l:r)

	T aux(int l, const T& x, int tv, int tl, int tr) {
        if (tr - tl == 1) return tl;

        int tm{(tl + tr) / 2};
		if (l < tm && t[left(tv)] >= x) {
			auto res{aux(l, x, left(tv), tl, tm)};
			if (res != n) return res;
		}
		if (t[right(tv, tl, tm)] >= x) return aux(l, x, right(tv, tl, tm), tm, tr);
		else return n; // n means not found
	}
	T binary_search_on_tree(int l, const T& x) { // assume merge is max
		if (l < n && t[0] >= x) return aux(l, x, 0, 0, n); // make sure l < tr && t[tv] >= x
		else return n;
	}
};

void solve() {
	int n, m;
	cin >> n >> m;

	SGT<int> sgt{n, [](const int& x, const int& y){return max(x, y);}};

	for (int i{0}; i < n; ++i) {
		int x; cin >> x;
		sgt.modify(i, x);
	}

	while (m--) {
		int op; cin >> op;
		if (op == 1) {
			int i, v; cin >> i >> v;
			sgt.modify(i, v);
		} else if (op == 2) {
			int x, l; cin >> x >> l;
			int res{sgt.binary_search_on_tree(l, x)}; // first at least x
			cout << (res == n ? -1 : res) << '\n';
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t{1};
	// cin >> t;
	while (t--) solve();
	
	return 0;
}
