/*
Universidad de La Laguna
Grado en Ingenieria Informatica
Asignatura: Algoritmos y Estructuras de Datos Avanzadas
Curso: 19/20
Practica #3: Juego de la vida de Conway (Conway's Game of life) (Mas reglas)
Breve descripcion: Generar el automata celular simulador de vida dise�ado por 
J. Conway en 1970. Añadiremos más tipos de celulas, cada una con sus 
reglas concretas.

Fichero "celula1.hpp" - Declaracion de la clase derivada y sus metodos.
*/

#pragma once

#include <iostream>
#include "celula.hpp"

using namespace std;

class Celula1 : public Celula{
  
  public:
  Celula1();
  Celula1(int i, int j);
  ~Celula1();

  int actualizarEstado();
  ostream& mostrarSimbolo(ostream&) const;
};