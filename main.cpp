#include "Liga.cpp"
#include <fstream>
#include <stdlib.h>


using namespace std;

int buscarLiga(vector<Liga*>, string);
bool hayEquipos(vector<Liga*>);


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
			
		}
		if(opcion==5)
		{
			
			
			opcion=0;
		}
		if(opcion==6)
		{
			
			
		}
		if(opcion==7)
		{
			
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

