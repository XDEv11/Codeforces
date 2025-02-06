//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>

using namespace std;

namespace {
	void solve() {
		int n;
		cin >> n;
		vector<int> v(n + 1);
		v[0] = n;
		for (int i{1}; i <= n; ++i) cin >> v[i];

		vector<int> ans(n + 1, n + 1);
		int j{0};
		vector<bool> ck(n + 1);
		for (int i{n}; i; --i) {
			if (v[i] < n - i || v[i - 1] > n || v[i - 1] < v[i]) return void(cout << "NO\n");
			ck[v[i]] = true;
			if (v[i - 1] == v[i]) {
				while (ck[j]) ++j;
				ans[i] = j, ck[j] = true;
			}
		}

		cout << "YES\n";
		for (int i{1}; i <= n; ++i) cout << ans[i] << " \n"[i == n];
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
