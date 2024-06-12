# Game Design
This is a version of Simon Says that I created for ENGR 103, you must reapeat the sequence that flashes by touching the corresponding capacitance sensors to the LED that lights up.

### Inputs
There are four sensors that are used for this game. Sensors A4, A5, A6, and A7 are used corresponding with the 4 lights that are also in a row.


### Game Design Doc
Matchy Color Extraganza:
-4 LEDs
-Capacitance sensors will be used as “buttons” to hit the corresponding LED
-You will have infinite time to hit the correct pattern
-After every round one more section will light up in sequence
-You will get one point per correct sequence
- There will be a maximum of 10 rounds before you win


Input/Output:
- Serial will show score at the end
- Capacitance sensors will count as “hit” when reaching 1000 or higher
