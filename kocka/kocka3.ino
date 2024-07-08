int led1 = 6; //definicija spremenljivk 
int led2 = 5; 
int led3 = 4; 
int but = 3; //pin na katerem bo gumbek 
int rng; //spremenljivka ki bo hranila naključno vrednost 
 
void setup() { 
  pinMode(led1, OUTPUT); //nastavitev pinov na katere si priklopljene ledice na izhod 
  pinMode(led2, OUTPUT); 
  pinMode(led3, OUTPUT); 
  pinMode(but, INPUT_PULLUP); //nastavitev pina na katerem je gumb na vhod z pullup uporom
  Serial.begin(9600);  //vklop in nastavitev serial monitorja na 9600 baudov 
} 

void loop() { 
    if (digitalRead(but) == LOW) {  //preveri če je stanje na pinu z gumbom LOW – gumb je pritisnjen 
 
 rng = random(0, 4); //Dobi naključno vrednost med 0 in 3 (random(vključno, izključno) in jo zapiše v spremenljivko rng. 
 Serial.println(rng); //Izpiše vrednost v serial monitor (za preverjanje pravilnosti delovanja) 

 if (rng == 0) { //Preveri če je vrednost rng 0 
      digitalWrite(led1, LOW); //Ugasne vse lučke  
      digitalWrite(led2, LOW); 
      digitalWrite(led3, LOW); 
 } else if (rng == 1) { //Preveri če je vrednost rng 1 
      digitalWrite(led1, HIGH); //Prižge 1. lučko  
      digitalWrite(led2, LOW); 
      digitalWrite(led3, LOW); 
 } else if (rng == 2) { //Preveri če je vrednost rng 2 
      digitalWrite(led1, HIGH); //Prižge 1. in 2. lučko 
      digitalWrite(led2, HIGH); 
      digitalWrite(led3, LOW); 
    } else if (rng == 3) { //Preveri če je vrednost rng 3. Tu bi lahko uporabili tudi else stavek saj je vrednost 3 še edina preostala možnost
       
      digitalWrite(led1, HIGH);  
      digitalWrite(led2, HIGH); //Prižge vse 3 lučke 
      digitalWrite(led3, HIGH); 
    } 

    while (digitalRead(but) == LOW) { //Preveri ali je gumb še vedno pritisnjen 
      delay(10); //Program ne dela nič – ne gre ponovno generirati naključne vrednosti dokler gumba ne spustimo in ga nato ponovno pritisnemo.
//10 milisekundni zamik dodamo za razbremenitev procesorja 
    } 
  } 
} 
 
