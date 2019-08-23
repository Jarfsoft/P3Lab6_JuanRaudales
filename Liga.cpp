#include "Equipo.cpp"

#ifndef LIGA_CPP
#define LIGA_CPP

class Liga
{
	private:
		string nombre;
		string pais;
		vector<Equipo*> equipos;
		
	public:
		Liga(){}
		Liga(string nom, string pa)
		{
			nombre=nom;
			pais=pa;
		}
		string getNombre()
		{
			return nombre;
		}
		string getPais()
		{
			return pais;
		}
		
		
		void setNombre(string nom)
		{
			nombre=nom;
		}
		
		void asignarEquipo(Equipo* nuevo)
		{
			equipos.push_back(nuevo);
		}
		
		void imprimir()
		{
			cout<<"Nombre: "<<nombre<<"\tPais: "<<pais;
			cout<<"\nEquipos:\n";
			for(int x=0;x<equipos.size();x++)
			{
				cout<<x+1<<": ";
				equipos.at(x)->impr();
				cout<<endl;
			}
		}
		
		void eliminarEquipo(int pos)
		{
			equipos.at(pos)->~Equipo();
			equipos.erase(equipos.begin()+pos);
			
		}
		
		vector<Equipo*> getEquipos()
		{
			return equipos;
		}
		
		~Liga(){}
		
};

#endif
