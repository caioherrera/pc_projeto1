/*
	criaBicho(nome, sexo): retorna um tBicho com o nome e sexo escolhidos, idade=0 e energia máxima na posição (0,0)
	movimentaBicho(*bicho, direcao): altera a posição do bicho, baseado nos direcionais (W, A, S, D), caso tenha energia suficiente
	alimentaBicho(*bicho): alimenta o bicho, recuperando toda a sua energia	
	mostraBicho(bicho): exibe todas as informações do bicho
*/

#include <stdio.h>
#include <string.h>
#define MAX 100

struct tPonto {
	int X, Y;
};

struct tBicho {
	int energia, idade;
	char nome[MAX], sexo;
	struct tPonto localizacao;	
};

struct tBicho criaBicho(char nome[MAX], char sexo) {
	struct tBicho b;
	strcpy(b.nome, nome);
	b.sexo = sexo;
	if (b.sexo == 'M')
		b.energia = 20;
	else
		b.energia = 15;
	b.idade = 0;
	b.localizacao.X = 0;
	b.localizacao.Y = 0;
	return b;
}

void movimentaBicho(struct tBicho* b, char direcao) {
	if ((b->energia > 0 && b->sexo == 'F') || (b->energia > 1 && b->sexo == 'M')) {
		switch(direcao) {
			case 'W':
				if (b->localizacao.Y > 0)
					b->localizacao.Y--;
				else
					b->localizacao.Y++;
			break;
			case 'S':
				if (b->localizacao.Y < MAX-1)
					b->localizacao.Y++;
				else
					b->localizacao.Y--;
			break;
			case 'A':
				if (b->localizacao.X > 0)
					b->localizacao.X--;
				else
					b->localizacao.X++;
			break;
			case 'D':
				if (b->localizacao.X < MAX-1)
					b->localizacao.X++;
				else
					b->localizacao.X--;
			break;
		}
		if (b->sexo == 'M')
			b->energia -= 2;
		else
			b->energia -= 1;
		b->idade++;
	}
}

void alimentaBicho(struct tBicho *b) {
	if (b->sexo == 'M')
		b->energia = 20;
	else
		b->energia = 15;		
}

void mostraBicho(struct tBicho b) {
	printf("\n");
	printf("Nome: %s\n", b.nome);
	printf("Idade: %d ano(s)\n", b.idade);
	printf("Sexo: %c\n", b.sexo);
	printf("Energia: %d\n", b.energia);
	printf("Posicao: (%d, %d)\n", b.localizacao.X, b.localizacao.Y);
	printf("\n");
}

int main() {
	struct tBicho b1, b2, b3;
	b1 = criaBicho("Moyses Asdrubal", 'M');
	b2 = criaBicho("Rosiende Cleison", 'M');
	b3 = criaBicho("Edmunda Virosina", 'F');
	movimentaBicho(&b1, 'S');
	movimentaBicho(&b2, 'D');
	movimentaBicho(&b3, 'W');
	movimentaBicho(&b3, 'W');
	alimentaBicho(&b1);
	mostraBicho(b1);
	mostraBicho(b2);
	mostraBicho(b3);
	return 0;
}
