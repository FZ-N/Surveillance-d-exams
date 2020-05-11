# include "header.h"


int Enregister_cmp(_Compte *Cmp,int n)
{
	FILE* fich=fopen("COMPTE.txt","w+");
	if (fich!=NULL)
	{
            int i;
          _Compte *p = Cmp;
    for(i = 0; i<n;i++) {
            if (p->admin ==0)
        fprintf(fich,"0\t%s\t%s\t%s\n",p->login, p->mdp, p->enseignant);
            else
        fprintf(fich,"1\t%s\t%s\t%s\n",p->login, p->mdp, p->enseignant);
        p++;
        }
		fclose(fich);
	}
	else
		printf("\nErreur d'ouverture du fichier!\n");
    return 0;
}

int ens_existe(_Enseignant *Ens,char enseignant[100],int n) {
    _Enseignant *p= Ens;
  for ( ; p - Ens < n ; p++) {
    if (strcmp(p->nom,enseignant)==0)
        return 0;
    }
    printf("Le nom du surveillant ne figure pas dans la liste des enseignants\n");
    return 1;
}

int lg_existe(_Compte *Cmp, int n,char login[95]) {
    _Compte *p= Cmp;
  for ( ; p - Cmp < n ; p++) {
    if (strcmp(p->login,login)==0)
        {
        return 1;
        }
    }
     printf("Ce login n'existe pas \n");
    return 0;
}

int cmp_existe(_Compte *Cmp, int n,char login[95],char enseignant[100]) {
    _Compte *p= Cmp;
  for ( ; p - Cmp < n ; p++) {
    if (strcmp(p->login,login)==0 || strcmp(p->enseignant,enseignant)==0)
    {
        printf("Le compte existe déja");
        return 1;
    }
  }

    return 0;
}


 void Creer_cmp(_Compte *Cmp,_Enseignant *Ens, int *n,int E){
     _Compte *ptr = Cmp;
     _Compte p;
     int k;
     char adm[20];
     k = *n;
     printf("Donner le type de ce compte (admin ou utilisateur) \n");
     scanf("%s", adm);
       if    (strcmp(adm,"admin") == 0)
           p.admin = 1;
           else
            p.admin = 0;

    printf("Entrer les informations du nouveau compte \n");
    scanf("%s %s %[^\t\n]s", &p.login, &p.mdp, &p.enseignant);
    if(cmp_existe(Cmp,*n,p.login,p.enseignant)==0 && ens_existe(Ens,p.enseignant,E)==0)
        {
    (*n)++;
    Cmp = (_Compte *) realloc(Cmp,(*n+1) * sizeof(_Compte));
     *(ptr+k) = p;
     printf("Compte cree avec succes !! \n");
      }

    }


    void Afficher_ens(_Enseignant *Surv,int n) {
    int i;
    _Enseignant *p = Surv;

    for(i = 0; i<n;i++) {

    printf("Nom: %s  Prenom: %s   Filiere : %s   Email: %s\n \n",p->nom, p->prenom,p->filiere, p->email);
    p++;
  }
}


void Afficher_cmp(_Compte *Surv,_Enseignant *ens,int n,int m) {
    int i;
    _Compte *p = Surv;

    for(i = 0; i<n;i++) {

    for (_Enseignant *ptr = ens; ptr - ens < m ; ptr++) {
    if (strcmp(ptr->nom,p->enseignant)==0) {
    printf("login : %s \nMot de passe : %s\nNom: %s \nPrenom: %s\nFiliere : %s\nEmail: %s\n \n",p->login, p->mdp, p->enseignant, ptr->prenom,ptr->filiere, ptr->email);
    printf("///////////////////////////////////////////////////////////\n");
    }

  }
   p++;
}
}


int Modifier_cmp(_Compte *Surv, int n,char login[90]){
    for (_Compte *p = Surv; p - Surv < n ; p++) {
    if (strcmp(p->login,login)==0)
        {
             printf("Entrez le nouveau mot de passe");
             scanf("%s",&p->mdp);
              printf("Mot de passe modifie ! !! \n");
              return 0;
        }

    }
 printf("ERREUR !! \n");
    }

void Supprimer_cmp(_Compte *Surv, int *n, char login[90]) {
     _Compte *ptr = Surv;
        for (_Compte *ptr = Surv; ptr - Surv < *n; ptr++){
            if (strcmp(login,ptr->login)==0) {
                    for (_Compte *ptr1 = ptr; ptr1 - Surv + 1 < *n; ptr1++) {
                            *ptr1 = *(ptr1 + 1);

    }
    (*n)--;
    printf("Compte supprime avec succes !! \n");
  }
}

}

void    Gestion_cmp(_Compte *Cmp,_Enseignant *Ens,int *N,int E,char login[99])
{
    char info[100];
    int option;

  do {
    puts("\n \n ===== MENU DE LA GESTION DES COMPTES =====\n");
    puts("\t1. Creer un nouveau compte");
    puts("\t2. Afficher tous les comptes");
    puts("\t3. Supprimer un compte");
    puts("\t4. Modifier le mot de passe d'un compte");
    puts("\t5. Chercher un compte");
    puts("\t6. Afficher la liste des enseignants ");
    puts("\t7. Revenir au menu principal \n");
    printf("Choisir une option (1->7) ");
    scanf("%d", &option);

    switch (option) {
        case 1:
        Creer_cmp(Cmp,Ens,N,E);
        Enregister_cmp(Cmp,*N);
        break;
      case 2:
        Afficher_cmp(Cmp,Ens,*N,E);
        break;
      case 3:
        printf("Entrer le login du compte a supprimer   ");
        scanf("%s",info);
        if (lg_existe(Cmp,*N,info) == 1)
        {
        if (strcmp(info,login) != 0) // Un admin ne peut pas supprimer son propre compte
        Supprimer_cmp(Cmp,N,info);
        else
            printf("Un admin ne peut pas supprimer son propre compte\n");
        Enregister_cmp(Cmp,*N);

        }
        break;
         case 4:
        printf("Entrer le login ");
        scanf("%s",info);
        if (lg_existe(Cmp,*N,info) == 1)
        {
        Modifier_cmp(Cmp,N,info);
        Enregister_cmp(Cmp,*N);
        }
        break;
        case 5:
        printf("Entrer le login ");
        scanf("%s",info);
      if (lg_existe(Cmp,*N,info) == 1)
        {
         Afficher_cp(Cmp,Ens,*N,E,info);
         Enregister_cmp(Cmp,*N);
        }

        break;
        case 6:
            Afficher_ens(Ens,E);
        break;

    }
       if  (option != 7)
    {
    getchar();
    printf("Tapez entrer pour continuer ...\t");
    getchar();
    system("cls");
    }
   } while (option != 7);
   printf("\n");
}
