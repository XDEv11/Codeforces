//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>

using namespace std;

static void solve() {
	int n, k;
	cin >> n >> k;

	vector<int> ans{};
	if (k > 1) { // 1 ~ (k-1)
		ans.push_back(1); int c{1};
		while (true) {
			if (2 * c + 1 >= k) {
				if (c < k - 1) ans.push_back(k - 1 - c);
				break;
			} else ans.push_back(c + 1), c = 2 * c + 1;
		}
	}
	ans.push_back(k + 1); // (k+1) ~ 2k
	ans.push_back(2 * k + 1), ans.push_back(3 * k + 1); // (2k+1) ~ (6k)
	int c{5 * k};
	while (c < n - k) ans.push_back(c), c = 2 * c;

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
