#define TAMANHO 5
#include <iostream>
#include <tuple>
#include "tadVetor_cab.h"

TadVetor::TadVetor() {
	//numeros = new int[TAMANHO];
	for (int i = 0; i < TAMANHO; i++) {
		numeros[i] = 0;
	}
}

//==============================================================================
// Metodo para imprimir o vetor.
void TadVetor::imprimir(int *vetor) {
//	int* ip = vetor;
	cout << "\n[ ";
	for (int i = 0; i < TAMANHO; i++) {
		cout << *(vetor+i) << " ";
	}
	cout << "]";
}

//------------------------------------------------------------------------------
/**	
* Metodo para incluir um elemento no vetor. A posicao tem que estar vaga
* (valor do elemento igual a zero). O novo elemento tem que ser maior que
* zero.
*
* @param indice - indice do elemento que sera´ incluido.
* @param valor - valor do elemento a ser incluido.
* @return
*/

string TadVetor::incluir(int indice, int valor, int *vetor) {
	// verifica se o valor e´ maior que zero
	if (valor < 0) {
		return "ERRO: o valor tem que ser maior que zero.";
	}
	// verifica se o indice e´ valido
	if (indice < 0 || indice > TAMANHO - 1) {
		return "ERRO: o indice esta´ fora dos limites do vetor.";
	}
	// verifica se a posicao ja´ esta´ ocupada.
	if (*(vetor + indice) > 0) {
		return "ERRO: posicao ocupada.";
	}
	// passou por todas as verificacoes: inserir
	*(vetor + indice) = valor;
	return "Inclusao bem sucedida.";
}

/**
* Excluir um elemento do vetor. Atribui zero `a posicao e retorna o
* elemento (valor).
*
* @param indice - indice do elemento que sera´ excluido.
* @return - valor do elemento excluido. Se retornar zero e´ porque a
* posicao estava vazia; se retornar -1 e´ porque o indice e´ invalido.
*/

int TadVetor::excluir(int indice, int *vetor) {
	// verifica se o indice e´ valido
	if (indice < 0 || indice > TAMANHO - 1) {
		return -1;
	}
	int *ip;
	ip = &vetor[indice];
	int numero = *ip;
	*ip = 0;
	return numero;
}

tuple<int, int> TadVetor::retornaMaiorEMenor(int *vetor) {
	int maior = numeros[0];
	int menor = maior;
	int i;
	int *ip = new int;
	for (i = 0; i < TAMANHO; i++) {
		switch (numeros[i] >= maior){
			case true:
				ip = &numeros[i];
				maior = *ip;
				break;
			case false:
				ip = &numeros[i];
				menor = *ip;
		}
	}
	delete ip;
	return make_tuple(menor, maior);
}

void TadVetor::troca(int *vetor, int idx1, int idx2) {
	if (idx1 == idx2) {
		return;
	}
	int temp = vetor[idx1];
	vetor[idx1] = vetor[idx2];
	vetor[idx2] = temp;
	
}

void TadVetor::ordenaCrescente(int *vetor) {
	int temp, i, j, *ip;
	for (i = 0; i <= TAMANHO - 1; i++) {
		for (j = 0; j < TAMANHO - 1; j++) {
			if (vetor[j] > vetor[j + 1]) {
				temp = vetor[j];
				ip = &vetor[j];
				*ip = vetor[j + 1];
				ip = &vetor[j + 1];
				*ip = temp;
				/*
				vetor[j] = vetor[j + 1];
				vetor[j + 1] = temp;
				*/
			}
		}
	}	
}

void TadVetor::ordenaDecrescente(int* vetor) {
	int temp, i, j;
	for (i = 0; i <= TAMANHO - 1; i++) {
		for (j = 0; j < TAMANHO  - 1; j++) {
			if (vetor[j] < vetor[j + 1]) {
				temp = vetor[j];
				vetor[j] = 
				vetor[j + 1];
				vetor[j + 1] = temp;
			}
		}
	}
}

int* TadVetor::retornaNovoVetor() {
	int* novoVetor = new int[TAMANHO];
	for (int i = 0; i <= TAMANHO - 1; i++) {
		novoVetor[i] = numeros[i];
	}
	return novoVetor;
}
