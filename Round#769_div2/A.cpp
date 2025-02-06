//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<char> v(n);
	for (auto& x : v) cin >> x;

	if (v.size() == 1 || (v.size() == 2 && v[0] != v[1])) cout << "YES\n"s;
	else cout << "NO\n"s;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
