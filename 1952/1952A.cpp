
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "../debugICPC.h"
#define chk(...) if (!(__VA_ARGS__)) cerr << "\033[41m" << "Line(" << __LINE__ << ") -> function(" \
	 << __FUNCTION__  << ") -> CHK FAILED: (" << #__VA_ARGS__ << ")" << "\033[0m" << "\n", exit(0);

#define MACRO(code) do {code} while (false)
#define RAYA MACRO(cerr << "\033[101m" << "================================" << "\033[0m" << endl;)
#else
#define dbg(...)

#define chk(...)
#define RAYA
#endif


using ll  = long long;
using str = string;      // yay python!

#define tcT template <class T
#define tcTU tcT, class U
//! ^ lol this makes everything look weird but I'll try it
tcT > using V = vector<T>;
tcT, size_t SZ > using AR = array<T, SZ>;
using vi = V<int>;
using vb = V<bool>;
using vl = V<ll>;
// vectors
// oops size(x), rbegin(x), rend(x) need C++17
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define sor(x) sort(all(x))
#define rsz resize
#define ins insert
#define pb push_back
#define eb emplace_back
#define ft front()
#define bk back()
#define ts to_string
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define each(a,x) for (auto& a: x)
const int MOD = 1e9+7;
const ll BIG = 1e18;  

void solve() {
	//dding", "D.E. Shaw", "Publicis Sapient", "XTX Markets", "Centerview Partners", "Verily", "Uber", "Netflix", "Cohere", "Goldman Sachs", "PayPal", "Charles Schwab", "Yext", "Red Hat", "Intel", "Pinterest", "Egerton", "Airtable", "Bain & Company", "Capital One", "PwC", "Yelp", "Qualtrics", "BCG", "Samsung", "Notion", "Snap", "Docusign", "ExodusPoint", "Redfin", "KPMG", "Two Sigma", "Blue Origin", "Anduril", "Tableau", "McKinsey & Company", "Zillow", "Kayak", "NASA", "EY", "Ramp", "Accenture", "SpaceX", "Atlassian", "Bridgewater", "Blackrock", "Pine River Capital", "Millennium", "Rippling", "Farallon Capital", "Bank of America", "Lyft", "Canva", "Coinbase", "Renaissance Technologies", "Square", "JPMC", "Point72", "Akuna Capital", "Surveyor", "Barclays", "Elliott Management", "Square", "Meta"};
    vector<string> a={"Hugging Face", "Analysis Group", "Strategy&", "ByteDance", "Asana", "Dropbox", "Anthropic", "Bloomberg", "Robinhood", "Intuit", "Quora", "Flow Traders", "Deutsche Bank", "Hulu", "Postmates", "IBM", "Balyasny Asset Management", "Affirm", "Nuro", "Waymo", "LinkedIn", "Jane Street", "Arrowstreet Capital", "Radix Trading", "Snowflake", "Five Rings", "Amazon", "The Brattle Group", "X", "Booz Allen Hamilton", "GrubHub", "Riot Games", "Evercore", "Akuna Capital", "Deloitte", "Morgan Stanley", "Blackrock", "Tesla", "DoorDash", "ServiceNow", "Glean", "Salesforce", "Citadel", "MRG", "Instacart", "Nutanix", "Box", "Jump Trading", "Workday", "OC&C", "Squarepoint Capital", "Renaissance Technologies", "Lazard", "Walmart", "OpenAI", "ZS", "Splunk", "VMware", "J.P. Morgan", "Lockheed Martin", "Neuralink", "GitHub", "Radix Trading", "Baupost Group", "Etsy", "Reddit", "Davidson Kempner Capital Management", "Guggenheim Securities", "Moelis & Company", "Elastic", "Zoom", "Slack", "Samsara", "Addepar", "Bolt", "Datadog", "Cisco", "Flow Traders", "WTW", "Tanium", "Airbnb", "Figma", "Plaid", "Two Sigma", "Hudson River Trading", "Cloudflare", "Apple", "Morgan Stanley", "Citadel", "Hudson River Trading", "MongoDB", "Wish", "Optiver", "Palantir", "Five Rings", "Optiver", "Autodesk", "Okta", "Third Point Partners", "AlixPartners", "Scale AI", "D.E. Shaw", "Credit Suisse", "Nextdoor", "Microsoft", "Duolingo", "DRW", "Slalom", "SIG", "Alvarez & Marsal", "Peloton", "D.E. Shaw", "Nvidia", "Shopify", "Jump Trading", "Spotify", "Roblox", "Flexport", "Cruise", "Goldman Sachs", "Brex", "Expedia", "Google", "HubSpot", "Oliver Wyman", "AQR Capital Management", "Brevan Howard", "Indeed", "Capital One", "Kearney", "Oracle", "IMC Trading", "Deepmind", "Ebay", "Adobe", "Retool", "Blackstone", "Twilio", "Jane Street", "Databricks", "Discord", "Twitch", "L.E.K.", "IMC Trading", "D.E. Shaw", "Publicis Sapient", "XTX Markets", "Centerview Partners", "Verily", "Uber", "Netflix", "Cohere", "Goldman Sachs", "PayPal", "Charles Schwab", "Yext", "Red Hat", "Intel", "Pinterest", "Egerton", "Airtable", "Bain & Company", "Capital One", "PwC", "Yelp", "Qualtrics", "BCG", "Samsung", "Notion", "Snap", "Docusign", "ExodusPoint", "Redfin", "KPMG", "Two Sigma", "Blue Origin", "Anduril", "Tableau", "McKinsey & Company", "Zillow", "Kayak", "NASA", "EY", "Ramp", "Accenture", "SpaceX", "Atlassian", "Bridgewater", "Blackrock", "Pine River Capital", "Millennium", "Rippling", "Farallon Capital", "Bank of America", "Lyft", "Canva", "Coinbase", "Renaissance Technologies", "Square", "JPMC", "Point72", "Akuna Capital", "Surveyor", "Barclays", "Elliott Management", "Square", "Meta"};
    sor(a);
    map<str,ll> idx;
    map<str,ll> num;
    FOR(i,0,a.size()){
        str e=a[i];
        ll cont=0;
        for(auto & ele : e){
            if(ele>='A' && ele<='Z') cont++;
        }

        transform(e.begin(),e.end(), e.begin(),::toupper);
        num[e]=cont;
        idx[e]=i;
    }
    //dbg(idx);
    ll t;
    cin>>t;
    cin.ignore();
    FOR(it,0,t){
        str b;
        getline(cin, b);
        ll cont=0;
        for(auto & e : b){
            if(e>='A' && e<='Z') cont++;
        }
        transform(b.begin(), b.end(), b.begin(),::toupper);
        //dbg(b);
        if(!idx.count(b)){
            cout<<"-1\n";
        }
        else{
            ll ans=idx[b],pari=num[b];
            //if((cont+pari)%2==0)ans++;
            cout<<ans<<"\n";
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();  
}








