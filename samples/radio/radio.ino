#include <VirtualWire.h>

int emiter = 12;
int receiver = 11;

void setup() {
  Serial.begin(9600);
  vw_setup(2000); // initialisation de la bibliothèque VirtualWire à 2000 bauds
  vw_rx_start();

  pinMode(13, OUTPUT);

  Serial.println("Starting...");

  blink();
}

void loop() {
  receive();
}

void send() {
  Serial.println("Send");
  
  byte paquet[27];
  strcpy(paquet, "Hello World!"); // Préparation du paquet
  
  vw_send(paquet, 27); // Envoi du paquet
  
  vw_wait_tx(); // Attente de la fin de l'envoi
}

void receive() {
  byte message[VW_MAX_MESSAGE_LEN];
  byte taille_paquet = VW_MAX_MESSAGE_LEN;
  
  Serial.println("Waiting for message...");
  Serial.println(VW_MAX_MESSAGE_LEN);
  
  vw_wait_rx(); // On attend de recevoir quelque chose
  
  if (vw_get_message(message, &taille_paquet)) { // Réception du paquet
    blink();
    // Le paquet reçu est correct, on peut le traiter
    // A ce stade "taille_paquet" contient la taille du paquet de données reçu
    Serial.println("Receiving a message...");
    Serial.println((char*) message);
  }
}

void blink() {
  digitalWrite(13, HIGH);
  delay(200);
  digitalWrite(13, LOW);
  delay(200);
  digitalWrite(13, HIGH);
  delay(200);
  digitalWrite(13, LOW);
  delay(200);
}
