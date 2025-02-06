//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int x, y;
	cin >> x >> y;

	vector<int> ans{};
	for (int i{y}; i <= x; ++i) ans.push_back(i);
	for (int i{x - 1}; i > y; --i) ans.push_back(i);

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
