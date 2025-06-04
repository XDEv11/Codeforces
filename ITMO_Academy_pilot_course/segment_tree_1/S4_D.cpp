#include <iostream>
#include <vector>
#include <functional>
#include <bitset>

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
};

void solve() {
	int n, q;
	cin >> n >> q;

	using data_t = bitset<40>;
	SGT<data_t> sgt{
		n,
		[](const data_t& x, const data_t& y) -> data_t {
			data_t res{x};
			return (res |= y);
		}
	};

	for (int i{0}; i < n; ++i) {
		int x;
		cin >> x, --x;
		data_t d{}; d[x] = true;
		sgt.modify(i, d);
	}

	while (q--) {
		int op, var1, var2;
		cin >> op >> var1 >> var2, --var1, --var2;
		if (op == 1) cout << sgt.query(var1, var2 + 1).count() << '\n';
		else {
			data_t d{}; d[var2] = true;
			sgt.modify(var1, d);
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
