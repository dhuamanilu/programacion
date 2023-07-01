void solve(){
    ll n;
    cin>>n;
    ll a[]={4,7};
    vector<ll> b;

    for(int i=0; i<n; i++){
        for(int j=0; j<b.size(); j++){
            b.push_back(b[j]*10 + 4);
            b.push_back(b[j]*10 + 7);
        }
    }

    // Imprimir el vector b
    for(int i=0; i<b.size(); i++){
        cout << b[i] << " ";
    }
    cout << endl;
}


