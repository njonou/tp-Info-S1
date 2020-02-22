#ifndef FONCTIONSUPPLEMENTAIRE_H_INCLUDED
#define FONCTIONSUPPLEMENTAIRE_H_INCLUDED

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////// quelques fonctions utiliser par les fonctions demander dans le tp //////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void add() // utiliser par la fonction admis pour aficher la liste des admis
	 {
		 FILE* fichier1=NULL;
		 int i;
		 char decision[8];
         int age , numero;
         float note[10];
         char nom[25],prenom[25];

		 fichier1=fopen("fichier_concour/fichier_concours/admis.txt","r");

		 if (fichier1!= NULL)
								 {
											while(!feof(fichier1))
													 {
                                 fscanf(fichier1,"%d  ;  %s  ;  %s  ;  %d  ;  %f ; %f ; %f ; %f ; %f ; %f ; %f ; %f ; %f ; %f  ;  %s\n",&numero,nom,prenom,&age,&note[0],&note[1],&note[2],&note[3],&note[4],&note[5],&note[6],&note[7],&note[8],&note[9],decision);

																 printf("%8d  *   %12s   *    %12s   *  %3d  *  ",numero,nom,prenom,age);
                                 for(i=0 ; i < 10 ; i++)
                                 {
                                   printf("%.2f  * ",note[i]);
                                 }

                                 printf(" %8s",decision);
                                 printf("\n");
																 printf("***********************************************************************************************************************************************************************\n");

														}

									 }fclose(fichier1);
				 }


void addattente()// utiliser par la fonction attente() pour aficher la liste des admis de plus de 20 ans
{

		 FILE* fichier2=NULL;
		 int i;
		 char decision[8];
         int age , numero;
         float note[10];
         char nom[100],prenom[100];

		 fichier2=fopen("fichier_concour/fichier_concours/attente.txt","r");

		 if (fichier2!= NULL)
					 {
								while(!feof(fichier2))
								{

                  fscanf(fichier2,"%d  ;  %s  ;  %s\n",&numero,nom,prenom);

                  printf("%d",numero);
									printf("%10s",nom);
									printf("%10s",prenom);
                  printf("\n");

								 }

					 }
					 fclose(fichier2);
 }

	 void afficher()// utiliser  pour aficher la liste des concourant
				{
					FILE* fich=NULL;
					int i;
					char decision[8];
                    int age , numero;
                    float note[10];
                    char nom[100],prenom[100];

									
					printf("***********************************************************************************************************************************************************************\n");
					fich=fopen("fichier_concour/fichier_concours/concours.txt","r");

					if (fich!= NULL)
											{
													 while(!feof(fich))
																{
                                  fscanf(fich,"%d  ;  %s  ;  %s  ;  %d  ;  %f ; %f ; %f ; %f ; %f ; %f ; %f ; %f ; %f ; %f  ;  %s\n",&numero,nom,prenom,&age,&note[0],&note[1],&note[2],&note[3],&note[4],&note[5],&note[6],&note[7],&note[8],&note[9],decision);

                                 printf("%8d  * %15s   *  %15s   *  %3d  *  ",numero,nom,prenom,age);
                                 for(i=0 ; i < 10 ; i++)
                                 {
                                   printf("%.2f  * ",note[i]);
                                 }

                                 printf(" %8s",decision);
                                 printf("\n");
																 printf("***********************************************************************************************************************************************************************\n");

																 }

												}
												fclose(fich);
							}


#endif // FONCTION-SUPPLEMENTAIRE_H_INCLUDED
