

#include <stdio.h>
#define TAILLE 6

void triParSelection(int n_tab[], int n_taille);

void triParInsertion(int n_tab[], int n_taille);

void triAbulles(int n_tab[], int n_taille);

int partitionnement(int n_tab[], int n_imin, int n_imax);
void TriRapid(int n_tab[], int n_imin, int n_imax);
void quickSort(int n_tab[], int n);

int main()
{
	int n_tab[TAILLE] = { 6,3,7,2,4,5 };

/**************************************************************************************************************/

//Tris
// 
// 
//Tri par sélection


	//triParSelection(n_tab, TAILLE);
	



//Tri par insertion

	//triParInsertion(n_tab,TAILLE);
	

//Tri par bulles

	triAbulles(n_tab, TAILLE);


//Tri rapide

	quickSort(n_tab, TAILLE);

  
    return 0;

}



void triParSelection(int n_tab[], int n_taille) {
	
	int n_k, n_l, n_imax, n_temp;

	n_l = n_taille;

	while (n_l>0) {
		n_imax = 0;
		for (n_k = 0; n_k<n_l; n_k++) {

			if (n_tab[n_imax]< n_tab[n_k]) {

				n_imax = n_k;
			}

		}

		n_temp = n_tab[n_l-1];
		n_tab[n_l-1] = n_tab[n_imax];
		n_tab[n_imax] = n_temp;

		n_l--;
	}

}

void triParInsertion(int n_tab[], int n_taille) {
	
	int n_k, n_temp;
	int n_i;
	for (n_k = 1; n_k < TAILLE; n_k++) {

		n_temp = n_tab[n_k];
		n_i = n_k - 1;
		while (n_i >= 0 && n_temp < n_tab[n_i]) {
			n_tab[n_i + 1] = n_tab[n_i];
			n_i--;
		}
		n_tab[n_i + 1] = n_temp;

	}
	

}


void triAbulles(int n_tab[], int n_taille) {

	int n_k, n_temp;
	

	// Test marquant l'arrêt du tri si le tableau est ordonné
	int n_desordre = 1;
	// Boucle de répétition du tri et le test qui
	// arrête le tri dès que le tableau est ordonné(en_desordre=false)
	while (n_desordre)
	{
		// Supposons le tableau ordonné
		n_desordre = 0;
		// Vérification des éléments des places j et j+1
		for (int n_j = 0; n_j < n_taille - 1; n_j++)
		{
			// Si les 2 éléments sont mal triés
			if (n_tab[n_j] > n_tab[n_j + 1])
			{
				// Inversion des 2 éléments
				n_temp = n_tab[n_j + 1];
				n_tab[n_j + 1] = n_tab[n_j];
				n_tab[n_j] = n_temp;

				// Le tableau n'est toujours pas trié
				n_desordre = 1;
			}
		}
	}



}


int partitionnement(int n_tab[], int n_imin, int n_imax) {

	int n_v;
	int n_i;
	int n_j;
	int n_temp;

	n_v = n_tab[n_imax];
	n_i = n_imin;
	n_j = n_imax - 1;

	while (n_i <= n_j) {
		while (n_i < n_imax && n_tab[n_i] <= n_v) {
			n_i=n_i+1;
		}
		while (n_j >= n_imin && n_tab[n_j] >= n_v) {
			n_j=n_j-1;
		}
		if (n_i < n_j) {

			n_temp= n_tab[n_i];
			n_tab[n_i] = n_tab[n_j];
			n_tab[n_j] = n_temp;
		}

	}
	n_tab[n_imax] = n_tab[n_i];
	n_tab[n_i] = n_v;

	return n_i;


}


void TriRapid(int n_tab[], int n_imin, int n_imax) {
	int n_i=0;

	if (n_imin < n_imax) {
		n_i = partitionnement(n_tab, n_imin, n_imax);

		TriRapid(n_tab, n_imin, n_i - 1);
		TriRapid(n_tab, n_i+1, n_imax);

	}

}

void quickSort(int n_tab[], int n) {
	TriRapid(n_tab, 0, n - 1);
}