#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fichier_concour/structure.h"
#include "fichier_concour/saisir.h"
#include "fichier_concour/ajouter.h"
#include "fichier_concour/modification.h"
#include "fichier_concour/suprrcandidat.h"
#include "fichier_concour/admis.h"
#include "fichier_concour/attente.h"
#include "fichier_concour/statistiques.h"
#include "fichier_concour/suppattente.h"
#include "fichier_concour/affichemerite.h"
#include "fichier_concour/rechercher.h"


      /* ***************************************************************************************
		 *                                                                                     *
		 *      10.ecriture du programme principal permettant d'executer toutes                *
		 *                            les fonctions precedentes                                *
		 *                                                                                     *
		 ***************************************************************************************            */


int main()
{
              ///////////////////////declaration des variables///////////////////////////////

                int choix1 ;
            	char choix2[50],b[8] , choix3[3];
            	int a , c;

///////////////////////////// fonction pour effectuer des choix/////////////////////////////////////////
  void choix_pour_le_traitement()
    {

		int ret ;

      void continuation()// fonction pour continuer ces operatios
            {
                  do
                  {

                      printf("\nVoulez vous continuer avec d autres options dans notre menu principal oui ou non | o/n : ");
                      scanf("%s",&choix2);

                      if (strcmp(choix2 ,"oui")==0 | strcmp(choix2 ,"o")==0)
                      {
                         printf("\n\t\t\t\tQue Voulez vous maintenant faire  \n\n");
                         choix_pour_le_traitement();
                         break;
                      } else if (strcmp(choix2 ,"non" )==0 | strcmp(choix2 ,"n")==0 )
                       {
                         printf("\nMerci d'avoir utiliser notre programme . A bientot .\n\n");
                         break;
                       }else{

                         printf("\nentrer un choix valide svp\n\n");
                       }

                  }while(strcmp(choix2 ,"oui")!=0 | strcmp(choix2 ,"non")!=0 | strcmp(choix2 ,"n")!=0 | strcmp(choix2 ,"o")!=0);
            }

/////////////////operation pouvant etre effectuer par l utilisateur
        printf(" 0 . Voir la liste des concourants avec toutes leurs donnees\n");
        printf(" 1 . Se faire enregistrer pour le concour \n");
        printf(" 2 . Modifier les informations d' un candidat \n");
        printf(" 3 . Creer et ou voir la liste des admis \n");
        printf(" 4 . Creer et ou voir la liste des admis qui sont dans la liste d'attente \n");
        printf(" 5 . Voir les statistiques du concours selon la decision \n");
        printf(" 6 . Afficher la liste des admis par ordre de merite \n");
        printf(" 7 . Rechercher les informations d'un candidat \n");
        printf("\n\t\tPour les administrateurs\n\n");
        printf(" 8 . Supprimer les informations d'un candidat \n");
        printf(" 9 . Supprimer les admis ayant plus de 20 ans dans le fichier admis \n");
		        do
		            {

				        do {
				  			ret = 0;
				  			printf("\n\t\t\tentrer votre choix :   \t ");
				            ret=scanf("%d",&choix1);

							  if (ret!=1)
							  {
							  	printf("erreur de saisir \n");
								rewind(stdin);
							  }

				        }while(ret!=1);


                if (choix1 < 0 | choix1 >= 10)
                {
                	printf("\n Ce choix est invalide \n");
                }
            } while (choix1 < 0 | choix1 >= 10);
            		        printf("\n");


        switch (choix1)
        {
          // on discute selon  les valeurs du choix effectuer
          case 0 :
          printf("\n\a\aVoici la liste des concourants avec leurs informations\n\n");
                  afficher();
                  continuation();
          break;
          case 1 :// pour se faire enregistrer
                    strcpy(choix3,"oui");
                    do
                     {
                      if (strcmp(choix3 ,"oui")==0 | strcmp(choix3 ,"o")==0)
                      {
                        printf("\n\t\tveillez remplir les informations ci dessous svp\n\n");
                        saisir();
                        ajouter();

                       }else if (strcmp(choix3 ,"non")==0 | strcmp(choix3 ,"n")==0)
                      {
                         printf("votre requete a ete prise en compte .......\n");
                         break;
                      }else{
                        printf("choix invalide\n");
                      }

                        printf("voulez vous Ajouter un autre candidat oui/non(o/n)\n ");
        								scanf("%s",&choix3);
                     } while (strcmp(choix3 ,"oui")!=0 | strcmp(choix3 ,"non")!=0 | strcmp(choix3 ,"n")!=0 | strcmp(choix3 ,"o")!=0);
                     continuation();
          break;
      //////////////////////////////////////////////////////////////////////////////////
          case 2 :// pour Modifier les informations
                  strcpy(choix3,"oui");
                  do
                   {
                    if (strcmp(choix3 ,"oui")==0 | strcmp(choix3 ,"o")==0)
                    {
                       modification();
                     }else if (strcmp(choix3 ,"non")==0 | strcmp(choix3 ,"n")==0)
                    {
                       printf("votre requete a ete prise en compte .......\n");
                       break;
                    }else{
                      printf("choix invalide\n");
                    }

                      printf("voulez vous refaire des modifications sur un autre/meme candidat/ oui/non(o/n)\n ");
      								scanf("%s",&choix3);
                   } while (strcmp(choix3 ,"oui")!=0 | strcmp(choix3 ,"non")!=0 | strcmp(choix3 ,"n")!=0 | strcmp(choix3 ,"o")!=0);

                      continuation();

          break;
      //////////////////////////////////////////////////////////////////////////////////
          case 3 :// pour Creer etvoir la liste des admis
                    admis();
                    printf("\n \t\t\tla mise a our du fichier admis.txt c est fait avec success .....\n");

				  do
					 {
								printf("\nVoulez vous consulter la liste des admis ? oui ou non | o/n : ");
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
                    continuation();
          break;
      //////////////////////////////////////////////////////////////////////////////////
          case 4 :// pour Creeret ou voir les admis qui sont dans la liste d'attente

                    attente();// on appelle la fonction attente
                    printf("\n \t\t\tla mise a our du fichier attente .txt c est fait avec success .....\n");

					 do
					 {

									printf("\nVoulez vous consulter la liste des candidat en attente  ? oui ou non | o/n : ");
									scanf("%s",&choix3);

									if (strcmp(choix3 ,"oui")==0 | strcmp(choix3 ,"o")==0)
									{
											printf("\n\t\t\t\t voici la liste des admis en attente  \n\n");
											addattente();
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
                    continuation();
          break;
      //////////////////////////////////////////////////////////////////////////////////
          case 5 :// pour Voir les statistiques du concour selon la decision
          strcpy(choix3,"oui");
          do
          {
                 if (strcmp(choix3 ,"oui")==0 | strcmp(choix3 ,"o")==0)
                 {
                   do
                   {
                       printf("\nvous voulez voir les statistique de quel decision? refuse admis ou ajourne   :   ");
                         scanf("%s",&b);
                       if (strcmp(b ,"admis")==0 | strcmp(b ,"refuse")==0 | strcmp(b ,"ajourne")==0)
                       {
                         printf("\n\t\t\tstatistique %s = %f\n",b,statistiques(b));
                         break;
                       }else{
                         printf("\ndesole cette decision n est pas prise en compte  \n\n");
                       }
                   } while (strcmp(b ,"admis")!=0 | strcmp(b ,"refuse")!=0 | strcmp(b ,"ajourne")!=0);

                 }else{
                         if (strcmp(choix3 ,"non" )==0 | strcmp(choix3 ,"n")==0 )
                         {
                               printf("\nVotre requete a ete bien recu  . A bientot .\n\n");
                               break;
                         }else{
                                 printf("\nentrer un choix valide svp\n\n");
                               }
                 }

                 printf("\nVoulez vous consulter les statistiques de d'autre decicion ? oui ou non | o/n : ");
                 scanf("%s",&choix3);

          } while (strcmp(choix3 ,"oui")!=0 | strcmp(choix3 ,"non")!=0 | strcmp(choix3 ,"n")!=0 | strcmp(choix3 ,"o")!=0);

                    continuation();

          break;
      //////////////////////////////////////////////////////////////////////////////////
          case 6 :// pour Afficher la liste des admis par ordre de merite
                    merite();
                    continuation();
          break;
      //////////////////////////////////////////////////////////////////////////////////
          case 7 :// pour Rechercher les informations d'un candidat
          strcpy(choix3,"oui");
                  do
                  {

                      if (strcmp(choix3 ,"oui")==0 | strcmp(choix3 ,"o")==0)
    									{
                        printf("\nveillez entrer la cnin du candidat que vous chercher :  ");
                        scanf("%d",&a);
                        rechercher(a);
                        printf("\n \t la recherche est termine .... \n\n");

    									}else{
    													if (strcmp(choix3 ,"non" )==0 | strcmp(choix3 ,"n")==0 )
    													{
    																printf("\nVotre requete a ete bien recu  . A bientot .\n\n");
    																break;
    													}else{
    																	printf("\nentrer un choix valide svp\n\n");
    																}
    									}
                      printf("Voulez vous effectuer d autres Recherche oui/non(o/n)  :  ");
                      scanf("%s",choix3);
                      printf("\n");
                  } while(strcmp(choix3 ,"oui")!=0 | strcmp(choix3 ,"non")!=0 | strcmp(choix3 ,"n")!=0 | strcmp(choix3 ,"o")!=0);
                    continuation();
          break;
      ///////////////////////////////////////////////////////////////////////////////////
          case 8 :// pour Supprimer les informations d'un candidat

          strcpy(choix3,"oui");
                  do
                  {

                      if (strcmp(choix3 ,"oui")==0 | strcmp(choix3 ,"o")==0)
                      {
                        do
                        {
                            printf("entrer la ncin du candidat ");
                              scanf("%d",&c);
                            if (c>=0)
                            {
                              suppr(c);
                              break;
                            }else{
                              printf("\ndesole cet NCIN n est pas valide  \n\n");
                            }
                        } while (c<0);

                      }else{
                              if (strcmp(choix3 ,"non" )==0 | strcmp(choix3 ,"n")==0 )
                              {
                                    printf("\nVotre requete a ete bien recu  . A bientot .\n\n");
                                    break;
                              }else{
                                      printf("\nentrer un choix valide svp\n\n");
                                    }
                      }
                      printf("Voulez vous Supprimer d autres candidats oui/non(o/n)  :  ");
                      scanf("%s",choix3);
                      printf("\n");
                  } while(strcmp(choix3 ,"oui")!=0 | strcmp(choix3 ,"non")!=0 | strcmp(choix3 ,"n")!=0 | strcmp(choix3 ,"o")!=0);

                    continuation();
          break;
      ///////////////////////////////////////////////////////////////////////////////////
          case 9 :// pour Supprimer les admis ayant plus de 20 ans dans le fichier admis
                    supprimer();
                    continuation();
          break;
        }

  }


  printf("#################################################################################################################\n");
  printf("##                                                                                                             ##\n");
  printf("##                               B I E N V E N U   D A N S  N O T R E   T P                                    ##\n");
  printf("##                                                                                                             ##\n");
  printf("#################################################################################################################\n");
  printf("\n\t\t\t \t\t  --> Unite d'enseignement : INFO 1031\n");
  printf("\n\t\t\t \t\t  --> Encardreur :  Dr.TSOPZE\n");

                          /*realisation du menu pour effectuer le choix de l utilisateur */

  printf("  \n\n\t\t\t     Que voulez vous faires : \n\n\n");
  choix_pour_le_traitement() ;
	printf("    \t  * *\t\t  * *\t  * *\t\t  * *\t  * *\t\t  * *\t\n");
	printf("    \t  * *\t\t  * *\t  * *\t\t  * *\t  * *\t\t  * *\t\n");
	printf("    \t  * *\t\t  * *\t  * *\t\t  * *\t  * *\t\t  * *\t\n");
	printf("    \t*******\t\t*******\t*******\t\t*******\t*******\t\t*******\t\n");
	printf("    \t *****\t\t *****\t *****\t\t *****\t *****\t\t *****\t\n");
	printf("    \t   *  \t\t   *  \t   *  \t\t   *  \t   *  \t\t   *  \t\n");
  printf("  \n\n\t\t\t\tRealise et presente par :    \n");
  printf("  \n\t\t\t --> Njonou Kouaya Gaby    19M2347\n");
  printf("  \t\t\t\t    et \n");
  printf("  \t\t\t --> Fone Simo Inzagui Merlin    19M2382 \n\n\n");

  printf("    \t   *  \t\t   *  \t   *  \t\t   *  \t   *  \t\t   *  \t\n");
  printf("    \t *****\t\t *****\t *****\t\t *****\t *****\t\t *****\t\n");
  printf("    \t*******\t\t*******\t*******\t\t*******\t*******\t\t*******\t\n");
  printf("     \t * *\t\t  * *\t  * *\t\t  * *\t  * *\t\t  * *\t\n");
  printf("     \t * *\t\t  * *\t  * *\t\t  * *\t  * *\t\t  * *\t\n");
  printf("     \t * *\t\t  * *\t  * *\t\t  * *\t  * *\t\t  * *\t\n");

  return 0;
}
// fin de notre programme
