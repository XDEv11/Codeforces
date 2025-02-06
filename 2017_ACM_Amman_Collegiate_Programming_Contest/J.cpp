//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>

using namespace std;

vector<int> pf{[] {
	int maxval{100001};
	vector<int> v(maxval + 1);
	for (long long i{2}; i <= maxval; ++i) {
		if (v[i]) continue;
		v[i] = i;
		for (long long j{i * i}; j <= maxval; j += i) v[j] = i;
	}
	return v;
}()};

void solve() {
	string s{};
	getline(cin, s);
	s += ' ';

	int x{s.size()};
	while (x > 1) {
		bool f{true};
		int y{pf[x]}, z{s.size() / y};
		while (x % y == 0) x /= y;
		for (int i{z - 1}; i < s.size(); i += z) {
			if (s[i] == ' ') continue;
			f = false;
			break;
		}
		if (f) return cout << "YES\n", []{}();
	}
	cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	(cin >> t).ignore(numeric_limits<std::streamsize>::max(), '\n');
	while (t--) solve();
}
