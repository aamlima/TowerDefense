#ifndef _INIMIGODEMO_H_
#define _INIMIGODEMO_H_

#include "Inimigo.h"

class InimigoDemo :	public Inimigo
{
public:
	InimigoDemo(GerenteAtor& _gerente, Mapa& _map, int _x, int _y, iDirecao _dir, TDBase *_td);
	
	void inicializar();			
    void atualizar();	
	void desenhar();		
	void finalizar();
};
#endif


