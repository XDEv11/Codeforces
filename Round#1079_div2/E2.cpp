//#pragma GCC optimize ("O3")

#include <iostream>
#include <utility>
#define fi first
#define se second
#include <vector>
#include <algorithm>

#include <cstdlib>

using namespace std;

namespace {
	vector<int> ask(int k) {
		cout << "? " << k << endl;
		int l;
		cin >> l;
		if (l == -1) exit(EXIT_SUCCESS);
		vector<int> p(l);
		for (auto& v : p) cin >> v;
		return p;
	}
	void solve() {
		int n;
		cin >> n;

		vector<pair<int, int>> ans{};
		int i{1};
		vector<pair<int, int>> t{{1, 1}};
		vector<int> sz(n + 1, 1);
		while (true) {
			i += sz[t.back().fi];
			auto p{ask(i)};
			if (p.empty()) break;
			while (t.size() + 1 > p.size()) sz[t.back().fi] = i - t.back().se, t.pop_back();
			if (p.size() > 1) ans.emplace_back(t.back().fi, p.back());
			t.emplace_back(p.back(), i);
		}

		cout << "! " << ans.size() << '\n';
		for (auto& [x, y] : ans) cout << x << ' ' << y << '\n';
		cout << endl;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
