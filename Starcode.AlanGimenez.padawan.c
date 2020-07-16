#include <stdio.h>
#include <stdbool.h> 

/* Pre: calcular la fuerza, voluntad y pasado.
   Post: mostrar resultados por consola. */
   
   
const float FUERZA = 0.0F;  
const float MIDICLORIANO1 = 100.0f; 
const float MIDICLORIANO2 = 2999.9f; 
#define BAJO 'b';
#define NORMAL 'n'; 
#define TRAGICO 't';
const float INFLUENCIA = 3.4F; 
const float OSCURIDAD = 0.001117684315; 


float influencia_fuerza(){
    
    float midicloriano = 0.0f; 
    int valor_correcto= 0;
    
    printf ("indique el valor del midicloriano: "); 
    scanf ("%f", &midicloriano);
    printf ("\n"); 
    
    while(valor_correcto == 0){
        
        if((midicloriano < MIDICLORIANO1) || midicloriano > MIDICLORIANO2){
            
            printf ("el midicloriano esta fuera del rango valido, vuelva a ingresar el valor: \n"); 
            scanf ("%f", &midicloriano);
            
        }else{
            printf ("el midicloriano es correcto\n"); 
            valor_correcto = 1;         
            
        }
    }
    
    return  midicloriano;     
    
}

float voluntad(){
    
    char voluntad; 
    float tipo_voluntad= 0;
    
    printf ("\nindique el valor de voluntad: \n"); 
    scanf (" %c", &voluntad); 

    while(tipo_voluntad == 0){
        
        switch(voluntad){
            
            case 'f' : printf ("\nla voluntad del padawan es floja\n");
                       tipo_voluntad = 10.3f;
            break;
            case 'b' : printf ("\nla voluntad del padawan es buena\n");
                       tipo_voluntad = 10.3f;
            break;
            case 'm' : printf ("\nla voluntad del padawan es mediana\n");
                       tipo_voluntad = 54.5f;
            break;
            case 'a' : printf ("\nla voluntad del padawan es alta\n");
                       tipo_voluntad = 54.5f;
            break;
            case 'e' : printf ("\nla voluntad del padawan es enorme\n");
                       tipo_voluntad = 103.4f;
            break;
            case 'p' : printf ("\nla voluntad del padawan es peligrosa\n");
                       tipo_voluntad = 103.4f;
            break;
            default : printf ("\nel tipo de voluntad es erroneo, volver a intentar: \n"); 
                      scanf (" %c", &voluntad);
                      tipo_voluntad= 0; 
            break;
        
            
        }
    }

return tipo_voluntad; 

}

float pasado(){
    
    char pasado; 
    float tipo_de_pasado= 0.0f; 
    
    printf ("\ningrese el valor del pasado: \n"); 
    scanf (" %c", &pasado); 
    
    while(tipo_de_pasado == 0.0f){ 
    
    switch(pasado){
        
        case 'b' : printf ("\nel pasado del novato es bueno\n");
                    tipo_de_pasado = 1.5f; 
        break; 
        case 'n' : printf ("\nel pasado del novato es normal\n");
                    tipo_de_pasado = 0.4f;
        break; 
        case 't': printf ("\nel pasado del novato es tragico\n");
                       tipo_de_pasado = 0.4f;
        break;
        default : printf ("\nvalor incorrecto vuelva a intentar\n"); 
                  scanf (" %c", &pasado);
                  
        
    }
    
        
    }
    
    return tipo_de_pasado;     
    
}

float calculo_fuerza(float midicloriano, float INFLUENCIA, float tipo_voluntad, float OSCURIDAD, float tipo_de_pasado){
    
   float calculo_influencia= midicloriano * INFLUENCIA;
   float probabilidad_de_convertirse= tipo_voluntad + (OSCURIDAD * calculo_influencia)/tipo_de_pasado; 
   
    printf ("\nel resultado de calculo_influencia es: %ffuerza\n", calculo_influencia); 
    printf ("\nel resultado de convertirse es: %f%\n", probabilidad_de_convertirse); 
    
    return probabilidad_de_convertirse; 
}

int tiempo_restante(float voluntad, float fuerza){
    
    int calculo_voluntad = ((voluntad * 20) /100) + voluntad; 
    int cuenta_fuerza = fuerza - ((fuerza * 75) /100); 
    int calculo_tiempo = fuerza/voluntad; 
    
    printf ("\nel tiempo restante es: %imeses\n", calculo_tiempo); 
    
    return calculo_tiempo; 
    
}





int main(){
    
    float INFLUENCIA = 3.4F;
    float OSCURIDAD = 0.001117684315; 
    
    float resultado_fuerza;
    float resultado_voluntad;
    float resultado_pasado; 
    float probabilidad_convertirse; 
    
    resultado_fuerza = influencia_fuerza();
    
    resultado_voluntad = voluntad(); 

    resultado_pasado = pasado();
    
    probabilidad_convertirse = calculo_fuerza(resultado_fuerza, INFLUENCIA, resultado_voluntad, OSCURIDAD, resultado_pasado); 
    
    tiempo_restante(resultado_voluntad, resultado_fuerza); 
    
    if(probabilidad_convertirse > 80){
        
        printf ("\nTransmision de lo aprendido: fuerza, maestria; pero insensatez, debilidad, fracaso tambien. ¡Si, fracaso sobre todo! El mejor profesor, el fracaso es. By Master Yoda");
    
    }
    
    
    return 0;

    
}



