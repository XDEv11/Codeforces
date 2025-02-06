//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <set>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	set<int> s{};
	for (int i{0}; i < n; ++i) {
		int x;
		cin >> x;
		s.insert(x);
	}

	for (auto& x : s)
		if (s.count(x - k)) return cout << "YES\n", []{}();
	cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
