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
    printf("Station st%zu :\n",st->id);
    printf("   MAC : ");
    afficher_mac(st->addr_mac);
    printf("\n   IP : ");
    afficher_ipv4(st->addr_ipv4);
    printf("\n");
}

void afficher_switch(sw *sw)
{
    printf("Switch sw%zu :\n",sw->id);
    printf("   MAC :");
    afficher_mac(sw->addr_mac);
    printf("\n   Ports : %zu\n",sw->nb_ports);
    printf("\n   Priorité : %zu\n",sw->priorite_stp);
    printf("\n   Table de commutation (%zu entrées)",sw->table_comm.nb_entrees);
    for (int i = 0; i < sw->table_comm.nb_entrees; i++)
    {
	printf("Port n°%zu : ",sw->table_comm.entrees[i].port);
        afficher_mac(sw->table_comm.entrees[i].addr_mac);
	printf("\n");	
}

void convertir_mac(mac m, char *chaine)
{
 sscanf(chaine,"%hhx:%hhx:%hhx:%hhx:%hhx:%hhx",&m[0],&m[1],&m[2],&m[3],&m[4],&m[5]);	
}

void convertir_ip(ipv4 i, char *chaine)
{
 sscanf(chaine,"%hhu:%hhu:%hhu:%hhu:%hhu:%hhu",&i[0],&i[1],&i[2],&i[3],&i[4],&i[5]);
}
