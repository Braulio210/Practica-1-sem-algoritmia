#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>



using namespace std;

class Paquete
{
public:
    char ID[10], Origen[35], Destino[15], Peso[20];
    void InsertarInicio();
    void Mostrar();
    void Recuperar();
    void EliminarInicio();
}p;


void Paquete::InsertarInicio()
{
    cout<<"Dame el id del paquete: ";
    cin.getline(ID, 10);
    cin.getline(ID, 10);
    cout<<"Dame El origen: ";
    cin.getline(Origen,35);
    cout<<"Dame El Destino: ";
    cin.getline(Destino,15);
    cout<<"Dame El peso: ";
    cin.getline(Peso,20);
    ofstream Archivo("Prodauto.txt",ios::app);
    Archivo<<ID<<'|'<<Origen<<'|'<<Destino<<'|'<<Peso<<'|';
    Archivo.close();
}

void Paquete::Mostrar()
{
    int i;
    ifstream Lectura("Prodauto.txt");
    if(!Lectura.good())
    {
        cout<<"No existe el paquet\n";
        system("pause");
    }
    else
    {
        while(!Lectura.eof())
        {
            i=0;
            do
            {
                Lectura.read((char *)&ID[i],1);
                if(Lectura.eof())
                    break;
                    i++;
            }while(ID[i-1]!='|');
            ID[i-1]='\0';

            i=0;


            do
            {
                Lectura.read((char *)&Origen[i],1);
                if(Lectura.eof())
                    break;
                i++;
            }while(Origen[i-1]!='|');
            Origen[i-1]='\0';

            i=0;
            do
            {
                Lectura.read((char *)&Destino[i],1);
                if(Lectura.eof())
                    break;
                i++;
            }while(Destino[i-1]!='|');
            Destino[i-1]='\0';

            i=0;
            do
            {
                Lectura.read((char *)&Peso[i],1);
                if(Lectura.eof())
                    break;
                i++;
            }while(Peso[i-1]!='|');
            Peso[i-1]='\0';

            if(Lectura.eof())
                break;

            cout<<endl<<"\nId: "<<ID<<endl<<"\nOrigen: "<<Origen<<endl<<"\nDestino: "<<Destino<<endl<<"\nPeso:  "<<Peso<<endl<<endl;
            if(Lectura.eof())
                break;
        }
        system("pause");
    }
    Lectura.close();
}
void Paquete::Recuperar(){
    int b;  b = 0;
    int i;
    int iguales;
    char caracter;
    char alubus[10];


    ifstream arc("Prodauto.txt");
    if(!arc.good())
    {
        cout<<"\n NO EXISTE EL PAQUETE...\n";
    }

    else{
        cout<<"\n Escribe el Id del paquete a buscar: ";
        cin.getline(alubus,10);
        cin.getline(alubus,10);


        while(!arc.eof()){
            i = 0;
            do{
                arc.read((char*)&caracter,1);
                if(caracter!='|')
                {
                    ID[i] = caracter;
                    i++;
                }

            }while(caracter != '|');

            ID[i]= '\0';
            i = 0;
            do
            {
                arc.read((char*)&caracter,1);
                if(caracter!='|')
                {
                   Origen[i] = caracter;
                    i++;
                }

            }while(caracter != '|');
            Origen[i]= '\0';


            i = 0;
            do
            {
                arc.read((char*)&caracter,1);
                if(caracter!='|' && !arc.eof())
                {
                    Destino[i] = caracter;
                    i++;
                }

            }while(caracter != '|' && !arc.eof());
            Destino[i]= '\0';
            i=0;

            do
            {
                arc.read((char*)&caracter,1);
                if(caracter!='|' && !arc.eof())
                {
                    Peso[i] = caracter;
                    i++;
                }

            }while(caracter != '|' && !arc.eof());
            Peso[i]= '\0';



            if(arc.eof())
            {
                break;
            }

            iguales = strcmp(ID,alubus);

            if(iguales == 0){
            cout<<endl<<"\nId: "<<ID<<endl<<"\nOrigen: "<<Origen<<endl<<"\nDestino: "<<Destino<<endl<<"\nPeso:  "<<Peso<<endl<<endl;
                b = 1;
                break;
            }
        }

        if( b == 0){
            cout<<"\n\n NO EXISTE EL PAQUETE... \n\n";
        }
        arc.close();
    }
}

void Paquete::EliminarInicio(){
    int b = 0;
    int i;
    int iguales,respuesta; respuesta = 0;
    char caracter;
    char alubus[10];


    ifstream arc("Prodauto.txt");
    if(!arc.good())
    {
        cout<<"\n NO EXISTE EL PAQUETE...\n";
    }
    else{
        cout<<"\n Escribe el id del Paquete: ";
        cin.getline(alubus,10);
        cin.getline(alubus,10);

        while(!arc.eof()){
            i = 0;
            do{
                arc.read((char*)&caracter,1);
                if(caracter!='|')
                {
                    ID[i] = caracter;
                    i++;
                }

            }while(caracter != '|');

            ID[i]= '\0';

            i = 0;
            do
            {
                arc.read((char*)&caracter,1);
                if(caracter!='|')
                {
                    Origen[i] = caracter;
                    i++;
                }

            }while(caracter != '|');
            Origen[i]= '\0';

            i = 0;
            do
            {
                arc.read((char*)&caracter,1);
                if(caracter!='|' && !arc.eof())
                {
                    Destino[i] = caracter;
                    i++;
                }

            }while(caracter != '|' && !arc.eof());
            Destino[i]= '\0';

            i=0;

           do
            {
                arc.read((char*)&caracter,1);
                if(caracter!='|' && !arc.eof())
                {
                    Peso[i] = caracter;
                    i++;
                }

            }while(caracter != '|' && !arc.eof());
            Peso[i]= '\0';



            if(arc.eof())
            {
                break;
            }

            iguales = strcmp(ID,alubus);

            if(iguales == 0){
            cout<<endl<<"\nId: "<<ID<<endl<<"\nOrigen: "<<Origen<<endl<<"\nDestino: "<<Destino<<endl<<"\nPeso:  "<<Peso<<endl<<endl;
                b = 1;
        }


        }
        arc.close();
        }

        if(b == 0) {
            cout<<"\n\n EL PAQUETE NO EXISTE \n\n";
        }
        if(b == 1){

            cout<<"\n Escribe 1 si deseas eliminar este paquete: ";

            cin>>respuesta;

            if(respuesta == 1){
                ifstream arc ("Prodauto.txt");
                ofstream temporal ("temporalauto.txt",ios::app);
                while(!arc.eof()){
                    i = 0;
                    do{
                        arc.read((char*)&caracter,1);
                        if(caracter!='|')

                        {
                            ID[i] = caracter;
                            i++;
                        }

                    }while(caracter != '|');
                    ID[i]= '\0';
                    i = 0;
                    do
                    {
                        arc.read((char*)&caracter,1);
                        if(caracter!='|')
                        {

                            Origen[i] = caracter;
                            i++;
                        }

                    }while(caracter != '|');
                    Origen[i]= '\0';

                    i = 0;
                    do
                    {
                        arc.read((char*)&caracter,1);
                        if(caracter!='|' && !arc.eof())
                        {
                            Destino[i] = caracter;
                            i++;
                        }

                    }while(caracter != '|' && !arc.eof());
                    Destino[i]= '\0';

                    i=0;

                    do
                    {
                        arc.read((char*)&caracter,1);
                        if(caracter!='|' && !arc.eof())
                        {
                            Peso[i] = caracter;
                            i++;
                        }

                    }while(caracter != '|' && !arc.eof());
                    Peso[i]= '\0';

                   if(arc.eof())

                    {
                        break;
                    }

                    iguales = strcmp(ID,alubus);
                    if(iguales != 0){
                        temporal <<ID<<"|"<<Origen<<"|"<<Destino<<"|"<<Peso<<"|";

                    }
                }

                arc.close();
                temporal.close();
                remove("Prodauto.txt");
                rename("temporalauto.txt","Prodauto.txt");
                cout<<"\n\n EL PAQUETE FUE ELIMINADO... \n\n";
                b = 1;
            } // if

            else {
                cout<<"\n EL PAQUETE NO FUE ELIMINADO... \n\n";
            }

        }


}




int main(){
    int opc;
    do{
        cout<<"\n 1.- Agregar paquete \n 2.- Mostrar \n 3.- Recuperar paquete \n 4.- Eliminar paquete \n 5.- Salir \n SELECCIONA LA OPCION (1-5): ";
        cin>>opc;
        switch(opc){
            case 1: p.InsertarInicio();
                break;

            case 2: p.Mostrar();
                break;

            case 3: p.Recuperar();
                break;

            case 4: p.EliminarInicio();
                break;

        }

    }while(opc!=5);
}
