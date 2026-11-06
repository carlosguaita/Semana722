#include <stdio.h>
#include <string.h>
#include "funciones.h"

float validarFloatRango(float a, float b){
    float num;
    int val;
    do
    {
        val = scanf("%f",&num);
        while((getchar())!='\n');
        if(num < a || num > b || val != 1){
            printf("Error: el valor ingresado es incorrecto\n");
        }
    } while (num < a || num > b || val != 1);
    return num;
}

void leerCadena(char cadena[], int n){
    fgetc(cadena,n,stdin);
    int len = strlen(cadena) - 1;
    cadena[len] = '\0';
}

void mostrarHabitaciones(int estados[5], char cedulas[5][20]){
    printf("Hab.\t\tEstado\t\tCedula\n");
    for (int i = 0; i < 5; i++)
    {
        if (estados[i]==0){
            printf("%d\t\tLibre\t\t%s\n",i,cedulas[i]);
        }else{
             printf("%d\t\tOcupada\t\t%s\n",i,cedulas[i]);
        }
    }
}

void ingresarHuesped(int estados[5], char cedulas[5][20], int diasEntrada[5]){
    printf("Habitacion (0-4): ");
    int indice = validarFloatRango(0,4);
    if(estados[indice]==0){
        printf("Cedula: ");
        leerCadena(cedulas[indice],20);
        printf("Dia Ingreso (1-31):");
        diasEntrada[indice] = validarFloatRango(1,31);
        estados[indice] = 1;
    }else{
        printf("Error: La habitacion no esta libre\n");
    }
}

void salidaHuesped(int estados[5], char cedulas[5][20], int diasEntrada[5]){
    printf("Habitacion (0-4): ");
    int indice = validarFloatRango(0,4);
    if(estados[indice]==1){
         printf("Cedula: %s\n",cedulas[indice]);
         printf("Dia Ingreso: %d\n",diasEntrada[indice]);
         printf("Dia Salida: ");
         int diaSalida = validarFloatRango(diasEntrada[indice],31);
         int dias = diasEntrada[indice] - diaSalida;
         float descuento;
         float subtotal = dias * 25;
         if (dias == 0)
         {
            dias = 1;
         }else if(dias>=3 && dias <=6){
            descuento = subtotal * 0.1;
            printf("Descuento (10): %.2f\n",descuento);
         }else if (dias >= 7)
         {
            descuento = subtotal * 0.2;
            printf("Descuento (20): %.2f\n",descuento);
         }else{
            printf("Descuento (0)");
         }
         float total = subtotal - descuento;
         printf("El total es: %.2f\n",total);
    }else{
        printf("Error: La habitacion esta libre\n");
    }
}