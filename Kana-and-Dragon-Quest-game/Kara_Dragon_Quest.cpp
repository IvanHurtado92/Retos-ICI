#include <iostream>
#include <conio.h>
#include <list>
#include <stack>
using namespace std;
const string Red("\033[1;91m");
const string Reset("\033[0m");
const string Green("\033[1;92m");
const string Blue("\033[1;34m");
const string Yellow("\033[0;33m");

int Void_Absorption(int);
int Lightning_Strike(int,int);
int result(int,int,int);


int main(){

    int cases,H,L,V,a=0;
    int data[1000];
    do{
        cout<<"Enter the number of test cases ---> ";cin>>cases;
    }while(cases<1 || cases>1000);
    
    for(int i=0;i<cases;i++){
        cout<<Yellow<<"\nSeparated by SPACE LINES"<<Reset<<", enter the "<<Green<<"[Dragon's Initial Health]\n"<<Reset;
        cout<<"the "<<Blue<<"[Maximum number of Void Absorption attacks]\n"<<Reset;
        cout<<"and the "<<Red<<"[Maximum number of Lightning Strike attacks]\n"<<Reset;

        do{
        cout<<"---> ";cin>>H>>V>>L;
        }while(H<1 || H>100000 || V<0 || L>30);
        
        H = result(H,V,L);
        
        data[a] = H;
        a++;
    }

    cout<<endl;
    for(int i=0;i<a;i++){
        if(data[i]>0){
            cout<<"NO";
        }
        else{
            cout<<"YES";
        }
        cout<<endl;
    }
    getch();
    return 0;
}

int Void_Absorption(int n){
    int valor = ((n/2)+10);
    return valor;
}

int Lightning_Strike(int n,int m){
    int valor = (n-(10*m));
    return valor;
}

int result(int health,int voi,int ligh){
    int v=voi,l=ligh,p;

    while(v>0 || health>0 && l!=0){
    //para entrar en el bucle se verifica, que aún hayan ataques de void o lightning disponibles o que el dragón aun tenga salud positiva
        if(health<=0){ //siempre verifica si ya está eliminado el dragón, si es así, reduce a cero el parámetro de lightning
            v=0;
        }
        if(health <= (ligh*10) && health>0 && l!=0){ //1er caso, la salud del dragón es menor que el total de daño proporcionado por el ataque lightning multiplicado por su cantidad máxima
            health = Lightning_Strike(health,ligh);  //si entra entonces le resta esa cantidad de daño
            l=0;                                     //y convierte l a 0 para que no se pueda volver a acceder
        }
        else if(health >= (ligh*10) && health>0 && v>0){ //2do caso, la salud es mayor a la ocacionada por el lightning y hay ataques de void disponibles
            health = Void_Absorption(health);            //hace un solo ataque de void y le resta uno a su cantidad de ataques restantes
            v--;
        }
        else{                       //3er caso: la salud restante después de usar todos los ataques de void sigue siendo mayor a la cantidad de daño ocacionada por todos los lightning
            l=0;                    //se cambia el valor de l para que termine el bucle
                                    //en este caso queda implícito que el dragón no es derrotado debido a que su salud seguirá siendo mayor a 0 a pesar de nuestros ataques restantes
        }
    }
    return health;
}