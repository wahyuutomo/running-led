#ifndef LetterHandler_h
#define LetterHandler_h

#include <Arduino.h>

const byte IMAGES[][8] = 
{
	{
	  0b00000000,
	  0b00111100,
	  0b01100110,
	  0b01100110,
	  0b01111110,
	  0b01100110,
	  0b01100110,
	  0b01100110
	},{
	  0b00000000,
	  0b01111100,
	  0b01100110,
	  0b01100110,
	  0b01111100,
	  0b01100110,
	  0b01100110,
	  0b01111100
	},{
	  0b00000000,
	  0b00111100,
	  0b01100110,
	  0b01100000,
	  0b01100000,
	  0b01100000,
	  0b01100110,
	  0b00111100
	},{
	  0b00000000,
	  0b01111100,
	  0b01100110,
	  0b01100110,
	  0b01100110,
	  0b01100110,
	  0b01100110,
	  0b01111100
	},{
	  0b00000000,
	  0b01111110,
	  0b01100000,
	  0b01100000,
	  0b01111100,
	  0b01100000,
	  0b01100000,
	  0b01111110
	},{
	  0b00000000,
	  0b01111110,
	  0b01100000,
	  0b01100000,
	  0b01111100,
	  0b01100000,
	  0b01100000,
	  0b01100000
	},{
	  0b00000000,
	  0b00111100,
	  0b01100110,
	  0b01100000,
	  0b01100000,
	  0b01101110,
	  0b01100110,
	  0b00111100
	},{
	  0b00000000,
	  0b01100110,
	  0b01100110,
	  0b01100110,
	  0b01111110,
	  0b01100110,
	  0b01100110,
	  0b01100110
	},{
	  0b00000000,
	  0b00111100,
	  0b00011000,
	  0b00011000,
	  0b00011000,
	  0b00011000,
	  0b00011000,
	  0b00111100
	},{
	  0b00000000,
	  0b00011110,
	  0b00001100,
	  0b00001100,
	  0b00001100,
	  0b01101100,
	  0b01101100,
	  0b00111000
	},{
	  0b00000000,
	  0b01100110,
	  0b01101100,
	  0b01111000,
	  0b01110000,
	  0b01111000,
	  0b01101100,
	  0b01100110
	},{
	  0b00000000,
	  0b01100000,
	  0b01100000,
	  0b01100000,
	  0b01100000,
	  0b01100000,
	  0b01100000,
	  0b01111110
	},{
	  0b00000000,
	  0b01100011,
	  0b01110111,
	  0b01111111,
	  0b01101011,
	  0b01100011,
	  0b01100011,
	  0b01100011
	},{
	  0b00000000,
	  0b01100011,
	  0b01110011,
	  0b01111011,
	  0b01101111,
	  0b01100111,
	  0b01100011,
	  0b01100011
	},{
	  0b00000000,
	  0b00111100,
	  0b01100110,
	  0b01100110,
	  0b01100110,
	  0b01100110,
	  0b01100110,
	  0b00111100
	},{
	  0b00000000,
	  0b01111100,
	  0b01100110,
	  0b01100110,
	  0b01100110,
	  0b01111100,
	  0b01100000,
	  0b01100000
	},{
	  0b00000000,
	  0b00111100,
	  0b01100110,
	  0b01100110,
	  0b01100110,
	  0b01101110,
	  0b00111100,
	  0b00000110
	},{
	  0b00000000,
	  0b01111100,
	  0b01100110,
	  0b01100110,
	  0b01111100,
	  0b01111000,
	  0b01101100,
	  0b01100110
	},{
	  0b00000000,
	  0b00111100,
	  0b01100110,
	  0b01100000,
	  0b00111100,
	  0b00000110,
	  0b01100110,
	  0b00111100
	},{
	  0b00000000,
	  0b01111110,
	  0b01011010,
	  0b00011000,
	  0b00011000,
	  0b00011000,
	  0b00011000,
	  0b00011000
	},{
	  0b00000000,
	  0b01100110,
	  0b01100110,
	  0b01100110,
	  0b01100110,
	  0b01100110,
	  0b01100110,
	  0b00111110
	},{
	  0b00000000,
	  0b01100110,
	  0b01100110,
	  0b01100110,
	  0b01100110,
	  0b01100110,
	  0b00111100,
	  0b00011000
	},{
	  0b00000000,
	  0b01100011,
	  0b01100011,
	  0b01100011,
	  0b01101011,
	  0b01111111,
	  0b01110111,
	  0b01100011
	},{
	  0b00000000,
	  0b01100011,
	  0b01100011,
	  0b00110110,
	  0b00011100,
	  0b00110110,
	  0b01100011,
	  0b01100011
	},{
	  0b00000000,
	  0b01100110,
	  0b01100110,
	  0b01100110,
	  0b00111100,
	  0b00011000,
	  0b00011000,
	  0b00011000
	},{
	  0b00000000,
	  0b01111110,
	  0b00000110,
	  0b00001100,
	  0b00011000,
	  0b00110000,
	  0b01100000,
	  0b01111110
	},{
	  0b00000000,
	  0b00000000,
	  0b00000000,
	  0b00000000,
	  0b00000000,
	  0b00000000,
	  0b00000000,
	  0b00000000
	},{
	  0b00000000,
	  0b00000000,
	  0b00000000,
	  0b00111100,
	  0b00000110,
	  0b00111110,
	  0b01100110,
	  0b00111110
	},{
	  0b00000000,
	  0b01100000,
	  0b01100000,
	  0b01100000,
	  0b01111100,
	  0b01100110,
	  0b01100110,
	  0b01111100
	},{
	  0b00000000,
	  0b00000000,
	  0b00000000,
	  0b00111100,
	  0b01100110,
	  0b01100000,
	  0b01100110,
	  0b00111100
	},{
	  0b00000000,
	  0b00000110,
	  0b00000110,
	  0b00000110,
	  0b00111110,
	  0b01100110,
	  0b01100110,
	  0b00111110
	},{
	  0b00000000,
	  0b00000000,
	  0b00000000,
	  0b00111100,
	  0b01100110,
	  0b01111110,
	  0b01100000,
	  0b00111100
	},{
	  0b00000000,
	  0b00011100,
	  0b00110110,
	  0b00110000,
	  0b00110000,
	  0b01111100,
	  0b00110000,
	  0b00110000
	},{
	  0b00000000,
	  0b00000000,
	  0b00111110,
	  0b01100110,
	  0b01100110,
	  0b00111110,
	  0b00000110,
	  0b00111100
	},{
	  0b00000000,
	  0b01100000,
	  0b01100000,
	  0b01100000,
	  0b01111100,
	  0b01100110,
	  0b01100110,
	  0b01100110
	},{
	  0b00000000,
	  0b00000000,
	  0b00011000,
	  0b00000000,
	  0b00011000,
	  0b00011000,
	  0b00011000,
	  0b00111100
	},{
	  0b00000000,
	  0b00001100,
	  0b00000000,
	  0b00001100,
	  0b00001100,
	  0b01101100,
	  0b01101100,
	  0b00111000
	},{
	  0b00000000,
	  0b01100000,
	  0b01100000,
	  0b01100110,
	  0b01101100,
	  0b01111000,
	  0b01101100,
	  0b01100110
	},{
	  0b00000000,
	  0b00011000,
	  0b00011000,
	  0b00011000,
	  0b00011000,
	  0b00011000,
	  0b00011000,
	  0b00011000
	},{
	  0b00000000,
	  0b00000000,
	  0b00000000,
	  0b01100011,
	  0b01110111,
	  0b01111111,
	  0b01101011,
	  0b01101011
	},{
	  0b00000000,
	  0b00000000,
	  0b00000000,
	  0b01111100,
	  0b01111110,
	  0b01100110,
	  0b01100110,
	  0b01100110
	},{
	  0b00000000,
	  0b00000000,
	  0b00000000,
	  0b00111100,
	  0b01100110,
	  0b01100110,
	  0b01100110,
	  0b00111100
	},{
	  0b00000000,
	  0b00000000,
	  0b01111100,
	  0b01100110,
	  0b01100110,
	  0b01111100,
	  0b01100000,
	  0b01100000
	},{
	  0b00000000,
	  0b00000000,
	  0b00111100,
	  0b01101100,
	  0b01101100,
	  0b00111100,
	  0b00001101,
	  0b00001111
	},{
	  0b00000000,
	  0b00000000,
	  0b00000000,
	  0b01111100,
	  0b01100110,
	  0b01100110,
	  0b01100000,
	  0b01100000
	},{
	  0b00000000,
	  0b00000000,
	  0b00000000,
	  0b00111110,
	  0b01000000,
	  0b00111100,
	  0b00000010,
	  0b01111100
	},{
	  0b00000000,
	  0b00000000,
	  0b00011000,
	  0b00011000,
	  0b01111110,
	  0b00011000,
	  0b00011000,
	  0b00011000
	},{
	  0b00000000,
	  0b00000000,
	  0b00000000,
	  0b01100110,
	  0b01100110,
	  0b01100110,
	  0b01100110,
	  0b00111110
	},{
	  0b00000000,
	  0b00000000,
	  0b00000000,
	  0b00000000,
	  0b01100110,
	  0b01100110,
	  0b00111100,
	  0b00011000
	},{
	  0b00000000,
	  0b00000000,
	  0b00000000,
	  0b01100011,
	  0b01101011,
	  0b01101011,
	  0b01101011,
	  0b00111110
	},{
	  0b00000000,
	  0b00000000,
	  0b00000000,
	  0b01100110,
	  0b00111100,
	  0b00011000,
	  0b00111100,
	  0b01100110
	},{
	  0b00000000,
	  0b00000000,
	  0b00000000,
	  0b01100110,
	  0b01100110,
	  0b00111110,
	  0b00000110,
	  0b00111100
	},{
	  0b00000000,
	  0b00000000,
	  0b00000000,
	  0b00111100,
	  0b00001100,
	  0b00011000,
	  0b00110000,
	  0b00111100
}};
const int IMAGES_LEN = sizeof(IMAGES)/8;

const int LETTER_SLICES = 8;

class LetterHandler {
	public:
		static byte getAlphabetIndex(char c);

};

#endif // LetterHandler_h