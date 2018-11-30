// Arduino Light sensor code created by AR Builder.
int IN1=7; // rotate backward, left wheel
int IN2=6; // rotate forward, left wheel
int IN3=5; // rotate backward, right wheel
int IN4=4;// rotate forward, right wheel
int ENA=11; // motor speed for left wheel
int ENB=3; // motor speed for right wheel

void setup() {
  Serial.begin(9600); // Start Serial.
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
}

void still() {
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  analogWrite(ENA,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
  analogWrite(ENB,LOW);
 }

void forward() {
  //both wheels going forward*****************************
  //Left wheel, IN2 = forward
  analogWrite(ENA, 200);// motor speed
  digitalWrite(IN1,LOW);// rotate forward
  digitalWrite(IN2,HIGH);
    
  //Right wheel, IN4 = forward
  analogWrite(ENB, 200);// motor speed
  digitalWrite(IN4,LOW);// rotate forward
  digitalWrite(IN3,HIGH);
}

void left() {
  //Right wheel, IN4 = forward
  analogWrite(ENB, 200);// motor speed
  digitalWrite(IN4,LOW);// rotate forward
  digitalWrite(IN3,HIGH);
}

void right() {
  //Left wheel, IN2 = forward
  analogWrite(ENA, 200);// motor speed
  digitalWrite(IN1,LOW);// rotate forward
  digitalWrite(IN2,HIGH);
}

void backward() {
  //both wheels going backward*****************************
  //Left wheel, IN1 = backward
  Serial.print("ROTATE BACKWARD");

  analogWrite(ENA, 200);// motor speed
  digitalWrite(IN2,LOW);// rotate forward
  digitalWrite(IN1,HIGH);

  //Right wheel, IN3 = backward
  analogWrite(ENB, 200);// motor speed
  digitalWrite(IN3,LOW);// rotate forward
  digitalWrite(IN4,HIGH);
}
 
void loop() {
  // sensors
  int A = analogRead(A0);
  int B = analogRead(A1);
  int C = analogRead(A2);
  int D = analogRead(A3);

 Serial.println(A);// Display serial results in serial monitor.
 
  if (A >= 400 && B<400) {   // Change 100 to the number depending on the light in your area. // if sensor is on 
     digitalWrite(13, HIGH);
     forward(); 
  }

  if (B >= 400 && A<400) {
     digitalWrite(12, HIGH);
     backward(); 
  }

  if (C >= 400 && A<400 && B<400) {
     digitalWrite(10, HIGH);
     left(); 
  }

  if (D >= 400 && A<400 && B<400 && C<400) {
     digitalWrite(9, HIGH);
     right(); 
  }

  if(A <400 && B<400 && C<400 && D<400) {
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
    still();
  }
}
