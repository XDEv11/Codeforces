#include <bits/stdc++.h>
#define MP make_pair
#define F first
#define S second
typedef long long ll;
using namespace std;
typedef pair<ll, ll> pll;

ll mx[200000];

pll a[200000], eye, v[200000];

pll operator-(const pll &a, const pll &b){
	return MP(a.F - b.F, a.S - b.S);
}

pll operator*(const pll &a, const ll &b){
	return MP(a.F * b, a.S * b);
}

pll operator/(const pll &a, const ll &b){
	return MP(a.F / b, a.S / b);
}

ll cross(const pll &a, const pll &b){
	return a.F * b.S - a.S * b.F;
}

pll intersect(const pll &p1, const pll &p2, const pll &p3, const pll &p4){
	ll a123 = cross(p2 - p1, p3 - p1);
	ll a124 = cross(p2 - p1, p4 - p1);
	return (p4 * a123 - p3 * a124) / (a123 - a124);
}

int main() {
	ll n, h;
	cin >> n >> h;
	for(int i = 0; i < n; i++)
		cin >> a[i].F >> a[i].S;
	eye = MP(a[n - 1].F, a[n - 1].S + h);
	for(int i = 0; i < n; i++)
		v[i] = eye - a[i];
	mx[n - 1] = n - 1;
	for(int i = n - 2; i >= 0; i--)
		if(cross(v[i], v[mx[i + 1]]) >= 0)
			mx[i] = i;
		else
			mx[i] = mx[i + 1];
	for(int i = 0; i < n; i++){
		int idx = mx[i + 1];
		if(i + 1 != idx && a[i].S != a[idx].S && )		
	}
}
