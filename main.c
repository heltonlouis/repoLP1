#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void limpar_entrada()
{
    char c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}

int main(void) {

  // sistema();
  caracteres();
  // corrida();
  return 0;
}

void caracteres() {
    char caracter[10];
    int cont = 0;

    gets(&caracter);

    for (int i=0; i < 10; i++) {
        if ( caracter[i] == 'L' && caracter[i+1] == 'P' && caracter[i+2] == '1') {
            cont++;
        }
    }

    printf("\nQuantidade: %d", cont);
}

void corrida() {
  int competidores, voltas;
  int soma, tempo, maior, menor = 1000000, position, competidor;

  printf("Quantidade de competidores e voltas: \n");
  scanf("%d %d", &competidores, &voltas);

  for(int i=0; i < competidores; i++) {
    soma = 0;
    printf("\nVoltas do competidor %d: \n", i+1);
    for (int j = 0; j < voltas; j++) {
        scanf("%d", &tempo);
        soma = soma + tempo;
        position = i + 1;
    }
    if (soma < menor) {
        menor = soma;
        competidor = position;
    }
  }

  printf("O vencedor foi o competidor %d", competidor);
}

void sistema() {
    int i, position;
    bool sair = false, match = false;
    char login[50], senha[6];
    typedef struct
    {
        char codigo[20];
        char nome[220];
        char login[50];
        char senha[6];
    } Usuario;
    Usuario usuario[2];


    printf("\nCadastro de usuario\n");
    for(i=1; i < 2; i++) {
        printf("Digite o codigo do usuario: ");
        gets(&usuario[i].codigo);

        printf("Digite o nome completo do usuario: ");
        gets(&usuario[i].nome);

        printf("Digite o login do usuario: ");
        gets(&usuario[i].login);

        printf("Digite a senha do usuario: ");
        gets(&usuario[i].senha);
    }

    for ( i = 0; i <  2; i++) {
        printf("\n=============== USUARIO %d ==================", i+1);
        printf("\nCodigo: %s", usuario[i].codigo);
        printf("\nNome: %s", usuario[i].nome);
        printf("\nlogin: %s", usuario[i].login);
        printf("\nSenha: %s", usuario[i].senha);
    }

    do {
        //limpar_entrada();
        printf("\n\nLogin no sistema!");
        printf("\nDigite seu login: ");
        gets(&login);

        printf("\nDigite sua senha: ");
        scanf("%s", &senha);
        limpar_entrada();
        for (i=0; i<2;i++) {
            // if 0 == 0
            if (strcmp(senha, usuario[i].senha) == strcmp(login, usuario[i].login)) {
                match = true;
                position = i;
            }
        }
        if (match == true) {
            printf("\nSeja bem vindo ao sistema %s!", usuario[position].nome);
            sair = true;
        } else {
            printf("Senha Invalida, por favor tente novamente!");
        }
    } while( sair == false);
}
