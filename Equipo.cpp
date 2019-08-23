#include "Jugador.cpp"

#ifndef EQUIPO_CPP
#define EQUIPO_CPP

class Equipo
{
	private:
		string nombre;
		string anio;
		vector<Jugador*> jugadores;
		int gf;
		int gc;
		int pg;
		int pj;
		int pp;
		int pe;
		
	public:
		Equipo(){}
		Equipo(string nom, string an)
		{
			nombre=nom;
			anio=an;
			gf=0;
			gc=0;
			pg=0;
			pj=0;
			pp=0;
			pe=0;
		}
		string getNombre()
		{
			return nombre;
		}
		
		void setNombre(string nom)
		{
			nombre=nom;
		}
		string getAnio()
		{
			return anio;
		}
		
		void impr()
		{
			cout<<"Nombre: "<<nombre<<"\tAnio de Fundacion: "<<anio;
			cout<<"\nJugadores:\n";
			for(int x=0;x<jugadores.size();x++)
			{
				cout<<x+1<<": ";
				jugadores.at(x)->imp();
				cout<<endl;
			}
		}
		vector<Jugador*> getJugadores()
		{
			return jugadores;
		}
		void asignarJugador(Jugador *nuevo)
		{
			jugadores.push_back(nuevo);
		}
		
		void eliminarJugador(int pos)
		{
			jugadores.erase(jugadores.begin()+pos);
		}
		
		void setGF(int n)
		{
			gf+=n;
		}
		void setGC(int n)
		{
			gc+=n;
		}
		void setPG(int n)
		{
			pg+=n;
		}
		void setPP(int n)
		{
			pp+=n;
		}
		void setPE(int n)
		{
			pe+=n;
		}
		void setPJ(int n)
		{
			pj+=n;
		}
		
		int getGF()
		{
			return gf;
		}
		int getGC()
		{
			return gc;
		}
		int getPG()
		{
			return pg;
		}
		int getPP()
		{
			return pp;
		}
		int getPE()
		{
			return pe;
		}
		int getPJ()
		{
			return pj;
		}
		~Equipo(){}
		
};

#endif

