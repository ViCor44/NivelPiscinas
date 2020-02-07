/***************
Nivel Automatico para Tanques 
Autor: Victor Correia
Versao 1.0
Data: 07/08/2019
Alterado em: 07/02/2020
***************/

#define RELE 12
#define VERDE 9
#define VERMELHO 10
#define NIVEL_BAIXO 7
#define NIVEL_ALTO 8

bool flag = 0;

void setup() {  
  Serial.begin(9600); 
  pinMode(RELE, OUTPUT);
  pinMode(VERDE, OUTPUT);
  pinMode(VERMELHO, OUTPUT);
  pinMode(NIVEL_BAIXO, INPUT); 
  digitalWrite(NIVEL_BAIXO, HIGH);
  pinMode(NIVEL_ALTO, INPUT); 
  digitalWrite(NIVEL_ALTO, HIGH);
  digitalWrite(VERDE, LOW);
  digitalWrite(VERMELHO, LOW);
  digitalWrite(RELE, LOW);
  Serial.print(NIVEL_BAIXO);
  if(digitalRead(NIVEL_BAIXO) == 0){ //Verifica estado inicial do nivel baixo
    flag = 1;
    digitalWrite(VERMELHO, HIGH);
  }
}

void loop() { 
  if(digitalRead(NIVEL_BAIXO) == 1 && digitalRead(NIVEL_ALTO) == 0){
    while(1){
      digitalWrite(VERMELHO, LOW);
      digitalWrite(VERDE, LOW);
      delay(100);
      digitalWrite(VERMELHO, HIGH);
      digitalWrite(VERDE, HIGH);
      delay(100);  
    }
  }
  if(digitalRead(NIVEL_BAIXO) == 1 && flag == 0){
    flag = 1;
    digitalWrite(RELE, LOW);
    digitalWrite(VERDE, LOW);
    digitalWrite(VERMELHO, HIGH);
    Serial.println("Vazio");      
  }
  if(digitalRead(NIVEL_ALTO) == 0 && flag == 1){
    flag = 0;
    digitalWrite(RELE, HIGH);
    digitalWrite(VERDE, HIGH);
    digitalWrite(VERMELHO, LOW);
    Serial.println("Cheio");      
  }
     
  //Serial.println(flag);
  //Serial.println(digitalRead(NIVEL_BAIXO));
}  

