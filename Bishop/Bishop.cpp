#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
using namespace std;
const string Red("\033[1;91m");
const string Reset("\033[0m");
const string Green("\033[1;92m");
const string Blue("\033[1;34m");
const string Yellow("\033[0;33m");
const string Purple("\033[0;35m");


bool diagonal_arribder(string[8][8],int,int); //arreglo, coords
bool diagonal_arribizq(string[8][8],int,int);
bool diagonal_abajder(string[8][8],int,int);
bool diagonal_abajizq(string[8][8],int,int);


int main(){

    int casos,a,r=0;
    string tabla[8][8];
    string dato;
    system("title Bishop");

    do{
        cout<<"Ingresa el numero de casos del juego ---> ";
        cin>>casos;
    }while(casos<1 || casos>36);

    int coord_x[36],coord_y[36];
    
    for(int i=0; i<casos; i++){ //guardando los datos por cada caso
        a=0;
        cout<<"Ingresa los datos de la tabla no. "<<i+1<<endl;
        fflush(stdin);
        bool bandera2 = true;
        bool bandera3 = false;
        for(int i=0;i<8;i++){
            cin>>dato;
            for(int j=0;j<8 && bandera2;j++){
                if(dato[j] != '.' && dato[j] != '#'){
                    bandera2 = false;
                }
                else tabla[a][j] = dato[j];
            }
        a++;
        }
        if(bandera2 == false){
            coord_x[r] = 9;
            coord_y[r] = 9;
        }
        else{
            bandera3 = false;
            for(int i=0;i<8 && bandera3==false;i++){
                for(int j=0;j<8 && bandera3==false;j++){
                    if(i==0 || i==7 || j==0 ||j==7){} // primero evalúa si las coordenadas no son del borde del tablero

                    else if( diagonal_arribder(tabla,i,j) &&
                        diagonal_arribizq(tabla,i,j) &&
                        diagonal_abajder(tabla,i,j) &&
                        diagonal_abajizq(tabla,i,j)){//en true coloca los casos de las diagonales

                            coord_x[r] = j;
                            coord_y[r] = i;
                            bandera3 = true;
                    }
                    else{
                        coord_x[r] = 9;
                        coord_y[r] = 9;
                    }
                }
            }
        }
        r++;
    }

    cout<<Green<<"\n\nResultados por tabla:"<<Reset<<endl;

    for(int i=0;i<casos;i++){
        cout<<i+1<<": ";
        if(coord_x[i] == 9 || coord_y[i] == 9){
            cout<<"Error en la tabla"<<endl;
        }
        else{
            cout<<coord_x[i]<<"\t"<<coord_y[i]<<endl;
        }
        getch();
    }

    return 0;
    system("pause");
}

bool diagonal_arribder(string tabla[8][8],int x,int y){
    bool bandera = true;
    //if(x==7 || y==0) bandera = false;
    while(bandera == true && y!=-1 && x!=8){
        if(tabla[x][y] == "#"){
            x+=1;
            y-=1;
            //if(x==7 || y==0) bandera = false;
        }
        else bandera = false;
    }
    return bandera;
}

bool diagonal_arribizq(string tabla[8][8],int x,int y){
    bool bandera = true;
    //if(x==0 || y==0) bandera = false;
    while(bandera == true && y!=-1 && x!=-1){
        if(tabla[x][y] == "#"){
            x-=1;
            y-=1;
            //if(x==0 || y==0) bandera = false;
        }
        else bandera = false;
    }
    return bandera;
}

bool diagonal_abajder(string tabla[8][8],int x,int y){
    bool bandera = true;
    //if(x==7 || y==7) bandera = false;
    while(bandera == true && y!=8 && x!=8){
        if(tabla[x][y] == "#"){
            x+=1;
            y+=1;
            //if(x==7 || y==7) bandera = false;
        }
        else bandera = false;
    }
    return bandera;
}

bool diagonal_abajizq(string tabla[8][8],int x,int y){
    bool bandera = true;
    //if(x==0 || y==7) bandera = false;
    while(bandera == true && y!=8 && x!=-1){
        if(tabla[x][y] == "#"){
            x-=1;
            y+=1;
            //if(x==0 || y==7) bandera = false;
        }
        else bandera = false;
    }
    return bandera;
}