#include <stdlib.h>
#include <stdbool.h>

typedef uint32_t mac;

typedef uint32_t ipv4;

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


void afficher_ipv4(ipv4 *addr);

void afficher_mac(mac *addr);

void afficher_station(station *st);

void afficher_switch(switch *sw);
