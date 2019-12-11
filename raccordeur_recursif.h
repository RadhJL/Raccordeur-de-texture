#ifndef _RACCORDEUR_RECURSIF_H
#define	_RACCORDEUR_RECURSIF_H

#include "raccordeur.h"


class Raccordeur_Recursif : public Raccordeur {

  virtual int calculerRaccord(MatInt2* distances, int* coupe);

  virtual ~Raccordeur_Recursif(); // destructeur

};

#endif	/* _RACCORDEUR_SIMPLE_H */

