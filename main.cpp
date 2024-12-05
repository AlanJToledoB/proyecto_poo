#include "LoginSystem.h"

int main() {
	string archivoUsuarios = "usuarios.txt";
	LoginSystem sistemaDeLogin(archivoUsuarios);
	sistemaDeLogin.mostrarMenu();
	return 0;
}
