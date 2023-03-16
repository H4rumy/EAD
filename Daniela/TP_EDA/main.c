/// Instituto Politécnico do Cávado e do Ave
/// Estruras de Dados Avançadas
/// Autor: Daniela Loureiro Pereira
/// Tema: Aplicação para gerir Aluguer de Mobilidade
/// 13 de Março de 2023

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "fonte.h"

// Inicializar as listas
Clientes* lista_clientes;
Gestores* lista_gestores;

#pragma region Menus

void menuLoginCliente(Clientes* lista_clientes) {
	
}

void menuLoginGestor(Gestores* lista_gestores) {

	int id, codigo, verificar;

	system("cls");
	printf(" _______________________________________\n");
	printf("|\t\tLOGIN\t\t\t|\n");
	printf("|_______________________________________|\n");
	printf("\t--> ID: ");
	scanf("%d", &id);
	printf("\t--> Codigo: ");
	scanf("%d", &codigo);
	verificar = verificarGestor(id, codigo, lista_gestores);

	if (verificar == 1)
	{
		system("cls");
		printf("Entrou!");
	}
	else
	{
		system("cls");
		printf("Dados Incorretos! Pressione qualquer tecla...");
		getch();
		menuLoginGestor(lista_gestores);
	}
}

void menu(Clientes* lista_clientes, Gestores* lista_gestores) {
	int escolha;

	system("cls");
	printf(" _______________________________________\n");
	printf("|\t\tBEM-VINDO\t\t|\n");
	printf("|\t\t\t\t\t|\n");
	printf("|\t\t1-Gestor\t\t|\n");
	printf("|\t\t2-Cliente\t\t|\n");
	printf("|\033[4m\t\t\t\t\t\033[0m|\n");
	printf("|_______________________________________|\n");
	printf("| Escolha: ");
	scanf("%d", &escolha);

	/// <summary>
	/// Menus dos Gestores
	/// </summary>
	if (escolha == 1)
	{
		menuLoginGestor(lista_gestores);
	}
	/// <summary>
	/// Menus dos Clientes
	/// </summary>
	else if (escolha == 2)
	{
		system("cls");
		printf(" _______________________________________\n");
		printf("|\t\tBEM-VINDO\t\t|\n");
		printf("|\t\t\t\t\t|\n");
		printf("|\t\t1-Login\t\t|\n");
		printf("|\t\t2-Registar\t\t|\n");
		printf("|\033[4m\t\t\t\t\t\033[0m|\n");
		printf("|_______________________________________|\n");
		printf("| Escolha: ");
		scanf("%d", &escolha);

		if (escolha == 1)
		{
			char email[50], password[50];
			int verificar;
			system("cls");
			printf(" _______________________________________\n");
			printf("|\t\tLOGIN\t\t\t|\n");
			printf("|_______________________________________|\n");
			printf("\t--> Email: ");
			scanf("%s", email);
			printf("\t--> Password: ");
			scanf("%s", password);
			verificar = verificarCliente(email, password, lista_clientes);
			if (verificar == 1)
			{
				system("cls");
				printf("Login concluído! Pressione qualquer tecla para continuar...");
				getch();
				system("cls");
				printf(" _______________________________________\n");
				printf("|\t\tBEM VINDO\t\t|\n");
				printf("|\t\t\t\t\t|\n");
				printf("|\t\t1-Alterar Dados\t\t|\n");
				printf("|\t\t2-Alugar Meio\t\t|\n");
				printf("|\t\t3-Carregar Saldo\t\t|\n");
				printf("|\t\t4-Desativar Conta\t\t|\n");
				printf("|\t\t5-Sair\t\t|\n");
				printf("|\033[4m\t\t\t\t\t\033[0m|\n");
				printf("|_______________________________________|\n");
				printf("| Escolha: ");
				scanf("%d", &escolha);
				switch (escolha)
				{
				case 1:

					break;
				default:
					break;
				}
			}
			else
			{
				system("cls");
				printf("Dados Incorretos! Pressione qualquer tecla para continuar...");
				getch();
				menuLoginCliente(lista_clientes);
			}
		}
		else if (escolha == 2)
		{
			int verificar;
			char nome[50], nif[50], email[50], password[50];
			system("cls");
			printf("\t\t--> Nome: ");
			scanf("%s", nome);
			printf("\t\t--> NIF: ");
			scanf("%s", nif);
			verificar = verificarNIF(nif, lista_clientes);
			if (verificar == 1)
			{
				system("cls");
				printf("NIF atualmente em uso! Pressione qualquer tecla para regressar ao menu...");
				getch();
				menu(lista_clientes, lista_gestores);
			}
			printf("\t\t--> Email: ");
			scanf("%s", email);
			verificar = verificarEmail(email, lista_clientes);
			if (verificar == 1)
			{
				system("cls");
				printf("Email atualmente em uso! Pressione qualquer tecla para regressar ao menu...");
				getch();
				menu(lista_clientes, lista_gestores);
			}
			printf("\t\t--> Password: ");
			scanf("%s", password);
			lista_clientes = registarCliente(nome, nif, email, password, 0, lista_clientes);
			system("cls");
			printf("Cliente registado com sucesso! Pression qualquer tecla para regressar ao menu...");
			getch();
			menu(lista_clientes, lista_gestores);
		}
	}	
}


#pragma endregion Funções utilizadas para o design do menu

void main()
{
	Clientes* lista_clientes = receberDadosClientes();
	Gestores* lista_gestores = receberDadosGestores();
	menu(lista_clientes, lista_gestores);
}