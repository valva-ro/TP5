//
// Created by alexteper on 20/7/20.
//

#ifndef TP5_TRIALGO_MENU_H
#define TP5_TRIALGO_MENU_H


using namespace std;

class Menu {
private:
    char opcion;
    MenuAeropuerto menuAeropuerto;
    MenuVuelo menuVuelo;

public:
    //DESCRIPCION: Muestra las opciones del MENU
    //PRE:
    //POST: Muestra las opciones del MENU
    void mostrarOpciones();

    //DESCRIPCION: selector de las opciones del MENU
    //PRE:
    //POST: selector de las opciones del MENU
    void selectorOpcion();





};


#endif //TP5_TRIALGO_MENU_H
