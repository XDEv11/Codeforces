#include <iostream>
#include <vector>

using namespace std;

static constexpr long long mod{1000000007};
/* Iterative Function to calculate (x^y) % P in O(log y) */
static long long power(long long x, long long y) { 
	long long res{1};
	while (y > 0) {
		if (y & 1) res = (res * x) % mod; 
		y >>= 1; 
		x = (x * x) % mod;
	}
	return res; 
}

// fast disjoint set union
class DSU {
	vector<int> p, sz;
public:
	explicit DSU(int n) : p(n, -1), sz(n, 1) {}
	int find(int x) { // path compression
		return (p[x] == -1 ? x : p[x] = find(p[x]));
	}
	void unionn(int x, int y) { // union by size
		auto rx{find(x)}, ry{find(y)};
		if (rx == ry) return ;
		if (sz[rx] < sz[ry]) swap(rx, ry);
		p[ry] = rx, sz[rx] += sz[ry];
	}
};

void solve() {
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for (auto& [x, y] : v) cin >> x;
	for (auto& [x, y] : v) cin >> y;

	DSU dsu{n + 1};
	for (auto& [x, y] : v) dsu.unionn(x, y);

	int cnt{0};
	for (int i{1}; i <= n; ++i)
		if (dsu.find(i) == i) ++cnt;
	cout << power(2, cnt) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
