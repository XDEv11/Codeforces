//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		int n, m;
		cin >> n >> m;
		vector<int> v(n);
		for (auto& x : v) cin >> x;

		vector<int> cnt(n * 2 + 1);
		for (auto& x : v) ++cnt[x];

		int ans{};
		int s{};
		vector<int> t{};
		for (int i{2 * n}; i >= 1; --i) {
			if (cnt[i] > m) {
				int d{cnt[i] - m};
				if (d <= t.size()) ans = max(ans, t[t.size() - d] - i);
				else ans = max(ans, s + d);
			}

			s += cnt[i];
			t.push_back(i);
			while (cnt[i] && !t.empty()) --cnt[i], t.pop_back();
		}

		cout << ans << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
