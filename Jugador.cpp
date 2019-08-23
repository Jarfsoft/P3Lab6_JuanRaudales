#include <iostream>
#include <string.h>
#include <bits/stdc++.h>
#include <vector>

#ifndef JUGADOR_CPP
#define JUGADOR_CPP

using namespace std;

class Jugador
{
	private:
		string nombre;
		string dorsal;
		string pais;
		
	public:
		Jugador(){}
		Jugador(string nom, string dor, string pa)
		{
			nombre=nom;
			dorsal=dor;
			pais=pa;
		}
		string getNombre()
		{
			return nombre;
		}
		string getDorsal()
		{
			return dorsal;
		}
		string getPais()
		{
			return pais;
		}
		
		void setNombre(string nom)
		{
			nombre=nom;
		}
		
		void imp()
		{
			cout<<"Nombre: "<<nombre<<"\tDorsal: "<<dorsal<<"\tPais: "<<pais;
		}
		
		~Jugador(){}
		
		
};

#endif
