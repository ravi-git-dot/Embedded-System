// int a = 1;
// char ass = "a";
// string name = "RaviRaj";
// float number = 2.5;
// double count = 3.456788;

int led = 7;

void setup() {
  pinMode(led,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(led, HIGH);
  Serial.println("LED ON");
  delay(1000);

  digitalWrite(led, LOW);
  Serial.println("LED OFF");
  delay(1000);
}
