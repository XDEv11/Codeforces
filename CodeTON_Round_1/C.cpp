//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	set<int> s{};
	for (int i{0}; i < n; ++i) {
		int x;
		cin >> x;
		s.insert(x);
	}

	bool z{s.count(0)}, o{s.count(1)};
	if (z && o) cout << "NO\n";
	else if (o) {
		for (auto it{s.begin()}; next(it) != s.end(); it = next(it))
			if (*it + 1 == *next(it)) return cout << "NO\n", []{}();
		cout << "YES\n";
	} else cout << "YES\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
