#include <stdlib.h>
#include <stdbool.h>

#define MAX_ENTREES 64

typedef uint8_t mac[6];

typedef uint8_t ipv4[4];

typedef struct station{
	mac addr_mac;
	ipv4 addr_mac;
} station;

typedef struct switch{
	mac addr_mac;
	size_t nb_ports;
	size_t priorite_stp;
	mac table_comm[];
} switch;

typedef struct {
	mac addr_mac;
	size_t port;
}EntreeTable

typedef struct {
	EntreeTable entree;
	size_t nb_entrees[MAX_ENTREES];
}TableCommutation


void afficher_ipv4(ipv4 *addr);

void afficher_mac(mac *addr);

void afficher_station(station *st);

void afficher_switch(switch *sw);
