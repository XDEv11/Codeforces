#pragma GCC optimize ("O3")

#include <iostream>
#include <string>

using namespace std;

void solve() {
	string s;
	cin >> s;

	if ((s.back() - '0') % 2 == 0) cout << "0\n"s;
	else if ((s.front() - '0') % 2 == 0) cout << "1\n"s;
	else {
		bool f{false};
		for (auto& c : s) f = f || ((c - '0') % 2 == 0);
		cout << (f ? 2 : -1) << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
