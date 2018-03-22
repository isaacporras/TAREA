#ifndef READER_H
#define READER_H


/**
  *@file Reader.h
  * @version 1.0
  * @date 15/3/18
  * @author Oscar Isaac Porras Perez
  * @title Reader
  * @brief Este archivo tiene todo lo referente con respecto a la lectura, creacion y escritura del archivo
  */
/**
 * @brief Esta clase tiene todo lo referente con respecto a la lectura, creacion y escritura del archivo
 */
class Reader {
private:
    const char* Path;
public:
    /**
     * @brief Inicializa el objeto Reader
     */
    Reader();

    /**
     *@brief Escribe los numeros aleatorios en el archivo.bin
     */
    void writeFile();
    /**
     * @brief lee el archivo.bin. NO SE USA
     */
    void readFile();
    /**
     * @brief da el tamano real del archivo, no de lo que contiene en numeros binarios. NO SE USA
     */
    void getSize();
};


#endif // READER_H
