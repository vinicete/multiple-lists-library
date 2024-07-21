#define MAX 100
#include "visual.h"
struct pAutor{
	char nomeAutor[MAX];
	char sobrenomeAutor[MAX];
	pAutor *prox;
};

struct pListaAutor{
	
	pAutor *autor;
	pListaAutor *prox;
};

struct pLivros{
	
	char titulo[MAX];
	int ano,pag;
	pListaAutor *listaAutor;
	pLivros *prox,*ant;
	
};

struct pEditora{
	
	char nomeEditora[MAX];
	pLivros *livros;	
	pEditora *prox;
};

struct TpDescritor{
	int quant;
	pEditora *inicio,*fim;
};

struct pImportarLivros{
	
	char autor[MAX];
	char titulo[MAX];
	char editora[MAX];
	int ano,pag;
	pListaAutor *listaAutor;
	pLivros *prox,*ant;
	
};

////////////////////////////////////
////////////////////////////////////

void Inicializa(TpDescritor &Descritor){
	Descritor.inicio = Descritor.fim = NULL;
	Descritor.quant=0;
}

pEditora *novaCaixa(char elem[]){
	pEditora *Caixa = new pEditora;
	
	strcpy(Caixa->nomeEditora, elem);
	Caixa->prox=NULL;
	
	return Caixa;
}

pListaAutor *InserirInicio(pListaAutor *Lista, char Elemento[], pAutor *ListaAutores){  
	
	pListaAutor *NovaBox = new pListaAutor;
	
	NovaBox->prox = NULL;
	
	pAutor *atual;
	
	// separar nomeAutor
	char *aux;
	int cont=0;
	char nome[50],sobrenome[50];
	FILE *nomeSeparar = fopen("nomeAutor.txt","w");
	fputs(Elemento,nomeSeparar);
	fclose(nomeSeparar);
	nomeSeparar = fopen("nomeAutor.txt","r");
	fscanf(nomeSeparar,"%[^,],%[^,]\n",&sobrenome,&nome);
	fclose(nomeSeparar);
	remove("nomeAutor.txt");
	
	atual = ListaAutores;
	while(atual!=NULL && strcmp(sobrenome,atual->sobrenomeAutor)!=0){
		atual = atual->prox;	
	}
	
	if(strcmp(sobrenome,atual->sobrenomeAutor)==0){
		NovaBox->autor = atual;
	}
	
	
	
	NovaBox ->prox = Lista;
	Lista = NovaBox; 

	return Lista;
}

pEditora *CarregarStruct(pImportarLivros &livroimp,pAutor *ListaAutores,TpDescritor Desc){
    char *tok;

	pEditora *editora = new pEditora;
    strcpy(editora->nomeEditora, livroimp.editora);
    editora->prox = NULL;

    pLivros *livro = new pLivros;
    
    editora->livros = livro;
    livro->ant = NULL;
    strcpy(livro->titulo, livroimp.titulo);
    livro->ano = livroimp.ano;
    livro->pag = livroimp.pag;
    livro->prox = NULL;

    pListaAutor *autores = new pListaAutor;
    pAutor *autor = new pAutor;

    tok = strtok(livroimp.autor, ";");
    while (tok) {
        autores = InserirInicio(autores,tok,ListaAutores);//Fazer a mudança do leandro
		tok = strtok(NULL, ";");

	}
	livro->listaAutor = autores; // estava sendo definido na linha 119, antes do while
	return editora;
}

pLivros *CarregarStructExistente(pImportarLivros &livroimp, pAutor *ListaAutores, pEditora *editora){
	
	char *tok;
	pLivros *livroaux = new pLivros;
	
	livroaux->ano = livroimp.ano;
	livroaux->pag = livroimp.pag;
	strcpy(livroaux->titulo,livroimp.titulo);
	
	livroaux->prox = editora->livros;
	editora->livros = livroaux;
	
	pListaAutor *autores = new pListaAutor;
    pAutor *autor = new pAutor;

    tok = strtok(livroimp.autor, ";");
    while (tok) {
        autores = InserirInicio(autores,tok,ListaAutores);//Fazer a mudança do leandro
		tok = strtok(NULL, ";");

	}
	livroaux->listaAutor = autores;
	
	return livroaux;
	
}
	
pAutor *CriarListaAutores(){
	
	pImportarLivros livroimp;
	pAutor *autor = NULL;
	FILE *Ptr = fopen("livros.dat","r");
	char *tok;
	
	if(Ptr == NULL){
		printf("\nErro ao abrir arquivo");
		return 0;
	}
	else{
		
		
		fread(&livroimp,sizeof(pImportarLivros),1,Ptr);
		while(!feof(Ptr)){
			
			pAutor *novo = new pAutor;
			tok = strtok(livroimp.autor, ";");
			while(tok){
				
				
				char nome[50],sobrenome[50];
				FILE *nomeSeparar = fopen("nomeAutor.txt","w");
				fputs(tok,nomeSeparar);
				fclose(nomeSeparar);
				nomeSeparar = fopen("nomeAutor.txt","r");
				fscanf(nomeSeparar,"%[^,],%[^,]\n",&sobrenome,&nome);
				fclose(nomeSeparar);
				remove("nomeAutor.txt");
				
				novo = new pAutor;
				strcpy(novo->nomeAutor,nome);
				strcpy(novo->sobrenomeAutor,sobrenome);
				novo->prox = NULL;
				
				novo->prox = autor;
				autor = novo;
				
				tok = strtok(NULL, ";");
			}
			
			
			fread(&livroimp,sizeof(pImportarLivros),1,Ptr);
		}
		
	}
	fclose(Ptr);
	return autor;
}

void ExibirListaDeAutores(pAutor *lista){
	
	pAutor *aux;
	
	aux = lista;
	while(aux!=NULL){
		gotoxy(41,7);
		printf("# # # Autores # # #");
		gotoxy(35,10);
		printf("Nome Autor: %s",aux->nomeAutor);
		gotoxy(35,11);
		printf("Sobrenome Autor: %s",aux->sobrenomeAutor);
		aux = aux->prox;
		gotoxy(35,14);
		printf("Nome Autor: %s",aux->nomeAutor);
		gotoxy(35,15);
		printf("Sobrenome Autor: %s",aux->sobrenomeAutor);
		aux = aux->prox;
		ClearMensagem();
		printf("Aperte [Enter] para ir para proxima Pagina");
		getch();
		ClearAreaExibicao();
	}
	ClearMensagem();
	printf("Fim! Pressione [Enter] para voltar ao Menu Principal");
	
}

void InserirOrdenadoEditora(TpDescritor &Desc,pAutor *ListaAutores) {
	
	pEditora *aux;
	pImportarLivros livroimp;
	char *tok;
	FILE *Ptr = fopen("livros.dat", "rb");
	
	if (!Ptr) {
		printf("\nErro ao abrir arquivo!\n");
		return;
	}
	

	while(fread(&livroimp, sizeof(pImportarLivros),1,Ptr)) {
		
	    aux = Desc.inicio;
	    while(aux!=NULL && strcmp(aux->nomeEditora,livroimp.editora)!=0){  //Busca para achar editoras com o mesmo nome
	    	aux = aux->prox;
	    }
	    
	    if(aux != NULL && strcmp(aux->nomeEditora,livroimp.editora)==0){
	    	pLivros *livroaux = new pLivros;
	    	
	    	livroaux = CarregarStructExistente(livroimp,ListaAutores,aux);
	    	
	    	aux->livros = livroaux;
	    }
	    else{
	    	pEditora *NC = new pEditora;
			NC = CarregarStruct(livroimp,ListaAutores,Desc);
	
			if (Desc.quant == 0) {
		        Desc.inicio = Desc.fim = NC;
		    } 
			else {
		        if (strcmp(NC->nomeEditora, Desc.inicio->nomeEditora) <= 0) { // 1 < 2
		            NC->prox = Desc.inicio;
		            Desc.inicio = NC;
		        } 
				else if (strcmp(NC->nomeEditora, Desc.fim->nomeEditora) >= 0) {
		            Desc.fim->prox = NC;
		            Desc.fim = NC;
		        }
				else {
		            pEditora *current = Desc.inicio;
		            while (current->prox!=NULL && strcmp(NC->nomeEditora, current->prox->nomeEditora) > 0) {
		                current = current->prox;
		            }
		            NC->prox = current->prox;
					current->prox = NC;
				
	            
		        }
		    }
		    Desc.quant++;
	    }
	    
	    
	}
		
	    
	
	fclose(Ptr);
	printf("\nOs livros foram inseridos ordenados\n");
}

void excluirLivro(TpDescritor &Desc) {
    FILE *file = fopen("livros.dat", "rb+");
    FILE *temp = fopen("temp.dat", "wb+");
    pImportarLivros livroImport;
    pEditora *editora;
    pLivros *livro, *prevLivro = NULL;
    char tituloLivro[MAX];
    
    if (file == NULL || temp == NULL) {
    	ClearMensagem();
        printf("Não foi possível abrir o arquivo!");
        return;
    }
	gotoxy(30,6);
	printf("# # # Exclusao Livro # # #");
	ClearMensagem();
	printf("Excluir livro pelo Titulo! ");
	gotoxy(5,10);
    printf("Digite o título do livro a excluir: ");
    fflush(stdin); 
    gotoxy(5,11);
	gets(tituloLivro);

    editora = Desc.inicio;
    int achou = 0;

    // Remover o livro da lista de livros da editora
    while (editora != NULL && !achou) {
        livro = editora->livros;
        prevLivro = NULL;
        while (livro != NULL && !achou) {
            if (strcmp(livro->titulo, tituloLivro) == 0) {
                if (prevLivro == NULL) {
                    editora->livros = livro->prox;
                } else {
                    prevLivro->prox = livro->prox;
                }
                if (livro->prox != NULL) {
                    livro->prox->ant = prevLivro;
                }
                delete livro;
                achou = 1;
            } else {
                prevLivro = livro;
                livro = livro->prox;
            }
        }
        editora = editora->prox;
    }

    // Remover o livro do arquivo
    fread(&livroImport, sizeof(pImportarLivros), 1, file);
    while (!feof(file)){
        if (strcmp(livroImport.titulo, tituloLivro) != 0) {
            fwrite(&livroImport, sizeof(pImportarLivros), 1, temp);
        }
        fread(&livroImport, sizeof(pImportarLivros), 1, file);
    }
    
    
    fclose(file);
    fclose(temp);
    remove("livros.dat");
    rename("temp.dat", "livros.dat");

    if (achou) {
    	gotoxy(5,16);
        printf("Livro '%s' excluído com sucesso.", tituloLivro);
    } else {
    	gotoxy(5,16);
        printf("Livro '%s' não encontrado.", tituloLivro);
    }
    ClearMensagem();
    printf("Aperte [ENTER] para continuar");
    getch();
}


