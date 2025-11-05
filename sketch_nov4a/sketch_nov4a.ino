#include <Adafruit_CircuitPlayground.h>
//define variables
float accelZ;//changing z axis acceleration from up to down
int lightLevel;//light sensor
int brightness;//brightness of LED
int toneFreq;//the frequency of sound value

void setup() {
  // put your setup code here, to run once:
  CircuitPlayground.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  accelZ = CircuitPlayground.motionZ();//read motion from accelerometer
  lightLevel = CircuitPlayground.lightSensor();// read light level

  toneFreq = map(accelZ * 100,-100,100,200,1000);//map to sound pitch
  brightness = map(abs(accelZ * 100), 0, 100, 10, 255);//map to led brightness

  uint8_t r,g,b;
  if (lightLevel<200){//light color based on the sensor
    r=255;g=0;b=0;
  }else{
    r=0;g=0;b=255;
  }
  CircuitPlayground.setBrightness(brightness);
  for (int i=0; i<10; i++){
    CircuitPlayground.setPixelColor(i,r,g,b);
  }
    CircuitPlayground.playTone(toneFreq,50);
}

