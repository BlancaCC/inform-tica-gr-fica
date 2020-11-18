/**
Fichero: modelo-jer.h  
Autora: Blanca Cano Camarero  
Descripción: Práctica 3, declaración de las clases derivadas de NodoGrafoEscena. Conforman el modelo jerárquico, para más información ver pdf con documentación. 
 */
#ifndef MODELO_JER_H
#define MODELO_JER_H

#include "grafo-escena.h"


//nodo raíz del grafo

class Submarino: public NodoGrafoEscena
{
 protected:
  // matrices que le dan movimiento a mi objeto
  
  //Matriz4f * translacion = nullptr;


  //void actualizarEstadoParametro( const unsigned iParam, const float t_sec);

 public:

  Submarino();

  //unsigned leerNumParametros() const;

  // translaciones 
  //void fijarTraslacion(const float n_translacion);
};


// ____________ RESTO DE NODOS DEL GRAFO  ________

class Cuerpo : public NodoGrafoEscena
{
 public:
  Cuerpo ();
};

class Ventana : public NodoGrafoEscena
{
public:
  Ventana(); 
};

#endif

