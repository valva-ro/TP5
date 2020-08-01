//
// Created by root-MKevin on 28/7/20.
// LOS METODOS SE ENCUENTRAN ORDENADOS ALFABETICAMENTE. ESTOS ULTIMOS SE ENCUENTRAN CLASIFICADOS POR EL TIPO
// DE METODO (CONSTRUCTOR, CONSULTORES, ETC.). SI HUBIESE UN CONSTRUCTOR Y/O UN DESTRUCTOR SE ENCUENTRAR AL
// PRINCIPIO Y AL FINAL RESPECTIVAMENTE.

#ifndef MATRIZ_H
#define MATRIZ_H

enum{
    POSICION_INVALIDA = -1,
    SIN_INCREMENTO = 0
};

template < typename Tipo >
class Matriz{

private :
    // ATRIBUTOS
    Tipo ** datos;
    int filas, columnas;

    // METODOS

    // MODIFICADORES

    // PRE:  RECIBE UN ENTERO MAYOR QUE CERO.
    // POST: CREA EN MEMORIA DINAMICA COLUMNAS NUEVAS.
    void crearColumnas(const int columnasNuevas);

    // PRE:  RECIBE UN PUNTERO CON MEMORIA DINAMICA ASIGNADA PARA LAS FILAS Y DOS ENTERO MAYORES QUE CERO.
    // POST: CREA EN MEMORIA DINAMINA LAS COLUMNAS NUEVAS PARA LA MATRIZ AUXILIAR.
    void crearColumnas(Tipo **&auxiliar, const int filasNuevas, const int columnasNuevas);

    // PRE:  RECIBE DOS ENTEROS DENTRO DE LOS SIGUIENTES INTERVALOS: 0 <= eliminarFila < filas;
    //       0 <= eliminarColumna < columnas
    // POST: ELIMINA DE LA MATRIZ LA FILA Y LA COLUMNA CORRESPONDIENTE. DECREMENTA EN UNO LA FILA Y/O LA COLUMNA
    //       DEPENDIENDO DE LO QUE SE ELIMINE.
    void eliminacion(const int eliminarFila, const int eliminarColumna);

    // PRE:  -
    // POST: LIBERA LA MEMORIA Y PONE A LA MATRIZ COMO SI SE HUBIESE CONSTRUIDO SIN NINGUN ARGUMENTO.
    void eliminacionTotal();

    // PRE:  RECIBE UN ELEMENTO DEL MISMO TIPO QUE LA MATRIZ.
    // POST: INICIALIZA TODOS LOS ELEMENTOS DE LA MATRIZ CON EL ELEMENTO RECIBIDO.
    void inicializarMatriz(Tipo elementoDefault);

    // PRE:  -
    // POST: LIBERA LA MEMORIA ALOJADA EN LAS COLUMNAS.
    void liberarMemoriaColumnas();

    //PRE:  RECIBE UN PUNTERO CON MEMORIA ALOJADA TANTO PARA FILAS COMO PARA COLUMNAS Y UN DATO DEL MISMO QUE LA
    //      MATRIZ.
    //POST: GENERA UNA MATRIZ MAYOR CON LOS MISMOS DATOS Y CON EL DATO RECIBIDO EN DONDE SE HAYA AGREGADO UNA
    //      FILA Y/O UNA COLUMNA.
    void matrizMayor(Tipo **auxiliar, const int filasNuevas, const int columnasNuevas, Tipo elementoInicializacion);

    // PRE:  RECIBE UN PUNTERO DE TIPO 'Tipo' CON MEMORIA ALOJADA TANTO PARA FILAS COMO PARA COLUMNAS Y DOS ENTEROS
    //       DENTRO DE LOS INTERVALOS: 0 <= eliminarFila < filas ; 0 <= eliminarColumna < columnas. SI SE ELIMINA
    //       SOLO FILAS, EL OTRO PARAMETRO ES IGUAL A -1. ANALOGAMENTE, OCURRE LO MISMO SI SE ELIMINA SOLO COLUMNAS.
    // POST: ELIMINA LA MATRIZ EXISTENTE Y GENERA UNA MATRIZ MENOR CON LA CANTIDAD DE FILAS Y COLUMNAS
    //       CORRESPONDIENTES.
    void matrizMenor(Tipo **&auxiliar, const int eliminarFila, const int eliminarColumna);

    //PRE:  RECIBE PUNTERO DE TIPO <Tipo> DISTINTO DE NULL Y DOS ENTEROS MAYORES A CERO.
    //POST: LE ASIGNA MEMORIA DINAMICA AL PUNTERO, TANTO FILAS COMO COLUMNAS.
    void memoriaEnAuxiliar(Tipo **&auxiliar, const int filasNuevas, const int columnasNuevas);

    // PRE:  RECIBE UN DATO DEL MISMO TIPO QUE LA MATRIZ Y RECIBE DOS ENTEROS MAYORES A CERO.
    // POST: REDIMENSIONA EL TAMANIO DE LAS FILAS Y LAS COLUMNAS Y LAS INICIALIZA CON EL DATO RECIBIDO.
    void redimensionar(Tipo elementoInicializacion, const int filasNuevas, const int columnasNuevas);

public:
    // METODOS

    // CONSTRUCTOR

    // PRE:  -
    // POST: CONSTRUYE UN OBJETO DE TIPO MATRIZ CON SUS ATRIBUTOS IGUALADOS A CERO.( El ATRIBUTO 'datos' EN NULL )
    Matriz();

    // PRE:  RECIBE UN ELEMENTO DEL MISMO TIPO QUE LA MATRIZ Y DOS ENTEROS MAYORES O IGUALES A CERO.
    // POST: CONSTRUYE UN OBJETO DE TIPO MATRIZ DE TAMANIO filas*columnas CON TODOS SUS ELEMENTOS IGUALADOS AL
    //       ELEMENTO RECIBIDO COMO DEFAULT.
    Matriz(Tipo elementoInicializacion, const int filasNuevas, const int columnasNuevas);

    // MODIFICADORES

    // PRE:  RECIBE UN DATO DEL MISMO TIPO QUE LA MATRIZ Y RECIBE DOS ENTEROS MAYORES QUE CERO.
    // POST: AGREGA TANTAS FILAS Y COLUMNAS COMO LOS ENTEROS RECIBIDOS Y LAS INICIALIZA CON EL DATO RECIBIDO.
    //       ADEMAS INCREMENTA LOS ATRIBUTOS filas Y columnas.
    void agregarFilasColumnas(Tipo elementoInicializacion, const int filasNuevas, const int columnasNuevas);

    //PRE:  RECIBE UN ENTERO EN EL SIGUIENTE INTERVALO. 0 <= posicionColumna < columna.
    //POST: ELIMINA TODA LA COLUMNA DE LA MATRIZ. DECREMENTA EN UNO EL VALOR DEL ATRIBUTO columnas.
    void eliminarColumna(const int posicionColumna);

    // PRE:  RECIBE UN ENTERO DENTRO DEL SIGUIENTE INTERVALO. 0 <= posicionFila < filas.
    // POST: ELIMINA TODA LA FILA DE LA MATRIZ. DECREMENTA EN UNO EL VALOR DEL ATRIBUTO filas.
    void eliminarFila(const int posicionFila);

    // PRE:  RECIBE DOS ENTEROS DENTRO DE LOS SIGUIENTES INTERVALOS: 0 <= eliminarFila < filas ;
    //       0 <= eliminarColumna < columnas;
    // PRE:  ELIMINA DE LA MATRIZ DICHA FILA Y/O DICHA COLUMNA DICHA COLUMNA.
    void eliminarFilaColumna(const int eliminarFila, const int eliminarColumna);

    // PRE:  RECIBE UN ELEMENTO DEL MISMO TIPO QUE LA MATRIZ Y DOS ENTEROS DENTRO DE LOS SIGUIENTES INTERVALOS:
    //       0 <= posicionFila < filas ; 0 <= posicionColumna < columnas
    // POST: MODIFICA EN LA MATRIZ EL ELEMENTO RECIBIDO EN LA POSICION DE FILA Y COLUMNA RECIBIDAS.
    void modificarElemento(Tipo elemento, const int posicionFila, const int posicionColumna);

    // CONSULTORES

    // PRE:  RECIBE UN ELEMENTO DEL MISMO TIPO QUE LA MATRIZ.
    // POST: DEVUELVE TRUE SI EL ELEMENTO SE ENCUENTRA EN LA MATRIZ, DE LO CONTRARIO, FALSE.
    bool elementoEnMatriz(Tipo elemento);

    // PRE:  RECIBE UN ELEMENTO DEL MISMO TIPO QUE LA MATRIZ Y DOS ENTEROS DENTRO DE LOS SIGUIENTES INTERVALOS:
    //       0 <= posicionFila < filas ; 0 <= posicionColumna < columnas
    // POST: DEVUELVE TRUE SI EL ELEMENDO DE LA MATRIZ EN LA POSICION DE LA FILA Y COLUMNA RECIBIDA ES IGUAL AL
    //       ELEMENTO RECIBIDO, DE LO CONTRARIO, DEVUELVE FALSE.
    bool elementoEnPosicion(Tipo elemento, const int posicionFila, const int posicionColumna);

    // PRE:  -
    // POST: DEVUELVE EL VALOR DEL ATRIBUTO filas.
    int longitudFilas();

    // PRE:  -
    // POST: DEVUELVE EL VALOR DEL ATRIBUTO columnas.
    int longitudColumnas();

    // PRE:  -
    // POST: DEVUELVE TRUE SI LA MATRIZ SE ENCUENTRA VACIA, DE LO CONTRARIO, FALSE.
    bool matrizVacia();

    // PRE:  LA MATRIZ NO DEBE ESTAR VACIA. RECIBE DOS ENTEROS DENTRO DEL SIGUIENTE INTERVALO:
    //       0 <= posicionFila < filas 0 <= posicionColumna < columnas;
    // POST: DEVUELVE EL VALOR QUE SE ENCUENTRA EN LA POSICION DE FILA Y COLUMNAS RECIBIDAS.
    Tipo obtenerValor(const int posicionFila, const int posicionColumna);

    // DESTRUCTOR

    // PRE:  -
    // POST: DESTRUYE EL OBJETO DE TIPO MATRIZ.
    ~Matriz();
};

//--------------------------------------------------CONSTRUCTORES--------------------------------------------------//

template < typename Tipo >
Matriz<Tipo>::Matriz(){
    datos = 0;
    filas = SIN_INCREMENTO;
    columnas = SIN_INCREMENTO;
}

template < typename Tipo >
Matriz<Tipo>::Matriz(Tipo elementoInicializacion, const int filasNuevas, const int columnasNuevas){
    filas = SIN_INCREMENTO;
    columnas = SIN_INCREMENTO;
    redimensionar(elementoInicializacion, filasNuevas, columnasNuevas);
}

//--------------------------------------------------MODIFICADORES--------------------------------------------------//


template < typename Tipo >
void Matriz<Tipo>::agregarFilasColumnas(Tipo elementoInicializacion, const int filasNuevas, const int columnasNuevas){
    redimensionar(elementoInicializacion,filas + filasNuevas, columnas + columnasNuevas);
}

template < typename Tipo >
void Matriz<Tipo>::columnasEnMemoria(const int columnasNuevas){
    for(int i = 0; i < filas; i ++){
        *(datos + i) = new Tipo[columnasNuevas];
    }
}

template < typename Tipo >
void Matriz<Tipo>::columnasEnMemoria(Tipo **&auxiliar, const int filasNuevas, const int columnasNuevas){
    for(int i = 0; i< filasNuevas; i++){
        *( auxiliar + i ) = new Tipo[columnasNuevas];
    }
}

template < typename Tipo >
void Matriz<Tipo>::eliminacion(const int eliminarFila, const int eliminarColumna) {
    Tipo **auxiliar = 0;
    if(eliminarFila == POSICION_INVALIDA) {
        memoriaEnAuxiliar(auxiliar, filas, columnas - 1);
        matrizMenor(auxiliar, eliminarFila, eliminarColumna);
        liberarMemoriaColumnas();
        columnas--;
    }
    else if(eliminarColumna == POSICION_INVALIDA){
        memoriaEnAuxiliar(auxiliar, filas - 1, columnas);
        matrizMenor(auxiliar, eliminarFila, eliminarColumna);
        liberarMemoriaColumnas();
        filas--;
    }
    else{
        memoriaEnAuxiliar(auxiliar, filas - 1, columnas - 1);
        matrizMenor(auxiliar, eliminarFila, eliminarColumna);
        liberarMemoriaColumnas();
        filas--;
        columnas--;
    }
    delete[] datos;
    datos = auxiliar;
}

template < typename Tipo >
void Matriz<Tipo>::eliminarColumna(const int posicionColumna){
    if(columnas > 1) {
        eliminacion(POSICION_INVALIDA, posicionColumna);
    }
    else{
        eliminacionTotal();
    }
}

template < typename Tipo >
void Matriz<Tipo>::eliminarFila(const int posicionFila){
    if(filas > 1) {
        eliminacion(posicionFila, POSICION_INVALIDA);
    }
    else{
        eliminacionTotal();
    }
}

template < typename Tipo >
void Matriz<Tipo>::eliminarFilaColumna(const int eliminarFila, const int eliminarColumna) {
    if (filas > 1 && columnas > 1){
        eliminacion(eliminarFila, eliminarColumna);
    }else{
        eliminacionTotal();
    }
}

template < typename Tipo >
void Matriz<Tipo>::eliminacionTotal(){
    liberarMemoriaColumnas();
    delete[] datos;
    datos = 0;
    filas = SIN_INCREMENTO;
    columnas = SIN_INCREMENTO;
}

template < typename Tipo >
void Matriz<Tipo>::inicializarMatriz(Tipo elementoDefault){
    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            *(*(datos + i) + j) = elementoDefault;
        }
    }
}

template < typename Tipo >
void Matriz<Tipo>::liberarMemoriaColumnas(){
    for(int i = 0; i < filas; i ++){
        delete[] *( datos + i );
    }
}

template < typename Tipo >
void Matriz<Tipo>::matrizMayor(Tipo **auxiliar, const int filasNuevas, const int columnasNuevas, Tipo elementoInicializacion){
    for(int i = 0; i < filasNuevas; i++){
        for(int j = 0; j < columnasNuevas; j++){
            if( i >= filas || j >= columnas ) {
                *(*(auxiliar + i) + j) = elementoInicializacion;
            }
            else{
                *(*(auxiliar + i) + j) = *(*(datos + i) + j);
            }
        }
    }
}

template < typename Tipo >
void Matriz<Tipo>::matrizMenor(Tipo **&auxiliar, const int eliminarFila, const int eliminarColumna){
    int k = 0;
    int l;
    bool seIncremento;
    for (int i = 0; i < filas; i++) {
        seIncremento = false;
        l = 0;
        for (int j = 0; j < columnas; j++) {
            if (i != eliminarFila) {
                if (j != eliminarColumna) {
                    *(*(auxiliar + k) + l) = *(*(datos + i) + j);
                    l++;
                    seIncremento = true;
                }
            }
        }
        if (seIncremento) {
            k++;
        }
    }
}

template < typename Tipo >
void Matriz<Tipo>::memoriaEnAuxiliar(Tipo **&auxiliar, const int filasNuevas, const int columnasNuevas){

    if (filasNuevas != 0) {
        auxiliar = new Tipo*[filasNuevas];
        if (columnasNuevas != 0) {
            columnasEnMemoria(auxiliar, filasNuevas, columnasNuevas);
        }
        else {
            columnasEnMemoria(auxiliar, filasNuevas, this->columnas);
        }
    } else if (columnasNuevas != 0) {
        auxiliar = new Tipo*[this->filas];
        columnasEnMemoria(auxiliar, this->filas, columnasNuevas);
    }

}

template < typename Tipo >
void Matriz<Tipo>::modificarElemento(Tipo elemento, const int posicionFila, const int posicionColumna){
    if(!matrizVacia())
        *( *(datos + posicionFila) + posicionColumna ) = elemento;
}

template < typename Tipo >
void Matriz<Tipo>::redimensionar(Tipo elementoInicializacion, const int filasNuevas, const int columnasNuevas) {
    if (filas == SIN_INCREMENTO && columnas == SIN_INCREMENTO) {
        filas = filasNuevas;
        columnas = columnasNuevas;
        datos = new Tipo*[filasNuevas];
        columnasEnMemoria(columnasNuevas);
        inicializarMatriz(elementoInicializacion);
    }
    else {
        Tipo **auxiliar = 0;
        memoriaEnAuxiliar(auxiliar, filasNuevas, columnasNuevas);
        matrizMayor(auxiliar, filasNuevas, columnasNuevas, elementoInicializacion);
        liberarMemoriaColumnas();
        delete[] datos;
        datos = auxiliar;
        filas = filasNuevas;
        columnas = columnasNuevas;
    }
}

//--------------------------------------------------CONSULTORES--------------------------------------------------//

template < typename Tipo >
bool Matriz<Tipo>::elementoEnMatriz(Tipo elemento){
    Tipo elementoAux;
    bool seEncontro = false;
    int i = 0;
    int j = 0;
    while( (i < filas) && (!seEncontro) ){
        while( (j < columnas) && (!seEncontro) ){
            elementoAux = *( *( datos + i ) + j );
            if(elemento = elementoAux)
                seEncontro = true;
            j++;
        }
        i++;
    }
    return seEncontro;
}

template < typename Tipo >
bool Matriz<Tipo>::elementoEnPosicion(Tipo elemento, const int posicionFila, const int posicionColumna){
    Tipo elementoAux;
    if(!matrizVacia())
        elementoAux = *( *( datos + posicionFila ) + posicionColumna );
    return (elemento == elementoAux);
}


template < typename Tipo >
int Matriz<Tipo>::longitudColumnas(){
    return columnas;
}

template < typename Tipo >
int Matriz<Tipo>::longitudFilas(){
    return filas;
}

template < typename Tipo >
bool Matriz<Tipo>::matrizVacia(){
    return ( (filas == SIN_INCREMENTO) || (columnas == SIN_INCREMENTO) );
}


template < typename Tipo >
Tipo Matriz<Tipo>::obtenerValor(const int posicionFila, const int posicionColumna){
    if(!matrizVacia())
        return *( *( datos + posicionFila ) + posicionColumna );
}

//--------------------------------------------------DESTRUCTOR--------------------------------------------------//

template < typename Tipo >
Matriz<Tipo>::~Matriz(){
    liberarMemoriaColumnas();
    delete[] datos;
}

#endif //MATRIZ_H