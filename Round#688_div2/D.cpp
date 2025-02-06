#include <iostream>
#include <vector>

using namespace std;

void solve() {
	long long k;
	cin >> k;
	if (k & 1) {
		cout << "-1\n";
		return ;
	}

	vector<int> ans{};
	while (k > 0) {
		int i{1};
		while (k >= (1ll << (i + 1)) - 2) ++i;
		k -= (1ll << i) - 2;

		ans.push_back(1);
		for (int j{2}; j < i; ++j) ans.push_back(0);
	}

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

	return 0;
}
