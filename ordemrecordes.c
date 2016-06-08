//victor.varallo@acad.pucrs.br
//opção 2-recordes
#include <stdio.h>
#include <string.h>

/*
struct stscore{			//struct deve ler recordes armazenados no arquivo recordes.txt
	char nome[50];
	int score;
}scores[10];

struct snome{
	char vnome[50];
}nomes[10];
*/
int main(void)
{
	FILE *arquivo;
	int temp,pts,i,points[11]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	char name[50];

	

	arquivo = fopen("recordes.txt","r");
	
	while(fscanf(arquivo,"%d",&pts)!= 1)				//  while (!feof(arq))
	{
	for(i=0;i<10;i++)
		{
		if(pts>points[i])	
			{
			temp=points[i];
			points[i]=pts;
			points[i+1]=temp;
			break;
			}
		}
	
	}

	fclose(arquivo);
/*
	for(i=0;i<10;i++)
	{
		scores[i].nome=nomes[i].vnome;
		scores[i].score=points[i];
	}
*/
	printf("pontuacao\n");

	for(i=1;1<10;i++)
		printf("%d\n",points[i]);
	
	return 0;
}	
