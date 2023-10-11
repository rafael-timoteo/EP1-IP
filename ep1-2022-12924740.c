/*********************************************************************/
/**   ACH2001 - Introducao a Programação                            **/
/**   EACH-USP - Primeiro Semestre de 2022                          **/
/**   Turma 04 - Prof. Marcos Lordello Chaim                        **/
/**                                                                 **/
/**   Primeiro Exercicio-Programa                                   **/
/**                                                                 **/
/**   <Rafael Francisco de Feitas Timoteo>      <12924740>          **/
/**                                                                 **/
/*********************************************************************/

/*
	Implementacao de diversas funcoes matematicas
*/

#include <stdio.h>
#include <math.h>

/* Variaveis globais utilizas pela função separaNumero */
int unidades;
int dezenas;
int centenas;
int milhares;

/*
	Separa o valor de entrada em unidades, dezenas, centenas e milhares.

	Se o numero passado como parametro for menor que zero ou maior que 9999,
	a função devera colocar o valor -1 nas quatro variaveis globais
	existentes no programa: unidades, dezenas, centenas e milhares.

	Caso contrario, a função devera separar o numero de acordo com suas
	unidades, dezenas, centenas e milhares e colocar esses valores nas
	respectivas variaveis globais.
	Isto e, para o numero 2345, deve atribuir o valor 2 na variavel
	milhares, o valor 3 na variavel centenas, o valor 4 na variavel dezenas
	e o valor 5 na variavel unidades.

	Parametro:
		valor - Valor a ter seus digitos separados
*/
void separaNumero(int valor){
  if (valor>9999 || valor<0){
    printf("Unidades = -1\n");
    printf("Dezenas = -1\n");
    printf("Centenas = -1\n");
    printf("Milhares = -1\n");
    printf("VALOR INVALIDO\n");
    }

    else {
        unidades=(((valor%1000)%100)%10)/1;
        dezenas=((valor%1000)%100)/10;
        centenas=(valor%1000)/100;
        milhares=valor/1000;

        printf("Valor: %i\n",valor);
        printf("Milhares = %d\n", milhares);
        printf("Centenas = %d\n", centenas);
        printf("Dezenas = %d\n", dezenas);
        printf("unidades = %d\n", unidades);
        printf("\n");

     }
}

void fun1(){
    int valor;
    printf("\n");

    valor = 2345;
    separaNumero(valor);

    valor = 606;
    separaNumero(valor);

    valor = -1;
    separaNumero(valor);

    printf("\n");
}


/*
	Suponha que a população de um país A seja da ordem de "popA" habitantes com uma taxa anual de crescimento de
	"taxaA" (em %) e que a população de B seja "popB" habitantes com uma taxa de crescimento de "taxab" (em %).
	Escreva uma função que calcule e retorne o número de anos necessários para que a população do país A
	ultrapasse ou iguale a população do país B, mantidas as taxas de crescimento.

	A função irá retornar -1 se algum dos parâmetros for  negativo ou se nunca for possível a população
	do país A ultrapassar a população de B.

	Parametros:
	pA: população do país A
	taxaA: taxa de crescimento de A em porcentagem
	pB: população do país A
	taxaB: taxa de crescimento de B em porcentagem
*/

int ultrapassagem(int popA, double taxaA, int popB, double taxaB){
   int anos = 0;

      while(popA<popB){
       popA = popA + (taxaA/100)*(popA);
       popB = popB + (taxaB/100)*(popB);
       anos = anos + 1;
     }

     if(anos<0 || popA<0 || popB<0)
     printf("Taxa A: %.2f; Populacao A: -1; Taxa B: %.2f; populacao B: -1; Anos: -1\n\n", taxaA, taxaB);
       else{
     printf("Taxa A: %.2f; Populacao A: %i; Taxa B: %.2f; Populacao B: %i; Anos: %i\n\n", taxaA, popA, taxaB, popB, anos);
   }
     return 0;
   }

   void fun2(){
     int popA;
     int popB;
     double taxaA;
     double taxaB;

     printf("\n");

   // primeiro teste
     taxaA = 2;
     taxaB = 1.5;
     popA = 37000;
     popB = 400000;
     ultrapassagem(popA, taxaA, popB, taxaB);

     //segundo teste
     taxaA = 2;
     taxaB = 1.5;
     popA = 37000;
     popB = 37000;
     ultrapassagem(popA, taxaA, popB, taxaB);

     //terceiro teste
     taxaA = 2;
     taxaB = 1.0;
     popA = 37000;
     popB = 400000;
     ultrapassagem(popA, taxaA, popB, taxaB);

     //quarto teste
     taxaA = 0.2;
     taxaB = 1.0;
     popA = 37000;
     popB = 400000;
     ultrapassagem(popA, taxaA, popB, taxaB);

     //quinto teste
     taxaA = 2;
     taxaB = -1.0;
     popA = 37000;
     popB = 400000;
     ultrapassagem(popA, taxaA, popB, taxaB);
   }


/*

	Esta função recebe tres numeros inteiros (inicio, fim e passo).
	Se qualquer desses numeros for negativo ou nulo a função devera
	retornar -1 (apenas como uma excecao e nao para representar o resultado
	da operacao);
	Se o valor de fim for menor do que o valor de inicio, a função tambem
	devera retornar -1 (menos um).

	Caso contrario, a função devera retornar a soma de todos os numeros
	"primos de Germain" que aparecem no intervalo. Sophie Germain foi
	uma matemática francesa nascida no século XVIII.	Um número n é "primo
	de Germain" se n é primo e 2n+1 também é primo.

	Os "primos de Germain" são chamados "primos seguros", devido a uma
	aplicação prática que ela
	nunca poderia ter previsto. Os principais métodos atuais de criptografia
	são baseados no fato de
	que, dado um produto pq de dois primos grandes, é difícil identificar
	os fatores p e q. Mas isso depende da escolha dos primos: por exemplo,
	se p é tal que p–1 pode ser fatorizado em primos pequenos, não é tão
	difícil quebrar a criptografia. Um jeito de evitar esse risco é usar
	p e q que sejam primos seguros. (Marcelo Vianna, Folha de São Paulo,
  01/06/22)

	Por exemplo, para inicio=0, fim=10 e passo=1, a função devera retornar 10,
	pois os "primos de Germain" são 2, 3 e 5, logo, a soma deles é 10.
	Fique à vontade para criar funções auxiliares caso julgue necessário para
	obter o resultado desta função.

	Parametros:
		inicio - Primeiro valor a participar da soma
		fim - Os valores utilizados na soma devem ser menores do que fim
		passo - Variacao aplicada a cada valor a partir do valor de inicio
*/
int primoGermain(int g){
  int germain;
  int div2 = 1;
  int gdiv = 0;

  germain = (g*2) + 1;

  while(germain >= div2){
    if(germain % div2 == 0)
      gdiv = gdiv + 1;
      div2 = div2 + 1;
  }
  if(gdiv == 2){
    return g;
  }
  else{
    return 0;
  }
}

int primo(int n){
  int div = 1;
  int ndiv = 0;

  while(n >= div){
    if(n % div == 0)
      ndiv = ndiv + 1;
      div = div +1;
  }
    if(ndiv == 2)
      primoGermain(n);
    else
      return 0;
}

int somaprimosdegermain(int inicio, int fim, int passo){
  int soma = 0;

  if(fim < inicio || inicio <= 0 || fim <= 0 || passo <= 0){
    return -1;
  }
  else
    while(inicio <= fim){
      primo(inicio);
      soma = soma + primo(inicio);
      inicio = inicio + passo;
    }
  return soma;
}

int fun3(){
  int inicio;
	int fim;
	int passo;

	inicio = 1;
	fim = 10;
	passo = 1;
	printf("\n\nInicio: %i; Fim: %i; Passo: %i; Resultado: %i\n\n", inicio, fim, passo, somaprimosdegermain(inicio, fim, passo));

	inicio = 1;
	fim = 30;
	passo = 1;
	printf("Inicio: %i; Fim: %i; Passo: %i; Resultado: %i\n\n", inicio, fim, passo, somaprimosdegermain(inicio, fim, passo));

  return 0;
}

/*
  Considere a sequência de números: 1, -1/2, 1/3, -1/4, 1/5,...
	onde n é um número inteiro maior que zero.

	Esta função calcula, para um valor de n passado como parâmetro,
	a somatória de 1 + (-1/2) + 1/3 + (-1/4) + 1/5... + (-1)^(n+1)/n
	onde o símbolo ^ representa a operação de potenciação. Por exemplo,
	2^2 = 4.

	Note que a fórmula (-1)^(n+1)/n dá o n-ésimo elemento
	da sequência. Por exemplo, para n=1, (-1)^(1+1)/1 = 1^2/1 = 1; para
	n = 3, o terceiro elemento será (-1)^(3+1)/3 = (-1)^4/3 = 1/3.

	A função recebe como parâmetro um número inteiro e retorna a somatória
	da sequência. O valor da somatória será um número real, logo, o retorno
	dela será um double.

	Se o parâmetro de entrada representando n for menor ou igual a zero, a
	função irá	retornar -1 (apenas como uma excecao e nao para representar o resultado
	da operacao);

		Parametros:
		n - inteiro positivo

*/

double somasequencia(long n){
  double calculo = 0;
	double soma = 0;

	if(n <= 0)
	printf("Soma da sequencia para n=%ld: -1\n\n", n);
	else
	while(n > 0){
	calculo = (pow(-1,n+1)/n);
	soma = soma + calculo;
	n = n - 1;
}
	return soma;
}

int fun4(){
	long n;

  printf("\n");

	n = 5;
	somasequencia(n);
	printf("Soma da sequencia para n = %ld: %f\n\n", n, somasequencia(n));

	n = 50;
	somasequencia(n);
	printf("Soma da sequencia para n = %ld: %f\n\n", n, somasequencia(n));

	n = 1000;
	somasequencia(n);
	printf("Soma da sequencia para n = %ld: %f\n\n", n, somasequencia(n));

	n = 25000;
	somasequencia(n);
	printf("Soma da sequencia para n = %ld: %f\n\n", n, somasequencia(n));

	n = 32000;
	somasequencia(n);
	printf("Soma da sequencia para n = %ld: %f\n\n", n, somasequencia(n));

	n = 32000000;
	somasequencia(n);
	printf("Soma da sequencia para n = %ld: %f\n\n", n, somasequencia(n));

	return 0;
}
/*
	Esta função calcula o fatorial de um número natural n (lembre-se
  que os números naturais são inteiros maiores ou iguais a zero)

	Ela recebe um numero inteiro como parâmetro (n).
	Se este numero for menor do que zero, a função devera retornar -1.

	Caso contrario, a função devera retornar o fatorial de n, isto é, n!

	Parametro:
		n - indica o numero natural para o qual será calculado o fatorial
*/
long fatorial(int n){
  long fatorial = 1;

  if(n<0)
    return -1;
  else
    while(n>0){
      fatorial = fatorial * n;
      n = n - 1;
  }
  return fatorial;
}

int fun5(){
  long valorDeN;

printf("\n");

valorDeN = -1;
printf("Valor de n: %i; Resultado: %li\n\n", valorDeN, fatorial(valorDeN));

valorDeN = 0;
printf("Valor de n: %i; Resultado: %li\n\n", valorDeN, fatorial(valorDeN));

valorDeN = 1;
printf("Valor de n: %i; Resultado: %li\n\n", valorDeN, fatorial(valorDeN));

valorDeN = 2;
printf("Valor de n: %i; Resultado: %li\n\n", valorDeN, fatorial(valorDeN));

valorDeN = 3;
printf("Valor de n: %i; Resultado: %li\n\n", valorDeN, fatorial(valorDeN));

valorDeN = 4;
printf("Valor de n: %i; Resultado: %li\n\n", valorDeN, fatorial(valorDeN));

valorDeN = 5;
printf("Valor de n: %i; Resultado: %li\n\n", valorDeN, fatorial(valorDeN));

valorDeN = 6;
printf("Valor de n: %i; Resultado: %li\n\n", valorDeN, fatorial(valorDeN));

valorDeN = 7;
printf("Valor de n: %i; Resultado: %li\n\n", valorDeN, fatorial(valorDeN));

valorDeN = 10;
printf("Valor de n: %i; Resultado: %li\n\n", valorDeN, fatorial(valorDeN));

valorDeN = 50;
printf("Valor de n: %i; Resultado: %li\n\n", valorDeN, fatorial(valorDeN));

return 0;
}

int main(){
  int valor;
  int popA;
  int popB;
  long n;
  long valorDeN;

  fun1();
  fun2();
  fun3();
  fun4();
  fun5();

	return 0;
}
