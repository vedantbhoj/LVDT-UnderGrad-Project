// LCD module connections
sbit LCD_RS at RD4_bit;
sbit LCD_EN at RD5_bit;
sbit LCD_D4 at RD0_bit;
sbit LCD_D5 at RD1_bit;
sbit LCD_D6 at RD2_bit;
sbit LCD_D7 at RD3_bit;

sbit LCD_RS_Direction at TRISD4_bit;
sbit LCD_EN_Direction at TRISD5_bit;
sbit LCD_D4_Direction at TRISD0_bit;
sbit LCD_D5_Direction at TRISD1_bit;
sbit LCD_D6_Direction at TRISD2_bit;
sbit LCD_D7_Direction at TRISD3_bit;
// End LCD module connections






unsigned long temp;
unsigned int i;
char digit[]="0.00mm";

void main() {


TRISA=0xFF;


ADCON0=0x01;
ADCON1=0x0E;



     Lcd_Init();                        // Initialize LCD

  Lcd_Cmd(_LCD_CLEAR);               // Clear display
  Lcd_Cmd(_LCD_CURSOR_OFF);          // Cursor off
  LCD_Out(1,3,"PROJECT NAME");
  LCD_Out(2,5,"--LVDT--");
  Delay_ms(2000);
  Lcd_Cmd(_LCD_CLEAR);
  LCD_Out(1,8,"BY");
   LCD_Out(2,1,"3119  3122  3123");
   Delay_ms(2000);

  do {
    temp = ADC_Read(0);   // Get 10-bit results of AD conversion
    temp=temp*5000/1023;   //Convert ADC value to mV



    digit[0]=(temp/1000)+48;
    digit[2]=((temp%1000)/100)+48;
    digit[3]=(((temp%1000)%100)/10)+48;
    //digit[4]=(((temp%1000)%100)%10)+48;

    LCD_Cmd(_LCD_CLEAR);
    LCD_Out(1,3,"DISPLACEMENT");
    LCD_Out(2,5,digit);

    Delay_ms(500);

  } while(1);
}