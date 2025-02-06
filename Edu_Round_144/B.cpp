//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <string>
#include <set>

using namespace std;

void solve() {
	string a{}, b{};
	cin >> a >> b;

	if (a.front() == b.front()) return cout << "YES\n" << a.front() << "*\n", []{}();
	else if (a.back() == b.back()) return cout << "YES\n" << '*' << a.back() << '\n', []{}();

	set<string> st{};
	for (int i{0}; i + 1 < a.size(); ++i) st.emplace(string{a[i], a[i + 1]});
	for (int i{0}; i + 1 < b.size(); ++i) {
		if (st.count({b[i], b[i + 1]})) return cout << "YES\n" << '*' << b[i] << b[i + 1] << "*\n", []{}();
	}
	cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
