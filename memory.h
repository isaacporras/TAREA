#ifndef MEMORY_H
#define MEMORY_H

#include <iostream>
/**
  *@file Memory.h
  * @version 1.0
  * @date 15/3/18
  * @author Oscar Isaac Porras Perez
  * @title Memory
  * @brief Este archivo maneja todo lo que tiene que ver con la paginacion
  */
struct Pagina{
    int lasttimeused = 0;
    int posInicio = -1;
    int posFinal = -1;
    int elementos[100];
    int *numerodepagina = (int*)malloc(sizeof(int));

};

/**
 * @brief Memory class es la clase que controla todo lo referente a el manejo de la paginacion
 */
class Memory{
public:
    Pagina todaslaspaginas[4];
    struct Pagina pagina1;
    struct Pagina pagina2;
    struct Pagina pagina3;
    struct Pagina pagina4;


public:

    Memory();


    /**
     * @brief este metodo busca la posicion del numero que se busca y retorna la pagina completa en la que se encuentra
     * @param posicion_numero la posicion del numero que se busca
     */
    Pagina cargarpagina(int posicion_numero);
    /**
     * @brief este metodo retorna el tamano del archivo que se esta leyendo, en este caso es archivo.bin
     * @return tamano en bytes del archivo
     */
    int getSize();
    /**
     * @brief este metodo inserta la pagina entera(que se busca en el metodo cargarpagina) en los arrays de la memoria.
     * @param paginainsertar
     */
    Pagina insertarPagina(struct Pagina *paginainsertar);

    int& operator[](int index);

};

#endif // MEMORY_H
