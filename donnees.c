# include "header.h"

int checkfile(FILE *file,int lines,int tab){
      int tabs=0;
      char c;
  while (EOF != (c = fgetc(file))) {
    if (c == '\t') {
      tabs++;
    }
  }
  rewind(file);
  if (tabs == tab*(lines))
   return 1;
else
     printf("Attention !! tous les elements doivent etre separés par une tabulation \n");
    while (EOF != (c = fgetc(file))) {
    if (c == '\n') {
      ++tabs;
      if (tabs == lines-1)
      {
          if (strcmp(c,'\n') == 0)
            return 1;
          else
            printf("Attention !! un retour à la ligne est obligatoire après chaque ligne \n");
      }
    }
  }

 return 0;
}


int countLines(FILE *file) {
  int lines = 0;
  int c;
  while (EOF != (c = fgetc(file))) {
    if (c == '\n') {
      ++lines;
    }
  }
  rewind(file);
  return lines;
}


_Surveillance *surv(int *N)
{
    char salle[4];
	char date[11];
	char duree[12];
    char enseignant[100];
	char module[70];
	char filiere[100];
    char ch[10000], file_name[250];
    int i = 1;
    FILE *fp;

   strcpy(file_name,"SURVEILLANCE.txt");
   fp = fopen(file_name, "r"); // read mode
    *N = countLines(fp);
   if (fp == NULL || checkfile(fp,*N,5) == 0)
   {
      perror("Fichier invalide ''SURVEILLANCE.txt''.\n");
      exit(0);
   }
   _Surveillance *Surv = (_Surveillance *) malloc((*N+1) * sizeof(_Surveillance));
   _Surveillance *p = Surv;

    while (fgets(ch,10000,fp) != NULL)
    {
	char delim[] = "\t\n";
	p->id = i;
	char *ptr = strtok(ch, delim);
    strcpy(p->salle,ptr);
    ptr = strtok(NULL, delim);
    strcpy(p->date,ptr);
    ptr = strtok(NULL, delim);
    strcpy(p->duree,ptr);
    ptr = strtok(NULL, delim);
    strcpy(p->enseignant,ptr);
    ptr = strtok(NULL, delim);
    strcpy(p->module,ptr);
    ptr = strtok(NULL, delim);
    strcpy(p->filiere,ptr);
    ptr = strtok(NULL, delim);
    i++;
    p++;
    }
   fclose(fp);
   return Surv;
}


_Enseignant *ens(int *N)
{

    char nom[95];
    char prenom [95];
	char filiere[90];
	char email[90];
    char ch[10000], file_name[250];
    FILE *fp;

   strcpy(file_name,"ENSEIGNANT.txt");

   fp = fopen(file_name, "r"); // read mode
 *N = countLines(fp);
 _Enseignant *Ens = (_Enseignant *) malloc((*N+1) * sizeof(_Enseignant));
   if (fp == NULL || checkfile(fp,*N,3) == 0)
   {
      perror("Fichier invalide ''enseignant.txt''.\n");
      exit(0);
   }
   _Enseignant *p = Ens;

    while (fgets(ch,10000,fp) != NULL)
    {

        char delim[] = "\t\n";

        char *ptr = strtok(ch, delim);
        strcpy(p->nom,ptr);
		ptr = strtok(NULL, delim);
        strcpy(p->prenom,ptr);
		ptr = strtok(NULL, delim);
        strcpy(p->filiere,ptr);
		ptr = strtok(NULL, delim);
        strcpy(p->email,ptr);
		ptr = strtok(NULL, delim);

        p++;

    }
   fclose(fp);
   return Ens;
}


_Compte *cmp(int *N)
{
    _Bool admin;
	char login[90];
    char mdp[20];
	char enseignant[90];
    char ch[10000], file_name[250];
    FILE *fp;

    strcpy(file_name,"COMPTE.txt");

   fp = fopen(file_name, "r"); // read mode
 *N = countLines(fp);
 _Compte *Cmp = (_Compte *) malloc((*N+1) * sizeof(_Compte));
   if (fp == NULL  || checkfile(fp,*N,3) == 0)
   {
      perror("Fichier invalide ''COMPTE.txt''.\n");
      exit(0);
   }
   _Compte *p = Cmp;

    while (fgets(ch,10000,fp) != NULL)
    {

        char delim[] = "\t\n";

        char *ptr = strtok(ch, delim);
           if    (strcmp(ptr,"1") == 0)
            p->admin = 1;
           else
            p->admin = 0;
            ptr = strtok(NULL, delim);
            strcpy(p->login,ptr);
            ptr = strtok(NULL, delim);
		    strcpy(p->mdp,ptr);
            ptr = strtok(NULL, delim);
		    strcpy(p->enseignant,ptr);
            ptr = strtok(NULL, delim);

        p++;
    }
   fclose(fp);
   return Cmp;
}

