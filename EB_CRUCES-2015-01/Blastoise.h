/**
*
* Blastoise.h
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

/*** BLASTOISE CLASS (3)***/
// - Hija de Pokemon class
class Blastoise : public Pokemon
{
private:

public:
	Blastoise(void);
	Blastoise(int px, int py);
	~Blastoise();

	void Mostrar(Graphics^ miGraphic);
};

Blastoise::Blastoise(void){ }

Blastoise::Blastoise(int px, int py) : Pokemon(px, py)
{
	ancho = 71;
	altura = 67;


	dx = 3;
	dy = 3;

	// Definir tipo
	tipo = 3;



}

Blastoise::~Blastoise(){ }



void Blastoise::Mostrar(Graphics^ miGraphic)
{
	//Incluir imagen	
	Bitmap^ imagenBlastoise = gcnew Bitmap("Blastoise.png");

	miGraphic->DrawImage(imagenBlastoise, Rectangle(x, y, ancho, altura), Rectangle(0, 0, ancho, altura), GraphicsUnit::Pixel);
}