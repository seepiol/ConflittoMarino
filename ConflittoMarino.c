/**
* CONFLITTO MARINO
* 04/06/2019
*
* Programma che simula uno scontro marino, ispirato al gioco battaglia navale
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

main(){
    // Var locali
    int player_ship1, player_ship2, player_ship3, player_ship4;    // Var navi giocatore
    int pc_ship1, pc_ship2, pc_ship3, pc_ship4;    // Var navi pc
    int player_attack;    // Var posizione attacco giocatore
    int pc_attack;    // Var posizione attacco pc
    int colpiti;    // Contatore navi nemiche colpite dal giocatore
    int colpitipc;    // Cont. navi nemiche colpite dal pc
    int vintiplayer=0;    // contatore partite vinte da giocatore
    int vintipc=0;    // Contatore partite vinte da pc
    int continua;

    do{
        // Reset variabili
        char* sea_grid[36] = {"0 ", "1 ", "2 ", "3 ", "4 ", "5 ", "6 ", "7 ", "8 ", "9 ", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "30", "31", "32", "33", "34", "35", "\0"};    // Array per griglia posizionamento navi giocatore
        char* sea_grid_attack[36] = {"0 ", "1 ", "2 ", "3 ", "4 ", "5 ", "6 ", "7 ", "8 ", "9 ", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "30", "31", "32", "33", "34", "35", "\0"};    // Array per griglia di attacco giocatore
        char* player_pos[4];
        char* pc_pos[4];
        char* player_select[36];
        char* pc_select[36];

        // navi giocatore
        player_ship1=0;
        player_ship2=0;
        player_ship3=0;
        player_ship4=0;
        player_attack=0;

        // navi pc
        pc_ship1=0;
        pc_ship2=0;
        pc_ship3=0;
        pc_ship4=0;
        pc_attack=0;

        // contatori
        colpiti=0;
        colpitipc=0;

        system("cls");
        srand(time(NULL));

        // banner e regole
        printf("================================================================================\n");
        printf("|                                      __/___                                  |\n");
        printf("|                                _____/______|                                 |\n");
        printf("|                        _______/_____\\_______\\_____                           |\n");
        printf("|                        \\              < < <       |                          |\n");
        printf("|                     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~                       |\n");
        printf("|     ______            _______ __  __        __  ___           _              |\n");
        printf("|    / ____/___  ____  / __/ (_) /_/ /_____  /  |/  /___ ______(_)___  ____    |\n");
        printf("|   / /   / __ \\/ __ \\/ /_/ / / __/ __/ __ \\/ /|_/ / __ `/ ___/ / __ \\/ __ \\   |\n");
        printf("|  / /___/ /_/ / / / / __/ / / /_/ /_/ /_/ / /  / / /_/ / /  / / / / / /_/ /   |\n");
        printf("|  \\____/\\____/_/ /_/_/ /_/_/\\__/\\__/\\____/_/  /_/\\__,_/_/  /_/_/ /_/\\____/    |\n");
        printf("|                                                                              |\n");
        printf("================================================================================\n");
        printf("|   REGOLE                                                                     |\n");
        printf("| - Hai a disposizione 4 navi                                                  |\n");
        printf("| - Ogni nave occupa uno spazio                                                |\n");
        printf("| - Il reticolo e' una griglia 6X6                                             |\n");
        printf("| - [X] = Navi giocatore posizionate                                           |\n");
        printf("| - [+] = Nave nemica affondata                                                |\n");
        printf("| - [-] = Nave nemica mancata                                                  |\n");
        printf("================================================================================\n\n\n");

        // Visualizzazione griglia di posizionamento navi utente vuota
            printf("\n\n================================================================================\n");
            printf("|                       POSIZIONAMENTO NAVI GIOCATORE                          |\n");
            printf("|                                                                              |\n");
            printf("|                         -------------------------                            |\n");
            printf("|                         |%s |%s |%s |%s |%s |%s |                            |\n", sea_grid[30], sea_grid[31], sea_grid[32], sea_grid[33], sea_grid[34], sea_grid[35]);
            printf("|                         |---|---|---|---|---|---|                            |\n");
            printf("|                         |%s |%s |%s |%s |%s |%s |                            |\n", sea_grid[24], sea_grid[25], sea_grid[26], sea_grid[27], sea_grid[28], sea_grid[29]);
            printf("|                         |---|---|---|---|---|---|                            |\n");
            printf("|                         |%s |%s |%s |%s |%s |%s |                            |\n", sea_grid[18], sea_grid[19], sea_grid[20], sea_grid[21], sea_grid[22], sea_grid[23]);
            printf("|                         |---|---|---|---|---|---|                            |\n");
            printf("|                         |%s |%s |%s |%s |%s |%s |                            |\n", sea_grid[12], sea_grid[13], sea_grid[14], sea_grid[15], sea_grid[16], sea_grid[17]);
            printf("|                         |---|---|---|---|---|---|                            |\n");
            printf("|                         |%s |%s |%s |%s |%s |%s |                            |\n", sea_grid[6], sea_grid[7], sea_grid[8], sea_grid[9], sea_grid[10], sea_grid[11]);
            printf("|                         |---|---|---|---|---|---|                            |\n");
            printf("|                         |%s |%s |%s |%s |%s |%s |                            |\n", sea_grid[0], sea_grid[1], sea_grid[2], sea_grid[3], sea_grid[4], sea_grid[5]);
            printf("|                         -------------------------                            |\n");
            printf("|                                                                              |\n");
            printf("================================================================================\n\n\n");

        // Input posizione navi utente

        //nave 1
        do{
            printf("Inserisci la posizione della tua prima nave<1-6>: ");
            scanf("%d", &player_ship1);
        }while(player_ship1<0||player_ship1>35);
        sea_grid[player_ship1]="X ";
        player_pos[0]=player_ship1;

        printf("\n");

        //nave 2
        do{
            printf("Inserisci la posizione della tua seconda nave<1-6>: ");
            scanf("%d", &player_ship2);
            if(player_ship2 == player_pos[0]){
                player_ship2 = -1;
            }
        }while(player_ship2<0||player_ship2>35);
        sea_grid[player_ship2]="X ";
        player_pos[1]=player_ship2;

        printf("\n");

        //nave 3
        do{
            printf("Inserisci la posizione della tua terza nave<1-6>: ");
            scanf("%d", &player_ship3);
            if(player_ship3 == player_pos[0] || player_ship3 == player_pos[1]){
                player_ship3 = -1;
            }
        }while(player_ship3<0||player_ship3>35);
        sea_grid[player_ship3]="X ";
        player_pos[2]=player_ship3;

        printf("\n");

        //nave 4
        do{
            printf("Inserisci la posizione della tua quarta nave<1-6>: ");
            scanf("%d", &player_ship4);
            if(player_ship4 == player_pos[0] || player_ship4 == player_pos[1] || player_ship4 == player_pos[2]){
                player_ship4 = -1;
            }
        }while(player_ship4<0||player_ship4>35);
        sea_grid[player_ship4]="X ";
        player_pos[3]=player_ship4;

        system("cls");

        // Visualizzazione griglia di posizionamento navi utente completa
            printf("================================================================================\n");
            printf("|                       POSIZIONAMENTO NAVI GIOCATORE                          |\n");
            printf("|                                                                              |\n");
            printf("|                         -------------------------                            |\n");
            printf("|                         |%s |%s |%s |%s |%s |%s |                            |\n", sea_grid[30], sea_grid[31], sea_grid[32], sea_grid[33], sea_grid[34], sea_grid[35]);
            printf("|                         |---|---|---|---|---|---|                            |\n");
            printf("|                         |%s |%s |%s |%s |%s |%s |                            |\n", sea_grid[24], sea_grid[25], sea_grid[26], sea_grid[27], sea_grid[28], sea_grid[29]);
            printf("|                         |---|---|---|---|---|---|                            |\n");
            printf("|                         |%s |%s |%s |%s |%s |%s |                            |\n", sea_grid[18], sea_grid[19], sea_grid[20], sea_grid[21], sea_grid[22], sea_grid[23]);
            printf("|                         |---|---|---|---|---|---|                            |\n");
            printf("|                         |%s |%s |%s |%s |%s |%s |                            |\n", sea_grid[12], sea_grid[13], sea_grid[14], sea_grid[15], sea_grid[16], sea_grid[17]);
            printf("|                         |---|---|---|---|---|---|                            |\n");
            printf("|                         |%s |%s |%s |%s |%s |%s |                            |\n", sea_grid[6], sea_grid[7], sea_grid[8], sea_grid[9], sea_grid[10], sea_grid[11]);
            printf("|                         |---|---|---|---|---|---|                            |\n");
            printf("|                         |%s |%s |%s |%s |%s |%s |                            |\n", sea_grid[0], sea_grid[1], sea_grid[2], sea_grid[3], sea_grid[4], sea_grid[5]);
            printf("|                         -------------------------                            |\n");
            printf("|                                                                              |\n");
            printf("================================================================================\n\n");


        // Posizionamento navi computer
        printf("================================================================================\n");
        printf("|                         POSIZIONAMENTO NAVI COMPUTER                         |\n");
        printf("================================================================================\n\n");

        // Selezione di una posizione random

        pc_ship1=rand() %35;
        pc_pos[0]=pc_ship1;

        do{
            pc_ship2=rand() %35;
        }while(pc_pos[0]==pc_ship2);
        pc_pos[1]=pc_ship2;

        do{
            pc_ship3=rand() %35;
        }while(pc_pos[0]==pc_ship3 || pc_pos[1]==pc_ship3);
        pc_pos[2]=pc_ship3;

        do{
            pc_ship4=rand() %35;
        }while(pc_pos[0]==pc_ship4 || pc_pos[1]==pc_ship4 || pc_pos[2]==pc_ship4);

        printf("\nPOSIZIONAMENTO COMPLETATO\n\n");

        system("pause");
        system("cls");


        // Inizio partita
        printf("================================================================================\n");
        printf("|                                  PARTITA AVVIATA                             |\n");
        printf("================================================================================");

        do{
            // utente

            if(colpiti==4||colpitipc==4){    // verifica navi rimanenti
                break;
            }else{
            printf("\n\nE' IL TUO TURNO \n");

            // Visualizzazione griglia di attacco giocatore e statistiche
            printf("================================================================================\n");
            printf("|                       POSIZIONAMENTO NAVI GIOCATORE     | Partite vinte: %d   |\n", vintiplayer);
            printf("|                                                         | Partite perse: %d   |\n", vintipc);
            printf("|                         -------------------------       | Partite Tot: %d     |\n", vintiplayer+vintipc);
            printf("|                         |%s |%s |%s |%s |%s |%s |       | Navi pc rimaste:%d  |\n", sea_grid_attack[30], sea_grid_attack[31], sea_grid_attack[32], sea_grid_attack[33], sea_grid_attack[34], sea_grid_attack[35], 4-colpiti);
            printf("|                         |---|---|---|---|---|---|       | Nav.gioc rimaste:%d |\n", 4-colpitipc);
            printf("|                         |%s |%s |%s |%s |%s |%s |                            |\n", sea_grid_attack[24], sea_grid_attack[25], sea_grid_attack[26], sea_grid_attack[27], sea_grid_attack[28], sea_grid_attack[29]);
            printf("|                         |---|---|---|---|---|---|                            |\n");
            printf("|                         |%s |%s |%s |%s |%s |%s |                            |\n", sea_grid_attack[18], sea_grid_attack[19], sea_grid_attack[20], sea_grid_attack[21], sea_grid_attack[22], sea_grid_attack[23]);
            printf("|                         |---|---|---|---|---|---|                            |\n");
            printf("|                         |%s |%s |%s |%s |%s |%s |                            |\n", sea_grid_attack[12], sea_grid_attack[13], sea_grid_attack[14], sea_grid_attack[15], sea_grid_attack[16], sea_grid_attack[17]);
            printf("|                         |---|---|---|---|---|---|                            |\n");
            printf("|                         |%s |%s |%s |%s |%s |%s |                            |\n", sea_grid_attack[6], sea_grid_attack[7], sea_grid_attack[8], sea_grid_attack[9], sea_grid_attack[10], sea_grid_attack[11]);
            printf("|                         |---|---|---|---|---|---|                            |\n");
            printf("|                         |%s |%s |%s |%s |%s |%s |                            |\n", sea_grid_attack[0], sea_grid_attack[1], sea_grid_attack[2], sea_grid_attack[3], sea_grid_attack[4], sea_grid_attack[5]);
            printf("|                         -------------------------                            |\n");
            printf("|                                                                              |\n");
            printf("================================================================================\n\n");

            // Inserimento
            do{
                printf("Inserisci la posizione: ");
                scanf("%d", &player_attack);
            }while(player_attack<0||player_attack>35);
            //TODO array per evitare ripetizioni

            if(player_attack==pc_ship1||player_attack==pc_ship2||player_attack==pc_ship3||player_attack==pc_ship4){    // Bersaglio colpito
                printf("\nBERSAGLIO AFFONDATO\n");
                sea_grid_attack[player_attack]="+ ";
                colpiti=colpiti+1;
                system("pause");

            }else{
                printf("\nMANCATO\n");    // Bersaglio non colpito
                sea_grid_attack[player_attack]="- ";
                system("pause");
            }
            }


            // computer

            if(colpiti==4||colpitipc==4){    // verifica navi rimanenti
                break;
            }else{
            printf("\n\nE' IL TURNO DELL'AVVERSARIO\n");
            pc_attack=rand() %35;    // generazione di una posizione di attacco random
            //TODO array per evitare ripetizioni

            if(pc_attack==player_ship1||pc_attack==player_ship2||pc_attack==player_ship3||pc_attack==player_ship4){
                printf("\nBERSAGLIO AFFONDATO\n");
                colpitipc=colpitipc+1;
                system("pause");
                system("cls");
            }else{
                printf("\nMANCATO\n");
                system("pause");
                system("cls");
            }
            }

        }while(colpiti<4||colpitipc<4);

        // giocatore elimina tutte le navi del pc (4)
        if(colpiti==4){
            printf("\n\n================================================================================\n");
            printf("|                                   HAI VINTO!!!                               |\n");
            printf("================================================================================\n\n");
            vintiplayer=vintiplayer+1;    // Incremento contatore

         // Pc elimina tutte le navi del giocatore
        }else if(colpitipc==4){
            printf("\n\n================================================================================\n");
            printf("|                                   HAI PERSO!!!                               |\n");
            printf("================================================================================\n\n");
            vintipc=vintipc+1;    // Incremento contatore
        }else{
            printf("\n[X]ERRORE\n");
        }

        // Richiesta restart
        do{
            printf("Premi '1' per giocare ancora, '0' per uscire: ");
            scanf("%d", &continua);
        }while(continua<0||continua>1);

        // Visualizzazione Risultato partite
        printf("\n\n================================================================================\n");
        printf("|                     GIOCATORE: [%d]  COMPUTER: [%d]                           |\n", vintiplayer, vintipc);
        printf("================================================================================\n\n");
        system("pause");



    }while(continua==1);


}
