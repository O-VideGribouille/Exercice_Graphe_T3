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

	//b) chargement du réseau en mémoire
	chargementResM(&Reseau, s);
	chargementResM(&Reseau, s2);
	chargementResM(&Reseau, s3);
	chargementResM(&Reseau, s4);

	//c) sauvegarde du réseau stocké en mémoire
	// Est-il question de créer un tableau,temporaire ou non, pour mettre les donné du tableau de côté ?



	//d) Déterminer si deux machines sont connecté par un câble
	cout << "Est-ce que deux machines on un câble entre eux :" <<endl;
	cout << "Machine 1 et Machine 2 : " << connectionCable(Reseau, s, s2) << endl;

	cout << "Machine 1 et Machine 3 : " << connectionCable(Reseau, s, s3) << endl;

	cout << "Machine 1 et Machine 4 : " << connectionCable(Reseau, s, s4) << endl;

	cout << "Machine 2 et Machine 3 : " << connectionCable(Reseau, s2, s3) << endl;

	cout << "Machine 2 et Machine 4 : " << connectionCable(Reseau, s2, s4) << endl;

	cout << "Machine 3 et Machine 4 : " << connectionCable(Reseau, s3, s4) << endl << endl;

	//e) Quest-ce qu'un chemin dans le réseau ?
	 
	cout << "Un chemin dans un reseau est une suite de sommets. Ils se suivent en etant lie par un cable." << endl;
	cout << endl << endl;

	//f) Prendre en paramètre un tableau de numéros de noeuds du réseau et 
	//qui détermine si qhaque noeud du tableau est connecté au suivant par un câble
	int tabExF[5];
	//tabNoeudCont(Reseau, tabExF[5]);



	//24.2 graphe non-orienté : 
	//Donner une priorité de la matrice qui soit caractéristique d'un graphe non orienté
	//Donner un algorithme qui prend en paramètre un graphe donné sous forme de matrice d'adjacence,
	//et qui renvoie 1 si le graphe et non orienté, sinon 0.

	cout << "Est-ce non-oriente ? " << endl;
	cout << "Machine 1 et Machine 2 : " << graphNonOriente(Reseau, s, s2) << endl;
	cout << "Machine 1 et Machine 2 : " << graphNonOriente(Reseau, s2, s3) << endl;
	cout << "Machine 1 et Machine 2 : " << graphNonOriente(Reseau, s3, s4) << endl;

	//24.3
	//Prendre en paramètre un graphe G représenté sous forme de matrice d'adjacence et un coloriage,
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
		
		if (Reseau->tab_sommet[i].n_sommet == -1) // vérification si cellule vide
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




/* Un graphe est diférent d'un arbre. 
Dans le formalisme du graphe, on pourra avoir plusieurs sommet, mais aussi plusieurs route/chemin/cable entre les sommets.
Cees sommet vont être en relation par les cables.
On a des arc qui vont définir le sens des route entre sommets.
Dans la navigation ,c comme les arbres binaire, on va passer d'un successeur à un autre.
On définit un sens de passage de sommet.
Toujours vérifier le déplacement.
Plus le graphe est grand, plus la matrice est grande = ce qui est fortement déconseillé.
Utilisation de liste :
On va entré les sommet et les succésseurs.

Il vaut bien meux d'utiliser les liste (voir liste doublement chainée) que des tableaux !

Chauqe noeud est hiérarchique. 



*/