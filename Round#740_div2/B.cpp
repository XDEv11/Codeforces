#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int a, b, n;
	cin >> a >> b, n = a + b;
	if (a < b) swap(a, b);

	vector<int> ans{};
	if (n & 1) {
		for (int ah{(n + 1) / 2}, ab{a - (n + 1) / 2}; ab <= n / 2; ++ab, --ah)
			ans.push_back((n + 1) / 2 - ah + ab);
		for (int ah{n / 2}, ab{a - n / 2}; ab <= (n + 1) / 2; ++ab, --ah)
			ans.push_back(n / 2 - ah + ab);
		sort(ans.begin(), ans.end());
	} else {
		for (int ah{n / 2}, ab{a - n / 2}; ab <= n / 2; ++ab, --ah)
			ans.push_back(n / 2 - ah + ab);
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
