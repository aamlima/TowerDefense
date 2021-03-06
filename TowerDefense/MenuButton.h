#ifndef _MENUBUTTON_H_
#define _MENUBUTTON_H_

#include "Menu.h"

class MenuButton : public Menu
{
private:
	mButton estado;
public:
	MenuButton(std::string _name, int _x, int _y, int& _fonte, double _r = 1, double _g = 0, double _b = 0, unsigned char _alfa = 255);
	MenuButton(std::string _name, int _x, int _y, int& _fonte, char* _cor, unsigned char _alfa = 255);
	mButton getEstado();
	void atualizar();
	void desenhar();

};

#endif


