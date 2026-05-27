#include "reseau.h"
#include <stdlib.h>
#include <stdio.h>

void afficher_ipv4(ipv4 *addr)
{
    for(size_t i = 0; i < 4; i++)
    {
        printf("%u", (*addr)[i]);

        if(i < 3)
        {
            printf(".");
        }
    }

    printf("\n");
}

void afficher_station(station *st)
{

}

void afficher_switch(sw *sw)
{

}
