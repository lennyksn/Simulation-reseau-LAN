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
	    printf("Port n°%zu : ",sw->table_comm.entree[i].port);
        afficher_mac(sw->table_comm.entree[i].addr_mac);
	    printf("\n");
    }	
}

void afficher_reseau(reseau r*)
{
    printf("Reseau :");
    printf("%zu switch(s), %zu station(s), %zu lien(s)\n\n", r->nb_switch, r->nb_station, r->nb_lien);

    for (int i = 0; i < r->nb_switch; i++) {
        afficher_switch(&r->switchs[i]);
        printf("\n");
    }

    for (int i = 0; i < r->nb_station; i++) {
        afficher_station(&r->stations[i]);
        printf("\n");
    }

    printf("Liens :\n");
    for (int i = 0; i < r->nb_lien; i++) {
        printf("  %zu <-> %zu (coût : %zu)\n",
            r->liens[i].eq1,
            r->liens[i].eq2,
            r->liens[i].cout);
    }  
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
    printf("type : %s\n", convertir_type_trame(t));
}

bpdu initialize_bpdu(sw *s)
{
    bpdu b;
    // je me crois racine donc ma priorité et ma MAC comme racine
    memcpy(b.addr_racine, s->addr_mac, 6);
    b.priorite_racine = s->priorite_stp;
    b.cout_racine = 0;  // coût 0 car je me crois racine
    memcpy(b.addr_emetteur, s->addr_mac, 6);
    return b;
}

void initialize_stp(reseau *r)
{
    for (size_t i = 0; i < r->nb_switch; i++)
    {
        r->switchs[i].meilleur_bpdu = initialize_bpdu(&r->switchs[i]);
    }
}

bool bpdu_meilleur(bpdu *b1, bpdu *b2) {
    if (b1->priorite_racine != b2->priorite_racine)
        return b1->priorite_racine < b2->priorite_racine;
    
    int cmp = memcmp(b1->addr_racine, b2->addr_racine, 6);
    if (cmp != 0)
        return cmp < 0;
    
    return b1->cout_racine < b2->cout_racine;
}

int traiter_bpdu(sw *s, bpdu *recu, size_t port_recu, size_t cout_lien) {
    bpdu candidat = *recu;
    candidat.cout_racine += cout_lien;  // on ajoute le coût du lien
    
    if (bpdu_meilleur(&candidat, &s->meilleur_bpdu)) {
        s->meilleur_bpdu = candidat;
        s->ports[port_recu].etat = RACINE;
        return 1;  // changement détecté
    }
    return 0;  // pas de changement
}