#include <bits/stdc++.h>
using namespace std;
string to_string(string s){
    return '"' + s + '"';
}
string to_string(const char* s){
    return to_string((string) s);
}
string to_string(char c){
    return string(1,c);
}
string to_string(bool b){
    return (b ? "true" : "false");
}
template <typename A>
string to_string(A v);

template<typename A,typename B>

string to_string(pair <A,B> p){
    return "(" + to_string(p.first) + "," + to_string(p.second) + ")";
}

template <typename A>
string to_string(A v){
    bool first=true;
    string res="[";
    for(const auto & x : v){
        if(!first){
            res+=",";
        }
        first=false;
        res+=to_string(x);
    }
    res+="]";
    return res;
}

void debug_out(){cerr<<endl;}

template <typename Head, typename... Tail>
void debug_out(Head H,Tail... T){
    cerr<<" "<<to_string(H);
    debug_out(T...);
}

#ifdef LOCAL
#define MACRO(code ) do{code} while(false)

#define dbg(x) {auto xd = x; cout<<"Line()"<<__LINE__<<"): "<<"\033[1;34m"<<#x<<"\033[0;32m = \033[35m" << to_string(xd)<<"\033[0m"<<endl;}
#define dbg(...) MACRO(cout<<"Line("<<__LINE__<<"): "<<"\033[1;34m"<<"["<<#__VA_ARGS__<<"]\033[35m:"; debug_out(__VA_ARGS__); cout<<"\033[0m"<<endl;)

#define GA dbg(0)
#define RAYA cout<<"\033[101m"<<"==============="<<<<"\033[0m"<<endl;

#else
#define dbg(x)
#define dbg(...)
#define GA
#define RAYA
#endif


using ll = long long;

using db=long double;

using str=string;

using pi=pair<int,int>;

using pl=pair<ll,ll>;

#define mp make_pair

#define f first
#define s second
#define tcT template <class T
tcT> using V = vector<T>;
tcT,size_t SZ> using AR = array<T,SZ>;

using vi=V<int>;
using vl=V<ll>;
using vb = V<bool>;
using vpi=V<pi>;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define rsz resize
#define pb push_back
#define ft front()
#define bk back()

#define FOR(i,a,b) for( int i=(a);i<(b);++i)
#define F0R FOR(i,0,a)
#define ROF(i,a,b) for( int i=(b-1);i>=(a);--i)
#define R0F(i,a) ROF(i,0,a)
#define rep(a) F0R(_,a)
#define each(a,x) for(auto&a:x)
const int MOD=1e9+7;
const db PI = acos((db)-1);
//mt19937 rng(0); 
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

tcT> bool ckmin(T &a , const T&b){
    return b<a ? a = b , 1 : 0;
}

tcT> bool ckmax(T &a , const T&b){
    return a<b ? a = b , 1 : 0;
}

void setIn(string s){ freopen(s.c_str(),"r",stdin); }
struct Container{
    int id=-1;
    map<string,ll> goods;
    vector<Container> children;
};
void solve(){
    map<string,ll> goodsGeneral;
    vector<Container> warehouse;
    ll ID=1;

    auto getGood=[](string &input,ll l,ll r){
        string quantity="";
        string good="";
        for(int it=l;it<r;it++){
            if(input[it]==' ' || input[it]==',') continue;
            if(input[it]>='0' && input[it]<='9'){
                dbg("me encontre este digito ",input[it]);
                quantity+=input[it];
            }
            else{
                char actual=toupper(input[it]);
                dbg(actual);
                assert(actual>='A' && actual <='Z');
                good+=actual;
            }
        }
        if(quantity=="") quantity="1";
        return make_pair(good,stoll(quantity));
    };
    auto process_input=[&](auto &&process_input,string &input,ll l,ll r,Container& container,vl &match)->void{
        for(int i=l;i<=r;i++){
            if(input[i]==' ' or input[i]==',') continue;
            if(input[i]=='('){
                Container interno;
                process_input(process_input,input,i+1,match[i]-1,interno,match);
                container.children.push_back(interno);
                i=match[i];
            }
            else{
                //encontre 1 good, quiero parsearlo
                ll j=i+1;
                while(j<=r && input[j]!=','){
                    j++;
                }
                pair<string,ll> good=getGood(input,i,j);
                //dbg("insertare esto ",good);
                container.goods[good.first]+=good.second;
                i=j;
            }
        }
    };
    auto get_match=[](string &a){
        ll tam=a.size();
        vl match(tam,-1);
        vl stack;
        for(int it=0;it<tam;it++){
            if(a[it]=='('){
                stack.push_back(it);
            }
            else if(a[it]==')'){
                assert(stack.size()>0);
                match[stack.back()]=it;
                stack.pop_back();
            }
        }
        return match;
    };
    auto add_container=[&](Container& container){
        container.id=ID++;
        warehouse.push_back(container);
    };
    auto manage_buy=[&](string &a){
        //creando nuevo contenedor
        Container actual;
        vl match=get_match(a);
        ll tam=a.size();
        process_input(process_input,a,1,tam-2,actual,match);
        add_container(actual);
        cout<<"OK\n";
    };
    auto process_input2=[&](auto &&process_input2,string &input,ll l,ll r,vl &match,map<string,ll> & needed,Container & container)->void{
        //dbg("procesando input de needed",input);
        for(int i=l;i<=r;i++){
            if(input[i]==' ' or input[i]==',') continue;
            if(input[i]=='('){
                Container interno;
                process_input2(process_input2,input,i+1,match[i]-1,match,needed,interno);
                container.children.push_back(interno);
                i=match[i];
            }
            else{
                //encontre 1 good, quiero parsearlo
                ll j=i+1;
                while(j<=r && input[j]!=','){
                    j++;
                }
                pair<string,ll> good=getGood(input,i,j);
                container.goods[good.first]+=good.second;
                needed[good.first]+=good.second;
                i=j;
            }
        }
    };
    auto obtenerNeeded=[&](string &a){
        vl match=get_match(a);
        map<string,ll> needed;
        ll tam=a.size();
        Container container;
        process_input2(process_input2,a,1,tam-2,match,needed,container);
        return make_pair(needed,container);
    };
    auto findContainer=[&](ll id){
        ll indice=-1;
        for(int i=0;i<(ll)warehouse.size();i++){
            if(warehouse[i].id==id){
                indice=i;
                break;
            }
        }
        return indice;
    };
    auto sell=[&](string id){
        ll num=stoll(id);
        ll idx=findContainer(num);
        if(idx!=-1){
            assert(idx< warehouse.size());
            warehouse.erase(warehouse.begin()+idx);
            cout<<"OK\n";
        }
        else{
            cout<<"DISCARD\n";
        }
    };
    auto unpack=[&](string & id){
        ll num=stoll(id);
        ll idx=findContainer(num);
        if(idx!=-1){
            //unpack goods
            auto actual=warehouse[idx];
            assert(idx < warehouse.size());
            warehouse.erase(warehouse.begin()+idx);
            for(auto & [good,quantity] : actual.goods){
                goodsGeneral[good]+=quantity;
            }
            //unpack containers
            for(auto & container : actual.children){
                container.id=ID++;
                warehouse.push_back(container);
            }
            
            cout<<"OK, ";
            if(actual.children.size() == 0){
                cout<<"No containers added.\n";
            }
            else{
                cout<<actual.children.size()<<" ";
                if(actual.children.size()==1){
                    cout<<"container added.\n";
                }
                else{
                    cout<<"containers added.\n";
                }
            }
            
        }
        else{
            cout<<"DISCARD\n";
        }
    };
    auto contar=[&](auto &&contar,Container & container,string &good)->ll{
        if(container.goods.count(good) && container.goods[good] > 0 ) return 1;
        ll res=0;
        if(container.children.size()>0){
            for(auto & e : container.children){
                res|=contar(contar,e,good);
            }
        }
        return res;
    };
    auto get2=[&](auto &&get2,Container & container,string &good)->ll{
        if(container.goods.count(good) && container.goods[good] > 0){
            //dbg("de get 2 entre al PRIMER IF ",good,container.goods);
            return 1;
        } 
        ll res=(ll)1e12;
        if(container.children.size()>0){
            for(auto & e : container.children){
                res=min(res,1+get2(get2,e,good));
            }
        }
        return res;
    };
    auto sanitizar=[](string &xd){
        for(auto & e : xd){
            e=toupper(e);
        }
    };
    string line;
    while(getline(cin,line)){
        //dbg(line);

        if(line[0]=='?'){
            ll len=line.size();
            if(len>=7 && line.substr(2,5)=="COUNT"){
                string good=line.substr(8);
                sanitizar(good);
                ll ans=goodsGeneral.count(good) ? goodsGeneral[good] : 0ll;
                cout<<ans<<"\n";
            }
            else if(len>=10 && line.substr(2,8)=="CONTAINS"){
                string good=line.substr(11);
                sanitizar(good);
                //dbg(good);
                ll res=0;
                for(auto & container : warehouse){
                    res+=contar(contar,container,good);
                }
                cout<<res<<"\n";
            }
            else{
                assert(len>=5 && line.substr(2,3)=="MIN");
                string good=line.substr(6);
                sanitizar(good);
                //dbg(good,goodsGeneral);
                if(goodsGeneral.count(good) && goodsGeneral[good] > 0){
                    cout<<"0\n";
                }
                else{
                    
                    ll res=(ll)1e18;
                    /*for(auto &e : warehouse){
                        dbg(e.id,e.goods);
                        dbg("mis hijos");
                        for(auto & hijo : e.children){
                            dbg(hijo.id,hijo.goods);
                            for(auto &hijo2 : hijo.children){
                                dbg(hijo2.id,hijo2.goods);
                            }
                        }
                    }*/
                    for(auto & container : warehouse){
                        ll act=get2(get2,container,good);
                        //dbg(act);
                        //dbg("para este container ",container.id, "mi respuesta es",act);
                        res=min(res,act);
                    }
                    if(res>=(ll)1e12) res=-1;
                    cout<<res<<"\n";
                }
            }
        }
        else{
            ll len=line.size();
            if(len>=3 && line.substr(0,3)=="BUY"){
                string content=line.substr(4);
                manage_buy(content);
            }
            else if(len>=4 && line.substr(0,4)=="SELL"){
                string content=line.substr(5);
                sell(content);
            }
            else if(len>=6 && line.substr(0,6)=="UNPACK"){
                string content=line.substr(7);
                unpack(content);
            }
            else{
                assert(len>=4 && line.substr(0,4)=="PACK");
                string content=line.substr(5);
                auto need=obtenerNeeded(content);
                //dbg(need);
                bool ok=true;
                for(auto & [good,quantity] : need.first){
                    if(!goodsGeneral.count(good)){
                        ok=false;
                        break;
                    }
                    else if(goodsGeneral[good] < quantity){
                        ok=false;
                        break;
                    }
                }
                if(ok){
                    //Container toadd;
                    for(auto & [good,quantity] : need.first){
                        goodsGeneral[good]-=quantity;
                        //toadd.goods[good]=quantity;
                    }
                    add_container(need.second);
                    cout<<"OK\n";
                }
                else{
                    cout<<"DISCARD\n";
                }
            }
        }
        
        
    }

}
int main(){
    //setIn("K.in");
    cin.tie(0)->sync_with_stdio(0);
    solve();
}