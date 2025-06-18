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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jogador_16818655.h"
#include "../carta.h"
#include "../baralho.h"
#include "../mao.h"

// Variáveis globais para armazenar o estado do jogador
static int id; // meu ide
static int num_jogadores; // número de jogadores na mesa
static Carta mao[6]; // a minha mão
static int num_cartas; // o número de cartas recebidas/na minha mão
static int mais_forte; // manilha
static float* probilidade; // probabilidade
static Carta baralho[TOTAL_CARTAS]; // o baralho
static Carta carta_v; // carta virada
static int apostado; // número de aposta
static posicao_mesa; // posicao na mesa
static num_rodada; // o número da rodada



/// Retorna o nome do jogador (usado no placar final)
const char* nome_jogador_16818655() {
// Substitua abaixo pelo nome que deseja exibir no placar
    return "CS 0.7";
}

/// Esta função é chamada uma vez no início do jogo.
/// Você recebe seu id (posição na mesa) e o número total de jogadores.
/// Guarde essas informações se quiser usá-las em sua estratégia.

void iniciar_16818655(int meu_id, int total_jogadores) {
    id = meu_id; //meu id
    num_jogadores = total_jogadores; //numero de jogadores
}

/// Esta função é chamada no início de cada rodada.
/// Você recebe:
/// - A carta virada
/// - A manilha
/// - Sua mão (de 2 a 6 cartas)
void nova_rodada_16818655(int rodada, Carta carta_virada, int n_cartas, Carta* minha_mao) {
    num_cartas = n_cartas; // número de cartas recebidas
    //armazena minha mão
    for (int i = 0; i < n_cartas; i++) {
        mao[i] = minha_mao[i];
    }

    mais_forte = carta_virada.valor == TRES? (int)(QUATRO):((int)(carta_virada.valor))+1; // armazena a manilha
    carta_v = carta_virada; // armazena a carta virada
    num_rodada = rodada;
}


/// Esta função define quantas mãos você pretende vencer na rodada.
/// Analise sua mão e a manilha para tomar essa decisão.
/// Retorne um valor entre 0 e `num_cartas`.

// FUNÇÃO QUE ORGANIZAR A PROBABILIDADE EM ORDEM DECRESCENTE
int decrescente(const void* a, const void* b){
    float fa = *(const float*)a;
    float fb = *(const float*)b;
    
    // Para ordem decrescente:
    if (fa < fb) return 1;
    else if (fa > fb) return -1;
    else return 0;
}

int apostar_16818655() {
    probilidade = malloc(num_cartas * sizeof(float)); // mudo tamanho do vetor para que possa armazenar a quantidade de probabilidades
    int i = 0; // variável para poder montar o baralho, em que é a iº carta
    for (int v = 0; v < 10; v++) {
        for (int n = 0; n < 4; n++) {
            baralho[i].valor = (Valor)v; //define o valor da carta no baralho
            baralho[i].naipe = (Naipe)n; //define o naipe da carta
            i++;
        }
    }
    
    // for para varrer todas as cartas da minha mão
    for(int c = 0; c < num_cartas; c++){
        int count = 0; // contador de quantidade de cartas menores que a minha carta atual
        int carta_valor = (int)(mao[c].valor); // define o valor da minha carta como int
        for(int b = 0; b < 40; b++){
            int baralho_valor = (int)(baralho[b].valor); // define o valor da carta do baralho como int
            if(carta_valor == mais_forte){ // caso a minha carta seja uma manilha
                probilidade[c] = 0.9;
                break;
            } else if(carta_valor >= baralho_valor && baralho_valor != mais_forte)count++; // caso não seja uma manilha, contar quantas cartas são menores que a minhar
            if (b==39) // quando chegar no final, coloca dentro do vetor probabilidade a probabilidade daquela carta vencer
            {
                probilidade[c] = ((float)(count))/((float)40);
            }
            
        }
        
    }
    
    int apostar = 0; // quanto vou apostar;
    
    qsort(probilidade, num_cartas, sizeof(float), decrescente); // organiza os valores da probabilidade em ordem decrescente;

    for(int j = 0; j < num_cartas; j++){ // verifica se a probabilidade é maior que 70% + (10*j)% de vitória 
        if(j < 2){
            if(probilidade[j] > (float)(0.7 + ((0.1)*j))){
                        apostar++;
            }
        } else {
            if(probilidade[j] >= (float)(0.9)){
                apostar++;
            }
        }
    }
    
    free(probilidade);
    probilidade = NULL;
    apostado = apostar;
    return apostar;
}

/// Esta função escolhe qual carta jogar.
/// Você deve retornar o índice (posição) da carta na sua mão (`mao[]`).

int comparar_mao(const void* a, const void* b) {
    const Carta* c1 = (const Carta*)a;
    const Carta* c2 = (const Carta*)b;

    int c1_manilha = c1->valor == mais_forte;
    int c2_manilha = c2->valor == mais_forte;

    // Se uma é manilha e a outra não
    if (c1_manilha && !c2_manilha) return -1;  // c1 é mais forte
    if (!c1_manilha && c2_manilha) return 1;   // c2 é mais forte

    // Ambas são manilhas → desempate por naipe
    if (c1_manilha && c2_manilha) {
        if (c1->naipe > c2->naipe) return -1; // PAUS > ...
        if (c1->naipe < c2->naipe) return 1;
        return 0;
    }

    // Nenhuma é manilha → compara por valor
    if (c1->valor > c2->valor) return -1;  // valores maiores são mais fortes
    if (c1->valor < c2->valor) return 1;

    // Desempate por naipe
    if (c1->naipe > c2->naipe) return -1;
    if (c1->naipe < c2->naipe) return 1;

    return 0; // cartas idênticas
}

// Encontra o indice de mao[], em que mao == mao_organizada
int encontrar_carta(Carta* mao, Carta* mao_organizada, int num_cartas, Carta alvo) {
    for (int i = 0; i < num_cartas; i++) {
        if (!carta_foi_usada(mao[i]) &&
            mao[i].valor == alvo.valor &&
            mao[i].naipe == alvo.naipe) {
            return i; // índice real da mão original
        }
    }
    return -1; // não encontrou
}

//Função descarte da carta
void descarte_carta(Carta* mao, Carta* mao_organizada, int num_cartas, Carta alvo) {
    for (int i = 0; i < num_cartas; i++) {
        if (!carta_foi_usada(mao[i]) &&
            mao[i].valor == alvo.valor &&
            mao[i].naipe == alvo.naipe) {
            // Marca como usada
            mao[i].valor = -1;
            mao[i].naipe = -1;
            
            for (int j = 0; j < num_cartas; j++) {
                if (mao_organizada[j].valor == alvo.valor &&
                    mao_organizada[j].naipe == alvo.naipe) {
                    mao_organizada[j].valor = -1;
                    mao_organizada[j].naipe = -1;
                    break;
                }
            }
        }
    }
    return -1; // não encontrou
}

/**
 * jogar_16818655()
 *
 * Decide qual carta jogar:
 * 1) Se ainda devo vitórias, tento bater cada carta da mesa
 * 2) Caso contrário, jogo a menor carta disponível
 * 3) Marca a carta jogada como usada na mão
 *
 * @param mesa         array de cartas já jogadas nesta rodada
 * @param num_na_mesa  número de cartas em `mesa`
 * @param vitorias     quantas vitórias já conquistei nesta rodada
 * @return índice (0..num_cartas-1) da carta em `mao[]` a ser jogada
 */

int jogar_16818655(const Carta* mesa,const int num_na_mesa, const int vitorias) {
    posicao_mesa = num_na_mesa;

    Carta mao_organizada[6];  // tamanho máximo
    
    for (int i = 0; i < num_cartas; i++) {
        mao_organizada[i] = mao[i];
    }

    qsort(mao_organizada, num_cartas, sizeof(Carta), comparar_mao); //organiza a mão organizada da maior para menor

    int idx;


    if(mesa != NULL && posicao_mesa != 0){
        
        for(int q = 0; q < posicao_mesa; q++) {
            Carta carta_atual = mesa[q];

            for(int w = 0; w < num_cartas; w++){
                Carta minha_carta = mao_organizada[w];

                if(vitorias < apostado){

                    if((int)carta_atual.valor != mais_forte && (int)minha_carta.valor != mais_forte){
                        //Caso nenhuma seja manilha
                        if(carta_atual.valor < minha_carta.valor){
                            // se minha carta é maior
                            idx = encontrar_carta(mao, mao_organizada, num_cartas, mao_organizada[w]);
                            printf("\nAQUI1\n");
                            if(idx != -1) break;
                        } else {
                            //Caso não seja maior
                            for (int i = num_cartas - 1; i >= 0; i--) {

                                if (!carta_foi_usada(mao_organizada[i])) {
                                    // Encontrou a menor carta ainda não usada
                                    idx = encontrar_carta(mao, mao_organizada, num_cartas, mao_organizada[i]);
                                    descarte_carta(mao, mao_organizada, num_cartas, mao_organizada[i]);
                                    if(idx != -1) return idx;
                                }
                            }
                        }

                    } else if((int)carta_atual.valor == mais_forte && (int)minha_carta.valor == mais_forte){
                        //Caso sejam manilhas, eliminar pelo naipe
                        if(minha_carta.naipe > carta_atual.naipe){
                            idx = encontrar_carta(mao, mao_organizada, num_cartas, mao_organizada[w]);; // marca como usada
                            if(idx != -1) break;
                        } else {
                            
                            for (int i = num_cartas - 1; i >= 0; i--) {

                                if (!carta_foi_usada(mao_organizada[i])) {
                                    // Encontrou a menor carta ainda não usada
                                    idx = encontrar_carta(mao, mao_organizada, num_cartas, mao_organizada[i]); // marca como usada
                                    descarte_carta(mao, mao_organizada, num_cartas, mao_organizada[i]);
                                    if(idx != -1) return idx;
                                }
                            }
                        }

                    } else if((int)carta_atual.valor == mais_forte && (int)minha_carta.valor != mais_forte){
                        //Se a carta seja manilha, jogar a mais fraca
                        for (int i = num_cartas - 1; i >= 0; i--) {

                            if (!carta_foi_usada(mao_organizada[i])) {
                                idx = encontrar_carta(mao, mao_organizada, num_cartas, mao_organizada[i]); // marca como usada
                                descarte_carta(mao, mao_organizada, num_cartas, mao_organizada[i]);
                                if(idx != -1) return idx;
                            }
                        }

                    } else if((int)carta_atual.valor != mais_forte && (int)minha_carta.valor == mais_forte){
                        //Caso eu tenho a manilha e o outro não, jogar a manilha
                        idx = encontrar_carta(mao, mao_organizada, num_cartas, mao_organizada[w]);; // marca como usada
                        if(idx != -1) break;
                    }

                } else {
                    //Caso já tenha as vitórias, tentar perder
                    for (int i = num_cartas - 1; i >= 0; i--) {

                        if (!carta_foi_usada(mao_organizada[i])) {
                            // Encontrou a menor carta ainda não usada
                            idx = encontrar_carta(mao, mao_organizada, num_cartas, mao_organizada[i]);; // marca como usada
                            descarte_carta(mao, mao_organizada, num_cartas, mao_organizada[i]);
                            if(idx != -1) return idx;
                        }
                    }
                }
            }
        }
    } else {
        //Caso não tenha recebido a mesa
        if(apostado != 0 && vitorias < apostado){
            //Jogo a minha mais forte se não ter comprido o número de vitórias
            for (int p = 0; p < num_cartas; p++) {
                if (!carta_foi_usada(mao_organizada[p])) {
                    idx = encontrar_carta(mao, mao_organizada, num_cartas, mao_organizada[p]);; // marca como usada
                    if(idx != -1) break;
                }
            }

        } else {
            //Jogo a mais fraca se já ter batido o número de vitórias
            for (int i = num_cartas - 1; i >= 0; i--) {
                if (!carta_foi_usada(mao_organizada[i])) {
                    // Encontrou a menor carta ainda não usada
                    idx = encontrar_carta(mao, mao_organizada, num_cartas, mao_organizada[i]); // marca como usada
                    if(idx != -1) break;
                }
            }
        }
    }

    descarte_carta(mao_organizada, mao, num_cartas, mao[idx]);
    if(idx != -1) return idx;
    free(mao_organizada);
}