#include "reseau.h"
#include <stdlib.h>
#include <stdio.h>

void afficher_ipv4(ipv4 *addr)
{
    printf("%u.%u.%u.%u\n", (*addr)[0],(*addr)[1],(*addr)[2],(*addr)[3]);
}

void afficher_mac(mac *addr){
    printf("%02x:%02x:%02x:%02x:%02x:%02x\n", (*addr)[0],(*addr)[1],(*addr)[2],(*addr)[3],(*addr)[4],(*addr)[5]);
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

void convertir_ip(ipv4 i, char *chaine)
{
 sscanf(chaine,"%hhu:%hhu:%hhu:%hhu:%hhu:%hhu",&i[0],&i[1],&i[2],&i[3],&i[4],&i[5]);
}

char* convertir_type_trame(trame *t){
    if(t->type[0] == 0x08 && t->type[1] == 0x00){
        return "Paquet IPV4";
    }
}

void afficher_trame_humain(trame *t){
    /*printf("source : ");
    afficher_mac(&t->source);
    printf("\ndestination : ");
    afficher_mac(&t->destination);*/
    printf("type : %s", convertir_type_trame(t));
}