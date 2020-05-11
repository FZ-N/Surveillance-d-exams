#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define t 95


FILE* fich;


typedef struct Enseignant{
	char nom[95];
    	char prenom [95];
	char CIN [9];
	struct Surveillance* surveillance;
}_Enseignant;

typedef struct Surveillance{
	char salle[3];
	char date[11];
	char duree[11];
	char module[7];
	char filiere[100];
  	char enseignant[100];
}Surveillance;

Surveillance* fillstruct(FILE* fich, Surveillance* tab)
{
    char s1[t],s2[t],s3[t],s4[t],s5[t],s6[t],s7[t];
    int pos=0, i=0;
    Surveillance Surveil;
    pos=fseek(fich,0,SEEK_SET);
    while(fgets(s6,100,fich)!=NULL && pos!=SEEK_END)
      {
            fseek(fich,0,pos);
            fscanf(fich, "%s\t%s\t%s\t%s\t%s\t%s",s1,s2,s3,s4,s5,s6,s7);
            pos=ftell(fich);
            strcpy(Surveil.salle,s1);
            printf("\n%s\t",Surveil.salle);
            strcpy(Surveil.date,s2);
            printf("%s\t",Surveil.date);
            printf("\t%s",s6);
            strcpy(Surveil.duree,s3);
            strcpy(Surveil.module,s4);
            strcpy(Surveil.filiere,s5);
            strcpy(Surveil.enseignant,s6);

            tab[i]=Surveil;
            i++;
      }


    return(tab);

}

FILE* fillfile(FILE* fich, Surveillance Surveil)
{
    fseek(fich,0,SEEK_END);
    fprintf(fich,"\n%s\t%s\t%s\t%s\t%s\t%s",Surveil.salle,Surveil.date,Surveil.duree,Surveil.module,Surveil.filiere,Surveil.enseignant);
    return (fich);
}
/*
int main(int argc, char** argv)
{
    Surveillance *tab;
    int i=0;

    fich=fopen("Surveillance1.txt","r+");
    tab=(Surveillance*)malloc(300*sizeof(Surveillance));

    if(tab!=NULL)
      {
        tab=fillstruct(fich,tab);
        fich=fillfile(fich,tab[0]);
        fclose(fich);
      }


    else
    {
        printf("ERREUR");
        exit (EXIT_FAILURE);
    }

    return 0;
}*/
