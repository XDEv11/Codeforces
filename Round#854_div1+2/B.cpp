//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <map>
#include <iterator>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	multimap<int, int> mmp{};
	for (int i{0}; i < n; ++i) mmp.emplace(v[i], i);
	if (mmp.begin()->fi == 1) return cout << (mmp.rbegin()->fi == 1 ? "0\n" : "-1\n"), []{}();

	vector<pair<int, int>> ans{};
	while (mmp.begin()->fi != 2) {
		if (mmp.begin()->fi == mmp.rbegin()->fi) break;
		int vi{mmp.rbegin()->fi}, i{mmp.rbegin()->se}; mmp.erase(prev(mmp.end()));
		ans.emplace_back(i, mmp.begin()->se);
		vi = (vi + mmp.begin()->fi - 1) / mmp.begin()->fi;
		mmp.emplace(vi, i);
	}
	if (mmp.begin()->fi == 2) {
		int j{mmp.begin()->se};
		mmp.erase(mmp.begin());
		while (!mmp.empty()) {
			int vi{mmp.begin()->fi}, i{mmp.begin()->se}; mmp.erase(mmp.begin());
			while (vi != 2) {
				ans.emplace_back(i, j);
				vi = (vi + 1) / 2;
			}
		}
	}

	cout << ans.size() << '\n';
	for (auto& [i, j] : ans) cout << i + 1 << ' ' << j + 1 << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
