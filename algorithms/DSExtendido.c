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

//L[i] é um DS
//T é um conjunto de DSs
int DSEstendido(gr G, ori v, T){
  for v in G
    v.add = 0

  L = vazio

  for v in G
    for u in adj[v]
      if u not in L
        u.add = 1
        L += u
        v = u
      else if u.add in L == 1
        u.add = 2
        L[i] += u
        v = u

  L[i] is not in T
    T += L[i]
    DSEstendido(gr G, ori v, T)
}
