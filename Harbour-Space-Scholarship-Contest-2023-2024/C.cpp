//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int x;
	cin >> x;

	vector<int> ans{};
	ans.push_back(x);
	for (int b{0}; (1 << b) < x; ++b) {
		if (!(x & (1 << b))) continue;
		x -= (1 << b);
		ans.push_back(x);
	}
	while (x > 1) {
		x /= 2;
		ans.push_back(x);
	}

	cout << ans.size() << '\n';
	for (auto& e : ans) cout << e << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
