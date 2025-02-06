//#pragma GCC optimize ("O3")

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
	int m;
	cin >> m;
	string s{};
	cin >> s;
	int n{s.size()};

	string r{s};
	reverse(r.begin(), r.end());

	cout << (s <= r ? s : (r + s)) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
