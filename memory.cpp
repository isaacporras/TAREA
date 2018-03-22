#include "memory.h"

#include "Memory.h"
#include <iostream>
#include <string>
using std::string;

/**
  *@file Memory.h
  * @version 1.0
  * @date 15/3/18
  * @author Oscar Isaac Porras Perez
  * @title Memory
  * @brief Este archivo maneja todo lo que tiene que ver con la paginacion
  */


Memory::Memory() {


    *pagina1.numerodepagina = -1;

    *pagina2.numerodepagina = -1;

    *pagina3.numerodepagina = -1;

    *pagina4.numerodepagina = -1;

}

int Memory::getSize(){                                                                                                  //Este metodo no se utiliza
    std::cout<<"LOS NUMEROS QUE SE ALMACENAN EN MI ARCHIVO SON: "<<std::endl;
    FILE *file;
    int number;
    file = fopen("archivo.bin","rb");
    int *cantidad = (int *)malloc(sizeof(int));
    *cantidad = 0;
    if(file==NULL){
        std::cout<<"no se abrio"<< std::endl;
    }
    else{
        while(fread(&number, sizeof(int),1,file)){
            cantidad = cantidad +1;
            std::cout<<number<<std::endl;
        }
    }
    return *cantidad *sizeof(int);

}

Pagina Memory::insertarPagina(Pagina *paginainsertar) {                                                                   //Este metodo asigna la pagina que se quiere cargar a las que se tienen
    std::cout<<"****************************  VA A INSERTAR ***********************"<<std::endl;
    std::cout<<"****************************  "<<*paginainsertar->numerodepagina<<" ***********************"<<std::endl;
    if(*pagina1.numerodepagina == -1){

        std::cout<<"SE INSERTO EN LA PAGINA 1 Y TIENE A PAGINA " << *paginainsertar->numerodepagina<<std::endl;

        pagina1.numerodepagina = paginainsertar->numerodepagina;
        std::cout<<"Llego al for" << std::endl;

        for(int x = 0; x < 101; ++x){
            pagina1.elementos[x] = paginainsertar->elementos[x];
        }

        todaslaspaginas[0] = pagina1;

        pagina1.lasttimeused += 1;
        std::cout<<"salio de la funcion" << std::endl;
        return pagina1;
    }
    if(*pagina2.numerodepagina == -1){

        pagina2.numerodepagina = paginainsertar->numerodepagina;
        std::cout<<"SE INSERTO EN LA PAGINA 2 :"<< *paginainsertar->numerodepagina<<std::endl;


        pagina2.lasttimeused += 1;
        for(int x= 0; x < 101; ++x){
            pagina2.elementos[x] = paginainsertar->elementos[x];
        }
        todaslaspaginas[1] = pagina2;
        return pagina2;
    }
    if(*pagina3.numerodepagina == -1) {
        pagina3.numerodepagina = paginainsertar->numerodepagina;
        std::cout<<"SE INSERTO EN LA PAGINA 3 :"<< *paginainsertar->numerodepagina<<std::endl;


        pagina3.lasttimeused +=1;
        for(int x=0; x < 101; ++x){
            pagina3.elementos[x] = paginainsertar->elementos[x];
        }
        todaslaspaginas[2] = pagina3;
        return pagina3;
    }
    if(*pagina4.numerodepagina == -1){
        pagina4.numerodepagina = paginainsertar->numerodepagina;
        std::cout<<"SE INSERTO EN LA PAGINA 4 : "<< *paginainsertar->numerodepagina<<std::endl;


        pagina4.lasttimeused +=1;
        for(int x = 0 ; x < 101; ++x){
            pagina4.elementos[x] = paginainsertar->elementos[x];
        }
        todaslaspaginas[3] = pagina4;
        return pagina4;
    }
        //ACA APLICA EL CRITERIO DE LA MENOS USADA PARA AREMPLAZAR
    else{
        if(pagina1.lasttimeused >= pagina2.lasttimeused && pagina1.lasttimeused>= pagina3.lasttimeused
           && pagina1.lasttimeused>= pagina4.lasttimeused)
        {
            std::cout<<"SE INSERTO EN LA PAGINA 1 POR LIFO" <<std::endl;
            pagina1.numerodepagina = paginainsertar->numerodepagina;
            for(int x=0; x < 101; ++x){
                pagina1.elementos[x] = paginainsertar->elementos[x];
            }
            todaslaspaginas[0] = pagina1;
            return pagina1;
        }
        if(pagina2.lasttimeused>= pagina1.lasttimeused && pagina2.lasttimeused>= pagina3.lasttimeused
           && pagina2.lasttimeused>= pagina4.lasttimeused){
            std::cout<<"SE INSERTO EN LA PAGINA 2 POR LIFO"<<std::endl;
            pagina2.numerodepagina = paginainsertar->numerodepagina;
            for(int x=0; x < 101; ++x){
                pagina2.elementos[x] = paginainsertar->elementos[x];
            }
            todaslaspaginas[1] = pagina2;
            return pagina2;
        }
        if(pagina3.lasttimeused>= pagina1.lasttimeused && pagina3.lasttimeused>= pagina2.lasttimeused
           && pagina3.lasttimeused>= pagina4.lasttimeused){
            std::cout<<"SE INSERTO EN LA PAGINA 3 POR LIFO"<<std::endl;

            pagina3.numerodepagina = paginainsertar->numerodepagina;
            for(int x=0; x < 101; ++x){
                pagina3.elementos[x] = paginainsertar->elementos[x];
            }
            todaslaspaginas[2] = pagina3;
            return pagina3;
        }
        if(pagina4.lasttimeused>= pagina1.lasttimeused && pagina4.lasttimeused>= pagina2.lasttimeused
           && pagina4.lasttimeused>= pagina3.lasttimeused){
            std::cout<<"SE INSERTO EN LA PAGINA 4 POR LIFO"<<std::endl;
            pagina4.numerodepagina = paginainsertar->numerodepagina;
            for(int x=0; x < 101; ++x){
                pagina4.elementos[x] = paginainsertar->elementos[x];
            }
            pagina4 = (*paginainsertar);
            todaslaspaginas[3] = pagina4;

            return pagina4;
        }
        else{
            return pagina3;
        }

    }
}

Pagina Memory::cargarpagina(int posicion_numero) {                                                                        //Yo defini las paginas de 100 ints = 400bytes
    std::cout << "el dato mio es: "<< posicion_numero<< std::endl;
    string status = "no cargado";                                                                                       //Este status permite saber si la pagina esta cargada o no
    int bytepos = posicion_numero * sizeof(int);
    std::cout << "La posicion en bytes es: " << bytepos<< std::endl;//Calcula la posicion en bytes de el numero
    float numero_de_pagina = (float(bytepos) / (sizeof(int) * 100));

    if(numero_de_pagina > int(numero_de_pagina)){
        numero_de_pagina = int(numero_de_pagina + 1);
    }
    else{
        numero_de_pagina = int(numero_de_pagina);
    }



    std::cout << "El numero de pagina es: " << numero_de_pagina<< std::endl;


    std::cout << "MI NUMERO ESTA POSICIONADO EN LA POSICION: " << bytepos << std::endl;

    if (numero_de_pagina == *pagina1.numerodepagina){
        std::cout << "Esta en memoria la pagina :" << *pagina1.numerodepagina << std::endl;
        std::cout << "retorno la pagina 1 de golpe" << std::endl;
        pagina1.lasttimeused += 1;
        for (int contador = 0; contador< 101; ++contador){
            std::cout<< pagina1.elementos[contador]<<std::endl;
        }

        return pagina1;
    }

    if(numero_de_pagina == *pagina2.numerodepagina){
        std::cout << "Esta en memoria la pagina :" << *pagina2.numerodepagina << std::endl;
        std::cout << "retorno la pagina 2 de golpe" << std::endl;
        pagina2.lasttimeused +=1;
        for (int contador = 0; contador< 101; ++contador){
            std::cout<< pagina2.elementos[contador]<<std::endl;
        }
        return pagina2;
    }
    if( numero_de_pagina == *pagina3.numerodepagina ){
        std::cout << "Esta en memoria la pagina :" << *pagina3.numerodepagina << std::endl;
        std::cout << "retorno la pagina 3 de golpe" << std::endl;
        pagina3.lasttimeused +=1;
        for (int contador = 0; contador< 101; ++contador){
            std::cout<< pagina3.elementos[contador]<<std::endl;
        }
        return pagina3;
    }
    if(numero_de_pagina == *pagina4.numerodepagina){
        std::cout << "Esta en memoria la pagina :" << *pagina4.numerodepagina << std::endl;
        std::cout << "retorno la pagina 4 de golpe" << std::endl;
        pagina4.lasttimeused +=1;
        for (int contador = 0; contador< 101; ++contador){
            std::cout<< pagina4.elementos[contador]<<std::endl;
        }
        return pagina4;
    }


    if (status == "no cargado") {                                                                                         //Si la pagina no esta normal
        std::cout << "MI DATO NO ESTA CARGADO" << std::endl;

        FILE *file;
        file = fopen("archivo.bin", "rb");                                                                               //Abre el archivo.bin

        if (file == NULL) {                                                                                               //Verifica si se abrio
            std::cout << "no se abrio" << std::endl;
        }
        if (numero_de_pagina == 1) {
                                                                                                                        //Si el elemento se encuentra en la pagina 1 entonces  no lo multiplica por la cantidad de bytes que tiene cada pagina
            fseek(file, 0, SEEK_SET);
        }

        if (numero_de_pagina != 1) {                                                                                       //Si el elemento no es la primera multiplica la pagina por la cantidad de bytes que tiene cada pagina
                                                                                                        //...y de esta manera posiciona el lector del archivo donde va a empezar leer la pagina
            fseek(file, (int(numero_de_pagina)-1) * 400, SEEK_SET);
        }

        int posicion = 0;

        Pagina paginaProv;                                                                                                //Crea la pagina

        *paginaProv.numerodepagina = int(numero_de_pagina);
                                                                                                                        // Le asigna el numero de la pagina
        if(numero_de_pagina == 1){
            paginaProv.posInicio = 0;
        }
        if(numero_de_pagina != 1){
            paginaProv.posInicio = int(numero_de_pagina) * 400;
        }
                                                                           //Le asigna la posicion inicial de la pagina

        paginaProv.posFinal = (int(numero_de_pagina)+1) * 400;


        //Le asigna la posicion final de la pagina

        int number;
        std::cout << "ESTOS SON LOS ELEMENTOS DE MI PAGINA: " << numero_de_pagina << std::endl;
        std::cout << "-----------------------------------------------------------------" << std::endl;
        int contador = 0;

        while (fread(&number, sizeof(int), 1, file) && contador != 101) {                                                  //Aca lee el archivo y le mete los numeros al array que tiene la pagina

            paginaProv.elementos[posicion] = number;                                                                       //Aca mete los numeros al array
            posicion = posicion + 1;                                                                                    //Aumenta la posicion
            std::cout << number << " , " << contador << ", " << *paginaProv.numerodepagina << std::endl;
            contador = contador + 1;
        }

        std::cout << "HAY " << contador << " elementos en esta pagina" << std::endl;
        std::cout << "-----------------------------------------------------------------" << std::endl;

        insertarPagina(&paginaProv);                                                                                       //Inserta la pagina creada en los memoria

    }

}
