//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> v(n);
	for (auto& [l, r] : v) cin >> l >> r;

	bool fl{false}, fr{false};
	for (auto& [l, r] : v) {
		if (l == k) fl = true;
		if (r == k) fr = true;
	}

	cout << (fl && fr ? "YES\n" : "NO\n");
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
