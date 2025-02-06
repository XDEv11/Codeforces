//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

void solve() {
	int n;
	string s{};
	cin >> n >> s;

	set<string> ss{};
	for (int i{1}; i + 1 < n; ++i) {
		if (ss.count(s.substr(i, 2))) return cout << "YES\n", []{}();
		ss.insert(s.substr(i - 1, 2));
	}
	cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
