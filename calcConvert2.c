#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

// Declaracao de funcoes

void calc();

void operator();

// ----------

void convert();

int convertBaseBin();
long long convertToBaseBin();
int convertBaseOctDec(); 

// ----------

// Menu central

void menu(){
     int choice;
     
     printf("\t\tBem vindo ao Programa de Numeros do Gui em C\n\n");
    printf("\t\tSelecione o que voce deseja utilizar:\n");
    printf("\t\t1 - Calculadora\n");
    printf("\t\t2 - Conversor\n");
    printf("\t\t3 - Sair\n");    
    
    printf("Escolha = ");
    scanf("%d", &choice);
    
    switch(choice){
       case 1: 
            calc();
            break;
       case 2: 
            convert();
            break;
       case 3: 
            system("exit");
            printf("\nFinalizando...\n\n");
            break;
       default: 
                printf("\nComando invalido, tente novamente!\n\n");
                system("pause");
                system("cls");
                break;
    }
}

// Calculadora

void calc(){
    int choice;

    printf("\t\tBem vindo a Calculadora\n\n");
    printf("\t\tSelecione uma operacao matematica:\n");
    printf("\t\t1 - Adicao\n");
    printf("\t\t2 - Subtracao\n");
    printf("\t\t3 - Multiplicacao\n");
    printf("\t\t4 - Divisao\n");
    printf("\t\t5 - Sair\n");    
    
    printf("Operacao = ");
    scanf("%d", &choice);
    
    switch(choice){
       case 1:
            operator(1);
            break;
       case 2: 
            operator(2);
            break;
       case 3: 
            operator(3);
            break;
       case 4:
            operator(4);
            break;
       case 5:
            system("exit");
            printf("\nFinalizando...\n\n");
            break;
       default: 
            printf("\nComando invalido, tente novamente!\n\n");
            system("pause");
            system("cls");
            break;
    }
            
}

// Operacao

void operator(int op){
     float value1, value2, result = 0;
     int exception = 0;
     
     printf("\nDigite o valor 1 = ");
     scanf("%f", &value1);
     
     printf("\nDigite o valor 2 = ");
     scanf("%f", &value2);
     
     switch(op){
       case 1:
            result = value1 + value2;
            break;
       case 2:
            result = value1 - value2;
            break;
       case 3: 
            result = value1 * value2;
            break;
       case 4:
            if(value2 != 0){
                result = value1 / value2;       
             } else {
                exception = 1;       
             }
            break;           
     }
     
     if(exception == 1){
        printf("O divisor nao pode ser 0");                    
     } else {
        printf("Resultado = %f", result);
     }
    
     system("pause");
     system("cls");
     menu();
}

// Conversor usando o modelo ascii

void convert(){
     char opc;
     
     int octal_value;
     long long binary_value;
     int decimal_value;
     
     int quotient;  
     int sequencial, temp_value, lengthStr;
     char hexa_value[100]; 
     
     while(opc != '0'){
          printf("\t\tBem vindo ao Conversor\n\n");
        printf("\t\tSelecione uma opcao:\n");
        printf("\t\t1 - Binario para Decimal\n");
        printf("\t\t2 - Binario para Octal\n");
        printf("\t\t3 - Decimal para Binario\n");
        printf("\t\t4 - Decimal para Octal\n");
        printf("\t\t5 - Decimal para Hexadecimal\n");
        printf("\t\t6 - Octal para Decimal\n");
        printf("\t\t7 - Hexadecimal para Decimal\n");
        printf("\t\t8 - Sair\n");
        
        printf("Escolha = ");
        scanf(" %c", &opc);
        
        if (opc == '1'){
               printf("\nDigite o numero binario = ");
               scanf("%lld", &binary_value);
               
               printf("[%lld] em binario = [%d] em decimal\n", binary_value, convertBaseBin(binary_value, 10));   
               
               system("pause");
               system("cls");
               menu();
        }
        
        else if (opc == '2'){
               printf("\nDigite o numero binario = ");
               scanf("%lld", &binary_value); 
               
               decimal_value = convertBaseBin(binary_value, 10);
               octal_value = convertBaseOctDec(decimal_value, 10);
               
               printf("[%lld] em binario = [%d] em octal\n", binary_value, octal_value);
               
               system("pause");
               system("cls");
               menu();
        }
        
        else if (opc == '3'){
             printf("\nDigite o numero decimal = ");
             scanf("%d", &decimal_value);
             
             printf("[%d] em decimal = [%lld] em binario\n", decimal_value, convertToBaseBin(decimal_value)); 
             
             system("pause");
             system("cls");
             menu();  
        }
        
        else if (opc == '4'){
             printf("\nDigite o numero decimal = ");
             scanf("%d", &decimal_value);
             
             printf("[%d] em decimal = [%d] em octal\n", decimal_value, convertBaseOctDec(decimal_value, 10));   
             
             system("pause");
             system("cls");
             menu();  
        }
        
        else if (opc == '5'){
             printf("\nDigite o numero decimal = ");
             scanf("%d", &decimal_value);
             
             sequencial = 0;
             quotient = decimal_value;
             
             while(quotient != 0){
                 temp_value = quotient % 16;
                 
                 if(temp_value < 10){
                    temp_value += 48;           
                 } else {
                    temp_value += 55;       
                 } 
                 
                 hexa_value[sequencial] = temp_value;
                 
                 quotient /= 16;      
                 
                 sequencial++;       
             }
             
             hexa_value[sequencial] = '\0';
             
             int i, j;
             char temp;
             
             for(i = 0, j = sequencial - 1; i < j; i++, j--){
                   temp = hexa_value[i];
                   hexa_value[i] = hexa_value[j];
                   hexa_value[j] = temp;      
             }
             
             printf("[%d] em decimal = [%s] em hexadecimal\n", decimal_value, hexa_value);     
             
             system("pause");
             system("cls");
             menu();
        }
        
        else if (opc == '6'){
             printf("\nDigite o numero octal = ");
             scanf("%d", &octal_value);
             
             printf("[%d] em octal = [%d] em decimal\n", octal_value, convertBaseOctDec(octal_value, 8));     
             
             system("pause");
             system("cls");
             menu();
        }
        
        else if (opc == '7'){
             decimal_value = 0;
             
             while (getchar() != '\n');

            printf("\nDigite o numero hexadecimal = ");
            fgets(hexa_value, sizeof(hexa_value), stdin);
            hexa_value[strcspn(hexa_value, "\n")] = 0;

            decimal_value = strtol(hexa_value, NULL, 16);
             
             printf("[%s] em hexadecimal = [%d] em decimal", hexa_value, decimal_value);
             
             system("pause");
             system("cls");
             menu();
                          
        }
        
        else if (opc == '8'){
        
             system("pause");
             system("cls");
             menu();
             
        }
        
        else {
             printf("Opcao desconhecida [%c]\n", opc);
             
             system("pause");
             system("cls");
             menu();
        }
         
     }  
}

int convertBaseBin(long long binary_value, int baseTo){
    int return_value = 0, sequencial = 0, rest;
    
    while(binary_value != 0){
        rest = binary_value % baseTo;
        
        binary_value /= baseTo;
        
        return_value += rest * pow(2, sequencial);
        
        ++sequencial;
    }   
    
    return return_value;
}

long long convertToBaseBin(int decimal_value){
     long long binary_value = 0, sequencial = 0, rest;
     
     while(decimal_value != 0){
          rest = decimal_value % 2;
          
          decimal_value /= 2;
          
          binary_value += rest * pow(10, sequencial);
          
          ++sequencial;
     }    
     
     return binary_value;
}

int convertBaseOctDec(int value, int baseFrom){
    int return_value = 0, sequencial = 0, rest;
        
        if(baseFrom == 10){
          while(value != 0){
              rest = value % 8;
              value /= 8;
              
              return_value += rest * pow(baseFrom, sequencial);
              ++sequencial;
          }            
        } else {
          while(value != 0){
              rest = value % 10;
              value /= 10;
              
              return_value += rest * pow(baseFrom, sequencial);
              ++sequencial;
          }         
        }
    
    return return_value;
}

int main(){
 menu();
 system("pause");
 return 0;   
}
