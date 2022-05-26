# HiTechnic NXT IRSeeker V2

## Introduction

<img src="https://modernroboticsinc.com/wp-content/uploads/2019/03/0001388_hitechnic-nxt-irseeker-v2.png" align="right" width="30%"/>

The NXT IRSeeker V2 (Version 2) is a multi-element infrared detector that detects   infrared signals from sources such as the HiTechnic IRBall soccer ball, infrared  remote controls, and sunlight. It is perfect for robot soccer competitions.

The IRSeeker V2 operates in 2 selectable modes:

Modulated (AC) Mode – The sensor will detect modulated IR signals such as those from the HiTechnic IRBall or some IR remote controls. In Modulated mode, the sensor will filter out most other IR signals to decrease interference from lights and the sunshine for example. The sensor is tuned to square wave signals at 1200Hz.

Un-modulated (DC) Mode – The sensor will detect unmodulated IR signals such as older style IRBalls or sunlight.

The IRSeeker V2 uses advanced digital signal processing techniques to filter the signals received and select only the signals required. A newly designed housing with a constant radius curved end cap increases directional performance by minimizing the distortion of light signals entering the sensor.

The IRSeeker direction values are shown here with 1 indicating the infrared target is left and behind, 5 if the target is directly ahead and 9 if the target is to the right and behind. A value of 0 is returned if no signal is detected.


## Installation

* To use this library, first download the library file, paste it into the \Arduino\libraries directory, then open the examples folder and run the demo in the folder.
* Another method to install is directly from the Arduino IDE then go to Sketch then Include Library then Add .ZIP Library and search for the compressed library.

## Methods
```cpp
/**
 * @fn Initialize
 * @brief Function to Initialize and Construct the Seeker.
 * @param mode AC or DC 
 */
void Initialize( int mode = AC ); 
/**
 * @fn Read
 * @brief Main function to loop.
 * @return IR_Result 
 */
IR_Result Read();
```

## History
* 2022/05/26 - Version 0.0.1 Released.

## Credits

Written by Uraraka-Chan(jorgy@saya.gg), 2022.