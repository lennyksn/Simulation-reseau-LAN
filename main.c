#include <stdio.h>
#include "reseau.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
    FILE* fichier = NULL;
    int score[2] = {0};
    size_t ports;
    size_t priorite;
    uint8_t mmac[6] = {0};
    uint8_t iipv4[4] = {0};
    char ligne[128];

    fichier = fopen("Ressources_Moodle/mylan_no_cycle.lan.txt", "r");

    if (fichier != NULL)
    {
        // On peut lire et écrire dans le fichier
        fscanf(fichier, "%d %d", &score[0], &score[1]);

        printf("Il y a %d équipement(s) pour le réseau et %d lien(s) pour les connecter\n", score[0], score[1]);

        fgets(ligne, sizeof(ligne), fichier);
        fgets(ligne, sizeof(ligne), fichier);

        // --- Lignes type 2 : switches ---
        do {
            if (ligne[0] != '2') break;
            // format : 2;XX:XX:XX:XX:XX:XX;nb_ports;priorite
            if (sscanf(ligne, "%*d;""%hhx:%hhx:%hhx:%hhx:%hhx:%hhx;""%ld;""%ld", &mmac[0], &mmac[1], &mmac[2], &mmac[3], &mmac[4], &mmac[5], &ports, &priorite) == 8) // ✅ mmac[5] ajouté                                         // ✅ & ajouté
            {
                mac addr_mac = {mmac[0], mmac[1], mmac[2], mmac[3], mmac[4], mmac[5]};
                printf("Adresse MAC : ");
                afficher_mac(&addr_mac);
                printf("Nombre de ports : %ld\n", ports);
                printf("Priorité : %ld\n", priorite);
                printf("\n");
            }
        } while (fgets(ligne, sizeof(ligne), fichier) != NULL && ligne[0] == '2');

        do {
            if (ligne[0] != '1') break; // sécurité
            // format : 1;XX:XX:XX:XX:XX:XX;ip
            if (sscanf(ligne,"%*d;""%hhx:%hhx:%hhx:%hhx:%hhx:%hhx;""%hhu.%hhu.%hhu.%hhu", &mmac[0], &mmac[1], &mmac[2], &mmac[3], &mmac[4], &mmac[5], &iipv4[0], &iipv4[1], &iipv4[2], &iipv4[3]) == 10)
            {
                mac addr_mc = {mmac[0], mmac[1], mmac[2], mmac[3], mmac[4], mmac[5]};
                printf("Adresse MAC : ");
                afficher_mac(&addr_mc);

                ipv4 addr_ipv4 = {iipv4[0], iipv4[1], iipv4[2], iipv4[3]};
                printf("Adresse IP : ");
                afficher_ipv4(&addr_ipv4);
                printf("\n");
            }
        } while (fgets(ligne, sizeof(ligne), fichier) != NULL && ligne[0] == '1');

        fclose(fichier);
    }
    else
    {
        // On affiche un message d'erreur si on veut
        printf("Impossible d'ouvrir le fichier test.txt");
    }

    ipv4 adresse = {192, 168, 1, 1};

    afficher_ipv4(&adresse);

    mac addr_mc = {180, 109, 131, 221, 206, 73};

    afficher_mac(&addr_mc);

    trame t1;

    t1.type[0] = 0x08;
    t1.type[1] = 0x00;

    printf("\n%d + %d\n", t1.type[0], t1.type[1]);
    
    afficher_trame_humain(&t1);

    return 0;
}
