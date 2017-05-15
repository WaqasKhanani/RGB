#include <Adafruit_NeoPixel.h>

#include <Adafruit_NeoPixel.h>
#include <NewPing.h>
#define MAX_DISTANCE 200 
#define MAX_DISTANCE_OBJECT 50
#define TRIGGER_PIN 9
#define ECHO_PIN 10
#define PIN 8
Adafruit_NeoPixel strip = Adafruit_NeoPixel(1, PIN, NEO_GRB + NEO_KHZ800);
NewPing sonar(TRIGGER_PIN,ECHO_PIN,MAX_DISTANCE);
void setup() 
{
  Serial.begin(9200);
  strip.begin();
  strip.show();
}
void loop() 
{
unsigned int PING = sonar.ping_cm();
Serial.println ("DISTANCE : " + String(PING) + "cm");
if ( PING <  MAX_DISTANCE_OBJECT )
{
  strip.setPixelColor(0,255,0,0);
  strip.show();
  delay(50);
}
else
{
  strip.setPixelColor(0,0,0,255);
  strip.show();
  delay(50);
}
}

