//#pragma GCC optimize ("O3")

#include <iostream>
#include <string>
#include <array>
#include <algorithm>

using namespace std;

void solve() {
	string a{}, b{};
	cin >> a >> b;

	array<int, 26> cnt{};
	for (auto& x : b) ++cnt[x - 'a'];

	for (int i{0}; i < a.size(); ++i) {
		if (!cnt[a[i] - 'a']--) return cout << i << '\n', []{}();
	}
	cout << a.size() << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
