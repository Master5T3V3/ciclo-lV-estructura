/*Programa desarrollado por Brian Steve Rodas Hernandez
	Arvol binario de busqueda con opciones adicionales*/

#include <iostream>
#include <cstdlib>
#include <windows.h>

using namespace std;

class ArbolBinarioBusqueda {
	private:
		struct nodo{
			int nro;
			struct nodo *izq, *der;
		};
		
	public:
		typedef struct nodo *ABB;
		/* es un puntero de tipo nodo que hemos llamado ABB, que ulitizaremos
		para mayor facilidad de creacion de variables */
		int nodos;
		ABB arbol = NULL;
		
		ABB crearNodo(int x) {
	    	ABB nuevoNodo = new(struct nodo);
	    	nuevoNodo->nro = x;
	    	nuevoNodo->izq = NULL;
	    	nuevoNodo->der = NULL;
	
	    	return nuevoNodo;
		}
	
		//Insercion del nodo singular
		void insertar(ABB &arbol, int x)
		{
			if (arbol == NULL)
			 {
				arbol = crearNodo(x);
				cout << "\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t  Insertado..!" << endl << endl;
			}
			else if (x < arbol->nro) {
				insertar(arbol->izq, x);
			}
			else if (x > arbol->nro)
				insertar(arbol->der, x);
		}
		
		void preOrden(ABB arbol)
		{
			if (arbol != NULL)
			{
				cout << arbol->nro << " ";
				preOrden(arbol->izq);
				preOrden(arbol->der);
			}
		}
		void enOrden(ABB arbol)
		{
			if (arbol != NULL)
			{
				enOrden(arbol->izq);
				cout << arbol->nro << " ";
				enOrden(arbol->der);
			}
		}
		void postOrden(ABB arbol)
		{
			if (arbol != NULL)
			{
				postOrden(arbol->izq);
				postOrden(arbol->der);
				cout << arbol->nro << " ";
			}
		}
		
		void verArbol(ABB arbol, int n) {						
			if (arbol == NULL) { //arbol vacio
				return;
			}
			else {
				verArbol(arbol->der, n + 1); // para en el nodo que esta mas a la derecha
				for(int i = 0; i < n; i++) {
					cout << " ";
				}
				nodos++;
				cout<< arbol->nro <<endl;
				
				verArbol(arbol->izq, n + 1); // para en el nodo que esta mas a la izquierda
			}
		}
		
		void Nodos(ABB arbol, int n) {						
			if (arbol == NULL) { //arbol vacio
				return;
			}
			else {
				Nodos(arbol->der, n + 1); // para en el nodo que esta mas a la derecha
				nodos++;
				
				Nodos(arbol->izq, n + 1); // para en el nodo que esta mas a la izquierda
			}
		}
		
		int alturaABB(ABB arbol) {
		    int AltIzq;
			int AltDer;
		
		    if(arbol == NULL) {
		        return 0;
		    }
		    else {
		        AltIzq = alturaABB(arbol->izq);
		        AltDer = alturaABB(arbol->der);
		
		        if(AltIzq > AltDer) {
		            return AltIzq+1;
		        }
		        else {
		            return AltDer+1;
				}
		    }
		}
		
		int sumABB(ABB arbol) {
		    if (arbol == 0) {return 0;}
		    
		    return arbol->nro + sumABB(arbol->izq) + sumABB(arbol->der);
		}
		
		void AltEnter() { //Funcion para simular teclas alt + enter (pantalla completa)
		    keybd_event(VK_MENU, 0x38, 0, 0); //Inicializar
		    keybd_event(VK_RETURN, 0x1c, 0, 0); //Inicializar
		    keybd_event(VK_RETURN, 0x1c, KEYEVENTF_KEYUP, 0); //Lanzar tecla sin intrada manual
		    keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0); //Lanzar tecla sin entrada manual
		}
		
		void gotoxy(int x, int y) {	//Funcion para obtener coordenadas en pantalla
			HANDLE hConsoleOutput; //Propiedades que debe tener la terminal o consola
			COORD Cursor_Pos = { x,y };	//Fijar coordenadas del cursor
			hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE); //Obtener propiedades por movimiento
			SetConsoleCursorPosition(hConsoleOutput, Cursor_Pos); //Setear coordenadas
		}

		void menu(ABB arbol) {
			system("cls"); //Limpiar pantalla de consola
			system("color 30"); //Cambiar colores, fondo turquesa, texto negro
		    cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl; //Espacios de linea
		    //Imprimir menu de opciones en pantalla
			cout << "\t\t\t\t\t\t\t###################################################" << endl;
		    cout << "\t\t\t\t\t\t\t## ******* [[MENU DE OPCIONES DE ARBOL]] ******* ##" << endl;
		    cout << "\t\t\t\t\t\t\t## --------------------------------------------- ##" << endl;
		    cout << "\t\t\t\t\t\t\t##                                               ##" << endl;
		    cout << "\t\t\t\t\t\t\t##        1. Agregar nodos al arbol              ##" << endl;
		    cout << "\t\t\t\t\t\t\t##        2. Mostrar arbol graficamente          ##" << endl;
		    cout << "\t\t\t\t\t\t\t##        3. Recorrer arbol                      ##" << endl;
		    cout << "\t\t\t\t\t\t\t##        4. Salir del programa                  ##" << endl;
		    cout << "\t\t\t\t\t\t\t##                                               ##" << endl;
		    cout << "\t\t\t\t\t\t\t## --------------------------------------------- ##" << endl;
		    cout << "\t\t\t\t\t\t\t##           Digite la opcion:                   ##" << endl; //Mensaje para pedir ingreso de opcion
		    cout << "\t\t\t\t\t\t\t###################################################" << endl << endl << endl;
		    Nodos(arbol, 0);
		    cout << "\t\t\t\t\t\t\t        ---> Numero de nodos: " << nodos << endl;
		    nodos = 0;
		    gotoxy(88, 21);
		}
		
		void submenu(ABB arbol) {
			system("cls");
			system("color 03");
			cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl; //Espacios de linea
		    //Imprimir menu de opciones en pantalla
			cout << "\t\t\t\t\t\t\t ------------------------------------------------- " << endl;
		    cout << "\t\t\t\t\t\t\t|          [[MENU DE OPCIONES DE ARBOL]]          |" << endl;
		    cout << "\t\t\t\t\t\t\t|-------------------------------------------------|" << endl;
		    cout << "\t\t\t\t\t\t\t|                                                 |" << endl;
		    cout << "\t\t\t\t\t\t\t|         1. Recorrer arbol en Inorden            |" << endl;
		    cout << "\t\t\t\t\t\t\t|                                                 |" << endl;
		    cout << "\t\t\t\t\t\t\t|         2. Recorrer arbol en PreOrden           |" << endl;
		    cout << "\t\t\t\t\t\t\t|                                                 |" << endl;
		    cout << "\t\t\t\t\t\t\t|         3. Recorrer arbol en PostOrden          |" << endl;
		    cout << "\t\t\t\t\t\t\t|                                                 |" << endl;
		    cout << "\t\t\t\t\t\t\t ------------------------------------------------- " << endl;
		    cout << "\t\t\t\t\t\t\t|            Digite la opcion:                    |" << endl; //Mensaje para pedir ingreso de opcion
		    cout << "\t\t\t\t\t\t\t ------------------------------------------------- " << endl;
		    gotoxy(88, 22);
		}
};


int main() {
	system( "color 30");
	ArbolBinarioBusqueda *a = new ArbolBinarioBusqueda();
	a->AltEnter();
	int opc;
	int opcs;
	int n;
	int x;
	int h;
	
	retorno:
	do {
		a->menu(a->arbol);
		cin >> opc;
	}
	while(opc < 1 || opc > 4);
	
	system("cls");
	system("color 30");
	switch(opc) {
		case 1:
			system("color 57");
			cout << "\n\n\n\n\n\t\t\t\t\t\t\t\t### Numero de nodos a ingresar: ";
			cin >> n;
			cout << endl;
			
			for(int i = 0; i < n; i++) {
				cout << "\t\t\t\t\t\t\t\t--> Ingrese nodo " << i + 1 << ": ";
				cin >> x;
				a->insertar(a->arbol, x);
			}
			cout << endl << endl;
			system("pause");
			goto retorno;
		
		case 2:
			if(a->arbol != NULL) {
				a->verArbol(a->arbol, 0); 
				cout << endl << endl;
				cout << endl << "\t\t--> Numero de nodos: " << a->nodos;
				cout << endl << "\t\t--> La altura del arbol es de: " << a->alturaABB(a->arbol);
				cout << endl << "\t\t--> La suma de todos los nodos es:" << a->sumABB(a->arbol) << endl << endl;
				a->nodos = 0; 
				system("pause");
				goto retorno;
			}
			else {
				system("color 4F"); //Cambiar colores, fondo rojo, texto blanco
				//Mostrar mensaje de error
				cout << endl << endl << endl << endl << endl;
				cout << "\t\t\t\t\t\t\t//////////////////////////////////////////////////" << endl;
				cout << "\t\t\t\t\t\t\t/  ### Error, aun no se han ingresado nodos ###  /" << endl;
				cout << "\t\t\t\t\t\t\t//////////////////////////////////////////////////" << endl << endl << endl << endl;
				system("pause");
				goto retorno;
			}
			
		case 3:
			if(a->arbol != NULL){
				do {
					a->submenu(a->arbol);
					cin >> opcs;
				}
				while(opcs < 1 || opcs > 3);
				
				system("cls");
				system("color 30");
				switch(opcs) {
					case 1:
						cout << "\n\t\t\tMostrando arbol enOrden" << endl;
						cout << "\t\t\t";
						a->enOrden(a->arbol);
						cout << endl << endl;
						system("pause");
						goto retorno;
						
					case 2:
						cout << "\n\t\t\tMostrando arbol preOrden" << endl;
						cout << "\t\t\t";
						a->preOrden(a->arbol);
						cout << endl << endl;
						system("pause");
						goto retorno;
						
					case 3:
						cout << "\n\t\t\tMostrando arbol postOrden" << endl;
						cout << "\t\t\t";
						a->postOrden(a->arbol);
						cout << endl << endl;
						system("pause");
						goto retorno;
				}
			}
			else {
				system("color 4F"); //Cambiar colores, fondo rojo, texto blanco
				//Mostrar mensaje de error
				cout << endl << endl << endl << endl << endl;
				cout << "\t\t\t\t\t\t\t//////////////////////////////////////////////////" << endl;
				cout << "\t\t\t\t\t\t\t/  ### Error, aun no se han ingresado nodos ###  /" << endl;
				cout << "\t\t\t\t\t\t\t//////////////////////////////////////////////////" << endl << endl << endl << endl;
				system("pause");
				goto retorno;
			}
			
		case 4:
			break;
	}
	
	return 0;
}
