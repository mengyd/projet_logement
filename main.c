#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "logement.h"

int main(int argc, char *argv[])
{
    int op = -1;
    liste ltTotal = NULL;

    ltTotal = chargeFichier(argv[1]);
    afficheListe(ltTotal);


    do{
        printf("\n++++++++++++++++++++++++\n");
        printf("\nChoisir votre opération :\n0.Quitter;\n1.Ajout;\n2.Cherche par type;\n3.Cherche par nombre de pièces;\n4.Cherche par surface;"
               "\n5.Cherche par nombre de pièces et loyer;\n6.Cherche par budget\n7.Sauvegarder\n8.Afficher la liste\n");
        scanf("%d", &op);

        switch(op){
            case 1 : ltTotal = ajoutAnnonce(ltTotal);
                break;
            case 2 : chercheType(ltTotal);
                break;
            case 3 : chercheNbPieces(ltTotal);
                break;
            case 4 : chercheSurface(ltTotal);
                break;
            case 5 : chercheNbLoyer(ltTotal);
                break;
            case 6 : chercheBudget(ltTotal);
                break;
            case 7 : sauvegarder(ltTotal);
                break;
            case 8 : afficheListe(ltTotal);
                break;
            default : break;
        }

    }while(op!=0);


    return 0;
}
