#ifndef RECHERCHER_H_INCLUDED
#define RECHERCHER_H_INCLUDED

/* ***************************************************************************************
		 *                                                                                     *
		 *      9.Definition de la fonction rechercher(ncin) qui permet de                     *
		 *         rechercher un candidat et d'afficher ses informations                       *
		 *                                                                                     *
		 ***************************************************************************************            */
	void rechercher(int ncin)
	 {
		 char decision[8] ,nom[100],prenom[100];
		 int i , age , numero ;
		 float note[10];

		int trouve = 0 ;

		 FILE* fich=NULL;
		      fich=fopen("fichier_concour/fichier_concours/concours.txt","r");

		if(fich==NULL)
		{
		printf("Ouverture impossible du fichier de donnees.");
		getch();
	  }else{

		 while(!trouve & !feof(fich))

		 {

			          fscanf(fich,"%d  ;  %s  ;  %s  ;  %d  ;  %f ; %f ; %f ; %f ; %f ; %f ; %f ; %f ; %f ; %f  ;  %s\n",&numero,nom,prenom,&age,&note[0],&note[1],&note[2],&note[3],&note[4],&note[5],&note[6],&note[7],&note[8],&note[9],decision);

	if(numero==ncin) trouve=1;
		 }

		 if(trouve==0)
													 {
														 printf("\nLe candidat n'a pas ete trouve.\n");
													 }else{

									 				 			printf("\nVoici les informations du candidat ayant pour NCIN : %d  \n\t\t\t\t\t\t\t\tNom    : %s \n\t\t\t\t\t\t\t\tPrenom : %s\n\t\t\t\t\t\t\t\tAge    : %d \n",numero,nom,prenom,age);

											for(i=0 ; i < 9 ; i++)
											 {

														printf("\t\t\t\t\t\t\t\tNOTE%d  : %.2f \n",i+1,note[i]);

											 }
											 printf("\t\t\t\t\t\t\t        NOTE10 : %.2f \n",note[9]);

									 printf("\t\t\t\t\t\t\t\t\t\t\tStatut  : %s\n",decision);
									 printf("\n\n");
							 }

		fclose(fich);

	}
	}
#endif // RECHERCHER_H_INCLUDED
