/**
 * jogador_16818655.c
 *
 * Implementação da lógica de aposta e jogada para o jogador “CS 0.7”
 * no jogo de Curto.  
 * Autor: Caique Sidrão (16818655)  
 * Data: Jun/2025  
 * Dependências: carta.h, baralho.h, mao.h
 * Licença: MIT
 */

#ifndef JOGADOR_16818655_H
#define JOGADOR_16818655_H

#include "../carta.h"
#include "../baralho.h"
#include "../mao.h"

const char* nome_jogador_16818655();
void iniciar_16818655(int meu_id, int total_jogadores);
void nova_rodada_16818655(int rodada, Carta carta_virada, int n_cartas, Carta* minha_mao);
int apostar_16818655();
int jogar_16818655(const Carta* mesa, const int num_na_mesa, const int vitorias);
int decrescente(const void* a, const void* b);
int comparar_mao(const void* a, const void* b);
int encontrar_carta(Carta* mao, Carta* mao_organizada, int num_cartas, Carta alvo);
void descarte_carta(Carta* mao, Carta* mao_organizada, int num_cartas, Carta alvo);
static int achar_carta_que_vence(const Carta* mesa, int tam_mesa);
static int achar_menor_carta(void);

#endif