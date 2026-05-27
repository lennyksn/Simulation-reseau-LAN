#include <stdio.h>
#include "reseau.h"
#include <stdlib.h>
#include <stdio.h>


int main()
{
    FILE* fichier = NULL;

    fichier = fopen("mylan_no_cycle.lan", "r");

    if (fichier != NULL)
    {
        // On peut lire et écrire dans le fichier
        int carac = fgetc(fichier);
        printf("%c", carac);

        carac = fgetc(fichier);
        printf("%c\n", carac);
        fclose(fichier);
    }
    else
    {
        // On affiche un message d'erreur si on veut
        printf("Impossible d'ouvrir le fichier test.txt");
    }

    mac mc1;

    mc1[0] = 15;
    mc1[1] = 19;
    mc1[2] = 11;
    mc1[3] = 26;
    mc1[4] = 26;
    mc1[5] = 13;

    afficher_mac(&mc1);

    return 0;
}
