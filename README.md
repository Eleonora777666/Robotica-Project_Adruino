# 🤖 Robotica-Project_Adruino

## Project Description
This project implements an interactive function for an Arduino-based educational robot kit.
The main objective is to play **different sounds** (melodies or tones) upon each press of the **yellow button** mounted on the main control board.

## Components Used
* Robot Control Board (Arduino-compatible).
* Yellow Push Button (Assumed to be connected to digital pin **D2**).
* Built-in Piezo Buzzer for sound output (Assumed to be connected to pin **8**).
* Servo Motor (For potential future expansion).

## How It Works
The Arduino sketch uses a counter to track the number of presses on the yellow button.
1.  **First Press:** Plays a short, simple tone.
2.  **Second Press:** Plays a long, high-pitched tone.
3.  **Third Press:** Plays a short melody.
4.  **Fourth Press:** The counter resets, and the first tone is played again.

## Setup and Run
1.  Upload the sketch file (`.ino`) to the board using the Arduino IDE.
2.  Ensure the yellow button and the piezo buzzer are connected according to the pins specified in the code.
3.  Press the yellow button to cycle through the different sounds.
