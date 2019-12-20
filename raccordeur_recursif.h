#ifndef _RACCORDEUR_RECURSIF_H
#define	_RACCORDEUR_RECURSIF_H
#include "raccordeur.h"
#include<algorithm>
#include<climits>
using namespace std; 

class Node{
public:
 int x;
 int cout;
 Node *child;
 Node(int x,int cout,Node* child){
 	this->x=x;
 	this->cout=cout;
 	this->child=child;
 		
 }
 Node(){
 	this->x=0;
 	this->cout=0;
 	this->child=NULL;
 		
 }
 Node(Node* n){
 	this->x=n->x;
 	this->cout=n->cout;
 	this->child=n->child;
 		
 }


};


class RaccordeurRecursif : public Raccordeur {
  virtual Node* MinChild(Node* **Memo,int min,int y, int x,int largeur);
  virtual Node* CoupeOpt(Node* **Memo,MatInt2* distances, int y,int x,int largeur);
  virtual int calculerRaccord(MatInt2* distances, int* coupe);
  virtual ~RaccordeurRecursif(); // destructeur

};

#endif	/* _RACCORDEUR_SIMPLE_H */

