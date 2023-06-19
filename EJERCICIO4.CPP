#include <bits/stdc++.h>
//Para usar numeros de 128 bits
#include <boost_1_82_0/boost/multiprecision/cpp_int.hpp>
using namespace std;
using namespace boost::multiprecision;
//https://cp-algorithms.com/algebra/primality_tests
using u64 = uint128_t;
using u128 = uint128_t;
u64 binpower(u64 base, u64 e, u64 mod) {
    u64 result = 1;
    base %= mod;
    while (e) {
        if (e & 1)
            result = (u128)result * base % mod;
        base = (u128)base * base % mod;
        e >>= 1;
    }
    return result;
}
bool check_composite(u64 n, u64 a, u64 d, int s) {
    u64 x = binpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = (u128)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
};
bool isPrime(u128 n) { // returns true if n is prime, else returns false.
    if (n < 2)
        return false;
    int r = 0;
    u128 d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        r++;
    }
    for (int a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
        if (n == a)
            return true;
        if (check_composite(n, a, d, r))
            return false;
    }
    return true;
}
vector<u128> getPerfectos(){
    int cont=0;
    vector<u128> ans;
    long long k=1;
    while(cont!=8){
        u128 m=pow(u128(2), k) - 1;;
        //Funcion anidada,si (2^k)-(1) es primo entonces
        if(isPrime(m)){
            //2^(k-1) *((2^k)-(1)) es un numero perfecto
            u128 pot=pow(u128(2), k-1)*m;
            ans.push_back(pot);
            cont++;
        }
        k++;
    }
    return ans;
}
void paresImpares(vector<int> &nums){
    for(int i=0;i<nums.size();i++){
        if(nums[i]%2==0){
            cout<<nums[i]<<" es par, ";
        }
        else{
            cout<<nums[i]<<" es impar, ";
        }
    }
    cout<<"\n";
}
int invertir(int num){
    int ans=0;
    while(num>0){
        int d=num%10;
        ans=10*ans+d;
        num/=10;
    }
    return ans;
}
int main(){
    cout<<"Bienvenido al programa\n";
    while(true){
        cout<<"Elija opcion:\n";
        cout<<"Opcion 1 : Introducir 10 enteros y determinar cuales de "<<
        "estos son pares y cuales son impares\n";
        cout<<"Opcion 2 : Ver los 8 primeros numeros perfectos\n";
        cout<<"Opcion 3: Tomar un valor entero de cuatro digitos"<<
        " y ver el numero con los digitos invertidos\n";
        cout<<"Opcion 4: Salir\n";
        int opcion;
        cout<<"Ingrese opcion:";
        cin>>opcion;
        cout<<"\n";
        if(opcion==1){
            vector<int> nums(10);
            for(int i=0;i<nums.size();i++){
                cout<<"Introduzca numero:";
                cin>>nums[i];
            }
            paresImpares(nums);
        }
        else if(opcion==2){
            vector<u128> perfectos=getPerfectos();
            cout<<"Los 8 primeros numeros perfectos:\n";
            for(int i=0;i<perfectos.size();i++){
                cout<<perfectos[i]<<" ";
            }
            cout<<"\n";
        }
        else if(opcion==3){
            do{
                cout<<"Ingrese valor de 4 digitos\n";
                int num;
                cin>>num;
                if(num<1000 || num>9999){
                    cout<<"El numero ingresado no tiene 4 digitos\n";
                }
                else{
                    int invertido=invertir(num);
                    cout<<"El numero con los digitos invertidos es:"<<invertido<<"\n";
                    break;
                }
            }while(true);
        }
        else if(opcion==4){
            break;
        }
        else{
            cout<<"Numero incorrecto,intentelo de nuevo\n";
        }

    }

    return 0;
}
