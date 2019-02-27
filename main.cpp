# define TAMANHO 5
#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <stdio.h>
#include <tuple>
#include "tadVetor_cab.h"
/**
 * Aluno: Lucas Morita da Nova
 * TIA: 31826199
 * data: 17/02/2019
 */
 
using namespace std;

int numeros[TAMANHO];

//=================================================================================================
/*
void imprimir () {
	cout << "\n[ ";
	for (int i = 0; i < TAMANHO; i++) {
		cout << numeros[i] << " ";
	}
	cout << "]";
} */
//=================================================================================================

/**
 *@param indice - indice do elemento que será incluido
 *@param valor - valor do elemento a ser incluido.
 *@return 
 */
/*
string incluir(int indice, int valor) {
	// verifica se o valor e maior que zero
	if (valor < 0)
		return "ERRO: o valor tem que ser maior que zero.";
	
	//verifica se o indice é valido
	if (indice < 0 || indice > TAMANHO - 1)
		return "ERRO: o indice esta fora dos limites do vetor.";
	
	//verifica se a posicao já está ocupada
	if (numeros[indice] > 0) 
		return "ERRO: posicao ocupada.";
		
	//passou por todas as verificações: inserir
	numeros[indice] = valor;
	return "Inclusao bem sucedida.";
}*/
//=================================================================================================

/**
 *@param indice - indice do elemento que será excluído
 *@return - valor do elemento excluido. Se retornar zero é pq a posicao
 *estava vazia; se retornar -1 é pq o índice é inválido .
 */
/*
int excluir(int indice) {
	// verifica se o indice é valido
	if (indice < 0 || indice > TAMANHO - 1)
		return -1;
		
	int numero = numeros[indice];
	numeros[indice] = 0;
	return numero;
}
*/
//=================================================================================================
/**
 *@param numeros - recebe um array para ordenar de forma crescente
 */
/*
void ordenaCrescente(int vetor[5]) {
	int temp;
	for (int i = 0; i <= TAMANHO - 1; i++) {
		for (int j = 0; j < TAMANHO  - 1; j++) {
			if (vetor[j] > vetor[j + 1]) {
				temp = vetor[j];
				vetor[j] = 
				vetor[j + 1];
				vetor[j + 1] = temp;
			}
		}
	}
}*/
//=================================================================================================

/**
 *@param numeros - recebe um array para ordenar de forma decrescente
 */
/*
void ordenaDecrescente(int numeros[5]) {
	int temp;
	for (int i = 0; i <= TAMANHO - 1; i++) {
		for (int j = 0; j < TAMANHO  - 1; j++) {
			if (numeros[j] < numeros[j + 1]) {
				temp = numeros[j];
				numeros[j] = 
				numeros[j + 1];
				numeros[j + 1] = temp;
			}
		}
	}
}
*/
//=================================================================================================
/*
int* retornaVetor(int vetor[]) {
	for (int i = 0; i < TAMANHO; i++) {
		novoVetor[i] = vetor[i];
	}
	return novoVetor;
}
*/
//=================================================================================================

/**
 *@param vetor - vetor que será ordenado e copiado para um segundo vetor
 *@param return
 */

/* 
std::array<int, 5> ordenaEmSegundoVetor(int vetor[5]) {
	static int vetorASerRetornado[];

}
*/
//========================================================================
//							MAIN
//========================================================================

int main() {
	
	TadVetor tv;
	
	for (int i = 0; i < TAMANHO; i++) {
		numeros[i] = 0;
	}
	
	while (true){
		
		system("CLS");
		cout << "\n-------------------------------------------------------------------";
		cout << "\n			RELEMBRANDO VETORES ";
		cout << "\n-------------------------------------------------------------------";
		cout << "\n0 - sair.";
		cout << "\n1 - imprimir o vetor.";
		cout << "\n2 - inserir um elemento ( >0 e a posicao no vetor tem que estar livre (=0).";
		cout << "\n3 - excluir um elemento.";
		cout << "\n4 - trocar dois elementos de lugar entre si.";
		cout << "\n5 - localizar o maior e o menor elementos do vetor.";
		cout << "\n6 - ordenar os elementos do vetor em ordem crescente.";
		cout << "\n7 - ordenar os elementos do vetor em ordem decrescente.";
		cout << "\n8 - ordenar os elementos do vetor em um segundo vetor (o metodo cria o novo vetor, copia os dados e retorna o vetor ordenado)";
		cout << "\n------------------------------------";
		cout << "\nQual a sua opcao -> ";
		
		int opc;
		cin >> opc;
		
		if (opc == 0){
			break;
		}
		else if (opc == 1) {
			tv.imprimir(numeros);
			cout << "\n\n";
			system("PAUSE");
		} else if (opc == 2) {
			//= precisa pedir os dados: posicao no vetor (indice) e valor do elemento.
			cout << "Indice do novo elemento: ";
			int idx;
			cin >> idx;
			cout << "Valor do novo elemento: ";
			int val;
			cin >> val;
			cout << tv.incluir(idx, val, numeros) << endl;
			system("PAUSE");
		} else if (opc == 3) {
			cout << "Indice do elemento a ser removido: ";
			int idx;
			cin >> idx;
			int val = tv.excluir(idx, numeros);
			if (val == 0)
				cout << "Nao ha elemento na posicao " << idx;
			else if (val == -1)
			 	cout << "ERRO: o indice esta fora dos limites do vetor.";
			else
				cout << "Valor excluido da posicao " << idx << ": " << val;
			
			cout << "\n\n";
			system("PAUSE");
			
		} else if (opc == 4) {
			cout << "Digite o primeiro indice: ";
			int idx1;
			cin >> idx1;
			
			// valida indice1
			while (idx1 < 0 || idx1 > TAMANHO - 1){
				cout << "Digite novamente: ";
				cin >> idx1;
			}
			
			cout << "\nDigite o segundo indice: ";
			int idx2;
			cin >> idx2;
			
			// valida indice 2
			while (idx2 < 0 || idx2 > TAMANHO - 1){
				cout << "Digite novamente: ";
				cin >> idx2;
			}
			
			tv.troca(numeros, idx1, idx2);
			
			/*
			if (idx1 == idx2){
				tv.imprimir();
				system("PAUSE");
			} else {
				int temp = numeros[idx1];
				numeros[idx1] = numeros[idx2];
				numeros[idx2] = temp;

			}*/
			tv.imprimir(numeros);
			system("PAUSE");
			
		} else if (opc == 5) {
			int menor, maior;
			tuple<int, int> mytuple;
			mytuple = tv.retornaMaiorEMenor();
			tie(menor, maior) = mytuple;
			/*
			int maior = numeros[0];
			int menor = maior;
			
			for (int i = 0; i < TAMANHO; i ++){
				
				switch (numeros[i] >= maior) {
					case true:
						maior = numeros[i];
						break;
					case false:
						if (menor < numeros[i])
							break;
						menor = numeros[i];
						break;
				}
				

				if (numeros[i] >= maior) {
					maior = numeros[i];
					
				} else if (numeros[i] <= menor) {
					menor = numeros[i];
				} */
			
			cout << "Menor valor: " << menor << endl;
			cout << "Maior valor: " << maior << endl;
			system("PAUSE");
			
		} else if (opc == 6) {
			tv.ordenaCrescente(numeros);
			cout << endl;
			tv.imprimir(numeros);
			system("PAUSE");
			
		} else if (opc == 7) {
			tv.ordenaDecrescente(numeros);
			cout << endl;
			tv.imprimir(numeros);
			system("PAUSE");
			
		} else if (opc == 8) {
			int *vetorCopiado = tv.retornaNovoVetor();
			tv.ordenaCrescente(vetorCopiado);
			cout << "novo vetor: ";
			cout << "\n[ ";
			for (int i = 0; i < TAMANHO; i++) {
				cout << vetorCopiado[i] << " ";
			}
			cout << "]" << endl;
			cout << "\n";
			cout << "vetor original: ";
			tv.imprimir(numeros);
			cout << "\n";
			system("PAUSE");
				
		}
		//system("PAUSE")
	cout << "\n----------------------------------------------------------------";
	cout << "\n\nObrigado e ate a proxima vez.";
	}
return 0;	
}




