#include <Adafruit_Fingerprint.h>

HardwareSerial mySerial(2);
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

// 👉 Map ID to names
String getName(int id) {
  switch(id) {
    case 1: return "Rithika";
    case 2: return "Friend";
    case 3: return "Guest";
    default: return "Unknown";
  }
}

int nextID = 1;

void setup() {
  Serial.begin(115200);
  delay(1000);

  mySerial.begin(57600, SERIAL_8N1, 16, 17);

  Serial.println("Smart Fingerprint System");

  finger.begin(57600);

  if (finger.verifyPassword()) {
    Serial.println("Sensor ready ✅");
  } else {
    Serial.println("Sensor not found ❌");
    while (1);
  }

  finger.getTemplateCount();
  nextID = finger.templateCount + 1;

  Serial.print("Stored fingerprints: ");
  Serial.println(finger.templateCount);
}

void loop() {
  Serial.println("\nPlace finger...");

  if (finger.getImage() != FINGERPRINT_OK) return;

  if (finger.image2Tz() != FINGERPRINT_OK) return;

  // 🔍 Check if already stored
  if (finger.fingerFastSearch() == FINGERPRINT_OK) {
    int id = finger.fingerID;
    Serial.print("Welcome 👋 ");
    Serial.print(getName(id));
    Serial.print(" (ID: ");
    Serial.print(id);
    Serial.println(")");
    delay(2000);
    return;
  }

  // ❌ New fingerprint → enroll
  Serial.println("New Fingerprint! Enrolling...");

  enrollFinger(nextID);

  Serial.print("Stored as ID: ");
  Serial.println(nextID);

  nextID++;
}

// 🧾 Enroll Function
void enrollFinger(int id) {

  Serial.println("Remove finger...");
  delay(2000);
  while (finger.getImage() != FINGERPRINT_NOFINGER);

  Serial.println("Place same finger again...");
  while (finger.getImage() != FINGERPRINT_OK);

  if (finger.image2Tz(2) != FINGERPRINT_OK) {
    Serial.println("Error converting");
    return;
  }

  if (finger.createModel() != FINGERPRINT_OK) {
    Serial.println("Finger mismatch ❌");
    return;
  }

  if (finger.storeModel(id) == FINGERPRINT_OK) {
    Serial.println("Stored successfully 🎉");
  } else {
    Serial.println("Store failed ❌");
  }
}