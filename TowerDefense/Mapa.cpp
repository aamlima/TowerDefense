#include "globalDef.h"
#include "Mapa.h"

#include "c2d2f.h"

#include <iostream>
#include <fstream>

#include <c2d2/chien2d2.h>

using namespace std;

Mapa::Mapa()
	:initX(16), initY(304)
{
	for(int x = 0; x < 18; x++){
		for(int y = 0; y < 18; y++){
				map[x][y] = 0;
		}
	}
}

void Mapa::inicializar()
{
	sprite = C2D2_CarregaSpriteSet("imgs/map.png", 32, 32);
#ifdef LOG
	if(sprite == 0)
		addToLog("Falha ao carregar o sprite do mapa!(Mapa.cpp)");
#endif
}


void Mapa::desenhar()
{
	for(int x = 0; x < 18; x++){
			for(int y = 0; y < 18; y++){
				C2D2_DesenhaSprite(sprite, map[x][y]/5, x*32, y*32);
		}
	}
}
void Mapa::getInit(int &x, int &y){
	x = initX;
	y = initY;
}

char Mapa::conteudo( int x, int y )
{
	return map[x/32][y/32]%5;
}

char Mapa::conteudo32(int x, int y){
	return map[x][y]%5;
}

int Mapa::sprite32( int x, int y )
{
	return map[x][y]/5;
}

void Mapa::addTorre( int x, int y )
{
	map[x/32][y/32] += 1;
}

void Mapa::removeTorre( int x, int y )
{
	map[x/32][y/32] -= 1;
}

void Mapa::construir( int x, int y, int sprite, int id)
{
	map[x/32][y/32] = (sprite*5)+id;
}

void Mapa::save()
{
	for(int x = 0; x < 18; x++){
		for(int y = 0; y < 18; y++){
			if(map[x][y]%5 == 2){
				initX = x*32+16;
				initY = y*32+16;
			}
		}
	}
	C2D2_RemoveSpriteSet(sprite);
	ofstream ofile("map/"+stringFInput("(SAVE)Nome do mapa:", ".map")+".map", ios_base::binary);
	ofile.write((char*)this, sizeof(Mapa));
	ofile.close();
	sprite = C2D2_CarregaSpriteSet("imgs/map.png", 32, 32);
#ifdef LOG
	if(sprite == 0)
		addToLog("Falha ao carregar o sprite do mapa!(Mapa.cpp)");
#endif
}

void Mapa::load()
{
	C2D2_RemoveSpriteSet(sprite);
	string nome = "";
	stringFInput(nome, "(LOAD)Nome do mapa:", ".map");
	ifstream ifile("map/"+nome+".map", ios_base::binary);
	ifile.read((char*)this, sizeof(Mapa));
#ifdef LOG
	if(!ifile.is_open())
		addToLog("Falha ao carregar mapa:", nome);
#endif
	ifile.close();
	sprite = C2D2_CarregaSpriteSet("imgs/map.png", 32, 32);
#ifdef LOG
	if(sprite == 0)
		addToLog("Falha ao carregar o sprite do mapa!(Mapa.cpp)");
#endif
}

void Mapa::load(string nome)
{
	C2D2_RemoveSpriteSet(sprite);
	ifstream ifile("map/"+nome+".map", ios_base::binary);
#ifdef LOG
	if(!ifile.is_open())
		addToLog("Falha ao carregar mapa:", nome);
#endif
	ifile.read((char*)this, sizeof(Mapa));
	ifile.close();
	sprite = C2D2_CarregaSpriteSet("imgs/map.png", 32, 32);
#ifdef LOG
	if(sprite == 0)
		addToLog("Falha ao carregar o sprite do mapa!(Mapa.cpp)");
#endif
}

void Mapa::finalizar()
{
	C2D2_RemoveSpriteSet(sprite);
}
