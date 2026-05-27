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

void afficher_mac(mac *addr)
{

}

void afficher_station(station *st)
{

}

void afficher_switch(sw *sw)
{

}

void convertir_mac(mac m, char *chaine)
{
 sscanf(chaine,"%hhx:%hhx:%hhx:%hhx:%hhx:%hhx",&m[0],&m[1],&m[2],&m[3],&m[4],&m[5]);	
}

void convertir_ip(ip i, char *chaine)
{
 sscanf(chaine,"%hhu:%hhu:%hhu:%hhu:%hhu:%hhu",&i[0],&i[1],&i[2],&i[3],&i[4],&i[5]);
}
