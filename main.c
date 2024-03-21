#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void etichetta()
{
    printf("              ");
    printf("+++++++++++++++++++++++++");
    printf("\n");
    printf("              ");
    printf("+");
    printf("                       ");
    printf("+");
    printf("\n");
    printf("              ");
    printf("+");
    printf("        ");
    printf("FORZA 4");
    printf("        ");
    printf("+");
    printf("\n");
    printf("              ");
    printf("+");
    printf("                       ");
    printf("+");
    printf("\n");
    printf("              ");
    printf("+++++++++++++++++++++++++");
    printf("\n\n");
}
int colonnacomputer()
{
    int colonna,n=0;
    srand(time(NULL));
    while(n==0)
    {
        colonna=rand();
        if(colonna>=0&&colonna<=6)
        {
            return colonna;
        }
    }
    return -1;
}
void drawboard(int board[6][7])
{
    /*se valore matrice � 0 allora casella vuota
    se valore matrice � 1 allora simbolo giocatore 1
    se valore matrice � 2 allora simbolo giocatore 2*/
    printf("  0   1   2   3   4   5   6");
    for(int i=0;i<6;i++)
    {
        printf("\n --- --- --- --- --- --- --- \n|");
        for(int j=0;j<7;j++)
        {
            switch (board[i][j])
         {
            case 1:
                    printf(" X |");
                    break;
            case 2:
                    printf(" O |");
                    break;
               case 0 :
                       printf("   |");
                       break;
            }
        }
    }
    printf("\n --- --- --- --- --- --- --- \n");
    return;
}
void istruzioni()
{
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    etichetta();
    printf("\n\nForza 4 e'un gioco di allineamento su una matrice di 6 righe e 7 colonne.\nL'obiettivo del gioco e' mettere in fila (orizzontale, verticale o diagonale)\n4 delle proprie pedine; l'elemento fondamentale del gioco, che lo rende del\ntutto originale, e' la forza di gravita': la scacchiera\ne' posta in verticale e le pedine vengono fatte cadere lungo\nun'asse verticale in modo tale che una pedina inserita in una certa colonna\nva sempre a occupare la posizione libera situata piu' in basso nella colonna\nstessa.\nSara' richiesto di inserire una colonna alla volta alternando il turno del\ngiocatore 1, contrassegnato dal simbolo X e il turno del giocatore 2\ncontrassegnato dal simbolo O.\nNel caso in cui la matrice risulti completa quindi senza spazi vuoti e nessuno\ndei due giocatori e' riuscito a posizionare quattro delle proprie pedine\nin fila in colonna o in diagonale,\nla partita terminera'in pareggio.\n\n\n");
}
int giocata(int board[6][7],int turno,char giocatore[50])
{
    int colonna,cont=-1,i=1;
    printf("\n Turno di %s: inserire colonna da 0 a 6 e premi invio: ",giocatore);
    do
    {
        cont++;
        if(cont>0)
        {
            printf("\n Inserire altra colonna: ");
        }
        scanf("%d",&colonna);
        printf("\n");
    }while(colonna<0||colonna>6||board[0][colonna]!=0);
    cont=-1;
    while(i<6&&board[i][colonna]==0)
    {
        i=i+1;
    }
    board[i-1][colonna]=turno;
    return colonna;
}
int giocatacomputer(int board[6][7],int turno,char computer[9])
{
    int colonna=-1,i=1;
        srand(time(NULL));
    do
    {
     colonna=colonnacomputer();
    printf("\n");
    }while(board[0][colonna]!=0);
    while(i<6&&board[i][colonna]==0)
    {
        i=i+1;
    }
    board[i-1][colonna]=turno;
    return colonna;
}
void inizializzaBoard(int board[6][7])
{
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<7;j++)
        {
            board[i][j]=0;          /*0=vuoto*/
        }
    }
}
int verificaboard(int board[6][7],int turno,int colonna)
{
    int cont=0,riga=0,somma,differenza,i,m;
    while(board[riga][colonna]==0)
    {
        riga=riga+1;
    }
        for(int j=0;j<6;j++)                       /*scorre la colonna verticale*/
        {
            if(board[j][colonna]==turno)
                {
                    cont=cont+turno;
                    if(turno==1&&cont==4||turno==2&&cont==8)
                    {
                        return 1;
                    }
                }
                else
                {
                    cont=0;
                }
        }
        cont=0;
        for(int j=0;j<7;j++)                        /*scorre riga orizzonatele*/
        {
            if(board[riga][j]==turno)
                {
                    cont=cont+turno;
                    if(turno==1&&cont==4||turno==2&&cont==8)
                    {
                        return 1;
                    }
                }
                else
                {
                    cont=0;
                }
        }
        cont=0;
        somma=colonna+riga;
        switch(somma)                                 /*verifico diagonale da basso a sinistra a alto a destra*/
        {                                             /*i scorre le righe m scorre le colonne*/
            case 3:
                    m=0;
                    for(int i=3;i>=0;i--)
                    {
                            if(board[i][m]==turno)
                            {
                                cont=cont+turno;
                                if(turno==1&&cont==4||turno==2&&cont==8)
                                {
                                    return 1;
                                }
                            }
                            else
                            {
                                cont=0;
                            }
                        m=m+1;
                    }
                    break;
            case 4:
                m=0;
                    for(int i=4;i>=0;i--)
                    {
                            if(board[i][m]==turno)
                            {
                                cont=cont+turno;
                                if(turno==1&&cont==4||turno==2&&cont==8)
                                {
                                    return 1;
                                }
                            }
                            else
                            {
                                cont=0;
                            }
                        m=m+1;
                    }
                    break;
            case 5:
                    m=0;
                    for(int i=5;i>=0;i--)
                    {
                        
                            if(board[i][m]==turno)
                            {
                                cont=cont+turno;
                                if(turno==1&&cont==4||turno==2&&cont==8)
                                {
                                    return 1;
                                }
                            }
                            else
                            {
                                cont=0;
                            }
                            m=m+1;
                    }
                    break;
            case 6:
                    i=0;
                    for(int m=6;m>=1;m--)
                    {
                        
                            if(board[i][m]==turno)
                            {
                                cont=cont+turno;
                                if(turno==1&&cont==4||turno==2&&cont==8)
                                {
                                    return 1;
                                }
                            }
                            else
                            {
                                cont=0;
                            }
                        i=i+1;
                    }
                    break;
            case 7:
                    i=1;
                    for(int m=6;m>=2;m--)
                    {
                            if(board[i][m]==turno)
                            {
                                cont=cont+turno;
                                if(turno==1&&cont==4||turno==2&&cont==8)
                                {
                                    return 1;
                                }
                            }
                            else
                            {
                                cont=0;
                            }
                        i=i+1;
                    }
                    break;
            case 8:
                    i=2;
                    for(int m=6;m>=3;m--)
                    {
                            if(board[i][m]==turno)
                            {
                                cont=cont+turno;
                                if(turno==1&&cont==4||turno==2&&cont==8)
                                {
                                    return 1;
                                }
                            }
                            else
                            {
                                cont=0;
                            }
                        i=i+1;
                    }
                    break;
                    
        }
        cont=0;
        differenza=riga-colonna;
        switch(differenza)                                 /*verifico diagonale da alto a sinistra a basso a destra*/
        {
            case 2:
                    m=0;
                    for(int i=2;i<=5;i++)
                    {
                            if(board[i][m]==turno)
                            {
                                cont=cont+turno;
                                if(turno==1&&cont==4||turno==2&&cont==8)
                                {
                                    return 1;
                                }
                            }
                            else
                            {
                                cont=0;
                            }
                        m=m+1;
                    }
                    break;
            case 1:
                    m=0;
                    for(int i=1;i<=5;i++)
                    {
                            if(board[i][m]==turno)
                            {
                                cont=cont+turno;
                                if(turno==1&&cont==4||turno==2&&cont==8)
                                {
                                    return 1;
                                }
                            }
                            else
                            {
                                cont=0;
                            }
                        m=m+1;
                    }
                    break;
            case 0:
                    m=0;
                    for(int i=0;i<=5;i++)
                    {
                            if(board[i][m]==turno)
                            {
                                cont=cont+turno;
                                if(turno==1&&cont==4||turno==2&&cont==8)
                                {
                                    return 1;
                                }
                            }
                            else
                            {
                                cont=0;
                            }
                        m=m+1;
                    }
                    break;
            case -1:
                    i=0;
                    for(int m=1;m<=6;m++)
                    {
                            if(board[i][m]==turno)
                            {
                                cont=cont+turno;
                                if(turno==1&&cont==4||turno==2&&cont==8)
                                {
                                    return 1;
                                }
                            }
                            else
                            {
                                cont=0;
                            }
                        i=i+1;
                    }
                    break;
            case -2:
                    i=0;
                    for(int m=2;m<=6;m++)
                    {
                            if(board[i][m]==turno)
                            {
                                cont=cont+turno;
                                if(turno==1&&cont==4||turno==2&&cont==8)
                                {
                                    return 1;
                                }
                            }
                            else
                            {
                                cont=0;
                            }
                        i=i+1;
                    }
                    break;
            case -3:
                    i=0;
                    for(int m=3;m<=6;m++)
                    {
                            if(board[i][m]==turno)
                            {
                                cont=cont+turno;
                                if(turno==1&&cont==4||turno==2&&cont==8)
                                {
                                    return 1;
                                }
                            }
                            else
                            {
                                cont=0;
                            }
                        i=i+1;
                    }
                    break;
        }
        for(int j=0;j<6;j++)                       /*verifica se nella prima riga ci sono caselle vuote e stabilisce se la partita termina in parit�*/
        {
            if(board[0][j]==0)
            {
                return -1;
            }
        }
        return 0;
}
main()
{
    int board[6][7],vittoria=-1,turno=1,gioca=0,win=-1,colonna,variabileistruzioni,scelta;
    char giocatore1[50],giocatore2[50],computer[9]="computer";
    while(gioca==0)
    {
        etichetta();
        printf(" Se vuoi giocare contro un avversario premi 0 ed invio: \n Se vuoi giocare contro il computer premi 1 ed invio: ");
        scanf("%d",&scelta);
        if(scelta==0)
        {
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        inizializzaBoard(board);
        etichetta();
        printf(" Se si desidera leggere le istruzioni del gioco, premi 0 e invio\n altrimenti, se vuoi iniziare subito a giocare premi 1 e invio.\n");
        while(variabileistruzioni!=0&&variabileistruzioni!=1)
        {
        printf(" inserisci 0 o 1:");
        scanf("%d",&variabileistruzioni);
        }
        if(variabileistruzioni==0)
        {
            istruzioni();
        }
        else
        {
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            etichetta();
        }
        printf(" Il giocatore 1 inserisca il suo nome: ");
        scanf("%s",&giocatore1);
        printf("\n");
        printf(" Il giocatore 2 inserisca il suo nome: ");
        scanf("%s",&giocatore2);
        printf("\n");
        while(vittoria<0)
        {
            drawboard(board);
            if(turno==1)
            {
                colonna=giocata(board,turno,giocatore1);
            }
            else
            {
                colonna=giocata(board,turno,giocatore2);
            }
            vittoria=verificaboard(board,turno,colonna);
            if(vittoria<0)
            {
                if(turno%2==0)
                {
                    turno--;
                }
                else
                {
                    turno++;
                }
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                etichetta();
            }
        }
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        etichetta();
        drawboard(board);
        if(vittoria==0)
        {
            printf("\n\n La partita e' terminata in Pareggio \n");           /*la funzione verificaboard risponde vittoria=0 se la partita � terminata in un pareggio da parte di uno dei due giocatori*/
        }
        else
        {
            if(turno==1)
            {
                printf("\n\n %s ha VINTO \n\n\n",giocatore1);        /*la funzione verificaboard risponde vittoria=1 se la partita � terminata in una vittoria da parte di uno dei due giocatori*/
            }
            else
            {
                printf("\n\n %s ha VINTO \n\n\n",giocatore2);
            }
        }
        }
        else
        {
        inizializzaBoard(board);
        etichetta();
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        etichetta();
        printf(" Se si desidera leggere le istruzioni del gioco, premi 0 e invio\n altrimenti, se vuoi iniziare subito a giocare premi 1 e invio:\n");
        while(variabileistruzioni!=0&&variabileistruzioni!=1)
        {
        printf(" inserisci 0 o 1:");
        scanf("%d",&variabileistruzioni);
        }
        if(variabileistruzioni==0)
        {
            istruzioni();
        }
        else
        {
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            etichetta();
        }
        printf(" Il giocatore 1 inserisca il suo nome: ");
        scanf("%s",&giocatore1);
        printf("\n");
        while(vittoria<0)
        {
            drawboard(board);
            if(turno==1)
            {
                colonna=giocata(board,turno,giocatore1);
            }
            else
            {
                colonna=giocatacomputer(board,2,computer);
            }
            vittoria=verificaboard(board,turno,colonna);
            if(vittoria<0)
            {
                if(turno%2==0)
                {
                    turno--;
                }
                else
                {
                    turno++;
                }
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                etichetta();
            }
        }
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        etichetta();
        drawboard(board);
        if(vittoria==0)
        {
            printf("\n\n La partita e' terminata in Pareggio \n");           /*la funzione verificaboard risponde vittoria=0 se la partita � terminata in una vittoria da parte di uno dei due giocatori*/
        }
        else
        {
            if(turno==1)
            {
                printf("\n\n %s ha VINTO \n\n\n",giocatore1);        /*la funzione verificaboard risponde vittoria=1 se la partita � terminata in una vittoria da parte di uno dei due giocatori*/
            }
            else
            {
                printf("\n\n %s ha VINTO \n\n\n",computer);
            }
        }
        }
        
    printf(" Per giocare ancora premi 0 ed invio.\n Se vuoi uscire premi 1 ed invio.\n");
    gioca=-1;
    while(gioca!=0&&gioca!=1)
    {
        printf("\n inserisci 0 o 1:");
        scanf("%d",&gioca);
        printf("\n");
    }
    vittoria=-1;
    variabileistruzioni=1;
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    }
}
