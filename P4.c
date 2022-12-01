/*
-Diego Saavedra
-Nicolás Vázquez
-Pedro Peón
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>
#include <time.h>
#include <stdbool.h>

#define UMBRAL 10
#define SWAP(a,b) {int t = (a); (a) = (b); (b) = t;}

struct mediciones{
    double tiempo;
    double subestimada;
    double ajustada;
    double sobrestimada;
};

double microsegundos(){
/* obtiene la hora del sistema en microsegundos */
    struct timeval t;
    if (gettimeofday(&t, NULL) < 0 )
        return 0.0;
    return (t.tv_usec + t.tv_sec * 1000000.0);
}

void inicializar_semilla(){
    srand(time(NULL));
}

void aleatorio(int v [], int n){
/* se generan números pseudoaleatorio entre -n y +n */
    int i, m=2*n+1;
    for (i=0; i < n; i++)
        v[i] = (rand() % m) - n;
}

void ascendente(int v [], int n){
    int i;
    for (i=0; i < n; i++)
        v[i] = i;
}

void descendente(int v [], int n){
	int i;

	for (i=0; i < n ; i++)
		v[i] = n-i;
}

void ord_ins(int v[], int n){
    int i, j, x;

    for (i=1; i<n; i++){
        x = v[i];
        j = i-1;
        while (j>=0 && v[j]>x){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = x;
    }
}

void OrdenarAux(int v[], int izq, int der){
    int x, pivote, i, j;

    if(izq + UMBRAL <= der){
        x = izq + (rand() % (der - izq));
        pivote = v[x]; //Se escoje el pivote aleatoriamente
        SWAP(v[izq], v[x]); //Se pone de primero
        i = izq + 1;
        j = der;

        while(i <= j){ //Termina cuando i y j se cruzan
        
            while((i <= der) && (v[i] < pivote)){
                i++; //Si es menor que el pivote, avanza
            }

            while(v[j] > pivote){
                j--; //Si es mayor que el pivote, avanza
            }

            if(i <= j){ //Si no se cruzan, se intercambian
                SWAP(v[i], v[j]);
                i++;
                j--;
            }
        }
        SWAP(v[izq], v[j]); //Se mueve el pivote en el medio
        OrdenarAux(v, izq, (j-1));
        OrdenarAux(v, (j+1), der);
    }
}

void ord_rapida(int v[], int n){
    OrdenarAux(v, 0, (n-1));

    if(UMBRAL > 1){ //Supera el umbral y se ordena por insercion
        ord_ins(v, n);
    }
}

void imp_array(int v[], int n){
    int i;

    printf("[");
    for(i = 0; i < (n-1); i++){
        printf("%d, ", v[i]);
    }
    printf("%d]\n", v[i]);
}

void cabecera_ini(void (*inicializar)(int v[], int n)){
    if (inicializar == descendente)
        printf("\n%s\n", "Inicializacion descendente");
    else if (inicializar == ascendente)
        printf("\n%s\n", "Inicializacion ascendente");
    else
        printf("\n%s\n", "Inicializacion aleatoria");
}

void comp_ordenado(int v[], int n){
    int i;
    int ordenado = true;

    for (i=0; i<n-1; i++){
        if (v[i] > v[i+1])
            ordenado = false;
    }
    printf("%s%d\n", "Ordenado? ", ordenado);
}

void test(void (*inicializar)(int v[], int n)){
    int tam_vector = 10, v[tam_vector];

    cabecera_ini(inicializar);
    inicializar(v,tam_vector);
    imp_array(v,tam_vector);
    comp_ordenado(v,tam_vector);
    ord_rapida(v,tam_vector);
    imp_array(v,tam_vector);
    comp_ordenado(v,tam_vector);
}

void testear_todo(){
    test(ascendente);
    test(descendente);
    test(aleatorio);
}

double medir_tiempo(int n, void (*inicializar)(int v[], int n)){

    double tiempo,instante_inicial,instante_final,tiempo_ord_con_init,
           tiempo_de_init;
    int v[n], i;
    int repeticiones = 2000;
    int umbral = 500;

    inicializar(v, n);
    instante_inicial = microsegundos();
    ord_rapida(v, n);
    instante_final = microsegundos();
    tiempo = instante_final - instante_inicial;

    if (tiempo < umbral){
            instante_inicial = microsegundos();
            for(i=0; i < repeticiones; i++){
                inicializar(v, n);
                ord_rapida(v, n);
            }
            instante_final = microsegundos();
            tiempo_ord_con_init = (instante_final - instante_inicial)
                                  / repeticiones;
            instante_inicial = microsegundos();
            for(i=0; i < repeticiones; i++){
                inicializar(v, n);
            }
            instante_final = microsegundos();
            tiempo_de_init =(instante_final - instante_inicial)/repeticiones;
            tiempo = tiempo_ord_con_init - tiempo_de_init;
            printf("%s", "*");
    }
    else printf(" ");
    return tiempo;
}

struct mediciones calcular_cota1(int n, void (*inicializar)(int v[], int n)){
	struct mediciones cotas;
	
    cotas.tiempo = medir_tiempo(n, inicializar);
    if (inicializar == ascendente){
            cotas.subestimada = cotas.tiempo/n;;
            cotas.ajustada = cotas.tiempo/pow(n, 1.07);
            cotas.sobrestimada = cotas.tiempo/pow(n,1.15);
    }
    else if (inicializar == descendente){
            cotas.subestimada = cotas.tiempo/n;
            cotas.ajustada = cotas.tiempo/pow(n, 1.08);
            cotas.sobrestimada = cotas.tiempo/pow(n,1.19);
    }
    else if (inicializar == aleatorio){
            cotas.subestimada = cotas.tiempo/n;
            cotas.ajustada = cotas.tiempo/pow(n, 1.1);
            cotas.sobrestimada = cotas.tiempo/pow(n, 1.3);
    }
    return cotas;	
}

struct mediciones calcular_cota10(int n, void (*inicializar)(int v[], int n)){
	struct mediciones cotas;
	
    cotas.tiempo = medir_tiempo(n, inicializar);
    if (inicializar == ascendente){
            cotas.subestimada = cotas.tiempo/pow(n, 1.04);
            cotas.ajustada = cotas.tiempo/pow(n, 1.1);
            cotas.sobrestimada = cotas.tiempo/pow(n,1.18);
    }
    else if (inicializar == descendente){
            cotas.subestimada = cotas.tiempo/n;
            cotas.ajustada = cotas.tiempo/pow(n, 1.1);
            cotas.sobrestimada = cotas.tiempo/pow(n,1.2);
    }
    else if (inicializar == aleatorio){
            cotas.subestimada = cotas.tiempo/n;
            cotas.ajustada = cotas.tiempo/pow(n, 1.1);
            cotas.sobrestimada = cotas.tiempo/pow(n, 1.2);
    }
    return cotas;	
}

struct mediciones calcular_cota100(int n, void (*inicializar)(int v[], int n)){
	struct mediciones cotas;
	
    cotas.tiempo = medir_tiempo(n, inicializar);
    if (inicializar == ascendente){
            cotas.subestimada = cotas.tiempo/pow(n, 1.04);
            cotas.ajustada = cotas.tiempo/pow(n, 1.1);
            cotas.sobrestimada = cotas.tiempo/pow(n,1.18);
    }
    else if (inicializar == descendente){
            cotas.subestimada = cotas.tiempo/n;
            cotas.ajustada = cotas.tiempo/pow(n, 1.1);
            cotas.sobrestimada = cotas.tiempo/pow(n,1.2);
    }
    else if (inicializar == aleatorio){
            cotas.subestimada = cotas.tiempo/n;
            cotas.ajustada = cotas.tiempo/pow(n, 1.1);
            cotas.sobrestimada = cotas.tiempo/pow(n, 1.2);
    }
    return cotas;	
}

void crear_tabla(void (*inicializar)(int v[], int n)){                                
    int n=500;
    int *v, i, tiempoMax = 0;
    struct mediciones cotas;

    cabecera_ini(inicializar);
    printf("%13s%15.4s%15.9s%15.9s%15.9s\n","n","T(n)","T(n)/f(n)",
            "T(n)/g(n)","T(n)/h(n)");
	for(i = 0 ; (i < 12) && tiempoMax < 1000000 ; i++){
        v=(int*)malloc(n*sizeof(int));
        if (UMBRAL == 1)
            cotas = calcular_cota1(n, inicializar);
        else if (UMBRAL == 10)
            cotas = calcular_cota10(n, inicializar);
        else cotas = calcular_cota100(n, inicializar);
        printf("%12d%15.3f%15.7f%15.7f%15.7f\n", n, cotas.tiempo,
                cotas.subestimada, cotas.ajustada, cotas.sobrestimada);
        tiempoMax = cotas.tiempo;
        n *= 2;
        free(v);
	}
}

void repetir_tablas(){
    int i;

    for(i = 0; i < 3; i++)
        crear_tabla(ascendente);
    for(i = 0; i < 3; i++)
        crear_tabla(descendente);
    for(i = 0; i < 3; i++)
        crear_tabla(aleatorio);
}

int main(){
    testear_todo();
    repetir_tablas();

   return 0;
}
