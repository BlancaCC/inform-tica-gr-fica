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

// ________ implementación de funciones relativas a la animación _____

unsigned Submarino :: leerNumParametros() const
{
  // número de grado de libertad 
  return 3; 
}

void Submarino::fijarRotacionTurbina( const float rot_turbina)
{

  * rotTurbina = MAT_Rotacion( rot_turbina, 1.0, 0.0, 0.0); 
}


void Submarino::fijarMovimientoMirilla( const float vertical, const float giro)
{

  * movimientoMirilla  = MAT_Rotacion( giro, 0.0, 1.0, 0.0)*
    MAT_Traslacion( 0.0, 1.2+1.5*sin(vertical), 0.0); 
    
}
float Submarino::calculaAnguloSubmarino( const float x, const float z, const float t)
{
  float angulo = 0;
  int mi_t = t*360; 
  
  if( 0 <= z && z<= M_PI/2 && 0 <= x && x <= M_PI/4)
    angulo = 90.0 - (mi_t % 360);
  else if( M_PI/2 < z && z<= M_PI && M_PI/4 < x && x <= M_PI/2)
    angulo = 90.0 -(mi_t % 360);

  return angulo; 
}
void Submarino::fijarMovimientoSubmarino( const float t)
{
  
  float x = 0.2*t;
  float z = 0.4*t; 
  /**
  * traslacionCuerpoSubmarino = MAT_Rotacion(-360*sin(0.04*t),0.0, 1.0, 0.0 )*
    MAT_Traslacion( -6*sin(0.2*t), 2*sin(0.05*t), 2.5*cos(0.075*t) );
  */

   //* traslacionCuerpoSubmarino = MAT_Traslacion( 3*-sin(0.2*t), 0.0, 3*cos(M_PI/2+0.4*t) ) *MAT_Rotacion(360*sin(0.08*t),0.0, 1.0, 0.0 ) ;
  
  * traslacionCuerpoSubmarino = MAT_Rotacion(
		      calculaAnguloSubmarino(x, z, t),0.0, 1.0, 0.0 ) *
    MAT_Traslacion( 3*cos(x), 0.0, 3*sin(z) );
}

void Submarino :: actualizarEstadoParametro ( const unsigned iParam, const float t_sec )
{
  assert ( iParam < leerNumParametros());

  switch(iParam)
    {
    case 0 :
      fijarRotacionTurbina( 360 * t_sec);
      break;

    case 1:
      fijarMovimientoMirilla(0.2*t_sec, 20*t_sec);
      break;

    case 2:
      fijarMovimientoSubmarino( t_sec);
      break; 
      
    }
}
// _______ clase raíz ________

Submarino:: Submarino()
{
  ponerNombre("Submarinillo");
  
  // animación de movimiento del cuerpo general
  unsigned indice = agregar (MAT_Ident()); 

  // cuerpo general
  agregar(MAT_Escalado(0.6, 0.6, 0.6)); 
  agregar( new Cuerpo(rotTurbina));

  //mirilla
  agregar(MAT_Traslacion( 0.0,-1.0, 0.0)); // con -1 "se oculta, con 1 se muestra
  agregar(new MirillaAnimada( movimientoMirilla ));

  //para golpes
  agregar(MAT_Traslacion( -2.2,1.2, 0.0));
  agregar(MAT_Escalado(0.5, 0.5, 0.5)); 
  agregar(new ParaGolpes()); 

  traslacionCuerpoSubmarino = leerPtrMatriz(indice);  
  
}


Cuerpo :: Cuerpo(Matriz4f * & rotTurbina )
{

  Objeto3D * inst_turbina = new Turbina(rotTurbina);
  Objeto3D * inst_camara_turbina = new CamaraTurbina( inst_turbina); 

  
  agregar(new BaseCuerpo());
  agregar( MAT_Escalado( -0.8, 0.8, 0.8));
  agregar(MAT_Traslacion( -0.5,1.0, 0.0));
  agregar(new Cabina());

  agregar( MAT_Escalado( -1.0, 1.0, 1.0));
  agregar(MAT_Traslacion( 2.3,-1.0, 0.0));
  agregar(inst_turbina);

  agregar(MAT_Traslacion( -4,0.0, 2.1));
  agregar(inst_camara_turbina);
  agregar(MAT_Traslacion( 0,0.0, -2*2.1));
  agregar(inst_camara_turbina);
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


ParaGolpes :: ParaGolpes()
{
  agregar(MAT_Cizalla_yx(0.5));
  agregar(new Esfera(15, 20));
  ponerColor(amarillo); 
}

//_______ TURNINA__________



Turbina:: Turbina(Matriz4f * & rotacion_turbina)
{
  unsigned ind = agregar (MAT_Rotacion(20, 1.0, 0.0, 0.0)); 
  agregar( new EspigaTurbina());

  // aspas
  agregar(MAT_Traslacion( 1.0,0.0, 0.0));
  for( int i=0; i<3; i++)
    {
      agregar(new Aspa());
      agregar(MAT_Rotacion(360.0/3, 1.0, 0.0, 0.0 ));
    }

   rotacion_turbina = leerPtrMatriz(ind); 
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
  ponerColor(amarillo); 
 
}


CamaraTurbina:: CamaraTurbina ( Objeto3D * & turbina)
{
  // por defecto las ventanas están en horizontal

  // parámetros a ajustar de la ventana
  const int num_verts_per = 3; 
  const unsigned nperfiles = 25; // para que salga redondo

  

  agregar(MAT_Escalado(1.2,0.5 ,0.75 )); 
  agregar(MAT_Rotacion(270.0, 0.0, 0.0, 1.0 ));
  agregar(MAT_Cizalla_yx(0.2)); 
  agregar( new Cilindro( num_verts_per, nperfiles));
  ponerColor(morado);

  agregar(MAT_Cizalla_yx(-0.2)); 
  agregar(MAT_Escalado(0.8, 0.2 ,0.5 ));
  agregar(MAT_Rotacion(90.0, 0.0, 0.0, 1.0 ));
  agregar(MAT_Traslacion( 3.8,0.0, 0.0));
  agregar(turbina); 
   
}

// ________ FIN TURBINA 


MirillaAnimada:: MirillaAnimada(Matriz4f * & movimientoMirilla )
{
  unsigned ind = agregar(MAT_Ident());
  agregar(new Mirilla());

  movimientoMirilla = leerPtrMatriz(ind);
}
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
  agregar(MAT_Escalado(0.1, 0.8  , 0.1 ));
  
  agregar( new Cilindro( num_verts_per, nperfiles));
  
  ponerColor( negro);  
}
