//programa hechoi por wiliam alfredo vasquez flores
//carnet VF18003

#include <iostream>//libreria obligatoria 
#include <stdio.h>//contine macros y las declaraciones de funciones
#include <time.h>
#include <cstdlib>
//CUERPO DEL PROGRAMA
using namespace std;

//declaracion de funciones
void principio();
void linea(int j);
void juego();
void moverdisco();
void numAleatorios();
//declaracion de variables
int tem,tem2,n,i,j,desde,hacia,con,tam,tamdisco,espacios,k,matriz[100][3];
char cr='±',si,fondo=177;

int main() {
	
	principio();
	
	return 0;
}

void principio(){
	bool repite = true;
	int opcion;
	do{
		
		//Titulo del menu
		cout << "\n\t\t\tMENU PRINCIPAL\n";
		
		//Las opciones del menu
		cout << "\n\t1. jugar con las torres de hanoi\n";
		cout << "\n\t2. ordenar los 100 numeros\n";
		cout << "\n\t3. salir\n";
		
		//Leer la opcion elejida por el ususario
		cout << "\n\tOpcion: ";
		cin >> opcion;

		//Alternativas
		switch(opcion){
			case 1:
					juego();
					break;
				
				
			case 2:	
				
					numAleatorios();
					system("PAUSE");
					system("CLS");
					break;
					
			case 3:
					repite = false;
					break;
					
		}
		
		
	}while(repite);
	
	
	
}

void linea(int j){
 for(int i=0;i<j;i++)
	cout<<cr;
	cout<<endl;
}
void salir(){
 char r='©';
 system("cls");
 linea(27);
 cout<<cr<<cr<<cr<<cr<<cr<<cr<<" WILLIAM VASQUEZ "<<r<<" ";
 linea(6);
 cout<<cr<<cr<<cr<<cr<<cr<<cr<<cr<<cr<<cr<<cr<<cr<<" 2018 ";
 linea(10);
 linea(27);
 cout<<cr<<" Apoya el Software Libre "<<cr<<endl;
 cout<<cr<<"   y el codigo abierto   "<<cr<<endl;
 linea(27);
 getchar();
}
void juego(){
    system("color 0f");
    system("cls");
    cout<<"Las Torres de Hanoi\n"<<endl<<endl;
    cout<<"Digite la cantidad de discos: ";
    cin>>n;
    while(n>13||n<3){
        system("cls");
        cout<<"Tiene que jugar minimo con tres discos y maximo con 13"<<endl<<"Digite la cantidad de discos:";
        cin>>n;
    }
    tam=n+(n-1);
    for(i=1;i<=((tam*3)+3)+1;i++)
        cout<<fondo;
    cout<<endl<<fondo;
    for(i=0;i<n;i++){
        for(j=0;j<3;j++){
              if(j==0)
                  matriz[i][j]=i+1;
              else
                  matriz[i][j]=0;
              for(k=1;k<=tam;k++){
                   tamdisco=matriz[i][j]+(matriz[i][j]-1);
                   espacios=(tam-tamdisco)/2;
                   if(matriz[i][j]==0)
                       cout<<fondo;    
                   else{
                       if(k<=espacios||k>(tam-espacios))
                           cout<<fondo;
                       else
                           cout<<"*";
                   }
              }
              cout<<fondo;
        }
        cout<<endl<<fondo;
    }
    for(i=1;i<=((tam*3));i++){
        if(i==n-1)
            cout<<"T1";
        else if(i==((n*2)+n)-2)
            cout<<"T2";
        else if(i==(((n*2)+n)-3)+n*2)
            cout<<"T3";
        else
            cout<<fondo;
    }
    cout<<endl;
    for(i=1;i<=((tam*3)+4);i++)
        cout<<fondo;
    moverdisco();
}

void moverdisco()
{
    while(matriz[0][1]!=1&&matriz[0][2]!=1){
    cout<<"\n\n\t\t\tLleva "<<con++<<" movimientos\n";
    do{
        cout<<"Desde cual torre (T) desea mover el disco: ";
        cin>>desde;
        if(matriz[n-1][desde-1]==0){cout<<"No hay disco en esa torre"<<endl;}
    }
	    while(matriz[n-1][desde-1]==0);
	    cout<<"Hacia cual torre (T) desea mover el disco: ";
	    cin>>hacia;
	    desde--;
	    hacia--;
	    for(i=0;i<n;i++){
	        if(matriz[i][desde]!=0){
	        tem=matriz[i][desde];
	        tem2=i;        
	        i=n;
        	}
   		}
    for(i=n-1;i>=0;i--)
    {
        if(matriz[i][hacia]==0)
        {
            if(matriz[i+1][hacia]>tem||i==(n-1))
            {
            matriz[i][hacia]=tem;
            matriz[tem2][desde]=0;
            }
            else
            {
            cout<<"\n\nNo puede colocar un disco grande encima de uno pequeno\nni poner un disco en la misma posicion"<<endl
                <<"Cambie los parametros"<<endl;
                con--;
            moverdisco();
            }       
            i=0;
        }
    }
    system("cls");
    for(i=1;i<=((tam*3)+3)+1;i++)
        cout<<fondo;
    cout<<endl<<fondo;
    for(i=0;i<n;i++)
    {
        for(j=0;j<3;j++)
        {
              for(k=1;k<=tam;k++)
              {
                   tamdisco=matriz[i][j]+(matriz[i][j]-1);
                   espacios=(tam-tamdisco)/2;
                   if(matriz[i][j]==0)
                      cout<<fondo;
                   else
                   {
                       if(k<=espacios||k>(tam-espacios))
                           cout<<fondo;
                       else
                           cout<<"*";
                   }
              }
              cout<<fondo;
        }
        cout<<endl<<fondo;
    }
    for(i=1;i<=((tam*3));i++)
    {
        if(i==n-1)
            cout<<"T1";
        else if(i==((n*2)+n)-2)
            cout<<"T2";
        else if(i==(((n*2)+n)-3)+n*2)
            cout<<"T3";
        else
            cout<<fondo;
    }
    cout<<endl;
    for(i=1;i<=((tam*3)+4);i++)
        cout<<fondo;
    }
    system("color f1");
    cout<<"\n\nFelicitaciones acaba de ganar en "<<con<<" movimientos\n\nDesea volver a jugar S/N: ";
    cin>>si;
    con=0;
    if(si=='s'||si=='S')
        main();
    else
        salir();
    getchar();
}

//fincion para nuemros aleatorios
void numAleatorios(){
	//decalracion de variables
    int vector [101];//
	int i;//
	int j;//
	int temp;
	
	
	cout<<"numeros randoms generados: "<<endl;
	for (i=0;i<=100; i++)
	{
		
		vector[i]= rand()%100;
	
		cout<<"\t - "<<vector[i]<<"\n";
	}

	cout<<endl;
	cout<<endl;
	

	cout<<"numeros randoms: "<<endl;
	
	for(i=1; i<=100; i++)
	{
		for(j=i+1; j<=100; j++)
		{
			
			if(vector [j] < vector[i])
			{
				
				temp=vector[j];
				vector[j]=vector[i];
				vector[i]=vector[j];
				vector[i]=temp;
			}
			
		}
	}
	
	
	for(i=1; i<=100; i++)
	{
		
		cout<<i<<") "<<vector[i];
		cout<<endl;
	}
}
