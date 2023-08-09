#include <SPI.h>
#include <SD.h>
File myFile;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; 
  }
  
  Serial.println("pokretanje SD kartice...");
  
  if (!SD.begin(10)) {
    Serial.println("Pokretanje bezuspješno");
    while (1);
  }
  
  Serial.println("Pokretanje uspješno");
  
  myFile = SD.open("test.txt");                     // otvori dokument pod nazivom test
  
  if (myFile) {                                     // ako je dokument otvoren
    Serial.println("test.txt:");                    // ispiši tekst za serial monitor
    
    while (myFile.available()) {
      Serial.write(myFile.read());                  // ispiši sve podatke sa kartice
    }
    
    myFile.close();                                 // zatvori očitano
  } else {                                          // ako nije moguće otvori dokument
    Serial.println("Greška otvaranja  test.txt");   // ispiši na serial monitoru
  }
}

void loop() {
  // ...
}
