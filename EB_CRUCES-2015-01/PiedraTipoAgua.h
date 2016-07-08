/**
*
* PiedraTipoAgua.h
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

/* PIEDRA TIPO AGUA (1) */
// - Hija de Pokemon class
class PiedraAgua : public Pokemon
{
private:

public:
	PiedraAgua(void);
	PiedraAgua(int px, int py);
	~PiedraAgua();

	void Mostrar(Graphics^ miGraphic);
};

PiedraAgua::PiedraAgua(void){ }

PiedraAgua::PiedraAgua(int px, int py) : Pokemon(px, py)
{
	ancho = 23;
	altura = 23;
	int R = rand() % 2;


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
	tipo = 1;
}

PiedraAgua::~PiedraAgua(){ }



void PiedraAgua::Mostrar(Graphics^ miGraphic){

	//Incluir imagen	
	Bitmap^ ImagenPiedraAgua = gcnew Bitmap("Piedra1.png");

	miGraphic->DrawImage(ImagenPiedraAgua, Rectangle(x, y, ancho, altura), Rectangle(0, 0, ancho, altura), GraphicsUnit::Pixel);
}