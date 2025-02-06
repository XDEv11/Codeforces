//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <set>

using namespace std;

void solve() {
	using ll = long long;

	int n;
	cin >> n;
	vector<array<ll, 3>> v(n);
	for (int i{0}; i < n; ++i) cin >> v[i][0] >> v[i][1], v[i][2] = i;

	auto test{[&](int s) {
		struct cmph { bool operator()(const array<ll, 3>& x, const array<ll, 3>& y) const {
			if (x[0] > y[0]) return true;
			else if (x[0] < y[0]) return false;
			if (x[1] > y[1]) return true;
			else if (x[1] < y[1]) return false;
			return x[2] > y[2];
		} };
		set<array<ll, 3>, cmph> sh{};
		struct cmpw { bool operator()(const array<ll, 3>& x, const array<ll, 3>& y) const {
			if (x[1] > y[1]) return true;
			else if (x[1] < y[1]) return false;
			if (x[0] > y[0]) return true;
			else if (x[0] < y[0]) return false;
			return x[2] > y[2];
		} };
		set<array<ll, 3>, cmpw> sw{};
		for (auto& x : v) sh.insert(x), sw.insert(x);
		ll ans{s == 1 ? (*sh.begin())[0] : (*sw.begin())[1]};
		ll h{-1}, w{-1};
		while (!sh.empty()) {
			if (s == 1) {
				h = (*sh.begin())[0];
				ll c{0};
				auto it{sh.begin()};
				while (it != sh.end() && (*it)[0] == h) {
					c += (*it)[1];
					auto nit{next(it)};
					sw.erase(sw.find(*it));
					sh.erase(it), it = nit;
				}
				if (w != -1 && w != c + (sw.empty() ? 0ll : (*sw.begin())[1])) return 0ll;
				s = 0;
			} else {
				w = (*sw.begin())[1];
				ll c{0};
				auto it{sw.begin()};
				while (it != sw.end() && (*it)[1] == w) {
					c += (*it)[0];
					auto nit{next(it)};
					sh.erase(sh.find(*it));
					sw.erase(it), it = nit;
				}
				if (h != -1 && h != c + (sh.empty() ? 0ll : (*sh.begin())[0])) return 0ll;
				s = 1;
			}
		}
		return ans;
	}};

	vector<array<ll, 2>> ans{};
	ll area{0};
	for (auto& [a, b, i] : v) area += a * b;
	auto r{test(1)}; if (r) ans.push_back({r, area / r});
	r = test(0); if (r) ans.push_back({area / r, r});
	if (ans.size() == 2 && ans[0] == ans[1]) ans.pop_back();

	cout << ans.size() << '\n';
	for (auto& [h, w] : ans) cout << h << ' ' << w << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
