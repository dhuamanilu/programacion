#pragma GCC optimize ("Ofast")
//? #pragma GCC target ("avx,avx2")
//#pragma GCC optimize ("trapv")
#undef _GLIBCXX_DEBUG //? for Stress Testing
#include <bits/stdc++.h>
using namespace std;

//* Debugger
string to_string(string s) {
    return '"' + s + '"';
}

string to_string(const char* s) {
    return to_string((string) s);
}

string to_string(char c) {
    return string(1, c);
}

string to_string(bool b) {
    return (b ? "true" : "false");
}

template <typename A>
string to_string(A v);

template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "[";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "]";
    return res;
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#ifdef LOCAL
#define MACRO(code) do {code} while (false)
#define dbg(x)      {auto xd = x; cout << "Line(" << __LINE__ << "): " << "\033[1;34m" << #x << "\033[0;32m = \033[35m" << to_string(xd) << "\033[0m" << endl;}
#define dbg(...)    MACRO(cout << "Line(" << __LINE__ << "): " << "\033[1;34m" << "[" << #__VA_ARGS__ << "]\033[35m:"; debug_out(__VA_ARGS__); cout << "\033[0m";)

#define GA          dbg(0)
#define RAYA        cout << "\033[101m" << "================================" << "\033[0m" << endl;
#else
#define dbg(x)
#define dbg(...)
#define GA
#define RAYA
#endif
//* /Debugger

using ll = long long;
using db = long double; // or double if tight TL
using str = string;

using pi = pair<int,int>;
using pl = pair<ll, ll>;
#define mp make_pair
#define f first


#define tcT template<class T
tcT> using V = vector<T>;
tcT, size_t SZ> using AR = array<T,SZ>;
using vi = V<int>;
using vl = V<ll>;
using vb = V<bool>;
using vpi = V<pi>;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define rsz resize
#define pb push_back
#define ft front()
#define bk back()

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define rep(a) F0R(_,a)
#define each(a,x) for (auto& a: x)

const int MOD = 1e9+7;
const db PI = acos((db)-1);
mt19937 rng(0); // or mt19937_64
//* mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

tcT> bool ckmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0; } // set a = min(a,b)
tcT> bool ckmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0; } // set a = max(a,b)

void setIn(string s) { freopen(s.c_str(), "r", stdin); }
//? /Custom Helpers
//? Generator
int rng_int(int L, int R) { assert(L <= R);
	return uniform_int_distribution<int>(L,R)(rng);  }
ll rng_ll(ll L, ll R) { assert(L <= R);
	return uniform_int_distribution<ll>(L,R)(rng);  }

struct Thresholds {
    ll agent = -1, ip = -1, session = -1, crawl = -1, pdf = -1;
};
struct Info_per_day{
	set<string> agents;
    set<string> ips;
    ll pdfCount = 0;
    set<string> sessions;
    ll lastPdfNum = LONG_LONG_MIN;
	ll cur = 0,maxi = 0;
};

struct faltas{ 
	string id;
	string type; 
	ll value; 
};
void solve(){
    
	auto trim = [](string &s)->str{
		auto a = s.find_first_not_of(" \t\r\n");
		auto b = s.find_last_not_of(" \t\r\n");
		ll len = b - a + 1;
		return s.substr(a,len);
	};


	Thresholds lim;
	auto get_thresholds =[&](str & rules)->void{
		ll n = rules.size();
		string cur="";
		for(ll i = 0;i <= n; i++){
			if(i == n || (i < n && rules[i]==',')){
				auto pos = cur.find('=');
				str parte1 = cur.substr(0, pos);

				string key = trim(parte1);

				str parte2 = cur.substr(pos+1);
                string val = trim(parte2);
				ll x = stoll(val);

				if(key == "agent") lim.agent = x;
				else if (key == "ip") lim.ip = x;
                else if (key == "pdf") lim.pdf = x;
                else if (key == "session") lim.session = x;
                else if (key == "crawl") lim.crawl = x;
				cur = "";
				continue;
			}
			if(i < n && rules[i]!=' '){
				cur.push_back(rules[i]);
			}
		}
	};
	
	
	str rules;
	getline(cin,rules);
	get_thresholds(rules);
	dbg(lim.agent,lim.ip,lim.session,lim.crawl,lim.pdf);
	vl order;
	auto get_header = [&](str & header){
		ll n = header.size();
		string cur="";
		for(ll i = 0;i <= n; i++){
			if(i == n || (i < n && header[i]==',')){
				str act = trim(cur);
				dbg(act);
				if(act == "Host") order.push_back(0);
				else if (act == "ClientIP") order.push_back(1);
				else if (act == "Id") order.push_back(2);
				else if (act == "Date") order.push_back(3);
				else if (act == "Request") order.push_back(4);
				else if (act == "HTTPStatus") order.push_back(5);
				else if (act == "UserAgent") order.push_back(6);
				else if (act == "SessionCookie") order.push_back(7);
				cur = "";
				continue;
			}
			if(i < n && header[i]!=' '){
				cur.push_back(header[i]);
			}
		}
	};

	str header;
	getline(cin,header);
	get_header(header);

	string line;
	dbg(header);
	GA;
	map<string, map<string, Info_per_day>> bd;
	while(getline(cin,line)){
		ll ptr = 0;
		string host, ip, id, date_raw, request, ua, sess, status;
		ll n = line.size();
		auto read=[&](){
			//del primero
			while (ptr < n && line[ptr]==' '){
				ptr++;
			}
			ll start = ptr;
			while (ptr < n && line[ptr] != ' '){
				ptr++;
			}
			string out = line.substr(start, ptr - start);

			//dejar listo para el sgte
			while (ptr < n && line[ptr]==' '){
				ptr++;
			}
			return out;
		};
		dbg(order);
		for(auto & e: order){
			/*
				if(act == "Host") order.push_back(0);
				else if (act == "Client IP") order.push_back(1);
				else if (act == "Id") order.push_back(2);
				else if (act == "Date") order.push_back(3);
				else if (act == "Request") order.push_back(4);
				else if (act == "HTTP Status") order.push_back(5);
				else if (act == "User Agent") order.push_back(6);
				else if (act == "Session Cookie") order.push_back(7);
			
			*/
			auto read_esp = [&](char esp1,char esp2){
				//del primero
				while (ptr < n && (line[ptr]==' ' || line[ptr]==esp1)){
					ptr++;
				}
				ll start = ptr;
				while (ptr < n && (line[ptr] != esp2)){
					ptr++;
				}
				string out = line.substr(start, ptr - start);

				//dejar listo para el sgte
				while (ptr < n && (line[ptr]==' ' || line[ptr]==esp2)){
					ptr++;
				}
				return out;
			};
			if(e==0){
				host = read();
			}
			else if(e==1){
				ip = read();
			}
			else if(e==2){
				id = read();
			}
			else if(e==3){
				date_raw = read_esp('[',']');
			}
			else if(e==4){
				dbg("leere request",line[ptr] , line[ptr+1]);
				request = read_esp('"','"');
			}
			else if(e==5){
				status = read();
			}
			else if(e==6){
				ua = read_esp('"','"');
			}
			else{
				sess = read_esp('"','"');
			}
		}
		dbg(host, ip, id);
		dbg(date_raw);
		dbg(request);
		dbg(ua, sess, status);
		RAYA;
		RAYA;

		if(status!="200") continue;
		if(id.size()==0 || id=="-")continue;
		

        auto colon = date_raw.find(':');
        string dayKey = date_raw.substr(0, colon);

		Info_per_day &act = bd[id][dayKey];
		if (!ua.empty() && ua != "-") act.agents.insert(ua);
        if (!ip.empty() && ip != "-") act.ips.insert(ip);
        if (!sess.empty() && sess != "-") act.sessions.insert(sess);
		auto is_all_digits=[](string& s){
			if (s.empty()) return false;
			for(auto & c: s) {
				if(c < '0' || c > '9'){
					return false;
				}
			}
			return true;
		};
		auto get = [&](ll &val){
			auto p = request.find("/document/");
			if (p == string::npos) return false;

			auto start = p + string("/document/").size();
			auto dot = request.find(".pdf", start);
			if (dot == string::npos) return false;
			
			string idd = request.substr(start, dot - start);
			if (!is_all_digits(idd)) return false;
			val = stoll(idd);
			return true;
		};
		if(!request.empty()){
			ll val = -1;
			if(get(val)){
				act.pdfCount++;
				if (act.lastPdfNum != LONG_LONG_MIN && val == act.lastPdfNum + 1){
					act.cur += 1;
				} else {
					act.cur = 1;
				}
				act.lastPdfNum = val;
				if (act.cur > act.maxi) act.maxi = act.cur;
			}
		}
		
	}
	V<faltas> res;
	for(auto & [id, mapita] : bd){
		ll maxiAgents = 0, maxiIps = 0, maxiPdfs = 0, maxiSess = 0, maxiCrawls = 0; 
		for(auto & [day , info] : mapita){
			maxiAgents = max(maxiAgents, (ll)info.agents.size());
            maxiIps = max(maxiIps, (ll)info.ips.size());
            maxiPdfs = max(maxiPdfs, info.pdfCount);
            maxiSess = max(maxiSess, (ll)info.sessions.size());
            maxiCrawls = max(maxiCrawls, info.maxi);
		}
		if (lim.agent != -1 && maxiAgents >= lim.agent) res.push_back({id, "agent", maxiAgents});
        if (lim.ip != -1 && maxiIps >= lim.ip) res.push_back({id, "ip",    maxiIps});
        if (lim.pdf != -1 && maxiPdfs >= lim.pdf) res.push_back({id, "pdf",   maxiPdfs});
        if (lim.session!= -1 && maxiSess >= lim.session) res.push_back({id, "session", maxiSess});
        if (lim.crawl != -1 && maxiCrawls >= lim.crawl) res.push_back({id, "crawl", maxiCrawls});
	}
	if (res.empty()){
        cout << "N/A\n";
        return;
    }
	sort(all(res), []( faltas& a, faltas& b){
        if (a.id != b.id) return a.id < b.id;
        if (a.type != b.type) return a.type < b.type;
        return a.value < b.value;
    });
	
    for (auto& e : res){
        cout << e.id << " " << e.type << "=" << e.value << "\n";
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll t=1;
	setIn("app.in");
    //cin>>t;
    while(t--) solve();
}