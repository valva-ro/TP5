#include "Excepcion.h"

Excepcion::Excepcion(int motivo)throw()
{
    this->motivo = motivo;
}

const char* Excepcion::what() const throw()
{
	switch(motivo)
	{
    case 0 : return "Error en la lectura y cargado del ABB.";break;

    case 1 : return "Error en la lectura y cargado del grafo.";break;

    default: return "Error desconocido";
	};
}