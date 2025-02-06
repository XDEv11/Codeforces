//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

using ll = long long;

class trie {
	struct node {
		ll cnt1{}, cnt2{};
		map<char, int> nxt{};
	};
public:
	vector<node> t;
	explicit trie() : t(1) {}
	void add(const string& s) {
		int p{0};
		++t[p].cnt1, t[p].cnt2 += s.size();
		for (int i{0}; i < s.size(); ++i) {
			char c{s[i]};
			if (!t[p].nxt[c]) t[p].nxt[c] = t.size(), t.emplace_back();
			p = t[p].nxt[c];
			++t[p].cnt1, t[p].cnt2 += s.size() - (i + 1);
		}
	}
	ll cal(const string& s) {
		ll ans{};
		int p{0}, q;
		for (int i{0}; p != -1 && i < s.size(); ++i) {
			char c{s[i]};
			if (t[p].nxt.count(c)) {
				q = t[p].nxt[c];
				ans += (t[p].cnt1 - t[q].cnt1) * (s.size() - i) + t[p].cnt2 - (t[q].cnt1 + t[q].cnt2);
				p = q;
			} else {
				ans += t[p].cnt1 * (s.size() - i) + t[p].cnt2;
				p = -1;
			}
		}
		if (p != -1) ans += t[p].cnt2;
		return ans;
	}
};

bool solve() {
	int n;
	if (!(cin >> n)) return false;
	vector<string> v(n);
	for (auto& x : v) cin >> x;

	trie t{};
	for (auto& x : v) t.add(x);

	ll ans{};
	for (auto& x : v) reverse(x.begin(), x.end()), ans += t.cal(x);

	cout << ans << '\n';
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (solve()) ;
}
