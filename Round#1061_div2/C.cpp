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

		vector<int> cnt(n + 1);
		for (auto& x : v) ++cnt[x];
		vector<int> ps(n + 1);
		for (int i{1}; i <= n; ++i) ps[i] = ps[i - 1] + cnt[i];
		
		for (int i{n}; i >= 2; --i) {
			int b{ps[i - 1] + ps[min(n, i * 4 - 1)] - ps[i]};
			if (i * 2 <= n) b -= cnt[i * 2];
			if (i * 3 <= n) b -= cnt[i * 3];

			if (b <= m) {
				cout << i << '\n';
				return ;
			}
		}
		cout << "1\n";
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
