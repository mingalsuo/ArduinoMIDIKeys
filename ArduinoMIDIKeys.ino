/*
  Copyright © 2017 Markus Ingalsuo <markus.ingalsuo@gmail.com>
  
  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <MIDI.h>

// Created and binds the MIDI interface to the default hardware Serial port
MIDI_CREATE_DEFAULT_INSTANCE();

// Constants
const int pinC    = 2;
const int pinCMaj = 3;
const int pinD    = 4;
const int pinDMaj = 5;
const int pinE    = 6;
const int pinF    = 7;
const int pinFMaj = 8;
const int pinG    = 9;
const int pinGMaj = 10;
const int pinA    = 11;
const int pinAMaj = 12;
const int pinLed  = 13;
const int pinB    = 14;
const int pinCU   = 15;
const int pinDemo = 19;

const int noteC     = 0;
const int noteCMaj  = 1;
const int noteD     = 2;
const int noteDMaj  = 3;
const int noteE     = 4;
const int noteF     = 5;
const int noteFMaj  = 6;
const int noteG     = 7;
const int noteGMaj  = 8;
const int noteA     = 9;
const int noteAMaj  = 10;
const int noteB     = 11;
const int noteCU    = 12;

// Variables
int noteC_cur    = 0;
int noteCMaj_cur = 0;
int noteD_cur    = 0;
int noteDMaj_cur = 0;
int noteE_cur    = 0;
int noteF_cur    = 0;
int noteFMaj_cur = 0;
int noteG_cur    = 0;
int noteGMaj_cur = 0;
int noteA_cur    = 0;
int noteAMaj_cur = 0;
int noteB_cur    = 0;
int noteCU_cur   = 0;

int noteC_prev    = 0;
int noteCMaj_prev = 0;
int noteD_prev    = 0;
int noteDMaj_prev = 0;
int noteE_prev    = 0;
int noteF_prev    = 0;
int noteFMaj_prev = 0;
int noteG_prev    = 0;
int noteGMaj_prev = 0;
int noteA_prev    = 0;
int noteAMaj_prev = 0;
int noteB_prev    = 0;
int noteCU_prev   = 0;

int keyVelocity  = 127; //map() to analog input, later
int keyOctave    = 5;  //map() to analog input, later
int keyChannel   = 3;  //map() to analog input, later

int demoMode = 0;

void setup(void) {
  // Set pin modes
  pinMode(pinC,     INPUT);
  pinMode(pinCMaj,  INPUT);
  pinMode(pinD,     INPUT);
  pinMode(pinDMaj,  INPUT);
  pinMode(pinE,     INPUT);
  pinMode(pinF,     INPUT);
  pinMode(pinFMaj,  INPUT);
  pinMode(pinG,     INPUT);
  pinMode(pinGMaj,  INPUT);
  pinMode(pinA,     INPUT);
  pinMode(pinAMaj,  INPUT);
  pinMode(pinLed,   OUTPUT);
  pinMode(pinB,     INPUT);
  pinMode(pinCU,    INPUT);
  pinMode(pinDemo,  INPUT);
  
  MIDI.begin(MIDI_CHANNEL_OMNI);  // Listen to all incoming messages and hopefully merge
  Serial.begin(38400); // Debug, remove for production
}

void loop() {
  //Read MIDI messages from serial buffer and hopefully merge
  MIDI.read();
  
  //Visualize iteration
  digitalWrite(pinLed, LOW);
  
  //Get current note state
  noteC_cur    = digitalRead(pinC);
  noteCMaj_cur = digitalRead(pinCMaj);
  noteD_cur    = digitalRead(pinD);
  noteDMaj_cur = digitalRead(pinDMaj);
  noteE_cur    = digitalRead(pinE);
  noteF_cur    = digitalRead(pinF);
  noteFMaj_cur = digitalRead(pinFMaj);
  noteG_cur    = digitalRead(pinG);
  noteGMaj_cur = digitalRead(pinGMaj);
  noteA_cur    = digitalRead(pinA);
  noteAMaj_cur = digitalRead(pinAMaj);
  noteB_cur    = digitalRead(pinB);
  noteCU_cur   = digitalRead(pinCU);
  demoMode     = digitalRead(pinDemo);

  //Play the changed notes
  if (noteC_prev == LOW && noteC_cur == HIGH) { MIDI.sendNoteOn((noteC + keyOctave * 12), keyVelocity, keyChannel); }
  if (noteC_prev == HIGH && noteC_cur == LOW) { MIDI.sendNoteOn((noteC + keyOctave * 12), 0,           keyChannel); }
  
  if (noteCMaj_prev == LOW && noteCMaj_cur == HIGH) { MIDI.sendNoteOn((noteCMaj + keyOctave * 12), keyVelocity, keyChannel); }
  if (noteCMaj_prev == HIGH && noteCMaj_cur == LOW) { MIDI.sendNoteOn((noteCMaj + keyOctave * 12), 0,           keyChannel); }
  
  if (noteD_prev == LOW && noteD_cur == HIGH) { MIDI.sendNoteOn((noteD + keyOctave * 12), keyVelocity, keyChannel); }
  if (noteD_prev == HIGH && noteD_cur == LOW) { MIDI.sendNoteOn((noteD + keyOctave * 12), 0,           keyChannel); }

  if (noteDMaj_prev == LOW && noteDMaj_cur == HIGH) { MIDI.sendNoteOn((noteDMaj + keyOctave * 12), keyVelocity, keyChannel); }
  if (noteDMaj_prev == HIGH && noteDMaj_cur == LOW) { MIDI.sendNoteOn((noteDMaj + keyOctave * 12), 0,           keyChannel); }

  if (noteE_prev == LOW && noteE_cur == HIGH) { MIDI.sendNoteOn((noteE + keyOctave * 12), keyVelocity, keyChannel); }
  if (noteE_prev == HIGH && noteE_cur == LOW) { MIDI.sendNoteOn((noteE + keyOctave * 12), 0,           keyChannel); }

  if (noteF_prev == LOW && noteF_cur == HIGH) { MIDI.sendNoteOn((noteF + keyOctave * 12), keyVelocity, keyChannel); }
  if (noteF_prev == HIGH && noteF_cur == LOW) { MIDI.sendNoteOn((noteF + keyOctave * 12), 0,           keyChannel); }

  if (noteFMaj_prev == LOW && noteFMaj_cur == HIGH) { MIDI.sendNoteOn((noteFMaj + keyOctave * 12), keyVelocity, keyChannel); }
  if (noteFMaj_prev == HIGH && noteFMaj_cur == LOW) { MIDI.sendNoteOn((noteFMaj + keyOctave * 12), 0,           keyChannel); }

  if (noteG_prev == LOW && noteG_cur == HIGH) { MIDI.sendNoteOn((noteG + keyOctave * 12), keyVelocity, keyChannel); }
  if (noteG_prev == HIGH && noteG_cur == LOW) { MIDI.sendNoteOn((noteG + keyOctave * 12), 0,           keyChannel); }

  if (noteGMaj_prev == LOW && noteGMaj_cur == HIGH) { MIDI.sendNoteOn((noteGMaj + keyOctave * 12), keyVelocity, keyChannel); }
  if (noteGMaj_prev == HIGH && noteGMaj_cur == LOW) { MIDI.sendNoteOn((noteGMaj + keyOctave * 12), 0,           keyChannel); }

  if (noteA_prev == LOW && noteA_cur == HIGH) { MIDI.sendNoteOn((noteA + keyOctave * 12), keyVelocity, keyChannel); }
  if (noteA_prev == HIGH && noteA_cur == LOW) { MIDI.sendNoteOn((noteA + keyOctave * 12), 0,           keyChannel); }

  if (noteAMaj_prev == LOW && noteAMaj_cur == HIGH) { MIDI.sendNoteOn((noteAMaj + keyOctave * 12), keyVelocity, keyChannel); }
  if (noteAMaj_prev == HIGH && noteAMaj_cur == LOW) { MIDI.sendNoteOn((noteAMaj + keyOctave * 12), 0,           keyChannel); }

  if (noteB_prev == LOW && noteB_cur == HIGH) { MIDI.sendNoteOn((noteB + keyOctave * 12), keyVelocity, keyChannel); }
  if (noteB_prev == HIGH && noteB_cur == LOW) { MIDI.sendNoteOn((noteB + keyOctave * 12), 0,           keyChannel); }

  if (noteCU_prev == LOW && noteCU_cur == HIGH) { MIDI.sendNoteOn((noteCU + keyOctave * 12), keyVelocity, keyChannel); }
  if (noteCU_prev == HIGH && noteCU_cur == LOW) { MIDI.sendNoteOn((noteCU + keyOctave * 12), 0,           keyChannel); }
  
  //Copy the current note states to previous, for the next iteration 
  noteC_prev    = noteC_cur;
  noteCMaj_prev = noteCMaj_cur;
  noteD_prev    = noteD_cur;
  noteDMaj_prev = noteDMaj_cur;
  noteE_prev    = noteE_cur;
  noteF_prev    = noteF_cur;
  noteFMaj_prev = noteFMaj_cur;
  noteG_prev    = noteG_cur;
  noteGMaj_prev = noteGMaj_cur;
  noteA_prev    = noteA_cur;
  noteAMaj_prev = noteAMaj_cur;
  noteB_prev    = noteB_cur;
  noteCU_prev   = noteCU_cur;

  //Play a hip demo if so requested
  if (demoMode){
    for (int i=48; i <= 83; i++){
      MIDI.sendNoteOn(i, 127, keyChannel);
      delay(150);
      MIDI.sendNoteOn(i, 0, keyChannel);
    }
  }

  digitalWrite(pinLed, HIGH);
}