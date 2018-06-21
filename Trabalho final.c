#include<stdio.h>
#include<string.h>
#define TAM 10


struct alunos{
	char nome[20], sobre[50], email[30];
	int matricula, materias[5], grade[4][5];

};

struct materias{
	char nome[20], dia[10];
	int carga, hora[2], cod;
	int grid[2][2];
};

struct dia{
	char nome[10], materias[10];

};


typedef struct dia Dia;
typedef struct alunos Alunos;
typedef struct materias Materias;

void retornaMat(Materias materia[5], int mat, char a[40]);
void imprime(Alunos aluno[TAM], Materias materia[5]);
void cadastroAluno(Alunos aluno[TAM]);
void cadastroMateria(Alunos aluno[TAM], Materias materia[5]);
void materiaSemestre(Materias materia[5]);
void novoAluno(Alunos aluno[TAM]);
void consultaAluno(Alunos aluno[TAM]);

main(){
	int i, j, k, x;
	
	Alunos aluno[TAM];
	Materias materia[5];
	Dia dias[10];
	
	
	for(k=0; k<TAM; k++){
		aluno[k].matricula=0;
		for(i=0; i<4; i++){
			for(j=0; j<5; j++){
			aluno[k].grade[i][j]=0;
			}
		}
	}
	
	
	cadastroAluno(aluno);
	
	//retornaMat(aluno, materia, 0, a);
	//puts(a);
	
	
	materiaSemestre(materia);
	printf("Entre com a opcao:\n");
	printf("1. Consulta de aluno.\n");
	printf("2. Cadastro de materia.\n");
	printf("3. Impressão da grade.\n");
	printf("4. Cadastro de aluno.\n");
	scanf("%d",&x);
	switch(x){
		case 1:{
			consultaAluno(aluno);
			break;
		}

		case 2:{
			cadastroMateria(aluno, materia);
			break;
		}

		case 3:{
			imprime(aluno, materia);
			break;
		}

		case 4:{
			novoAluno(aluno);
			break;
		}

	}

}

void cadastroMateria(Alunos aluno[TAM], Materias materia[5]){
	int y=0, x=0, i, j, a, b, c, d, index, index2, matri;
	printf("Entre com a matricola do aluno: \n");
	scanf("%d",&matri);
	
	for(j=0; j<TAM; j++){
			if(aluno[j].matricula==matri)index=j;


		}
	
	
	while(x==0){
		
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
		if(aluno[index].grade[a][b]!=0){
			printf("Horario ocupado!!\n");
			x=0;
		}else{
			aluno[index].grade[a][b]=materia[index2].cod;
			x++;
			
		}		
		
		if(aluno[index].grade[c][d]!=0){			
			printf("Horario ocupado!!\n");
			x=0;
		
		}else{
			aluno[index].grade[c][d]=materia[index2].cod;
			x++;
			
		}
		
		
		printf("%d\n",materia[index2].cod);
		
		
		
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

void consultaAluno(Alunos aluno[TAM]){
	int i, j, index, comp=0;
	char nome[30], nomeCompleto[50]={};
	printf("Entre com nome do aluno, ou parte dele: \n");
	fflush(stdin);
	gets(nome);
	for(i=0; i<TAM; i++){
		if(strcmp(aluno[i].nome, nome)==0){
			index=i;
			fflush(stdin);
			strcpy(nomeCompleto, aluno[i].nome);
			fflush(stdin);
			strcat(strcat(nomeCompleto, " "),aluno[i].sobre);
			puts(nomeCompleto);
			
			puts(aluno[i].email);
			printf("%d",aluno[i].matricula);
			
			
		}for(j=0; j<strlen(nome); j++){
			if(nome[j]==aluno[i].nome[j]){
				comp++;
				if(comp==strlen(nome)-1){
					index=i;
					fflush(stdin);
					strcpy(nomeCompleto, aluno[i].nome);
					fflush(stdin);
					strcat(strcat(nomeCompleto, " "),aluno[i].sobre);
					puts(nomeCompleto);
				
					puts(aluno[i].email);
					printf("%d",aluno[i].matricula);
					
				}
			}
		}
	}
	
	
}

void novoAluno(Alunos aluno[TAM]){
	int i, j, x=0, index, arroba=0, ponto=0;
	char email[30];
	
	for(i=0; i<TAM; i++){
		if(aluno[i].matricula==0)index=i;
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
	while(x==0){
		fflush(stdin);
		printf("Entre com email do novo aluno: \n");
		fflush(stdin);
		gets(email);
		fflush(stdin);
		
		for(j=0; j<30; j++){
			if(email[j]=='@' && j<3){
				printf("Email deve ter ao menos 3 caracteres \n");
				arroba=j;
			}
			if(email[j]=='.' && j-arroba < 3){
				printf("%d %d\n", j, arroba);
				printf("Email deve tar ao menos 3 caracteres apos o @ \n");
				ponto=j;				
			}else if(email[j]=='\0' && j-ponto < 3){
				printf("Email deve ter ao menos 2 caracteres apos o .\n",ponto);
				j=30;
			}
			else{
				strcmp(aluno[index].email, email);
			}
		}
		
	}
}


void cadastroAluno(Alunos aluno[TAM]){



	strcpy(aluno[0].nome, "julliet");
	strcpy(aluno[0].sobre, "Senna da Rosa");
	strcpy(aluno[0].email, "asjaosjoasjoas@hotmail.com");
	aluno[0].matricula=1220;
	//aluno[0].materias={0};
	puts(aluno[0].nome);
	puts(aluno[0].sobre);
	puts(aluno[0].email);



}

void imprime(Alunos aluno[TAM], Materias materia[5]){
	int i, j, index, matri;
	char a[40];
	printf("Entre com a matricula: \n");
	scanf("%d", &matri);
	for(j=0; j<TAM; j++){
		if(aluno[j].matricula==matri)index=j;
	}
	
	
	
	printf("         Seg       Ter       Qua       Qui       sex\n");
	 for(i=0; i<4; i++){
	 	for(j=0; j<5; j++){
	 		retornaMat(materia, aluno[index].grade[i][j], a);
	 		if(i==0 && j==0)printf("08:00    ");
	 		if(i==0)printf(" %s        ", a);
	 		if(i==1 && j==0)printf("10:00    ");
	 		if(i==1)printf(" %s        ",a);
	 		if(i==2 && j==0)printf("13:00    ");
	 		if(i==2)printf(" %s        ",a);
	 		if(i==3 && j==0)printf("15:00    ");
	 		if(i==3)printf(" s%        ",a);
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
				if(mat==materia[k].cod);
				strcpy(a, materia[k].nome);
				return;
	//		}
	//	}
	}	
}

void materiaSemestre( Materias materia[5]){
	strcpy(materia[0].nome, "Algorítmos");
	materia[0].carga=60;
	materia[0].hora[0]=8;
	materia[0].hora[1]=10;
	materia[0].cod=122;
	materia[0].grid[0][0]=0;
	materia[0].grid[0][1]=0;
	materia[0].grid[1][0]=1;
	materia[0].grid[1][1]=1;

	strcpy(materia[1].nome, "Estrutura de dados");
	materia[1].carga=60;
	materia[1].hora[0]=13;
	materia[1].hora[1]=15;
	materia[1].cod=127;
	materia[1].grid[0][0]=2;
	materia[1].grid[0][1]=1;
	materia[1].grid[1][0]=3;
	materia[1].grid[1][1]=2;
	

	strcpy(materia[2].nome, "Sistemas Operacionais A");
	materia[2].carga=60;
	materia[2].hora[0]=13;
	materia[2].hora[1]=10;
	materia[2].cod=132;
	materia[2].grid[0][0]=2;
	materia[2].grid[0][1]=1;
	materia[2].grid[1][0]=1;
	materia[2].grid[1][1]=3;
	
	

	strcpy(materia[3].nome, "Padroes de Projeto");
	materia[3].carga=30;
	materia[3].hora[0]=10;
	materia[3].cod=143;
	materia[3].grid[0][0]=1;
	materia[3].grid[0][1]=4;
	materia[3].grid[1][0]=-1;
	materia[3].grid[1][1]=-1;
	

	strcpy(materia[4].nome, "Banco de dados II");
	materia[4].carga=60;
	materia[4].hora[0]=10;
	materia[4].hora[1]=10;
	materia[4].cod=135;
	materia[4].grid[0][0]=1;
	materia[4].grid[0][1]=2;
	materia[4].grid[1][0]=1;
	materia[4].grid[1][1]=4;
	


}
