void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);   // Initialize the serial communication with baud rate of 9600
  pinMode(10, OUTPUT);  // set pin 10 as output pin
  pinMode(11, OUTPUT);  // set pin 11 as output pin
  pinMode(12, OUTPUT);  // set pin 12 as output pin
  pinMode(13, OUTPUT);  // set pin 13 as output pin
}

void loop() {
  // put your main code here, to run repeatedly:
  int xaxis =  analogRead(A1);  //Read and Store the analog value of pin A1, connected to x-out of ADXL sensor
  int yaxis =  analogRead(A2);  //Read and Store the analog value of pin A2, connected to x-out of ADXL sensor

  Serial.println("Value of X-axis " + String(xaxis)); // print value of xaxis on serial monitor
  Serial.println("Value of y-axis " + String(yaxis)); // print value of yaxis on serial monitor

  delay(100);
  
  // comparing if xaxis is less than 300 -ADXL sensor is tilted forward
  if (xaxis < 300) {
    digitalWrite(10,HIGH);  // Move Forward
    digitalWrite(11,LOW);
    digitalWrite(12,HIGH);
    digitalWrite(13,LOW);
    Serial.println("Robot is moving Forward");   
  }

  // comparing if xaxis is greater than 300 -ADXL sensor is tilted backward
  if (xaxis > 350) {
    digitalWrite(10,LOW);  // Move Backward
    digitalWrite(11,HIGH);
    digitalWrite(12,LOW);
    digitalWrite(13,HIGH);
    Serial.println("Robot is moving Backward");   
  }

  // comparing if yaxis is less than 300 -ADXL sensor is tilted left
  if (yaxis < 300) {
    // right wheel should move forward
    digitalWrite(10,HIGH);  // Move left
    digitalWrite(11,LOW);
    // left wheel should move backward
    digitalWrite(12,LOW);
    digitalWrite(13,HIGH);
    Serial.println("Robot is moving LEFT");   
  }

  // comparing if yaxis is greater than 300 -ADXL sensor is tilted Right
  if (yaxis > 350) {
    digitalWrite(10,LOW);  // Move Right
    digitalWrite(11,HIGH);
    digitalWrite(12,HIGH);
    digitalWrite(13,LOW);
    Serial.println("Robot is moving Right");   
  }

  // values form ADXL Sensor when sensor is flat
  if ((xaxis > 300 ) && (xaxis < 350) && (yaxis > 300 ) && (yaxis < 350))
  {
    digitalWrite(10,LOW);  
    digitalWrite(11,LOW);
    digitalWrite(12,LOW);
    digitalWrite(13,LOW);
    Serial.println("Robot is Stopped");   
  }
}
