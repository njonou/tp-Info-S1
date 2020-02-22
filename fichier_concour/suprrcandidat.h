#ifndef SUPRRCANDIDAT_H_INCLUDED
#define SUPRRCANDIDAT_H_INCLUDED
#include "fonctionsupplementaire.h"
#include "admis.h"
#include "attente.h"



	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////// fonctions permettant de suprimer les donnees d'un candidat dans le fichier concour.txt ////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void suppr(int cnin)
				{
					char choi[50] ;
	char choix3[50] ;
	char dec[8];
	char choix31[5] ;
	FILE* fich=NULL;
	FILE* fichier4=NULL;
	int i , age , numero;
	long int verify[99999] , j=0 ;
	float note[10];
	char det[8] ,nom[100],prenom[100],*test1 , decision[8];
	fich=fopen("fichier_concour/fichier_concours/concours.txt","r");


	 if (fich!= NULL)
			{

						 do
						 {

               fscanf(fich,"%d  ;  %s  ;  %s  ;  %d  ;  %f ; %f ; %f ; %f ; %f ; %f ; %f ; %f ; %f ; %f  ;  %s\n",&numero,nom,prenom,&age,&note[0],&note[1],&note[2],&note[3],&note[4],&note[5],&note[6],&note[7],&note[8],&note[9],decision);

								 verify[j] = numero ;
								 j = j+1;

						 }while(!feof(fich));

		 }
			 fclose(fich);

					 i=0;
					 test1="true";
						while ((i < j) & test1=="true")
								{
											if (cnin==verify[i] )
											{
												test1="false";
											}
											else {
												test1="true";
											}

											i++;
								 }

							if (test1=="true")
								 {
										 printf("cni non trouver\n");
								 }
								 else {

									 fich=fopen("fichier_concour/fichier_concours/concours.txt","r");
									 if (fich!= NULL)
										{

										fichier4=fopen("fichier_concour/fichier_concours/modiftemp.txt","w");

										if (fichier4!= NULL)
										 {
													 while(!feof(fich))
																		{

									 //transfert des admis dans admis.txt

																	 /*colecte des admis/*/

                                   fscanf(fich,"%d  ;  %s  ;  %s  ;  %d  ;  %f ; %f ; %f ; %f ; %f ; %f ; %f ; %f ; %f ; %f  ;  %s\n",&numero,nom,prenom,&age,&note[0],&note[1],&note[2],&note[3],&note[4],&note[5],&note[6],&note[7],&note[8],&note[9],decision);

																				 /*fin de la colecte et debut de l ecriture*/
																				 if (numero != cnin)
																								 {

                                                   fprintf(fichier4,"%d  ;  %s  ;  %s  ;  %d  ;  %.2f ; %.2f ; %.2f ; %.2f ; %.2f ; %.2f ; %.2f ; %.2f ; %.2f ; %.2f  ;  %s\n",numero,nom,prenom,age,note[0],note[1],note[2],note[3],note[4],note[5],note[6],note[7],note[8],note[9],decision);

																			           }else{
																									 printf("\nVoici les informations du candidat que vous voulez supprimer : %d  \n\t\t\t\t\t\t\t\tNom    : %s \n\t\t\t\t\t\t\t\tPrenom : %s\n\t\t\t\t\t\t\t\tAge    : %d \n",numero,nom,prenom,age);
																											for(i=0 ; i < 9 ; i++)
																											 {

																														printf("\t\t\t\t\t\t\t\tNOTE%d  : %.2f \n",i+1,note[i]);

																											 }
																											 printf("\t\t\t\t\t\t\t        NOTE10 : %.2f \n",note[9]);
																								 }
									 //fin transfert
									 }

										 }

									fclose(fichier4);

										}

									fclose(fich);
									do
										{

												printf(" \nvoulez vraiment supprimer toutes les informations de ce candidat oui ou non o/n  : ");
												scanf("%s",&choi);

												 if (strcmp(choi ,"oui")==0 | strcmp(choi ,"o")==0)
												 {
													 remove("fichier_concour/fichier_concours/concours.txt");
													 rename("fichier_concour/fichier_concours/modiftemp.txt","fichier_concour/fichier_concours/concours.txt");
													 printf("\n \t\t\t la suppression c est fait avec success .....\n");
													 break;


												 }else{
													 if (strcmp(choi ,"non" )==0 | strcmp(choi ,"n")==0 )
													 {
														 remove("fichier_concour/fichier_concours/modiftemp.txt");
														 printf("\nVotre requete a ete bien recu . La suppression n'a pas ete effectuer...\n\n");
														 break;
													 }else{

														 printf("\nentrer un choix valide svp\n\n");

													 }
									 }


										} while (strcmp(choi ,"oui")!=0 | strcmp(choi ,"non")!=0 | strcmp(choi ,"n")!=0 | strcmp(choi ,"o")!=0);

									do
									{

											printf("\nVoulez vous consulter la liste des candidats   ? oui ou non | o/n : ");
											scanf("%s",&choix3);

											 if (strcmp(choix3 ,"oui")==0 | strcmp(choix3 ,"o")==0)
											 {
												 printf("\n\t\t\t\t voici la nouvelle liste    \n\n");
												 afficher();

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

							admis();///////on met a jour le fichier admis.txt
							attente();///////on met a jour le fichier attente.txt
	}


#endif // SUPRR-CANDIDAT_H_INCLUDED
