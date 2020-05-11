# include "header.h"
int ft_surveillant(_Surveillance *SURV ,_Compte *Compte,_Enseignant *Ens ,char lg[90],char nom[90],int *N,int *C,int E)
{
int option;
  do {
    puts("\n \n ===== MENU DU SURVEILLANT =====\n");
    puts("\t1. Afficher les surveillances");
    puts("\t2. Afficher les informations du compte");
    puts("\t3. Changer le mot de passe");
    puts("\t4. Changer l'email");
    puts("\t5. Quitter\n");
    printf("Choisir une option (1->5) ");
    scanf("%d", &option);

    switch (option) {
        case 1:
        if (Afficher_sur(SURV ,*N,nom) == 0)
            printf("Pas de surveillance prevue\n");
        break;
      case 2:
          Afficher_cp(Compte,Ens ,*C, E,lg);

        break;
         case 3:
         cp_modifier_mdp(Compte, *C, lg);
          Enregister_cmp(Compte,*C);
        break;
         case 4:
         cp_modifier_email(Compte,Ens , *C,E, lg);
         Enregister_ens(Ens ,E);
        break;

    }
    if (option != 5)
    {
        getchar();
    printf("Tapez entrer pour continuer ...\t");
    getchar();
   system("cls");
    }

  } while (option != 5);

    return 0;
}

void ft_admin(_Compte *Compte, _Surveillance *SURV , _Enseignant *Ens ,char lg[90],char nom[90],int *N, int *C,int E)
{

int option;
  do {
    puts("\n \n ===== MENU ADMINISTRATEUR =====\n");
    puts("\t1. Gerer la base de donnees des comptes des enseignants");
    puts("\t2. Gerer la base de donnees des surveillances des examens");
    puts("\t3. Quitter\n");
    printf("Choisir une option (1->3) ");
    scanf("%d", &option);

    switch (option) {
        case 1:
           system("cls");
            Gestion_cmp(Compte,Ens , C, E,lg);
        break;
         case 2:
              system("cls");
            Gestion_surv(SURV ,N);
        break;
         case 3:
            exit(0);
    }
    system("cls");
  } while (option != 3);
  exit(0);
}

