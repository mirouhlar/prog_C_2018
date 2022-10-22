#include "mastermind.h"
#include "lcd_wrapper.h"

void setup(){
  lcd_init();
  
  pinMode(LED_BLUE_1, OUTPUT);
  pinMode(LED_BLUE_2, OUTPUT);
  pinMode(LED_BLUE_3, OUTPUT);
  pinMode(LED_BLUE_4, OUTPUT);
  pinMode(LED_RED_1, OUTPUT);
  pinMode(LED_RED_2, OUTPUT);
  pinMode(LED_RED_3, OUTPUT);
  pinMode(LED_RED_4, OUTPUT);
  pinMode(BTN_ENTER_PIN, INPUT_PULLUP);  
  pinMode(BTN_1_PIN, INPUT_PULLUP); 
  pinMode(BTN_2_PIN, INPUT_PULLUP); 
  pinMode(BTN_3_PIN, INPUT_PULLUP); 
  pinMode(BTN_4_PIN, INPUT_PULLUP); 
  Serial.begin(9600);
}


void loop(){
  
    turn_off_leds();
    char* code = generate_code(false, 4);
    Serial.println(code);
    play_game(code);
    free(code);
 

    
}
