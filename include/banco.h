
// Ana Alicia Vílchez Ceballos - ETSIIT (ugr)
// este es el .h para el programa Banco.cpp


#ifndef BANCO
#define BANCO

#include <iostream>
#include <cstdlib>
#include <map>
#include <utility>
#include <cstring>
#include <unistd.h>
#include <banco.h>
using namespace std;

class Banco{


private:
	// el string hace referencia al identificador de la cuenta y el float hace referencia al banco
	map <string, float> salarios;
	// aquí tenemos el identificador de la cuenta y los movimientos de cada cuenta (con un identificador por movimiento)
	map <string, map <int, float> > movimientos;

public:

	// obtener el saldo de una cuenta bancaria:
	float getSalario(string id);

	// para insertar un nuevo movimiento en la cuenta x
	void insertarMovimiento(string id, int id_mov, float mov);

	// para eliminar un movimiento de x cuenta:
	void eliminarMovimiento(string id, int id_mov);


	// para modificar un movimiento de x cuenta:
	void modificarMovimiento(string id, int nmov, float cantidad);

	//insertamos una nueva cuenta bancaria:
	void insertarCuentaBancaria(string ncuenta, float salario);

	// Obtener los movimientos de una determinada cuenta bancaria
	map <int, float>getMovimientos(string id);
};

#endif
