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
#include "colores-aux.h"
/**
#include "funciones-aux.h"
#include "clases-aux.h"
*/
// _______ clase raíz ________

Submarino:: Submarino()
{
  ponerNombre("Submarinillo");
  //agregar( new Cuerpo() );
  //agregar( new Ventana());
  agregar(new Turbina());
}




Cuerpo :: Cuerpo ( ) 
{
  // parámetor de nuestro paraboloide 

  const float semieje_x = 2; 
  const float semieje_y = 1; 

  const int num_verts_per = 20; 
  const unsigned nperfiles = 20;

  ponerColor(gris);  // esta variable se define en colores-aux.h
  agregar( MAT_Escalado( semieje_x, semieje_y, semieje_y));
  agregar( new Esfera( num_verts_per, nperfiles));

  ponerNombre("Cuerpo "); 
  ponerIdentificador(-1); 
  
}


Ventana :: Ventana ()
{
  // por defecto las ventanas están en horizontal

  // parámetros a ajustar de la ventana
  const int num_verts_per = 4; 
  const unsigned nperfiles = 25; // para que salga redondo

  

  agregar(MAT_Rotacion(90.0, 0.0, 0.0, 1.0 ));
  agregar(MAT_Escalado(0.75,0.5 ,0.75 )); 
  agregar( new Cilindro( num_verts_per, nperfiles));
  ponerColor(azul); 
  
  
}


Turbina:: Turbina()
{
  agregar( new EspigaTurbina());

  // aspas
  agregar(MAT_Traslacion( 1.0,0.0, 0.0));
  for( int i=0; i<3; i++)
    {
      agregar(new Aspa());
      agregar(MAT_Rotacion(360.0/3, 1.0, 0.0, 0.0 ));
    }
}

EspigaTurbina:: EspigaTurbina ( )
{
  // parámetros a ajustar de la ventana
  const int num_verts_per = 4; 
  const unsigned nperfiles = 25; // para que salga redondo

  //tubo turbina 
  agregar(MAT_Rotacion(270.0, 0.0, 0.0, 1.0 ));
  agregar(MAT_Escalado(0.1, 1.7  , 0.1 )); 
  agregar( new Cilindro( num_verts_per, nperfiles));
  ponerColor( negro);  
}


Aspa::Aspa()
{
  ponerColor(marron); 
  agregar(MAT_Traslacion(0,-1.0, 0)); 
  agregar(MAT_Escalado(1.0/3.0, 1.0, 0.07/3) ); 
  agregar(new PrismaTrapecio());
  ponerColor(marron); 
 
}
