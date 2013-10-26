#include "globalDef.h"

#include "MenuInicial.h"
#include "TowerDefense.h"
#include "MapEditor.h"

#include "MenuToggle.h"
#include "MenuText.h"
#include "MenuButton.h"

#include <c2d2/chien2d2.h>

Tela* MenuInicial::proximaTela()
{
	C2D2_Botao* teclas = C2D2_PegaTeclas();

	if (teclas[C2D2_ENCERRA].pressionado || teclas[C2D2_ESC].pressionado || btnExit->getEstado() == SOLTO)
		return nullptr;	
	if(btnTD->getEstado() == SOLTO)
		return new TowerDefense();
	if(btnME->getEstado() == SOLTO)
		return new MapEditor();
	return this;
}

void MenuInicial::inicializar()
{
	C2D2_TrocaCorLimpezaTela(255, 255, 255);
	mouseSprite = C2D2_CarregaSpriteSet("imgs/mouse.png", 0, 0);
	tahoma16 = C2D2_CarregaFonte("imgs/tahoma16.bmp", 16);
	tahoma32 = C2D2_CarregaFonte("imgs/tahoma32.bmp", 32);
	tahoma64 = C2D2_CarregaFonte("imgs/tahoma64.bmp", 64);

#ifdef LOG
	if(mouseSprite == 0)
		addToLog("Falha ao carregar sprite do mouse!(MenuInicial.cpp)");
	if(tahoma16 == 0)
		addToLog("Falha ao carregar a fonte Tahoma de tamanho 16!(MenuInicial.cpp)");
	if(tahoma32 == 0)
		addToLog("Falha ao carregar a fonte Tahoma de tamanho 32!(MenuInicial.cpp)");
	if(tahoma64 == 0)
		addToLog("Falha ao carregar a fonte Tahoma de tamanho 64!(MenuInicial.cpp)");
#endif

	menus.push_back(new MenuText("TowerDefense", 400, 100, tahoma64));
	menus.push_back(btnTD = new MenuButton("Jogar", 400, 300, tahoma32));
	menus.push_back(btnME = new MenuButton("MapEditor", 400, 350, tahoma32));
	menus.push_back(btnExit = new MenuButton("Sair!", 400, 500, tahoma32));
}

void MenuInicial::atualizar()
{
	C2D2_Mouse* m = C2D2_PegaMouse();
	C2D2_Botao* teclas = C2D2_PegaTeclas();
	mouseX = m->x;
	mouseY = m->y;

	for(Menu* menu : menus){
		menu->atualizar();
	}
}

void MenuInicial::desenhar()
{
	for(Menu* menu : menus){
		menu->desenhar();
	}

	C2D2_DesenhaSprite(mouseSprite, 0, mouseX, mouseY);
}

void MenuInicial::finalizar()
{
	for(Menu* menu : menus){
		delete menu;
	}
	C2D2_RemoveSpriteSet(mouseSprite);
	C2D2_RemoveFonte(tahoma16);
	C2D2_RemoveFonte(tahoma32);
	C2D2_RemoveFonte(tahoma64);
}