#include <DS3231.h> //mengincludekan library DS3231
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <TM1637Display.h>

#define CLK 2
#define DIO 3

TM1637Display display(CLK, DIO);
LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display
DS3231  rtc(SDA, SCL); // inisialisasi penggunaan i2c

Time  t;
unsigned int h,m,s;
byte f;

#define buz 11

int Hor;

int Min;

int Sec;

void setup()
{
  Serial.begin(115200); //set komunikasi baut serial monitor pada 115200
  rtc.begin();
  lcd.begin();
  // Print a message to the LCD.
  lcd.setCursor(0,1);
  //setting pertama download program
//  rtc.setDate(15, 8, 2021);   //mensetting tanggal
//  rtc.setTime(11, 8, 00);
//  rtc.setDOW(7);     //menset hari

  display.setBrightness(0x0f);
//--------------------------------------------------------------
//aktifkan baris perintah ini untuk seting RTC
//lakukan jika waktu tidak sesuai
//cukup sekali saja, setelah itu di-non-aktifkan lagi perintahnya
//rtc.setDate(15,8,2021);  //setting tanggal 11 Oktober 2019
//rtc.setTime(11, 8, 00);   //setting jam 08:15:00
//rtc.setDOW(7);            //setting hari Jumat, 7=Minggu,1=Senin
 
//setelah didownload awal selesai, download kedua dengan memberi tanda komen "//"
}
 
void loop()
{
  t = rtc.getTime();

  Hor = t.hour;

  Min = t.min;

  Sec = t.sec;
  Serial.print(rtc.getDOWStr()); //prosedur pembacaan hari
  Serial.print(" ");
  
  Serial.print(rtc.getDateStr()); //prosedur pembacaan tanggal
  Serial.print(" -- ");
 
  Serial.println(rtc.getTimeStr()); //prosedur pembacaan waktu


  lcd.setCursor(0,0);
  lcd.print("Date: "); 
  lcd.setCursor(6,0);
  lcd.print(rtc.getDateStr());

//  lcd.setCursor(0,1);
//  lcd.print("Jam: ");
//  lcd.setCursor(5,1);
//  lcd.print(rtc.getTimeStr());

  lcd.setCursor(0,1);
  lcd.print("Day :");
  lcd.setCursor(6,1);
  lcd.print(rtc.getDOWStr());
  

  t = rtc.getTime();
  h=t.hour,DEC;
  m=t.min,DEC;
  s=t.sec,DEC; 
  h=(h*100+m);
  if(f==0)
  {
    display.showNumberDecEx(h, 64); 
    f=1;
  }
  else
  {
    display.showNumberDecEx(h, 0); 
    f=0;
  }
  
  delay (1000); //waktu tunda 1 detik per cycle
}
