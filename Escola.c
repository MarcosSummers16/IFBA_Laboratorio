

#include <stdio.h>
#include <string.h>

//Funções

// Validar Data
int validaData(dia, mes, ano) {
	int validado = 1;
	if (mes > 12 || mes < 1 || dia < 1) || dia > 31{
		validado = 0;
	}
	else if (mes % 2 == 0 && mes != 2 && dia > 30) {
		validado = 0;
	}
	else if (ano % 400 == 0 || (ano % 4 == 0 && ano % 100 != 0)) {
		if (mes == 2 && dia > 29) {
			validado = 0;
		}
		else
		{
			validado = 1;
		}
	}
	else if (mes == 2 && dia > 28) {
		validado = 0;
	}
	else {
		validado = 1;
	}

	return (validado);
}

typedef struct dma {
	int dia;
	int mes;
	int ano;
} Data;

/*Criando a struct aluno */
typedef struct dados_aluno
{
	int matricula;
	char nome[50];
	char sexo; //M - Masculino, F - Feminino
	Data data_nascimento;
	char cpf[11];

} Aluno;

/* Criando a struct professor */

typedef struct dados_professor
{
	int matricula;
	char nome[50];
	char sexo;
	Data data_nascimento;
	char cpf[11];

} Professor;

/* Struct de Disciplina*/
typedef struct dados_disciplina
{
	int codigo;
	char nome[20];
	int semestre;
	char professor[50];

} Disciplina;

typedef struct Relacao_Disciplina_Aluno
{
	int codigo;
	int matricula[20];

} Rel_Disc_Aluno;

int main(void)
{

	Aluno aluno; /*Criando a variável aluno que será do tipo struct Ficha_Aluno */
	Aluno lista_aluno[10]; // vetor para armazenar a lista de alunos
	int qtd_alunos = 0; // variável para controlar a quantidade de alunos cadastrados

	Professor professor;
	Professor lista_professor[5];
	int qtd_professores = 0;

	Disciplina disciplina;
	Disciplina lista_disciplinas[20];
	int qtd_disciplinas = 0;

	Rel_Disc_Aluno alunos_disciplina;
	Rel_Disc_Aluno lista_alunos_disciplina[20];

	int intData = 0

	int opcao, opcao2;
	int sair = 0;
	int sair2 = 0;

	while (!sair) {

		printf("Digite a opção:\n");
		printf("0 - Sair\n");
		printf("1 - Inserir Aluno\n");
		printf("2 - Listar Alunos\n");
		printf("3 - Inserir Professor\n");
		printf("4 - Listar Professores\n");
		scanf("%d", &opcao);

		switch (opcao) {
		case 0: {
			printf("Finalizando Escola\n");
			sair = 1;
			break;
		}
		case 1: {
			printf("\n### Cadastro de Aluno ###\n");
			printf("Digite a matrícula: ");
			scanf("%d", &lista_aluno[qtd_alunos].matricula);
			getchar();

			printf("Digite o nome do aluno: ");
			fgets(lista_aluno[qtd_alunos].nome, 50, stdin);
			/*o fgets é uma das funções mais indicadas para ler string do teclado.
			Ela controla o tamanho do buffer, e não deixa o buffer com lixo.
			Entretanto ela guarda o \n ao final da string, por isso é preciso removê-lo, como feito a seguir*/
			size_t ln = strlen(lista_aluno[qtd_alunos].nome) - 1; //size_t = unsigned integer type
			if (lista_aluno[qtd_alunos].nome[ln] == '\n')
				lista_aluno[qtd_alunos].nome[ln] = '\0';

			printf("Digite o sexo: ");
			scanf("%c", &lista_aluno[qtd_alunos].sexo);

			/* obs. a data nascimento será recuperada separadamente o dia, mês e ano,
			mas depois tem que mudar para informar uma string dd/mm/aaaa, e validar a data*/
			do
			{
				printf("Digite o dia de nascimento: ");
				scanf("%d", &lista_aluno[qtd_alunos].data_nascimento.dia);

				printf("Digite o mês de nascimento: ");
				scanf("%d", &lista_aluno[qtd_alunos].data_nascimento.mes);

				printf("Digite o ano de nascimento: ");
				scanf("%d", &lista_aluno[qtd_alunos].data_nascimento.ano);
				getchar();
				// Validação de Data
				// corrigir validação, está incorreta
				intData = validaData(lista_aluno[qtd_alunos].data_nascimento.dia, lista_aluno[qtd_alunos].data_nascimento.mes, lista_aluno[qtd_alunos].data_nascimento.ano);

				if (intData == 1) {
					printf("Data inválida, digite novamente.\n");
				}
			}
			while (intData == 0)
			{

			}
			printf("Digite o CPF: ");
			fgets(lista_aluno[qtd_alunos].cpf, 11, stdin);
			ln = strlen(lista_aluno[qtd_alunos].cpf) - 1;
			if (lista_aluno[qtd_alunos].cpf[ln] == '\n')
				lista_aluno[qtd_alunos].cpf[ln] = '\0';

			qtd_alunos++;

			printf("\n");

			break;
		}
		case 2:

		case 3: {
			printf("\n### Cadastro de Professor ###\n");
			printf("Digite a matrícula: ");
			scanf("%d", &lista_professor[qtd_professores].matricula);
			getchar;

			printf("Digite o nome do professor: \n");
			fgets(lista_professor[qtd_professores].nome, 50, stdin);

			size_t ln = strlen(lista_professor[qtd_professores].nome) - 1;
			if (lista_professor[qtd_professores].nome[ln] == '\n')
				lista_professor[qtd_professores].nome[ln] = '\0';

			printf("Digite o sexo: \n");
			scanf("%c", &lista_professor[qtd_professores].sexo);

			printf("\n");

			do
			{
				printf("Digite o dia de nascimento: ");
				scanf("%d", &lista_professor[qtd_professores].data_nascimento.dia);

				printf("Digite o mês de nascimento: ");
				scanf("%d", &lista_professor[qtd_professores].data_nascimento.mes);

				printf("Digite o ano de nascimento: ");
				scanf("%d", &lista_professor[qtd_professores].data_nascimento.ano);
				getchar();
				// Validação de Data
				intData = validaData(lista_professor[qtd_professores].data_nascimento.dia, lista_professor[qtd_professores].data_nascimento.mes, lista_professor[qtd_professores].data_nascimento.ano);

				if (intData == 1) {
					printf("Data inválida, digite novamente.\n");
				}

			} while (intData == 0)

			printf("Digite o CPF: \n");
			fgets(lista_professor[qtd_professores].cpf, 11, stdin);
			ln = strlen(lista_professor[qtd_professores].cpf) - 1;
			if (lista_professor[qtd_professores].cpf[ln] == '\n')
				lista_professor[qtd_professores].cpf[ln] = '\0';

			qtd_professores++;
			break;

		case 4: {
			do {

				printf("\n### Relatórios ###\n");
				printf("\n");
				printf("\n");
				printf("Digite 1 para listar os professores: \n");
				printf("Digite 2 para listar os alunos: \n");
				printf("Digite 0 para retornar ao menu principal. \n");

				switch (opcao2) {
				case 0: {
					sair2 = 1;
					sair = 0;
				}
				case 1: {
					printf("\n### Lista Professores ###\n");
					int i;
					for (i = 0; i < qtd_professores; i++) {
						printf("-----\n");
						printf("Matrícula: %d\n", lista_professor[i].matricula);
						printf("Nome: %s\n", lista_professor[i].nome);
						printf("Sexo: %c\n", lista_professor[i].sexo);
						printf("Data Nascimento: %d/%d/%d\n", lista_professor[i].data_nascimento.dia, lista_professor[i].data_nascimento.mes, lista_professor[i].data_nascimento.ano);
						printf("CPF: %s\n", lista_professor[i].cpf);
					}
					printf("-----\n\n");
					break;
				}

				case 2: {
					printf("\n### Alunos Cadastrados ####\n");
					int i;
					for (i = 0; i < qtd_alunos; i++) {
						printf("-----\n");
						printf("Matrícula: %d\n", lista_aluno[i].matricula);
						printf("Nome: %s\n", lista_aluno[i].nome);
						printf("Sexo: %c\n", lista_aluno[i].sexo);
						printf("Data Nascimento: %d/%d/%d\n", lista_aluno[i].data_nascimento.dia, lista_aluno[i].data_nascimento.mes, lista_aluno[i].data_nascimento.ano);
						printf("CPF: %s\n", lista_aluno[i].cpf);

					}
					printf("-----\n\n");
					break;

				}

				case 3: {



				}

				}

			} while (sair2 != 1);
		case 5: {
			printf("\n### Cadastrar Matéria ###\n");
			printf("\n### Digite o código da matéria:\n");
			scanf("%d", &lista_disciplinas[qtd_disciplinas].codigo);
			lista_alunos_disciplina[qtd_disciplinas].codigo = lista_disciplinas[qtd_disciplinas].codigo;
			getchar;

			printf("\n### Digite o nome da matéria:\n");




		}
		default: {
			printf("Opção Inválida\n");
		}
		}
	}


	return 1;

}
