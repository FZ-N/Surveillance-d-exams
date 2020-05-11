
# include "header.h"

int Enregister(_Surveillance *Surv,int n)
{
	FILE* fich=fopen("SURVEILLANCE.txt","w+");
	if (fich!=NULL)
	{
            int i;
          _Surveillance *p = Surv;
    for(i = 0; i<n;i++) {
        p->id = i+1;
    fprintf(fich,"%d %s\t%s\t%s\t%s\t%s\t%s\n",p->id,p->salle, p->date, p->duree, p->enseignant,p->module, p->filiere);
    p++;
   }
		fclose(fich);
	}
	else
		printf("\nErreur d'ouverture du fichier!\n");
    return 0;
}

int id_existe(_Surveillance *Surv, int n, int i) {
    _Surveillance *p= Surv;
  for ( ; p - Surv < n ; p++) {
    if (p->id==i) {
        return 1;
    }
  }
    return 0;
}

void Afficher(_Surveillance *Surv,int n) {
    int i;
    _Surveillance *p = Surv;
    for(i = 0; i<n;i++) {
    printf(" %d  %s\t%s\t%s\t%s\t%s\t%s\n",p->id,p->salle, p->date, p->duree, p->enseignant,p->module, p->filiere);
    p++;
  }
}

void Chercher_salle(_Surveillance *Surv, int n, char num[100]) {
  int trouve = 0;
  for (_Surveillance *p = Surv; p - Surv < n ; p++) {
    if (strcmp(p->salle,num)==0) {
       printf("%s %s %s %s %s %s\n",p->salle, p->date, p->duree, p->enseignant,p->module, p->filiere);
       trouve =1;
    }
  }
  if (trouve == 0)
    printf("Cette salle ne correspond a aucune surveillance ! \n");

}

int Chercher_ens(_Surveillance *Surv, int n, char num[100]) {
  int trouve = 0;
  for (_Surveillance *p = Surv; p - Surv < n ; p++) {
    if (strcmp(p->enseignant,num)==0) {
       printf("%s %s %s %s %s %s\n",p->salle, p->date, p->duree, p->enseignant,p->module, p->filiere);
       trouve =1;
    }
  }
   if (trouve == 0)
    printf("Cet enseignant n'a aucune surveillance pour le moment ! \n");

}

int existe(_Surveillance *Surv, int n, char salle[3],char date[11],char duree[11],char enseignant[100]) {
    _Surveillance *p= Surv;
  for ( ; p - Surv < n ; p++) {
    if (strcmp(p->salle,salle)==0) {
       if((strcmp(p->duree,duree)==0) && strcmp(p->date,date)==0)
        return 1;
    }
    else if (strcmp(p->enseignant,enseignant)==0) {
       if((strcmp(p->duree,duree)==0) && strcmp(p->date,date)==0)
        return 1;
    }
  }
    return 0;
}


 void Inserer(_Surveillance *Surv, int *n){
     _Surveillance *ptr = Surv;
     _Surveillance p;
     int k;
     k = *n;
    printf("Entrer les informations de la nouvelle surveillance \n");
    scanf("%s %s %s %s %s %s",&p.salle, &p.date, &p.duree, &p.enseignant,&p.module, &p.filiere);

    if(existe(Surv,k,p.salle, p.date, p.duree, p.enseignant)==0)
        {
    (*n)++;
    Surv = (_Surveillance *) realloc(Surv,(*n) * sizeof(_Surveillance));
     *(ptr+k) = p;
         printf("Surveillance ajoutee ! \n");
    }
    else
    printf("Les données sont invalides, salle ou surveillant non disponible");

}


    void Modifier(_Surveillance *Surv, int *n){
     _Surveillance *ptr = Surv;
     _Surveillance p;
     int k;
     k = *n;
      printf("Donner le numéro de la surveillance à modifier  \n");
    scanf("%d", &p.id);
    if(id_existe(Surv,k,p.id)==1)
        { for (_Surveillance *ptr = Surv; ptr - Surv < *n ; ptr++) {
    if (ptr->id == p.id)
        {
            printf("Entrez les nouvelles valeurs");
             scanf("%s %s %s %s %s %s",
                &ptr->salle, &ptr->date, &ptr->duree, &ptr->enseignant, &ptr->module, &ptr->filiere);
                    printf("Surveillance modifee ! \n");
        }
    }
    }
    else
    printf("Cette surveillance est introuvable");

    }


void Supprimer(_Surveillance *Surv, int *n) {
     _Surveillance *ptr = Surv;
     _Surveillance p;
     int k;
     k = *n;
      printf("Entrer le numéro de la surveillance à supprimer \n");
      scanf("%d",&p.id);

    if(id_existe(Surv,k, p.id)==1){
        for (_Surveillance *ptr = Surv; ptr - Surv < *n; ptr++){
            if (p.id==ptr->id)
                {
                    for (_Surveillance *ptr1 = ptr; ptr1 - Surv + 1 < *n; ptr1++) {
                    *ptr1 = *(ptr1 + 1);
                    }
                (*n)--;
                printf("Surveillance supprimee ! \n");
                }
            }
        }
    }



int Gestion_surv(_Surveillance *Surv,int *N)
{
    char info[100];
    int option;

  do {
    puts("\n \n ===== MENU DE GESTION DES SURVEILLANCES DES EXAMENS=====\n");
    puts("\t1. Afficher toutes les surveillances");
    puts("\t2. Chercher une surveillance par salle");
    puts("\t3. Chercher une surveillance par enseignant");
    puts("\t4. Modifier une surveillance");
    puts("\t5. Supprimer une surveillance");
    puts("\t6. Inserer une nouvelle surveillance");
    puts("\t7. Revenir au menu principal ");
    puts("\t8. Quitter le programme \n");
    printf("Choisir une option (1->8)\t");
    scanf("%d", &option);

    switch (option) {
      case 1:
        Afficher(Surv, *N);
        break;
      case 2:
        printf("Entrer le num de la salle\t");
        scanf("%s", &info);
        Chercher_salle(Surv,*N, info);
        break;
         case 3:
        printf("Entrer le nom de l'enseignant\t");
        scanf("%[^\n]s", &info);
        Chercher_ens(Surv,*N, info);
        break;
        case 4:
        Modifier(Surv, N);
        Enregister(Surv,*N);
        break;
      case 5:
        Supprimer(Surv, N);
        Enregister(Surv,*N);
        break;
      case 6:
        Inserer(Surv, N);
        Enregister(Surv,*N);
        break;
    case 8:
       exit(0);
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
    return 0;
}
