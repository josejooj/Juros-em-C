#include <stdio.h>
#include <conio.h>

void pl(char str[])
{
    printf("\n   %s", str);
}

void draw() {
    pl("________________________________________________________");
    pl("|                                                      |");
    pl("|                      FEITO POR                       |");
    pl("|                     cleiton#2040                     |");
    pl("|            https://github.com/cleiton2040            |");
    pl("|                                                      |");
    pl("|______________________________________________________|");
    pl("");
}

float get(char str[], int i)
{
    system("CLS");
    draw();
    float variable;
    printf("\n   > %d - %s ", i, str);
    scanf("%f", &variable);
    return variable;
}

float anomes(char str[], int i, float valor)
{
    system("CLS");
    draw();
    printf("\n   > %d - %s (\"a\" = ano, \"m\" = mes, sem aspas): ", i++, str);
    char t = getche();
    printf("\n");
    if (t == 'a' || t == 'A')
    {
        if(valor != 0) valor = valor / 12;
    }
    return valor;
}

int main()
{
    int i = 1;
    char tempojuros, valortodomestempo;

    draw();

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
    system("CLS");
    printf("\n   =~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=  RESULTADOS  =~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=\n\n");
    printf("    _______________________________ PARAMETROS _______________________________\n");
    printf("   |\n");
    printf("   |  >  1. Valor base: %0.2f\n", valbase);
    printf("   |  >  2. Valor adicionado todo mes: %0.2f\n", valmes);
    printf("   |  >  3. Juros: %0.2f a.m\n", juros);
    printf("   |  >  4. Duracao: %d meses (%d anos)\n", duracao, (duracao / 12));
    printf("   |  >  5. Valor investido no total: %0.2f\n", semjuros);
    printf("   |\n");
    printf("   |_______________________________ RENDIMENTOS ______________________________\n");
    printf("   |\n");
    printf("   |  >  Rendimentos sem juros (So juntando): %0.2f\n", semjuros);
    printf("   |  >  Rendimentos em juros simples: %0.2f\n", simples);
    printf("   |  >  Rendimentos em juros compostos: %0.2f\n", compostos);
    printf("   |\n");
    printf("   |_______________________________ DIFERENCA ________________________________\n");
    printf("   |\n");
    printf("   |  >  Diferenca entre juros compostos e sem juros: %0.2f - ^ Compostos ^\n", compostos - semjuros);
    printf("   |  >  Diferenca entre juros compostos e simples: %0.2f - ^ Compostos ^\n", compostos - simples);
    printf("   |  >  Diferenca entre juros simples e sem juros: %0.2f - ^ Simples ^\n", simples - semjuros);
    printf("   |__________________________________________________________________________\n\n");
    system("pause");
    return 1;
}
