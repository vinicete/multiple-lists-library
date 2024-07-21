void exibeLivros(){
	FILE *Ptr = fopen("livros.dat","rb+");
	pImportarLivros Livro;
	
	fread(&Livro,sizeof(pImportarLivros),1,Ptr);
	while(!feof(Ptr)){
		gotoxy(16,7);
        printf("# # # Relatorio Autores sem Livros # # #");
		gotoxy(5,10);
        printf("%s",Livro.autor);
        gotoxy(5,12);
        printf("%s",Livro.titulo);
        gotoxy(5,14);
        printf("%s",Livro.editora); 
		gotoxy(5,16);
        printf("%d",Livro.ano);
		gotoxy(5,18);
        printf("%d",Livro.pag);   
            
		
		
		ClearMensagem();
		printf("Aperte [Enter] para ir para proxima Pagina");
		getch();
		ClearRelatorio();
		
		
		fread(&Livro,sizeof(pImportarLivros),1,Ptr);
	}
	
	getch();
	fclose(Ptr);
}

void exibeEditora(TpDescritor Desc){
	pEditora *E = Desc.inicio;
	while(E!=NULL){
		printf("\n%s",E->nomeEditora);
		E=E->prox;
	}
}
