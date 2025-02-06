//#pragma GCC optimize ("O3")

#include <iostream>
#include <string>

using namespace std;

void solve() {
	string s{};
	cin >> s;
	int n{s.size()};

	char f{'0'};
	for (auto& x : s) {
		if (x == '?') continue;
		f = x;
		break;
	}
	for (auto& x : s) {
		if (x == '?') x = f;
		f = x;
	}

	cout << s << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
