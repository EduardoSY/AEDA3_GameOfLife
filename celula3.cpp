/*
Universidad de La Laguna
Grado en Ingenieria Informatica
Asignatura: Algoritmos y Estructuras de Datos Avanzadas
Curso: 19/20
Practica #3: Juego de la vida de Conway (Conway's Game of life) (Mas reglas)
Breve descripcion: Generar el automata celular simulador de vida dise�ado por 
J. Conway en 1970. Añadiremos más tipos de celulas, cada una con sus 
reglas concretas.

Fichero "celula3.cpp" - Implementacion de los metodos de la clase derivada celula3.
*/

#include "celula3.hpp"

Celula3::Celula3(int i, int j){
  i_ = i;
  j_ = j;
  tipo = 3;
  //alive_ = 0;
  vecinas_vivas_ = 0;
  //cout << "cel 3 con i" << i_ << " y j " << j_ << endl;
}

int Celula3::actualizarEstado(){
  //Regla de supervivencia tipo 1
  if ((vecinas_vivas_ == 1) || (vecinas_vivas_ == 5)) {
    return 3; //tipo de celula
  }else{
    return 0;
  }
}

ostream& Celula3::mostrarSimbolo(ostream& os) const {
  cout << "3";
  //return os;
}


/*
std::ostream& operator<<(std::ostream& os, const cell1& cell)
{
    return cell.show(os);
}
*/