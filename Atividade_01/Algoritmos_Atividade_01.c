#include <stdio.h>
#include <locale.h>

//Fun��o calcSalario - utilizada para realizar o calculo do salario bruto
float calcSalario (float n1, float n2){
	return n1 * n2;
}

//Fun��o calcIR - utilizada para realizar o calculo do Imposto de Renda
float calcIR (float n1){
	return n1 > 1000 ? (n1 * 0.1) : (n1 = 0);
	//Fun��o com operador tern�rio, utilizado no lugar do if, ao fazer a compara��o retornar� com 10% do valor comparado ou 0
}

//Fun��o calcINSS - utilizada para realizar o calculo do INSS
float calcINSS (float n1){
	return n1 * 0.1;
	//Opera��o matem�tica para se obter 10% de um valor
}

//Fun��o calcFGTS - utilizada para realizar o calculo do FGTS
float calcFGTS (float n1){
	return n1 * 0.11;
	//Opera��o matem�tica para se obter 11% de um valor
}

//Fun��o vlrHolerite - utilizada para realizar o calculo do salario e impress�o dos resultados
float vlrHolerite() {
	setlocale(LC_ALL, "");
	
	float vlrHora;
	float quantHTrabalhada;	
	
	printf("Digite o valor da hora trabalhada: ");
	scanf("%f", &vlrHora);
	
	printf("\nDigite a quantidade de horas trabalhadas: ");
	scanf("%f", &quantHTrabalhada);
	
	float salarioBruto = calcSalario(vlrHora, quantHTrabalhada);
	//Variavel salarioBruto recebe o resultado do calculo dos par�metros vlrHora e quantHTrabalhada na fun��o calcSalario
	float salarioLiquido = salarioBruto - calcIR(salarioBruto) - calcINSS(salarioBruto);
	//Vari�vel salarioLiquido recebe o resultado do salarioBruto subtraido pelo calculo do par�metro salarioBruto nas fun��es calcIR e calcINSS
	
	printf("\nSal�rio Bruto --> R$ %.2f", salarioBruto);
	//Impress�o do resultado do Salario Bruto, dado pela vari�vel salarioBruto
	printf("\nIR --> R$ %.2f", calcIR(salarioBruto));
	//Impress�o do resultado do Imposto de Renda, dado pela fun��o calcIR com o par�metro salarioBruto
	printf("\nINSS --> R$ %.2f", calcINSS(salarioBruto));
	//Impress�o do resultado do INSS, dado pela fun��o calcINSS com o par�metro salarioBruto
	printf("\nFGTS --> R$ %.2f", calcFGTS(salarioBruto));
	//Impress�o do resultado do FGTS, dado pela fun��o calcFGTS com o par�metro salarioBruto
	printf("\nSal�rio L�quido --> R$ %.2f", salarioLiquido);
	//Impress�o do resultado do Sal�rio L�quido, dado pela vari�vel salarioLiquido
	
	return 0;
}

//Fun��o main - Fun��o principal do c�digo, onde iniciar� o programa que ir� chamar as fun��es necess�rias para iniciar a ordem de l�gica das fun��es
int main(){
	vlrHolerite();
	//Chamada da fun��o vlrHolerite, que solicita valores para chamar outras fun��es de calculo e imprimir o resultado dos calculos.
	
	return 0;
}
