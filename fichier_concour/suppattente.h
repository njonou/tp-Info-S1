#ifndef SUPPATTENTE_H_INCLUDED
#define SUPPATTENTE_H_INCLUDED
#include "fonctionsupplementaire.h"
#include "admis.h"

/* ***************************************************************************************
			 *                                                                                     *
			 *      7.Definition de la fonction supprimer() qui permet de supprimer                *
			 *                  les admis de plus de 20ans dans admis.txt                          *
			 *                                                                                     *
			 *************************************************************************************** */

	void supprimer()
{

char choix3[50] ;
FILE* fichier3=NULL;
FILE* fichier1=NULL;
int i;
char decision[8];
char choix31[5] ;
int age , numero;
float note[10];
char nom[100],prenom[100];

admis();///////on met a jour le fichier admis.txt


fichier1=fopen("fichier_concour/fichier_concours/admis.txt","r");
if (fichier1!= NULL)
{

			fichier3=fopen("fichier_concour/fichier_concours/tempadmis.txt","w");

			if (fichier3!= NULL)
			 {
						 while(!feof(fichier1))
													 {

		 //transfert des admis dans admis.txt

										 /*colecte des admis/*/

                                fscanf(fichier1,"%d  ;  %s  ;  %s  ;  %d  ;  %f ; %f ; %f ; %f ; %f ; %f ; %f ; %f ; %f ; %f  ;  %s\n",&numero,nom,prenom,&age,&note[0],&note[1],&note[2],&note[3],&note[4],&note[5],&note[6],&note[7],&note[8],&note[9],decision);

																 /*fin de la colecte et debut de l ecriture*/

																 if ((age) < 20)
															 {

                                 fprintf(fichier3,"%d  ;  %s  ;  %s  ;  %d  ;  %.2f ; %.2f ; %.2f ; %.2f ; %.2f ; %.2f ; %.2f ; %.2f ; %.2f ; %.2f  ;  %s\n",numero,nom,prenom,age,note[0],note[1],note[2],note[3],note[4],note[5],note[6],note[7],note[8],note[9],decision);

															 }
								 //fin transfert
								 }
	 }
fclose(fichier3);

}
fclose(fichier1);

remove("fichier_concour/fichier_concours/admis.txt");
rename("fichier_concour/fichier_concours/tempadmis.txt","fichier_concour/fichier_concours/admis.txt");

printf("\n \t\t\tla suppression c est fait avec success .....\n");

do
{

printf("\nVoulez vous consulter la liste des candidat qui n ont pas ete supprimer  ? oui ou non | o/n : ");
scanf("%s",&choix3);

if (strcmp(choix3 ,"oui")==0 | strcmp(choix3 ,"o")==0)
{
printf("\n\t\t\t\t voici la liste des admis   \n\n");
add();
break;
}else{
	if (strcmp(choix3 ,"non" )==0 | strcmp(choix3 ,"n")==0 )
 {
	 printf("\nVotre requete a ete bien recu  . A bientot .\n\n");
	 break;
 }else{

			 printf("\nentrer un choix valide svp\n\n");
}
}

} while (strcmp(choix3 ,"oui")!=0 | strcmp(choix3 ,"non")!=0 | strcmp(choix3 ,"n")!=0 | strcmp(choix3 ,"o")!=0);

}

#endif // SUPPATTENTE_H_INCLUDED
