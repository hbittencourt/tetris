//victor.varallo@acad.pucrs.br
//opcao 2-recordes
#include <stdio.h>
#include <string.h>

struct stscore{
char anome[50];
int ascore;
}score[11];

struct auxscore{
char anome[50];
int ascore;
}aux;

void ordena_pontuacao(void)
{
	int j,k;

	for(k=0;k<11;k++)
	{
		aux=score[k];
		for(j=k+1;j<11;j++)
		{
			if(score[j].ascore>score[k].ascore)
			{
				aux.anome=score[k].anome;
				aux.ascore=score[k].ascore;
				score[k].anome=score[j].anome;
				score[k].ascore=score[j].ascore;
				score[j].anome=aux.anome;
				score[j].ascore=aux.ascore;
			}	
		}
	}
}
