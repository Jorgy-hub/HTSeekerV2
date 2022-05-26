# ifndef IRSeeker_h
# define IRSeeker_h
# define AC 0
# define DC 1

# include "Arduino.h"
# include "Wire.h"

struct IR_Result {
    byte Dir;
    byte Strength;
};

class HTSeekerV2 {
    private:
        /**
         * @brief 8 Bits = I2C Address.
         */
        static int Address = 0x10 / 2;
        /**
         * @brief Lecture Mode AC or DC.
         */
        static int Mode = AC;
    public:
        /**
         * @brief Function to Initialize and Construct the Seeker.
         * @param mode AC or DC 
         */
        static void Initialize( int mode = AC );  
        /**
         * @brief Function to set the Buffer Values from the Addresses.
         * @param Address DC or AC Addresses for values
         * @param buffer Buffer values to return
         */
        static void WireRead( byte Address, byte* buffer );  
        /**
         * @brief Function to transform the Raw Values.
         * @param buffer Buffer values to convert
         * @return IR_Result 
         */
        static IR_Result Results( byte* buffer );
        /**
         * @brief Main function to loop.
         * @return IR_Result 
         */
        static IR_Result Read();
        /**
         * @brief Function to check if it's the right sensor.
         * @return boolean 
         */
        static boolean Verify();
};

# endif