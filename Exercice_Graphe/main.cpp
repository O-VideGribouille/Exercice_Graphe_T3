#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <cassert>

#include "ex_24_1.h";

using namespace std;

void init(s_reseau* Reseau);
void chargementResM(s_reseau* Reseau, s_sommet s);
void saveResStockM();
bool connectionCable(s_reseau Reseau, s_sommet s1, s_sommet s2);
bool tabNoeudCont(s_reseau Reseau, int tabExF);

bool graphNonOriente(s_reseau Reseau, s_sommet s1, s_sommet s2);

bool graphColoriage(s_reseau Reseau);

int main() {

	s_reseau Reseau;
	s_sommet s;
	s.n_sommet = 0;
	s.n_id = 0;
	s_sommet s2;
	s2.n_sommet = 1;
	s2.n_id = 1;
	s_sommet s3;
	s3.n_sommet = 2;
	s3.n_id = 2;
	s_sommet s4;
	s4.n_sommet = 3;
	s4.n_id = 3;
	//24.1
	//a) initialisation
	init(&Reseau);

	//b) chargement du r�seau en m�moire
	chargementResM(&Reseau, s);
	chargementResM(&Reseau, s2);
	chargementResM(&Reseau, s3);
	chargementResM(&Reseau, s4);

	//c) sauvegarde du r�seau stock� en m�moire
	// Est-il question de cr�er un tableau,temporaire ou non, pour mettre les donn� du tableau de c�t� ?



	//d) D�terminer si deux machines sont connect� par un c�ble
	cout << "Est-ce que deux machines on un c�ble entre eux :" <<endl;
	cout << "Machine 1 et Machine 2 : " << connectionCable(Reseau, s, s2) << endl;

	cout << "Machine 1 et Machine 3 : " << connectionCable(Reseau, s, s3) << endl;

	cout << "Machine 1 et Machine 4 : " << connectionCable(Reseau, s, s4) << endl;

	cout << "Machine 2 et Machine 3 : " << connectionCable(Reseau, s2, s3) << endl;

	cout << "Machine 2 et Machine 4 : " << connectionCable(Reseau, s2, s4) << endl;

	cout << "Machine 3 et Machine 4 : " << connectionCable(Reseau, s3, s4) << endl << endl;

	//e) Quest-ce qu'un chemin dans le r�seau ?
	 
	cout << "Un chemin dans un reseau est une suite de sommets. Ils se suivent en etant lie par un cable." << endl;
	cout << endl << endl;

	//f) Prendre en param�tre un tableau de num�ros de noeuds du r�seau et 
	//qui d�termine si qhaque noeud du tableau est connect� au suivant par un c�ble
	int tabExF[5];
	//tabNoeudCont(Reseau, tabExF[5]);



	//24.2 graphe non-orient� : 
	//Donner une priorit� de la matrice qui soit caract�ristique d'un graphe non orient�
	//Donner un algorithme qui prend en param�tre un graphe donn� sous forme de matrice d'adjacence,
	//et qui renvoie 1 si le graphe et non orient�, sinon 0.

	cout << "Est-ce non-oriente ? " << endl;
	cout << "Machine 1 et Machine 2 : " << graphNonOriente(Reseau, s, s2) << endl;
	cout << "Machine 1 et Machine 2 : " << graphNonOriente(Reseau, s2, s3) << endl;
	cout << "Machine 1 et Machine 2 : " << graphNonOriente(Reseau, s3, s4) << endl;

	//24.3
	//Prendre en param�tre un graphe G repr�sent� sous forme de matrice d'adjacence et un coloriage,
	//et qui renvoie 1 si le coloriage de G est correst, sinon 0.


	//25.1

	//25.2

	//25.3
	
	//25.4
	
	//25.5

	//25.6

	//26.1

	//26.2

	//26.3
	//a)
	//b)
	//c)
	//d)
	//e)

	//26.4
	//a)
	//b)

	//26.5


	return 0;

};

// version dynamique
/* 
void init(s_reseau* Reseau) {

	Reseau->n = 0;
	Reseau->m = 0;
	
	Reseau->tab_sommet = new s_sommet[0];
	
	Reseau->tab_matrice = new char*[0];

	

}*/

//version avec constente
void init(s_reseau* Reseau) {

	Reseau->n = 3;
	Reseau->m = 3;

	Reseau->tab_sommet = new s_sommet[Reseau->n];

	for (int i = 0; i < Reseau->n; i++)
	{
		Reseau->tab_sommet[i].n_sommet = -1;
	}

	Reseau->tab_matrice = new char* [Reseau->m];

	for (int i = 0; i < Reseau->m; i++)
	{
		Reseau->tab_matrice[i] = new char[Reseau->m];
	}


}

void chargementResM(s_reseau* Reseau, s_sommet s){

	//Reseau->n = 3;
	//Reseau->tab_sommet;
	int i = 0;
	
	bool b_nodeHere = false;
	
	while (b_nodeHere == false)
	{
		
		if (Reseau->tab_sommet[i].n_sommet == -1) // v�rification si cellule vide
		{
			Reseau->tab_sommet[i] = s;
			b_nodeHere = true;
		}

		i++;
		
		if (i == Reseau->n) // pour sortir de la boucle
		{
			b_nodeHere = true;
		}

	}

}

void saveResStockM(){


}

bool connectionCable(s_reseau Reseau, s_sommet s1, s_sommet s2) {

	for (int i = 0; i < Reseau.n ; i++)
	{
		if (Reseau.tab_sommet[i].n_id == s1.n_id)// ne peut pas fonctionner ainsi
		{
			for (int j = 0; j < Reseau.n; j++)
			{
				if (Reseau.tab_sommet[j].n_id == s2.n_id)
				{
					if (Reseau.tab_matrice[i][j] == 1)
					{
						return true;
					}

				}

			}
		}
	
	}
	 


	return false;
}

bool tabNoeudCont(s_reseau Reseau, int tabExF)
{


	for (int i = 0; i < tabExF ; i++)
	{
		//connectionCable(Reseau, s, s2);
	}

	return false;
}

bool graphNonOriente(s_reseau Reseau, s_sommet s1, s_sommet s2)
{

	if (connectionCable(Reseau, s1, s2) == true)
	{

		for (int i = 0; i < Reseau.n; i++)
		{
			if (Reseau.tab_sommet[i].n_id == s2.n_id)// ne peut pas fonctionner ainsi
			{
				for (int j = 0; j < Reseau.n; j++)
				{
					if (Reseau.tab_sommet[j].n_id == s1.n_id)
					{
						if (Reseau.tab_matrice[i][j] == 1)
						{
							return true;
						}

					}

				}
			}

		}


	}


	return false;
}




/* Un graphe est dif�rent d'un arbre. 
Dans le formalisme du graphe, on pourra avoir plusieurs sommet, mais aussi plusieurs route/chemin/cable entre les sommets.
Cees sommet vont �tre en relation par les cables.
On a des arc qui vont d�finir le sens des route entre sommets.
Dans la navigation ,c comme les arbres binaire, on va passer d'un successeur � un autre.
On d�finit un sens de passage de sommet.
Toujours v�rifier le d�placement.
Plus le graphe est grand, plus la matrice est grande = ce qui est fortement d�conseill�.
Utilisation de liste :
On va entr� les sommet et les succ�sseurs.

Il vaut bien meux d'utiliser les liste (voir liste doublement chain�e) que des tableaux !

Chauqe noeud est hi�rarchique. 



*/