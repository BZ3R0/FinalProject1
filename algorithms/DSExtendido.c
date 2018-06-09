//Entrada: KMTS
//Saida: DSExtendido
#include <stdio.h>
#include <string.h>

int DSExtendido(v)
{
  DSExtendido = [];
  ConjuntoDS = [];

  for adj[v]
    a.rpre = v.p
    a.rpos = adj[v].p
    DSExtendido += a
    DSExtendido(adj[v])

  ConjuntoDS += DSExtendido

  return ConjuntoDS
}
