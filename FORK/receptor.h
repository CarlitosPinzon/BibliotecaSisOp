/**************************************************************
#         		Pontificia Universidad Javeriana
#     Autor: Carlos Pinzon
#     Fecha: 15 de Mayo de 2025
#     Materia: Sistemas Operativos
#     Tema: Proyecto - Sistema para el prestamo de libros
#     Fichero: receptor.h
#	Descripcion: Archivo de encabezado para receptor.c. 
#                 Define las estructuras de datos, constantes y prototipos de funciones utilizadas por el receptor
#****************************************************************/

#ifndef RECEPTOR_H
#define RECEPTOR_H

#include <unistd.h> // Para close, unlink, etc.
#include <stdio.h>  // Para printf, snprintf, etc.

#define MAX_EJEMPLAR 10
#define MAX_LIBROS 100
#define BUFFER_TAM 10

//Representa un ejemplar de un libro con su número, estado y fecha
struct Ejemplar {
    int numero;
    char status;
    char fecha[11];
};

// Representa un libro con su ISBN, nombre y arreglo de ejemplares
struct Libros {
    int isbn;
    char nombre[250];
    int numEj;
    struct Ejemplar ejemplares[MAX_EJEMPLAR];
};

// Representa una operación enviada por el solicitante
struct Operaciones {
    char tipo;
    char nombre[250];
    int isbn;
    int pid;
};

// Funciones del receptor
int leerDB(char *nomArchivo, struct Libros *libros);
void enviarRespuesta(int pid, const char *mensaje);
int leerPipe(int fd, struct Operaciones *op, int verbose);
void prestamoProceso(struct Operaciones *op, struct Libros *libros, int numLibros);
void guardarSalida(char *fileSalida, struct Libros *libros, int numLibros);
void escribirTempLibros(struct Libros *libros, int numLibros);

#endif
