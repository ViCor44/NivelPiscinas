#define RELE 13
#define NIVEL_BAIXO 7
#define NIVEL_ALTO 8

bool flag = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  pinMode(RELE, OUTPUT);
  pinMode(NIVEL_BAIXO, INPUT); 
  digitalWrite(NIVEL_BAIXO, HIGH);
  pinMode(NIVEL_ALTO, INPUT); 
  digitalWrite(NIVEL_ALTO, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  bool flag;
  if(digitalRead(NIVEL_BAIXO) == 1 && flag == 0){
    flag = 1;
    digitalWrite(RELE, HIGH);
    Serial.println("Vazio");      
  }
  if(digitalRead(NIVEL_ALTO) == 0 && flag == 1){
    flag = 0;
    digitalWrite(RELE, LOW);
    Serial.println("Cheio");      
  }   
  Serial.println(flag);
  Serial.println(digitalRead(NIVEL_BAIXO));
}  
