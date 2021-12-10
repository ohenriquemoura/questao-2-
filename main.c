#include <stdio.h>
#include <stdlib.h>
#define MAXTAM 10

typedef struct {
    int nome;
    int matricula;
    
}Aluno;
Aluno array[MAXTAM];
 int n;

 void start(){
 n = 0;
 }
 void inserirInicio(Aluno x) { 
   if (n >= MAXTAM)
    exit(1);
 //levar elementos para o fim do array
   for (int i = n; i > 0; i--){
    array[i] = array[i-1];
   }
   array[0].nome = x.nome;
   array[0].matricula = x.matricula;
   n++;
 }
 void inserirFim(Aluno x) { 
   if (n >= MAXTAM)
    exit(1);
   array[n].nome = x.nome;
   array[n].matricula = x.matricula;
   n++;

  }
 void inserir(Aluno x, int pos) { 
   if (n >= MAXTAM || pos < 0 || pos > n)
    exit(1);
 //levar elementos para o fim do array
   for (int i = n; i > pos; i--){
    array[i].nome = array[i-1].nome;
    array[i].matricula = array[i-1].matricula;
   }
   array[pos].nome = x.nome;
   array[pos].matricula = x.matricula;
   n++;
  }
 int removerInicio() { 
   if (n == 0)
    exit(1);
   int resp = array[0].nome;
   int resp2 = array[0].matricula;
   n--;
   for (int i = 0; i < n; i++){
    array[i].nome = array[i+1].nome;
    array[i].matricula = array[i+1].matricula;
   }
  return resp && resp2;
 } 
 int removerFim() { 
   if (n == 0)
    exit(1);

   return array[--n].nome && array[--n].matricula;

 }
 int remover(int pos) { 
   if (n == 0 || pos < 0 || pos >= n)
    exit(1);
   int resp = array[0].nome;
   int resp2 = array[0].matricula;
   n--;
   for (int i = pos; i < n; i++){
    array[i].nome = array[i+1].nome;
    array[i].matricula = array[i+1].matricula;
   }
   return resp;
  }
 void mostrar () { 
   printf("[ ");
   for (int i = 0; i < n; i++){
    printf("Aluno %i, matricula %i -- " "",array[i].nome,array[i].matricula);
   }
   printf(" ]\n");
   
  }
  void insercao(int n){
    for (int i = 1; i < n; i++) {
      int tmp = array[i].matricula;
      int j = i - 1;

      while ((j >= 0) && (array[j].matricula > tmp)) {
         array[j + 1] = array[j];
         j--;
      }
      array[j+1].matricula = tmp;
   }
}
 int buscasequencial(int x){
    for(int i=0;i<n;i++){
      if(array[i].nome==x)
        return array[i].matricula;
        
    }
    return-1;
 }
 int pesquisabinaria( int esq, int dir, int x)
{
   if (dir >= esq)
   {
        insercao(n);
        int meio = esq + (dir - esq)/2;


        if (array[meio].matricula == x)  return array[meio].nome;//se o elemento se encontra no meio do array


        if (array[meio].matricula > x) return pesquisabinaria( esq, meio-1, x);// se o elemento for menor que o meio em um vetor ordenado so pode ser encontrado na esquerda


        return pesquisabinaria( meio+1, dir, x);// senao o elemento so pode ser encontrado na direita de um vetor ordenado
   }

   return -1;//elemento nao esta no array
}

int main(void) {
  start();
  Aluno x;
  x.nome=1;
  x.matricula=100;
  Aluno y;
  y.nome=2;
  y.matricula=200;
  Aluno z;
  z.nome=3;
  z.matricula=300;
  

  inserirInicio(x);
  inserirInicio(y);
  inserirInicio(z);
  int numero =3,numero2=100;
  int result=buscasequencial(numero);

  (result == -1)? printf("Nao existe esse aluno\n")
                : printf("A matricula do aluno %d e %d\n",numero, result);

  int result2 = pesquisabinaria( 0, n-1, numero2);
   (result2 == -1)? printf("Nao existe essa matricula\n")
                  : printf("O aluno da matricula %d e o aluno%d\n",numero2, result2);
  
  

  mostrar();

  return 0;
}