#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define PRETO "\033[0;30m"
#define VERMELHON "\033[1;31m"
#define VERMELHO "\033[0;31m"
#define VERDE "\033[0;32m"
#define AMARELO "\033[0;93m"
#define AZUL "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CIANO "\033[0;36m"
#define BRANCO "\033[0;37m"
#define RESETAR "\033[0m"
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
char menu[7][6];
int a[7][5] = {{0, 0, 0, 0, 0}};
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
void preencherMat()
{
    short int cont, cont2;

    for(cont = 1; cont < 8; cont++)
    {
        for(cont2 = 0; cont2 < 5; cont2++)
        {
            menu[cont][cont2] = '*';
        }
    }
}
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
void detPalavra()
{
    char palavra[6] = "*****";
    short int i;
    
    for(;;)
    {
        system("clear");
        printf("\nDigite uma palavra da lingua portuguesa de 5 caracteres: ");
        setbuf(stdin, NULL);
        scanf("%6s", palavra );
        if(strlen(palavra) != 5)
        {
            printf("Tamanho incorreto, digite novamente: ");
            system("clear");
        }

        else    if (isalpha(palavra[0]) == 0 || isalpha(palavra[1]) == 0 || isalpha(palavra[2]) == 0 || isalpha(palavra[3]) == 0 || isalpha(palavra[4]) == 0 ) 
                {
                    printf ("Existem Caracteres invalidos, Digite Novamente  : ");
                }
                else break;
    }

    for(i = 0; i < 5; i++)
    {
        menu[0][i] = palavra[i];
        menu[0][i] = toupper(menu[0][i]); 
    }
}
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
void vervit()
{
    char dnv;

    for (int contInterface3 = 0; contInterface3 < 7; contInterface3++)
    {
        if (a[contInterface3][0]== 1 && a[contInterface3][1]==1 && a[contInterface3][2]==1 && a[contInterface3][3]==1 && a[contInterface3][4]==1)
        {
            printf("Voce Acertou a palavra!!!\n\n");
            for(;;)
            {
                printf("Deseja continar?\nDigite S para jogar novamente ou N para encerrar o codigo: ");
                setbuf(stdin, NULL);
                scanf("%c", &dnv);
                dnv = toupper(dnv);
                if(dnv == 'S')
                {   
                    for(int cont = 0; cont < 8; cont++)
                    {
                        for(int cont2 = 0; cont2 < 5; cont2++)
                        {
                            menu[cont][cont2] = '*';
                        }
                    }
                    for(int cont = 0; cont < 8; cont++)
                    {
                        for(int cont2 = 0; cont2 < 5; cont2++)
                        {
                            a[cont][cont2] = 0;
                        }
                    }
                    main();
                }
                else
                {
                    if(dnv == 'N')
                    {
                        menu[6][4] = 'a';
                        return ;
                    }
                    else printf("Digito incorreto, tente novamente!\n:");
                }
            }
        }
    }
}
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
void adicionarPal(int cont)
{
    if(menu[6][4] == '*')
    {
        for(int checagemPalavra = 0; checagemPalavra < 1;)
        {  
            printf("Tente advinhar a palavra: \n");
            setbuf(stdin, NULL);
            scanf("%6s", menu[cont]);
            
            if(strlen(menu[cont]) != 5)
            {
                printf("Tamanho incorreto, digite novamente.\n");
                for(int buffer = cont + 1; buffer < 7; buffer++)
                {
                    for(int cont2 = 0; cont2 < 5; cont2++)
                    {
                        menu[buffer][cont2] = '*';
                    }
                }
            }
                
            else    if (isalpha(menu[cont][0]) == 0 || isalpha(menu[cont][1]) == 0 || isalpha(menu[cont][2]) == 0 || isalpha(menu[cont][3] )  == 0 || isalpha(menu[cont][4] ) == 0)
                    { 
                        printf ("Existem Caracteres invalidos, Digite Novamente =(\n");
                    }

                    else
                    {
                        for(int cont2 = 0; cont2 < 5; cont2++) menu[cont][cont2] = toupper(menu[cont][cont2]);
                        checagemPalavra = 1;
                    }
        }
    }
}
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
void Game()
{
    short int cont, cont2, tentativas = 0;
    system("clear");
    preencherMat();
 
    cont = 1;
    printf(BRANCO);

    for(;cont < 8; cont++)
    {
        imprimirMenu();
        tentativas++;

        vervit();
        if(menu[6][4] == '*')
        { 
            adicionarPal(cont);
            verPalavra(tentativas);
        }
        else 
            
            return;
    }
}
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
void verPalavra(int tentativas)
{
    short int cont, cont2;

    for(cont = 0; cont < 5; cont++)
    {

        for(cont2 = 0; cont2 < 5; cont2++)
        {

            if(menu[0][cont] == menu[0][cont2])
            a[0][cont] = cont2;

        }


        printf("%d ", a[0][cont]);
    }  



    for(cont = 0; cont < 5; cont++)
    {
        if(menu[tentativas][cont] != menu[0][cont])
        a[tentativas][cont] = 0;
        
        if(menu[tentativas][cont] == menu[0][cont])
        a[tentativas][cont] = 1;
        
    }

    for(cont = 0; cont < 5; cont++)
    {

        for(cont2 = 0; cont2 < 5; cont2++)
        {
            if(menu[tentativas][cont] == menu[0][cont2] && a[tentativas][cont2] != 1 && a[0][cont] == 1)
            {
                a[tentativas][cont] = 2;
                
            }
        }
    }  
}
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
void imprimirMenu()
{
    setbuf(stdin, NULL);
    system("clear");
    for(int contInterface = 1; contInterface < 7; contInterface++)
    {
        for(int contInterface2 = 0 ;contInterface2 < 5; contInterface2++)
        {
            if(a[contInterface][contInterface2]==0)
 
            printf(BRANCO"%c   ", menu[contInterface][contInterface2]);
 
            else
            {
                if(a[contInterface][contInterface2]==1)
 
                    printf(AZUL"%c   ", menu[contInterface][contInterface2]);
    
                else
 
                    printf(AMARELO "%c   ", menu[contInterface][contInterface2]);
            }
        }
        printf("\n\n"); 
    }

    printf(BRANCO);
}
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
int main()
{
    system("clear");
    char op = '9';
    printf(VERMELHON "\n\t\tTermo\n\n1 - Iniciar o Jogo\n0 - Encerrar o codigo\n\n");
    
    do
    {
        printf(VERMELHO "Digite sua escolha para continuar: ");
        setbuf(stdin, NULL);
        scanf("%c", &op);

        if(op == '1')
        {
            detPalavra();
            Game();
            break;
        }
        else if(op != '0') printf("\nOpcao invalida. Tente novamente\n");

    } while (op != '0');

    printf("\nCodigo encerrado, tchau.\n");
    return 0;
}
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
