#include "LedControl.h"
#include "string.h"
#include "LetterHandler.h"

#define NUMBER_OF_DISPLAY 4
#define NUMBER_OF_COLUMN 8
#define NUMBER_OF_ROW 8

#define DELAY_TIME 100

// SPI PIN
#define DIN 11
#define SCLK 13
#define SS 10

// Buffer for display 4x8x8, here we define it row wise
byte buffer[NUMBER_OF_DISPLAY][NUMBER_OF_ROW] = {{}};

// Function to shift buffer vertical
void shiftBufferColumn(){
  for(int j = 3; j>=0; j--){
    for(int k = 0; k<7; k++){
        buffer[j][k] = buffer[j][k+1];
    }
    if(j-1>=0){
      buffer[j][7] = buffer[j-1][0];
    }else{
      buffer[j][7] = 0b00000000;  
    }
  }
}

// Function to shift buffer horizontal
void shiftBuffer(int n, int letter, char* text){
  for(int j = 3; j>0; j--){
    for(int k = 0; k<8; k++){
      if(j>0){
        buffer[j][k] = buffer[j][k]<<1 | buffer[j-1][k]>>7;
      } 
    }
  }
  for(int k = 0; k<8; k++){
    byte mask = IMAGES[LetterHandler::getAlphabetIndex(text[letter])][k]<<n;
    buffer[0][k] = buffer[0][k] <<1 | mask>>7;
  }

}

// MAX72XX LED Control
LedControl lc = LedControl(
    DIN,
    SCLK,
    SS,
    NUMBER_OF_DISPLAY);


// shows index for letter parts, a letter is sliced into 8 parts
int part = 0;

// shows index for letter in the text
int letter_idx = 0;

// text that is shown, harcoded for now and only support capital letter
char text[] = "JEZZ ";

void setup() {
  
  for (int display = 0; display < NUMBER_OF_DISPLAY; display++){
    /*
    The MAX72XX is in power-saving mode on startup,
    we have to do a wakeup call
    */
    lc.shutdown(display, false);

    /* Set the brightness to a medium values */
    lc.setIntensity(display,4);

    /* and clear the display */
    lc.clearDisplay(display);

  }
}



void loop() {
  
  // Display the buffer
  for(int row = 0; row<NUMBER_OF_ROW; row++){
    for(int display = 0; display<NUMBER_OF_DISPLAY; display++){
      lc.setRow(display,row,buffer[display][row]);
    }
  }

  // Shift buffer to the left
  shiftBuffer(part, letter_idx, text);
  part = part+1;
  if (part == LETTER_SLICES){
    part = 0;
    letter_idx = letter_idx + 1;
    if(letter_idx == strlen(text)) letter_idx = 0;  
  }
  
  delay(DELAY_TIME);
  
}
