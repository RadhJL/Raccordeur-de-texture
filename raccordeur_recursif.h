#ifndef _RACCORDEUR_RECURSIF_H
#define	_RACCORDEUR_RECURSIF_H

#include "raccordeur.h"


class RaccordeurRecursif : public Raccordeur {

  virtual pair<int,int*> CoupeOptimale(MatInt2* distances, int x,int y,int tab[]);
  virtual int calculerRaccord(MatInt2* distances, int* coupe);
  virtual ~RaccordeurRecursif(); // destructeur

};

#endif	/* _RACCORDEUR_SIMPLE_H */

