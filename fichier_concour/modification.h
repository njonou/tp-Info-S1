#ifndef MODIFICATION_H_INCLUDED
#define MODIFICATION_H_INCLUDED
#include "fonctionsupplementaire.h"
#include "admis.h"
#include "attente.h"



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////// fonctions permettant de modifier les donnees d'un candidat dans le fichier concours.txt ///////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void modification()
	 {

				char choix3[50] ;
				char dec[8];
				char choix31[5], choi[6];
				FILE* fich=NULL;
				FILE* fichier5=NULL;
				int i , age , numero , cnin , i1 ,choisir , i2;
				long int verify[99999] , j=0 ;
				float note[10];
				char det[8] ,nom[100],prenom[100],*test1;
				int   s , ret;
				float moyenne ;
				char  *statut , decision[8];
				fich=fopen("fichier_concour/fichier_concours/concours.txt","r");


				do {
						ret = 0;
						printf("Entrer votre cnin : ");
								 ret=scanf("%d",&cnin);

						if (ret!=1)
						{
							printf("erreur de saisir \n\n");
						rewind(stdin);
						}
						printf("\n");

				}while(ret!=1);


				if (fich!= NULL)
					 {

									do
									{

											fscanf(fich,"%d  ;  %s  ;  %s  ;  %d  ;  %f ; %f ; %f ; %f ; %f ; %f ; %f ; %f ; %f ; %f  ;  %s\n",&numero,nom,prenom,&age,&note[0],&note[1],&note[2],&note[3],&note[4],&note[5],&note[6],&note[7],&note[8],&note[9],decision);

											verify[j] = numero ;

											if (numero==cnin) {

												printf("\t\t\tles informations actuelles de ce candidats sont : \n\n");
												printf("\t\t\t\t\t\tNOM : %s\n",nom);
												printf("\t\t\t\t\t\tPRENOM : %s\n",prenom);
												printf("\t\t\t\t\t\tAGE : %d\n",age);
												for ( i1 = 0; i1 < 10; i1++) {
													printf("\t\t\t\t\t\tNOTE %d : %.3f\n",i1+1,note[i1]);
												}

											}

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
													printf("cni non trouver\n\n");
											}
											else {

												fich=fopen("fichier_concour/fichier_concours/concours.txt","r");
												if (fich!= NULL)
												 {

												 fichier5=fopen("fichier_concour/fichier_concours/modiftemp.txt","w");

												 if (fichier5!= NULL)
													{
																while(!feof(fich))
																				 {

												//transfert de donnees

																				/*colecte de donnees/*/

																						 fscanf(fich,"%d  ;  %s  ;  %s  ;  %d  ;  %f ; %f ; %f ; %f ; %f ; %f ; %f ; %f ; %f ; %f  ;  %s\n",&numero,nom,prenom,&age,&note[0],&note[1],&note[2],&note[3],&note[4],&note[5],&note[6],&note[7],&note[8],&note[9],decision);


																							/*fin de la colecte et debut de l ecriture*/
																							if (numero != cnin)
																											{

																												fprintf(fichier5,"%d  ;  %s  ;  %s  ;  %d  ;  %.2f ; %.2f ; %.2f ; %.2f ; %.2f ; %.2f ; %.2f ; %.2f ; %.2f ; %.2f  ;  %s\n",numero,nom,prenom,age,note[0],note[1],note[2],note[3],note[4],note[5],note[6],note[7],note[8],note[9],decision);

																						}else{
																							printf("voici les choix : \n");

																							printf(" 1- Le Nom\n");
																							printf(" 2- Le Prenom\n");
																							printf(" 3- l'Age\n");
																							printf(" 4- Les Notes\n");
																							printf(" 5- Toutes les informations \n\n");
																							printf("Que voulez vous modifier : \n");
																							scanf("%d",&choisir);
																							switch (choisir) {
																								case  1 :
																												 printf("\n\t\t\t\t Nouveau Nom :\t\t");
																												 scanf("%s",&nom);
																								break;

																								case 2 :
																												printf("\t\t\t\t Nouveau PRENOM :\t");
																												scanf("%s",&prenom);
																								break;

																								case 3 :
																												do
																												{
																													printf("\t\t\t\t Nouveau AGE :\t\t");
																													scanf("%d",&age);
																												}while(age < 0 | age > 100);

																								break;

																								case 4 :
																													printf("\n\t\t\t\t PRISE DES NOTES \n\n");
																												 i=0;
																													while(i<10)
																														{

																																	 do
																																	 {

																																			 printf("\t\t\t Entrer la nouvelle note %d  :\t",i+1);
																																			 scanf("%f",&note[i]);

																																	 }while((note[i] < 0 ) | (note[i] > 20));

																																	 i++;
																														 }

																													statut = "true";
																													i=0;

																													while (i < 10 & statut == "true")
																													 {
																																 if (note[i]>=10)
																																			{
																																					 statut = "true";
																																			}
																																	else{
																																					statut = "false";
																																 }

																																 i++ ;
																													 }

																													s=0 ;

																													for (i = 0; i < 10; ++i)
																													{
																														 s= s + note[i] ;
																													}

																													moyenne = s / 10 ;

																													if ( moyenne >= 10 & statut == "true" )
																													{
																														 strcpy(decision,"admis");

																													}

																													if (moyenne >= 10 & statut == "false")
																													 {
																																strcpy(decision,"ajourne");
																													 }
																													if(moyenne < 10 )
																													{
																															strcpy(decision,"refuse");
																													}
																								break;

																								case 5 :
																								printf("\n\t\tveillez entrer les nouvelles informations du candidat ayant pour CNIN %d   \n",cnin);

																								printf("\n\t\t\t\t Nouveau Nom :\t\t");
																								scanf("%s",&nom);

																								printf("\t\t\t\t Nouveau PRENOM :\t");
																							 scanf("%s",&prenom);

																							 do
																							 {
																								 printf("\t\t\t\t Nouveau AGE :\t\t");
																								 scanf("%d",&age);
																							 }while(age < 0 | age > 100);

																							 printf("\n\t\t\t\t PRISE DES NOUVELLES NOTES \n\n");
																								i=0;
																								 while(i<10)
																									 {

																													do
																													{

																															printf("\t\t\t Entrer la nouvelle note %d  :\t",i+1);
																															scanf("%f",&note[i]);

																													}while((note[i] < 0 ) | (note[i] > 20));

																													i++;
																										}

																								 statut = "true";
																								 i=0;

																								 while (i < 10 & statut == "true")
																									{
																												if (note[i]>=10)
																														 {
																																	statut = "true";
																														 }
																												 else{
																																 statut = "false";
																												}

																												i++ ;
																									}

																								 s=0 ;

																								 for (i = 0; i < 10; ++i)
																								 {
																										s= s + note[i] ;
																								 }

																								 moyenne = s / 10 ;

																								 if ( moyenne >= 10 & statut == "true" )
																								 {
																										strcpy(decision,"admis");

																								 }

																								 if (moyenne >= 10 & statut == "false")
																									{
																											 strcpy(decision,"ajourne");
																									}
																								 if(moyenne < 10 )
																								 {
																										 strcpy(decision,"refuse");
																								 }

																								break;
																							}

                                               fprintf(fichier5,"%d  ;  %s  ;  %s  ;  %d  ;  %.2f ; %.2f ; %.2f ; %.2f ; %.2f ; %.2f ; %.2f ; %.2f ; %.2f ; %.2f  ;  %s\n",numero,nom,prenom,age,note[0],note[1],note[2],note[3],note[4],note[5],note[6],note[7],note[8],note[9],decision);

																							 											 }

																							 												//fin transfert
																							 												}
																							 													}
																							 											 fclose(fichier5);
																							 												 }
																							 											 fclose(fich);
																							 do
																								 {

																										 printf(" \nvoulez vraiment modifier ces informations oui ou non o/n  : ");
																										 scanf("%s",&choi);

																											if (strcmp(choi ,"oui")==0 | strcmp(choi ,"o")==0)
																											{
																													remove("fichier_concour/fichier_concours/concours.txt");
																	 											  rename("fichier_concour/fichier_concours/modiftemp.txt","fichier_concour/fichier_concours/concours.txt");
																													admis();
																													attente();
																													printf("\n \t\t\t les modification ont ete faites avec success .....\n");
																													break;
																											}else{
																																		if (strcmp(choi ,"non" )==0 | strcmp(choi ,"n")==0 )
																																		{
																																			remove("fichier_concour/fichier_concours/modiftemp.txt");
																																			printf("\nVotre requete a ete bien recu  . Aucune modification ne va etre apporter  bientot .\n\n");
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
																	printf("\n\t\t\t\t voici la liste   \n\n");
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

}
#endif // MODIFICATION_H_INCLUDED
