//#pragma GCC optimize ("O3")

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
	string l{}, r{};
	cin >> l >> r;
	reverse(l.begin(), l.end()), reverse(r.begin(), r.end());
	while (l.size() < r.size()) l += '0';
	int n{l.size()};

	for (int i{n - 1}; i >= 0; --i) {
		if (l[i] == r[i]) continue;
		cout << (r[i] - l[i] + i * 9) << '\n';
		return ;
	}
	cout << "0\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
