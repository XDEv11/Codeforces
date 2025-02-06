//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>

using namespace std;

namespace {
	void solve() {
		int n;
		cin >> n;
		vector<int> v(n);
		for (auto& x : v) cin >> x;

		vector<char> ans{};
		int j{0}, k{n - 1};
		for (int i{0}; i < n; ++i) {
			if (i & 1) {
				if (v[j] < v[k]) ans.push_back('L'), ++j;
				else ans.push_back('R'), --k;
			} else {
				if (v[j] > v[k]) ans.push_back('L'), ++j;
				else ans.push_back('R'), --k;
			}
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
