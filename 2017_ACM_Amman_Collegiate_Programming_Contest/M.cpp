#include <iostream>
#include <vector>
#include <map>
#define fi first
#define se second
#include <algorithm>

using namespace std;

void solve() {
	static const int maxval{1000000};
	static vector<int> cnt(maxval + 1), nxt(maxval + 1);

	int n;
	cin >> n;
	map<int, int> mp{};
	for (int i{0}; i < n * (n - 1) / 2; ++i) {
		int x;
		cin >> x;
		++mp[x];
	}

	int mx{mp.rbegin()->fi};
	for (auto it{mp.begin()}; next(it) != mp.end(); ++it) nxt[next(it)->fi] = it->fi;

	for (int k{0}; k < (1 << (n - 2)); ++k) {
		for (auto& [x, y] : mp) cnt[x] = y;
		bool f{true};
		vector<int> ans{};
		ans.push_back(0), ans.push_back(mx), --cnt[mx];
		for (int i{mx}, j{0}; j < n - 2; ++j) {
			while (!cnt[i]) i = nxt[i];
			int p{((k >> j) & 1) ? i : mx - i};
			for (auto& q : ans) {
				int d{abs(p - q)};
				if (!cnt[d]) {
					f = false;
					break;
				}
				--cnt[d];
			}
			if (!f) break;
			ans.push_back(p);
		}
		if (f) {
			sort(ans.begin(), ans.end());
			for (auto& x : ans) cout << x << ' ';
			cout << '\n';
			return ;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t{1};
	cin >> t;
	while (t--) solve();
}
