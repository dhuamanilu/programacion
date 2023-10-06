#include "infante.h"
using namespace std;
int main(){
    string nom1="Marco";
    infante inf1(nom1);
    string nom2="Pedro";
    joven jov1(nom2);
    string nom3="Juan";
    adulto adul1(nom3);
    inf1.gatear();
    jov1.correr();
    //adul1.
    return 0;
}
