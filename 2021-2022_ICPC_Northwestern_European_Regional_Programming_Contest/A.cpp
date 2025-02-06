//#pragma GCC optimize ("O3")

#include <iostream>
#include <string>
#include <array>
#include <algorithm>

using namespace std;

const array<int, 62> ch{[] {
	array<int, 62> a;
	for (int i{0}; i < 26; ++i) a[i] = 'a' + i;
	for (int i{0}; i < 26; ++i) a[26 + i] = 'A' + i;
	for (int i{0}; i < 10; ++i) a[52 + i] = '0' + i;
	return a;
}()};

int interact(const string& s) {
	cout << s << endl;

	string t1; char t2;
	cin >> t1 >> t1;
	if (t1 == "GRANTED") return -1;
	int r;
	cin >> t2 >> r >> t1;
	return r;
}

void solve() {
	string s{};

	int len;
	for (len = 1; ; ++len) {
		s += ch[0];
		int r{interact(s)};
		if (r == -1) return ;
		else if (r > 5) break;
	}

	for (int i{0}; i < len; ++i)
		for (int j{0}; j < ch.size(); ++j) {
			s[i] = ch[j];
			int r{interact(s)};
			if (r == -1) return ;
			else if (r > 5 + (i + 1) * 9) break;
		}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}
