//#pragma GCC optimize ("O3")

#include <iostream>
#include <string>
#include <list>
#include <algorithm>

using namespace std;

void solve() {
	string s{};
	cin >> s;
	int n{s.size()};
	long long p;
	cin >> p, --p;

	list<char> lst{};
	for (int i{0}; i < n; ++i) lst.push_back(s[i]);

	vector<bool> d(n);
	auto it{lst.begin()};
	for (int i{0}; ; ++i) {
		if (p < n - i) {
			it = lst.begin();
			while (p--) ++it;
			cout << (*it);
			return ;
		}
		if (i == n - 1) break;
		while (next(it) != lst.end() && *it <= *next(it)) ++it;
		auto pv{it == lst.begin() ? next(it) : prev(it)}; lst.erase(it), it = pv;
		p -= n - i;
	}
	cout << '$';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
