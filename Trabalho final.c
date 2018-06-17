#include<stdio.h>
#include<string.h>


struct alunos{
	char nome[20], sobre[50], email[30];
	int matricula, materias[6];
	
};

struct materias{
	char nome[20], prof[30];
	int carga, hora, cod;
	
};

struct dia{
	char nome[10], materias[10];
	
};


typedef struct dia d;
typedef struct alunos al;
typedef struct materias mat;

void cadastroAluno();
void cadastroMateria(al aluno[10]);

main(){
	int i, j,x;
	al aluno[10];
	mat materia[10];
	d dias[10];
	cadastroAluno();
	cadastroMateria(aluno);
	
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
	}

}

void cadastroMateria(al aluno[10]){
	int y=0;
	printf("Entre com o código da matéria: \n");
	scanf("%d",al aluno[0].materias[0]);
	printf("%d",al aluno[0].materias[0);
		
}


void cadastroAluno(){
	
		
	
	strcpy(aluno[0].nome, "Joao");
	strcpy(aluno[0].sobre, "Senna da Rosa");
	strcpy(aluno[0].email, "asjaosjoasjoas@hotmail.com");
	puts(aluno[0].nome);
	puts(aluno[0].sobre);
	puts(aluno[0].email);
	
	
	
}
