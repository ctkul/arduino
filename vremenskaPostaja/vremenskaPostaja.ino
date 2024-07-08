#include <LiquidCrystal.h> //naložimo knjižnico "AM50288H" za LCD, ki jo prej namestimo v Arduino IDE
#include <DHT.h> //naložimo knjižnico "DHT sensor library by Adafruit" za DHT senzor,   ki jo prej namestimo v Arduino IDE

const int DHTTYPE = DHT11; //povemo katero vrsto DHT senzorja uporabljamo
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2; //povemo kateri pin na lcd je priključen na kateri pin na arduinu. 
// Če spredaj napišemo »const« to pomeni da je ta vrednost konstanta in se ne bo spreminjala. 
// Namesto da pišemo vsako spremenljivko enakega tipa posebej, lahko uporabimo zgornji zapis. 

LiquidCrystal lcd(rs, en, d4, d5, d6, d7); //definicija pinov za delovanje funkcije. Namesto dejanskih številk pinov smo uporabili konstante, ki smo jih prej določili. 
  
DHT dht(8, DHT11); //definiramo na katerem pinu so podatki, ki jih pošilja DHT senzor in vrsto senzorja 

void setup() {
  lcd.begin(16, 2); //Vklopimo naš LCD in definiramo koliko stolpcev in vrstic ima
  dht.begin(); //začne delovanje DHT senzorja 
  lcd.clear(); //pobriše zaslon
   //Pinov lcd zaslona in dht senzorja ni potrebno definirati, saj to stori knjižnica že sama 
}

void loop() {
lcd.setCursor(0, 0); //nastavi začetek pisanja na prvi stolpec in vrstico (začne šteti z 0)
  lcd.print("Temp: "); //Izpiše Temp: in presledek 
  lcd.print(dht.readTemperature()); //izpiše vrednost za temperaturo, ki jo je prebral DHT senzor 
  lcd.print((char)223); //223 (ASCII vrednost za ° ) bo spremenilo v obliko znaka in ga izpisalo, saj ne prepozna če vnesemo notri samo znak. 
  lcd.print("C"); //izpiše C

  lcd.setCursor(0, 1); //začne pisati v naslednji vrstici 
  lcd.print("Vlaga: "); //izpiše Vlaga: in presledek  
  lcd.print(dht.readHumidity()); //izpiše vrednost za vlago, ki jo je prebral DHT senzor
  lcd.print("%"); //Izpiše znak %

  delay(5000); //5 sekundni zamik pred naslednjim branjem
}
