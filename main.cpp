/*
Universidad de La Laguna
Grado en Ingenieria Informatica
Asignatura: Algoritmos y Estructuras de Datos Avanzadas
Curso: 19/20
Practica #3: Juego de la vidade Conway (Conway's Game of life)
Breve descripcion: Generar el automata celular simulador de vida dise�ado por 
J. Conway en 1970

Fichero "main.cpp" - Fichero principal main. En el se piden los parametros 
iniciales para establecer el tablero y ejecutar el "juego" 
*/

#include <iostream>
#include <cstdlib>

#include "celula.hpp"
#include "tablero.hpp"

using namespace std;

int main(void){
  system("clear");
  try{
  cout << ".: GAME OF LIFE :." << endl;
  cout << "Introduce numero de filas: ";
  int filas;
  cin >> filas;
  
  cout << "Introduce numero de columnas: ";
  int columnas;
  cin >> columnas;
  
  cout << "Introduce numero de turnos: ";
  int turnos;
  cin >> turnos;
  Tablero tabla(filas, columnas, turnos);
  tabla.jugar();
  
  }catch (exception& ex){
    cout << ex.what();
  }
  return 0;
}
