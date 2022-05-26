// We include the Seeker Library.
#include "HTSeeker.h"

// We create the Seeker Class.
HTSeeker Seeker;

void setup() {
    // We Initialize the Seeker by Setting the Current Mode.
    Seeker.Initialize(AC);
    Serial.begin(115200);
};

void loop(){
    // We read the Values.
    IR_Result SeekerResult = Seeker.Read(); 
    byte Direction = SeekerResult.Direction;
    byte Strength = SeekerResult.Strength;

    // Printing Values
    Serial.println();
    Serial.println("Direction | Strength");
    Serial.print(Direction);
    Serial.print(" | ");
    Serial.print(Strength);
};