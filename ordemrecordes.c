//victor.varallo@acad.pucrs.br
//opção 2-recordes
#include <stdio.h>
#include <string.h>
#define SIZE 999999
	

struct stscore{
char anome[50];
int ascore;
}score[SIZE];

struct auxscore{
char anome[50];
int ascore;
}aux;

int main(void)
{
	FILE *arquivo;
	int j,k;
	char nome[50];

	arquivo = fopen("recordes.txt","r");
	
	k=0;
	//le o arquivo de recordes e preenche os ascore na struct
	while (!feof(arquivo))
	{
		fscanf(arquivo,"%d",&score[k].ascore);
		k++;
	}
	
	fclose(arquivo);

//arrumar leitura da string
	arquivo = fopen("nomes.txt","r");  
	
	k=0;
	//le o arquivo com os nomes e preenche os anome na struct
	while (!feof(arquivo))
	{
        fscanf(arquivo, "%s",nome);
        strcpy(score[k].anome, nome);
		k++;
	}
	
	fclose(arquivo);



//ordena struct de acordo com a pontuacao
	for(k=0;k<SIZE-1;k++)
	{
        //copia a struct para uma auxiliar
		strcpy(aux.anome, score[k].anome);//aux.anome=score[k].anome;
		aux.ascore=score[k].ascore;
		for(j=k+1;j<SIZE;j++)//compara uma struct com a seguinte no vetor
		{
			if(score[j].ascore>score[k].ascore)
			{
				strcpy(aux.anome, score[k].anome);//aux.anome=score[k].anome;
				aux.ascore=score[k].ascore;
				strcpy(score[k].anome, score[j].anome);//score[k].anome=score[j].anome;
				score[k].ascore=score[j].ascore;
				strcpy(score[j].anome, aux.anome);//score[j].anome=aux.anome;
				score[j].ascore=aux.ascore;
			}	
		}
	}



	printf("pontuacao:\n");		//printa top 10
	for(k=0;k<10;k++)
		printf("%do : \t%d\t-%s\n",k+1,score[k].ascore,score[k].anome);

	return 0;
}	
