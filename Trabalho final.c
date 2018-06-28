#include<stdio.h>
#include<string.h>
#define TAM 10

struct alunos{
	char nome[20], sobre[50], email[30];
	int matricula, materias[5], grade[4][5];
	//struct que dos alunos

};

struct materias{
	char nome[20], dia[20], dia2[20], abrev[10], prof[30];
	int carga, hora[2], cod;
	int grid[2][2];
	//struct das materias
};

//aqui os structs ganham nome 
typedef struct alunos Alunos;
typedef struct materias Materias;

//aqui os protótipos das funções são criados
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
	//aqui é definido o tamano dos arrays de structs
	Alunos aluno[TAM];
	Materias materia[5];	
	
	//essa função varre todos os alunos, e então seta a matriz de horário de cada um para guardar 0 nas posições
	for(k=0; k<TAM; k++){
		aluno[k].matricula=0;
		for(i=0; i<4; i++){
			for(j=0; j<5; j++){
			aluno[k].grade[i][j]=0;
			aluno[k].materias[j]=0;
			}
		}
		aluno[k].grade[-1][-1]=0;
	}
	
	//aqui uma função com alunos já cadastrados para fins de exemplificação, só para não serem cadastrados pelo usuário
	cadastroAluno(aluno);
	
	//aqui uma função que cadastra todas as matérias do semestre
	materiaSemestre(materia);
	
	//um loop que faz rodar o switch case até o usuário decidir fechar o programa
	while(y==0){
		system("cls");
		printf("Entre com a opcao:\n");
		printf("1. Consulta de aluno.\n");
		printf("2. Cadastro de disciplina.\n");		
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
					//Uma firula, ideia roubada da colega
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
//função para cadastrar matérias novas, fiz separado imaginando uma situação de reajuste
void cadastroMateria(Alunos aluno[TAM], Materias materia[5]){
	int y=0, x=0, i, j, a, b, c, d, index, index2, matri;
	char resp='y';
	printf("Entre com a matricula do aluno: \n");
	scanf("%d",&matri);
	//como não foi especificado, assumi que só poderiam ser cadastradas matérias usando o numero da matrícula
	for(j=0; j<TAM; j++){
		if(aluno[j].matricula==matri)index=j;
	}	
	
	while(resp!='n'){
		//aqui pede o código da matéria, e salva os index da matriz correspondente ao código em 4 variáveis a, b, c ,d
		printf("Entre com o codigo da materia: \n");
		scanf("%d",&y);
		
		for(i=0; i<5; i++){
			if(y==materia[i].cod)index2=i;
			
		}		
		
		a=materia[index2].grid[0][0];
		b=materia[index2].grid[0][1];
		c=materia[index2].grid[1][0];
		d=materia[index2].grid[1][1];
		//aqui verifica se já existe alguma matéria na grade de horários, se sim, exibe essa mensagem por 2 segundos
		if(aluno[index].grade[a][b]!=0 || aluno[index].grade[c][d]!=0){
			printf("Conflito de horarios!!\n");
			
			sleep(2);
			
		}else{
			//aqui ele n só salva as coordenadas como também em uma lista as disciplinas matriculadas
			aluno[index].grade[a][b]=materia[index2].cod;
			aluno[index].grade[c][d]=materia[index2].cod;
			aluno[index].materias[index2]=materia[index2].cod;
		}
		
		system("cls");
		printf("Mais alguma materia? (S/N)\n");
		scanf(" %c", &resp);
		system("cls");		
		
	}

}
//função que consulta e mostra os dados do aluno
void consultaAluno(Alunos aluno[TAM],Materias materia[5]){
	int i, j, index, mark=0 ;
	char nome[30], nomeLow[30]={}, nomeCompleto[50]={};
	printf("Entre com nome do aluno, ou parte dele: \n");
	fflush(stdin);
	gets(nome);
	for(i=0; i<TAM; i++){
		int comp=0;			
	
		for(j=0; j<strlen(nome); j++){
			//um pulo do gato que precisei fazer para o case da letra não me atrapalhar na verificação do nome
			strcpy(nomeLow, aluno[i].nome);
			strlwr(nomeLow);
			if(nome[j]==nomeLow[j]){
				comp++;
				
			}else{
				comp=0;
			}
				
			if(j+1==strlen(nome) && comp >= 3){
				//aqui ele verifica se já foram todas as letras, e tbm se foram digitadas no mínimo 3 
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
				sleep(6);
				//esse uso do return que só me liguei nas ultimas aulas revolucionou minha logica
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
//cadastro de novo aluno
void novoAluno(Alunos aluno[TAM], Materias materia[5]){
	int i, j, k, l, x=0, index, arroba=0, ponto=0;
	char email[30];
	//aqui verifica onde tem uma posição de aluno vazia
	for(i=0; i<TAM; i++){
		if(aluno[i].matricula==0)index=i;
		break;
	}
	//paranoia tamanha que aqui mais uma vez é zerado a grade do aluno em questão
	for(k=0; k<4; k++){
		for(l=0; l<5; l++){
			aluno[index].grade[k][l]=0;
		}
	}
	aluno[index].grade[-1][-1]=0;
	fflush(stdin);
	printf("Entre com o nome do novo aluno: \n");
	gets(aluno[index].nome);	
	fflush(stdin);
	printf("Entre com o sobrenome do novo aluno: \n");
	gets(aluno[index].sobre);
	fflush(stdin);
	printf("Entre com o numero da matricula: \n");	
	scanf("%d",&aluno[index].matricula);
	//aqui a verificação do email que só aceita a entrada quando as 3 condições são satifeitas
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
			if(email[j]=='.' && j-arroba <= 3){
				printf("Email deve tar ao menos 3 caracteres apos o @ \n");
				break;
			}if(email[j]=='.' && j-arroba > 3){
				x++;
			}
			if(email[j]=='\0' && j-ponto < 3){
				printf("Email deve ter ao menos 2 caracteres apos o .\n");
				
				break;
			}if(email[j]=='\0' && j-ponto > 3){
				printf("%d",j);
				x++;
			}
			if(x==3){
				//já vi essa estrutuda uma vez em um cadastro de jogo, então achei realista ser feito assim
				system("cls");
				strcpy(aluno[index].email, email);
				printf("Va para o cadastro das materias!!\n");
				sleep(2);
				
			}
		}
		
	}	
	
}


void cadastroAluno(Alunos aluno[TAM]){


	strcpy(aluno[0].nome, "Julia");
	strcpy(aluno[0].sobre, "Piluski");
	strcpy(aluno[0].email, "juliap@hotmail.com");
	aluno[0].matricula=1220;
	aluno[0].materias[0]=122;
	aluno[0].materias[1]=127;
	aluno[0].materias[2]=143;
	aluno[0].materias[3]=0;
	aluno[0].materias[4]=0;
	aluno[0].grade[0][0]=122;
	aluno[0].grade[1][1]=122;
	aluno[0].grade[2][1]=127;
	aluno[0].grade[3][2]=127;
	aluno[0].grade[1][4]=143;	
	
	
	strcpy(aluno[1].nome, "Gabriela");
	strcpy(aluno[1].sobre, "Trevisan Leturiondo");
	strcpy(aluno[1].email, "gagabriel@gmail.com");
	aluno[1].matricula=1330;
	aluno[1].materias[0]=122;
	aluno[1].materias[1]=132;
	aluno[1].materias[2]=135;
	aluno[1].materias[3]=0;
	aluno[1].materias[4]=0;
	aluno[1].grade[0][0]=122;
	aluno[1].grade[1][1]=122;
	aluno[1].grade[2][1]=132;
	aluno[1].grade[3][2]=132;
	aluno[1].grade[1][4]=135;
	aluno[1].grade[1][2]=135;
	
	
	strcpy(aluno[2].nome, "Rafaella");
	strcpy(aluno[2].sobre, "Marques Farias");
	strcpy(aluno[2].email, "rafaell@hotmail.com");
	aluno[2].matricula=1440;
	aluno[2].materias[0]=122;
	aluno[2].materias[1]=127;
	aluno[2].materias[2]=143;
	aluno[2].materias[3]=0;
	aluno[2].materias[4]=0;
	aluno[2].grade[0][0]=122;
	aluno[2].grade[1][1]=122;
	aluno[2].grade[2][1]=127;
	aluno[2].grade[3][2]=127;
	aluno[2].grade[1][4]=143;

}

void imprime(Alunos aluno[TAM], Materias materia[5], int matri){
	int i, j, index;
	char a[40]={};
//um contador que encontra o index da matricula que entrou 
	for(j=0; j<TAM; j++){
		if(aluno[j].matricula==matri)index=j;
	} 	
	
	// essa impressão achei que era a forma mais condizente de se fazer
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
	 		if(j==4)printf("\n");
	 		
		 }
		 printf("\n");
	 }		
}
//função que consulta informações das matérias 
void retornaMat(Materias materia[5], int mat, char a[40]){
	int k;
	
	for(k=0; k<5; k++){
		if(mat==materia[k].cod){
			strcpy(a, materia[k].abrev);					
		}	
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
		//o tempo começou a apertar e a única forma de fazer isso e funcionas foi com outro switch case
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
				fflush(stdin);
				printf("Valor informado esta errado!!\n");
				sleep(3);
				break;
			}
		}
	}	
	
	/*poderiam estar dentro da mesma condição, porém também pela falta de tempo, dado a quantidade de provas finais, 
	deixei em dois "if" diferentes para poder controlar melhor os problemas que tive em cada condição*/
	while(y==0){
		fflush(stdin);
		int a=0;
		for(i=0; i<5; i++){
			if(materia[i].cod==x){
				puts(materia[i].nome);
				fflush(stdin);
				puts(materia[i].prof);
				printf("Carga horaria: %d\n",materia[i].carga);
				puts(materia[i].dia);
				puts(materia[i].dia2);
				sleep(5);
				y++;
				a++;					
			}
			if(!(strcmp(materia[i].nome, nome))){
				puts(materia[i].nome);
				fflush(stdin);
				puts(materia[i].prof);
				printf("Carga horaria: %d\n",materia[i].carga);
				puts(materia[i].dia);
				puts(materia[i].dia2);
				sleep(5);
				a++;
				y++;
			}
		
		}
		if(a==0){
			printf("Materia nao encontrada, tente novamente.\n");
			sleep(2);
			break;
		}
	
	}
}
//o cadastro das matérias, acrescentei a ideia de um nome abreviado para deixar a impressão da grade mais parecida com o exemplo
void materiaSemestre( Materias materia[5]){
	strcpy(materia[0].nome, "Algoritmos");
	strcpy(materia[0].abrev, "Algo");
	strcpy(materia[0].prof, "Jonas Bulegon Gassen");
	strcpy(materia[0].dia, "Segunda 08:00");
	strcpy(materia[0].dia2, "Terca 10:00");
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
	strcpy(materia[1].dia, "Terca 13:00");
	strcpy(materia[1].dia2, "Quarta 15:00");
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
	strcpy(materia[2].dia, "Terca 13:00");
	strcpy(materia[2].dia2, "Quinta 10:00");
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
	strcpy(materia[3].dia, "Sexta 10:00");
	strcpy(materia[3].dia2, " ");	
	materia[3].carga=30;
	materia[3].hora[0]=10;
	materia[3].cod=143;
	materia[3].grid[0][0]=1;
	materia[3].grid[0][1]=4;
	materia[3].grid[1][0]=1;
	materia[3].grid[1][1]=4;
	

	strcpy(materia[4].nome, "Banco de dados II");
	strcpy(materia[4].abrev, "B/Dad");
	strcpy(materia[4].prof, "Daniel Lichtnow");
	strcpy(materia[4].dia, "Quarta 10:00");
	strcpy(materia[4].dia2, "Sexta 10:00");
	materia[4].carga=60;
	materia[4].hora[0]=10;
	materia[4].hora[1]=10;
	materia[4].cod=135;
	materia[4].grid[0][0]=1;
	materia[4].grid[0][1]=2;
	materia[4].grid[1][0]=1;
	materia[4].grid[1][1]=4;

}
