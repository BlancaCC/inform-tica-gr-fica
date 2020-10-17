// *********************************************************************
// **
// ** Informática Gráfica, curso 2019-20
// ** Implementación de la clase 'MallaRevol'
// **
// *********************************************************************

#include "ig-aux.h"
#include "tuplasg.h"
#include "lector-ply.h"
#include "matrices-tr.h"
#include "malla-revol.h"

using namespace std ;

// *****************************************************************************




// Método que crea las tablas de vértices, triángulos, normales y cc.de.tt.
// a partir de un perfil y el número de copias que queremos de dicho perfil.
void MallaRevol::inicializar
(
 const std::vector<Tupla3f> & perfil,     // tabla de vértices del perfil original
 const unsigned               num_copias  // número de copias del perfil
 )
{
  // COMPLETAR: Práctica 2: completar: creación de la malla....
  

  // hay que implementar el algoritmo tocho que se describe en el guión de prácticas en la pag 28 en adelante

  int num_vertices = perfil.size(); // número de índices, van de abajo a arriba

  Tupla3f q; //  contiene los vértices futuros
  Matriz4f matriz_rotacion;
  int k;  // vértice auxiliar para representar triángulos

  // cada copia es una instancia ángulo (2pi/(n-1)
  // instancia 0 y n-1 tienen sus vertices en el mismo sitio
  
  // primero crear table de vértices (se parte del perfil original y se inserta al final una copia de los vertices del principio)

  for( unsigned int i=0 ; i< num_copias; i++) //numero instancias
    {
      matriz_rotacion = MAT_Rotacion( (360.0 * i) / (num_copias-1), 0.0, 1.0, 0.0); 
      for( int j=0; j< num_vertices ; j++) // numéro de vértices en el perfil
	{
	  q = matriz_rotacion * perfil[j];
	  vertices.push_back(q); 
	  
	  // hay que obtener el vértice q rotando p_j un ángulo de 2pi * i /(n-1)
	  
	}
    }
  
  //segundo crear TABLA DE TRIÁNGULOS

  for(unsigned  int i = 0; i< (num_copias-1); i++)
    {
      for( int j = 0; j< (num_vertices-1); j++)
	{
	  k = i*num_vertices + j;      // índice de cierto vértice en tabla de vértices

	  // creamos cuadrado 
	  triangulos.push_back({k, k+num_vertices, k+num_vertices+1}); // x, x siguiente instancia y el de abajo de x
	  triangulos.push_back({ k, k+num_vertices+1, k+1}); //x abajo siguienre x, abajo x
	    
	}
    }


  
  


}

// -----------------------------------------------------------------------------
// constructor, a partir de un archivo PLY

MallaRevolPLY::MallaRevolPLY
(
   const std::string & nombre_arch,
   const unsigned      nperfiles
)
{
   ponerNombre( std::string("malla por revolución del perfil en '"+ nombre_arch + "'" ));
   // COMPLETAR: práctica 2: crear la malla de revolución
   // Leer los vértice del perfil desde un PLY, después llamar a 'inicializar'
   vector<Tupla3f> perfil;
   
   LeerVerticesPLY(nombre_arch, perfil); 

   inicializar(perfil, pnerfiles); 
   // ...........................


}


