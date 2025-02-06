#include <iostream>
#include <vector>
#include <string>
#include <map>
#define fi first
#define se second

using namespace std;

bool solve() {
	int n;
	if (!(cin >> n)) return false;
	vector<string> v(n);
	for (auto& x : v) cin >> x;

	int m;
	cin >> m;
	map<string, vector<string>> mp1{}, mp0{};
	while (m--) {
		string a, b, c;
		cin >> a >> b >> c;
		if (c == "correct") mp1[a].push_back(b);
		else mp0[a].push_back(b);
	}

	bool f{true};
	for (auto& x : v) {
		auto it1{mp1.find(x)}, it2{mp0.find(x)};
		if ((it1 == mp1.end() ? 0 : it1->se.size()) + (it2 == mp0.end() ? 0 : it2->se.size()) > 1) {
			f = false;
			break;
		}
	}
	if (f) {
		bool ans{true};
		for (auto& x : v) {
			auto it1{mp1.find(x)}, it2{mp0.find(x)};
			if (it1 != mp1.end()) cout << (it1->se[0]) << ' ';
			else cout << (it2->se[0]) << ' ', ans = false;
		}
		cout << '\n';
		if (!ans) cout << "in";
		cout << "correct\n";
		return true;
	}

	using ll = long long;
	ll ans1{1}, ans2{1};
	for (auto& x : v) {
		auto it1{mp1.find(x)}, it2{mp0.find(x)};
		ll c1{it1 == mp1.end() ? 0 : it1->se.size()}, c2{c1 + (it2 == mp0.end() ? 0 : it2->se.size())};
		ans1 *= c1, ans2 *= c2;
	}
	ans2 -= ans1;

	cout << ans1 << " correct\n" << ans2 << " incorrect\n";
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (solve()) ;
}
