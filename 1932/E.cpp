#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef map <ll,ll> mll;
typedef vector <pair<ll,ll>> vpll;
typedef priority_queue<ll> pq;
#define FOR(i, a, b) for (long long i=a; i<(b); i++)
#define FOR1(i, a, b) for (long long i=a; i<=(b); i++)
#define mp make_pair
#define pb push_back
#define f first
#define se second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
#ifdef LOCAL
	#define n_l '\n'
	#define dbg(...) cout << "[" << #__VA_ARGS__ << "]: "; cout << to_string(__VA_ARGS__) << endl
	template <typename T, size_t N> int SIZE(const T (&t)[N]){ return N; } template<typename T> int SIZE(const T &t){ return t.size(); } string to_string(const string s, int x1=0, int x2=1e9){ return '"' + ((x1 < s.size()) ? s.substr(x1, x2-x1+1) : "") + '"'; } string to_string(const char* s) { return to_string((string) s); } string to_string(const bool b) { return (b ? "true" : "false"); } string to_string(const char c){ return string({c}); } template<size_t N> string to_string(const bitset<N> &b, int x1=0, int x2=1e9){ string t = ""; for(int __iii__ = min(x1,SIZE(b)),  __jjj__ = min(x2, SIZE(b)-1); __iii__ <= __jjj__; ++__iii__){ t += b[__iii__] + '0'; } return '"' + t + '"'; } template <typename A, typename... C> string to_string(const A (&v), int x1=0, int x2=1e9, C... coords); int l_v_l_v_l = 0, t_a_b_s = 0; template <typename A, typename B> string to_string(const pair<A, B> &p) { l_v_l_v_l++; string res = "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; l_v_l_v_l--; return res; } template <typename A, typename... C> string to_string(const A (&v), int x1, int x2, C... coords) { int rnk = rank<A>::value; string tab(t_a_b_s, ' '); string res = ""; bool first = true; if(l_v_l_v_l == 0) res += n_l; res += tab + "["; x1 = min(x1, SIZE(v)), x2 = min(x2, SIZE(v)); auto l = begin(v); advance(l, x1); auto r = l; advance(r, (x2-x1) + (x2 < SIZE(v))); for (auto e = l; e != r; e = next(e)) { if (!first) { res += ", "; } first = false; l_v_l_v_l++; if(e != l){ if(rnk > 1) { res += n_l; t_a_b_s = l_v_l_v_l; }; } else{ t_a_b_s = 0; } res += to_string(*e, coords...); l_v_l_v_l--; } res += "]"; if(l_v_l_v_l == 0) res += n_l; return res; } void dbgm(){;} template<typename Heads, typename... Tails> void dbgm(Heads H, Tails... T){ cout << to_string(H) << " | "; dbgm(T...); }
	#define dbgm(...) cout << "[" << #__VA_ARGS__ << "]: "; dbgm(__VA_ARGS__); cout << endl
#else
	#define dbg(...)
	#define dbgm(...)
#endif
using u32=unsigned;
using i64=long long;
using u64=unsigned long long;
struct ict4{
    int num[10000];
    constexpr ict4(){
        for(int e0=(48<<0),j=0;e0<(58<<0);e0+=(1<<0)){
            for(int e1=(48<<8);e1<(58<<8);e1+=(1<<8)){
                for(int e2=(48<<16);e2<(58<<16);e2+=(1<<16)){
                    for(int e3=(48<<24);e3<(58<<24);e3+=(1<<24)){
                        num[j++]=e0^e1^e2^e3;
                    }
                }
            }
        }
    }
    auto get(int x)const{
        return (const char*)(num+x);
    }
};
constexpr ict4 ot4={};
inline auto stou_8(const char*s){
    u64 tmp=(*(u64*)s)^0x3030303030303030ull;
    tmp=((tmp*(10ull<<8|1))>>8)&0x00ff00ff00ff00ffull;
	tmp=((tmp*(100ull<<16|1))>>16)&0x0000ffff0000ffffull;
	return (u32)((tmp*(10000ull<<32|1))>>32);
}
using f64=double;
using cpx=std::complex<f64>;
//from https://judge.yosupo.jp/submission/156446
struct ffter{
    std::vector<cpx> w{1.0};
    void init(int l){
        int old=w.size();
        if(l<=(old<<1)){return;}
		int t=std::__lg(l-1);
		l=1<<t,w.resize(l);
		for(int i=old;i<l;i<<=1){w[i]=std::polar(1.0,acos(-1.0)/(i<<1));}
		for(int i=old;i<l;++i){w[i]=w[i&(i-1)]*w[i&-i];}
    }
    void dif(cpx*f,int L){
		for(int l=L>>1,r=L;l;l>>=1,r>>=1){
            for(cpx*k=f;k!=f+l;++k){
                cpx x=*k,y=k[l];
				*k=x+y,k[l]=x-y;
            }
			for(cpx*j=f+r,*o=w.data()+1;j!=f+L;j+=r,++o){
				for(cpx*k=j;k!=j+l;++k){
					cpx x=*k,y=k[l]**o;
					*k=x+y,k[l]=x-y;
				}
			}
		}
	}
    void dit(cpx*f,int L){
		for(int l=1,r=2;l<L;l<<=1,r<<=1){
            for(cpx*k=f;k!=f+l;++k){
                cpx x=*k,y=k[l];
				*k=x+y,k[l]=x-y;
            }
			for(cpx*j=f+r,*o=w.data()+1;j!=f+L;j+=r,++o){
				for(cpx*k=j;k!=j+l;++k){
					cpx x=*k,y=k[l];
					*k=x+y,k[l]=(x-y)*std::conj(*o);
				}
			}
		}
	}
    void fconv(cpx*F,cpx*G,int lm){
        init(lm),dif(F,lm),dif(G,lm);
        f64 fx=1.0/lm,fx2=0.25*fx;
        F[0]={F[0].real()*G[0].real()+F[0].imag()*G[0].imag(),F[0].real()*G[0].imag()+F[0].imag()*G[0].real()};
        F[0]*=fx,F[1]*=G[1]*fx;
        for(int k=2,m=3;k<lm;k<<=1,m<<=1){
			for(int i=k,j=i+k-1;i<m;++i,--j){
				cpx oi=F[i]+std::conj(F[j]),hi=F[i]-std::conj(F[j]);
                cpx Oi=G[i]+std::conj(G[j]),Hi=G[i]-std::conj(G[j]);
				cpx r0=oi*Oi-hi*Hi*((i&1)?-w[i>>1]:w[i>>1]),r1=Oi*hi+oi*Hi;
                F[i]=(r0+r1)*fx2,F[j]=std::conj(r0-r1)*fx2;
			}
		}
        dit(F,lm);
    }
}ft;
class Buint{
    struct re_init{u32 x;};
    public:
    static constexpr u32 base=1E8;
    Buint():a{nullptr},sz{0},cp{0}{}
    Buint(u64 x):a{new u32[4]},sz{0},cp{4}{while(x){a[sz++]=x%base,x/=base;}}
    Buint(const Buint&x):a{(u32*)memcpy(new u32[x.sz],x.a,x.sz*sizeof(u32))},sz{x.sz},cp{sz}{}
    void swap(Buint&x){std::swap(a,x.a),std::swap(sz,x.sz),std::swap(cp,x.cp);}
    Buint(Buint&&x):a{x.a},sz{x.sz},cp{x.cp}{x.a=nullptr;}
    Buint&operator=(Buint&&x){this->swap(x);return *this;}
    Buint&operator=(const Buint&x){
        if(cp<x.sz){delete []a,a=new u32[x.sz],cp=x.sz;}
        memcpy(a,x.a,x.sz*sizeof(u32)),sz=x.sz;
        return *this;
    }
    ~Buint(){delete []a;}
    friend auto operator<=>(const Buint&a,const Buint&b){
        if(a.sz!=b.sz){return a.sz<=>b.sz;}
        for(u32 n=a.sz-1;~n;--n){if(a.a[n]!=b.a[n]){return a.a[n]<=>b.a[n];}}
        return 0u<=>0u;
    }
    friend bool operator==(const Buint&a,const Buint&b){
        return (a<=>b)==0;
    }
    friend Buint operator+(const Buint&a,const Buint&b){
        return a.sz<b.sz?b.radd(a):a.radd(b);
    }
    friend Buint operator-(const Buint&a,const Buint&b){
        assert(a>=b);
        return a.rsub(b);
    }
    friend Buint operator*(const Buint&a,const Buint&b){
        return a.sz<b.sz?b.rmul(a):a.rmul(b);
    }
    friend Buint operator/(const Buint&a,const Buint&b){
        return a.rdiv(b).first;
    }
    friend Buint operator%(const Buint&a,const Buint&b){
        return a.rdiv(b).second;
    }
    static auto div_mod(const Buint&a,const Buint&b){
        return a.rdiv(b);
    }
    static std::string to_str(const Buint&x){
        if(x.sz==0){return "0";}
        std::string r;
        r.reserve(x.sz*8);
        r=std::to_string(x.a[x.sz-1]);
        for(u32 i=x.sz-2;~i;--i){
            r.append(ot4.get(x.a[i]/10000u),4);
            r.append(ot4.get(x.a[i]%10000u),4);
        }
        return r;
    }
    static std::string to_sn_str(const Buint&x){
        if(x.sz==0){return "0";}
        int bt=x.sz*8-1;
        char buf[24];
        auto get_f=[&](u64 x){
            u64 b=(u64(base)*base)/10u;
            while(x<b){b/=10u,--bt;}
            snprintf(buf,24,"%c.%06llu",char(x/b)+'0',(x%b)/(b/1000000ull));
            return std::string(buf);
        };
        auto s=get_f(x.a[x.sz-1]*u64(base)+(x.sz==1?0:x.a[x.sz-2]));
        return s+"E"+std::to_string(bt);
    }
    static Buint fr_str(std::string_view s){
        assert(!s.empty());
        u32 n=s.size(),sz=(n+7)>>3,p=n&7;
        if(p==0){p=8;}
        Buint r{re_init{sz}};
        auto y=s.data();
        r.sz=sz,std::from_chars(y,y+p,r.a[sz-1]);
        for(u32 i=sz-2;~i;--i){r.a[i]=stou_8(y+p),p+=8;}
        r.shr();
        return r;
    }
    bool is_zero()const{return sz==0;}
    private:
    Buint(re_init x):a{new u32[x.x]},sz{0},cp{x.x}{}
    void shr(){while((sz>0)&&a[sz-1]==0u){--sz;}}
    Buint rshiftr(u32 d)const{
        if(d>=sz){return {};}
        Buint r{re_init{sz-d}};
        r.sz=sz-d;
        memcpy(r.a,a+d,r.sz*sizeof(u32));
        return r;
    }
    Buint rshiftl(u32 d)const{
        if(sz==0){return {};}
        Buint r{re_init{sz+d}};
        r.sz=sz+d;
        memset(r.a,0,d*sizeof(u32));
        memcpy(r.a+d,a,sz*sizeof(u32));
        return r;
    }
    Buint radd(const Buint&x)const{
        Buint r{re_init{sz+1}};
        u32 c=0;
        for(u32 i=0;i<x.sz;++i){
            r.a[i]=a[i]+x.a[i]+c,c=0;
            if(r.a[i]>=base){r.a[i]-=base,c=1;}
        }
        for(u32 i=x.sz;i<sz;++i){
            r.a[i]=a[i]+c,c=0;
            if(r.a[i]>=base){r.a[i]-=base,c=1;}
        }
        if(c){r.a[sz]=c,r.sz=sz+1;}else{r.sz=sz;}
        return r;
    }
    Buint rsub(const Buint&x)const{
        Buint r{re_init{sz}};
        u32 c=0;
        for(u32 i=0;i<x.sz;++i){
            r.a[i]=a[i]-x.a[i]-c,c=0;
            if(r.a[i]>=base){r.a[i]+=base,c=1;}
        }
        for(u32 i=x.sz;i<sz;++i){
            r.a[i]=a[i]-c,c=0;
            if(r.a[i]>=base){r.a[i]+=base,c=1;}
        }
        r.sz=sz,r.shr();
        return r;
    }
    Buint rmul(const Buint&x)const{
        if(x.sz==0){return {};}//0を掛ける
        if(x.sz<=16){return rmul_bf(x);}
        return rmul_fft(x);
    }
    Buint rmul_bf(const Buint&x)const{
        Buint r{re_init{sz+x.sz}};
        u64 tmp=0;
        u32 u=sz+x.sz-1;
        for(u32 i=0;i<u;++i){
            for(u32 j=((i>=sz)?i-sz+1:0);j<=std::min(i,x.sz-1);++j){tmp+=x.a[j]*u64(a[i-j]);}
            r.a[i]=tmp%base,tmp/=base;
        }
        if(tmp){r.a[u]=tmp,r.sz=u+1;}else{r.sz=u;}
        return r;
    }
    Buint rmul_fft(const Buint&x)const{
        static std::vector<cpx> F,G;
        u32 u=sz+x.sz,lm=2u<<std::__lg(u-1);
        Buint r{re_init{u}};
        F.assign(lm,0.0),G.assign(lm,0.0);
        for(u32 i=0;i<sz;++i){F[i]=cpx(a[i]%10000u,a[i]/10000u);}
        for(u32 i=0;i<x.sz;++i){G[i]=cpx(x.a[i]%10000u,x.a[i]/10000u);}
        ft.fconv(F.data(),G.data(),lm);
        u64 tmp=0;
        for(u32 i=0;i<u;++i){tmp+=(i64(F[i].real()+0.5)+(i64(F[i].imag()+0.5)*10000)),r.a[i]=tmp%base,tmp/=base;}
        return r.sz=u,r.shr(),r;
    }
    std::pair<Buint,Buint> rdiv(const Buint&x)const{
        assert(x.sz>0);//0で割る
        if((*this)<x){return {{},*this};}
        if(std::min(x.sz,sz-x.sz)<=64){return rdiv_bf(x);}
        return rdiv_nwt(x);
    }
    std::pair<Buint,Buint> rdiv_bf(const Buint&x)const{        
        Buint q{re_init{sz-x.sz+1}},r=*this;
        q.sz=sz-x.sz+1;
        auto get_val=[](const u32*A,int y,int z){
            return u64(10)*base*((y+1)<z?A[y+1]:0)+u64(10)*A[y]+((y-1)>=0?A[y-1]:0)/(base/10);
        };
        for(u32 i=sz-x.sz;~i;--i){
            u32 p={};
            auto subt=[&](){
                i64 k=0;
                for(u32 j=0;j<x.sz;++j){
                    k=k-i64(p)*x.a[j]+r.a[i+j];
                    r.a[i+j]=int(k%base),k/=base;
                    if(r.a[i+j]>=base){r.a[i+j]+=base,--k;}
                }
                if(k){r.a[i+x.sz]+=k;}
                q.a[i]+=p;
            };
            q.a[i]=0;
            while((p=get_val(r.a,i+x.sz-1,sz)/(get_val(x.a,x.sz-1,x.sz)+1))){subt();}
            p=1;
            for(u32 j=x.sz-1;~j;--j){
                if(r.a[j+i]!=x.a[j]){
                    p=x.a[j]<r.a[j+i];
                    break;
                }
            }
            if(p){subt();}
        }
        q.shr(),r.shr();
        return {q,r};
    }
    //base^n * 1/this
    //sz<=n
    Buint __inv(u32 n)const{
        if(std::min(sz,n-sz)<=64){
            Buint a{re_init{n+1}};
            memset(a.a,0,n*sizeof(u32));
            a.a[n]=1u,a.sz=n+1;
            return a.rdiv_bf(*this).first;
        }
        u32 k=(n-sz+5)>>1,kk=k>sz?0:sz-k;
        auto x=rshiftr(kk);
        u32 nn=k+x.sz;
        auto y=x.__inv(nn);
        /*
        base^{nn} * 1/x
        x=this/base^{kk}
        base^{nn+kk} * 1/this
        */
        auto a=y+y;
        // base^{nn+kk}
        auto b=(*this)*y*y;
        // base^{2nn+2kk}
        return a.rshiftl(n-nn-kk)-b.rshiftr(2*(nn+kk)-n)-1;
    }
    std::pair<Buint,Buint> rdiv_nwt(const Buint&x)const{
        u32 k=sz-x.sz+5,kk=k>x.sz?0:x.sz-k;
        auto xx=x.rshiftr(kk);
        if(kk!=0){xx=xx+1;}
        u32 nn=k+xx.sz;
        auto u=(*this)*(xx.__inv(nn));
        auto q=u.rshiftr(nn+kk);
        auto r=(*this)-q*x;
        if(r>=x){q=q+1,r=r-x;}
        assert(r<x);
        return {q,r};
    }
    u32*a;
    u32 sz,cp;
};
struct Bint{
    private:
    bool sign;
    Buint x;
    public:

};
using std::cin;
using std::cout;
auto&operator>>(std::istream&is,Buint&x){
    std::string s;
    return is>>s,x=Buint::fr_str(s),is;
}
auto&operator<<(std::ostream&os,const Buint&x){
    return os<<Buint::to_str(x);
}
std::mt19937 rnd(time(nullptr));
std::string rnd_s(int m){
    std::string s(m,'0');
    s.front()=(rnd()%9)+'1';
    for(int i=1;i<m;++i){s[i]=(rnd()%10)+'0';}
    return s;
}
void dpr(const Buint&x){
    std::cout<<Buint::to_sn_str(x)<<std::endl;
}
struct auto_timer{
	std::chrono::system_clock::time_point lst;
	auto_timer() : lst(std::chrono::system_clock::now()){
		
	}
	~auto_timer(){
		std::chrono::duration<long double,std::milli> tott=std::chrono::system_clock::now()-lst;
		char bbuf[24];
		snprintf(bbuf,24,"%.6Lf",tott.count());
		std::clog<<bbuf<<"ms"<<std::endl;
	}
};

void solve(){
    ll n;
    cin>>n;
    string s;
    cin>>s;
    string ans=s;
    ll ptr=0;
    string sum="";
    sum.pb(s[ptr]-'0');
    while(ptr<n-1){
    	ans=add(ans,sum);
    	ptr++;
    	sum.pb(s[ptr]-'0');
    }
    string res=ans;
    reverse(all(res));
    while(res.size()>0 && res.back()=='0'){
    	res.pop_back();
    }
    reverse(all(res));
    cout<<"\n";   
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}








