String StateCommand="";
String a="";
void setup() {
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, INPUT_PULLUP);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  Serial.println("Command line:");
}

void loop() {

 if(Serial.available()>0)
 {
  StateCommand= Serial.readStringUntil('\n');
  if(StateCommand == "active")
  {
    Serial.println("System activeted");
 do
  {
    String a= Serial.readStringUntil('\n');
  if(digitalRead(10)==LOW)
  {
    digitalWrite(9, HIGH);
    digitalWrite(8, LOW);
    Serial.println("All correct");
    while(digitalRead(10)==LOW){delay(500);}
  }
  else
  {
    digitalWrite(9, LOW);
    digitalWrite(8, HIGH);
    Serial.println("Alarm!");
     while(digitalRead(10)==HIGH){delay(500);}
  }
  }while(true);

  }
  else
  {
    Serial.println("ERROR");
    digitalWrite(9, HIGH);
    digitalWrite(8, HIGH);
    delay(1000);
    digitalWrite(9, LOW);
    digitalWrite(8, LOW);
     delay(1000);
    digitalWrite(9, HIGH);
    digitalWrite(8, HIGH);
    delay(1000);
    digitalWrite(9, LOW);
    digitalWrite(8, LOW);
     delay(1000);
    digitalWrite(9, HIGH);
    digitalWrite(8, HIGH);
    delay(1000);
    digitalWrite(9, LOW);
    digitalWrite(8, LOW);
    Serial.println("The system has been reset");
  }
 }
 else
 {
  while(Serial.available()>0)
  {
  digitalWrite(9, LOW);
  digitalWrite(8, LOW);
  }
 }
}
