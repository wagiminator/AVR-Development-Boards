void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}


void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.println("Hello world!");
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);
}
