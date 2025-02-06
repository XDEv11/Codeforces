//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <set>
#include <utility>
#define fi first
#define se second
#include <tuple>
#include <iterator>
#include <algorithm>

using namespace std;

bool solve() {
	int q;
	if (!(cin >> q)) return false;

	set<pair<int, int>> st2{}, st3{};
	for (int i{0}; q--; ) {
		int t, m, a, b;
		cin >> t;
		switch (t) {
			break; case 1:
				cin >> m, ++i;
				st2.emplace(i, m), st3.emplace(-m, i);
			break; case 2:
				tie(a, b) = *st2.begin();
				st2.erase(st2.begin()), st3.erase({-b, a});
				cout << a << ' ';
			break; case 3:
				tie(a, b) = *st3.begin();
				st3.erase(st3.begin()), st2.erase({b, -a});
				cout << b << ' ';
		}
	}
	return cout << '\n', true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (solve()) ;
}
