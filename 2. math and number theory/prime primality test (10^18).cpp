#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <utility>
#include <random>
#include <chrono>
using namespace std;

#define forn(i,n) for (int i=0;i<(int)(n);i++)
#define dforn(i,n) for(int i=(int)((n)-1);i>=0;i--)
typedef long long tint;
typedef tint tipo;
#define BASEXP 6
#define BASE 1000000
#define LMAX 200   // Needs to be varied acording to the size of the numbers to be tested. LMAX = 200 works fine for 300 digit primes

struct Long {
	int l;
	tipo n[LMAX];
	Long(tipo x) { l = 0; forn(i, LMAX) { n[i]=x%BASE; l+=!!x||!i; x/=BASE;} }
	Long(){*this = Long(0);}
	Long(string x) {
		l=(x.size()-1)/BASEXP+1;
		fill(n, n+LMAX, 0);
		tipo r=1;
		forn(i, x.size()){
			n[i / BASEXP] += r * (x[x.size()-1-i]-'0');
			r*=10; if(r==BASE)r=1;
		}
	}
};
void out(Long& a) {

	char msg[BASEXP+1];
	cout << a.n[a.l-1];
	dforn(i, a.l-1) {
		sprintf(msg, "%6.6llu", a.n[i]); cout << msg; // 6 = BASEXP!
	}
	cout << endl;
}
void invar(Long &a) {
	fill(a.n+a.l, a.n+LMAX, 0);
	while(a.l>1 && !a.n[a.l-1]) a.l--;
}
void lsuma(const Long&a, const Long&b, Long &c) { // c = a + b
	c.l = max(a.l, b.l);
	tipo q = 0;
	forn(i, c.l) q += a.n[i]+b.n[i], c.n[i]=q%BASE, q/=BASE;
	if(q) c.n[c.l++] = q;
	invar(c);
}
Long& operator+= (Long&a, const Long&b) { lsuma(a, b, a); return a; }
Long operator + (const Long&a, const Long&b) { Long c; lsuma(a, b, c); return c;}
bool lresta(const Long&a, const Long&b, Long&c) { // c = a - b
	c.l = max(a.l, b.l);
	tipo q = 0;
	forn(i, c.l) q += a.n[i] - b.n[i], c.n[i]=(q+BASE)%BASE, q=(q+BASE)/BASE-1;
	invar(c);
	return !q;
}
Long& operator-= (Long&a, const Long&b) { lresta(a, b, a); return a;}
Long operator- (const Long&a, const Long&b) {Long c; lresta(a, b, c); return c;}
bool operator< (const Long&a, const Long&b) { Long c; return !lresta(a, b, c); }
bool operator<= (const Long&a, const Long&b) { Long c; return lresta(b, a, c); }
bool operator== (const Long&a, const Long&b) { return a <= b && b <= a; }
void lmul(const Long&a, const Long&b, Long&c) { // c = a * b
	c.l = a.l+b.l;
	fill(c.n, c.n+c.l, 0);
	forn(i, a.l) {
		tipo q = 0;
		forn(j, b.l) q += a.n[i]*b.n[j]+c.n[i+j], c.n[i+j] = q%BASE, q/=BASE;
		c.n[i+b.l] = q;
	}
	invar(c);
}
Long& operator*= (Long&a, const Long&b) { Long c; lmul(a, b, c); return a=c; }
Long operator* (const Long&a, const Long&b) { Long c; lmul(a, b, c); return c; }
void lmul (const Long&a, tipo b, Long&c) { // c = a * b
	tipo q = 0;
	forn(i, a.l) q+= a.n[i]*b, c.n[i] = q%BASE, q/=BASE;
	c.l = a.l;
	while(q) c.n[c.l++] = q%BASE, q/=BASE;
	invar(c);
}
Long& operator*= (Long&a, tipo b) { lmul(a, b, a); return a; }
Long operator* (const Long&a, tipo b) { Long c = a; c*=b; return c; }
void ldiv(const Long& a, tipo b, Long& c, tipo& rm) { // c = a / b; rm = a % b
	rm = 0;
	dforn(i, a.l) {
		rm = rm * BASE + a.n[i];
		c.n[i] = rm / b; rm %= b;
	}
	c.l = a.l;
	invar(c);
}
Long operator/ (const Long&a, tipo b) { Long c; tipo r; ldiv(a, b, c, r); return c;}
Long operator% (const Long&a, tipo b) { Long c; tipo r; ldiv(a, b, c, r); return r;}
void ldiv(const Long& a, const Long& b, Long& c, Long& rm) { // c = a / b; rm = a % b
	rm = 0;
	dforn(i, a.l) {
		if (rm.l == 1 && rm.n[0] == 0) {
			rm.n[0] = a.n[i];
		}
		else {
			dforn(j, rm.l) rm.n[j+1] = rm.n[j];
			rm.n[0] = a.n[i]; rm.l++;
		}
		tipo q = rm.n[b.l] * BASE + rm.n[b.l-1];
		tipo u = q / (b.n[b.l-1] + 1);
		tipo v = q / b.n[b.l-1] + 1;
		while (u < v-1) {
			tipo m = (u+v)/2;
			if (b*m <= rm) u=m; else v = m;
		}
		c.n[i] = u;
		rm -= b*u;
	}
	c.l = a.l;
	invar(c);
}
Long operator/ (const Long&a, const Long& b) { Long c,r; ldiv(a, b, c, r); return c;}
Long operator% (const Long&a, const Long& b) { Long c,r; ldiv(a, b, c, r); return r;}

typedef Long ll;

ll gcd (ll a, ll b) { // Computes the greatest common divisor using Euclid's algorithm
	ll t;
	while (!(b == 0)) {
		t = b;
		b = a % b;
		a = t;
	}
	return a;
}

ll modexp(ll a, ll b, ll n) { // Performs modular exponentiation by repeated squaring
	ll c = 1;
	while (!(b <= 1)) {
		if (b % 2 == 0) {
			a *= a;
			a = a % n;
			b = b / 2;
		}
		else {
			c = c * a;
			c = c % n;
			b = b - 1;
		}
	}
	return (a * c) % n;
}

bool isprime (ll n, int rounds) { // Does 'rounds' iterations of Rabin-Miller primality test
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	mt19937 g1 (seed);
	uniform_int_distribution<tipo> distribution(0, BASE-1);
	vector <ll> bases(rounds);
	for (int c = 0; c < rounds; c++) {
		bases[c].l = n.l;
		forn(i, n.l) {
			bases[c].n[i] = distribution(g1);
		}
		invar(bases[c]);
		if (n <= bases[c]) c--;
	}
	if (n == 2) return true;
	if (n == 1 || n % 2 == 0) return false;
	ll d, x, b;
	tipo k;
	tipo s = 0;
	d = n - 1;
	while (d % 2 == 0) {
		s = s + 1;
		d = d / 2;
	}
	for (int c = 0; c < rounds; c++) {
		b = bases[c];
		if (n <= b) continue;
		if (!(gcd(b,n) == 1)) {
			if (b == n) continue;
			else return false;
		}
		x = modexp(b,d,n);
		if ((x == 1) || (x == n -1)) continue;
		for(k = 1; k < s; k++) {
			x = (x*x) % n;
			if (x == n-1) break;
			if (x == 1) return false;
		}
		if (k == s) return false;
		if (s == 1 && !(x == n - 1)) return false;
	}
	return true;
}
bool isPrime(char c)
{
    return (c == '2' || c == '3' || c == '5' || c == '7');
}
void decrease(string& s, tint i)
{
    if (s[i] <= '2') {
        s.erase(i, 1);
        s[i] = '7';
    }

    else if (s[i] == '3')
        s[i] = '2';
    else if (s[i] <= '5')
        s[i] = '3';
    else if (s[i] <= '7')
        s[i] = '5';
    else
        s[i] = '7';

    return;
}

string primeDigits(string s)
{
    for (tint i = 0; i < s.length(); i++) {
        if (!isPrime(s[i])) {
            while (s[i] <= '2' && i >= 0)
                i--;
            if (i < 0) {
                i = 0;
                decrease(s, i);
            }
            else
                decrease(s, i);
            for (tint j = i + 1; j < s.length(); j++)
                s[j] = '7';

            break;
        }
    }

    return s;
}
int main() { // It reads input from stdin, first the ammount of numbers to be tested and then the numbers
	int t;
	string s;
	int cas=1;
	//cin >> s;
	s="1000000000000000000";
	while(cas<=1000) {
		while(1){
			s=primeDigits(s);
			ll N(s);
			if (isprime(N, 3)){
				cout<<"Case "<<cas<<": "<<s<<endl;
                        tint l=s.size();
                        s[l-1]-=('2'-'1');
                        cas++;
                        break;
			}
			tint l=s.size();
            s[l-1]-=('2'-'1');

		}
	}
	return 0;
}
