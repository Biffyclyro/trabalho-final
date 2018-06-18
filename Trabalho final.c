#include<stdio.h>
#include<string.h>
#define TAM 10


struct alunos{
	char nome[20], sobre[50], email[30];
	int matricula, materias[5]={};
	
};

struct materias{
	char nome[20], dia[10];
	int carga, hora[2], cod;
	
};

struct dia{
	char nome[10], materias[10];
	
};


typedef struct dia Dia;
typedef struct alunos Alunos;
typedef struct materias Materias;

void cadastroAluno(Alunos aluno[TAM]);
void cadastroMateria(Alunos aluno[TAM]);
void materiaSemestre(Materias materia[5]);

main(){
	int i, j,x;
	Alunos aluno[TAM];
	Materias materia[5];
	Dia dias[10];
	cadastroAluno(aluno);
	cadastroMateria(aluno);
	materiaSemestre(ateria);
	printf("Entre com a opcao:\n")
	printf("1. Consulta de aluno.\n");
	printf("2. Cadastro de materia.\n");
	printf("3. Impressão da grade.\n");
	printf("4. Cadastro de aluno.\n");
	scanf("%d",&x);
	switch(x){
		case 1:{
			break;
		}
		
		case 2:{
			
			break;
		}
		
		case 3:{
			break;
		}
		
		case 4:{
			break;
		}
		
	}

}

void cadastroMateria(Alunos aluno[TAM]){
	int y=0, x=0, i, j, index, matri;
	
	while(x==0)
		printf("Entre com a matricola do aluno: \n");
		scanf("%d",&matri);
		printf("Entre com o código da matéria: \n");
		scanf("%d",&y);
		//scanf("%d",&aluno[0].materias[0]);
		printf("%d",aluno[0].materias[0]);
		for(j=0; j<TAM; j++){
			if(aluno[j].matricula==matri)
				index=j;
		}
		for(i=0, i<5, i++){			
			if(aluno[index].materias[i]==y) printf("Materia ja cadastrada!\n");
			if(aluno[index].materias[i]==127 && y == 132) printf("Horario de terca 13:00 ja ocupado!!\n");
			if(aluno[index].materias[i]==132 && y == 127) printf("Horario de terca 13:00 ja ocupado!!\n");
			if(aluno[index].materias[i]==143 && y == 135) printf("Horario de sexta 10:00 ja ocupado!!\n");
			if(aluno[index].materias[i]==135 && y == 143) printf("Horario de sexta 10:00 ja ocupado!!\n");
			if(aluno[index].materias[i]==0)aluno[index].materias[i]=y;
			
		}
		
		
}


void cadastroAluno(Alunos aluno[TAM]){
	
		
	
	strcpy(aluno[0].nome, "Joao");
	strcpy(aluno[0].sobre, "Senna da Rosa");
	strcpy(aluno[0].email, "asjaosjoasjoas@hotmail.com");
	puts(aluno[0].nome);
	puts(aluno[0].sobre);
	puts(aluno[0].email);
	
	
	
}

void materiaSemestre( Materias materia[5]){
	strcpy(materia[0].nome, "Algorítmos");
	materia[0].carga=60;
	materia[0].hora[0]=8;
	materia[0].hora[1]=10;
	materia[0].cod=0122;
	
	strcpy(materia[1].nome, "Estrutura de dados");
	materia[1].carga=60;
	materia[1].hora[0]=13;
	materia[1].hora[1]=15;
	materia[1].cod=0127;
	
	strcpy(materia[2].nome, "Sistemas Operacionais A");
	materia[2].carga=60;
	materia[2].hora[0]=13;
	materia[2].hora[1]=10;	
	materia[2].cod=0132;
	
	strcpy(materia[3].nome, "Padroes de Projeto");
	materia[3].carga=30;
	materia[3].hora[0]=10;	
	materia[3].cod=0143;
	
	strcpy(materia[4].nome, "Banco de dados II");
	materia[4].carga=60;
	materia[4].hora[0]=10;
	materia[4].hora[1]=10;
	materia[4].cod=0135;	
	
	
}	
	
