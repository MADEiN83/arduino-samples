#include <SPI.h>
#include <MFRC522.h>
// Affectation des broches
#define RST_PIN 9
#define SS_PIN 10
MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup()
{
  // Initialisation du Module RFID
  Serial.begin(9600);
  while (!Serial)
    ;
  SPI.begin();
  mfrc522.PCD_Init();
  mfrc522.PCD_DumpVersionToSerial(); // Affichage des données de la bibliothèque
  Serial.println(F("Scan PICC to see UID, type, and data blocks..."));
}

void loop()
{
  // Attente d'une carte RFID
  if (!mfrc522.PICC_IsNewCardPresent())
  {
    return;
  }

  // Récupération des informations de la carte RFID
  if (!mfrc522.PICC_ReadCardSerial())
  {
    return;
  }

  Serial.print(F("The NUID tag is: "));
  String nuid = getCardUNID(mfrc522.uid.uidByte, mfrc522.uid.size);
  Serial.println(nuid);
  Serial.println();

  // Affichage des informations de la carte RFID
  mfrc522.PICC_DumpToSerial(&(mfrc522.uid));
}

/**
 * Helper routine to dump a byte array as hex values to Serial. 
 */
String getCardUNID(byte *buffer, byte bufferSize)
{
  String nuid = "";

  for (byte i = 0; i < bufferSize; i++)
  {
    nuid += buffer[i] < 0x10 ? " 0" : " ";
    nuid += String(buffer[i], HEX);
  }

  nuid.toUpperCase();

  return nuid;
}
