# Informática gráfica 
Material de la asignatura de prácticas de informática gráfica.


## Cómo se compila   

- Ir a carperta `trabajo/cmake-unix/build`, escribir `cmake ..` una sola vez. 
- Ir a directorio `build` y escribir `make` genera ejecutable `cmake-unix/build/prac_ig_exe`  
- `make clean` para limpiarlo to. 



## Preguntas futuras para la Blanca que se prepare el examen

### Praáctica 1

- Dibuja un cubo con cada cara de un color 


### Práctica 2

- Cambia para que el eje de rotación no sea y, sino x
- Crear una nueva escena que contenga lo anterior   

### Práctica 3  

- En teoría planteó cuestiones de adyacencia de triángulos   




## Cómo trabajar de manera general     

Ficheros involucrados:   
-  malla-revol.h (declaración de figuras de malla de revolución, con lo parámeteros pertinentes que le queramos añadir)   
- malla-revol.cpp cálculo e inserción de los nodos que definirán el perfil de la figura. 



#### Para declarar lo creado   

- Escena.h añadir los objetos creados. 
- main.cpp  push con la nueva escena 
- Para añadir color , en la función de jerárquica porner `ponerColor ({ r,g,v})



te refieres a un elipsoide en 3D ?
Tú
10:44
sí
puede hablar si quiere
CARLOS UREÑA ALMAGRO
10:45
ok, entonces, eso se obtiene a partir de una esfera con una matriz de escalado no uniforme
es decir, puedes usar la esfera creada por revolución de un perfil, centrada en el origen y con radio unidad,
Tú
10:45
a vale, gracias
CARLOS UREÑA ALMAGRO
10:45
no tienes que añadirle nada a ese objeto 'esfera'
simplemente lo instancias en un grafo de escena afectado de un escalado no uniforme

en general no es necesario extender la clase esfera, cubo, cono, cilindro con parámetros adicionales como altura, anchura, radio, etc... ya que esos objetos están definidos en sus propio sistema de coordenadas maestras y luego usas matrices para ponerlos en distintos sitios y con distintos tamaños
de nada
