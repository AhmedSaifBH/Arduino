// ----------------------------------------------------------------------
// 10-bit 1.95kHz Fast PWM For Arduino Mega2560
// Created by Ahmed Saif
// Instagram: https://www.instagram.com/digital.bh/
// YouTube: https://www.youtube.com/@AhmedSaif_BH
// ----------------------------------------------------------------------

void setup() {
  pinMode(11,OUTPUT);     // Set output compare pin (OC1A -- pin 11) as output pin

  TCCR1A = 0b00000011;    // Timer/Counter 1 Control Register A  -- b7b6,b5b4,b3b2 Compare Output Mode for Channel A,B,C -- b1b0 waveform generation mode
  TCCR1B = 0b00001010;    // Timer/Counter 1 Control Register B  -- b4b3 waveform generation mode -- set timer prescaler b3b1b0
  PRR0 &= 0b11110111;     // Power Reduction Register 0 -  enable Timer1 bit3 -> 0
  OCR1A = 0;              // Output Compare Register 1A 
  TCNT1 = 0;              // Reset Timer/Counter 1

}

void loop() {
    //-----------Example code --------------
    duty_cycle(0);  // Use the function duty_cycle to change the PWM duty cycle
    delay(5000);
    duty_cycle(50);
    delay(5000);
    duty_cycle(100);
    delay(5000);
    //--------------------------------------
}


void duty_cycle(float duty) {
  if(duty > 100 || duty == 0) {
      OCR1A = 0;
      TCNT1 = 0; // Reset Timer/Counter 1
      TCCR1A = 0b00000011; 
  }
  else {
      OCR1A = (duty/100)*1023;
      TCNT1 = 0; // Reset Timer/Counter 1
      TCCR1A = 0b10000011; 
  }
}
