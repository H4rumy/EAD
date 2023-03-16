#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonte.h"

#pragma region Dados

/// <summary>
/// Função responsável por receber os dados do ficheiro que contém os dados dos clientes
/// e guardar esses dados na lista ligada
/// </summary>
/// <returns>A lista com os dados</returns>
Clientes* receberDadosClientes() {
    FILE* fp;

    fp = fopen("clientes.txt", "r");

    if (fp == NULL)
    {
        printf("Erro ao receber dados! Renicie a aplicação!\n");
        return NULL;
    }

    Clientes* lista_clientes = NULL;

    while (!feof(fp))
    {
        char nome[50];
        char nif[50];
        char email[50];
        char password[50];
        float saldo;

        fscanf(fp, "%[^;];%[^;];%[^;];%[^;];%f\n", nome, nif, email, password, &saldo);

        Clientes* cliente = (Clientes*)malloc(sizeof(Clientes));

        if (cliente == NULL)
        {
            printf("Erro ao alocar a memória de um cliente!\n");
            fclose(fp);
            return lista_clientes;
        }

        strcpy(cliente->nome, nome);
        strcpy(cliente->nif, nif);
        strcpy(cliente->email, email);
        strcpy(cliente->password, password);
        cliente->saldo = saldo;

        cliente->next = lista_clientes;
        lista_clientes = cliente;
    }

    fclose(fp);
    return lista_clientes;
}

Gestores* receberDadosGestores() {

    FILE* fp;

    fp = fopen("gestores.txt", "r");

    if (fp == NULL)
    {
        printf("Erro ao receber dados! Renicie a aplicação!\n");
        return NULL;
    }

    Gestores* lista_gestores = NULL;

    while (!feof(fp))
    {
        int id, codigo;
        fscanf(fp, "%d;%d", &id, &codigo);

        Gestores* gestor = (Gestores*)malloc(sizeof(Gestores));

        if (gestor == NULL)
        {
            printf("Erro ao alocar a memória de um cliente!\n");
            fclose(fp);
            return lista_gestores;
        }

        gestor->id = id;
        gestor->codigo = codigo;
        gestor->next = lista_gestores;
        lista_gestores = gestor;
    }

    fclose(fp);
    return lista_gestores;
}

Meios* receberDadosMeios() {
    FILE* fp;

    fp = fopen("meios.txt", "r");

    if (fp == NULL) {
        printf("Erro ao receber dados! Renicie a aplicação!\n");
        return NULL;
    }

    Meios* lista_meios = NULL;

    while (!feof(fp))
    {
        int codigo;
        char tipo[55];
        float custo;
        
        fscanf(fp, "%d;%[^;];%f", &codigo, tipo, &custo);

        Meios* meio = (Meios*)malloc(sizeof(Meios));

        if (meio == NULL)
        {
            printf("Erro ao alocar a memória de um meio!\n");
            fclose(fp);
            return lista_meios;
        }

        meio->codigo = codigo;
        strcpy(meio->tipo, tipo);
        meio->custo = custo;
        meio->next = lista_meios;
        lista_meios = meio;
    }

    fclose(fp);
    return lista_meios;
}

Alugueres* receberDadosAlugueres() {
    FILE* fp;

    fp = fopen("alugueres.txt", "r");

    if (fp == NULL)
    {
        printf("Erro ao receber dados! Renicie a aplicação!\n");
        return NULL;
    }

    Alugueres* lista_alugueres = NULL;

    while (!feof(fp))
    {
        int codigo;
        float custo;
        char email[50];

        fscanf(fp, "%d;%f;%s", &codigo, &custo, email);

        Alugueres* aluguer = (Alugueres*)malloc(sizeof(Alugueres));

        if (aluguer == NULL)
        {
            printf("Erro ao alocar a memória de um aluguer!\n");
            fclose(fp);
            return lista_alugueres;
        }

        aluguer->codigo = codigo;
        aluguer->custo = custo;
        strcpy(aluguer->email, email);
        aluguer->next = lista_alugueres;
        lista_alugueres = aluguer;
    }

    fclose(fp);
    return lista_alugueres;
}

#pragma endregion Funções usadas para receber os dados dos ficheiros

/// <summary>
/// Função responsável por imprimir todos os clientes registados
/// </summary>
/// <param name="lista_clientes">Lista que contém todos os dados dos clientes</param>
/// <returns></returns>
int imprimirClientes(Clientes* lista_clientes) {
    Clientes* clienteAtual = lista_clientes;
    while (clienteAtual != NULL) {
        printf("| Nome: %s | NIF: %s | Email: %s | Saldo: %f |\n", clienteAtual->nome, clienteAtual->nif, clienteAtual->email,
            clienteAtual->saldo);
        clienteAtual = clienteAtual->next;
    }
    return 0;
}

#pragma region Verificação

int verificarCliente(char email[50], char password[50], Clientes* lista) {
    int verificar = 0;

    Clientes* clienteAtual = lista;
    while (clienteAtual != NULL)
    {
        if (strcmp(clienteAtual->email, email) == 0 && strcmp(clienteAtual->password, password) == 0)
        {
            verificar = 1;
            free(clienteAtual);
            return verificar;
        }
        clienteAtual = clienteAtual->next;
    }
    return verificar;
}

int verificarGestor(int id, int codigo, Gestores* lista_gestores) {
    int verificar = 0;
    Gestores* gestorAtual = lista_gestores;
    while (gestorAtual != NULL)
    {
        if (gestorAtual->id == id && gestorAtual->codigo == codigo) {
            verificar = 1;
            return verificar;
        }
        gestorAtual = gestorAtual->next;
    }
    return verificar;
}

int verificarNIF(char nif[50], Clientes* lista_clientes) {
    int verificar = 0;
    Clientes* clienteAtual = lista_clientes;
    while (clienteAtual != NULL)
    {
        if (strcmp(clienteAtual->nif, nif) == 0)
        {
            verificar = 1;
            return verificar;
        }
        clienteAtual = clienteAtual->next;
    }

    return verificar;
}

int verificarEmail(char email[50], Clientes* lista_clientes) {
    int verificar = 0;
    Clientes* clienteAtual = lista_clientes;
    while (clienteAtual != NULL)
    {
        if (strcmp(clienteAtual->email, email) == 0) {
            verificar = 1;
            return verificar;
        }
        clienteAtual = clienteAtual->next;
    }

    return verificar;
}

#pragma endregion Funções usadas para validar o login dos clientes/gestores


Clientes* registarCliente(char nome[50], char nif[50], char email[50], char password[50], float saldo, Clientes* lista_clientes) {
    
    Clientes* novocliente = (Clientes*)malloc(sizeof(Clientes));
    
    if (novocliente == NULL)
    {
        printf("Erro ao registar utilizador!");
        return lista_clientes;
    }
    
    strcpy(novocliente->nome, nome);
    strcpy(novocliente->nif, nif);
    strcpy(novocliente->email, email);
    strcpy(novocliente->password, password);
    novocliente->saldo = saldo;
    novocliente->next = lista_clientes;

    return novocliente;

}
