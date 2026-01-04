int relay1 = 22;

void setup() 
{
  Serial.begin(9600);
  pinMode(relay1, OUTPUT);
  digitalWrite(relay1, 1);
}

void loop() 
{
  if(Serial.available())
  {
    char data = Serial.read();
    Serial.print(data);
    if(data == 'a')
    {
     digitalWrite(relay1, 1);
    }
    else if(data == 'b');
    {
     digitalWrite(relay1, 0);
    }
  }
}


