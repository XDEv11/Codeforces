//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <array>
#include <set>
#include <algorithm>

using namespace std;

// fast disjoint set union
class DSU {
	vector<int> p, sz;
public:
	explicit DSU(int n) : p(n, -1), sz(n, 1) {}
	int find(int x) { // collapsing find
		return p[x] == -1 ? x : p[x] = find(p[x]);
	}
	void unionn(int x, int y) { // weighted union
		auto rx{find(x)}, ry{find(y)};
		if (rx == ry) return ;
		if (sz[rx] < sz[ry]) swap(rx, ry);
		p[ry] = rx, sz[rx] += sz[ry];
	}
};

void solve() {
	int n;
	cin >> n;
	vector<char> v(n);
	for (auto& x : v) cin >> x;

	array<char, 26> r{};
	DSU dsu{26};
	set<int> s{};
	for (int i{0}; i < 26; ++i) s.insert(i);
	for (auto& x : v) {
		if (!r[x - 'a']) {
			for (int i{0}; i < 26; ++i) {
				if (!s.count(i) || dsu.find(x - 'a') == dsu.find(i)) continue;
				r[x - 'a'] = 'a' + i;
				dsu.unionn(x - 'a', i);
				s.erase(i);
				break;
			}
		}
		if (!r[x - 'a']) r[x - 'a'] = 'a' + *s.begin();
		x = r[x - 'a'];
	}

	for (auto& x : v) cout << x;
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
