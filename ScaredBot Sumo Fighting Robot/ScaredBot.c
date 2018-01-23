#include <p18f4520.h>
#include <adc.h>
#include <delays.h>

unsigned char GetADC( unsigned char ADC_CHANNEL );
void RightForward( void );
void RightReverse( void );
void LeftForward( void );
void LeftReverse( void );

#define RIGHT_IR ADC_CH0
#define RIGHT_POT ADC_CH1
#define LEFT_IR ADC_CH2
#define LEFT_POT ADC_CH3

void main( void ) {

  unsigned char rightIR;
  unsigned char rightPot;
  unsigned char leftIR;
  unsigned char leftPot;

  TRISA = 0b00001111;
  TRISC = 0;

  OpenADC( ADC_FOSC_32 & ADC_RIGHT_JUST & ADC_12_TAD, ADC_CH0 & ADC_INT_OFF & ADC_VREFPLUS_VDD & ADC_VREFMINUS_VSS, 11 );

  while( 1 ) {
      rightIR = GetADC( RIGHT_IR );
      rightPot = GetADC( RIGHT_POT );
      leftIR = GetADC( LEFT_IR );
      leftPot = GetADC( LEFT_POT );

      if (rightIR > rightPot && leftIR > leftPot) {
          RightReverse();
          LeftReverse();
          //medium delay
          Delay10KTCYx(255);
          Delay10KTCYx(255);
          Delay10KTCYx(255);

          RightForward();
          LeftReverse();
          //delay time for 180 deg
          Delay10KTCYx(255);
          Delay10KTCYx(255);
          Delay10KTCYx(255);
          Delay10KTCYx(255);
          Delay10KTCYx(255);
      }
      else if (rightIR > rightPot){
          RightReverse();
          LeftReverse();
          //medium delay
          Delay10KTCYx(255);
          Delay10KTCYx(255);

          //rotate CCW
          RightReverse();
          LeftForward();
          //delay timed for 135 deg
          Delay10KTCYx(255);
          Delay10KTCYx(255);
          Delay10KTCYx(255);
          Delay10KTCYx(255);
      }
      else if (leftIR > leftPot){
          RightReverse();
          LeftReverse();
          //medium delay
          Delay10KTCYx(255);
          Delay10KTCYx(255);

          //rotate CW
          RightForward();
          LeftReverse();
          //delay timed for 135 deg
          Delay10KTCYx(255);
          Delay10KTCYx(255);
          Delay10KTCYx(255);
          Delay10KTCYx(255);
      }
      else {
          RightForward();
          LeftForward();
          //smaller delay for 'sample rate'
          Delay10KTCYx(255);
      }
  }

}



void RightForward( void ) {
    PORTCbits.RC7 = 0;

    PORTCbits.RC4 = 0; //input 1
    PORTCbits.RC5 = 1; //input 2
}

void RightReverse( void ) {
    PORTCbits.RC7 = 1; //right flag raised

    PORTCbits.RC4 = 1; //input 1
    PORTCbits.RC5 = 0; //input 2
}

void LeftForward ( void ) {
    PORTCbits.RC6 = 0;

    PORTCbits.RC2 = 1;
    PORTCbits.RC3 = 0;
}

void LeftReverse ( void ) {
    PORTCbits.RC6 = 1; //left flag raised

    PORTCbits.RC2 = 0;
    PORTCbits.RC3 = 1;
}

unsigned char GetADC( unsigned char ADC_CHANNEL ) {
  unsigned int raw;

  SetChanADC( ADC_CHANNEL );
  ConvertADC();
  while( BusyADC() );
  raw = ReadADC();
  return raw>>2;
}