#ifndef _CLIENTE_H
#define _CLIENTE_H

#include "produto.h"
#include "item.h"

typedef struct Cliente tCliente;

tCliente *criaCliente();

int comparaCliente(tCliente *cliente1, tCliente *cliente2);

char *getCpfCliente(tCliente *cliente);

void adicionaItemCliente(tCliente *cliente, tItem *item);

void removeItemCliente(tCliente *cliente, tItem *item);

void limpaSacolaCliente(tCliente *cliente);

int efetuaCompraCliente(tCliente *cliente);

void printaCliente(tCliente *cliente);

void liberaCliente(tCliente *cliente);

#endif