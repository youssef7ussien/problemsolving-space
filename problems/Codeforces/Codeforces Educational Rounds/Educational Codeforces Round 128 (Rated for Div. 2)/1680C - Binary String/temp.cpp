// Author : Epsilon573
// If it works, don't touch it.

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

const ll mod  = 1e9+7;
const ld eps  = 1e-9 ;
const ll maxn = 1e5+1;
const ll inf  = 5e18 ;
const ll minf = -inf ;

#define mp make_pair
#define pb push_back
#define endl "\n"

bool solve()
{
    string s;
    cin >> s;
    ll n = s.size();

    ll ans = 0, cnt = 0;

    ll ones = count(s.begin(),s.end(),'1');
    ll zeroes = count(s.begin(),s.end(),'0');

    vector<ll> pref_zeroes,suff_zeroes;

    for(ll i=0 ; i<n ; ++i){
        if(s[i]=='0'){
            cnt++;
        }
        else{
            pref_zeroes.pb(cnt);
        }
    }

    pref_zeroes.pb(cnt);
    cnt = 0;

    for(ll i=n-1 ; i>0 ; --i){
        if(s[i]=='0'){
            cnt++;
        }
        else{
            suff_zeroes.pb(cnt);
        }
    }

    suff_zeroes.pb(cnt);
    // for(auto &it : pref_zeroes)
    //   cout<<it<<" ";
    // cout<<"\n";
    // for(auto &it : suff_zeroes)
    //   cout<<it<<" ";
    // cout<<"\n";
    ll low = 0, high = ones;
    while(low<=high){
        ll mid = (low+high)/2;

        ll is_possible = 0;

        for(ll i=0 ; i<=mid ; ++i){
            ll left = zeroes;
            
            // ones used in prefix
            left -= pref_zeroes[i];

            // ones used in suffix
            left -= suff_zeroes[mid-i];
            
            if(left<=mid){
                is_possible = 1;
                break;
            }
        }

        if(is_possible){
            ans = mid;
            high = mid-1;
        }
        else
            low = mid+1;
    }

    cout << ans << endl;
    return true;    
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifdef EPSILON
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
    #endif

    ll t=1;
    cin >> t;

    while(t--)
    {
        if(solve())
        {
            // cout << "YES" << endl;
        }
        else
        {
            // cout << "NO" << endl;
        }
    }

    return 0;
} 