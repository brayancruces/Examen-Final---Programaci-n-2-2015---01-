/**
*
* Charizard.h
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

/*** CHARIZARD CLASS (4)***/
// - Hija de Pokemon class
class Charizard : public Pokemon
{
private:

public:
	Charizard(void);
	Charizard(int px, int py);
	~Charizard();

	void Mostrar(Graphics^ miGraphic);
};

Charizard::Charizard(void){ }

Charizard::Charizard(int px, int py) : Pokemon(px, py)
{
	ancho = 105;
	altura = 80;


	dx = 3;
	dy = 3;

	// Definir tipo
	tipo = 4;
}

Charizard::~Charizard(){ }



void Charizard::Mostrar(Graphics^ miGraphic)
{

	//Incluir imagen	
	Bitmap^ imagenCharizard = gcnew Bitmap("Charizard.png");


	miGraphic->DrawImage(imagenCharizard, Rectangle(x, y, ancho, altura), Rectangle(0, 0, ancho, altura), GraphicsUnit::Pixel);
}