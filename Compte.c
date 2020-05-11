
# include "header.h"

int Enregister_ens(_Enseignant *Ens,int n){
	FILE* fich=fopen("ENSEIGNANT.txt","w+");
	if (fich!=NULL)
	{
            int i;
          _Enseignant *p = Ens;
    for(i = 0; i<n;i++) {

        fprintf(fich,"%s\t%s\t%s\t%s\n",p->nom, p->prenom, p->filiere, p->email);

    p++;
  }
		fclose(fich);
	}
	else
		printf("\nErreur d'ouverture du fichier!\n");
    return 0;
}

int Afficher_cp(_Compte *Surv,_Enseignant *ens,int n,int m,char login[90]) {
    int i;
    _Compte *p = Surv;
    for(i = 0; i<n;i++) {
     if(strcmp(p->login,login) == 0)
        {
             if (p->admin == 1)
                printf("ADMIN \n");
    for (_Enseignant *ptr = ens; ptr - ens < m ; ptr++) {
    if (strcmp(ptr->nom,p->enseignant)==0) {
printf("login : %s \nMot de passe : %s\nNom: %s \nPrenom: %s\nFiliere : %s\nEmail: %s\n \n",p->login, p->mdp, p->enseignant, ptr->prenom,ptr->filiere, ptr->email);
            }
        }
    }
    p++;
  }
}

int Afficher_sur(_Surveillance *Surv, int n, char num[100]) {
  int trouve = 0;
  for (_Surveillance *p = Surv; p - Surv < n ; p++) {
    if (strcmp(p->enseignant,num)==0)
    {
       printf("%s %s %s %s %s \n",p->salle, p->date, p->duree,p->module, p->filiere);
       trouve = 1;
        }
    }
  return trouve ? 1 : 0;
}


void cp_modifier_email(_Compte *Surv,_Enseignant *ens, int n,int m,char login[90]){
    for (_Compte *p = Surv; p - Surv < n ; p++) {
    if (strcmp(p->login,login)==0)
        {
            for (_Enseignant *ptr = ens; ptr - ens < m ; ptr++) {
    if (strcmp(ptr->nom,p->enseignant)==0) {
             printf("Entrez la nouvelle adresse mail");
             scanf("%s",&ptr->email);
                 printf("Adresse email modifiee ! \n");
            }
        }
     }
    }
}

void cp_modifier_login(_Compte *Surv, int n,char login[90]){
    for (_Compte *p = Surv; p - Surv < n ; p++) {
    if (strcmp(p->login,login)==0)
        {
             printf("Entrez le nouveau login");
             scanf("%s",&p->login);
                 printf("Login modifie ! \n");
        }
    }
}

void cp_modifier_mdp(_Compte *Surv, int n,char login[90]){
    for (_Compte *p = Surv; p - Surv < n ; p++) {
    if (strcmp(p->login,login)==0)
        {
             printf("Entrez le nouveau mot de passe");
             scanf("%s",&p->mdp);
                 printf("Mot de passe modifie ! \n");
        }
    }
}
