#include <stdio.h>
#include <stdlib.h>
#include "tetris.h"
#include "tetris.c"
<<<<<<< HEAD
#include "conio.h"

=======
>>>>>>> 26e1dab3f5b9879d0f5d58d4488d99288c1de4a0

void recordes(void)
{
    FILE *arquivo;
    int j,k,count=0;
    char nome[50];

    arquivo = fopen("recordes.txt","r");

    k=0;
    //le o arquivo de recordes e preenche os ascore na struct
    while (!feof(arquivo))
    {
        fscanf(arquivo,"%d",&score[k].ascore);
        k++;
        count++;
    }

    fclose(arquivo);

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
    for(k=0; k<count-1; k++) //for executa tantas vezes qunto o numero de linhas(count) -1
    {
        //copia a struct para uma auxiliar
        strcpy(aux.anome, score[k].anome);//aux.anome=score[k].anome;
        aux.ascore=score[k].ascore;
        for(j=k+1; j<count; j++) //compara uma struct com a seguinte no vetor
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


    printf("Pontuação:\n");		//printa top 10
    for(k=0; k<10; k++)
        printf("%do : \t%d\t-%s\n",k+1,score[k].ascore,score[k].anome);
        printf("\n\n\n\n\n");
}


void alarm_handler (int signal __attribute__ ((unused)))
{
    static long h[4];

    if (!signal)
    {
        /* On init from main() */
        h[3] = 500000;
    }

    h[3] -= h[3] / (3000 - 10 * level);
    setitimer (0, (struct itimerval *)h, 0);
}

int update (void)
{
    int x, y;
#ifdef ENABLE_PREVIEW
    const int start = 5;
    int preview[B_COLS * 10];
    int shadow_preview[B_COLS * 10];

    /* Display piece preview. */
    memset (preview, 0, sizeof(preview));
    preview[2 * B_COLS + 1] = 7;
    preview[2 * B_COLS + 1 + peek_shape[1]] = 7;
    preview[2 * B_COLS + 1 + peek_shape[2]] = 7;
    preview[2 * B_COLS + 1 + peek_shape[3]] = 7;

    for (y = 0; y < 4; y++)
    {
        for (x = 0; x < B_COLS; x++)
        {
            if (preview[y * B_COLS + x] - shadow_preview[y * B_COLS + x])
            {
                shadow_preview[y * B_COLS + x] = preview[y * B_COLS + x];
                gotoxy (x * 2 + 26 + 28, start + y);
                printf ("\e[%dm  ", preview[y * B_COLS + x]);
            }
        }
    }
#endif

    /* Display board. */
    for (y = 1; y < B_ROWS - 1; y++)
    {
        for (x = 0; x < B_COLS; x++)
        {
            if (board[y * B_COLS + x] - shadow[y * B_COLS + x])
            {
                shadow[y * B_COLS + x] = board[y * B_COLS + x];
                gotoxy (x * 2 + 28, y);
                printf ("\e[%dm  ", board[y * B_COLS + x]);
            }
        }
    }


    /* Update points and level*/
    while (lines_cleared >= 10)
    {
        lines_cleared -= 10;
        level++;
    }

#ifdef ENABLE_SCORE
    /* Display current level and points */
    textattr(RESETATTR);
    gotoxy (26 + 28, 2);
    printf ("Level  : %d", level);
    gotoxy (26 + 28, 3);
    printf ("Points : %d", points);
#endif
#ifdef ENABLE_PREVIEW
    gotoxy (26 + 28, 5);
    printf ("Preview:");
#endif
    gotoxy (26 + 28, 10);
    printf ("Keys:");

    return getchar ();
}

int fits_in (int *shape, int pos)
{
    if (board[pos] || board[pos + shape[1]] ||
            board[pos + shape[2]]  || board[pos + shape[3]])
    {
        return 0;
    }

    return 1;
}

void place (int *shape, int pos, int b)
{
    board[pos] = b;
    board[pos + shape[1]] = b;
    board[pos + shape[2]] = b;
    board[pos + shape[3]] = b;
}

int *next_shape (void)
{
    int *next = peek_shape;

    peek_shape = &shapes[rand () % 7 * 4];
    if (!next)
    {
        return next_shape ();
    }

    return next;
}
/*******Ascii arts*******/
void abertura()
{
    printf("\t\t\t\t████████╗███████╗████████╗██████╗ ██╗███████╗ \n");
    printf("\t\t\t\t╚══██╔══╝██╔════╝╚══██╔══╝██╔══██╗██║██╔════╝ \n");
    printf("\t\t\t\t   ██║   █████╗     ██║   ██████╔╝██║███████╗ \n");
    printf("\t\t\t\t   ██║   ██╔══╝     ██║   ██╔══██╗██║╚════██║ \n");
    printf("\t\t\t\t   ██║   ███████╗   ██║   ██║  ██║██║███████║ \n");
    printf("\t\t\t\t   ╚═╝   ╚══════╝   ╚═╝   ╚═╝  ╚═╝╚═╝╚══════╝ \n");
    printf("\t\t\t\t \n");

}

void game_over()
{
    printf("\t\t\t\t ██████╗  █████╗ ███╗   ███╗███████╗     ██████╗ ██╗   ██╗███████╗██████╗  \n");
    printf("\t\t\t\t██╔════╝ ██╔══██╗████╗ ████║██╔════╝    ██╔═══██╗██║   ██║██╔════╝██╔══██╗ \n");
    printf("\t\t\t\t██║  ███╗███████║██╔████╔██║█████╗      ██║   ██║██║   ██║█████╗  ██████╔╝ \n");
    printf("\t\t\t\t██║   ██║██╔══██║██║╚██╔╝██║██╔══╝      ██║   ██║╚██╗ ██╔╝██╔══╝  ██╔══██╗ \n");
    printf("\t\t\t\t██║   ██║██╔══██║██║╚██╔╝██║██╔══╝      ██║   ██║╚██╗ ██╔╝██╔══╝  ██╔══██╗ \n");
    printf("\t\t\t\t╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗    ╚██████╔╝ ╚████╔╝ ███████╗██║  ██║ \n");
    printf("\t\t\t\t ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝     ╚═════╝   ╚═══╝  ╚══════╝╚═╝  ╚═╝ \n");
    printf("\t\t\t\t \n");
}


//Arquivo de Recordes


void arq(char jogador[], int points, int level)

{
    FILE *arq;

    arq = fopen("recordes.txt","a");

    fprintf (arq, "%d\n", points * level);

    fclose(arq);

    arq = fopen("nomes.txt","a");

    fprintf (arq, "%s\n", jogador);

    fclose (arq);
}


//COMO JOGAR - Guia na tela

void show_online_help (void)
{
    const int start = 11;

    textattr(RESETATTR);
    gotoxy (26 + 28, start);
    puts("j     - left");
    gotoxy (26 + 28, start + 1);
    puts("k     - rotate");
    gotoxy (26 + 28, start + 2);
    puts("l     - right");
    gotoxy (26 + 28, start + 3);
    puts("space - drop");
    gotoxy (26 + 28, start + 4);
    puts("p     - pause");
    gotoxy (26 + 28, start + 5);
    puts("q     - quit");
}

/* Code stolen from http://c-faq.com/osdep/cbreak.html */
int tty_break (void)
{
    struct termios modmodes;

    if (tcgetattr(fileno(stdin), &savemodes) < 0)
    {
        return -1;
    }
    havemodes = 1;

    hidecursor();

    /* "stty cbreak -echo" */
    modmodes = savemodes;
    modmodes.c_lflag &= ~ICANON;
    modmodes.c_lflag &= ~ECHO;
    modmodes.c_cc[VMIN] = 1;
    modmodes.c_cc[VTIME] = 0;

    return tcsetattr(fileno(stdin), TCSANOW, &modmodes);
}

int tty_fix (void)
{
    if (!havemodes)
    {
        return 0;
    }

    showcursor();

    /* "stty sane" */
    return tcsetattr(fileno(stdin), TCSANOW, &savemodes);
}


