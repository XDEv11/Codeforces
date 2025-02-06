#include <iostream>
#include <vector>
#include <optional>

#define fi first
#define se second

using namespace std;

// segment tree
// range query & range modify
template <typename value_t>
class SGT {
    int n;
    vector<value_t> t;
    vector<optional<value_t>> lz;
    // [ tv+1 : tv+2*(tm-tl) ) -> left subtree
    inline int left(int tv) { return tv + 1; }
    inline int right(int tv, int tl, int tm) { return tv + 2 * (tm - tl); }
    /** differ from case to case **/
    // query is "sum" and modify is "add" here
    inline value_t merge(const value_t& x, const value_t& y) { // associative function
        return x + y;
    }
    inline void update(int tv, int len, const value_t& x) {
        if (!lz[tv]) lz[tv] = x;
        else lz[tv] = lz[tv].value() + x;
        t[tv] += len * x;
    }
    /******************************/
    void push(int tv, int tl, int tr) { // lazy propagation
        if (!lz[tv]) return;
        
        int tm{(tl + tr) / 2};
        update(left(tv), tm - tl, lz[tv].value());
        update(right(tv, tl, tm), tr - tm, lz[tv].value());
        lz[tv].reset();
    }
    void modify(int l, int r, const value_t& x, int tv, int tl, int tr) {
        if (l == tl && r == tr) update(tv, tr - tl, x);
        else {
            push(tv, tl, tr);
            int tm{(tl + tr) / 2};
            if (r <= tm) modify(l, r, x, left(tv), tl, tm);
            else if (l >= tm) modify(l, r, x, right(tv, tl, tm), tm, tr);
            else modify(l, tm, x, left(tv), tl, tm),
                modify(tm, r, x, right(tv, tl, tm), tm, tr);
            t[tv] = merge(t[left(tv)], t[right(tv, tl, tm)]);
        }
    }
    value_t query(int l, int r, int tv, int tl, int tr) {
        if (l == tl && r == tr) return t[tv];
        push(tv, tl, tr);
        int tm{(tl + tr) / 2};
        if (r <= tm) return query(l, r, left(tv), tl, tm);
        else if (l >= tm) return query(l, r, right(tv, tl, tm), tm, tr);
        else return merge(query(l, tm, left(tv), tl, tm), 
                query(tm, r, right(tv, tl, tm), tm, tr));
    }
public:
    explicit SGT(int _n) : n{_n}, t(2 * n), lz(2 * n) {}
    void modify(int l, int r, const value_t& x) { modify(l, r, x, 1, 0, n); } // [l:r)
    value_t query(int l, int r) { return query(l, r, 1, 0, n); } // [l:r)
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	SGT<long long> sgt{n};

	while (m--) {
		int op;
		cin >> op;
		if (op == 1) {
			int l, r, v;
			cin >> l >> r >> v;
			sgt.modify(l, r, v);
		} else if (op == 2) {
			int l, r;
			cin >> l >> r;
			cout << sgt.query(l, r) << '\n';
		}
	}

	return 0;
}
