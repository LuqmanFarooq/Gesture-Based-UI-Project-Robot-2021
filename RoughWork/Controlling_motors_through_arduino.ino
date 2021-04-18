void setup() {
  // put your setup code here, to run once:
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // for clockwise
  digitalWrite(10,LOW);
  digitalWrite(11,HIGH);
  delay(3000);
  // for anticlockwise
  digitalWrite(10,HIGH);
  digitalWrite(11,LOW);
  delay(3000);
}
