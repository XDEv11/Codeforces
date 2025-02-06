#include <iostream>
#include <vector>
#include <optional>

#define fi first
#define se second

using namespace std;

template <typename value_t>
class SGT {
    int n;
    vector<value_t> t;
    vector<optional<value_t>> lz;
    inline int left(int tv) { return tv + 1; }
    inline int right(int tv, int tl, int tm) { return tv + 2 * (tm - tl); }
    
    inline value_t merge(const value_t&, const value_t&);
    inline void update(int, int, const value_t&);
    
    void push(int, int, int);
    void modify(int, int, const value_t&, int, int, int);
    value_t query(int, int, int, int, int);
    
public:
    explicit SGT(int _n) : n{_n}, t(2 * n), lz(2 * n) {}
    void modify(int l, int r, const value_t& x) { modify(l, r, x, 1, 0, n); }
    value_t query(int l, int r) { return query(l, r, 1, 0, n); }
};

template <typename value_t>
inline value_t SGT<value_t>::merge(const value_t& x, const value_t& y) {
    return x + y;
}

template <typename value_t>
inline void SGT<value_t>::update(int tv, int len, const value_t& x) {
    if (!lz[tv]) lz[tv] = x;
    else lz[tv] = lz[tv].value() + x;
    t[tv] += len * x;
}

template <typename value_t>
void SGT<value_t>::push(int tv, int tl, int tr) { // lazy propagation
    if (!lz[tv]) return;
        
    int tm{(tl + tr) / 2};
    update(left(tv), tm - tl, lz[tv].value());
    update(right(tv, tl, tm), tr - tm, lz[tv].value());
    lz[tv].reset();
}

template <typename value_t>
void SGT<value_t>::modify(int l, int r, const value_t& x, int tv, int tl, int tr) {
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

template <typename value_t>
value_t SGT<value_t>::query(int l, int r, int tv, int tl, int tr) {
    if (l == tl && r == tr) return t[tv];
    push(tv, tl, tr);
    int tm{(tl + tr) / 2};
    if (r <= tm) return query(l, r, left(tv), tl, tm);
    else if (l >= tm) return query(l, r, right(tv, tl, tm), tm, tr);
    else return merge(query(l, tm, left(tv), tl, tm), 
            query(tm, r, right(tv, tl, tm), tm, tr));
}

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
			int i;
			cin >> i;
			cout << sgt.query(i, i + 1) << '\n';
		}
	}

	return 0;
}
