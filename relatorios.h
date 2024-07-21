#include "visual.h"
void RelatorioEditoras(TpDescritor desc){
	
	pEditora *editora;
	pLivros *livros;
	pListaAutor *listaautor;
	pAutor *autor;
	editora = desc.inicio;
	int c=0;
	while(editora!=NULL){
		c=0;
		ClearRelatorio();
		gotoxy(23,6);
		printf("# # # RELATORIO POR EDITORAS # # #");
		gotoxy(5,9);
		printf("Editora: %s",editora->nomeEditora);
		livros = editora->livros;
		while(livros!=NULL){
			gotoxy(5,11);
			
			
			printf("Titulo: %s",livros->titulo);
			gotoxy(5,13);
			printf("Ano: %d",livros->ano);
			gotoxy(5,15);
			printf("Pags: %d",livros->pag);
			
			listaautor = livros->listaAutor;
			while(listaautor->prox!=NULL){
				autor = listaautor->autor;
				ClearPartePequena();
				gotoxy(5,17);
				printf("NomeAutor: %s",autor->nomeAutor);
				gotoxy(5,19);
				printf("SobreomeAutor: %s",autor->sobrenomeAutor);
				ClearMensagem();
				printf("Aperte [Enter] para ir para proxima Pagina");
				getch();
				listaautor = listaautor->prox;
				c++;
			}
			
			livros = livros->prox;
		}
		if(c==0){
			gotoxy(5,11);
			printf("Editora sem livros :/");
			getch();
		}
		editora = editora->prox;
	}
	ClearMensagem();
	printf("Fim! Pressione 2x [Enter] para voltar ao Menu Principal");
	getch();
}

void RelatorioEditoras2(TpDescritor desc){
	
	pEditora *editora;
	pLivros *livros;
	pListaAutor *listaautor;
	pAutor *autor;
	editora = desc.inicio;
	while(editora!=NULL){
		printf("\n");
		printf("\nEditora: %s",editora->nomeEditora);
		livros = editora->livros;
		while(livros!=NULL){
			printf("\nTitulo: %s",livros->titulo);
			printf("\nAno: %d",livros->ano);
			printf("\nPags: %d",livros->pag);
			listaautor = livros->listaAutor;
			autor = listaautor->autor;
			while(autor->prox!=NULL){
				printf("\nNomeAutor: %s",autor->nomeAutor);
				printf("\nSobreomeAutor: %s",autor->sobrenomeAutor);
				
				autor = autor->prox;
			}
			
			livros = livros->prox;
		}
		editora = editora->prox;
	}
	printf("\nFim");
}


void RelatorioLivroPorAutores(TpDescritor desc){
	
	pEditora *editora;
	pLivros *livros;
	pListaAutor *listaautor;
	pAutor *autor;
	editora = desc.inicio;
	while(editora!=NULL){
		printf("\n");
	
		livros = editora->livros;
		
		while(livros!=NULL){
			printf("\nTitulo: %s",livros->titulo);
			listaautor = livros->listaAutor;
			while(listaautor->prox!=NULL){
				autor = listaautor->autor;
				printf("\nNomeAutor: %s",autor->nomeAutor);
				printf("\nSobreomeAutor: %s",autor->sobrenomeAutor);
				
				listaautor = listaautor->prox;
			}
			
			livros = livros->prox;
		}
		editora = editora->prox;
	}
	ClearMensagem();
	printf("Fim! Pressione 2x [Enter] para voltar ao Menu Principal");
}

void RelatorioAutores(TpDescritor desc, pAutor *listaautores){
	pAutor *aux = listaautores;
	pEditora *editora;
	pLivros *livros;
	pListaAutor *listaautor;
	pAutor *autor;
	int c = 0;
	while(aux!=NULL){
		editora = desc.inicio;
		c=0;
		while(editora!=NULL){
			livros = editora->livros;
			
			while(livros!=NULL){
				listaautor = livros->listaAutor;
				
				while(listaautor->prox!=NULL){
					
					autor = listaautor->autor;
//					printf("%s",aux->sobrenomeAutor);
//					printf("%s",autor->sobrenomeAutor);
					if(strcmp(autor->sobrenomeAutor,aux->sobrenomeAutor)==0){
						
						ClearRelatorio();
						
						gotoxy(22,6);
						printf("# # # RELATORIO POR AUTORES # # #");
						gotoxy(5,9);
						printf("Nome: %s",autor->nomeAutor);
	
						gotoxy(5,11);
						printf("Sobreome: %s",autor->sobrenomeAutor);
				
						gotoxy(5,13);
						printf("Livro: %s",livros->titulo);
				
						gotoxy(5,15);
						printf("Ano: %d",livros->ano);
		
						gotoxy(5,17);
						printf("Pags: %d",livros->pag);
				
						gotoxy(5,19);
						printf("Editora: %s",editora->nomeEditora);
						
						ClearMensagem();
						printf("Aperte [Enter] para ir para proxima Pagina");
						getch();
						
						c++;
					}
					listaautor = listaautor->prox;
				}
				
				livros = livros->prox;
			}
			editora = editora->prox;
		}
		if(c==0){
			ClearRelatorio();
						
			gotoxy(22,6);
			printf("# # # RELATORIO POR AUTORES # # #");
			gotoxy(5,9);
			printf("Nome: %s",aux->nomeAutor);

			gotoxy(5,11);
			printf("Sobreome: %s",aux->sobrenomeAutor);
	
			gotoxy(5,13);
			printf("Não possui livros :/");
			
			ClearMensagem();
			printf("Aperte [Enter] para ir para proxima Pagina");
			getch();
			
			
		}
		aux = aux->prox;
	}
	ClearMensagem();
	printf("Fim! Pressione 2x [Enter] para voltar ao Menu Principal");
	getch();
}


int AutorEstaEmLista(pAutor *autor, pListaAutor *listaAutor) {
    pListaAutor *atual = listaAutor;
    while (atual->autor != NULL) {
        if (strcmp(atual->autor->nomeAutor, autor->nomeAutor) == 0 && strcmp(atual->autor->sobrenomeAutor, autor->sobrenomeAutor) == 0) {
            return true;
        }
        atual = atual->prox;
    }
    return 0;
}

void ExibirAutoresSemLivros(pAutor *listaAutores, TpDescritor Desc) {
    pAutor *autor = listaAutores;

    while (autor != NULL) {
        int autorTemLivro = 0;
        
        pEditora *editora = Desc.inicio; 
        while (editora != NULL && !autorTemLivro) { // Percorre todas as editoras
            pLivros *livro = editora->livros;
            while (livro != NULL && !autorTemLivro) { // Percorre todos os livros da editora
                if (AutorEstaEmLista(autor, livro->listaAutor)) {// Verifica se o autor está na lista de autores do livro
                    autorTemLivro = 1;
                }
                livro = livro->prox;
            }
            editora = editora->prox;
        }

        if (autorTemLivro==0) { // Se o autor não tem livros, exibe suas informações
       	 	ClearRelatorio();
        	gotoxy(16,7);
        	printf("# # # Relatorio Autores sem Livros # # #");
        	gotoxy(5,13);
            printf("Nome Autor: %s", autor->nomeAutor);
            gotoxy(5,15);
            printf("Sobrenome Autor: %s", autor->sobrenomeAutor);
            gotoxy(5,17);

            ClearMensagem();
        	printf("Aperte [Enter] para ir para proxima Pagina");
        	getch();
        	ClearRelatorio();
        }else{
        	
        	gotoxy(16,7);
        	printf("# # # Relatorio Autores sem Livros # # #");
        	gotoxy(30,13);
            printf("Sem relatorios!!!");
        }

        autor = autor->prox;
    }
    ClearMensagem();
	printf("Fim! Pressione 2x [Enter] para voltar ao Menu Principal");
	getch();
}
