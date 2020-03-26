/*
Universidad de La Laguna
Grado en Ingenieria Informatica
Asignatura: Algoritmos y Estructuras de Datos Avanzadas
Curso: 19/20
Practica #3: Juego de la vida de Conway (Conway's Game of life) (Mas reglas)
Breve descripcion: Generar el automata celular simulador de vida dise�ado por 
J. Conway en 1970. Añadiremos más tipos de celulas, cada una con sus 
reglas concretas.

Fichero "celula1.cpp" - Implementacion de los metodos de la clase derivada celula1.
*/

#include "celula1.hpp"

Celula1::Celula1(int i, int j){
  i_ = i;
  j_ = j;
  tipo = 1;
  //alive_ = 0;
  vecinas_vivas_ = 0;
  //cout << "cel 1 con i" << i_ << " y j " << j_ << endl;
}

int Celula1::actualizarEstado(){
  //Regla de supervivencia tipo 1
  if ((vecinas_vivas_ == 2) || (vecinas_vivas_ == 3)) {
    return 1; //tipo de celula
  }else{
    return 0;
  }
}

ostream& Celula1::mostrarSimbolo(ostream& os) const {
  cout << "1";
  //return os;
}


/*
std::ostream& operator<<(std::ostream& os, const cell1& cell)
{
    return cell.show(os);
}
*/