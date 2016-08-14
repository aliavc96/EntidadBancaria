

// Ana Alicia Vílchez Ceballos - ETSIIT (ugr)
// he creado una funcion principal para probar los métodos de mi programa

#include <iostream>
#include <cstdlib>
#include <map>
#include <utility>
#include <cstring>
#include <unistd.h>
#include "banco.h"
using namespace std;

int main(){


	string id;
	float saldo;
	int numero;
	Banco aliVil;
	int id_mov = 0;
	bool salir = false;
	cout << "HOLA :D Introduce tu identificador bancario (si no tienes introduce alguno para crearlo): " << endl;
	cin >> id;
	sleep(3);

	while(!salir){
		cout << "\n------------------------------------------------------------------------\n" << endl;
		cout << "BIENVENIDO AL BANCO ALIVIL \nopciones:\n   1 crear cuenta 	\n   2 consultar saldo	\n   3 insertar nuevo movimiento 	\n   4 ver los movimientos";
		cout << "	\n   5 modificar algun movimiento 	\n   6 eliminar movimiento \n   7 SALIR" << endl;
		cout << "\n------------------------------------------------------------------------\n" << endl;
		cout << "\nintroduce una opcion: " << endl;
		cin >> numero;

		switch (numero){
			case 1 :
			{
				cout << "procedamos a crear tu cuenta..." << endl;
				sleep(3);
				cout << "\n------------------------------------------------------------------------\n" << endl;
				cout << "introduce el saldo que quiere ingresar en este banco" << endl;
			
				cin >> saldo;
				
				aliVil.insertarCuentaBancaria(id, saldo);
				sleep(3);
				cout << "Su cuenta ha sido creada correctamente " << endl;
				sleep(3);
			}
			break;
			case 2 :
			{
					cout << "su saldo es de: " << aliVil.getSalario(id)<< endl;
					sleep(3);
			}
			break;
			case 3 :
			{ 
				float cantidad;
				cout << "introduce la cantidad del movimiento: " << endl;
				cin >> cantidad;
				aliVil.insertarMovimiento(id, id_mov, cantidad);
				id_mov++;
				
				cout << "el movimiento ha sido introducido correctamente" << endl;
				sleep(3);
			}
			break;
			case 4 :
			{
				map <int, float>:: iterator it ;
				map <int, float> lista = aliVil.getMovimientos(id);
				for(it = lista.begin(); it != lista.end(); it++)
					cout << "nº movimiento: " << (*it).first << "	cantidad: " << (*it).second << endl;
				sleep(3);

			}
			break;
			case 5 : 
			{
				int n_mov;
				float cantidad;
				cout << "introduce el numero de movimiento y la cantidad a modificar: " << endl;
				cin >> n_mov >> cantidad;
				aliVil.modificarMovimiento(id, n_mov, cantidad);
				sleep(3);
				cout << "exito en la operacion " << endl;
				sleep(3);

			}
			break;
			case 6 :
			{
				int n_mov;
				cout << "introduce el id del movimiento a eliminar" << endl;
				cin >> n_mov;
				aliVil.eliminarMovimiento(id, n_mov);
				sleep(3);
				cout << "exito en la operacion " << endl;
				sleep(3);
			}
			break;
			case 7 :
			{
				salir = true;
			}

			default:
      			cout << "Esa opcion no se encuentra disponible." << endl;
      			sleep(3);
       		break;

		}

		system("clear");//Borrando pantalla

	// movimientos

	}
}
