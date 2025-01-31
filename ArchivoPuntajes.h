#ifndef ARCHIVOPUNTAJES_H
#define ARCHIVOPUNTAJES_H
#include <string>
#include <vector>
using namespace std;

struct jugador{
	int puntos;
	string nombre;
};


class ArchivoPuntajes {
public:
	ArchivoPuntajes(int puntaje,string texto);
	void agregarJugador(int puntaje,  string nombre);
	void guardarArchivo();
	void cargarJugadores();
private:
	int m_puntaje;
	string m_texto;
	string archivoNombre="ranking.txt";
	vector<jugador>jugadores;
	
	
};

#endif

