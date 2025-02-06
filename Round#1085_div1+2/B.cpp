//#pragma GCC optimize ("O3")

#include <iostream>
#include <utility>
#define fi first
#define se second
#include <vector>
#include <deque>
#include <iterator>

using namespace std;

namespace {
	void solve() {
		int n, m, l;
		cin >> n >> m >> l;
		vector<int> v(n);
		for (auto& x : v) cin >> x, --x;

		int c{m};
		deque<pair<int, int>> t{{0, m}};
		for (int k{0}, i{0}; k < l; ++k) {
			while (c > n - i + 1) {
				--c;
				if (!--t.back().se) t.pop_back();
			}

			auto [x, y]{t.back()}; t.pop_back();
			if (!t.empty() && t.back().fi == x + 1) ++t.back().se;
			else t.emplace_back(x + 1, 1);
			if (--y) t.emplace_back(x, y);

			if (i < n && v[i] == k) {
				++i;
				if (!--t.front().se) t.pop_front();
				if (!t.empty() && t.back().fi == 0) ++t.back().se;
				else t.emplace_back(0, 1);
			}
		}

		cout << t[0].fi << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
