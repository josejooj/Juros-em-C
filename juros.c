#include <stdio.h>
#include <conio.h>

float get(char str[1000], int i)
{
    float variable;
    printf("\n   > %d - %s ", i, str);
    scanf("%f", &variable);
    return variable;
}

float anomes(char str[1000], int i, float valor)
{
    printf("\n   > %d - %s (\"a\" = ano, \"m\" = mes, sem aspas): ", i++, str);
    char t = getche();
    printf("\n");
    if (t == 'a' || t == 'A')
    {
        if(valor != 0) valor = valor / 12;
    }
    return valor;
}

void pl(char str[1000])
{
    printf("\n   %s", str);
}

int main()
{
    int i = 1;
    char tempojuros, valortodomestempo;

    pl("________________________________________________________");
    pl("|                                                      |");
    pl("|                      FEITO POR                       |");
    pl("|                     cleiton#2040                     |");
    pl("|            https://github.com/cleiton2040            |");
    pl("|                                                      |");
    pl("|______________________________________________________|");
    pl("");

    float valbase = get("Qual o valor inicial?", i++);                                                                          // valor-base
    float valmes = get("Algum valor sera adicionado ao decorrer do tempo?\n   Se sim, insira o valor, se nao, insira 0:", i++); // adicional
          valmes = anomes("E esse valor sera adicionado todo ano ou todo mes?", i++, valmes);                                   // adicional

    float juros = get("Qual a taxa de juros? Apenas numeros, e decimais com ponto > . <:", i++);
          juros = anomes("Essa taxa de juros e ao mes ou ao ano?", i++, juros);
    int duracao = (get("Esses juros vao durar quantos anos?", i++) * 12) + get("E quantos meses?", i++);
    float simples = valbase;   // valor juros simples
    float compostos = valbase; // valor juros composto
    float semjuros = valbase;
    float jurossimples = simples / 100 * juros;
    i = 0;
    for (; i < duracao; i++)
    {
        semjuros = semjuros + valmes;
        simples = simples + valmes + jurossimples;
        compostos = compostos + valmes + (compostos / 100 * juros);
    }

    printf("\n   =~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=  RESULTADOS  =~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=\n\n    _______________________________ PARAMETROS _______________________________\n   |\n   |  >  1. Valor base: %0.2f\n   |  >  2. Valor adicionado todo mes: %0.2f\n   |  >  3. Juros: %0.2f a.m\n   |  >  4. Duracao: %d meses (%d anos)\n   |  >  5. Valor investido no total: %0.2f\n   |\n   |_______________________________ RENDIMENTOS ______________________________\n   |\n   |  >  Rendimentos sem juros (So juntando): %0.2f\n   |  >  Rendimentos em juros simples: %0.2f\n   |  >  Rendimentos em juros compostos: %0.2f\n   |\n   |_______________________________ DIFERENCA ________________________________\n   |\n   |  >  Diferenca entre juros compostos e sem juros: %0.2f - ^ Compostos ^\n   |  >  Diferenca entre juros compostos e simples: %0.2f - ^ Compostos ^\n   |  >  Diferenca entre juros simples e sem juros: %0.2f - ^ Simples ^\n   |__________________________________________________________________________\n\n", valbase, valmes, juros, duracao, duracao / 12 , semjuros, semjuros, simples, compostos, compostos - semjuros, compostos - simples, simples - semjuros);
    system("pause");
    return 1;
}
