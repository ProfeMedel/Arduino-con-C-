//29 de julio 2024
//Medidor de distancia con sensor Ultrasonico usando 2 LED

int Verde = 2;
int Rojo = 3;
int Pin_trigger = 13;
int Pin_echo = 12;
long alm_dist = 0;//alm_dist variable para almacenar distancia

//inicio de función para medir distancia
  long readUltrasonicDistance(int Pin_trigger, int Pin_echo)
{
  pinMode(Pin_trigger, OUTPUT);
  digitalWrite(Pin_trigger, LOW);
  //delayMicroseconds(2);
  digitalWrite(Pin_trigger, HIGH);
  //delayMicroseconds(10);
  digitalWrite(Pin_trigger, LOW);
  pinMode(Pin_echo, INPUT);
  return (pulseIn(Pin_echo, HIGH)*0.01723);//Mide la duración del pulso en el pin de eco y calcula la distancia en centímetros usando el factor de conversión
}
//Fin de función para medir distancia

void setup()
{

  pinMode(Verde, OUTPUT);
  pinMode(Rojo, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  alm_dist =readUltrasonicDistance(13, 12);

  Serial.print(alm_dist);
  Serial.println("cm");
 
  if (alm_dist > 300) {
    digitalWrite(Verde, LOW);
    digitalWrite(Rojo, LOW);
  }
  
  if (alm_dist <= 300 && alm_dist > 260) {
    digitalWrite(Verde, HIGH);
    digitalWrite(Rojo, LOW);
  }
    
 if (alm_dist <= 180 && alm_dist > 50) {
    digitalWrite(Verde, HIGH);
    digitalWrite(Rojo, HIGH);
  }
  
   if (alm_dist <= 50 && alm_dist > 3) {
    digitalWrite(Verde, HIGH);
    digitalWrite(Rojo, HIGH);
    delay(300);
    digitalWrite(Verde, LOW);
    digitalWrite(Rojo, LOW);
    delay(300);
    digitalWrite(Verde, HIGH);
    digitalWrite(Rojo, HIGH);
    delay(300);
    digitalWrite(Verde, LOW);
    digitalWrite(Rojo, LOW);
    delay(300);
  }

  delay(100);
}