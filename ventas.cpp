#include <iostream>

void mostrarTabla(int tabla[][6],int t);
int agregarVenta(int tabla[][6], int t);
void sumarVentas(int tabla[][6], int t);
void sumaTotal(int tabla[][6], int t);
void vendio(int tabla[][6], int t);
int menu();

using namespace std;

int main() 
{
    int tabla [6][6]={{0}};
    int t = 6;
    int opc;
    do {
        opc = menu();
        if (opc==1)
            mostrarTabla(tabla, t);
        else if(opc==2)
            agregarVenta(tabla,t);
        else if(opc==0)
            cout<<"Adios"<<endl;
        else
            cout<<"Error"<<endl;
    	} while (opc!=0);
    return 0;
}
int menu()
{
    int opc;
    cout<<"1.- Mostrar la tabla"<<endl;
    cout<<"2.- Agregar venta"<<endl;
    cout<<"0.- Salir"<<endl;
    cout<<"\nIngresar opcion:";
    cin>>opc;
    cout<<endl;
    
    return opc;
}
void mostrarTabla(int tabla[][6], int t)
{
    sumarVentas(tabla, t);
    sumaTotal(tabla, t);
    for(int i=0;i<6;i++){
        for (int j=0; j<t; j++) 
		{
            if(j==5){
                cout<<"=";
                cout<<"\t"<<tabla[i][j];
                cout<<" ";
            }
            else if(i==4)
                cout<<"\t-";
            else
            cout<<"\t"<<tabla[i][j];
  
            cout<<" ";
        }
    cout<<"\n";
    }
    
    vendio(tabla, t);
}
int agregarVenta(int tabla[][6], int t)
{ int vendedor, producto, precio;
    char opc;
    cout<<"---Agregar venta---"<<endl;
    do {
        cout<<"Numero de vendedor:";
        cin>>vendedor;
        cout<<"Numero de producto:";
        cin>>producto;
        if (vendedor>4 || producto >5) {
            cout<<"Numero no valido\n";
            return 0;
        }
        else
            cout<<"Precio del producto: \n";
            cout<<"$";
            cin>>precio;
        if (tabla[vendedor-1][producto-1]!=0)
            tabla[vendedor-1][producto-1]+=precio;
        else
            tabla[vendedor-1][producto-1]=precio;
        cout<<"Desea agregar otro producto? [s/n]\n";
        cin>>opc;
        
    } while (opc!='n'&& opc!='N');
    
    return 0;
}

void sumarVentas(int tabla[][6], int t)
{ 
    for (int i = 0; i<t; i++)
        for (int j=0; j<t-1; j++)
            tabla[i][t-1] += tabla[i][j];
}
void sumaTotal(int tabla[][6], int t)
{
    for (int i=0; i<t; i++)
        for (int j=0; j<t-1; j++)
            tabla[t-1][i] += tabla[j][i];
}
void vendio(int tabla[][6], int t)
{
    for (int i=0; i<4; i++)
    {
            if (tabla[i][t-1]==0)
                cout<<"Vendedor "<<i+1<< " no vendio nada\n";
            else
                cout<<"Vendedor "<<i+1<< " vendio :"<<tabla[i][t-1]<<"\n";
        }
}
