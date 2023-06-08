// Broches de contrôle du four à micro-ondes
const int boutonStartPin = 2;
const int boutonStopPin = 3;
const int relaisPin = 4;
const int buzzerPin = 5;

// Durée en secondes pour chauffer la nourriture
const int dureeChauffage = 30;

void setup() {
  // Initialisation des broches
  pinMode(boutonStartPin, INPUT);
  pinMode(boutonStopPin, INPUT);
  pinMode(relaisPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  
  // Désactiver le relais et le biiiiip au démarrage
  digitalWrite(relaisPin, LOW);
  digitalWrite(buzzerPin, LOW);
}

void loop() {
  // Vérifier si le bouton de démarrage est enfoncé
  if (digitalRead(boutonStartPin) == HIGH) {
    // Activer le relais pour démarrer le micro-ondes
    digitalWrite(relaisPin, HIGH);
    
    // Sonner le buzzer pour indiquer que le micro-ondes est en marche
    digitalWrite(buzzerPin, HIGH);
    delay(500);
    digitalWrite(buzzerPin, LOW);
    
    // Chauffer pendant la durée spécifiée
    delay(dureeChauffage * 1000);
    
    // Désactiver le relais et le buzzer lorsque le temps est écoulé
    digitalWrite(relaisPin, LOW);
    digitalWrite(buzzerPin, LOW);
  }
  
  // Vérifier si le bouton d'arrêt est enfoncé
  if (digitalRead(boutonStopPin) == HIGH) {
    // Désactiver le relais et le buzzer
    digitalWrite(relaisPin, LOW);
    digitalWrite(buzzerPin, LOW);
  }
}
