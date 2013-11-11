#ifndef _PROJETIL_H_
#define _PROJETIL_H_

#include "Ator.h"

class Projetil : public Ator
{
protected:
	int posX, posY, altura, largura, vel, dano;
	int pSprite;
	Ator& alvo;
	bool alive;

public:
	Projetil(GerenteAtor& _gerente, int _x, int _y, int _vel, Ator& _alvo, int _dano);

	int x();
	int y();
	int l();
	int a();

	int sprite();

	bool estaNoJogo();

	virtual void inicializar();

	Tipo tipo();
	int retornaDano();

	virtual ~Projetil(){ }
};

#endif
