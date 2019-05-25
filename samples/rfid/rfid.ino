#include <SPI.h>
#include <MFRC522.h>

// Affectation des broches
#define RST_PIN 9
#define SS_PIN 10

MFRC522 rfid(SS_PIN, RST_PIN);

void setup()
{
  // Initialisation du Module RFID
  Serial.begin(9600);
  while (!Serial)
    ;

  SPI.begin();
  rfid.PCD_Init();
  rfid.PCD_DumpVersionToSerial(); // Affichage des données de la bibliothèque
  Serial.println(F("Scan PICC to see UID, type, and data blocks..."));
}

void loop()
{
  
  // Attente d'une carte RFID
  if (!rfid.PICC_IsNewCardPresent())
  {
    return;
  }

  // Récupération des informations de la carte RFID
  if (!rfid.PICC_ReadCardSerial())
  {
    return;
  }

  Serial.print(F("The NUID tag is: "));
  String nuid = getNUID(rfid.uid.uidByte, rfid.uid.size);
  Serial.println(nuid);
  Serial.println();

  info();
  //write(rfid, "Anthony", 1);
  //write(rfid, "DI STEFANO", 14);
/*
  Serial.println("Result: ");
  Serial.println(read(rfid, 10));
  Serial.println(read(rfid, 11));
  Serial.println(read(rfid, 12));*/

  //writeAllToBlocks(rfid, "A very long text to be able to test");

  rfid.PICC_HaltA();      // Halt PICC
  rfid.PCD_StopCrypto1(); // Stop encryption on PCD
  
  delay(300000);
}

/**
 * Helper routine to dump a byte array as hex values to Serial. 
 */
void info()
{
  rfid.PICC_DumpToSerial(&(rfid.uid));
}

String getNUID(byte *buffer, byte bufferSize)
{
  String nuid = "";

  for (byte i = 0; i < bufferSize; i++)
  {
    nuid += buffer[i] < 0x10 ? " 0" : " ";
    nuid += String(buffer[i], HEX);
  }

  nuid.toUpperCase();
  nuid.trim();

  return nuid;
}

bool auth(MFRC522 rfid, int block)
{
  //Serial.println("Authenticating...");

  MFRC522::MIFARE_Key key;
  for (byte i = 0; i < 6; i++)
    key.keyByte[i] = 0xFF;

  MFRC522::StatusCode status = rfid.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_B, block, &key, &(rfid.uid));

  if (status != MFRC522::STATUS_OK)
  {
    Serial.print(F("PCD_Authenticate() failed: "));
    Serial.println(rfid.GetStatusCodeName(status));
    return false;
  }

  //Serial.println(F("PCD_Authenticate() success"));
  return true;
}

void writeAllToBlocks(MFRC522 rfid, char content[]) {
  Serial.println(F("cut string"));
  int maxSize = 16;
  int contentLength = strlen(content);
  int partsCount = ceil(contentLength / maxSize);
  String result[partsCount + 1];
  
  int currentBockNumber = 0;

  for(int i = 0;i < contentLength; i++){
    if(i > 0 && i % maxSize == 0) {
      currentBockNumber++;
    }
  
    result[currentBockNumber] += content[i];
  }

int startBlock = 10;
  for(int i = 0; i < partsCount + 1; i++) {
      Serial.print(startBlock);
      Serial.print(": ");
      Serial.println(result[i]);

      write(rfid, result[i], startBlock);
      startBlock++;
      delay(200);
  }
}

void write(MFRC522 rfid, String content, int block)
{
  Serial.print("Writing ");
  Serial.print(block);
  Serial.print(": ");
  Serial.println(content);

  byte buffer[34];
  byte len;

  content.toCharArray((char *)buffer, 30);
  if (!auth(rfid, block))
  {
    return;
  }

  MFRC522::StatusCode status = rfid.MIFARE_Write(block, buffer, 16);
  if (status != MFRC522::STATUS_OK)
  {
    Serial.print(F("MIFARE_Write() failed: "));
    Serial.println(rfid.GetStatusCodeName(status));
    return;
  }
  else
    Serial.println(F("MIFARE_Write() success"));

  delay(200);


}

String read(MFRC522 rfid, int block)
{
  byte len;
  byte buffer[18];

  if (!auth(rfid, block))
  {
    return;
  }

  MFRC522::StatusCode status = rfid.MIFARE_Read(block, buffer, &len);
  if (status != MFRC522::STATUS_OK)
  {
    Serial.print(F("Reading failed: "));
    Serial.println(rfid.GetStatusCodeName(status));
    return;
  }

  delay(1);

  String result((char *)buffer);
  return result;
}
