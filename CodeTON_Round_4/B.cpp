//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	if (n % 2 == 0) return cout << "-1\n", []{}();

	vector<int> ans{};
	while (n > 1) ans.push_back(n & 2 ? 2 : 1), n >>= 1;
	reverse(ans.begin(), ans.end());

	cout << ans.size() << '\n';
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
