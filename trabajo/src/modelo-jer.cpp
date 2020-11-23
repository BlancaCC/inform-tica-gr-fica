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

// Includes propios 
#include "colores-aux.h"
#include "trasformaciones-aux.h"

// _______ clase raíz ________

Submarino:: Submarino()
{
  ponerNombre("Submarinillo");
  
  agregar( new Cuerpo());

  agregar(MAT_Traslacion( 0.0,-1.0, 0.0)); // con -1 "se oculta, con 1 se muestra
  agregar(new Mirilla()); 
  
}


Cuerpo :: Cuerpo()
{
  agregar(new BaseCuerpo());
  agregar( MAT_Escalado( -0.8, 0.8, 0.8));
  agregar(MAT_Traslacion( -0.5,1.0, 0.0));
  agregar(new Cabina());

  agregar( MAT_Escalado( -1.0, 1.0, 1.0));
  agregar(MAT_Traslacion( 2.3,-1.0, 0.0));
  agregar(new Turbina());

  agregar(MAT_Traslacion( -4,0.0, 2.1));
  agregar(new Turbina2());
  agregar(MAT_Traslacion( 0,0.0, -2*2.1));
  agregar(new Turbina2());
}

BaseCuerpo :: BaseCuerpo ( ) 
{
  ponerNombre("Cuerpo "); 
  ponerIdentificador(-1);

  
  // parámetor de nuestro paraboloide 

  const float semieje_x = 4/1.5; 
  const float semieje_y = 2/1.5; 

  const int num_verts_per = 20; 
  const unsigned nperfiles = 20;
  
  agregar( MAT_Escalado( semieje_x, semieje_y, semieje_y));
  agregar( new Esfera( num_verts_per, nperfiles));
  ponerColor(gris);  // esta variable se define en colores-aux.h
  
  
}


Cabina :: Cabina ()
{
  agregar(MAT_Cizalla_yx(0.5));  
  agregar (new Cubo());
  ponerColor(azul); 
}




//_______ TURNINA__________
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


Turbina2:: Turbina2 ()
{
  // por defecto las ventanas están en horizontal

  // parámetros a ajustar de la ventana
  const int num_verts_per = 3; 
  const unsigned nperfiles = 25; // para que salga redondo

  

  agregar(MAT_Escalado(1.2,0.5 ,0.75 )); 
  agregar(MAT_Rotacion(270.0, 0.0, 0.0, 1.0 ));
  
  agregar( new Cilindro( num_verts_per, nperfiles));
  ponerColor(morado);

  agregar(MAT_Escalado(0.8, 0.2 ,0.5 ));
  agregar(MAT_Rotacion(90.0, 0.0, 0.0, 1.0 ));
  agregar(MAT_Traslacion( 3.8,0.0, 0.0));
  agregar(new Turbina()); 

  
  
}

// ________ FIN TURBINA 



Mirilla:: Mirilla ( )
{
  // parámetros a ajustar de la ventana
  const int num_verts_per = 4; 
  const unsigned nperfiles = 25; // para que salga redondo

  //tubo vertical
  
  
  agregar(MAT_Escalado(0.1, 2  , 0.1 ));
  agregar( new Cilindro( num_verts_per, nperfiles));
  agregar(MAT_Escalado(10.0, 0.5  , 10 ));

  //tubo horizontal
  agregar(MAT_Traslacion( 0.0,1.8, 0.0));
  agregar(MAT_Rotacion(90.0, 0.0, 0.0, 1.0 ));
  agregar(MAT_Escalado(0.1, 1.3  , 0.1 ));
  
  agregar( new Cilindro( num_verts_per, nperfiles));
  
  ponerColor( negro);  
}
