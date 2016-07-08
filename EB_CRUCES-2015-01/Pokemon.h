/**
*
* Pokemon.h
*
* EXAMEN FINAL 2015-01 (Programación 2 - UPC)
*
* @author Brayan Cruces (brayancru.com)
* @since 1.0.0
* @version 1.0.0, 07/07/2015
*
*/
#pragma once

#include<stdlib.h>//para rand() y NULL

using namespace System;
using namespace System::Drawing;

class Pokemon
{
protected:
	int x;
	int y;

	int dx;
	int dy;
	int ancho;
	int altura;
	int tipo;//1 = Piedra de Agua, 2 = Piedra de Fuego, 3 = Blastoise, 4 = Charizard , 
public:
	Pokemon(void);// para sobrecarga
	Pokemon(int px, int py);//constructor
	~Pokemon(void);//destructor

	//para colisiones, mover y mostrar el Pokemon
	int GET_x();
	int GET_y();
	int GET_ancho();
	int GET_altura();
	int GET_tipo();
	int GET_dx();
	int GET_dy();


	void InvertirDx();//para que rebote cuando choque a la pared izquierda o a la pared derecha
	void InvertirDy();//para que rebote cuando choque arriba o abajo

	void Mover();//para cambiar las coordenadas
	virtual void Mostrar(Graphics^ miGraphic) abstract;//Polimorfismo, se tiene que escribir este metodo en las clases hijas


};


Pokemon::Pokemon(void){}
Pokemon::Pokemon(int px, int py)
{
	//se asignan las variables
	x = px;
	y = py;

}

Pokemon::~Pokemon(void){}

//Metodos GET
int Pokemon::GET_x(){ return x; }
int Pokemon::GET_y(){ return y; }
int Pokemon::GET_ancho(){ return ancho; }
int Pokemon::GET_altura(){ return altura; }
int Pokemon::GET_tipo(){ return tipo; }
int Pokemon::GET_dx(){ return dx; }
int Pokemon::GET_dy(){ return dy; }

//No hay metodos SET


void Pokemon::InvertirDx()
{
	//Si es que dx es positivo se convertira en negativo 
	//Si es que dx es negativo se convertira en positivo 
	dx *= -1;
}

void Pokemon::InvertirDy()
{
	//Si es que dy es positivo se convertira en negativo 
	//Si es que dy es negativo se convertira en positivo 
	dy *= -1;
}

void Pokemon::Mover()
{
	//se actualiza las coordenadas de x, y, que pueden incrementar o disminuir
	//dependiendo si dx y dy son positivos o negativos
	x += dx;
	y += dy;
}