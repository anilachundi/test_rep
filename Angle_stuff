#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <MPU6050_light.h>
// #include <iostream>
#include <vector>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire);


MPU6050 mpu(Wire);
unsigned long timer = 0;
int num_sectors = 12;

const int LED_PINS[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, A0, A1};
const int NUM_LEDS = sizeof(LED_PINS) / sizeof(LED_PINS[0]);

void setup() {
  Serial.begin(9600);                           // Ensure serial monitor set to this value also    
  Wire.begin()
  mpu.initializer();
  for (int i = 0; i < NUM_LEDS; i++) {
    pinMode(LED_PINS[i], OUTPUT);
  }        
}

void loop() {
  int16_t ax, ay, az;
  int16_t gx, gy, gz;

  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  // Convert roll and pitch to radians
  float roll_rad = atan2(ay, az);
  float pitch_rad = atan2(-ax, sqrt(ay * ay + az * az));

  // Calculate the angle of the vector and convert to degrees
  float angle = (180 / M_PI) * atan2(pitch_rad, roll_rad);

  // Shift the range from -180 to 180 to 0 to 360 degrees
  angle = (angle + 180) % 360;

  // Divide the angle by the number of sectors to determine which sector to light up
  int sector = angle / (360.0 / num_sectors);
  int pin = int(angle/ (360 / NUM_LEDS));
  std::vector<int> pins = pin_list(pin);
  for (pin : pins) {
    digitalWrite(pin, HIGH); // on
    delay(1000); // wait 1 second
    digitalWrite(pin, LOW); //off
    delay(1000); // wait one second

  }

//  int ledIndex = int((roll + 180.0) / 360.0 * NUM_LEDS);
//  for (int i = 0; i < NUM_LEDS; i++) {
//    digitalWrite(LED_PINS[i], i == ledIndex);
//  }

}

std::vector<int> pin_list(int n) {
  std::vector<int> res;
  for (int i = n - 4; i < n + 4; i++) {
    res.push_back(i)
  }
  return res;
}
