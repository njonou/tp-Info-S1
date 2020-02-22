#ifndef AFFICHEMERITE_H_INCLUDED
#define AFFICHEMERITE_H_INCLUDED
#include "admis.h"


/* ***************************************************************************************
	 *                                                                                     *
	 *              8. Ecriture de la fonction affiche_merite() qui permet                 *
	 *                    d'afficher les admis par ordre de merite                         *
	 *                                                                                     */


	 void merite()
	 				{


	 				 void trier(int i, int j, float tab[], float tmp[])
	 																					 {
	 																											if(j <= i){ return;}
	 																											int m = (i + j) / 2;

	 																											trier(i, m, tab, tmp);     //trier la moitie gauche recursivement
	 																											trier(m + 1, j, tab, tmp); //trier la moitie droite recursivement
	 																											int pg = i;     //pg pointe au debut du sous-tableau de gauche
	 																											int pd = m + 1; //pd pointe au debut du sous-tableau de droite
	 																											int c;          //compteur
	 																										 // on boucle de i a  j pour remplir chaque element du tableau final fusionne
	 																											for(c = i; c <= j; c++) {
	 																													if(pg == m + 1) { //le pointeur du sous-tableau de gauche a atteint la limite
	 																															tmp[c] = tab[pd];
	 																															pd++;
	 																													}else if (pd == j + 1) { //le pointeur du sous-tableau de droite a atteint la limite
	 																															tmp[c] = tab[pg];
	 																															pg++;
	 																													}else if (tab[pg] > tab[pd])
	 																													{ //le pointeur du sous-tableau de gauche pointe vers un element plus grand
	 																															tmp[c] = tab[pg];
	 																															pg++;
	 																													}else
	 																												 {  //le pointeur du sous-tableau de droite pointe vers un element plus grand
	 																															tmp[c] = tab[pd];
	 																															pd++;
	 																													}
	 																											}
	 																											for(c = j; c >= i; c--)
	 																											{  //copier les elements de tmp[] a  tab[]
	 																													tab[c] = tmp[c];
	 																											}
	 																					 }



	 					FILE* fichier1=NULL;
	 					int i , k, j=0 ,l=0 , z , y , i1  , t=1;
	 					char decision[8] ;
	           int age , numero;
	           float note[10] , tst ;
	           char nom[100],prenom[100];
	 					int verify[999]   ;
	 					float  moyenne[999],tempo[999], s=0;
	 					fichier1=fopen("fichier_concour/fichier_concours/admis.txt","r");

						admis();///////on met a jour le fichier admis.txt
	 //
	 // on enregistre toutes les moyenne dans un tableau
	 					if (fichier1!= NULL)
	 											{
	 													 do
	 																{
	 																	s=0;

	                                   fscanf(fichier1,"%d  ;  %s  ;  %s  ;  %d  ;  %f ; %f ; %f ; %f ; %f ; %f ; %f ; %f ; %f ; %f  ;  %s\n",&numero,nom,prenom,&age,&note[0],&note[1],&note[2],&note[3],&note[4],&note[5],&note[6],&note[7],&note[8],&note[9],decision);

	 																				for ( i1 = 0; i1 < 10; i1++)
	                                         {
	                                           s+=note[i1];
	                                         }

	 																			moyenne[l] = s/10;
	 																			verify[l]=numero;

	 																			l=l+1;

	 																 }while(!feof(fichier1));

	 												}
	 												else
	 												{
	 												printf("le fichier nexiste pas ou est vide \n");
	 												}
	 												fclose(fichier1);

	 												//fin de l'enregistrement

	 												trier(0, l-1,moyenne,tempo); ////// on trie le tableau des moyennes enregistrer dans le bloc precedent

														printf("\t\t  ############## Voici la liste des admis par ordre de merite ###############\n\n");

														for ( i = 0; i <= l; i++)// on affiche les informations des candidats dans lordre des moyenne obtenus(moyenne deja trie)
														{
															if (moyenne[i]==tst) {
																continue;
															}
															 	fichier1=fopen("fichier_concour/fichier_concours/admis.txt","r");
															 while (!feof(fichier1))
															 {

																		 fscanf(fichier1,"%d  ;  %s  ;  %s  ;  %d  ;  %f ; %f ; %f ; %f ; %f ; %f ; %f ; %f ; %f ; %f  ;  %s\n",&numero,nom,prenom,&age,&note[0],&note[1],&note[2],&note[3],&note[4],&note[5],&note[6],&note[7],&note[8],&note[9],decision);


																		 s=0;
																		 for ( z = 0; z < 10; z++)
																		 {
																			 s+=note[z];
																		 }
																		 s=s/10;
																		 if (s==moyenne[i])
																			 {
																				 printf("%8d  *  %14s  *  %14s  * %3d",numero,nom,prenom,age);
																				 for(y=0 ; y < 10 ; y++)
																				 {
																					 printf(" *  %.2f",note[y]);
																				 }
																				 printf(" *  %8s ",decision);
																				 printf(" *  %.2f",moyenne[i]);
																				 printf("\n");
																				 printf("***********************************************************************************************************************************************************************\n");

																			 }
															 }
															 fclose(fichier1) ;
															 tst = moyenne[i];
														}
	 												/////////fin de laffichage des informationsdans lordre des moyennes obtenus

	 	} ////////////////// fin de la fonction merite/////////////////////////////////


#endif // AFFICHE-MERITE_H_INCLUDED
