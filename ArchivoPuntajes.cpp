#include "ArchivoPuntajes.h"
#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


bool compararPorPuntos(const jugador &a, const jugador &b) {
	return a.puntos > b.puntos;
}

ArchivoPuntajes::ArchivoPuntajes(int puntaje,string texto):m_puntaje(puntaje),m_texto(texto) {
	
	cargarJugadores();
	agregarJugador(m_puntaje, m_texto);
	guardarArchivo();
	
}
void ArchivoPuntajes::cargarJugadores() {
	ifstream inFile(archivoNombre);
	
	jugador aux;
	while (getline(inFile, aux.nombre) and inFile >> aux.puntos) {
		jugadores.push_back(aux);
	}
	
	inFile.close();
}

void ArchivoPuntajes::agregarJugador(int puntaje,  string nombre) {
	jugador aux;
	aux.puntos = puntaje;
	aux.nombre = nombre;
	jugadores.push_back(aux);
	sort(jugadores.begin(), jugadores.end(), compararPorPuntos);
}

void ArchivoPuntajes::guardarArchivo() {
	ofstream outFile(archivoNombre, ios::trunc);
	for(size_t i=0;i<jugadores.size();++i){
		outFile<<jugadores[i].nombre;
		outFile<<jugadores[i].puntos<<endl;
	}
	outFile.close();
}

