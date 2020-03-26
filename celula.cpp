/*
Universidad de La Laguna
Grado en Ingenieria Informatica
Asignatura: Algoritmos y Estructuras de Datos Avanzadas
Curso: 19/20
Practica #3: Juego de la vida de Conway (Conway's Game of life) (Mas reglas)
Breve descripcion: Generar el automata celular simulador de vida dise�ado por 
J. Conway en 1970. Añadiremos más tipos de celulas, cada una con sus 
reglas concretas.

Fichero "celula.cpp" - Implementacion de los metodos de la clase base celula.
*/

#include <iostream>

#include "tablero.hpp"
#include <exception>
using namespace std;

struct error : std::exception {
  const char* what() const noexcept {return "Tipo de celula no conocida\n";}
};


// Constructores y destructor
Celula::Celula(){}

Celula::Celula(int i,int j){
  i_ = i;
  j_ = j;
  tipo = 0;
  //alive_ = 0;
  vecinas_vivas_ = 0;
}

Celula::~Celula(){ }

// Setters y Getters
int Celula::getEstado() const{
  return tipo;
}

int Celula::setEstado(int state){
  tipo = state;
}

int Celula::geti() const{
  return i_;
}

int Celula::getj() const{
  return j_;
}

void Celula::seti(int i){
  i_ = i;
}

void Celula::setj(int j){
  j_ = j;
}

//Funciones publicas
 Celula* Celula::createCelula(int tipo, int i, int j){
  Celula* celulaActual;
  switch(tipo){
    case 0: celulaActual = new Celula(i, j); break;
    case 1: celulaActual = new Celula1(i, j); break;
    case 2: celulaActual = new Celula2(i, j); break;
    case 3: celulaActual = new Celula3(i, j); break;
    default: throw error(); break;//cout << "F" << endl;
  }
  return celulaActual;
}


int Celula::actualizarEstado(){
  if(vecinas_vivas_ == 3){
    return 1;
  }else if ((vecinas_vivas_ == 6) || (vecinas_vivas_ == 8)){
    return 2;
  }else if (vecinas_vivas_ == 4){
  	return 3;
	}else{
    return -1;
  }
}

int Celula::contarVecinas(const Tablero& tablero){
/*
1 2 3
4 X 5
6 7 8
*/
  int vecinas = 0;
  if(tablero.getPos(i_-1, j_-1)->getEstado() != 0)
  vecinas += 1;  //1
  if(tablero.getPos(i_-1, j_)->getEstado() != 0)
  vecinas += 1;  //2
  if(tablero.getPos(i_-1, j_+1)->getEstado() != 0)
  vecinas += 1;  //3
  if(tablero.getPos(i_, j_-1)->getEstado() != 0)
  vecinas += 1;  //4
  if(tablero.getPos(i_, j_+1)->getEstado() != 0)
  vecinas += 1;  //5
  if(tablero.getPos(i_+1, j_-1)->getEstado() != 0)
  vecinas += 1;  //6
  if(tablero.getPos(i_+1, j_)->getEstado() != 0)
  vecinas += 1;  //7
  if(tablero.getPos(i_+1, j_+1)->getEstado() != 0)
  vecinas += 1;  //8
  //cout << "CELULAS VECINAS [" << i_ << " " << j_ << "]: " << vecinas << endl;
  vecinas_vivas_ = vecinas;
  return vecinas;
}

ostream& Celula::mostrarSimbolo(ostream& os) const{
  cout << " ";
}

//Sobrecarga del operador <<
/*
ostream& operator<<(ostream& os, const Celula& cell){
  if(cell.getEstado() == 1){
    cout << "X";
  }else if(cell.getEstado() == 0){
    cout << " "; 
  }
  
}
*/



