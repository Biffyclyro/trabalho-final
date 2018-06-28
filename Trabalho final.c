#include<stdio.h>
#include<string.h>
#define TAM 10


struct alunos{
	char nome[20], sobre[50], email[30];
	int matricula, materias[5], grade[4][5];

};

struct materias{
	char nome[20], dia[10], abrev[10], prof[30];
	int carga, hora[2], cod;
	int grid[2][2];
};

struct dia{
	char nome[10], materias[10];

};


typedef struct dia Dia;
typedef struct alunos Alunos;
typedef struct materias Materias;
void consultaDisc(Materias materia[5]);
void retornaMat(Materias materia[5], int mat, char a[40]);
void imprime(Alunos aluno[TAM], Materias materia[5], int matri);
void cadastroAluno(Alunos aluno[TAM]);
void cadastroMateria(Alunos aluno[TAM], Materias materia[5]);
void materiaSemestre(Materias materia[5]);
void novoAluno(Alunos aluno[TAM], Materias materia[5]);
void consultaAluno(Alunos aluno[TAM],Materias materia[5]);

main(){
	int i, j, k, x, y=0;
	
	Alunos aluno[TAM];
	Materias materia[5];
	Dia dias[10];
	
	
	for(k=0; k<TAM; k++){
		aluno[k].matricula=0;
		for(i=0; i<4; i++){
			for(j=0; j<5; j++){
			aluno[k].grade[i][j]=0;
			aluno[k].materias[j]=0;
			}
		}
	}
	
	
	cadastroAluno(aluno);
	
	//retornaMat(aluno, materia, 0, a);
	//puts(a);
	
	
	materiaSemestre(materia);
	while(y==0){
	//	system("cls");
		printf("Entre com a opcao:\n");
		printf("1. Consulta de aluno.\n");
		printf("2. Cadastro de materia.\n");		
		printf("3. Cadastro de aluno.\n");
		printf("4. Contultar disciplinas.\n");
		printf("5. Sair do programa.\n");
		scanf("%d",&x);
		
		
			switch(x){
				case 1:{
					system("cls");
					consultaAluno(aluno, materia);
					break;
				}
		
				case 2:{
					system("cls");
					cadastroMateria(aluno, materia);
					break;
				}
		
				
				case 3:{
					system("cls");
					novoAluno(aluno, materia);
					break;
				}
				case 4:{
					consultaDisc(materia);
					break;
				}
				case 5:{
					printf("Saindo do programa...");
					y++;					
					break;
				}
				default :{
					printf("Valor errado!!\n");
					sleep(1);
					break;
				}
			
		
			}
	}

}

void cadastroMateria(Alunos aluno[TAM], Materias materia[5]){
	int y=0, x=0, i, j, a, b, c, d, index, index2, matri;
	char resp='y';
	printf("Entre com a matricula do aluno: \n");
	scanf("%d",&matri);
	
	for(j=0; j<TAM; j++){
			if(aluno[j].matricula==matri)index=j;


		}
	
	
	while(resp!='n'){
		
		printf("Entre com o codigo da materia: \n");
		scanf("%d",&y);
		//scanf("%d",&aluno[0].materias[0]);
		//printf("%d",aluno[0].materias[0]);
		for(i=0; i<5; i++){
			if(y==materia[i].cod)index2=i;
			
		}
		
		
		a=materia[index2].grid[0][0];
		b=materia[index2].grid[0][1];
		c=materia[index2].grid[1][0];
		d=materia[index2].grid[1][1];
		if(aluno[index].grade[a][b]!=0 || aluno[index].grade[c][d]!=0){
			printf("Conflito de horarios!!\n");
			
			sleep(2);
			
		}else{
			aluno[index].grade[a][b]=materia[index2].cod;
			aluno[index].grade[c][d]=materia[index2].cod;
			aluno[index].materias[index2]=materia[index2].cod;
		}
	//	if(aluno[index].grade[a][b]==0){
			
			
			
	//	}		
		
	/*	if(){			
			printf("Conflito de horarios!!\n");
			sleep(2);*/
			
		
	//	}
	//	if(aluno[index].grade[c][d]==0){
			
			
			
	//	}
		
		system("cls");
		printf("Mais alguma materia? (S/N)\n");
		scanf(" %c", &resp);
		system("cls");
		
		
		
	}
		
		
	/*	for(i=0; i<5; i++){
			if(aluno[index].materias[i]==y)printf("Materia ja cadastrada!\n");
			if(aluno[index].materias[i]==127 && y == 132) printf("Horario de terca 13:00 ja ocupado!!\n");
			if(aluno[index].materias[i]==132 && y == 127) printf("Horario de terca 13:00 ja ocupado!!\n");
			if(aluno[index].materias[i]==143 && y == 135) printf("Horario de sexta 10:00 ja ocupado!!\n");
			if(aluno[index].materias[i]==135 && y == 143) printf("Horario de sexta 10:00 ja ocupado!!\n");
			if(aluno[index].materias[i]==0)aluno[index].materias[i]=y;
			
		}*/



}

void consultaAluno(Alunos aluno[TAM],Materias materia[5]){
	int i, j, index, mark=0 ;
	char nome[30], nomeLow[30]={}, nomeCompleto[50]={};
	printf("Entre com nome do aluno, ou parte dele: \n");
	fflush(stdin);
	gets(nome);
	for(i=0; i<TAM; i++){
		int comp=0;
	/*	if(strcmp(aluno[i].nome, nome)==0){
			index=i;
			fflush(stdin);
			strcpy(nomeCompleto, aluno[i].nome);
			fflush(stdin);
			strcat(strcat(nomeCompleto, " "),aluno[i].sobre);
			printf("\n");
			puts(nomeCompleto);
			printf("\n");			
			puts(aluno[i].email);
			printf("\nMatricula: %d\n\n",aluno[i].matricula);
			fflush(stdin);
			imprime(aluno, materia, aluno[i].matricula);
			fflush(stdin);
			 */
			
			
	//	}
		for(j=0; j<strlen(nome); j++){
			
			strcpy(nomeLow, aluno[i].nome);
			strlwr(nomeLow);
			if(nome[j]==nomeLow[j]){
				comp++;
				
			}else{
				comp=0;
			}
				
			if(j+1==strlen(nome)&&comp>=3){
				mark++;
				index=i;
				fflush(stdin);
				strcpy(nomeCompleto, aluno[i].nome);
				fflush(stdin);
				strcat(strcat(nomeCompleto, " "),aluno[i].sobre);
				printf("\n");
				puts(nomeCompleto);
				printf("\n");
				fflush(stdin);
				puts(aluno[i].email);
				printf("\nMatricula: %d\n\n",aluno[i].matricula);
				fflush(stdin);
				imprime(aluno, materia,aluno[i].matricula);
				fflush(stdin);
				return;
					
				
			}
			
					
		}
	
		
	}
		if(i==TAM && mark==0){
			system("cls");
			printf("Aluno nao encontrado.\n");
			sleep(2);
			system("cls");
			return;
		}
	
	
}

void novoAluno(Alunos aluno[TAM], Materias materia[5]){
	int i, j, k, l, x=0, index, arroba=0, ponto=0;
	char email[30];
	
	for(i=0; i<TAM; i++){
		if(aluno[i].matricula==0)index=i;
	}
	for(k=0; k<4; k++){
		for(l=0; l<5; l++){
			aluno[index].grade[k][l]=0;
		}
	}
	fflush(stdin);
	printf("Entre com o nome do novo aluno: \n");
	gets(aluno[index].nome);	
	fflush(stdin);
	printf("Entre com o sobrenome do novo aluno: \n");
	gets(aluno[index].sobre);
	fflush(stdin);
	printf("Entre com o numero da matricula: \n");
	
	scanf("%d",&aluno[index].matricula);
	while(x < 3){
		fflush(stdin);
		printf("Entre com email do novo aluno: \n");
		fflush(stdin);
		gets(email);
		fflush(stdin);
		x=0;
		for(j=0; j<30; j++){
			if(email[j]=='@'){				
				arroba=j;
			}
			if(email[j]=='@' && j<3){
				printf("Email deve ter ao menos 3 caracteres \n");
				
			
			}else if(email[j]=='@' && j>=3){
				x++;
			}
			if(email[j]=='.'){
				
				
				ponto=j;				
			}
			if(email[j]=='.' && j-arroba < 3){
				printf("Email deve tar ao menos 3 caracteres apos o @ \n");
				
			}else if(email[j]=='.' && j-arroba >= 3){
				x++;
			}
			if(email[j]=='\0' && j-ponto < 3){
				printf("Email deve ter ao menos 2 caracteres apos o .\n",ponto);
				
				j=30;
			}else if(email[j]=='\0' && j-ponto >= 3){
				x++;
			}
			if(x==3){
				system("cls");
				strcpy(aluno[index].email, email);
				printf("Va para o cadastro das materias!!\n");
				sleep(2);
				
			}
		}
		
	}
	//cadastroMateria(aluno,materia);
	
}


void cadastroAluno(Alunos aluno[TAM]){



	strcpy(aluno[0].nome, "Julia");
	strcpy(aluno[0].sobre, "Piluski");
	strcpy(aluno[0].email, "asjaosjoasjoas@hotmail.com");
	aluno[0].matricula=1220;
	aluno[0].materias[0]=0122;
	aluno[0].materias[1]=0127;
	aluno[0].materias[2]=0143;
	aluno[0].materias[3]=0;
	aluno[0].materias[4]=0;
	aluno[0].grade[0][0]=0122;
	aluno[0].grade[1][1]=0122;
	aluno[0].grade[2][1]=0127;
	aluno[0].grade[3][2]=0127;
	aluno[0].grade[1][4]=0143;
	
	
	
	
	strcpy(aluno[1].nome, "Gabriela");
	strcpy(aluno[1].sobre, "Trevisan Leturiondo");
	strcpy(aluno[1].email, "gagabriel@gmail.com");
	aluno[1].matricula=1330;
	aluno[1].materias[0]=0122;
	aluno[1].materias[1]=0132;
	aluno[1].materias[2]=0135;
	aluno[1].materias[3]=0;
	aluno[1].materias[4]=0;
	aluno[1].grade[0][0]=0122;
	aluno[1].grade[1][1]=0122;
	aluno[1].grade[2][1]=0132;
	aluno[1].grade[3][2]=0132;
	aluno[1].grade[1][4]=0135;
	aluno[1].grade[1][2]=0135;
	
	
	strcpy(aluno[2].nome, "Rafaella");
	strcpy(aluno[2].sobre, "Marques Farias");
	strcpy(aluno[2].email, "rafaell@hotmail.com");
	aluno[2].matricula=1440;
	aluno[2].materias[0]=0122;
	aluno[2].materias[1]=0127;
	aluno[2].materias[2]=0143;
	aluno[2].materias[3]=0;
	aluno[2].materias[4]=0;
	aluno[2].grade[0][0]=0122;
	aluno[2].grade[1][1]=0122;
	aluno[2].grade[2][1]=0127;
	aluno[2].grade[3][2]=0127;
	aluno[2].grade[1][4]=0143;


}

void imprime(Alunos aluno[TAM], Materias materia[5], int matri){
	int i, j, index;
	char a[40]={};
/*	printf("Entre com a matricula: \n");
	scanf("%d", &matri); */
	for(j=0; j<TAM; j++){
		if(aluno[j].matricula==matri)index=j;
	} 
	
	
	
	printf("        Seg        Ter       Qua       Qui       sex\n\n");
	 for(i=0; i<4; i++){
	 	for(j=0; j<5; j++){
	 		retornaMat(materia, aluno[index].grade[i][j], a);
	 		if(aluno[index].grade[i][j]==0)strcpy(a, "---");
	 		if(i==0 && j==0)printf("08:00   ");
	 		
	 		if(i==0)printf("%s       ",a);
	 	
	 		if(i==1 && j==0)printf("10:00   ");
	 		if(i==1)printf("%s       ",a);
	 		if(i==2 && j==0)printf("13:00   ");
	 		if(i==2)printf("%s       ",a);
	 		if(i==3 && j==0)printf("15:00   ");
	 		if(i==3)printf("%s       ",a);
	 		//printf("%d   ", aluno[index].grade[i][j]);
	 		if(j==4)printf("\n");
	 		//puts(retornaMat(aluno, materia, index));
		 }
		 printf("\n");
	 }
	
		
		
}

void retornaMat(Materias materia[5], int mat, char a[40]){
	int k;
	//char materia[30];
	//for(i=0; i<4; i++){
	//	for(j=0; j<5; j++){
			for(k=0; k<5; k++){
				if(mat==materia[k].cod){
					strcpy(a, materia[k].abrev);
					//printf("%d\n",materia[k].cod);
				}
			//	return;
	//		}
	//	}
	}	
}
void consultaDisc(Materias materia[5]){
	int i, x, y=0, z=0, s=0;
	char nome[10];
	while(s==0){
	
		system("cls");
		printf("Escolha a opicao:\n");
		printf("1. Buscar pelo codigo da disciplina.\n");
		printf("2. Buscar pelo nome da disciplina.\n");
		scanf("%d", &z);
		switch(z){
			case 1:{
				system("cls");
				printf("Entre com o codigo da disciplina.\n");
				scanf("%d", &x);
				s++;
				break;
			}
			case 2:{
				system("cls");
				printf("Ente com o nome da disciplina.\n");
				fflush(stdin);
				gets(nome);
				s++;	
				break;
			}
			default:{
				system("cls");
				printf("Valor informado esta errado!!\n");
				sleep(3);
				break;
			}
		}
	}
	
	
	
	
	
	while(y==0){
		fflush(stdin);
		for(i=0; i<5; i++){
			if(materia[i].cod==x){
				puts(materia[i].nome);
				fflush(stdin);
				puts(materia[i].prof);
				printf("Carga horaria: %d\n",materia[i].carga);
				printf("%d:00h\n", materia[i].hora[0]);
				printf("%d:00h\n", materia[i].hora[1]);
				y++;						
			}
			if(!(strcmp(materia[i].nome, nome))){
				puts(materia[i].nome);
				fflush(stdin);
				puts(materia[i].prof);
				printf("Carga horaria: %d\n",materia[i].carga);
				printf("%d:00h\n", materia[i].hora[0]);
				printf("%d:00h\n", materia[i].hora[1]);
				y++;
			}
		}
	}
}

void materiaSemestre( Materias materia[5]){
	strcpy(materia[0].nome, "Algoritmos");
	strcpy(materia[0].abrev, "Algo");
	strcpy(materia[0].prof, "Jonas Bulegon Gassen");
	materia[0].carga=60;
	materia[0].hora[0]=8;
	materia[0].hora[1]=10;
	materia[0].cod=122;
	materia[0].grid[0][0]=0;
	materia[0].grid[0][1]=0;
	materia[0].grid[1][0]=1;
	materia[0].grid[1][1]=1;

	strcpy(materia[1].nome, "Estrutura de dados");
	strcpy(materia[1].abrev, "Estr");
	strcpy(materia[1].prof, "Jonas Bulegon Gassen");
	materia[1].carga=60;
	materia[1].hora[0]=13;
	materia[1].hora[1]=15;
	materia[1].cod=127;
	materia[1].grid[0][0]=2;
	materia[1].grid[0][1]=1;
	materia[1].grid[1][0]=3;
	materia[1].grid[1][1]=2;
	

	strcpy(materia[2].nome, "Sistemas Operacionais A");
	strcpy(materia[2].abrev, "Sis.Op");
	strcpy(materia[2].prof, "Rafael Gressler Milbradt");
	materia[2].carga=60;
	materia[2].hora[0]=13;
	materia[2].hora[1]=10;
	materia[2].cod=132;
	materia[2].grid[0][0]=2;
	materia[2].grid[0][1]=1;
	materia[2].grid[1][0]=1;
	materia[2].grid[1][1]=3;
	
	

	strcpy(materia[3].nome, "Padroes de Projeto");
	strcpy(materia[3].abrev, "P/Pro");
	strcpy(materia[3].prof, " Marcos Alexandre Rose Silva");
	materia[3].carga=30;
	materia[3].hora[0]=10;
	materia[3].cod=143;
	materia[3].grid[0][0]=1;
	materia[3].grid[0][1]=4;
	materia[3].grid[1][0]=-1;
	materia[3].grid[1][1]=-1;
	

	strcpy(materia[4].nome, "Banco de dados II");
	strcpy(materia[4].abrev, "B/Dad");
	strcpy(materia[4].prof, "Daniel Lichtnow");
	materia[4].carga=60;
	materia[4].hora[0]=10;
	materia[4].hora[1]=10;
	materia[4].cod=135;
	materia[4].grid[0][0]=1;
	materia[4].grid[0][1]=2;
	materia[4].grid[1][0]=1;
	materia[4].grid[1][1]=4;
	


}
