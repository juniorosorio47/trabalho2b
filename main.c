#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<locale.h>

//---------------------------------Declaração das structs---------------------------------


//Informacoes do paciente
typedef struct paciente{
	int ativo;
	int id;
    char nome[50];
    char endereco[100];
    int telefone;
    int dataNascimento;
    char historico[200];
    char nomeResponsavel[50];
    int telefoneResponsavel;
} Paciente;

//Informacoes do dentista
typedef struct dentista{
	int ativo;
    int CRO;
    char nome[50];
    char endereco[100];
    int telefone;
} Dentista;

//Informacoes dos materiais
typedef struct material{
	int ativo;
	int id;
    char nome[50];
    char descricao[100];
    char tipoMaterial[50];
    float preco;
} Material;

//Informacoes da consulta
typedef struct consulta{
    int finalizada;
    int idConsulta;
    char nomePaciente[50];
    int dataConsulta;
    int horaConsulta;
    char nomeResponsavel[50];
    int telefoneResponsavel;
    char descricaoConsultas[200];
} Consulta;

//---------------------------------Declaração das funções---------------------------------

//Cadastros
void cadastrarDentista();
void cadastrarPaciente();
void cadastrarMaterial();

//Buscar
void buscarDentistas();
void buscarPacientes();
void buscarMateriais();

//Listar
void listarDentistas();
void listarPacientes();
void listarMateriais();

//Remover
void removerDentista();
void removerPaciente();
void removerMaterial();

//Pesquisar
void pesquisarCadastro();

Paciente pacientes[100];
Consulta consultas[100];
Dentista dentistas[100]; 
Material materiais[100];

int contadorConsulta=0, contadorPaciente=0, contadorMaterial=0, contadorDentista=0;

//---------------------------------Função main---------------------------------
int main(){
	setlocale(LC_ALL, "Portuguese");

    int i, escolhaMenu, escolhaBuscaConsultas, buscaInt, busca, buscaData , x, y, aux;
    int contadorConsulta=0, contadorPaciente=0, contadorMaterial=0, contadorDentista=0;
    char buscaChar[100];

	
	do{
		system("cls");
		
		printf("===============================================\n");
		
		printf("-------------- MENU PRINCIPAL São -----------------\n");
		
		printf("===============================================\n\n");
		
		printf("\n============== CONSULTAS ===================== \n");
		printf("Digite 1 para agendar uma nova consulta: \n");
		printf("Digite 2 para buscar as consultas agendadas:\n");
		printf("Digite 3 para listar todas as as consultas:\n");
		printf("Digite 4 para finalizar uma consulta: \n");
		
		printf("===============================================\n\n");
		
		printf("============== BUSCAR CADASTRO ================\n");
		printf("Digite 5 para buscar pacientes cadastrados: \n");
		printf("Digite 6 para buscar dentistas cadastrados: \n");
		printf("Digite 7 para buscar materiais cadastrados: \n");

		printf("===============================================\n\n");
		
		printf("============== LISTAR CADASTRO ================\n");
		printf("Digite 8 para listar todos os pacientes cadastrados: \n");
		printf("Digite 9 para listar todos os dentistas cadastrados: \n");
		printf("Digite 10 para listar todos os materiais cadastrados: \n");
		
		printf("===============================================\n\n");
		
		printf("============== CADASTRAR ======================\n");
		printf("Digite 11 para cadastrar um novo paciente: \n");
		printf("Digite 12 para cadastrar um novo dentista: \n");
		printf("Digite 13 para cadastrar um novo material: \n");
		
		printf("===============================================\n\n");
		
		printf("============== REMOVER ======================\n");
		printf("Digite 14 para remover um paciente: \n");
		printf("Digite 15 para remover um dentista: \n");
		printf("Digite 16 para remover um material: \n");
		
		printf("===============================================\n\n");
		
		printf("============== SAIR ===========================\n");
		printf("Digite 0 para sair do programa: \n");
		
		printf("===============================================\n\n");
		
		
		fflush(stdin);
		scanf("%d", &escolhaMenu);
		
		getchar();
		switch(escolhaMenu){
			
			case 6:
				buscarDentistas();
			break;
			
			case 8:
				listarPacientes();
			break;
			
			case 9:
				listarDentistas();
			break;
			
			case 10:
				listarMateriais();
			break;
			
			case 11:
				cadastrarPaciente();
			break;
			
			case 12:
				cadastrarDentista();	
			break;
			
			case 13:
				cadastrarMaterial();
			break;

			case 14:
				removerPaciente();
			break;

			case 15:
				removerDentista();
			break;

			case 16:
				removerMaterial();
			break;

			case 0:
				return 0;
			break;
		}
		getchar();
	}while(escolhaMenu!=0);
  	
}

//---------------------------------Funcoes----------------------------------------------------------------------------


//Cadastros-----------------------------------------------------------------------------------------------------------

void cadastrarDentista(){
	FILE* arquivo;
	Dentista dentistas[100];
	int CRO;
    char nome[50];
    char endereco[100];
    int telefone;
    int escolha;
    int i, n=0;
    
    arquivo = fopen("dentistas.txt", "ab");

	if(arquivo==NULL){
		printf("Não foi possível abrir o arquivo\n");
	}else{
		do{
			system("cls");
			
			printf("\nDigite o CRO do dentista:\n");
			fflush(stdin);
			scanf("%d", &CRO);
			
			printf("\nDigite o nome do dentista:\n");
			fflush(stdin);
			fgets(nome, sizeof(nome), stdin);
			
			printf("\nDigite o endereco do dentista:\n");
			fflush(stdin);
			fgets(endereco, sizeof(endereco), stdin);
			
			printf("\nDigite o telefone do dentista:\n");
			fflush(stdin);
			scanf("%d", &telefone);
				
			dentistas[contadorDentista].CRO = CRO;
			strcpy(dentistas[contadorDentista].nome, nome);
			strcpy(dentistas[contadorDentista].endereco, endereco);
			dentistas[contadorDentista].telefone = telefone;
			
			dentistas[contadorDentista].ativo =1;

			contadorDentista++;

			fwrite(&dentistas, sizeof(dentistas), 1, arquivo);
			
			getchar();
			printf("\nDigite 1 para Cadastrar mais Dentistas.");
			printf("\nDigite 0 para Sair.\n");
				fflush(stdin);
			scanf("%d", &escolha);
			
		}while(escolha!=0);
		fclose(arquivo);
	}
	
}
void cadastrarPaciente(){
	FILE* arquivo;
	Paciente pacientes[100];
	int ativo;
    char nome[50];
    char endereco[100];
    int telefone;
    int dataNascimento;
    char nomeResponsavel[50];
    int telefoneResponsavel;
    int i, escolha;

	arquivo = fopen("pacientes.txt", "ab");

	if(arquivo==NULL){
		printf("Não foi possível abrir o arquivo\n");
	}else{
    
		do{
			system("cls");
			
			printf("\nDigite o nome do paciente:\n");
			getchar();
			fgets(nome, sizeof(nome), stdin);
	

			printf("\nDigite o nome do responsavel pelo paciente:\n");
			fgets(nomeResponsavel, sizeof(nomeResponsavel), stdin);
			
			printf("\nDigite o endereco do paciente:\n");
			fgets(endereco, sizeof(endereco), stdin);
			
			printf("\nDigite o telefone do paciente:\n");
			fflush(stdin);
			scanf("%d", &telefone);
			
			printf("\nDigite o telefone do responsavel pelo paciente:\n");
			fflush(stdin);
			scanf("%d", &telefoneResponsavel);
			
			printf("\nDigite a data de nascimento do paciente:\n");
			fflush(stdin);
			scanf("%d", &dataNascimento);

			strcpy(pacientes[contadorPaciente].nome, nome);
			strcpy(pacientes[contadorPaciente].nomeResponsavel, nomeResponsavel);
			strcpy(pacientes[contadorPaciente].endereco, endereco);
			pacientes[contadorPaciente].telefone = telefone;
			pacientes[contadorPaciente].telefoneResponsavel = telefoneResponsavel;
			pacientes[contadorPaciente].dataNascimento = dataNascimento;
			pacientes[contadorPaciente].ativo = 1;
			contadorPaciente++;

			fwrite(&pacientes, sizeof(pacientes), 1, arquivo);
			
			getchar();
			printf("\nDigite 1 para Cadastrar mais Pacientes.");
			printf("\nDigite 0 para Sair.\n");
				fflush(stdin);
			scanf("%d", &escolha);
		}while(escolha!=0);
		fclose(arquivo);
	}
	
}
void cadastrarMaterial(){
	int ativo;
    char nome[50];
    char descricao[100];
    char tipoMaterial[50];
    float preco;
    int i, escolha;
    
    do{
    	system("cls");
    	
		printf("\nDigite o nome do material:\n");
		getchar();
    	fgets(nome, sizeof(nome), stdin);

    	printf("\nDigite a descricao do material:\n");
    	fgets(descricao, sizeof(descricao), stdin);
    	
    	printf("\nDigite a categoria do material:\n");
    	fgets(tipoMaterial, sizeof(tipoMaterial), stdin);
    	
    	printf("\nDigite o preco do material:\n");
    	fflush(stdin);
    	scanf("%f", &preco);
    			
		strcpy(materiais[contadorMaterial].nome, nome);
		strcpy(materiais[contadorMaterial].descricao, descricao);
		strcpy(materiais[contadorMaterial].tipoMaterial, tipoMaterial);
		materiais[contadorMaterial].preco = preco;
		materiais[contadorMaterial].ativo = 1;
		contadorMaterial++;
    	
    	getchar();
    	printf("\nDigite 1 para Cadastrar mais Pacientes.");
    	printf("\nDigite 0 para Sair.\n");
    		fflush(stdin);
    	scanf("%d", &escolha);
	}while(escolha!=0); 
}


//Buscar---------------------------------------------------------------------------------------------------

void buscarDentistas(){
	

	char nome[50];
	int escolha=1;
	int CRO;
	int i;
	
	do{
		system("cls");
		printf("Digite o nome do dentista:\n");
		fgets(nome, sizeof(nome), stdin);

		for(i=0;  i<contadorDentista; i++){
			if(strstr(dentistas[i].nome, nome)!=NULL){
				printf("\n\n--------------------------------------------\n\n");

				printf("\n\nID: %d", i+1);
				printf("\nCRO: %d ", dentistas[i].CRO);
				printf("\nNome: %s", dentistas[i].nome);
				printf("Endereco: %s", dentistas[i].endereco);
				printf("Telefone: %d", dentistas[i].telefone);
				
				printf("\n\n--------------------------------------------\n\n");
			}
		}
		printf("\n\nDigite 1 para buscar novamente:\n");
		printf("Digite 0 para sair:\n");
		scanf("%d", &escolha);
		getchar();
	}while(escolha!=0);

}
void buscarPacientes(){

}
void buscarMateriais(){

}


//Listar---------------------------------------------------------------------------------------------------

void listarDentistas(){
	system("cls");
	
	int i, escolha;
	
	printf("Lista de Dentistas:\n\n");
	
	for(i=0; i<contadorDentista; i++){
		
		if(dentistas[i].ativo == 1){
			printf("ID: %d \n", i+1);
			printf("\nCRO: %d ", dentistas[i].CRO);
			printf("\nNome: %s", dentistas[i].nome);
			printf("\nEndereco: %s", dentistas[i].endereco);
			printf("\nTelefone: %d", dentistas[i].telefone);
			
			printf("\n\n--------------------------------------------\n");
		}
		
	}
	
}

void listarPacientes(){
	system("cls");
	
	int i, escolha;
	
	printf("Lista de Pacientes:\n\n");
	
	for(i=0; i<contadorPaciente; i++){
		
		if(pacientes[i].ativo == 1){
			
			printf("ID: %d \n", i+1);
			printf("\nNome: %s", pacientes[i].nome);
			printf("\nNome responsavel: %s", pacientes[i].nomeResponsavel);
			printf("\nTelefone: %d", pacientes[i].telefone);
			printf("\nTelefone responsavel: %d", pacientes[i].telefoneResponsavel);
			printf("\nEndereco: %s", pacientes[i].endereco);
			printf("\nData de nascimento: %d", pacientes[i].dataNascimento);
			
			printf("\n\n--------------------------------------------\n");
		}
		
	}
	
}

void listarMateriais(){
	system("cls");
	
	int i, escolha;
	
	printf("Lista de Materiais:\n\n");
	
	for(i=0; i<contadorMaterial; i++){
		
		if(materiais[i].ativo == 1){

			printf("\n\n--------------------------------------------\n");
			
			printf("ID: %d\n ", i+1);
			printf("\nNome: %s", materiais[i].nome);
			printf("\nCategoria: %s", materiais[i].tipoMaterial);
			printf("\nDescricao: %d", materiais[i].descricao);
			printf("\nPreco: %d", materiais[i].preco);
			
			printf("\n\n--------------------------------------------\n");
		}
		
	}
	getchar();
	
}


//Remover-----------------------------------------------------------------------------------------------------------

void removerPaciente(){
	int id;

	listarPacientes();

	printf("\n\nDigite o ID do paciente a ser removido:");
	scanf("%d", &id);
	--id;
	pacientes[id].ativo = 0;
	printf("\n\nPaciente excluido com sucesso. \nAperte enter para voltar ao menu:\n");
	getchar();
}

void removerDentista(){
	int id;

	listarDentistas();

	printf("\n\nDigite o ID do dentista a ser removido:");
	scanf("%d", &id);
	--id;
	dentistas[id].ativo = 0;
	printf("\n\nDentista excluido com sucesso. \nAperte enter para voltar ao menu:\n");
	getchar();
}

void removerMaterial(){
	int id;

	listarMateriais();

	printf("\n\nDigite o ID do material a ser removido:");
	scanf("%d", &id);
	--id;
	materiais[id].ativo = 0;
	printf("\n\nMaterial excluido com sucesso. \nAperte enter para voltar ao menu:\n");
	getchar();
}
