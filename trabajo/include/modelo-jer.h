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


//______CLASES PARA EL CUERPO ________
class Cuerpo : public NodoGrafoEscena
{
 public:
  Cuerpo ();
};

class BaseCuerpo: public NodoGrafoEscena
{
public:
  BaseCuerpo();
};

  
class Cabina : public NodoGrafoEscena
{
public:
  Cabina(); 
};
class ParaGolpes : public NodoGrafoEscena
{
public:
  ParaGolpes(); 
};


// __________ CLASES PARA TURBINA __________
class Turbina: public NodoGrafoEscena
{
public:
  Turbina(); 
};


class EspigaTurbina: public NodoGrafoEscena
{
public:
  EspigaTurbina(); 
};

class Aspa: public NodoGrafoEscena
{
public: Aspa(); 
};

class Turbina2: public NodoGrafoEscena
{
public: Turbina2();  
};


// _________- mirilla________

class Mirilla: public NodoGrafoEscena
{
public: Mirilla();  
};


#endif

