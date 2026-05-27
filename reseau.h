#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#define MAX_ENTREES 64

typedef uint8_t mac[6];

typedef uint8_t ipv4[4];

typedef struct station
{
	mac addr_mac;
	ipv4 addr_ipv4;
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
	mac addr_mac;
	size_t nb_ports;
	size_t priorite_stp;
	TableCommutation table_comm;
} sw;

void afficher_ipv4(ipv4 *addr);

void afficher_mac(mac *addr);

void afficher_station(station *st);

void afficher_switch(sw *sw);
