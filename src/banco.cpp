

// Ana Alicia Vílchez Ceballos - ETSIIT (ugr)
// este es el fichero banco.cpp, contiene las funciones declaradas en banco.h

#include <iostream>
#include <cstdlib>
#include <map>
#include <utility>
#include <cstring>
#include <unistd.h>
#include "banco.h"
using namespace std;

// obtener el saldo de una cuenta bancaria:
float Banco::getSalario(string id)
{
	map <string, float>:: iterator it;
	it = salarios.find(id);

	if(it == salarios.end()){
			cout << "ERROR: NO existe la cuenta bancaria" << endl;
		return 0;
	}
	else
		return (*it).second;
}

// para insertar un nuevo movimiento en la cuenta x
void Banco::insertarMovimiento(string id, int id_mov, float mov)
{
	pair <int, float> insercion(id_mov, mov);
	map<string, map<int, float> >:: iterator it;
	it = movimientos.find(id);

	if(it == movimientos.end())
		cout << "ERROR: NO existe la cuenta bancaria" << endl;

	else{

		(*it).second.insert(insercion);
		// actualizamos el salario de la cuenta correspondiente
		salarios[id] = salarios[id] + mov;
	}
}

// para eliminar un movimiento de x cuenta:
void Banco::eliminarMovimiento(string id, int id_mov)
{
	map<string, map<int, float> >:: iterator it;
	it = movimientos.find(id);
	if(it == movimientos.end())
		cout << "ERROR: NO existe la cuenta bancaria" << endl;

	else{
		
		float a_borrar = (*it).second[id_mov];
		// quitamos la cantidad del salario correspondiente, ya que ese movimiento ha sido eliminado
		salarios[id] = salarios[id] - a_borrar;
		(*it).second.erase(id_mov);
	}

}

// para modificar un movimiento de x cuenta:
void Banco::modificarMovimiento(string id, int nmov, float cantidad)
{
	map<string, map<int, float> >:: iterator it;
	it = movimientos.find(id);

	if(it == movimientos.end())
		cout << "ERROR: NO existe la cuenta bancaria" << endl;

	else
	{
		float antigua_cantidad = (*it).second[nmov]; 
		(*it).second[nmov] = cantidad; // pisamos la antigua cantidad por la nueva

		// quitamos la cantidad del salario correspondiente, ya que ese movimiento ha sido eliminado
		salarios[id] = salarios[id] - antigua_cantidad + cantidad;
		
	}

}

	//insertamos una nueva cuenta bancaria:
void Banco::insertarCuentaBancaria(string ncuenta, float salario)
{

	pair <string, float> nueva(ncuenta, salario);
	salarios.insert(nueva);
	pair <string, map<int, float> > mov;
	mov.first = ncuenta;
	movimientos.insert(mov);
}

map <int, float> Banco::getMovimientos(string id)
{

	map<string, map<int, float> >:: iterator it;
	it = movimientos.find(id);
	if(it == movimientos.end()){
		cout << "ERROR: NO existe la cuenta bancaria" << endl;
		exit(1);
	}

	return (*it).second;

}	
