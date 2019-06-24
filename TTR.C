#include<avr/io.h>
#include<util/delay.h>
void main()
{
DDRD=0b00000000; //Setting part A as an input port
DDRB=0b11111111; //Setting Part B as an output port
PORTD=0b11111111; // Pulling up all the pins of part A
int c;
while(1)
{
c=PIND;
if(c==0b11110000)  //All the sensors are on the table
PORTB=0b00001010; //Move Forward

if(c==0b11111000) //Sensor 1 is out of table
{
PORTB=0b00000101;
_delay_ms(400);
PORTB=0b00001001;
_delay_ms(600);
}

if(c==0b11110100) //Sensor 2 is out of table
{
PORTB=0b00000101;
_delay_ms(400);
PORTB=0b00000110;
_delay_ms(300);
}
if(c==0b11110010) //Sensor 3 is out of table
{
PORTB=0b00001010;
_delay_ms(200);
PORTB=0b00001001;
_delay_ms(300);
}

if(c==0b11110001) //Sensor 4 is out of table
{
PORTB=0b00001010;
_delay_ms(200);
PORTB=0b00001001;
_delay_ms(300);
}

if(c==0b11111100) //Sensor 1 and 2 is out of table
{
PORTB=0b00000101;
_delay_ms(250);
PORTB=0b00001001;
_delay_ms(300);
}

if(c==0b11111001) //Sensor 1 and 4  is out of table
PORTB=0b00000110;

if(c==0b11110011) //Sensor 3 and 4  is out of table
PORTB=0b00001010;

if(c==0b11110110) //Sensor 2 and 3 is out of table
PORTB=0b00000110;

if(c==0b11111110) //Sensor 1,2 and 3  is out of table
PORTB=0b00000110;

if(c==0b11110111) //Sensor 1 is on table
PORTB=0b00000110;

if(c==0b11111011) //Sensor 2 is on the table
PORTB=0b00001001;

if(c==0b11111101) //Sensor 3 is on the table
PORTB=0b00001001;
}
}









