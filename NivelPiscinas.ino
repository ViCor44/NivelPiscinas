/***************
Nivel Automático para Tanques 
Autor: Victor Correia
Versão 1.0
Data: 07/08/2019
Alterado em:
***************/

#define RELE 13
#define VERDE 9
#define VERMELHO 10
#define NIVEL_BAIXO 7
#define NIVEL_ALTO 8

bool flag = 0;

void setup() {
  // put your setup code here, to run once:
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
}

void loop() {
  
  bool flag;
  if(digitalRead(NIVEL_BAIXO) == 1 && flag == 0){
    flag = 1;
    digitalWrite(RELE, HIGH);
    digitalWrite(VERDE, LOW);
    digitalWrite(VERMELHO, HIGH);
    Serial.println("Vazio");      
  }
  if(digitalRead(NIVEL_ALTO) == 0 && flag == 1){
    flag = 0;
    digitalWrite(RELE, LOW);
    digitalWrite(VERDE, HIGH);
    digitalWrite(VERMELHO, LOW);
    Serial.println("Cheio");      
  }   
  Serial.println(flag);
  Serial.println(digitalRead(NIVEL_BAIXO));
}  
