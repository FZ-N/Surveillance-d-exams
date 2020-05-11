# include "header.h"

char *Nom_ens(_Compte *Surv, int n, char login[90],char mdp[90]) {
  for ( _Compte *p= Surv; p - Surv < n ; p++) {
    if (strcmp(p->login,login)==0) {
       if(strcmp(p->mdp,mdp)==0)
            return (p->enseignant);
        else
            {
            printf("Mot de passe invalide !! \n");
            return NULL;
            }
        }
  }
  printf("Login introuvable !! \n");
        return NULL;
}

int Verifier_admin(_Compte *Surv, int n, char login[90]) {
  for ( _Compte *p= Surv; p - Surv < n ; p++) {
    if (strcmp(p->login,login)==0) {
       if(p->admin == 1)
        return 1;
    }
  }
        return 0;
}


int main(int argc, char *argv[])
{

    char *lg[90]; //login
    char *mdp[90]; // mot de passe
    int n,E,C; // le nombre de surveillance , enseignants et comptes

//Création
     _Compte *Comptes = cmp(&C);
     _Enseignant *Ens = ens(&E);
     _Surveillance *Surv=surv(&n);
     char *nom = NULL;
//Demander à l'utilisateur d'entrer son login et mot de passe
         while ( nom == NULL)
     {
         printf("login :  ");
         scanf("%s",&lg);
         printf("Mot de passe : ");
         scanf("%s",&mdp);
         nom = Nom_ens(Comptes,n,lg,mdp); // mémoriser le nom du professeur dans cette variable à partir de son login
     }
     system("cls");
     //On sort de la boucle une fois que le mot de passe correspond au login

    //Vérifier si c'est un compte d'administrateur ou non pour lui donner les autorisations necessaires
    int admin;
    admin = Verifier_admin(Comptes,C,lg);
    if (admin == 1)
    {
          printf("\n Bienvenue  \n"); //message de bienvenue
           ft_admin(Comptes,Surv,Ens,lg,nom,&n,&C,E);
    }

    else

    {
         printf("\n Bienvenue professeur  %s \n",nom); //message de bienvenue
          ft_surveillant(Surv,Comptes,Ens,lg,nom,&n,&C,E);
    }


    free(Surv);
    free(Ens);
    free(Comptes);

    return 0;
}
