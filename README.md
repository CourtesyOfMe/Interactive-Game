# Game Design
This is a version of Simon Says that I created for ENGR 103, you must reapeat the sequence that flashes by touching the corresponding capacitance sensors as the sector that lights up

### Inputs
You will being by using the left button to select game difficulty, then hit the right button to begin playing. After that you will repeat the sequence as it adds one extra light until you either beat the game or mess up the sequence. Then you will go back to choosing a difficulty and begin it all again. You can also flip the switch to enable silent mode.


### Game Design Doc
Matchy Color Extraganza:
-LEDs will be separated into 4 sections
-Capacitance sensors will be used as “buttons” to hit the corresponding LED section
-You will have infinite time to hit the correct pattern
-After every round one more section will light up in sequence
-You will get one point per correct sequence
- There will be multiple difficulties to choose from before beginning the game
- There will be a mode that will disable the sounds from being played that gets turned on by the switch


Input/Output:
- Serial will show score 
- Capacitance sensors will count as “hit” when reaching 800 or higher
- Right button will start game and reset game
- Left button will be used to select difficulty before beginning
- Switch will enable silent mode
