#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#define MAX_ENTREES 64
#define MAX_SWITCH 16
#define MAX_STATION 64
#define MAX_LIENS 128

typedef uint8_t mac[6];

typedef uint8_t ipv4[4];

typedef struct station
{
	mac addr_mac;
	ipv4 addr_ipv4;
	size_t id;
} station;

typedef struct EntreeTable{
	mac addr_mac;
	size_t port;
}EntreeTable;

typedef struct TableCommutation{
	EntreeTable entree[MAX_ENTREES];
	size_t nb_entrees;
}TableCommutation;

typedef struct sw{
	size_t id;
	mac addr_mac;
	size_t nb_ports;
	size_t priorite_stp;
	TableCommutation table_comm;
} sw;

typedef struct lien{
	size_t eq1;
	size_t eq2;
	size_t cout;
}lien;

typedef struct reseau{
	sw switchs[MAX_SWITCH];
	station stations[MAX_STATION];
	lien liens[MAX_LIENS];
	size_t nb_switch;
	size_t nb_station;
	size_t nb_lien;
}reseau;

typedef struct trame{
	uint8_t preambule[7];
	uint8_t sfd[1];
	uint8_t destination[6];
	uint8_t source[6];
	uint8_t type[2];
	uint8_t donnees[1500];
	uint8_t bourrage[46];
	uint8_t fcs[4];
} trame;

void afficher_ipv4(ipv4 *addr);

void afficher_mac(mac *addr);

void afficher_station(station *st);

void afficher_switch(sw *sw);

void convertir_mac(mac m, char *chaine);

void convertir_ip(ipv4 i, char *chaine);

void afficher_trame_humain(trame *t);