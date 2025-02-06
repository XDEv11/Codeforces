//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <optional>
#include <algorithm>
#include <string>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v{};
	vector<optional<int>> p(n + 1, nullopt);
	for (int i{0}; i < n; ++i) {
		int x;
		cin >> x;
		if (x <= n && !p[x]) p[x] = x;
		else v.push_back(x);
	}
	sort(v.begin(), v.end());

	int i{1};
	for (auto& x : v) {
		while (p[i]) ++i;
		p[i] = x;
	}

	int ans{0};	
	for (int i{1}; i <= n; ++i) {
		if (p[i] == i) continue;

		if (p[i] < i * 2 + 1) return cout << "-1\n"s, []{}();
		++ans;
	}
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
