//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <utility>
#include <set>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for (auto& [l, r] : v) cin >> l >> r;

	vector<bool> ck(n, false);

	set<int> s{};
	for (int i{1}; i <= n; ++i) s.insert(i);

	vector<int> ans(n);
	for (int k{0}; k < n; ++k)
		for (int i{0}; i < n; ++i) {
			if (ck[i]) continue;

			auto& [l, r]{v[i]};
			auto itl{s.lower_bound(l)}, itr{s.upper_bound(r)};
			if (next(itl) == itr) {
				ans[i] = *itl;
				ck[i] = true;
				s.erase(itl);
				break;
			}
		}

	for (int i{0}; i < n; ++i) {
		auto& [l, r]{v[i]};
		cout << l << ' ' << r << ' ' << ans[i] << '\n';
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
