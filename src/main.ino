#define LED_PIN 13

#define PIN_ESC  2

#define KEY_RESET       0x00
#define KEY_ESC         0x29

uint8_t keyData[8] = { 0, 0, 0, 0, 0, 0, 0 };

void handler(int pin, uint8_t keycode) {
    if (digitalRead(pin) == 1) {
        digitalWrite(LED_PIN, HIGH);

        keyData[2] = keycode;
        Serial.write(keyData, 8);   // send keypress
        keyData[2] = KEY_RESET;
        Serial.write(keyData, 8);   // release key

        while( digitalRead(pin) == 1) {
            delay(100);
        }
        digitalWrite(LED_PIN, LOW);
    }
}

void setup() {
    pinMode(LED_PIN, OUTPUT);
    pinMode(PIN_ESC,  INPUT);
    Serial.begin(9600);
    delay(2000);
}

void loop() {
    handler(PIN_ESC,  KEY_ESC);
}

