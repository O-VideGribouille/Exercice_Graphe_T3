#pragma once
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <cassert>


using namespace std;

typedef struct s_sommet {

	int n_sommet;
	int n_id;

};

typedef struct s_reseau {

	s_sommet* tab_sommet; //tableau 1 dimension

	char** tab_matrice; //valeur de 0 à 1, tableau à 2 dimensions

	int n; //noeud réseau
	int m; // cable qui relie deux noeuds


}s_reseau;

