#ifndef STATISTIQUES_H_INCLUDED
#define STATISTIQUES_H_INCLUDED

/* ***************************************************************************************
		*                                                                                     *
		*      6.Definition de la fonction statistique(def) qui permet de                     *
		*              donner les statistiques selon les decision                             *
		*                                                                                     *
		***************************************************************************************            */

float statistiques(char def[8])

				{

						FILE* fich=NULL;
						int i ;
						float k=0 , l=0 , m=0 , n=0 ;
						float stat;
						char decision[8];
            			int age , numero;
            			float note[10];
            			char nom[100],prenom[100];

						fich=fopen("fichier_concour/fichier_concours/concours.txt","r");

						if (fich!= NULL)
									{
												while(!feof(fich))
															 {
																	k+=1;

                                    fscanf(fich,"%d  ;  %s  ;  %s  ;  %d  ;  %f ; %f ; %f ; %f ; %f ; %f ; %f ; %f ; %f ; %f  ;  %s\n",&numero,nom,prenom,&age,&note[0],&note[1],&note[2],&note[3],&note[4],&note[5],&note[6],&note[7],&note[8],&note[9],decision);

																		if (strcmp(decision ,"admis")==0)
																		{
																			l=l+1;
																		}
																		if (strcmp(decision ,"refuse")==0)
																		{
																			m=m+1;
																		}
																		if (strcmp(decision ,"ajourne")==0)
																		{
																			n=n+1;
																		}

																		}

																		if (strcmp(def ,"admis")==0)
																		{
																			stat= (l * 100)/k ;

																		}
																		if (strcmp(def ,"refuse")==0)
																		{
																			stat= (m * 100)/k ;

																		}
																		if (strcmp(def ,"ajourne")==0)
																		{
																			stat= (n * 100)/k ;

																		}
								return stat;

				}
				fclose(fich);

		}

#endif // STATISTIQUES_H_INCLUDED
