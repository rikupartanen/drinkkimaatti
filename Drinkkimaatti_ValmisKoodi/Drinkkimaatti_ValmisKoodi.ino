#include <LiquidCrystal.h>
#include <ezButton.h>
//Kirjastot näytölle sekä napille

ezButton button1(7);  // ezButton-objekti napille 7-pinnille
ezButton button2(8);  // ezButton-objekti napille 8-pinnille

int Contrast = 100;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
// Näytön alustaminen

const int pumppu1 = A0; //Oikea(Kossu)
const int pumppu2 = A1; //Vasen(Vissy)
const int pumppu3 = A2; //Oikea(Jallu)
const int pumppu4 = A3; //Vasen(Kokis)
const int pumppu5 = A4; //Oikea(Rommi)
const int pumppu6 = A5; //Vasen(Russian)
// Pumput ja niiden pinnit

int valittujuoma;
int juomanteko;
// intit joiden perusteella valikot toimivat



void setup()
{

  button1.setDebounceTime(50); 
  button2.setDebounceTime(50); 
// Napeille debouncen tekeminen, aikana 50 millisekuntia  

  analogWrite(6, Contrast);
  lcd.begin(16, 2);
// Näytön päällelaittaminen
  
  valittujuoma = 1;
  juomanteko = 0;
// Valikoiden asettaminen perusasetuksiin

  
  pinMode(pumppu1, OUTPUT);
  pinMode(pumppu2, OUTPUT);
  pinMode(pumppu3, OUTPUT);
  pinMode(pumppu4, OUTPUT);
  pinMode(pumppu5, OUTPUT);
  pinMode(pumppu6, OUTPUT);

  
  lcd.setCursor(0, 0);
  lcd.print("Hyvaa iltaa!");
  lcd.setCursor(0, 1);
  lcd.print("Mita laitetaan?");
  delay(3000);
// Aloitusteksti näytölle
}



void loop(){

  button1.loop(); 
  button2.loop(); 
// Alustetaan ezButton napeille


if(button1.isPressed()) {
  valittujuoma ++;
// Mustaa nappia painamalla siirrytään menussa seuraavaan juomaan

}

if(button2.isPressed()){
  juomanteko ++;
// Punaisella napilla juoman tekeminen

}

if(valittujuoma == 7){
  valittujuoma = 1;
// Listan yli mentäessä palataan takaisin listan alkuun

}

//ensinmäinen drinkki 
if(valittujuoma == 1){
  if(juomanteko == 0){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Kossuvissy");
  lcd.setCursor(0, 1);
  lcd.print("Lisaa jaita");
  delay(50);
  return;
// Näytetään juoman tiedot
  }
  if(juomanteko == 1){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("KossuVissy");
  lcd.setCursor(0, 1);
  lcd.print("Drinkki tulossa...");
  delay(500);
  digitalWrite(pumppu1, HIGH);
  delay(2500);
  digitalWrite(pumppu1, LOW);
  delay(500);
  digitalWrite(pumppu2, HIGH);
  delay(7500);
  digitalWrite(pumppu2, LOW);
  delay(500);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Juoma valmis!");
  lcd.setCursor(0, 1);
  lcd.print("Ole hyva!");
  delay(4000);
  juomanteko = -juomanteko;
  return;
// Tehdään juoma


}
}

// Tämän jälkeinen koodi onkin edellisen if-lauseen toistoa uusilla arvoilla, pumpuilla sekä teksteillä

 //toinen drinkki
if(valittujuoma == 2){
  if(juomanteko == 0){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Jallukola");
  lcd.setCursor(0, 1);
  lcd.print("Lisaa jaita");
  delay(50);
  return;
  }
  if(juomanteko == 1){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("JalluKola");
  lcd.setCursor(0, 1);
  lcd.print("Drinkki tulossa...");
  delay(500);
  digitalWrite(pumppu3, HIGH);
  delay(2500);
  digitalWrite(pumppu3, LOW);
  delay(500);
  digitalWrite(pumppu4, HIGH);
  delay(7500);
  digitalWrite(pumppu4, LOW);
  delay(500);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Juoma valmis!");
  lcd.setCursor(0, 1);
  lcd.print("Ole hyva!");
  delay(4000);
  juomanteko = -juomanteko;
  return;

}
}
 //kolmas drinkki
if(valittujuoma == 3){
  if(juomanteko == 0){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("KossuRussian");
  lcd.setCursor(0, 1);
  lcd.print("Lisaa jaita");
  delay(50);

  }
  if(juomanteko == 1){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("KossuRussian");
  lcd.setCursor(0, 1);
  lcd.print("Drinkki tulossa...");
  delay(500);
  digitalWrite(pumppu1, HIGH);
  delay(2500);
  digitalWrite(pumppu1, LOW);
  delay(500);
  digitalWrite(pumppu6, HIGH);
  delay(7500);
  digitalWrite(pumppu6, LOW);
  delay(500);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Juoma valmis!");
  lcd.setCursor(0, 1);
  lcd.print("Ole hyva!");
  delay(4000);
  juomanteko = -juomanteko;

}
}
 //neljäs drinkki
if(valittujuoma == 4){
  if(juomanteko == 0){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("RommiKola");
  lcd.setCursor(0, 1);
  lcd.print("Lisaa jaita");
  delay(50);
  }
  if(juomanteko == 1){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("RommiKola");
  lcd.setCursor(0, 1);
  lcd.print("Drinkki tulossa...");
  delay(500);
  digitalWrite(pumppu5, HIGH);
  delay(2500);
  digitalWrite(pumppu5, LOW);
  delay(500);
  digitalWrite(pumppu4, HIGH);
  delay(7500);
  digitalWrite(pumppu4, LOW);
  delay(500);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Juoma valmis!");
  lcd.setCursor(0, 1);
  lcd.print("Ole hyva!");
  delay(4000);
  juomanteko = -juomanteko;

}
}
//letkujen täyttö ennen käyttöä
if(valittujuoma == 5){
  if(juomanteko == 0){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Letkujen taytto");
  lcd.setCursor(0, 1);
  lcd.print("tama ensin");
  delay(50);
  }
  if(juomanteko == 1){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Letkut");
  lcd.setCursor(0, 1);
  lcd.print("tayttymassa...");
  delay(500);
  digitalWrite(pumppu1, HIGH);
  delay(500);
  digitalWrite(pumppu1, LOW);
  digitalWrite(pumppu2, HIGH);
  delay(500);
  digitalWrite(pumppu2, LOW);
  digitalWrite(pumppu3, HIGH);
  delay(500);
  digitalWrite(pumppu3, LOW);
  digitalWrite(pumppu4, HIGH);
  delay(500);
  digitalWrite(pumppu4, LOW);
  digitalWrite(pumppu5, HIGH);
  delay(500);
  digitalWrite(pumppu5, LOW);
  digitalWrite(pumppu6, HIGH);
  delay(500);
  digitalWrite(pumppu6, LOW);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Letkut taynna");
  lcd.setCursor(0, 1);
  lcd.print("Ole hyva!");
  delay(4000);
  juomanteko = -juomanteko;

}
}
 //letkujen puhdistus käytön jälkeen
if(valittujuoma == 6){
  if(juomanteko == 0){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Letkujen");
  lcd.setCursor(0, 1);
  lcd.print("puhdistus");
  delay(50);
  }
  if(juomanteko == 1){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Puhdistus");
  lcd.setCursor(0, 1);
  lcd.print("kaynnissa...");
  delay(500);
  digitalWrite(pumppu1, HIGH);
  delay(6000);
  digitalWrite(pumppu1, LOW);
  digitalWrite(pumppu2, HIGH);
  delay(6000);
  digitalWrite(pumppu2, LOW);
  digitalWrite(pumppu3, HIGH);
  delay(6000);
  digitalWrite(pumppu3, LOW);
  digitalWrite(pumppu4, HIGH);
  delay(6000);
  digitalWrite(pumppu4, LOW);
  digitalWrite(pumppu5, HIGH);
  delay(6000);
  digitalWrite(pumppu5, LOW);
  digitalWrite(pumppu6, HIGH);
  delay(6000);
  digitalWrite(pumppu6, LOW);
  delay(500);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Letkut");
  lcd.setCursor(0, 1);
  lcd.print("puhdistettu");
  delay(4000);
  juomanteko = -juomanteko;
}
}

  
}
