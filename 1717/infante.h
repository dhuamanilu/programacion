#include <string>
#include <iostream>
using namespace std;
class infante{
    private:
        string nombre;
    public:
        infante(const string &nom) {
            nombre=nom;
        }
        void gatear () {
            cout<<nombre<<" gateando... \n";
        }
};

class joven{
    private:
        string nombre;
    public:
        joven(const string &nom) {
            nombre = nom;
        }
        void correr (){
            cout<<nombre<<" corriendo...\n";
        }
};
class adulto : public infante, public joven{
    private:
        string nombre;
    public:
        adulto (const string &nom);
        void caminar () {
            cout<<nombre<<" caminando... \n";
        }
};

