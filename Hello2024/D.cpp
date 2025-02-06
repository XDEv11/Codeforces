//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <queue>
#include <array>
#include <algorithm>
#include <numeric>

using namespace std;

// previous/next one
class PvNx {
    vector<int> pa, sz, mn, mx;
    int find(int x) { // collapsing find
        return pa[x] == -1 ? x : pa[x] = find(pa[x]);
    }
    void unionn(int x, int y) { // weighted union
        auto rx{find(x)}, ry{find(y)};
        if (rx == ry) return ;
        if (sz[rx] < sz[ry]) swap(rx, ry);
        pa[ry] = rx, sz[rx] += sz[ry], mn[rx] = min(mn[rx], mn[ry]), mx[rx] = max(mx[rx], mx[ry]);
    }
public:
    explicit PvNx(int n) : pa(n + 1, -1), sz(n + 1, 1), mn(n + 1) { iota(mn.begin(), mn.end(), 0), mx = mn; }
    void remove(int i) { unionn(i, i + 1); }
    int prev(int i) { return mn[find(i)] - 1; }
    int next(int i) {
        int j{mx[find(i)]};
        if (i == j) j = mx[find(j + 1)];
        return j;
    }
	bool exist(int i) { return i == mx[find(i)]; }
};

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;
	if (!count(v.begin(), v.end(), 0)) return cout << "NO\n", []{}();

	PvNx pn{n};
	priority_queue<array<int, 3>> pq{};

	for (int i{0}; i + 1 < n; ++i) {
		int j{i}, k{i + 1};
		if (v[j] < v[k]) swap(j, k);
		if (v[j] == v[k] + 1) pq.push({v[j], j, k});
	}

	while (!pq.empty()) {
		auto [_, j, k]{pq.top()}; pq.pop();
		if (!pn.exist(j) || !pn.exist(k)) continue;
		pn.remove(j);
		int i{j < k ? pn.prev(k) : pn.next(k)};
		if (0 <= i && i < n) {
			if (v[i] < v[k]) swap(i, k);
			if (v[i] == v[k] + 1) pq.push({v[i], i, k});
		}
	}

	int cnt{};
	for (int i{0}; i < n; ++i) cnt += pn.exist(i);
	cout << (cnt == 1 ? "YES\n" : "NO\n");
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
