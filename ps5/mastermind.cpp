#include "mastermind.h"
#include "lcd_wrapper.h"
#include <Arduino.h>


int scan_tlacidla(int pin)
{
  int stav_tlacidla;
 if(!(stav_tlacidla=digitalRead(pin))) 
 {
 delay(20);
 if(!(stav_tlacidla=digitalRead(pin))) 
 while(!(stav_tlacidla=digitalRead(pin))) {} 
 delay(20);
 return (1); 
 }
 return(0); 
}

char* generate_code(bool repeat, int length){
  if(repeat == false && length > 10){
    return NULL;
  }
  if(length < 1){
    return NULL;
  }
 
  char* result = (char*)calloc(length+1,sizeof(char));
  if(repeat == true){
    for(size_t i=0;i<length;i++){
      result[i] = random(48,57);
    }
  }
  if(repeat == false){

   char pole[] = {'0','1','2','3','4','5','6','7','8','9'};

  result[0] = rand()%9+48;
  for(int i = 0;i<10;i++){
  if(pole[i] == result[0]){
    pole[i] = ' ';
    break;
  }
}
int position = rand()%9;
for(int i = 1;i<4;i++){
  result[i] = pole[position];

while(result[i] == ' '){
  position = rand()%9;
  result[i] = pole[position];
  
}
pole[position] = ' ';
  
    
}
    
  }
  return result;
}

void get_score(const char* secret, const char* guess, int* peg_a, int* peg_b){
  int a=0,b=0;
  char pole[5];
  for(int i=0;i<4;i++){
    pole[i]=secret[i];
  }
  pole[4]='\0';
  for(int i=0; i<strlen((char*)guess);i++){
    for(int y=0; y<strlen(pole);y++){
      if(guess[i] == pole[y] && i == y && pole[y] != ' '){
        a++;
        pole[y] = ' ';
      }
      if(guess[i] == pole[y] && i != y && pole[y] != ' '){
        b++;
        pole[y] = ' ';
      }
    }
  }
 *peg_a=a;
 *peg_b=b;
}

void turn_off_leds(){
  digitalWrite(LED_BLUE_1, HIGH);
  digitalWrite(LED_BLUE_2, HIGH);
  digitalWrite(LED_BLUE_3, HIGH);
  digitalWrite(LED_BLUE_4, HIGH);
  digitalWrite(LED_RED_1, HIGH);
  digitalWrite(LED_RED_2, HIGH);
  digitalWrite(LED_RED_3, HIGH);
  digitalWrite(LED_RED_4, HIGH);
}

void render_leds(const int peg_a, const int peg_b){
  int pole[8];
  int i=0,y=0;
  for(i=0; i<8; i++){
    pole[i] = 1;
  }
  for(i=0,y=1; i<peg_a;i++){
    pole[y] = 0;
    y=y+2;
  }
  for(i=0,y=y-1; i<peg_b;i++){
    pole[y] = 0;
    y=y+2;
  }
  
  
  for(i =0, y = 6;i<8;i++,y++){
    digitalWrite(y,pole[i]);
  }
}


void win(){
   lcd_clear();
    for(int i =0; i<10;i++){
     lcd_set_cursor(4,0);
  lcd_print("YOU WIN!");
  digitalWrite(LED_BLUE_1, HIGH);
  digitalWrite(LED_BLUE_2, HIGH);
  digitalWrite(LED_BLUE_3, HIGH);
  digitalWrite(LED_BLUE_4, HIGH);
  digitalWrite(LED_RED_1, LOW);
  digitalWrite(LED_RED_2, LOW);
  digitalWrite(LED_RED_3, LOW);
  digitalWrite(LED_RED_4, LOW);
  delay(500);
 
  digitalWrite(LED_BLUE_1, LOW);
  digitalWrite(LED_BLUE_2, LOW);
  digitalWrite(LED_BLUE_3, LOW);
  digitalWrite(LED_BLUE_4, LOW);
  digitalWrite(LED_RED_1, LOW);
  digitalWrite(LED_RED_2, LOW);
  digitalWrite(LED_RED_3, LOW);
  digitalWrite(LED_RED_4, LOW);
  delay(500);
 lcd_clear();
  digitalWrite(LED_BLUE_1, LOW);
  digitalWrite(LED_BLUE_2, LOW);
  digitalWrite(LED_BLUE_3, LOW);
  digitalWrite(LED_BLUE_4, LOW);
  digitalWrite(LED_RED_1, HIGH);
  digitalWrite(LED_RED_2, HIGH);
  digitalWrite(LED_RED_3, HIGH);
  digitalWrite(LED_RED_4, HIGH);
  delay(500);
   
    }
}

void play_game(char* secret){
lcd_clear();
lcd_set_cursor(0,0);
lcd_print("MASTERMIND GAME!");
delay(2000);
lcd_clear();
lcd_set_cursor(0,0);  
lcd_print("Try to guess my");
lcd_set_cursor(0,1);
lcd_print("secret number");
delay(2000);
lcd_clear();
lcd_set_cursor(0,0);
lcd_print("Try it!");
  int peg_a,peg_b;
    size_t a=48;
    size_t b=48;
    size_t c=48;
    size_t d=48;
    int his = 0;
    
    char **history = (char **)calloc(10,sizeof(char*));
    for(int pocitadlo = 0; pocitadlo < 10 ; pocitadlo++){
    history[pocitadlo] = (char*)calloc(5,sizeof(char));
      his = pocitadlo;
      a = 48;
      b = 48;
      c = 48;
      d = 48;
      
  while(scan_tlacidla(14) != 1){
 
  if(digitalRead(BTN_1_PIN) == 0){
    a++;
    if(a > 57){
      a = 48;
    }
    while(digitalRead(BTN_1_PIN) == 0) {

      if(digitalRead(BTN_2_PIN) == 0 && pocitadlo != 0){
        his--;
        if(his <= 0){
          his = 1;
        }

        render_history(secret,history,his);
        while(digitalRead(BTN_2_PIN) == 0){}
        delay(300);
      }

       if(digitalRead(BTN_3_PIN) == 0){
        his++;
        if(his >= pocitadlo){
          his = pocitadlo;
        }
        render_history(secret,history,his);
        while(digitalRead(BTN_3_PIN) == 0){}
        delay(300);
      }
      
      }
    delay(300);
  }
  if(digitalRead(BTN_2_PIN) == 0){
    b++;
    if(b > 57){
      b = 48;
    }
     while(digitalRead(BTN_2_PIN) == 0) {}
     delay(300);
  }
  if(digitalRead(BTN_3_PIN) == 0){
    c++;
    if(c > 57){
      c = 48;
    }
     while(digitalRead(BTN_3_PIN) == 0) {}
     delay(300);
  }
  if(digitalRead(BTN_4_PIN) == 0 ){
    d++;
    if(d > 57){
      d = 48;
    }
     while(digitalRead(BTN_4_PIN) == 0) {}
     delay(300);
  }
  
 
  lcd_set_cursor(0,1);
  lcd_print("Your guess:");
  
    history[pocitadlo][0] = a;
    history[pocitadlo][1] = b;
    history[pocitadlo][2] = c;
    history[pocitadlo][3] = d;
    history[pocitadlo][4] = '\0';
  
  lcd_set_cursor(12,1);
  lcd_print(history[pocitadlo]); 
  }
 
 render_history(secret,history,pocitadlo+1);

 get_score(secret, history[pocitadlo],&peg_a, &peg_b);
 if(peg_a == 4){
  win();
  break;
 }
  
    history[pocitadlo][0] = a;
    history[pocitadlo][1] = b;
    history[pocitadlo][2] = c;
    history[pocitadlo][3] = d;
    history[pocitadlo][4] = '\0';
 Serial.println(history[pocitadlo]);
}
delay(3000);
  if(peg_a != 4){
  lcd_clear();
  turn_off_leds();
    lcd_print("Sorry. You Lose!");
    lcd_set_cursor(0,1);
    lcd_print("It was ");
    lcd_print(secret);
    digitalWrite(LED_RED_1, LOW);
    digitalWrite(LED_RED_2, LOW);
    digitalWrite(LED_RED_3, LOW);
    digitalWrite(LED_RED_4, LOW);
    delay(5000);
  }

  lcd_clear();
delay(3000);

free(history);
 

}

void render_history(char* secret, char** history, const int entry_nr){
 int peg_a,peg_b;
 char polo[5];
 char znak[3];
 znak[0] = entry_nr + 48;
 znak[1] = '\0';
 if(entry_nr > 9){
    znak[0]='1';
    znak[1]='0';
   }
   znak[2] = '\0';
 
 lcd_set_cursor(0,0);
  lcd_print("       ");
  lcd_set_cursor(0,0);
  lcd_print(znak);
  get_score(secret,history[entry_nr-1],&peg_a,&peg_b);
  Serial.println(history[entry_nr-1]);
   polo[0] = 'A';
   polo[2] = 'B';
   polo[1] = peg_a + 48;
   polo[3] = peg_b + 48;
   polo[4] = '\0';
   lcd_set_cursor(12,0);
   lcd_print(polo);
   lcd_set_cursor(3,0);
   lcd_print(history[entry_nr-1]);
   render_leds(peg_a,peg_b);
}

