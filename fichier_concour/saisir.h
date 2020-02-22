#ifndef SAISIR_H_INCLUDED
#define SAISIR_H_INCLUDED

/* ***************************************************************************************
   *                                                                                     *
   *      2.Definition de la fonction saisir() qui permet de remplir les donnes          *
   *              relatives aux candidats dans le fichier concours.txt                   *
   *                                                                                     *
   ***************************************************************************************            */

void saisir()
	 		{

	 	 FILE* fich=NULL;
	     int age , numero;
	     long int verify[99999] , j=0 ;
	     float note[10];
	     char decision[8] ,nom[100],prenom[100],*test1;
	 	 int   i, s , ret ;
	 	 float moyenne ;
	 	 char  *statut;

		 do {
	   			ret = 0;
	   			printf("\t\t\t\t NCIN :\t\t");
	             ret=scanf("%d",&concourant.NCIN);

	 			  if (ret!=1)
	 			  {
	 			  	printf("erreur de saisir \n");
	 				rewind(stdin);
	 			  }

	    }while(ret!=1);

	     fich=fopen("fichier_concour/fichier_concours/concours.txt","a");
	     fclose(fich);

	     fich=fopen("fichier_concour/fichier_concours/concours.txt","r");

	     if (fich!= NULL)
	            {

	                   do{

                       fscanf(fich,"%d  ;  %s  ;  %s  ;  %d  ;  %f ; %f ; %f ; %f ; %f ; %f ; %f ; %f ; %f ; %f  ;  %s\n",&numero,nom,prenom,&age,&note[0],&note[1],&note[2],&note[3],&note[4],&note[5],&note[6],&note[7],&note[8],&note[9],decision);

	            								verify[j] = numero ;
	            								j = j+1;

	    		             }while(!feof(fich));

	                 i=0;
	                 test1="true";
	    		          while ((i < j) & test1=="true")
	                      {
	                            if (concourant.NCIN==verify[i] ) {

	                              test1="false";

	                            } else {
	                              test1="true";
	                            }
	                            i++;
	                     }
	                    if (test1=="true")
	                    {

	                         printf("\n\t\t\t\t Nom :\t\t");
	                      		scanf("%s",&concourant.NOM);

	                      		printf("\n\t\t\t\t PRENOM :\t");
	                      		scanf("%s",&concourant.PRENOM);

	                      	  do
	                      		{

																do {
													 	   			ret = 0;
																		printf("\n\t\t\t\t AGE :\t\t");
													 	             ret=scanf("%d",&concourant.AGE);;

													 	 			  if (ret!=1)
													 	 			  {
													 	 			  	printf("erreur de saisir \n");
													 	 				rewind(stdin);
													 	 			  }

													 	    }while(ret!=1);


	                      		}while(concourant.AGE < 0 | concourant.AGE > 100);

	                      		printf("\n\n\t\t\t\t PRISE DES NOTES \n\n");

	                            i=0;

	                      		while(i<10)
	                             {

	                              			do
	                              			{
																						do {
																								 ret = 0;
																								 	printf("\t\t\t Entrer la note %d  :\t",i+1);
																										 ret=scanf("%f",&concourant.NOTE[i]);

																								 if (ret!=1)
																								 {
																									 printf("erreur de saisir \n");
																								 rewind(stdin);
																								 }

																							}while(ret!=1);

	                              			}while((concourant.NOTE[i] < 0 ) | (concourant.NOTE[i] > 20));

	                              			i++;
	                      		    }

	                      		statut = "true";

	                      		i=0;

	                      		while (i < 10 & statut == "true")
	                      		  {
	                            			if (concourant.NOTE[i]>=10)
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
	                      			  s= s + concourant.NOTE[i] ;
	                      		}

	                      		moyenne = s / 10 ;

	                      		if ( moyenne >= 10 & statut == "true" )
	                      		{
	                      			  concourant.DECISION = "admis";

	                      		}

	                      		if (moyenne >= 10 & statut == "false")
	                      			{
	                      				   concourant.DECISION = "ajourne";
	                      			}
	                      		if(moyenne < 10 )
	                      		{
	                      				 concourant.DECISION = "refuse";
	                      		}

	                    } else {
	                      printf("cni existe dja veillez lee changer\n");
	                      saisir();

	                    }
	    }

	 	}
#endif // SAISIR_H_INCLUDED
