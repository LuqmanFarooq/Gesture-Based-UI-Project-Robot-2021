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

  delay(1000);
}
