/*
Universidad de La Laguna
Grado en Ingenieria Informatica
Asignatura: Algoritmos y Estructuras de Datos Avanzadas
Curso: 19/20
Practica #3: Juego de la vidade Conway (Conway's Game of life)
Breve descripcion: Generar el automata celular simulador de vida dise�ado por 
J. Conway en 1970

Fichero "tablero.hpp" - Declaracion de la clase y metodos del tablero/malla donde 
se encuentran las celulas.
*/

#pragma once

#include <iostream>
#include <vector>
#include <cstdlib>
#include <unistd.h>

#include "celula.hpp"
#include "celula1.hpp"
#include "celula2.hpp"
#include "celula3.hpp"

using namespace std;

//Prototipo para solucionar el problema de la dependencia circular.
class Celula;

class Tablero{
  private:
    int n_; //FILAS
    int m_; //Columnas
    int turnos_;
    vector< vector< Celula* > > tabla;
    
    //Metodo privado
    void jugarTurno(int);
    void mostrarTablero(ostream& os );
    
    
  public:
  	
  	//Constructores y destructor
    Tablero();
    Tablero(int, int, int);
    ~Tablero();
    
		void jugar();
		Celula* getPos(int i, int j) const;
  
};
