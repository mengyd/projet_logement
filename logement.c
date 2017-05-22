#include <stdio.h> //Jojo
#include <stdlib.h>
#include <string.h>
#include "logement.h"


void afficheAnnonce(liste a){
    printf("\n-----------------\n");
    printf("\nidAnnonce : %d", a->idAnnonce);
    if(a->type == Appartement){
        printf("\nType : Appartement");
    }else if(a->type == Maison){
        printf("\nType : Maison");
    }
    printf("\nnbPièces : %d\nSurface : %.2f\nLoyer : %.2f\nCharge : %.2f", a->nbPieces, a->surface, a->loyer, a->charge);
    printf("\n=================\n");
}


liste saisie(liste lt){
    Annonce *a=NULL;
    int typ;

    a = malloc(sizeof(*a));

    a->idAnnonce = countListe(lt)+1;
    do{
        printf("\nChoisir type d'annonce (1 pour appartement, 2 pour maison): ");
        scanf("%d", &typ);
    }while(typ!=1 && typ!=2);
    if(typ == 1){
        a->type = Appartement;
    }else{
        a->type = Maison;
    }

    printf("\nSaisir nombre de pièces : ");
    scanf("%d", &a->nbPieces);

    printf("\nSaisir surface : ");
    scanf("%f", &a->surface);

    printf("\nSaisir loyer : ");
    scanf("%f", &a->loyer);

    printf("\nSaisir charge : ");
    scanf("%f", &a->charge);

    afficheAnnonce(a);
    return a;
}


int countListe(liste ltTotal){
    liste lt2;
    int cpt=0;

    lt2 = ltTotal;

    while(lt2 != NULL){
        lt2 = lt2->next;
        cpt++;
    }

    return cpt;
}


liste ajoutAnnonce(liste ltTotal){
    liste lt2;
    Annonce *a = NULL;

    a = malloc(sizeof(*a));
    a = saisie(ltTotal);

    lt2 = ltTotal;

    if(lt2 == NULL){
        lt2 = a;
        lt2->next = NULL;
        ltTotal = lt2;
    }else{
        while(lt2 != NULL){
            if(lt2->next == NULL){
                a->next = NULL;
                lt2->next = a;
                lt2 = a->next;
            }else{
                lt2 = lt2->next;
            }
        }
    }

    return ltTotal;
}


void afficheListe(liste ltTotal){
    liste lt2;

    lt2 = ltTotal;

    printf("\n**********************\n");
    if(lt2 == NULL){
        printf("\nListe vide !");
    }
    while(lt2 != NULL){
        afficheAnnonce(lt2);
        lt2 = lt2->next;
    }
}


void chercheType(liste ltTotal){
    liste lt2=NULL;
    int typ,cpt=0;

    lt2 = ltTotal;

    do{
        printf("\nChoisir un type(1 pour Appartement, 2 pour Maison): ");
        scanf("%d", &typ);
    }while(typ!=1 && typ!=2);

    while(lt2 != NULL){
        if(typ == lt2->type){
            afficheAnnonce(lt2);
            cpt++;
        }
        lt2 = lt2->next;
    }
    printf("\nNombre d'annonces : %d", cpt);
}


void chercheNbPieces(liste ltTotal){
    liste lt2=NULL;
    int nbPiece,cpt=0;

    lt2 = ltTotal;

    do{
        printf("\nSaisir nombre de pièces(plus grand que 0): ");
        scanf("%d", &nbPiece);
    }while(nbPiece<1);

    while(lt2 != NULL){
        if(nbPiece == lt2->nbPieces){
            afficheAnnonce(lt2);
            cpt++;
        }
        lt2 = lt2->next;
    }
    printf("\nNombre d'annonces : %d", cpt);
}


void chercheSurface(liste ltTotal){
    liste lt2=NULL;
    int cpt=0;
    float surface;

    lt2 = ltTotal;

    do{
        printf("\nSaisir surface(plus grand que 0): ");
        scanf("%f", &surface);
    }while(surface<1);

    while(lt2 != NULL){
        if(surface <= lt2->surface){
            afficheAnnonce(lt2);
            cpt++;
        }
        lt2 = lt2->next;
    }
    printf("\nNombre d'annonces : %d", cpt);
}


void chercheNbLoyer(liste ltTotal){
    liste lt2=NULL;
    int nbPiece, cpt=0;
    float loyer;

    lt2 = ltTotal;

    do{
        printf("\nSaisir nombre de pièces(plus grand que 0): ");
        scanf("%d", &nbPiece);
    }while(nbPiece<1);

    do{
        printf("\nSaisir loyer(plus grand que 0): ");
        scanf("%f", &loyer);
    }while(loyer<1);

    while(lt2 != NULL){
        if(nbPiece <= lt2->nbPieces && loyer >= lt2->loyer){
            afficheAnnonce(lt2);
            cpt++;
        }
        lt2 = lt2->next;
    }
    printf("\nNombre d'annonces : %d", cpt);
}


float cherchePrix(int id, liste ltTotal){
    liste lt2=NULL;
    float prix;

    lt2 = ltTotal;

    while(lt2 != NULL){
        if(id == lt2->idAnnonce){
            prix = lt2->charge + lt2->loyer;
            return prix;
        }
        lt2 = lt2->next;
    }
    return 0;
}


void afficheParId(int id, liste ltTotal){
    liste lt2=NULL;

    lt2 = ltTotal;

    while(lt2 != NULL){
        if(id == lt2->idAnnonce){
            afficheAnnonce(lt2);
        }
        lt2 = lt2->next;
    }
}


void chercheBudget(liste ltTotal){
    liste lt2=NULL;
    float budget, prix1, prix2;
    int longeur, i, j, tmp, cpt=0;
    int *tab=NULL;

    lt2 = ltTotal;

    longeur = countListe(lt2);

    tab = malloc(longeur*sizeof(int));

    for(i=0; i<longeur; i++){
        tab[i] = lt2->idAnnonce;
        lt2 = lt2->next;
    }

    for(i=0; i<longeur-1; i++){
        for(j=i+1; j<longeur; j++){
            prix1 = cherchePrix(tab[i], ltTotal);
            prix2 = cherchePrix(tab[j], ltTotal);
            if(prix1>prix2){
                tmp = tab[i];
                tab[i] = tab[j];
                tab[j] = tmp;
            }
        }
    }

    for(i=0; i<longeur; i++){
        //printf("\n%d", tab[i]);
        printf("\n----------------\n");
        afficheParId(tab[i], ltTotal);
    }

    printf("\nSaisir votre budget : ");
    scanf("%f", &budget);

    for(i=0; i<longeur; i++){
        if(budget == cherchePrix(tab[i], ltTotal)){
            afficheParId(tab[i], ltTotal);
            cpt++;
        }
    }

    if(cpt==0){
        printf("\nIl n'y a pas d'annonce correspondante !");
    }else{
        printf("\nIl y a %d annonce correspondante !", cpt);
    }

    free(tab);
}


void sauvegarder(liste ltTotal){
    FILE *fichier;
    char type[15];
    char emplacement[255];
    liste lt2=NULL;

    lt2 = ltTotal;

    printf("\nSaisir l'emplacement et nom de fichier pour sauvegarder : ");
    scanf("%s", emplacement);

    fichier = fopen(emplacement, "w");
    //fichier = fopen("C:\\ESGI_test\\test_projet.txt","w");

    if(fichier == NULL){
        exit(EXIT_FAILURE);
    }

    while(lt2 != NULL){
        if(lt2->type == Appartement){
            strcpy(type, "Appartement");
        }else{
            strcpy(type, "Maison");
        }

        fprintf(fichier, "%d %s %d %.2f %.2f %.2f\n", lt2->idAnnonce, type, lt2->nbPieces, lt2->surface, lt2->loyer, lt2->charge);

        lt2 = lt2->next;
    }
    fclose(fichier);

}


liste ajoutDepuisFichier(liste ltTotal, int id, char *type, int nbPieces, float surface, float loyer, float charge){
    Annonce *a=NULL;
    liste lt2=NULL;

    a = malloc(sizeof(*a));

    a->idAnnonce = id;

    if(strcmpi("Appartement", type)==0){
        a->type = Appartement;
    }else if(strcmpi("Maison", type)==0){
        a->type = Maison;
    }

    a->nbPieces = nbPieces;

    a->surface = surface;

    a->loyer = loyer;

    a->charge = charge;


    lt2 = ltTotal;

    if(lt2 == NULL){
        lt2 = a;
        lt2->next = NULL;
        ltTotal = lt2;
    }else{
        while(lt2 != NULL){
            if(lt2->next == NULL){
                a->next = NULL;
                lt2->next = a;
                lt2 = a->next;
            }else{
                lt2 = lt2->next;
            }
        }
    }

    return ltTotal;


}


liste chargeFichier(char *filename){
    liste ltTotal=NULL;
    FILE *fichier;
    char type[15];
    int id, nbPieces;
    float surface, loyer, charge;

    fichier = fopen(filename, "r");
    if(fichier == NULL){
        exit(EXIT_FAILURE);
    }

    while(fscanf(fichier, "%d %s %d %f %f %f", &id, type, &nbPieces, &surface, &loyer, &charge) != EOF){
        printf("%d %s %d %.2f %.2f %.2f\n", id, type, nbPieces, surface, loyer, charge);
        ltTotal = ajoutDepuisFichier(ltTotal, id, type, nbPieces, surface, loyer, charge);
    }

    fclose(fichier);
    return ltTotal;
}


