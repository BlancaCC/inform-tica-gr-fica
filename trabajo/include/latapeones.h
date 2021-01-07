#ifndef LATAPEONES_H
#define LATAPEONES_H

#include "objeto3d.h"
#include "grafo-escena.h"


class LataPeones : public NodoGrafoEscena
{
  
public:

  LataPeones(); 
};

class Lata : public NodoGrafoEscena
{
    public:
  Lata(const std::string nombre, const std::string & texturaJPG);

};


class LataTapaSup : public NodoGrafoEscena
{
  
public:

  LataTapaSup(); 
};




class LataTapaInf : public NodoGrafoEscena
{
  
public:

  LataTapaInf(); 
};


class Peon : public NodoGrafoEscena
{
    public:
  Peon(const std::string nombre, const std::string & texturaJPG);

};


#endif
