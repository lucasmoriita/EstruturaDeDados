#define TAMANHO 5
#ifndef TADVETOR_CAB_H
#define TADVETOR_CAB_H
#include <stdlib.h>
#include <tuple>

using namespace std;

class TadVetor {
	
	private:
		//int * numeros;
		int numeros[TAMANHO];

	public:
		TadVetor();
		void imprimir(int *vetor);
		string incluir(int indice, int valor, int *vetor);
		int excluir(int indice, int *vetor);
		tuple<int, int> retornaMaiorEMenor(int *vetor);
		void troca(int *vetor, int idx1, int idx2);
		void ordenaCrescente(int *vetor);
		void ordenaDecrescente(int *vetor);
		int *retornaNovoVetor();		
};

#endif
