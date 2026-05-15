//TESTE DE USO DE HEADER

unsigned long previousMillis = 0;  // will store last time LED was updated
int blinkIndex;
bool blinkEnable;
//int fadeIndex = 0;
//bool fadeDirection = false; //0 UP 1 DOWN
//int brightness = 0;
////////////////////////

//////////////////////////
// define directions for LED fade
#define UP 0
#define DOWN 1
// constants for min and max PWM
const int minPWM = 0;
const int maxPWM = 255;
// State Variable for Fade Direction
byte fadeDirection = UP;
// Global Fade Value
// but be bigger than byte and signed, for rollover
int fadeValue = 0;
// How smooth to fade?
byte fadeIncrement = 5;
// millis() timing Variable, just for fading
unsigned long previousFadeMillis;
// How fast to increment?
int fadeInterval = 5;
//Conta 3 vezes que fadeDirection muda para UP
int fadeIndex = 0;
//////////////////////////

void doTheFade(unsigned long thisMillis) {
   //fadeIndex between 3 and 1 to 3 fades
   if (fadeIndex >= 1 && fadeIndex <= 3){
      // is it time to update yet?
      // if not, nothing happens
      if (thisMillis - previousFadeMillis >= fadeInterval) {
         // yup, it's time!
         if (fadeDirection == UP) {
            fadeValue = fadeValue + fadeIncrement;
            if (fadeValue >= maxPWM) {
               // At max, limit and change direction
               fadeValue = maxPWM;
               fadeDirection = DOWN;
            }
         } else {
            //if we aren't going up, we're going down
            fadeValue = fadeValue - fadeIncrement;
            if (fadeValue <= minPWM) {
               // At min, limit and change direction
               fadeValue = minPWM;
               fadeDirection = UP;
               fadeIndex = fadeIndex - 1;
            }
         }
         // Only need to update when it changes
         analogWrite(LED_BUILTIN, fadeValue);
         

         // reset millis for the next iteration (fade timer only)
         previousFadeMillis = thisMillis;
      }
   }  
}

void piscaAlerta() {
   pinMode(LED_BUILTIN, OUTPUT);
   if (millis() - previousMillis >= 500 && blinkEnable){
      
        // save the last time you blinked the LED
        previousMillis = millis();
        digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN)); 
   }
    /////////////////////////
}

void piscaSeta() {
   pinMode(LED_BUILTIN, OUTPUT);
   if (blinkIndex >= 1 && blinkIndex <=6) {
        if (millis() - previousMillis >= 500){
            // save the last time you blinked the LED
            previousMillis = millis(); 
            digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
            blinkIndex--;
        }
   }
}