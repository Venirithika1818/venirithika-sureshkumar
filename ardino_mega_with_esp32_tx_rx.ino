#define RX 16
#define TX 17
void setup() {
  Serial.begin(9600);
  Serial2.begin(9600, SERIAL_8N1, 16, 17);
}
void loop(){
    if (Serial2.available()) {
    String data = Serial2.readStringUntil('\n'); 
    Serial.print("Received: ");
    Serial.println(data);  
}
}
