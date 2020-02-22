#ifndef ADMIS_H_INCLUDED
#define ADMIS_H_INCLUDED

	/* ***************************************************************************************
		 *                                                                                     *
		 *      4.Definition de la fonction admis() qui permet de remplir les donnees          *
		 *                 relatives des admis dans le fichier admis.txt                       *
		 *                                                                                     *
		 ***************************************************************************************            */


void admis()
	 {

	char choix3[50] ;
	FILE* fich=NULL;
	FILE* fichier1=NULL;
	int i;
	char decision[8];
    int age , numero;
    float note[10];
    char nom[100],prenom[100];
	char choix31[5] ;

	fich=fopen("fichier_concour/fichier_concours/concours.txt","r");
	if (fich!= NULL)
			 {
			 fichier1=fopen("fichier_concour/fichier_concours/admis.txt","w");
			 if (fichier1!= NULL)
						{
							 while(!feof(fich))
							 {
			//transfert des admis dans admis.txt

											/*colecte des admis/*/

                      fscanf(fich,"%d  ;  %s  ;  %s  ;  %d  ;  %f ; %f ; %f ; %f ; %f ; %f ; %f ; %f ; %f ; %f  ;  %s\n",&numero,nom,prenom,&age,&note[0],&note[1],&note[2],&note[3],&note[4],&note[5],&note[6],&note[7],&note[8],&note[9],decision);


												/*fin de la colecte et debut de l ecriture*/
												if (strcmp(decision ,"admis")==0)
											{
                        fprintf(fichier1,"%d  ;  %s  ;  %s  ;  %d  ;  %.2f ; %.2f ; %.2f ; %.2f ; %.2f ; %.2f ; %.2f ; %.2f ; %.2f ; %.2f  ;  %s\n",numero,nom,prenom,age,note[0],note[1],note[2],note[3],note[4],note[5],note[6],note[7],note[8],note[9],decision);

											}
											//fin transfert
						 }
				}
		 fclose(fichier1);
						}
		 fclose(fich);

 }
#endif // ADMIS_H_INCLUDED
