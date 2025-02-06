//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n, k, m;
	cin >> n >> k >> m;
	vector<char> v(m);
	for (auto& x : v) cin >> x;

	vector<char> ans{};
	int cnt{};
	vector<bool> ck(k);
	for (auto& x : v) {
		if (ans.size() == n) break;
		if (!ck[x - 'a']) ++cnt, ck[x - 'a'] = true;
		if (cnt == k) {
			ans.push_back(x);
			cnt = 0, fill(ck.begin(), ck.end(), false);
		}
	}

	if (ans.size() < n) {
		cout << "NO\n";
		int x{0};
		while (ck[x]) ++x;
		for (int i{0}; i < n; ++i) cout << (i < ans.size() ? ans[i] : char('a' + x));
		cout << '\n';
	} else cout << "YES\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
