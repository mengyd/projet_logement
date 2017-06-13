#ifndef LOGEMENT_H_INCLUDED
#define LOGEMENT_H_INCLUDED

//utilisateurs ne peut choisir que les deux type de logement au dessous
typedef enum Type{
    Appartement = 1,
    Maison = 2
}Type;

typedef struct Annonce{
    int idAnnonce;
    Type type;
    int nbPieces;
    float surface;
    float loyer;
    float charge;
    struct Annonce *next;
}Annonce;

typedef Annonce* liste;

void afficheAnnonce(liste a);

liste saisie(liste lt);

int countListe(liste ltTotal);

liste ajoutAnnonce(liste ltTotal);

void afficheListe(liste ltTotal);

void chercheType(liste ltTotal);

void chercheNbPieces(liste ltTotal);

void chercheSurface(liste ltTotal);

void chercheNbLoyer(liste ltTotal);

void chercheBudget(liste ltTotal);

float cherchePrix(int id, liste ltTotal);

void afficheParId(int id, liste ltTotal);

void sauvegarder(liste ltTotal);

liste chargeFichier(char *filename);

liste ajoutDepuisFichier(liste ltTotal, int id, char *type, int nbPieces, float surface, float loyer, float charge);

#endif // LOGEMENT_H_INCLUDED
