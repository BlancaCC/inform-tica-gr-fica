#include <math.h>
#include "ig-aux.h"
#include "matrices-tr.h"
#include "grafo-escena.h"
#include "malla-revol.h"
#include "materiales-luces.h"
#include "latapeones.h"

using namespace std;


LataPeones::LataPeones()
{
  ponerNombre("Lata Peones");

  agregar( new Lata("Lata de coke", "../recursos/imgs/lata-coke.jpg"));

  agregar( MAT_Traslacion(2,0,0));
  agregar( new Lata("Lata de pesi", "../recursos/imgs/lata-pepsi.jpg"));
}


Lata::Lata(const string nombre, const std::string & texturaJPG)
{

   // ___tapas ___

  agregar(new LataTapaSup());
  agregar(new LataTapaInf());  
  

  // ----   Cuerpo de la lata -----

 

  Textura * tex = new Textura(texturaJPG);

  
  agregar( new Material(tex, 0.5,0.3,0.8,100) );
  agregar(new MallaRevolPLY("../recursos/plys/lata-pcue.ply",30));


 

  
  ponerNombre(nombre);
  ponerIdentificador(1);
  
  
}


LataTapaSup::LataTapaSup(){
  
    agregar( new Material(0.6,0.6,1.0,100)  ); 
    agregar(new MallaRevolPLY("../recursos/plys/lata-psup.ply", 20));
    
    ponerNombre("Tapa superior lata");
    ponerIdentificador(-1);
}

LataTapaInf::LataTapaInf(){
    agregar( new Material(0.6,0.6,1.0,100) ); 
    agregar(new MallaRevolPLY("../recursos/plys/lata-pinf.ply", 20));
    ponerNombre("Tapa inferior lata");
    ponerIdentificador(-1);
}


Peon::Peon(const string nombre, const std::string & texturaJPG){
    agregar(new MallaRevolPLY("../recursos/plys/peon", 20));
}
