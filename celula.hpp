/*
Universidad de La Laguna
Grado en Ingenieria Informatica
Asignatura: Algoritmos y Estructuras de Datos Avanzadas
Curso: 19/20
Practica #3: Juego de la vida de Conway (Conway's Game of life) (Mas reglas)
Breve descripcion: Generar el automata celular simulador de vida dise�ado por 
J. Conway en 1970. Añadiremos más tipos de celulas, cada una con sus 
reglas concretas.

Fichero "celula.hpp" - Declaracion de la clase y metodos de las celulas que 
rellenaran el tablero.
*/

#pragma once

#include <iostream>


using namespace std;

#define CONDALIVEC1 (vecinas_vivas_ == 3)
#define CONDALIVEC2 (vecinas_vivas_ == 3 || vecinas_vivas_ == 6 || vecinas_vivas_ == 8)
#define CONDALIVEC3 (vecinas_vivas_ == 3 || vecinas_vivas_ == 4 || vecinas_vivas_ == 6)

//Declaramos un prototipo para solucionar la dependencia circular.
class Tablero;

class Celula{
  protected:
    int tipo;
    //int alive_ = 0; //Valores: 0 = MUERTA 1 = VIVA
    int i_;
    int j_;
    int vecinas_vivas_;
    
  public:
    //Constructores y destructor
    Celula();
    Celula(int, int);
    ~Celula();

    static Celula* createCelula(int, int, int);
  
    //Ahora Estado pasa a significar TIPO de celula
    virtual int getEstado() const;
    int setEstado(int); 
    
    int geti() const;
    int getj() const;
    void seti(int);
    void setj(int);
 
    virtual int actualizarEstado();
    virtual ostream& mostrarSimbolo(ostream& os) const;
    virtual int contarVecinas(const Tablero&);
};

//Sobrecarga del operador
//ostream& operator<<(ostream& os, const Celula& cell);
