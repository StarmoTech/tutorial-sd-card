#include <SPI.h>
#include <SD.h>
File myFile;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ;                                                // pokreni kada se otvori serial monitor
  }
  
  Serial.println("pokretanje SD kartice...");
  
  if (!SD.begin(10)) {
    Serial.println("Pokretanje bezuspješno");
    while (1);
  }
  
  Serial.println("Pokretanje uspješno");

  myFile = SD.open("test.txt", FILE_WRITE);          // napravi ili otvori dokument pod nazivom test (.txt je format)
  
  if (myFile) {                                      // ako je dokument otvoren piši po njemu
    Serial.print("pisanje po dok. test.txt...");     // ispiši tekst za serial monitor
    myFile.println("testno pisanje :)");             // zapiši na karicu ovaj tekst
    myFile.println("test 1, 2, 3.");                 // ispiši u novi red tekst
    for (int i = 0; i < 20; i++) {                   // koristi for petlju od 0 do 19
    myFile.println(i);                               // ispiši vrijednosti petlje                                             
  
    myFile.close();                                  // ZATVORI DOKUMENT
    Serial.println("Uspješno završeno!");            // ispiši na serial monitor               
  } else {                                           // ako nije moguće otvori dokument 
    Serial.println("Greška otvaranja  test.txt");    // ispiši na serial monitoru
  }
}

void loop() {
  // ...
}
