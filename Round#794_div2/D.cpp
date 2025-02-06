//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int n{a + b + 2 * c + 2 * d};
	vector<char> v(n);
	for (auto& x : v) cin >> x;

	for (auto& x : v) cout << x;
	cout << endl; //
	cout << count(v.begin(), v.end(), 'A') << endl; //
	if (count(v.begin(), v.end(), 'A') != a + c + d) return cout << "NO\n", []{}();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
