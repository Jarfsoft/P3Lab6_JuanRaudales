#include "Liga.cpp"
#include <fstream>
#include <stdlib.h>

using namespace std;

int buscarLiga(vector<Liga*>, string);
bool hayEquipos(vector<Liga*>);
string separar(string, string, string );
string ultimoDesde(string, string);
string primeroHasta(string, string);
bool findSimbol(string, string);
string token(string, string, int);
int contarCaracter(string, string);

int main()
{
	vector<Liga*> ligas;
	srand (time(NULL));
	int opcion=0;
	
	while(opcion!=8)
	{
		cout<<"*******************Administracion de Ligas de Futbol*******************\n\n1. Administrar ligas\n2. Administrar equipos\n3. Administrar Jugadores\n4. Jugar Partido\n5. Cargar archivo\n6. Guardar archivo\n7. Ver tablas\n8. Salir\n\nSeleccion: ";
		cin>>opcion;
		if(opcion==1)
		{
			opcion=0;
			while(opcion!=3)
			{
				cout<<"\n\n1. Crear liga\n2. Borrar liga\n3. Regresar\n\nSeleccion: ";
				cin>>opcion;
				if(opcion==1)
				{
					Liga *nuevo;
					string nom, pa;
					
					cout<<"\n\nIntroducir el nombre de la nueva liga: ";
					cin>>nom;
					cout<<"Pais de origen: ";
					cin>>pa;
					
					nuevo=new Liga(nom,pa);
					
					ligas.push_back(nuevo);
					
					cout<<"\n\nLiga creada exitosamente.";
				}
				if(opcion==2)
				{
					string nom;
					cout<<"\n\nIntroduzca el nombre de la liga que desea eliminar: ";
					cin>>nom;
					int pos=buscarLiga(ligas,nom);
					if(pos==-1)
					{
						cout<<"\n\nNo se pudo encontrar la liga;";
					}else
					{
						ligas.at(pos)->~Liga();
						ligas.erase(ligas.begin()+pos);
						cout<<"\n\nLiga Eliminada.";
					}
					
				}
				cout<<"\n\n";
			}
			opcion=0;
		}
		if(opcion==2)
		{
			opcion=0;
			while(opcion!=3)
			{
				cout<<"\n\n1. Crear Equipo\n2. Borrar Equipo\n3. Regresar\n\nSeleccion: ";
				cin>>opcion;
				if(opcion==1)
				{
					if(ligas.size()!=0)
					{
						Equipo *nuevo;
						string nom, an;
						cout<<"\n\nIngresar nombre del equipo: ";
						cin>>nom;
						cout<<"Anio de fundacion: ";
						cin>>an;
						
						cout<<"\n\n";
						
						int pos;
						for(int x=0;x<ligas.size();x++)
						{
							cout<<x+1<<": ";
							ligas.at(x)->imprimir();
							cout<<endl;
						}
						cout<<"\n\nElija el numero de liga para asignar: ";
						cin>>pos;
						pos--;
						
						nuevo= new Equipo(nom,an);
						
						ligas.at(pos)->asignarEquipo(nuevo);
						
						cout<<"\n\nEquipo creado exitosamente.";
					}else
					{
						cout<<"\n\nNo hay Ligas para asignar equipos";
					}
					
				}
				if(opcion==2)
				{
					if(ligas.size()!=0)
					{
						cout<<"\n\n";
						int pos, pos2;
						for(int x=0;x<ligas.size();x++)
						{
							cout<<x+1<<": ";
							ligas.at(x)->imprimir();
							cout<<endl;
						}
						cout<<"\n\nSeleccione el numero de la liga que contiene al equipo: ";
						cin>>pos;
						pos--;
						cout<<"\n\n";
						ligas.at(pos)->imprimir();
						cout<<"\n\nSeleccione el numero del equipo que desea eliminar: ";
						cin>>pos2;
						pos2--;
						ligas.at(pos)->eliminarEquipo(pos2);
						
						cout<<"\n\nEquipo Eliminado";
					}else
					{
						cout<<"\n\nNo hay Ligas.";
					}
						
					
				}
				cout<<"\n\n";
			}
			opcion=0;
			
		}
		if(opcion==3)
		{
			opcion=0;
			while(opcion!=3)
			{
				cout<<"\n\n1. Crear Jugador\n2. Borrar Jugador\n3. Regresar\n\nSeleccion: ";
				cin>>opcion;
				if(opcion==1)
				{
					if(hayEquipos(ligas))
					{
						Jugador *nuevo;
						string nom, dor, pa;
						cout<<"\n\nIngresar nombre del jugador: ";
						cin>>nom;
						cout<<"Dorsal: ";
						cin>>dor;
						cout<<"Pais de origen: ";
						cin>>pa;
						
						cout<<"\n\n";
						
						int pos;
						for(int x=0;x<ligas.size();x++)
						{
							cout<<x+1<<": ";
							ligas.at(x)->imprimir();
							cout<<endl;
						}
						cout<<"\n\nElija el numero de liga para asignar: ";
						cin>>pos;
						pos--;
						
						nuevo= new Jugador(nom,dor,pa);
						
						int pos2;
						
						cout<<"\n\nEquipos:\n";
						
						ligas.at(pos)->imprimir();
						cout<<endl;
							
						cout<<"\n\nElija un equipo para asignar: ";
						cin>>pos2;
						pos2--;
						
						ligas.at(pos)->getEquipos().at(pos2)->asignarJugador(nuevo);
						
						cout<<"\n\nJugador creado exitosamente.";
						
					}else
					{
						cout<<"\n\nNo existen equipos para asignar Jugadores.";
					}
					
				}
				if(opcion==2)
				{
					if(hayEquipos(ligas))
					{
						cout<<"\n\n";
						int pos, pos2, pos3;
						for(int x=0;x<ligas.size();x++)
						{
							cout<<x+1<<": ";
							ligas.at(x)->imprimir();
							cout<<endl;
						}
						cout<<"\n\nSeleccione el numero de la liga que contiene al equipo: ";
						cin>>pos;
						pos--;
						cout<<"\n\n";
						ligas.at(pos)->imprimir();
						cout<<"\n\nSeleccione el numero del equipo que contiene el jugador: ";
						cin>>pos2;
						pos2--;
						
						ligas.at(pos)->getEquipos().at(pos2)->impr();
						
						cout<<"\n\nSeleccione el numero del Jugador que desea eliminar: ";
						cin>>pos3;
						pos3--;
						
						ligas.at(pos)->getEquipos().at(pos2)->eliminarJugador(pos3);
						
						cout<<"\n\nJugador Eliminado";
					}else
					{
						cout<<"\n\nNo hay equipos";
					}
						
					
				}
				cout<<"\n\n";
			}
			
			
		}
		if(opcion==4)
		{
			cout<<"\n\n";
			int n, n2, n3;
			for(int x=0;x<ligas.size();x++)
			{
				cout<<x+1<<": ";
				ligas.at(x)->imprimir();
				cout<<endl;
			}
				
			
			cout<<"\n\nElegir una liga: ";
			cin>>n;
			n--;
			cout<<"\n\nEquipo 1: ";
			cin>>n2;
			n2--;
			cout<<"Equipo 2: ";
			cin>>n3;
			n3--;
			if(n2==n3)
			{
				cout<<"\n\nHa seleccionado el mismo equipo dos veces.";
				continue;
			}
			
		}
		if(opcion==5)
		{
			fstream Leer;
			string linea;
			Leer.open("./ligas.txt");
			Liga *nuevo;
			Equipo *nuev;
			Jugador *nue;
			ligas.erase(ligas.begin(),ligas.end());
			getline(Leer,linea);
			while(!Leer.eof())
			{
				
				if(linea.size()>0)
				{
					
					nuevo= new Liga(separar(linea,"$",":"),ultimoDesde(linea,":"));
					getline(Leer,linea);
					while(!findSimbol(linea,"$"))
					{
						nuev= new Equipo(primeroHasta(linea,":"),separar(linea,":","{"));
						string temp=separar(linea,"{","}");
						if(findSimbol(temp,";"))
						{
							int cant=contarCaracter(temp,"|");
							cant/=2;
							
							for(int x=0;x<cant;x++)
							{
								string temp2=token(temp,";",x+1);
								nue= new Jugador(token(temp2,"|",1),token(temp2,"|",2),token(temp2,"|",3));
								nuev->asignarJugador(nue);
							}
						}
							
						else
							{
								nue= new Jugador(token(temp,"|",1),token(temp,"|",2),token(temp,"|",3));
								nuev->asignarJugador(nue);
							}
						nuevo->asignarEquipo(nuev);
						getline(Leer,linea);
						if(Leer.eof())
							break;
					}
					ligas.push_back(nuevo);
				}
				Leer.close();
			}
			cout<<"\n\nArchivos cargados.";
			
			opcion=0;
		}
		if(opcion==6)
		{
			ofstream Escribir;
			Escribir.open("./ligas.txt");
			for(int x=0;x<ligas.size();x++)
			{
				Escribir<<"$"<<ligas.at(x)->getNombre()<<":"<<ligas.at(x)->getPais()<<endl;
				for(int y=0;y<ligas.at(x)->getEquipos().size();y++)
				{
					
					Escribir<<ligas.at(x)->getEquipos().at(y)->getNombre()<<":"<<ligas.at(x)->getEquipos().at(y)->getAnio()<<"{";
					for(int z=0;z<ligas.at(x)->getEquipos().at(y)->getJugadores().size();z++)
					{
						Escribir<<ligas.at(x)->getEquipos().at(y)->getJugadores().at(z)->getNombre()<<"|"<<ligas.at(x)->getEquipos().at(y)->getJugadores().at(z)->getDorsal()<<"|"<<ligas.at(x)->getEquipos().at(y)->getJugadores().at(z)->getPais();
						int temp=ligas.at(x)->getEquipos().at(y)->getJugadores().size();
						temp--;
						if(z==temp)
							Escribir<<"}";
						else
							Escribir<<";";
					}
					Escribir<<endl;
				}
				
			}
			cout<<"\n\nGuardado exitoso.";
			Escribir.close();
			
			opcion=0;
			
		}
		if(opcion==7)
		{
			
		}
		cout<<"\n\n";
	}
	
	
	return 0;
}



int buscarLiga(vector<Liga*> lista, string nom)
{
	for(int x=0;x<lista.size();x++)
	{
		if(lista.at(x)->getNombre()==nom)
			return x;
		
	}
	return-1;
	
}


bool hayEquipos(vector<Liga*> lista)
{
	for(int x=0;x<lista.size();x++)
	{
		if(lista.at(x)->getEquipos().size()!=0)
			return true;
			
	}
	return false;
}

string separar(string cadena, string simbolo1, string simbolo2)
{
	char devuelta[cadena.size()];
	if(cadena.size()>0)
		for(int x=0;x<cadena.size();x++)
			if(cadena[x]==simbolo1[0])
				for(int y=x;y<cadena.size();y++)
				{
					if(cadena[y]==simbolo2[0])
					{
						devuelta[y-x-1]=NULL;
						return devuelta;
					}
					if(y>x)
						devuelta[y-x-1]=cadena[y];
				}
	return "";
}

string ultimoDesde(string cadena, string simbolo)
{
	char devuelta[cadena.size()];
	if(cadena.size()>0)
		for(int x=0;x<cadena.size();x++)
			if(cadena[x]==simbolo[0])
				for(int y=x;y<cadena.size();y++)
				{
					if(y>x)
						devuelta[y-x-1]=cadena[y];
						
				}
	return devuelta;
}

bool findSimbol(string cadena, string simbolo)
{
	for(int x=0;x<cadena.size();x++)
	{
		if(cadena[x]==simbolo[0])
			return true;
	}
	return false;
}
string primeroHasta(string cadena, string simbolo)
{
	char devuelta[cadena.size()];
	if(cadena.size()>0)
		for(int x=0;x<cadena.size();x++)
			if(cadena[x]!=simbolo[0])
				devuelta[x]=cadena[x];
			else
				return devuelta;
}
string token(string cadena, string divisor, int pos){
       if(cadena.size()>0){
         char oracion[cadena.size()]; 
         for (int i=0;i<=cadena.size();i++)
         {
               oracion[i]=cadena[i];
         }                    
         char *ptrtoken; 
         int num=1;
         const char* d=divisor.c_str();
         ptrtoken = strtok(oracion , d);             
         while(ptrtoken){
             if(num==pos){ 
                return ptrtoken;                    
             }                 
             ptrtoken = strtok(NULL, d);
             num++;
         }
         return "";
       }else{
             return "";
       }
}

int contarCaracter(string cadena, string simbolo)
{
	int n=0;
	for(int x=0;x<cadena.size();x++)
		if(cadena[x]==simbolo[0])
			n++;
			
			
	return n;
}
