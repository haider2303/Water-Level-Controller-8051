 #include<reg51.h>
 #include<lcd.h>

 sbit Selection_Switch=P1^0;
 sbit Quarter=P1^1;
 sbit Half=P1^2;
 sbit Three_Fourth=P1^3;
 sbit Full=P1^4;
 sbit Motor_Led=P1^5;
 
sbit RS = P0^0;
sbit EN = P0^1;
sbit D0 = P2^0;
sbit D1 = P2^1;
sbit D2 = P2^2;
sbit D3 = P2^3;
sbit D4 = P2^4;
sbit D5 = P2^5;
sbit D6 = P2^6;
sbit D7 = P2^7;

void Set_IO()
{
	Selection_Switch=1;
	Quarter=1;
	Half=1;
	Three_Fourth=1;
	Full=1;
}

void time_delay(int input)
{
 int j;
 int i;
  for(i=0;i<input;i++)
  {
    for(j=0;j<100;j++)
    {
    }
  }
}

void main(void)
{
    
   Set_IO();
   Lcd8_Init();
   while(1)
   {
	 if(Selection_Switch==1)
	 {
          Lcd8_Set_Cursor(1,1);
	 
	 if(Quarter==0&&Half==0&&Three_Fourth==0&&Full==0)
	 {
	   Lcd8_Clear();
	   time_delay(1000);
	   Lcd8_Write_String("EMPTY");
	 }
	 
	else if(Quarter==1&&Half==0&&Three_Fourth==0&&Full==0)
	 {
	  Lcd8_Clear();
	  time_delay(1000);
	  Lcd8_Write_String("QUARTER");
	 }
	 
	else if(Quarter==1&&Half==1&&Three_Fourth==0&&Full==0)
	 {
	  Lcd8_Clear();
	  time_delay(1000);
	  Lcd8_Write_String("HALF");
	 } 
	 
	 else if(Quarter==1&&Half==1&&Three_Fourth==1&&Full==0)
	 {
	  Lcd8_Clear();
	  time_delay(1000);
      Lcd8_Write_String("THREE FOURTH");
	 } 
	 
	 else if(Quarter==1&&Half==1&&Three_Fourth==1&&Full==1)
	 {
	  Lcd8_Clear();
	  time_delay(1000);
	  Lcd8_Write_String("FULL");
	 } 	 
	
}
}
}

 