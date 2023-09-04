/*
  Instituto Federal de Sergipe                                                
  Bacharelado em Engenheria Eletrica                              
                                                                      
  Aluno: Leonardo Aprígio Nascimento Fontes                                      
                                                                      
  Orientadora: Profª. Dra. Stephanie Kamarry Alves de Sousa           
  Coorientador: Prof. Me. Fabio Luiz Sa Prudente                      
                                                                      
*/

/*-Defincao de pinos utilizados-*/

#define enA   9
#define enB   3
#define in1   8
#define in2   7
#define in3   4
#define in4   5

void setup()
{
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
  Serial.begin(9600); 
}

void loop()
{
  int velocidademotor = 0;
  
  int joydirecaoY = analogRead(A0);
  int joydirecaoX = analogRead(A1);

  if (joydirecaoY > 540)
  {
    velocidademotor = map(joydirecaoY, 540, 1023, 0, 255);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
  }
  else if (joydirecaoY < 460)
  {
    velocidademotor = map(joydirecaoY, 460, 0, 0, 255);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  }
  else if (joydirecaoX > 540)
  {
    velocidademotor = map(joydirecaoX, 540, 1023, 0, 255);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  }
  else if (joydirecaoX < 460)
  {
    velocidademotor = map(joydirecaoX, 460, 0, 0, 255);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
  }
  else
  {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
  }

  int pwm = map(abs(velocidademotor), 0, 255, 0, 255); 
  analogWrite(enA, pwm);
  analogWrite(enB, pwm);

  Serial.print("Joystick Y: ");
  Serial.print(joydirecaoY);
  Serial.print("\tJoystick X: ");
  Serial.print(joydirecaoX);
  Serial.print("\tVelocidade dos motores: ");
  Serial.println(velocidademotor);
}
