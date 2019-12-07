//Code for ATMEG8
// including temperature and humidity
#include <avr/io.h>
#define F_CPU 16000000UL 
#include <avr/interrupt.h>
#include <util/delay.h>
#include <LiquidCrystal.h>


volatile uint16_t count=0;		//Main revolution counter

volatile uint16_t rpm=0000;	//Revolution per minute
volatile uint16_t rp4s=0000;	//Revolution per second
double speeds;
double speedskmph;
float tempc = 0;  // variable for holding Celcius temp (floating for decimal points precision)
int tempPin = 0;  // Declaring the Analog input to be 0 (A0) of Arduino board.
float rhsense = 0;
float rh = 0;
float k=0;


LiquidCrystal lcd(8, 7, 10, 11, 12, 13);

// for board made for control project use LiquidCrystal lcd(8, 7, 10, 11, 12, 13);

void Wait()
{
	uint8_t i;
	for(i=0;i<2;i++)
	{
		_delay_loop_2(0);
	}
}

void Wait2()
{
	uint8_t i;
	for(i=0;i<20;i++)
	{
		_delay_loop_2(0);
	}
}
void setup ()
{
    Serial.begin(9600); //opens serial port, sets data rate to 9600 bps
    
      lcd.begin(16, 2);
      


  
  Serial.println("RPM TESTING");
        lcd.setCursor(0, 0);
        lcd.print("RPM TESTING");
        lcd.setCursor(0, 1);
        lcd.print("By SHP");
        
	Wait2();
	Wait2();

           init_anemo(  );



}

	void loop()
	{
  
  
                 sei();
                 
              

		if(PIND & (1<<DDD2))
		{
			PORTB|=(1<<DDB1);
		}
		else
		{
			PORTB&=(~(1<<DDB1));
		}

            		Wait();

                  cli();

                 
                
                 
                 //lcd_all( );
                 
                 sei(); 


	}
	


ISR(INT0_vect)
{
	//Jumps here automatically when INT0 pin detect a falling edge
	count++;
       // Wait();
}

ISR(TIMER1_COMPA_vect)
{
	//Jumps here every 4 sec exactly!
	rp4s=count;
	rpm=rp4s*60*.25;
speeds= rp4s*3.14*.27*.25;
speedskmph= rp4s*3.14*.27*.25*3.6;
 // Serial print for debugging
             Serial.print("Count ");
             Serial.println(count, DEC);
             Serial.print("Speed ");
             Serial.println(speeds, DEC);      

       
       //lcd_anemo();
         lcd_all( );
       
	//count=0;
       
 //      cli(); //Disables interrupt
 

 
 
} 



void init_anemo(  ) {

        TCCR1A = 0;// set entire TCCR1A register to 0
        TCCR1B = 0;// same for TCCR1B
        TCNT1  = 0;//initialize counter value to 0


//INitialisations for anemo
	MCUCR|=(1<<ISC01)|(1<<ISC00);	//Raising edge on INT0 triggers interrupt.
	//MCUCR|=(1<<ISC00);
        //MCUCR|=(1<<ISC01)
        GICR|=(1<<INT0);	


	TCCR1B|=((1<<WGM12)|(1<<CS12)|(1<<CS10));


	
	//OCR1A=65530;
         OCR1A = 62499;// = (16*10^6) / (.25*1024) - 1 (must be <65536)
	TIMSK|=(1<<OCIE1A);	
	//sei();
        
        
	DDRB|=(1<<DDB1);
  
  
  
}






void lcd_anemo(  ) {

             lcd.clear();
             lcd.setCursor(0, 0);
             lcd.print("Count ");
             lcd.setCursor(0, 1);
             lcd.print("SPEED");
       
                lcd.setCursor(7, 0);
                lcd.print(count);
                lcd.setCursor(7, 1);
                lcd.print(speeds);
                lcd.setCursor(13, 1);
                lcd.print("m/S");        
        
        count=0;        
 
}

void lcd_all( ) {

             lcd.clear();
             lcd.setCursor(0, 0);
             lcd.print("Count ");
             lcd.setCursor(0, 1);
             lcd.print("SPEED");
       
                lcd.setCursor(7, 0);
                lcd.print(count);
                lcd.setCursor(7, 1);
                lcd.print(speedskmph);
                lcd.setCursor(13, 1);
                lcd.print("Km/h");  
  
              
                              
                Wait2();
                
                
                
                count=0;
            
 }
