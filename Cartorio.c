#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

void registro() {
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    
    printf("Digite o CPF a ser cadastrado: \n");
    scanf("%s", cpf);
    
    strcpy(arquivo, cpf);
    
    FILE *file;
    file = fopen(arquivo, "w");
    fprintf(file, "\nCPF: ");
    fprintf(file, "%s", cpf);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",\nNOME: ");
    fclose(file);
    
    printf("Digite o nome a ser cadastrado: \n");
    scanf("%s", nome);
    
    file = fopen(arquivo, "a");
    fprintf(file, "%s", nome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",\nSOBRENOME: ");
    fclose(file);
    
    printf("Digite o sobrenome a ser cadastrado: \n");
    scanf("%s", sobrenome);
    
    file = fopen(arquivo, "a");
    fprintf(file, "%s", sobrenome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",\nCARGO: ");
    fclose(file);
    
    printf("Digite o cargo a ser cadastrado: \n");
    scanf("%s", cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file, "%s", cargo);
    fprintf(file, ",\n\n");
    fclose(file);
    
    system("pause");
}

void consulta() {
    setlocale(LC_ALL, "Portuguese");
    
    char cpf[40];
    char conteudo[200];
    
    printf("Digite o CPF a ser consultado: \n");
    scanf("%s", cpf);
    printf("\n");
    
    FILE *file;
    file = fopen(cpf, "r");
    
    if (file == NULL) {
        printf("N�o foi poss�vel abrir o arquivo, n�o localizado.\n");
    } else {
        printf("Essas s�o as informa��es do usu�rio: \n");
    }
    
    while (fgets(conteudo, 200, file) != NULL) {
        printf("%s", conteudo);
    }
    
    fclose(file);
    
    system("pause");
}

void deletar() {
    setlocale(LC_ALL, "Portuguese");
    
    char cpf[40];
    
    printf("Digite o CPF do usu�rio a ser deletado: ");
    scanf("%s", cpf);
    
    remove(cpf);
    
    FILE *file;
    file = fopen(cpf, "r");
    
    if (file == NULL) {
        printf("O usu�rio n�o se encontra no sistema!\n");
        system("pause");
    } else {
        fclose(file);
    }
}

int main() {
    int opcao = 0;
    int laco = 1;

    for (laco = 1; laco;) {
        system("cls");
        
        setlocale(LC_ALL, "Portuguese");

        printf("### Cart�rio da Ebac ###\n\n");
        printf("Escolha a op��o desejada do menu:\n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar os nomes\n");
        printf("\t3 - Deletar os nomes\n\n");
        printf("\t4 - Sair do sistema\n\n");
        printf("Op��o:");
        
        scanf("%d", &opcao);
        
        system("cls");
        
        switch (opcao) {
            case 1:
                registro();
                break;
                
            case 2:
                consulta();
                break;
                
            case 3:
                deletar();
                break;
                
            case 4:
                printf("Obrigado por utilizar o sistema!\n");
                return 0;
            
            default:
                printf("Essa op��o n�o est� dispon�vel!\n");
                system("pause");
                break;
        }
    }
}

