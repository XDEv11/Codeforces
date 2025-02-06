//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <map>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

template<typename value_t>
class ITreap {
    mt19937 gen{chrono::system_clock::now().time_since_epoch().count()};
    uniform_int_distribution<mt19937::result_type> dist{};

	struct node_t;
	using node_pt = node_t*;
	struct node_t {
		int sz{1};
		mt19937::result_type pr;
		node_pt l{}, r{};
		value_t val;
	};
	int sz(node_pt x) { return x ? x->sz : 0; }
	node_pt upd(node_pt x) { return x->sz = sz(x->l) + 1 + sz(x->r), x; }

	node_pt rt{};
	node_pt merge(node_pt x, node_pt y) {
		if (!x) return y;
		else if (!y) return x;
		else if (x->pr > y-> pr) return x->r = merge(x->r, y), upd(x);
		else return y->l = merge(x, y->l), upd(y);
	}
	pair<node_pt, node_pt> split(node_pt x, int k) {
		if (!x) return {};
		else if (k <= sz(x->l)) {
			auto [y, z]{split(x->l, k)};
			return {y, (x->l = z, upd(x))};
		} else {
			auto [y, z]{split(x->r, k - sz(x->l) - 1)};
			return {(x->r = y, upd(x)), z};
		}
	}
	node_pt insert(node_pt x, int k, node_pt n) {
		if (!x) return n;
		else if (n->pr > x->pr) {
			auto [y, z]{split(x, k)};
			return n->l = y, n->r = z, upd(n);
		} else if (k <= sz(x->l)) return x->l = insert(x->l, k, n), upd(x);
		else return x->r = insert(x->r, k - sz(x->l) - 1, n), upd(x);
	}
	node_pt erase(node_pt x, int k) {
		if (k == sz(x->l)) {
			auto y{merge(x->l, x->r)};
			delete x;
			return y;
		} else if (k < sz(x->l)) return x->l = erase(x->l, k), upd(x);
		else return x->r = erase(x->r, k - sz(x->l) - 1), upd(x);
	}
	value_t find(node_pt x, int k) {
		if (k == sz(x->l)) return x->val;
		else if (k < sz(x->l)) return find(x->l, k);
		else return find(x->r, k - sz(x->l) - 1);
	}
	void clear(node_pt x) {
		if (!x) return ;
		clear(x->l), clear(x->r), delete(x);
	}
public:
	void insert(int k, value_t val) {
		node_pt n{new node_t};
		n->pr = dist(gen), n->val = val;
		rt = insert(rt, k, n);
	}
	void erase(int k) { rt = erase(rt, k); }
	value_t find(int k) { return find(rt, k); }
	void clear() { clear(rt), rt = nullptr; }
	~ITreap() { clear(); }
};

namespace {
	using ll = long long;
	const ll PM{998244353};
	ll MA(ll a, ll b) { return (a + b) % PM; }
	ll MS(ll a, ll b) { return (a - b + PM) % PM; }
	ll MM(ll a, ll b) { return (a * b) % PM; }
	ll MP(ll a, ll b) {
		ll res{1};
		do {
			if (b & 1) res = MM(res, a);
		} while (a = MM(a, a), b >>= 1);
		return res;
	}
	ll MI(ll a) { return MP(a, PM - 2); }
	ll MD(ll a, ll b) { return MM(a, MI(b)); }
	vector<ll> MF{[] {
		int n{500000};
		vector<ll> t(n + 1);
		t[0] = 1;
		for (int i{1}; i <= n; ++i) t[i] = MM(t[i - 1], i);
		return t;
	}()};
	ll MC(ll n, ll k) { return MD(MF[n], MM(MF[k], MF[n - k])); }

	vector<int> p{}, a{};
	vector<vector<int>> ch{};
	ITreap<int> it{};
	map<pair<int, int>, pair<ll, int>> dp{};
	void dfs(int u) {
		it.insert(a[u], u);
		int v{it.find(a[u] - 1)}, w{it.find(a[u] + 1)};
		auto it0{dp.find({v, w})}, it1{dp.insert({{v, u}, {1, 0}}).fi}, it2{dp.insert({{u, w}, {1, 0}}).fi};
		auto& v0{it0->se}; auto& v1{it1->se}; auto& v2{it2->se};

		for (auto& c : ch[u]) dfs(c);
		int t{v1.se + 1 + v2.se};
		v0.fi = MM(MM(MM(v0.fi, v1.fi), v2.fi), MC(v0.se += t, t));

		dp.erase(it1), dp.erase(it2);
		it.erase(a[u]);
	}
	void solve() {
		int n;
		cin >> n;
		p.resize(n + 2), a.resize(n + 2);
		p[0] = -1, a[0] = 0;
		p[n + 1] = 0, a[n + 1] = 1;
		p[1] = n + 1;
		for (int v{2}; v <= n; ++v) cin >> p[v];
		for (int v{1}; v <= n; ++v) cin >> a[v], ++a[v];

		ch.assign(n + 2, {});
		for (int v{1}; v <= n + 1; ++v) ch[p[v]].push_back(v);

		it.clear(), it.insert(0, 0), it.insert(1, n + 1);
		dp.clear(), dp[{0, n + 1}] = {1, 0};
		dfs(1);

		cout << dp[{0, n + 1}].fi << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
