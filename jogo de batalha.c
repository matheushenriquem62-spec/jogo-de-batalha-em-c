#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int escolha(int *atq1, int *def1, int *hp1, int *stats1, int pontos){
      printf("jogador 1 escolha seus atributos, voce tem %d\n", pontos);
    printf("ataque:\n");
    scanf("%d", atq1);
    printf("defesa:\n");
    scanf("%d", def1);
    printf("Vida:\n");
    scanf("%d", hp1);
    *stats1 = *atq1 + *def1 + *hp1;
}

int escolha2(int *atq2, int *def2, int *hp2, int *stats2, int pontos){
    printf("jogador 2 escolha seus atributos, voce tem %d\n", pontos);
    printf("ataque:\n");
    scanf("%d", atq2);
    printf("defesa:\n");
    scanf("%d", def2);
    printf("Vida:\n");
    scanf("%d", hp2);
    *stats2 = *atq2 + *def2 + *hp2;
}

int buff1(int *atq1, int *def1){
    int a;
    printf("Player 1, deseja buffar ataque(1) ou defesa(2)?");
    scanf ("%d", &a);
if( 1 > a > 2){
    printf("Escolha entre 1 ou 2 seu burro \n Deseja buffar ataque(1) ou defesa(2)?");
    scanf ("%d", &a);
}
    if(a == 1){
        *atq1 = *atq1 + 3;
        return *atq1;
    }if (a == 2){
        *def1 = *def1 +3;
        return *def1;
    }
    
}
int buff2(int *atq2, int *def2){
    int b;
    printf("Player 2, deseja buffar ataque(1) ou defesa(2)?");
    scanf ("%d", &b);
if( 1 > b > 2){
    printf("Escolha entre 1 ou 2 seu burro \n Deseja buffar ataque(1) ou defesa(2)?");
    scanf ("%d", &b);
}
    if(b == 1){
        *atq2 = *atq2 + 3;
        return *atq2;
    }if (b == 2){
        *def2 = *def2 +3;
        return *def2;
    }
}

int ataque1(int *atq1, int *def2, int *hp2){
   int resultado = *atq1 - *def2;
   *hp2 = *hp2 - resultado;
   printf("voce causou %d de dano\n Vida do inimigo = %d\n", resultado, *hp2);
   return *hp2;
}

int ataque2(int *atq2, int *def1, int *hp1){
   int resultado2 = *atq2 - *def1;
   *hp1 = *hp1 - resultado2;
     printf("voce causou %d de dano\n Vida do inimigo = %d\n", resultado2, *hp1);
     return *hp1;
}

int main()
{
    srand(time(NULL));
int p1, atq1, atq2, def1, def2, hp1, hp2, pontos = 50,stats1, stats2;
srand(time(NULL));
 
escolha(&atq1, &def1, &hp1, &stats1,pontos);
    if (stats1 > 50){
        printf("jogador 1 escolha seus atributos, voce tem %d\n", pontos);
    printf("ataque:\n");
    scanf("%d", &atq1);
    printf("defesa:\n");
    scanf("%d", &def1);
    printf("Vida:\n");
    scanf("%d", &hp1);
    }if(50 > stats1){
        pontos = pontos - stats1;
        escolha(&atq1, &def1, &hp1, &stats1, pontos);
    
    }
    pontos = 50;
escolha2(&atq2, &def2, &hp2, &stats2, pontos);
if (stats2 > 50){
        printf("Voce tentou colocoar mais que 50 pontos \n jogador 2 escolha seus atributos, voce tem %d\n", pontos);
    printf("ataque:\n");
    scanf("%d", &atq2);
    printf("defesa:\n");
    scanf("%d", &def2);
    printf("Vida:\n");
    scanf("%d", &hp2);
    }if(50 > stats2){
        pontos = pontos - stats2;
        escolha2(&atq2, &def2, &hp2, &stats2, pontos);
    }
    
   p1 = (rand() % 2) + 1;
while((hp1 > 0) || (hp2 > 0)){
    if(p1 == 1){
        int i;
    printf("Jogador 1, sua vez de jogar\n Escolha entre atacar(1) ou buffar(2):\n");
    scanf("%d", &i);
    if( 1 > i > 2){
    printf("Seu burro, escolha entre 1 ou 2\n");
    printf("Jogador 1, sua vez de jogar\n Escolha entre atacar(1) ou buffar(2):\n");
    scanf("%d", &i);
    }
    if(i == 1){
      hp2 = ataque1(&atq1, &def2, &hp2);
      if (hp2 < 1){
    printf("Parabéns jogador 1 voce ganhou!");
    break;
}
    }
    if(i == 2){
       atq1, def1 = buff1(&atq1, &def1);
    }
    
      printf("Jogador 2, sua vez de jogar\n Escolha entre atacar(1) ou buffar(2):");
     scanf("%d", &i);
    if( 1 > i > 2){
    printf("Seu burro, escolha entre 1 ou 2\n");
    printf("Jogador 2, sua vez de jogar\n Escolha entre atacar(1) ou buffar(2):\n");
    scanf("%d", &i);
    }
    if(i == 1){
    hp1 = ataque2(&atq2, &def1, &hp1);
    if(hp1 < 1){
    printf("Parabéns jogador 2 voce ganhou!");
    break;
}
    }
    if(i == 2){
        buff2(&atq2, &def2);
    }
}
if (p1 == 2){
    int i;
    printf("Jogador 2, sua vez de jogar\n Escolha entre atacar(1) ou buffar(2):");
     scanf("%d", &i);
    if( 1 > i > 2){
    printf("Seu burro, escolha entre 1 ou 2\n");
    printf("Jogador 2, sua vez de jogar\n Escolha entre atacar(1) ou buffar(2):\n");
    scanf("%d", &i);
    }
    if(i == 1){
      hp1 = ataque2(&atq2, &def1, &hp1);
      if(hp1 < 1){
    printf("Parabéns jogador 2 voce ganhou!");
    break;
}
    }
    if(i == 2){
        buff2(&atq2, &def2);
    }
    
    printf("Jogador 1, sua vez de jogar\n Escolha entre atacar(1) ou buffar(2):\n");
    scanf("%d", &i);
    if( 1 > i > 2){
    printf("Seu burro, escolha entre 1 ou 2\n");
    printf("Jogador 1, sua vez de jogar\n Escolha entre atacar(1) ou buffar(2):\n");
    scanf("%d", &i);
    }
    if(i == 1){
      hp2 = ataque1(&atq1, &def2, &hp2);
      if (hp2 < 1){
    printf("Parabéns jogador 1 voce ganhou!");
    break;
}
    }
    if(i == 2){
        buff1(&atq1, &def1);
    }
}
}

return 0;
}
