
int dirPin1 = 3;
int stepperPin1 = 2;
void setup() {
  pinMode(dirPin1, OUTPUT);
  pinMode(stepperPin1, OUTPUT);
}

void step(boolean dir,int steps){
  digitalWrite(dirPin1,dir);
  delay(50);
  for(int i=0;i<steps;i++){
    digitalWrite(stepperPin1, HIGH);
    delayMicroseconds(100);
    digitalWrite(stepperPin1, LOW);
    delayMicroseconds(100);
    delay(1);
  }
}

void loop(){
  step(true,200*5);
  delay(500);
  step(false,200*5);
  delay(500);
}
