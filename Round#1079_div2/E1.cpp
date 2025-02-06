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
		int i{1}, u{1}, v{1};
		while (true) {
			vector<int> t{};
			int r{1};
			while (true) {
				auto p{ask(i + r)};
				if (p.size() < 2 || p[0] != u || p[1] != v) { t = p; break; }
				r *= 2;
			}
			int l{r / 2};
			while (r - l > 1) {
				int m{(l + r) / 2};
				auto p{ask(i + m)};
				if (p.size() < 2 || p[0] != u || p[1] != v) t = p, r = m;
				else l = m;
			}
			i += r;

			if (t.empty()) break;
			else if (t.size() == 1) u = v = t[0];
			else ans.emplace_back(u = t[0], v = t[1]);
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
