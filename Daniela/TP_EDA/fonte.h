#include <stdio.h>
#include <stdlib.h>

#pragma region Structs

/* Struct usada para criar os nós da lista dos meios de transporte */
typedef struct meios {
	int codigo; 			// código do meio de mobilidade elétrica
	char tipo[55]; 			// tipo de transporte 
	float custo;			// custo do aluguer
	struct meios* next; 	// próximo elemento da lista ligada
} Meios;


/* Struct usada para criar os nós da lista dos clientes */
typedef struct clientes
{
	char nome[50];			// nome do cliente
	char nif[50];			// nif do cliente
	char email[50];			// email do cliente
	char password[50];		// password da conta do cliente		
	float saldo;			// saldo do cliente
	struct clientes* next;	// próximo elemento da lista ligada
} Clientes;

/* Struct usada para criar os nós da lista dos gestores */
typedef struct gestores
{
	int id;			// email do gestor
	int codigo;				// código de acesso do gestor
	struct gestores* next;	// próximo elemento da lista ligada
} Gestores;

/* Struct usada para criar os nós da lista dos alugueres*/
typedef struct alugueres {
	int codigo;				// código do meio de mobilidade
	float custo;			// custo do aluguer
	char email[50];			// email do cliente que realizou o aluguer
	struct alugueres* next;	// próximo elemento da lista ligada
} Alugueres;

#pragma endregion


Clientes* receberDadosClientes();
int imprimirClientes(Clientes* lista_clientes);
int verificarCliente(char email[50], char password[50], Clientes* lista);
int verificarNIF(char nif[50], Clientes* lista_clientes);
int verificarEmail(char email[50], Clientes* lista_clientes);
Clientes* registarCliente(char nome[50], char nif[50], char email[50], char password[50], float saldo, Clientes* lista_clientes);

Gestores* receberDadosGestores();
int verificarGestor(int id, int codigo, Gestores* lista_gestores);

Meios* receberDadosMeios();


Alugueres* receberDadosAlugueres();

