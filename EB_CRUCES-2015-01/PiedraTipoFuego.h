/**
*
* PiedraTipoFuego.h
*
* EXAMEN FINAL 2015-01 (Programación 2 - UPC)
*
* @author Brayan Cruces (brayancru.com)
* @since 1.0.0
* @version 1.0.0, 07/07/2015
*
*/
#pragma once
#include "Pokemon.h";

/* PIEDRA TIPO FUEGO (2) */
// - Hija de Pokemon class
class PiedraFuego : public Pokemon
{
private:
	//esta vez no hay elementos privados, osea exclusivos de esta clase hija
public:
	PiedraFuego(void);
	PiedraFuego(int px, int py);// constructor
	~PiedraFuego();//destructor

	/* Esta clase ya se definio en la clase padre, pero gracias al polimorfismo vamos a poder
	definirla denuevo aca, porque esta funcion va a ser diferente en cada clase hija.      */
	void Mostrar(Graphics^ miGraphic);
};

PiedraFuego::PiedraFuego(void){ }

//El constructor de una clase hija es de la siguiente manera:
PiedraFuego::PiedraFuego(int px, int py) : Pokemon(px, py)
{
	ancho = 23;
	altura = 23;
	int R = rand() % 2;

	//Pero tambien los mas lentos

	if (R)
	{
		dx = 5;
		dy = 5;
	}

	else
	{
		dx = -5;
		dy = 5;
	}

	// Definir tipo
	tipo = 2;
}

PiedraFuego::~PiedraFuego(){ }



void PiedraFuego::Mostrar(Graphics^ miGraphic)
{
	//Incluir imagen	
	Bitmap^ ImagenPiedraFuego = gcnew Bitmap("Piedra2.png");


	miGraphic->DrawImage(ImagenPiedraFuego, Rectangle(x, y, ancho, altura), Rectangle(0, 0, ancho, altura), GraphicsUnit::Pixel);
}