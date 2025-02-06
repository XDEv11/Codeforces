//#pragma GCC optimize ("O3")

#include <iostream>
#include <string>

using namespace std;

static void solve() {
	string s{};
	cin >> s;
	int n{s.size()};

	if (s[0] != '1') return cout << "NO\n", []{}();
	if (s[n - 1] == '9') return cout << "NO\n", []{}();
	for (int i{1}; i < n - 1; ++i) {
		if (s[i] == '0') return cout << "NO\n", []{}();
	}
	cout << "YES\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
