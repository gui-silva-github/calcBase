#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

// Declaracao de funcoes

void calc();

void sum();
void sub();
void mult();
void mineDiv();

// ----------

void convert();

int convertBinToDec(long long binary_value);
long long convertDecToBin(int decimal_value);
int convertDecToOct(int decimal_value);
long long convertOctToDec(int octal_value);

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
            sum();
            break;
       case 2: 
            sub();
            break;
       case 3: 
            mult();
            break;
       case 4:
            mineDiv();
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

// Operacoes

void sum(){
     float value1, value2, result;
     
     printf("\nDigite o valor 1 = ");
     scanf("%f", &value1);
     
     printf("\nDigite o valor 2 = ");
     scanf("%f", &value2);
     
     result = value1 + value2;
     printf("Resultado = %f", result);
     
     system("pause");
     system("cls");
     menu();    
}

void sub(){
     float value1, value2, result;
     
     printf("\nDigite o valor 1 = ");
     scanf("%f", &value1);
     
     printf("\nDigite o valor 2 = ");
     scanf("%f", &value2);
     
     result = value1 - value2;
     printf("Resultado = %f", result);
     
     system("pause");
     system("cls");
     menu();
}

void mult(){
     float value1, value2, result;
     
     printf("\nDigite o valor 1 = ");
     scanf("%f", &value1);
     
     printf("\nDigite o valor 2 = ");
     scanf("%f", &value2);
     
     result = value1 * value2;
     printf("Resultado = %f", result);
     
     system("pause");
     system("cls");
     menu();    
}

void mineDiv(){
     float value1, value2, result;
     
     printf("\nDigite o valor 1 = ");
     scanf("%f", &value1);
     
     printf("\nDigite o valor 2 = ");
     scanf("%f", &value2);
     
     if(value2 != 0){
        result = value1 / value2;
        printf("Resultado = %f", result);       
     } else {
       printf("O divisor nao pode ser 0");    
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
               
               printf("[%lld] em binario = [%d] em decimal\n", binary_value, convertBinToDec(binary_value));   
               
               system("pause");
               system("cls");
               menu();
        }
        
        else if (opc == '2'){
               printf("\nDigite o numero binario = ");
               scanf("%lld", &binary_value); 
               
               decimal_value = convertBinToDec(binary_value);
               octal_value = convertDecToOct(decimal_value);
               
               printf("[%lld] em binario = [%d] em octal\n", binary_value, octal_value);
               
               system("pause");
               system("cls");
               menu();
        }
        
        else if (opc == '3'){
             printf("\nDigite o numero decimal = ");
             scanf("%d", &decimal_value);
             
             printf("[%d] em decimal = [%lld] em binario\n", decimal_value, convertDecToBin(decimal_value)); 
             
             system("pause");
             system("cls");
             menu();  
        }
        
        else if (opc == '4'){
             printf("\nDigite o numero decimal = ");
             scanf("%d", &decimal_value);
             
             printf("[%d] em decimal = [%d] em octal\n", decimal_value, convertDecToOct(decimal_value));   
             
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
             
             printf("[%d] em octal = [%lld] em decimal\n", octal_value, convertOctToDec(octal_value));     
             
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

int convertBinToDec(long long binary_value){
    int decimal_value = 0, sequencial = 0, rest;
    
    while(binary_value != 0){
        rest = binary_value % 10;
        
        binary_value /= 10;
        
        decimal_value += rest * pow(2, sequencial);
        
        ++sequencial;
    }   
    
    return decimal_value;
}

long long convertDecToBin(int decimal_value){
     long long binary_value = 0;
     int rest, sequencial = 1;
     
     while(decimal_value != 0){
          rest = decimal_value % 2;
          
          decimal_value /= 2;
          
          binary_value += rest * sequencial;
          
          sequencial *= 10;
     }    
     
     return binary_value;
}

int convertDecToOct(int decimal_value){
    int octal_value = 0, sequencial = 1;
    
    while(decimal_value != 0){
        octal_value += (decimal_value % 8) * sequencial;
        
        decimal_value /= 8;
        
        sequencial *= 10;                    
    }   
    
    return octal_value;
}

long long convertOctToDec(int octal_value){
     int decimal_value = 0, sequencial = 0;
     
     while(octal_value != 0){
        decimal_value += (octal_value % 10) * pow(8, sequencial);
        
        ++sequencial;
        
        octal_value /= 10;
     }     
     
     return decimal_value;
}

int main(){
 menu();
 system("pause");
 return 0;   
}
