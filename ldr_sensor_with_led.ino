int sensor=A0;
int led=7;
void setup() {

  Serial.begin(9600);
  pinMode(sensor,INPUT);
  pinMode(led,OUTPUT);

}

void loop() {
  int data=analogRead(sensor);
  Serial.print("sensor_value : ");
  Serial.println(data);
  if(data > 1010)
  {
    digitalWrite(led,1);
  }
  else
  {
    digitalWrite(led, 0);
  }

}
