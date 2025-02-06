//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> v(n);
	for (int i{0}; i < n; ++i) {
		int k;
		cin >> k;
		v[i].resize(k);
		for (auto& x : v[i]) cin >> x;
	}

	map<int, int> mp{};
	for (int i{0}; i < n; ++i) {
		for (auto& x : v[i]) ++mp[x];
	}

	for (int i{0}; i < n; ++i) {
		bool flag{true};
		for (auto& x : v[i]) flag = flag && mp[x] > 1; 
		if (flag) return cout << "Yes\n", []{}();
	}
	cout << "No\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
