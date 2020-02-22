#ifndef ATTENTE_H_INCLUDED
#define ATTENTE_H_INCLUDED
#include "admis.h"

/* ***************************************************************************************
		*                                                                                     *
		*      5.Definition de la fonction attente() qui permet de remplir les donnes         *
		*             relatives aux admis de plus de 20 ans dans attente.txt                  *
		*                                                                                     *
		***************************************************************************************            */


void attente()
	 {

	char choix3[5] ;
	FILE* fichier2=NULL;
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

						 fichier2=fopen("fichier_concour/fichier_concours/attente.txt","w");

						 

						 if (fichier2!= NULL)
										 {
													 while(!feof(fichier1))
																	 {	//transfert des donnees

																										/*colecte */

                                            fscanf(fichier1,"%d  ;  %s  ;  %s  ;  %d  ;  %f ; %f ; %f ; %f ; %f ; %f ; %f ; %f ; %f ; %f  ;  %s\n",&numero,nom,prenom,&age,&note[0],&note[1],&note[2],&note[3],&note[4],&note[5],&note[6],&note[7],&note[8],&note[9],decision);


																					/*fin de la colecte et debut de l ecriture*/
																					if ((age) >= 20)
																				{

                                          fprintf(fichier2,"%d  ;  %s  ;  %s\n",numero,nom,prenom);

																				}
																				//fin transfert
																 }
										 }
					 fclose(fichier2);
			 }
		 fclose(fichier1);




 }

#endif // ATTENTE_H_INCLUDED
