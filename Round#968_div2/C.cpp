//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		int n;
		cin >> n;
		vector<char> v(n);
		for (auto& x : v) cin >> x;

		array<int, 26> cnt{};
		for (auto& x : v) ++cnt[x - 'a'];

		vector<char> ans{};
		while (true) {
			bool f{false};
			for (int i{0}; i < 26; ++i) {
				if (!cnt[i]) continue;
				ans.push_back('a' + i);
				--cnt[i];
				f = true;
			}
			if (!f) break;
		}
			
		for (auto& x : ans) cout << x;
		cout << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
