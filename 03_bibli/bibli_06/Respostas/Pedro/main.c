#include <stdio.h>
#include "temperature_conversor.h"

void printarConversaoCelsius(int temperature, char destino){
    if(destino == 'k'){
        printf("Temperature: %.2fK", convert_temperature(temperature, *convert_celsius_to_kelvin));
    }

    if(destino == 'f'){
        printf("Temperature: %.2fFº", convert_celsius_to_fahrenheit(temperature));
    }
}

void printarConversaoKelvin(int temperature, char destino){
    if(destino == 'c'){
        printf("Temperature: %.2fCº", convert_kelvin_to_celsius(temperature));
    }

    if(destino == 'f'){
        printf("Temperature: %.2fFº", convert_kelvin_to_fahrenheit(temperature));
    }
}

void printarConversaoFarenheit(int temperature, char destino){
    if(destino == 'c'){
        printf("Temperature: %.2fCº", convert_fahrenheit_to_celsius(temperature));
    }

    if(destino == 'k'){
        printf("Temperature: %.2fK", convert_fahrenheit_to_kelvin(temperature));
    }
}

int main(){
    float temperature;
    char origem, destino;

    scanf("%f %c %c", &temperature, &origem, &destino);

    if(origem == 'c'){
        printarConversaoCelsius(temperature, destino);
    }

    if(origem == 'k'){
        printarConversaoKelvin(temperature, destino);
    }

    if(origem == 'f'){
        printarConversaoFarenheit(temperature, destino);
    }

    return 0;
}