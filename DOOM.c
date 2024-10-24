#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

int main() {
    int hp; // Premenná pre životy hráča
    char name[15]; // Premenná pre meno hráča
    char c; // Premenná pre voľbu hráča
    char odpoved[100]; // Premenná pre odpoveď na hádanku
    int end1 = 0, end2 = 0, end3 = 0, end4 = 0; // Premenné pre konce hry

    // Úvod do hry
    printf("Princip hry je dostat sa az na druhy koniec hory. Prechadzas cez tunel, ktory sa vetvi a ty si musis zvolit spravnu cestu.\n");
    printf("Na zaciatku si vyberas obtiaznost. Obtiaznost urcuje pocet tvoje pociatocne zivoty. Akonahle tvoje zivoty klesnu na 0 hra sa ukonci tvojou smrtou.\n");

    // Výber mena hráča
    printf("Ako sa volas?\n");
    scanf("%s", name);

    // Rozhodovanie, či chce hráč začať hru
    do {
        fflush(stdin);
        printf("\nStojis pred vstupom do dungeonu.\n");
        printf("Chces vojst? (a) ano (n) nie: ");
        c = getchar(); // Číta voľbu od hráča
        if (c == 'a') {
            printf("\nVstupil si do dungeonu\n");
        } else if(c == 'n'){
            printf("\nRozhodol si sa odist");
            end4 = 1;
        }
    } while (c != 'a' && c != 'n' && end4 != 1); // Opakuje, pokiaľ nie je zvolená platná voľba

    // Ak hráč vstúpil do dungeon
    if (c == 'a') {
        printf("Ahoj %s, vyber si obtiaznost.\n", name);
        printf("(e)easy\n(n)normal\n(h)hard\nTvoja volba: ");

        // Výber obtiažnosti a nastavenie životov
        do {
            fflush(stdin);
            c = getchar(); // Číta voľbu obtiažnosti
            switch (c) {
                case 'e':
                    hp = 10; // Nastavenie životov na 10 pre easy
                    printf("Mas %d hp.\n", hp);
                    break;
                case 'n':
                    hp = 6; // Nastavenie životov na 6 pre normal
                    printf("Mas %d hp.\n", hp);
                    break;
                case 'h':
                    hp = 3; // Nastavenie životov na 3 pre hard
                    printf("Mas %d hp.\n", hp);
                    break;
                default:
                    printf("Neexistujuca moznost.\n"); // Chybová hláška pre neplatnú voľbu
                    break;
            }
        } while (c != 'e' && c != 'n' && c != 'h'); // Opakuje, pokiaľ nie je zvolená platná obtiažnosť

        // Hráč si vyberá medzi dvoma tunelmi
        printf("\nMas pred sebou dva tunely");
        do {
            printf("\nVyber si tunel \n(a)\n(b)\n");
            printf("Tvoja odpoved: ");
            do {
                fflush(stdin);
                c = getchar(); // Číta voľbu tunela
            } while (c != 'a' && c != 'b'); // Kontrola platnej voľby

            if (c == 'a') {
                printf("\nCesta je zatarasena\nMusis sa vratit.\n"); // Správa ak zvolený tunel je zatarasený
            }
        } while (c != 'b'); // Opakuje, pokiaľ nie je zvolený správny tunel

        // Rozvetvenie tunela
        printf("\nAko postupujes hlbsie, tunel sa rovetvuje");
        printf("\nVidis tri tunely, ktore vyzeraju uplne rovnako");
        
        // Výber medzi tromi tunelmi
        do {
            printf("\nVyber si tunel:\n(a)\n(b)\n(c)\n");
            printf("Tvoja odpoved: ");
            do {
                fflush(stdin);
                c = getchar(); // Číta voľbu tunela
            } while (c != 'a' && c != 'b' && c != 'c');

            if (c == 'a') {
                hp--; // Odoberie 1 hp za pascu
                printf("Ako si vosiel do tunelu, spustila sa pasca a ubrala ti zivot\n");
                if (hp > 0) {
                    printf("V tom momente si sa vratil.\nOstava ti %dhp\n", hp); // Informuje o zostatku hp
                }
                
            }
           
        } while (c != 'b' && c != 'c' && hp != 0); // Kontrola pre zánik
if(hp!=0){ 
        // Ak hráč prežil
        if (hp != 0) { 
            if (c == 'b') { // Ak sa zvolil druhý tunel
                printf("Pred sebou mas dalsie dva tunely.");
                do {
                    printf("\nVyber si tunel\n(a)\n(b)\n"); // Výber medzi dvoma tunelmi
                    printf("Tvoja odpoved: ");
                    do {
                        fflush(stdin);
                        c = getchar(); // Číta voľbu tunela
                    } while (c != 'a' && c != 'b');

                    if (c == 'a') { // Ak hráč zvolí nebezpečný tunel
                        printf("\nTunel do ktoreho si vosiel vyzeral nebezpecne. Po chvilke zacali padat kusy kamenia zo stropu.\nJeden kus ti padol na hlavu a ubral ti zivot.\n");
                        hp--; // Odoberie 1 hp
                        if (hp == 0) {
                            printf("Zomrel si na otras mozgu"); // Správa o smrti
                        } else {
                            printf("Ihned si sa vratil.\nOstava ti %dhp\n", hp); // Informuje o zostatku hp
                        }
                    }
                } while (c != 'b' && hp > 0); // Kontrola pre zánik
            } else if (c == 'c') { // Ak sa zvolí tretí tunel
                do {
                    printf("\nVyber si tunel:\n(a)\n(b)\n(c)\n");
                    printf("Tvoja odpoved: "); // Výber tunela
                    do {
                        fflush(stdin);
                        c = getchar(); // Číta voľbu tunela
                    } while (c != 'a' && c != 'b' && c != 'c');

                    if (c == 'c') { // Ak hráč zvolí nebezpečný tunel
                        hp--; // Odoberie 1 hp
                        printf("\nPo tom ako si vosiel do tunelu, ucitil si stiplavy smrad ktory ti ubral 1hp.\n");
                        if (hp != 0) {
                            printf("Po chvilke si sa radsej vratil.\nOstava ti %dhp\n", hp); // Informuje o zostatku hp
                        } else {
                            printf("Zomrel si na otravu trolim prdom.\n"); // Správa o smrti
                            end4 = 1;
                        }
                    } else if (c == 'a') {
                        printf("Zabila ta skupinka goblinov.\n"); // Správa o smrti
                        end1 = 1; // Označuje koniec hry
                    }
                } while (c != 'b' && hp != 0 && end1 != 1); // Kontrola pre zánik
            }

            // Ak hráč prežil a nebol zabitý goblinmi
            if (hp != 0 && end1 != 1) {
                do {
                    printf("Chces ist hore alebo dole? [h/d]\n");
                    printf("Tvoja odpoved: ");
                    do {
                        fflush(stdin);
                        c = getchar(); // Číta voľbu
                    } while (c != 'h' && c != 'd');
                    
                    if (c == 'h') { // Ak hráč ide hore
                        do {
                            printf("Dosiel si na vyssie podlazie, kde sa nachadzaju dvaja goblini.\n");
                            do {
                                printf("Chces sa vratit alebo bojovat? [u/b]\n");
                                fflush(stdin);
                                c = getchar(); // Číta voľbu
                            } while (c != 'u' && c != 'b');
                            
                            if (c == 'b') { // Ak hráč sa rozhodol bojovať
                                if (hp == 1)//Ak hrac ma 1hp prida sa 1 aby vysledok bol rovny 0
                                {
                                    hp++;
                                }
                                printf("Porazil si goblinov.\nPri boji si utrpel zranenie -2hp\n");
                                hp -= 2; // Odoberie 2 hp
                                if (hp <= 0) {
                                    printf("Zomrel si na zranenie.\n"); // Správa o smrti
                                    break; 
                                } else {
                                    printf("Mas %dhp\n", hp); // Informuje o zostatku hp
                                    break; 
                                } if (c == 'u') { // Ak sa hráč rozhodol utiecť
                                printf("Rozhodol si sa utiect.\n");
                                c = 'b'; // Zmení voľbu, aby sa vyhol ďalšiemu výberu
                            }
                            }  
                        } while (c != 'd' && hp != 0 && c != 'u' && c != 'b');
                    } 
                    
                    else if (c == 'd') { // Ak hráč ide dole
                        printf("Prisiel si do nizsieho podlazia. Obrovska miestnost z ktorej vedu dve cesty, avsak obe su zablokovane hrubymi mrezami.\n");
                        printf("V strede miestnosti su dve packy.\n");
                        printf("Vyber si jednu a zatiahni za nu.\n");
                        printf("(a)\n(b)\nTvoja volba: ");
                        do {
                            fflush(stdin);
                            c = getchar(); // Číta voľbu
                        } while (c != 'a' && c != 'b'); 
                        if(c == 'a'){
                            printf("\nMreze sa otvorili a ty postupujes dalej.\n"); // Správa o otvorení mriežok
                        } else if(c == 'b'){
                            printf("Otvorili sa mreze spoza ktorych na teba vyskakuje goblin.\n");
                            printf("Podarilo sa ti ho zneskodnit avsak prichadzas o 1hp\n");
                            hp--; // Odoberie 1 hp
                            printf("Ostava ti %dhp\n", hp); // Informuje o zostatku hp
                        }
                    }

                } while (c != 'd' && hp != 0 && c != 'b' && c != 'a');
            }

            // Hlavná hádanka s Gollumom
            if (hp != 0 && end1 != 1) {
                printf("\nPred tebou je gollum ktory ti dava hadanku:\n");
                printf("Korene ma ukryte v zemi,\nvypina sa nad jedlami,\nstupa stale vyssie a vyssie,\nale rast ju nevidis.\n");
                do {
                    printf("\nTvoja odpoved? ");
                    scanf("%s", odpoved); // Číta odpoveď na hádanku

                    if (strcmp(odpoved, "hora") != 0) { // Ak odpoveď nie je správna
                        hp--; // Odoberie 1 hp
                        if (hp > 0) {
                            printf("\nGollum po tebe hodil kamen a ubral ti 1hp. Ostava ti %d hp\n", hp); // Informuje o zostatku hp
                        }
                        end3 = 1; // Označuje koniec
                    }
                } while (strcmp(odpoved, "hora") != 0 && hp != 0); // Opakuje, pokiaľ nie je odpoveď správna alebo hráč nezomrie
                
                // Kontrola víťazstva alebo smrti
                if (hp != 0 && strcmp(odpoved, "hora") == 0) {
                    end2 = 1; // Označuje úspešný koniec hry
                    printf("Dostal si sa na cez horu zivy. Gratulujeme k uspesnemu koncu hry\n");
                } else if (hp == 0 && end3 == 1) {
                    printf("Gollum ta presnym hodom kamena omracil a odtiahol do tmavej miestnosti kde cakas na smrt.\n"); // Správa o smrti
                }   
}     
            
}
}   
        
    }if(end4!=1 && end1 != 1 && end3 != 1) {
        printf("Zomrel si, skus stastie nabuduce."); // Správa o smrti pred vstupom do dungeon
    }
    return 0; // Konec programu
}