#include <iostream>
#include <string>
#define TAM 50

using namespace std;

class GatoDomestico{
    private:
        string raza;
    public:
        string get_raza(){
            return raza;
        };
        void set_raza(string _raza){
            raza=_raza;
        }
        bool operator==(GatoDomestico & GM1){
            return (GatoDomestico::get_raza()==GM1.get_raza());
        }
        friend istream& operator>>( istream &o,GatoDomestico &GM1)
        {
            o>>GM1.raza;
            return o;
        }
        friend ostream& operator<<( ostream &o,GatoDomestico &GM1)
        {
            o<<GM1.raza;
            return o;
        }
};

class Lista{
private:
    GatoDomestico datos[TAM];
    int ult;
public:
    Lista():ult(-1){}
    bool vacia()const;
    bool llena()const;
    void agrega(GatoDomestico);
    bool inserta(GatoDomestico , int);
    bool elimina(int);
    GatoDomestico recupera(int)const;
    int primero()const;
    int ultimo()const;
    void imprime()const;
    int buscar(GatoDomestico);

};

void Lista::agrega(GatoDomestico elem){
    if(llena()){
        std::cout<<"\n No se pudo insertar";
    }
    else{
    datos[ult+1]=elem;
    ult++;
    }
}

int Lista::buscar(GatoDomestico elem){
    int i=0;
    while(i<=ult){
        if(elem==datos[i]){
            return i;
        }
        i++;
    }
    cout<<"Dato no encontrado. . ."<<endl;
    return -1;
}

void Lista::imprime()const{
    if(!vacia()){
        for(int i=0; i<=ult; i++){
            GatoDomestico Gm1=datos[i];
            std::cout<<Gm1<<std::endl;
        }
    }
}

bool Lista::vacia()const{
    return ult==-1;
}
bool Lista::llena()const{
    return ult==TAM-1;
}

bool Lista::inserta(GatoDomestico elem, int pos){
    if(llena() || pos<0 || pos>ult+1){
        std::cout<<"\n No se pudo insertar"<<endl;
        return false;
    }
    int i=ult+1;
    while(i>pos){
        datos[i]=datos[i-1];
        i--;
    }
    datos[pos]=elem;
    ult++;
    cout<<"Dato agregado correctamente. . ."<<endl;
    return true;
}

bool Lista::elimina(int pos){
    if(vacia() || pos<0 || pos>ult){
        std::cout<<"\n No se pudo eliminar"<<endl;
        return false;
    }
    int i=pos;
    while(i<ult){
        datos[i]=datos[i+1];
        i++;
    }
    ult--;
    std::cout<<"Dato eliminado correctamente"<<endl;
    return true;
}

GatoDomestico Lista::recupera(int pos)const{
    if(vacia() || pos<0 || pos>ult-1){
        std::cout<<"\n Insuficiencia de datos";
        //Manejar exceptions
    }
    else{
       return datos[pos];
    }
}

int Lista::primero()const{
    if(vacia()){
       return -1;
    }
    return 0;
}
int Lista::ultimo()const{
    if(vacia()){
       return -1;
    }
    return ult;
}

void menuPrincipal(){
    cout<<"Menu"<<endl;
    cout<<"1. Agrega"<<endl;
    cout<<"2. Buscar"<<endl;
    cout<<"3. Elimina"<<endl;
    cout<<"4. Inserta"<<endl;
    cout<<"5. Muestra"<<endl;
    cout<<"6. Salir"<<endl;
}

int main()
{
    Lista Milista;
    int opc,pos=0;
    GatoDomestico raza;
    Lista();
    do{
        system("cls");
        menuPrincipal();
        cout<<"Opcion: ";
        cin>>opc;
        switch(opc){
            case 1:
                cout<<"Dame el GatoDomestico a agregar: ";
                cin>>raza;
                Milista.agrega(raza);
                break;
            case 2:
                cout<<"Ingrese el dato a buscar: ";
                cin>>raza;
                pos=Milista.buscar(raza);
                if(pos!=-1){
                    cout<<"El dato se encuentra en la posicion: "<<pos<<endl;
                }
                system("pause");
                break;
            case 3:
                if(Milista.vacia()){
                    cout<<"Lista se encuentra vacia"<<endl;
                }
                else{
                cout<<"Dame el GatoDomestico a eliminar: ";
                cin>>raza;
                pos=Milista.buscar(raza);
                Milista.elimina(pos);
                }
                system("pause");
                break;
            case 4:
                cout<<"Dame el GatoDomestico a insertar: ";
                cin>>raza;
                cout<<endl<<"Dame la posicion donde se debe insertar el obejto GatoDomestico: ";
                cin>>pos;
                Milista.inserta(raza,pos);
                system("pause");
                break;
            case 5:
                Milista.imprime();
                system("pause");
                break;
            default:
                cout<<"Opcion invalida."<<endl;
                system("pause");
    }
    }
    while(opc!=6);
    return 0;
}
