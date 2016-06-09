//victor.varallo@acad.pucrs.br
//opção 2-recordes
#include <stdio.h>
#include <string.h>
#define SIZE 11
	
/**************************************************************************************************************/
//
//		concertar leitura da string do arquivo nomes.txt e armazena-la na struct junto com o score para
//      posterior ordenacao
//
//
//
//
/***************************************************************************************************************/

struct stscore{
//char anome[50];
int ascore;
}score[SIZE];

struct auxscore{
//char anome[50];
int ascore;
}aux;

int main(void)
{
	FILE *arquivo;
	int j,k;
//	char nome[50];
//	char *nome;	

	arquivo = fopen("recordes.txt","r");
	
	k=0;
	//le o arquivo de recordes e preenche os ascore na struct
	while (!feof(arquivo))
	{
		fscanf(arquivo,"%d",&score[k].ascore);
		k++;
	}
	
	fclose(arquivo);


/*	//arrumar leitura da string
	arquivo = fopen("nomes.txt","r");
	
	k=0;
	//le o arquivo com os nomes e preenche os anome na struct
	while (!feof(arquivo))
	{
		score[k].anome = fgets(nome, 50, arquivo);
	//	score[k].anome=nome;
		k++;
	}
	
	fclose(arquivo);
*/
/**********************************

//ordena struct de acordo com a pontuacao
	for(k=0;k<SIZE-1;k++)
	{
		aux.anome=score[k].anome;
		aux.ascore=score[k].ascore;
		for(j=k+1;j<SIZE;j++)
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
***********************************/


	printf("pontuacao\n");		//printa recordes
	for(k=1;1<10;k++)
		//printf("%s\n",score[k].anome);
		printf("%d\n",score[k].ascore);
	
	return 0;
}	
