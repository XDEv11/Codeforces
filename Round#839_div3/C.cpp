//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int k, n;
	cin >> k >> n;

	vector<int> ans(k);
	ans[0] = 1;
	for (int i{1}; i < k; ++i) {
		if (ans[i - 1] + i + (k - 1 - i) <= n) ans[i] = ans[i - 1] + i;
		else ans[i] = ans[i - 1] + 1;
	}

	for (auto& x : ans) cout << x << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
