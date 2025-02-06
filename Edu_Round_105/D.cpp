#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <functional>
#include <tuple>

using namespace std;

// fast disjoint set union
class DSU {
    vector<int> p;
public:
    explicit DSU(int n) : p(n, -1) {}
    int root(int x) { // path compression
        return (p[x] == -1 ? x : p[x] = root(p[x]));
    }
    void unionn(int x, int y) { // union y to x, rx will be root afterwards
        auto rx{root(x)}, ry{root(y)};
        if (rx == ry) return ;
        p[ry] = rx;
    }
};

void solve() {
	int n;
	cin >> n;

	vector<int> val{};
	vector<pair<int, int>> conn{};

	using pq_t = tuple<int, int, int>;
	priority_queue<pq_t, vector<pq_t>, greater<pq_t>> pq{};
	for (int i{0}; i < n; ++i)
		for (int j{0}; j < n; ++j) {
			int x;
			cin >> x;
			if (i > j) pq.emplace(x, i, j);
			else if (i == j) val.push_back(x);
		}

	DSU dsu{2 * n};

	int lb{n}; // label
	while (!pq.empty()) {
		auto [v, i, j]{pq.top()}; pq.pop();
		auto ri{dsu.root(i)}, rj{dsu.root(j)};
		if (ri == rj) continue;
		
		if (v == val[ri]) {
			conn.emplace_back(rj, ri); // rj -> ri
			dsu.unionn(ri, j);
		} else if (v == val[rj]) {
			conn.emplace_back(ri, rj); // ri -> rj
			dsu.unionn(rj, i);
		} else {
			val.push_back(v);
			conn.emplace_back(ri, lb); // ri -> lb
			conn.emplace_back(rj, lb); // rj -> lb
			dsu.unionn(lb, i);
			dsu.unionn(lb, j);
			++lb; // use next label next time
		}
	}

	cout << lb << '\n'; // [0:lb)
	for (auto& x : val) cout << x << ' ';
	cout << '\n';
	cout << lb << '\n'; // root, actually (lb - 1)
	for (auto& [u, v] : conn) cout << u + 1 << ' ' << v + 1 << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	// cin >> t;
	while (t--) solve();

	return 0;
}
