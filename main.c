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

    return 0;
}
