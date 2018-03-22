#include "reader.h"

#include <fstream>
using namespace std;

#include <iostream>
#include <sys/stat.h>



Reader::Reader() {

}

void Reader::writeFile() {

    Path = "archivo.bin";                                                                                               // Es el path al archivo
    ofstream file (Path, ios::out |ios::binary);                                                                        //Crea el archivo en binario

    std::cout<<"LOS DATOS QUE SE INSCRIBIRAN EN EL ARCHIVO SON:"<<std::endl;
    int pagina = 2;                                                                                                     // Esta variable se usa para poder imprimir la pagina por la que va
    int contador2 = 1;
    std::cout<<"------------------SE ENCUENTRA EN LA PAGINA : "<< 1 <<"---------------------"<<std::endl;
    for(int contador = 0; contador < 1000; ++contador){                                                                 //En este loop se escriben numeros random en el archivo
        if(contador2 == 101){
            std::cout<<"------------------SE ENCUENTRA EN LA PAGINA : "<< pagina <<"---------------------"<<std::endl;
            pagina = pagina + 1;
            contador2 = 1;
        }

        int num = 1 + rand()%(10-1);                                                                                    //Encuentra un numero random entre 1-10
        std::cout<<num<<","<< contador2 << std::endl;                                                                   //Imprime el numero que se va a escibir y la posicion
        file.write ((char *) &num, sizeof(int));                                                                        //Escribe el numero
        contador2 =  contador2 + 1;                                                                                     //Aumenta la posicion


    }
    std::cout<<"----------------------------SE TERMINO DE ESCRIBIR-----------------------------------------"<<std::endl;

}

void Reader::getSize() {                                                                                                //Metodo que retorna el tamano en bytes del archivo
    struct stat results;
    if (stat("archivo.bin", &results) == 0)
        std::cout<< "El tamaño del archivo es : "<<results.st_size <<" bytes" <<std::endl;                              //Imprime el tamano del archivo

    else{
        std::cout<< "No se pudo determinar el tamano del archivo" <<std::endl;
    }
}

void Reader::readFile() {                                                                                               //Lee el archivo binario
    std::cout<<"LOS NUMEROS QUE SE ALMACENAN EN MI ARCHIVO SON: "<<std::endl;
    FILE *file;                                                                                                         //crea una variable de tipo File
    int number;
    file = fopen("archivo.bin","rb");                                                                                   //Abre el archivo
    if(file == NULL){
       std::cout<<"no se abrio"<< std::endl;
    }
    else{
        int contador =0;
        while(fread(&number, sizeof(int),1,file)){                                                                      //En este loop mientras haya algo que leer lo imprime

            std::cout<<number<<", "<<contador<<std::endl;

        }
        std::cout<<"-----------------------------------------------SE TERMINO DE ESCRIBIR-----------------------------------------"<<std::endl;
    }

}
