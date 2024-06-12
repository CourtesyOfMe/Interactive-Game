#include <Adafruit_CircuitPlayground.h>

const int maxRounds = 10; // Maximum rounds in the game
int sequence[maxRounds]; // Array to store the sequence
int currentRound = 0; // Current round number

void setup() {
  CircuitPlayground.begin();
  randomSeed(analogRead(0)); // Seed the random number generator
  startNewGame();
  Serial.begin(9600);
}

void loop() {
  // Show the sequence to the player
  showSequence();

  // Wait for player input and check if it's correct
  if (!getPlayerInput()) {
    // If the player makes a mistake, end the game
    gameOver();
    startNewGame();
  } else {
    // If the player is correct, go to the next round
    currentRound++;
    if (currentRound == maxRounds) {
      // If the player completes all rounds, they win
      youWin();
      startNewGame();
    }
  }
}

void startNewGame() {
  currentRound = 0;
  for (int i = 0; i < maxRounds; i++) {
    sequence[i] = random(0, 4); // Generate a random sequence (0-3 for 4 LEDs)
  }
  delay(1000); // Wait a second before starting
}

void showSequence() {
  for (int i = 0; i <= currentRound; i++) {
    int led = sequence[i];
    CircuitPlayground.setPixelColor(led, CircuitPlayground.colorWheel(led * 64));
    CircuitPlayground.playTone(440 + led * 220, 500); // Different tone for each LED
    delay(500);
    CircuitPlayground.clearPixels();
    delay(250);
  }
}

bool getPlayerInput() {
  for (int i = 0; i <= currentRound; i++) {
    while (true) {
      if (CircuitPlayground.readCap(1) > 1000) { // Check capacitive sensor A1
        delay(50); // Debounce
        while (CircuitPlayground.readCap(1) > 1000); // Wait for release
        if (sequence[i] == 3) { // LED 3 is triggered by A1
          flashLed(3);
          break;
        } else {
          return false;
        }
      } else if (CircuitPlayground.readCap(0) > 1000) { // Check capacitive sensor A2
        delay(50); // Debounce
        while (CircuitPlayground.readCap(0) > 1000); // Wait for release
        if (sequence[i] == 2) { // LED 2 is triggered by A2
          flashLed(2);
          break;
        } else {
          return false;
        }
      } else if (CircuitPlayground.readCap(2) > 1000) { // Check capacitive sensor A3
        delay(50); // Debounce
        while (CircuitPlayground.readCap(2) > 1000); // Wait for release
        if (sequence[i] == 1) { // LED 1 is triggered by A3
          flashLed(1);
          break;
        } else {
          return false;
        }
      } else if (CircuitPlayground.readCap(3) > 1000) { // Check capacitive sensor A4
        delay(50); // Debounce
        while (CircuitPlayground.readCap(3) > 1000); // Wait for release
        if (sequence[i] == 0) { // LED 0 is triggered by A4
          flashLed(0);
          break;
        } else {
          return false;
        }
      }
    }
  }
  return true;
}

void flashLed(int led) {
  CircuitPlayground.setPixelColor(led, CircuitPlayground.colorWheel(led * 64));
  CircuitPlayground.playTone(440 + led * 220, 300);
  delay(300);
  CircuitPlayground.clearPixels();
}

void gameOver() {
  for (int i = 0; i < 3; i++) {
    Serial.print("score= ");
    Serial.println(currentRound);
    CircuitPlayground.setPixelColor(0, 255, 0, 0);
    CircuitPlayground.setPixelColor(1, 255, 0, 0);
    CircuitPlayground.playTone(200, 500);
    delay(500);
    CircuitPlayground.clearPixels();
    delay(500);
  }
}

void youWin() {
  for (int i = 0; i < 5; i++) {
    Serial.print("YOU WIN! ");
    CircuitPlayground.setPixelColor(0, 0, 255, 0);
    CircuitPlayground.setPixelColor(1, 0, 255, 0);
    CircuitPlayground.playTone(880, 500);
    delay(500);
    CircuitPlayground.clearPixels();
    delay(500);
  }
}
