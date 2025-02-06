#include <iostream>
#include <vector>

using namespace std;

void solve() {
	string s;
	cin >> s;

	bool zero{false}, one{false};
	for (auto& x : s) {
		if (x == '0') zero = true;
		else if (x == '1') one = true;
	}

	if (!zero) cout << "0\n"s;
	else if (!one) cout << "1\n"s;
	else {
		int cnt{0};
		for (int i{0}; i < s.size(); ++i)
			if (s[i] == '0' && (i + 1 == s.size() || s[i + 1] != '0')) ++cnt;
		cout << min(cnt, 2) << '\n';
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
