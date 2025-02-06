#include <iostream>
#include <vector>
#include <functional>
#include <array>

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
	int mod, n, m;
	cin >> mod >> n >> m;

	auto mod_ = [mod](int& x) {
		// x = ((x % mod) + mod) % mod;
		x %= mod;
	};

	using data_t = array<array<int, 2>, 2>;
	SGT<data_t> sgt{
		n,
		[&mod_](const data_t& x, const data_t& y) -> data_t {
			data_t res{};
			for (int r{0}; r < 2; ++r)
				for (int c{0}; c < 2; ++c) {
					for (int i{0}; i < 2; ++i)
						res[r][c] += x[r][i] * y[i][c];
					mod_(res[r][c]);
				}
			return res;
		}
	};

	for (int i{0}; i < n; ++i) {
		data_t mtx;
		for (auto& vt : mtx)
			for (auto& x : vt) cin >> x, mod_(x);
		sgt.modify(i, mtx);
	}

	while (m--) {
		int l, r;
		cin >> l >> r, --l, --r;
		auto mtx{sgt.query(l, r + 1)};

		for (auto& vt : mtx) {
			for (auto& x : vt) cout << x << ' ';
			cout << '\n';
		}
		cout << '\n';
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
