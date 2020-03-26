/*
Universidad de La Laguna
Grado en Ingenieria Informatica
Asignatura: Algoritmos y Estructuras de Datos Avanzadas
Curso: 19/20
Practica #3: Juego de la vidade Conway (Conway's Game of life)
Breve descripcion: Generar el automata celular simulador de vida dise�ado por 
J. Conway en 1970

Fichero "tablero.cpp" - Implementacion de los metodos de la clase tablero.
*/

#include <iostream>

#include "tablero.hpp"

using namespace std;

//Constructores

Tablero::Tablero(){ }

Tablero::Tablero(int filas, int columnas, int turnos){
  n_ = filas + 2;
  m_ = columnas + 2;
  turnos_ = turnos;
  
  
  for(int i = 0; i < n_; i++){ // cantidad filas
    vector<Celula*> temp;
    for(int j = 0; j < m_; j++){
      temp.push_back(new Celula(i,j));
    }
    tabla.push_back(temp);
  }
  
}

//Destructor

Tablero::~Tablero(){}

// METODO PUBLICO
//Jugar: Pide las celulas y ejecuta el automata en base a la indicaciones anteriores (turnos y tamanho)
void Tablero::jugar(){
  cout << "## GAME OF LIFE ##" << endl;
  cout << endl << "Numero de celulas de inicio vivas: ";
  int num_cell;
  cin >> num_cell;
  for(int i = 0; i < num_cell; i++){
    cout << "Coordenada X de celula [" << i+1 << "]: ";
    int x;
    cin >> x;
    cout << "Coordenada Y de celula [" << i+1 << "]: ";
    int y;
    cin >> y;
    cout << "Tipo de la celula [" << i+1 << "]: ";
    int z;
    cin >> z;
    tabla[y][x] = tabla[y][x]->createCelula(z,y,x);
    cout << endl;
  }
  cout << endl << "~~~ Celulas establecidas ~~~" << endl;
  
  cout << "-- TABLERO INICIAL --" << endl;
  mostrarTablero(cout);
  system("pause");
  system("cls");
  
  for(int i = 0; i < turnos_; i++){
    jugarTurno(i);
  }
}

Celula* Tablero::getPos(int i, int j) const{
  return tabla[i][j];
}

// METODOS PRIVADOS
//Muestra en pantalla la informacion de cada turno
void Tablero::jugarTurno(int turno_actual){
    sleep(1);
    system("cls");  
  
    cout << "TURNO [" << turno_actual + 1 << "]" << endl;
    //recorrer para contar
    for(int j = 1; j < n_ -1; j++){
      for(int k = 1; k < m_ -1; k++){
        tabla[j][k]->contarVecinas(*this);
      }
    }
    //cout << "DONE" << endl;
    int tipocelula;
    for(int j = 1; j < n_ -1; j++){
      for(int k = 1; k < m_ -1; k++){
        tipocelula = tabla[j][k]->actualizarEstado();
        //cout << "[" << j << "," << k << "] = " << tipocelula << endl;
        if(tipocelula != -1){
          Celula* ptr = tabla[j][k];
          tabla[j][k] = tabla[j][k]->createCelula(tipocelula, j, k);
          delete ptr;
        }
      }
    }
    //cout << "DONE 2" << endl;
    
    mostrarTablero(cout);
}


void Tablero::mostrarTablero(ostream& os){
    // os << " ";
    //for(int i = 1; i < m_-1; i++)
      //os << i;
    //os << endl;
  for(int i = 0; i < m_; i++)
    os << "-";
    os << endl;
  
  for(int i = 1; i < n_-1; i++){
    cout <<"|";
    for( int j = 1; j < m_-1; j++){
      tabla[i][j]->mostrarSimbolo(os);
    }
    cout << "|" << endl;
  }
  
  for(int i = 0; i < m_; i++)
    os << "-";
  os << endl;
}

