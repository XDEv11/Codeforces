#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool solve() {
	int n, k;
	if (!(cin >> n >> k)) return false;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	while (k--) {
		map<int, int> mp{};
		for (auto& x : v) ++mp[x];
		bool f{false};
		for (auto& x : v) {
			int y{mp[x]};
			if (x != y) f = true, x = y;
		}
		if (!f) break;
	}

	for (auto& x : v) cout << x << ' ';
	cout << '\n';
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (solve()) ;
}
