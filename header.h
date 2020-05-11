#ifndef Header_H
# define Header_H
# include "header.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Enseignant{
	char nom[95];
    char prenom [95];
	char filiere[90];
	char email[90];
}_Enseignant;

typedef struct Compte{
    bool admin;
	char login[90];
    char mdp[20];
	char enseignant[90];
}_Compte;

typedef struct Surveillance{
    int id;
	char salle[4];
	char date[11];
	char duree[12];
    char enseignant[100];
	char module[70];
	char filiere[100];
} _Surveillance;
char *Nom_ens(_Compte *Surv, int n, char login[90],char mdp[90]);
//Retourne  le nom du professeur à partir de son login
int Verifier_admin(_Compte *Surv, int n, char login[90]);
//Vérifie si c'est un compte d'administrateur ou non
int countLines(FILE *file) ;
//Retourne le nombre de lignes dans un fichier text

int checkfile(FILE *file, int lines,int tab);
// Retourne 1 si le fichier est valide 0 sinon
int countLines(FILE *file) ;
// Retourne le nombre de lignes dans un fichier texte
_Surveillance *surv(int *N);
//Retourne un tableau de type « surveillance » à partir d’un fichier «  SURVEILLANCE.txt »
_Enseignant *ens(int *N);
//Retourne un tableau de type « enseignant » à partir du fichier « ENSEIGNANT.tx »

_Compte *cmp(int *N);
//Retourne un tableau de type « compte » à partir du fichier « COMPTE.txt »


void ft_admin(_Compte *Compte, _Surveillance *SURV, _Enseignant *Ens,char lg[90],char nom[90],int *N, int *C,int E);
//Cette fonction permet d’afficher le menu de l’administrateur , demande à l’utilisateur d’entrer l’option qu’il veut et execute la fonction qui correspond à chaque option.
int ft_surveillant(_Surveillance *SURV ,_Compte *Compte,_Enseignant *Ens ,char lg[90],char nom[90],int *N,int *C,int E);
//Cette fonction permet d’afficher le menu de l’enseignant , demande à l’utilisateur d’entrer l’option qu’il veut et execute la fonction qui correspond à chaque option.

void cp_modifier_mdp(_Compte *Surv, int n,char login[90]);
//Modifie le mot de passe
void cp_modifier_login(_Compte *Surv, int n,char login[90]);
//Modifie le login
void cp_modifier_email(_Compte *Surv,_Enseignant *ens, int n,int m,char login[90]);
//Modifie l’email
int Afficher_sur(_Surveillance *Surv, int n, char num[100]);
//Affiche les surveillances de l’enseignant
int Afficher_cp(_Compte *Surv,_Enseignant *ens,int n,int m,char login[90]) ;
//Affiche les informations du compte
int Enregister_ens(_Enseignant *Ens,int n);
// Enregistre les modifications des informations dans le fichier.
int Gestion_surv(_Surveillance *Surv,int *N);
// Affiche le menu de gestion des surveillances
int Enregister(_Surveillance *Surv,int n);
// Enregistre les modifications dans les surveillances dans le fichier
void Afficher(_Surveillance *Surv,int n);
//Affiche toutes les surveillances
void Supprimer(_Surveillance *Surv, int *n) ;
// Supprime une surveillance en entrant toutes ces informations
void Modifier(_Surveillance *Surv, int *n);
//Modifie une surveillance
void Inserer(_Surveillance *Surv, int *n);
//Insère une surveillance
int id_existe(_Surveillance *Surv, int n, int i) ;
int existe(_Surveillance *Surv, int n, char salle[3],char date[11],char duree[11],char enseignant[100]) ;
// Retourne 1 si le surveillant existe et 0 sinon

int Enregister_cmp(_Compte *Cmp,int n);
//Enregistre les modifications des informations des comptes dans le fichier
void    Gestion_cmp(_Compte *Cmp,_Enseignant *Ens,int *N,int E,char login[99]);
//Affiche le menu de la gestion des comptes des enseignants
void Supprimer_cmp(_Compte *Surv, int *n, char login[90]);
//Supprimer le compte qui correspond au login que l’admin a entré
int Modifier_cmp(_Compte *Surv, int n,char login[90]);
//Modifie le compte qui correspond au login que l’admin a entré
void Afficher_cmp(_Compte *Surv,_Enseignant *ens,int n,int m);
// Affiche le compte qui correspond au login que l’admin a entré


void Afficher_ens(_Enseignant *Surv,int n) ;
//Affiche la liste des enseignants avec leurs infos
void Creer_cmp(_Compte *Cmp,_Enseignant *Ens, int *n,int E);
//Crée un nouveau compte
int cmp_existe(_Compte *Cmp, int n,char login[95],char enseignant[100]);
//Retourne 0 si le compte existe déjà 1 sinon
int lg_existe(_Compte *Cmp, int n,char login[95]);
// retourne 0 si un compte avec ce login existe et 1 sinon
int ens_existe(_Enseignant *Ens,char enseignant[100],int n);
// retourne 0 si l’enseignant possède déjà un compte et 1 sinon
#endif

