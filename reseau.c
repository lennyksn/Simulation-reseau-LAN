#include "reseau.h"
#include <stdlib.h>
#include <stdio.h>

void afficher_ipv4(ipv4 *addr)
{

}

void afficher_mac(mac *addr)
{
    for(int i = 0; i < 6; i++){
        printf("%c:", (char)(addr[i]));
    }
}

void afficher_station(station *st)
{

}

void afficher_switch(sw *sw)
{

}