//#pragma GCC optimize ("O3")

#include <iostream>
#include <string>
#include <array>
#include <algorithm>

using namespace std;

bool solve() {
	array<bool, 26> ck{};
	for (int _{0}; _ < 3; ++_) {
		string s{};
		if (!(cin >> s)) return false;
		for (auto& c : s) {
			if (c == '*') continue;
			ck[c - 'A'] = true;
		}
	}

	int q;
	cin >> q;
	while (q--) {
		string s{};
		cin >> s;
		array<bool, 26> a{}; a.fill(true);
		for (auto& c : s) a[c - 'A'] = false;
		if (a != ck) cout << "IM";
		cout << "POSSIBLE\n";
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (solve()) ;
}
