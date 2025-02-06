//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <optional>
#include <algorithm>
#include <set>

using namespace std;

// segment tree
// range query & range modify
template <typename value_t>
class SGT {
    using node_t = value_t;

    int n;
    vector<node_t> t;
    vector<optional<value_t>> lz;
    // [ tv+1 : tv+2*(tm-tl) ) -> left subtree
    int left(int tv) { return tv + 1; }
    int right(int tv, int tl, int tm) { return tv + 2 * (tm - tl); }
    /** differ from case to case **/
    // query is "sum, min" and modify is "add" here
    node_t merge(const node_t& x, const node_t& y) { // associative function
        return min(x, y);
    }
    void update(int tv, int len, const value_t& x) {
        if (!lz[tv]) lz[tv] = x;
        else lz[tv] = lz[tv].value() + x;
        t[tv] = t[tv] + x;
    }
    /******************************/
    void push(int tv, int tl, int tr) { // lazy propagation
        if (!lz[tv]) return ;

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
    node_t query(int l, int r, int tv, int tl, int tr) {
        if (l == tl && r == tr) return t[tv];
        push(tv, tl, tr);
        int tm{(tl + tr) / 2};
        if (r <= tm) return query(l, r, left(tv), tl, tm);
        else if (l >= tm) return query(l, r, right(tv, tl, tm), tm, tr);
        else return merge(query(l, tm, left(tv), tl, tm),
                query(tm, r, right(tv, tl, tm), tm, tr));
    }
public:
    explicit SGT(int _n) : n{_n}, t(2 * n - 1), lz(2 * n - 1) {}
    void modify(int l, int r, const value_t& x) { modify(l, r, x, 0, 0, n); } // [l:r)
    node_t query(int l, int r) { return query(l, r, 0, 0, n); } // [l:r)
};

void solve() {
	int n, q;
	cin >> n >> q;
	vector<bool> v(n);
	for (int i{0}; i < n; ++i) {
		char c;
		cin >> c;
		v[i] = (c == '(');
	}

	if (n & 1) {
		while (q--) {
			int i;
			cin >> i, --i;
			cout << "NO\n";
		}
		return ;
	}

	SGT<int> sgt{n};
	for (int i{0}; i < n; ++i) sgt.modify(i, n, v[i] ? 1 : -1);

	set<int> sco{}, scc{};
	for (int i{1}; i < n; ++i) {
		if (v[i - 1] && v[i]) sco.insert(i);
		if (!v[i - 1] && !v[i]) scc.insert(i);
	}

	while (q--) {
		int i;
		cin >> i, --i;

		sgt.modify(i, n, v[i] ? -1 : 1);
		if (i) {
			if (v[i - 1] && v[i]) sco.erase(i);
			if (!v[i - 1] && !v[i]) scc.erase(i);
		}
		if (i + 1 < n) {
			if (v[i] && v[i + 1]) sco.erase(i + 1);
			if (!v[i] && !v[i + 1]) scc.erase(i + 1);
		}
		v[i] = !v[i];
		sgt.modify(i, n, v[i] ? 1 : -1);
		if (i) {
			if (v[i - 1] && v[i]) sco.insert(i);
			if (!v[i - 1] && !v[i]) scc.insert(i);
		}
		if (i + 1 < n) {
			if (v[i] && v[i + 1]) sco.insert(i + 1);
			if (!v[i] && !v[i + 1]) scc.insert(i + 1);
		}

		if (sgt.query(0, sco.empty() ? n : *sco.begin()) < 0) cout << "NO\n";
		else if (sgt.query(n - 1, n) - (scc.empty() ? 0 : sgt.query(*scc.rbegin(), *scc.rbegin() + 1))) cout << "NO\n";
		else cout << "YES\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();
}
