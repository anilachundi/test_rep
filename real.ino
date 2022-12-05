/* Get tilt angles on X and Y, and rotation angle on Z
 * Angles are given in degrees, displays on SSD1306 OLED
 * 
 * License: MIT
 */
#include <Wire.h>

#include <MPU6050_light.h>

// #define SCREEN_WIDTH 128 // OLED display width, in pixels
// #define SCREEN_HEIGHT 64 // OLED display height, in pixels
// // Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
// Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire);


MPU6050 mpu(Wire);
unsigned long timer = 0;

void setup() {
  Serial.begin(6000);                           // Ensure serial monitor set to this value also    
  // if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))  // Address 0x3C for most of these displays, if doesn't work try 0x3D 
  // { 
  //   Serial.println(F("SSD1306 allocation failed"));
  //   for(;;);                                      // Don't proceed, loop forever
  // }
  
  // display.setTextSize(1);             
  // display.setTextColor(SSD1306_WHITE);            // Draw white text
  // display.clearDisplay();                         
  Wire.begin();
  mpu.begin();
  Serial.println(F("Calculating gyro offset, do not move MPU6050"));
  // display.display();        
  mpu.calcGyroOffsets();                          // This does the calibration
  // display.setTextSize(2);          
}

void loop() {
  mpu.update();  
  if((millis()-timer)>10)                         // print data every 10ms
  {                                           
    // display.clearDisplay();                       // clear screen
    // display.setCursor(0,0);                         
    Serial.print("P : ");
    Serial.println(mpu.getAngleX());
    Serial.print("R : ");
    Serial.println(mpu.getAngleY());
    Serial.print("Y : ");
    Serial.print(mpu.getAngleZ());
    // display.display();                            // display data
    timer = millis();  
  }
}
