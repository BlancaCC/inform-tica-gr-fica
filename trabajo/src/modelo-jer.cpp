/**
   Fichero: modelo-jer.cpp 
   Autora: Blanca cano Camarero 
   Descripción: implemtación del fichero modelo-jer.cpp
 */

#include "modelo-jer.h"
#include "malla-ind.h"
#include "malla-revol.h"
#include "matrices-tr.h"
#include "materiales-luces.h"
#include <cmath>

// por si declaro funciones extras
/**
#include "funciones-aux.h"
#include "clases-aux.h"
*/
// _______ clase raíz ________

Submarino:: Submarino()
{
  ponerNombre("Submarinillo");
  agregar( new Cuerpo() ); 
}



Cuerpo :: Cuerpo ( ) 
{
  // parámetor de nuestro paraboloide 

  const float semieje_x = 2; 
  const float semieje_y = 1; 

  const int num_verts_per = 20; 
  const unsigned nperfiles = 20;
  
  agregar( MAT_Escalado( semieje_x, semieje_y, semieje_y));
  agregar( new Esfera( num_verts_per, nperfiles));

  ponerNombre("Cuerpo ")
  ponerIdentificador(-1); 
  
}
