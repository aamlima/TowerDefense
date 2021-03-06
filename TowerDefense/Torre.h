#ifndef _TORRE_H_
#define _TORRE_H_

#include "Ator.h"
#include "Projetil.h"

class Torre : public Ator
{
protected:
	int posX, posY, alcance;
	tEstado estado;
	int tSprite;
	int ind;
	int largura;
	int altura;
	int valor;
	int custo;
	int aTiro;

	//Rate of Fire
	int RoF;

	//Cooldown
	int cd;

	Ator* alvo;

	bool alive;

public:
	Torre(GerenteAtor& _gerente, int _x, int _y, int _valor, int _custo);

	Tipo tipo();
	int x();
	int y();
	int l();
	int a();
	int sprite();
	int indice();
	virtual void inicializar();
	void vender();
	int getValor();
	int comprar();
	int getAlcance();
	int getRof();

	virtual void upgrade() = 0;

	virtual ~Torre(){ }
};

#endif
