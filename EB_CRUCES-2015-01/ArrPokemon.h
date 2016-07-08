/**
*
* ArrPokemon.h
*
* EXAMEN FINAL 2015-01 (Programaci�n 2 - UPC)
*
* @author Brayan Cruces (brayancru.com)
* @since 1.0.0
* @version 1.0.0, 07/07/2015
*
*/
#pragma once

#include "PiedraTipoAgua.h";
#include "PiedraTipoFuego.h";
#include "Charizard.h";
#include "Blastoise.h";

/*** ArrPokemon CLASS ***/
/* - Funciona como clase controladora
- Colisi�n (Triple colision)

*/
class ArrPokemon
{
private:
	Pokemon** arreglo;//Este sera el arreglo que contendra a todos los Pokemones, sin importar su tipo
	int cantidad;//nos va a servir para todos los "for"
	int contBlastoise;
	int contCharizard;
	int combx;//estas variable sera la coordernadas que tendra una combinacion
	int comby;//y deben ser inicializadas antes de crear la combinacion, o de lo contrario se generar� un error

public:
	ArrPokemon(void);//No requiere sobrecarga, porque no hay herencia 
	~ArrPokemon(void);//destructor


	int GET_cantidad();//para los "for" que se hagan fuera de esta clase
	int GET_contBlastoise();
	int GET_contCharizard();

	void Insertar(int tipo);

	void Eliminar(int posEnArreglo);//Para el boton eliminar
	void VerificarColisiones(Graphics^ miGraphic);//Verifica si los objetos chocan y modifica elementos del array si es necesario
	void MoverTodo(Graphics^ miGraphic);//Esta es la funcion que se llamara a cada tick del MyForm, si no hay pausa, claro

};

ArrPokemon::ArrPokemon(void)
{
	contBlastoise = 0;
	contCharizard = 0;
	cantidad = 0;//Importante inicializarla en 0
	arreglo = NULL;
}

ArrPokemon::~ArrPokemon(void)
{
	for (int i = 0; i < cantidad; i++)
		delete arreglo[i];

}

//M�todos GET
int ArrPokemon::GET_cantidad(){ return cantidad; }
int ArrPokemon::GET_contBlastoise(){ return contBlastoise; }
int ArrPokemon::GET_contCharizard(){ return contCharizard; }

void ArrPokemon::Insertar(int tipo)
{

	Pokemon** auxiliar = new Pokemon*[cantidad + 1];

	if (auxiliar != NULL)
	{
		for (int i = 0; i < cantidad; i++)
			auxiliar[i] = arreglo[i];


		/* CREACI�N DE OBJETOS SEG�N TIPO */
		// Tipo 1 -> Piedra Agua 
		// Tipo 2 -> Piedra Fuego 
		// Tipo 3 -> Blastoise
		// Tipo 4 -> Charizard

		if (tipo == 1){ auxiliar[cantidad] = new PiedraAgua(rand() % 635, rand() % 335); }
		if (tipo == 2){ auxiliar[cantidad] = new PiedraFuego(rand() % 635, rand() % 335); }
		if (tipo == 3){ auxiliar[cantidad] = new Blastoise(rand() % 635, rand() % 335); }
		if (tipo == 4){ auxiliar[cantidad] = new Charizard(rand() % 635, rand() % 335); }

		cantidad++;

		if (arreglo != NULL)
			delete arreglo;

		arreglo = auxiliar;

	}
}


void ArrPokemon::Eliminar(int posEnArreglo)
{
	//se crea un arreglo auxiliar pero esta vez con un valor menos 
	Pokemon** auxiliar = new Pokemon*[cantidad - 1];

	if (auxiliar != NULL)
	{
		//Dividimos el for en dos, para no copiar a el Pokemon que queremos eliminar

		for (int i = 0; i <= posEnArreglo - 1; i++)//Copiamos los Pokemones hasta el anterior objeto del que se quiere eliminar
			auxiliar[i] = arreglo[i];

		//...Y continuamos copiando desde el Pokemon que est� despues del que se quiere eliminar hasta el final
		for (int i = posEnArreglo + 1; i < cantidad; i++)
			auxiliar[i - 1] = arreglo[i];//se pone "[auxiliar - 1]"  porque se ya nos pasamos uno(el que se quiere eliminar)

		//Recien actualizamos el valor de cantidad
		cantidad--;

		// Y luego el mismo proceso para reemplazar arreglos
		if (arreglo != NULL)
			delete arreglo;

		arreglo = auxiliar;

	}
}

void ArrPokemon::VerificarColisiones(Graphics^ miGraphic)
{

	/* 1- TRIPLE COLISI�N */

	for (int i = 0; i < cantidad - 2; i++)
		for (int j = i + 1; j < cantidad - 1; j++)
			for (int h = j + 1; h <cantidad - 0; h++)
			{


				//Creamos 3 Rectangulos es decir 3 objetos (METODO CRAYON)				
				Rectangle obj1 = Rectangle(arreglo[i]->GET_x(), arreglo[i]->GET_y(), arreglo[i]->GET_ancho(), arreglo[i]->GET_altura());
				Rectangle obj2 = Rectangle(arreglo[j]->GET_x(), arreglo[j]->GET_y(), arreglo[j]->GET_ancho(), arreglo[j]->GET_altura());
				Rectangle obj3 = Rectangle(arreglo[h]->GET_x(), arreglo[h]->GET_y(), arreglo[h]->GET_ancho(), arreglo[h]->GET_altura());


				// Verificamos Triple colision
				if (!(obj1.IntersectsWith(obj2)) || !(obj2.IntersectsWith(obj3)) || !(obj3.IntersectsWith(obj1)))
					;//No Hacemos Nada

				// Triple colision : OK 
				else
				{
					// CASO 1: 1 piedra agua y 2 piedras fuego  (Charizard)
					if ((arreglo[i]->GET_tipo() == 2 && arreglo[j]->GET_tipo() == 1 && arreglo[h]->GET_tipo() == 1) ||
						(arreglo[j]->GET_tipo() == 2 && arreglo[i]->GET_tipo() == 1 && arreglo[h]->GET_tipo() == 1) ||
						(arreglo[h]->GET_tipo() == 2 && arreglo[i]->GET_tipo() == 1 && arreglo[j]->GET_tipo() == 1))
					{

						//Coordenada de partida de la nueva combinacion
						combx = (arreglo[i]->GET_x() + arreglo[j]->GET_x() + arreglo[h]->GET_x()) / 3;
						comby = (arreglo[i]->GET_y() + arreglo[j]->GET_y() + arreglo[h]->GET_y()) / 3;

						Insertar(4); //Inserta Charizard
						contCharizard++; // +1 Charizard

					} //end if

					// CASO 2: 1 piedra fuego y 2 piedras agua (Blastoise)
					if ((arreglo[i]->GET_tipo() == 1 && arreglo[j]->GET_tipo() == 2 && arreglo[h]->GET_tipo() == 2) ||
						(arreglo[j]->GET_tipo() == 1 && arreglo[i]->GET_tipo() == 2 && arreglo[h]->GET_tipo() == 2) ||
						(arreglo[h]->GET_tipo() == 1 && arreglo[i]->GET_tipo() == 2 && arreglo[j]->GET_tipo() == 2))
					{

						//Coordenada de partida de la nueva combinacion
						combx = (arreglo[i]->GET_x() + arreglo[j]->GET_x() + arreglo[h]->GET_x()) / 3;
						comby = (arreglo[i]->GET_y() + arreglo[j]->GET_y() + arreglo[h]->GET_y()) / 3;

						Insertar(3); //Inserta Blastoise
						contBlastoise++; // +1 Blastoise
					}  //end if


				}

			}

	/* 2- REBOTE : Colision Pokemon-Pared (recorrido de elementos)	*/
	for (int i = 0; i < cantidad; i++)
	{

		if (arreglo[i]->GET_tipo() == 3 || arreglo[i]->GET_tipo() == 4)
		{
			/* EJE X */
			//Si choca con la pared izquierda o si choca con la pared derecha...
			if (arreglo[i]->GET_x() + arreglo[i]->GET_dx() < 0 || arreglo[i]->GET_x() + arreglo[i]->GET_dx() + arreglo[i]->GET_ancho() > miGraphic->VisibleClipBounds.Width)
				arreglo[i]->InvertirDx();//Cambiamos el sentido en el que se mueve horizontalmente

			/* EJE Y */
			//Si es que choca con la pared de arriba o si choca con la pared abajo
			if (arreglo[i]->GET_y() + arreglo[i]->GET_dy() < 0 || arreglo[i]->GET_y() + arreglo[i]->GET_dy() + arreglo[i]->GET_altura() > miGraphic->VisibleClipBounds.Height)
				arreglo[i]->InvertirDy();//Cambiamos el sentido en el que se mueve verticalmente
		}
	}

}

void ArrPokemon::MoverTodo(Graphics^ miGraphic)
{

	VerificarColisiones(miGraphic);

	//Luego con el arreglo actualizado por VerificarColisiones
	for (int i = 0; i < cantidad; i++)
	{

		arreglo[i]->Mover();
		arreglo[i]->Mostrar(miGraphic);
	}
}

