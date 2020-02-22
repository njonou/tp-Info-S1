#ifndef AJOUTER_H_INCLUDED
#define AJOUTER_H_INCLUDED

/* ***************************************************************************************
   *                                                                                     *
   *      3.Ecriture des procedures permettant de gerer le fichier des candidats         *
   *                                                                                     *
   ***************************************************************************************  */

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////// 3.1 - fonctions permettant d'ajouter les donnees d'un candidat dans le fichier concour.txt ////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		void ajouter()
	{
		int i;

		FILE* fich=NULL;


		fich=fopen("fichier_concour/fichier_concours/concours.txt","a");

		if (fich!= NULL)
		{

             fprintf(fich,"%d  ;  %s  ;  %s  ;  %d  ;  %.2f ; %.2f ; %.2f ; %.2f ; %.2f ; %.2f ; %.2f ; %.2f ; %.2f ; %.2f  ;  %s\n",concourant.NCIN,concourant.NOM,concourant.PRENOM,concourant.AGE,concourant.NOTE[0],concourant.NOTE[1],concourant.NOTE[2],concourant.NOTE[3],concourant.NOTE[4],concourant.NOTE[5],concourant.NOTE[6],concourant.NOTE[7],concourant.NOTE[8],concourant.NOTE[9],concourant.DECISION);
			 printf("\n \t l operation d enregistrement a ete realise avec success .... \n\n");

			 }
			 else{
			 printf("desole il ya eu une erreur lors de l enregistrement\n");
			 printf("svp veillez re remplir\n");
			 saisir();
			 ajouter();

       }
	   fclose(fich);

    }

#endif // AJOUTER_H_INCLUDED
