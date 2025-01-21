#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define endl "\n"

ll binpow(ll a, ll b, ll m)
{
    ll resp = 1;
    a %= m;

    while (b > 0)
    {
        if (b & 1)
            resp = ((long long)resp * (long long)a) % m;
        resp %= m;
        a = ((long long)a * (long long)a) % m;
        a %= m;
        b /= 2;
    }
    return resp;
}
#define mod 1000000007
const ll MAXM = 5e6 + 10;
ll fact[MAXM];
ll factInv[MAXM];
ll inverso[MAXM];
ll inv(ll a, ll p)
{
    return binpow(a, p - 2, p);
}

ll nCk(ll n, ll k, ll p)
{
    if (n<0 || k<0) return 0LL;
		if (n < k) return 0LL;
		return fact[n]*factInv[n-k] % mod * factInv[k] % mod;
}

void solve()
{
    ll k, s, t;
    cin >> k >> s >> t;
    ll nBlocos = k / t;
    ll divisoria = k % t;

    ll resp = 0;
    // cout << nBlocos << " " << divisoria << endl;

    if (divisoria == 0)
    {
        if (s % nBlocos != 0 or s / nBlocos - 1 < 0 or s / nBlocos - t < 0)
        {
            cout << 0 << endl;
            return;
        }

        cout << nCk(s / nBlocos - 1, s / nBlocos - t, mod) << endl;
        return;
    }

    for (ll somaPrimeiraDivisoria = divisoria; somaPrimeiraDivisoria <= (s + nBlocos - 1) / nBlocos; somaPrimeiraDivisoria++)
    {
        ll somaSegunda;

        // cout << somaPrimeiraDivisoria << " " << (s - (nBlocos + 1) * somaPrimeiraDivisoria) << endl;

        if ((s - (nBlocos + 1) * somaPrimeiraDivisoria) / nBlocos < 0)
            break;

        if ((s - (nBlocos + 1) * somaPrimeiraDivisoria) % nBlocos != 0)
            continue;

        // cout << "aqui\n";
        somaSegunda = (s - (nBlocos + 1) * somaPrimeiraDivisoria) / nBlocos;

        // cout << somaPrimeiraDivisoria << " " << somaSegunda << " " << somaPrimeiraDivisoria * (nBlocos + 1) + somaSegunda * nBlocos << endl;

        if (somaSegunda < 0 or (somaPrimeiraDivisoria * (nBlocos + 1) + somaSegunda * nBlocos != s))
            continue;

        // cout << "calculou a combinacao " << endl;
        // cout << divisoria << " - " << somaPrimeiraDivisoria << " " << nCk(somaPrimeiraDivisoria - 1, somaPrimeiraDivisoria - divisoria, mod) << endl;
        // cout << somaSegunda << " " << t - divisoria << " --- " << nCk(somaSegunda - 1, somaSegunda - (t - divisoria), mod) << endl;

        if (somaSegunda - 1 < 0 or somaSegunda - (t - divisoria) < 0)
            continue;

        if (!divisoria)
            resp += nCk(somaSegunda - 1, somaSegunda - (t - divisoria), mod);

        if (somaSegunda - (t - divisoria) < 0 or somaSegunda - 1 < 0 or somaPrimeiraDivisoria - 1 < 0 or somaPrimeiraDivisoria - divisoria < 0)
            continue;

        if (divisoria)
            resp += (long long)(nCk(somaPrimeiraDivisoria - 1, somaPrimeiraDivisoria - divisoria, mod) * (long long)nCk(somaSegunda - 1, somaSegunda - (t - divisoria), mod)) % mod;

        resp %= mod;
    }
    cout << resp << endl;
}
int main()
{
    optimize;
    
    inverso[1] = 1;
    for (int i =2; i<MAXM; i++){
        inverso[i] = mod - (mod/i) * inverso[mod%i]%mod;
    }

    fact[0] = 1;
    factInv[0] = 1;

    for (int i = 1; i < MAXM; i++)
    {
        fact[i] = ((long long)fact[i - 1] * (long long)i) % mod;
        factInv[i] = factInv[i-1]*inverso[i] % mod;
    }

    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
}