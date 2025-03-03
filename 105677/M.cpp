
int rng_int(int L, int R) { assert(L <= R);
	return uniform_int_distribution<int>(L,R)(rng);  }
ll rng_ll(ll L, ll R) { assert(L <= R);
	return uniform_int_distribution<ll>(L,R)(rng);  }

int main() {
	
    //? Stress Testing
    while(1) {
        ll n=rng_ll(1,5000);
        ll k=rng_ll(1,20);
        vl a(n);
        each(e,a)e=rng_ll(0,1000000);
        auto xd = solve(a,k);
    }
}