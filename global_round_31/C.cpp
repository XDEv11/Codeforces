//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>

using namespace std;

namespace {
	void solve() {
		int n, k;
		cin >> n >> k;
		if (k & 1) {
			while (k--) cout << n << ' ';
			cout << '\n';
			return ;
		}

		vector<int> ans{};
		int a{n}, b{n};
		for (int i{29}; i >= 0; --i) {
			if (n & (1 << i)) {
				if (a < n) {
					b ^= (1 << i);
					if (ans.size() + 2 < k) {
						ans.push_back(a | ((1 << i) - 1));
						ans.push_back(b | ((1 << i) - 1));
						a = b = n;
					}
				} else a ^= (1 << i);
			} else {
				if (b < n) {
					a |= (1 << i);
					b |= (1 << i);
				}
			}
		}
		ans.push_back(a);
		ans.push_back(b);

		for (int i{0}; i < k; ++i) {
			cout << (i < ans.size() ? ans[i] : n) << " \n"[i == k - 1];
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
