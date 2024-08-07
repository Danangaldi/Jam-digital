#include <DS3231.h> //mengincludekan library DS3231
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <TM1637Display.h>

#define CLK 2
#define DIO 3

TM1637Display display(CLK, DIO);
LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display
DS3231  rtc(SDA, SCL); // inisialisasi penggunaan i2c

Time t;
unsigned int h,m,s;
byte f;

#define buz 11

int Hor;

int Min;

int Sec;
const int ldr = A2;
int nilai;

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
//  pinMode(11, OUTPUT);
//  pinMode(10, OUTPUT);
//  pinMode(9, OUTPUT);
//  pinMode(8, OUTPUT);
//  pinMode(7, OUTPUT);
//  pinMode(6, OUTPUT);
//  pinMode(5, OUTPUT);
//  pinMode(4, OUTPUT);
  DDRD = B11111111;
  DDRB = B11111111;
  Serial.begin(115200);

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

  nilai = analogRead(ldr);
  Serial.print("Nilai LDR: ");
  Serial.println(nilai);
  if (nilai < 25) {
  //led hidup kemudian mati 750
//    digitalWrite(11, HIGH);
//    digitalWrite(10, HIGH);
//    digitalWrite(9, HIGH);
//    digitalWrite(8, HIGH);
//    digitalWrite(7, HIGH);
//    digitalWrite(6, HIGH);
//    digitalWrite(5, HIGH);
//    digitalWrite(4, HIGH);
    PORTD = B11111000;
    PORTB = B00001111;
    delay(80);

    //Pembatas megalir dari tengah ke pinggir speed 100 kelima
//    digitalWrite(11, LOW);
//    digitalWrite(10, LOW);
//    digitalWrite(9, LOW);
//    digitalWrite(8, HIGH);
//    digitalWrite(7, HIGH);
//    digitalWrite(6, LOW);
//    digitalWrite(5, LOW);
//    digitalWrite(4, LOW);
    PORTD = B10000000;
    PORTB = B00000001;
    delay(60);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    delay(60);
    digitalWrite(11, LOW);
    digitalWrite(10, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(4, LOW);
    delay(60);
    digitalWrite(11, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(4, HIGH);
    delay(60);
    
    //mengalir dari pinggir ke tengah speed 100 kelima
    digitalWrite(11, LOW);
    digitalWrite(10, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(4, LOW);
    delay(60);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    delay(60);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
    digitalWrite(8, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    delay(60);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
    digitalWrite(8, LOW);
    digitalWrite(7, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    delay(60);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
    digitalWrite(8, LOW);
    digitalWrite(7, LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    delay(60);
     //Pembatas led mengalir 100 ketiga
    digitalWrite(11, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
    digitalWrite(8, LOW);
    digitalWrite(7, LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    delay(20);
    digitalWrite(11, LOW);
    digitalWrite(10, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(8, LOW);
    digitalWrite(7, LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    delay(20);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(8, LOW);
    digitalWrite(7, LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    delay(20);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
    digitalWrite(8, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    delay(20);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
    digitalWrite(8, LOW);
    digitalWrite(7, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    delay(20);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
    digitalWrite(8, LOW);
    digitalWrite(7, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    delay(20);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
    digitalWrite(8, LOW);
    digitalWrite(7, LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(4, LOW);
    delay(20);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
    digitalWrite(8, LOW);
    digitalWrite(7, LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    digitalWrite(4, HIGH);
    delay(20); 
    
    //mengalir sebaliknya 100 ketiga
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
    digitalWrite(8, LOW);
    digitalWrite(7, LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    digitalWrite(4, HIGH);
    delay(20);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
    digitalWrite(8, LOW);
    digitalWrite(7, LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(4, LOW);
    delay(20);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
    digitalWrite(8, LOW);
    digitalWrite(7, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    delay(20);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
    digitalWrite(8, LOW);
    digitalWrite(7, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    delay(20);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
    digitalWrite(8, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    delay(20);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(8, LOW);
    digitalWrite(7, LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    delay(20);
    digitalWrite(11, LOW);
    digitalWrite(10, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(8, LOW);
    digitalWrite(7, LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    delay(20);
    digitalWrite(11, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
    digitalWrite(8, LOW);
    digitalWrite(7, LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    delay(20);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
    digitalWrite(8, LOW);
    digitalWrite(7, LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    delay(20);
    
    digitalWrite(11, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(4, HIGH);
    delay(20);
    
    //mengalir dari pinggir ke tengah speed 100 kelima
    digitalWrite(11, LOW);
    digitalWrite(10, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(4, LOW);
    delay(20);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    delay(20);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
    digitalWrite(8, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    delay(20);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
    digitalWrite(8, LOW);
    digitalWrite(7, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    delay(20);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
    digitalWrite(8, LOW);
    digitalWrite(7, LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    delay(20);
    

   }
   else 
   {
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
    digitalWrite(8, LOW);
    digitalWrite(7, LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
   }

  
//  delay (1000); //waktu tunda 1 detik per cycle

  
}
