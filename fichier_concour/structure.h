#ifndef STRUCTURE_H_INCLUDED
#define STRUCTURE_H_INCLUDED

typedef struct concour concour ;

		struct concour
		{
			int    NCIN ;
			char   NOM[100];
			char   PRENOM[100];
			int    AGE ;
			float  NOTE[10];
			char   *DECISION ;

		};
		concour concourant ;

#endif // STRUCTURE_H_INCLUDED
