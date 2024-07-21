#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<locale.h>
#include <ctype.h>
#include <conio2.h>
#include <windows.h>
#include "tad.h"
#include "relatorios.h"
#include "exibicoes.h"
#include "visual.h"

///perguntar se precisa exibir o arquivo binario
void ImportarDados(){
	
	FILE *Ptr = fopen("livros.txt","r");
	FILE *PtrAux = fopen("livros.dat","wb");
	
	pImportarLivros livro;
	
	if(Ptr == NULL || PtrAux == NULL){
		printf("\nErro ao abrir arquivos");
	}
	else{
		fscanf(Ptr,"%[^|]%*c%[^|]%*c%[^|]%*c%d%*c%d\n",&livro.autor,&livro.titulo,&livro.editora,&livro.ano,&livro.pag);
		while(!feof(Ptr)){
			
			fwrite(&livro,sizeof(pImportarLivros),1,PtrAux);
			
			fscanf(Ptr,"%[^|]%*c%[^|]%*c%[^|]%*c%d%*c%d\n",&livro.autor,&livro.titulo,&livro.editora,&livro.ano,&livro.pag);
		}
		fwrite(&livro,sizeof(pImportarLivros),1,PtrAux);
		printf("\nArquivos importados com sucesso!\n");
	}
	fclose(Ptr);
	fclose(PtrAux);

}


char Menu(){
		gotoxy(7, 7);
	    printf("   ***MENU***");
	    gotoxy(5, 9);
        printf("[A] Excluir Livro");
        gotoxy(5,11);
        printf("  ***Relatorios***");
        gotoxy(5, 13);
        printf("[B] Livros p/ autor");
        gotoxy(5, 14);
        printf("[C] Livros p/ editora");
        gotoxy(5, 15);
        printf("[D] Autores sem livro");
        gotoxy(5, 17);
        printf("[E] Exibições");
        gotoxy(5, 19);
        printf("[ESC] Sair");
        ClearMensagem();
        printf("Escolha uma opção do Menu: ");
        return toupper(getche());
}

char MenuExibicao(){
	
		gotoxy(41,7);
		printf("# # # Menu de Exibição # # #");
		gotoxy(35,10);
		printf("[A] - Arquivo Binario");
		gotoxy(35,11);
		printf("[B] - Lista de Autores");
		gotoxy(35,12);
		printf("[ESC] - Voltar");
		
		gotoxy(35,14);
		return toupper(getch());
		
}

int main(){
	setlocale(LC_ALL,"Portuguese");
	TpDescritor Descritor; 
	pAutor *ListaDeAutores;
	Inicializa(Descritor);
	int opcao,opp;
	char tituloLivro[MAX];
	
	ImportarDados();
	ListaDeAutores = CriarListaAutores();
	InserirOrdenadoEditora(Descritor,ListaDeAutores);
	
    do {
    	//clrscr();
    	ClearTela();
		Formulario();
		opcao = Menu();
		clrscr();
        
        switch(opcao) {
            case 'A':
            	ClearTela();
				Formulario2();
               	excluirLivro(Descritor);
                break;
            case 'B':
            	ClearTela();
				Formulario2();
                RelatorioAutores(Descritor,ListaDeAutores);
                getch();
                break;
            case 'C':
            	ClearTela();
				Formulario2();
                RelatorioEditoras(Descritor);
                getch();
                break;
            case 'D':
            	ClearTela();
				Formulario2();
                ExibirAutoresSemLivros(ListaDeAutores, Descritor);
                getch();
                break;
            case 'E':
                //exibeLivros();
                ClearTela();
				Formulario();
                opp = MenuExibicao();
                
                switch(opp){
                	case 'A':
                		ClearTela();
						Formulario2();
						exibeLivros();
						getch();
						
                		break;
                		
                	case 'B':
                		ClearTela();
						Formulario();
                		ExibirListaDeAutores(ListaDeAutores);
                		getch();
                		break;
                }
                
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 27);
	getch();

	
	
	
	
	return 0;
}
