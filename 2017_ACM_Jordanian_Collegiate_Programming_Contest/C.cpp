//#pragma GCC optimize ("O3")

#include <iostream>
#include <fstream>
#include <array>
#include <algorithm>

using namespace std;

void solve(ifstream& fin) {
	int k;
	fin >> k;
	array<bool, 13> s{};
	while (k--) {
		char c;
		fin >> c;
		s[c - 'A'] = true;
	}
	array<int, 13> c;
	for (auto& x : c) fin >> x;

	int mx{-1}, ans;
	for (int i{0}; i < 13; ++i) {
		if (s[i]) continue;
		if (c[i] > mx) mx = c[i], ans = i;
	}

	cout << char('A' + ans) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	ifstream fin{"scoreboard.in"};
	
	int t{1};
	fin >> t;
	while (t--) solve(fin);
}
