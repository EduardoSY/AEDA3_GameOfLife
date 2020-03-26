/*
Universidad de La Laguna
Grado en Ingenieria Informatica
Asignatura: Algoritmos y Estructuras de Datos Avanzadas
Curso: 19/20
Practica #3: Juego de la vida de Conway (Conway's Game of life) (Mas reglas)
Breve descripcion: Generar el automata celular simulador de vida dise�ado por 
J. Conway en 1970. Añadiremos más tipos de celulas, cada una con sus 
reglas concretas.

Fichero "celula2.cpp" - Implementacion de los metodos de la clase derivada celula2.
*/

#include "celula2.hpp"

Celula2::Celula2(int i, int j){
  i_ = i;
  j_ = j;
  tipo = 2;
  //alive_ = 0;
  vecinas_vivas_ = 0;
  //cout << "cel 2 con i" << i_ << " y j " << j_ << endl;
}

int Celula2::actualizarEstado(){
  //Regla de supervivencia tipo 1
  if ((vecinas_vivas_ == 2) || (vecinas_vivas_ == 4) || (vecinas_vivas_ == 5)) {
    return 2; //tipo de celula
  }else{
    return 0;
  }
}

ostream& Celula2::mostrarSimbolo(ostream& os) const {
  cout << "2";
  //return os;
}


/*
std::ostream& operator<<(std::ostream& os, const cell1& cell)
{
    return cell.show(os);
}
*/