Obstacle Avoiding Robotic Car

This project is an autonomous robotic car built using an Arduino microcontroller. The car uses an HC-SR04 ultrasonic sensor for obstacle detection, an L293D motor driver shield to control four DC motors, and an SG90 servo motor to rotate the sensor for scanning the environment. The robot navigates by moving forward, stopping when an obstacle is detected within 30 cm, scanning left and right, and turning toward the clearer path.

The project was developed from September 2022 to November 2022 as a demonstration of embedded systems and sensor-based navigation.

Features
- Obstacle Detection: Uses an HC-SR04 ultrasonic sensor to detect obstacles up to 200 cm away.
- Autonomous Navigation: Scans left and right with a servo-mounted sensor to choose the clearest path.
- Motor Control: Drives four DC motors using the L293D motor driver shield for smooth movement.
- Serial Monitoring: Outputs distance readings to the Serial Monitor for debugging.

Hardware Requirements
- Arduino Board: Arduino Uno or compatible microcontroller.
- Motor Driver Shield: Adafruit L293D Motor Shield (or compatible).
- Ultrasonic Sensor: HC-SR04 for obstacle detection.
- Servo Motor: SG90 for rotating the ultrasonic sensor.
- DC Motors: Four DC motors (with wheels) for a 4WD chassis.
- Power Supply:
  - 7.4V (e.g., two 18650 batteries) or 9-12V for the motor shield.
  - Separate 5V supply (USB or 9V battery) for the Arduino.
- Chassis: 4WD robotic car chassis.
- Miscellaneous: Jumper wires, breadboard (optional), and a stable power source.

Software Requirements
- Arduino IDE: Version 1.8.x or later.
- Libraries:
  - Adafruit Motor Shield V1 Library: For controlling the L293D motor shield.
  - NewPing Library: For efficient ultrasonic sensor readings.
  - Servo Library: Built into the Arduino IDE for servo control.

Install the libraries via the Arduino IDE Library Manager:
1. Go to Sketch > Include Library > Manage Libraries... .
2. Search for and install:
   - Adafruit Motor Shield (version 1.x).
   - NewPing by Tim Eckel.

Wiring
| Component             | Pin/Port Connection                    |
|-----------------------|----------------------------------------|
| HC-SR04 TRIG          | A4 on L293D shield                     |
| HC-SR04 ECHO          | A5 on L293D shield                     |
| HC-SR04 VCC           | 5V on L293D shield                     |
| HC-SR04 GND           | GND on L293D shield                    |
| SG90 Servo Signal     | Pin 10 on L293D shield                 |
| SG90 Servo VCC/GND    | Servo pins (SER1/SER2) on L293D shield |
| DC Motors (4)         | M1, M2, M3, M4 ports on L293D shield   |
| Motor Power Supply    | +M and GND terminals on L293D shield   |

Note: Ensure the Arduino is powered separately (via USB or a 9V battery) to avoid voltage drops from the motor supply.

Installation
1. Clone the Repository:
   bash
   git clone https://github.com/Arti21082003/obstacle-avoiding-robot.git

2. Open the Arduino Sketch:
   - Open 'Obstacle_Avoiding_Robot.ino' in the Arduino IDE.

3. Install Libraries:
   - Follow the Software Requirements section to install 'Adafruit Motor Shield V1' and 'NewPing' libraries.

4. Connect Hardware:
   - Wire the components as per the Wiring section.
   - Double-check connections to avoid short circuits.

5. Upload the Code:
   - Connect the Arduino to your computer via USB.
   - In the Arduino IDE, select your board (e.g., 'Arduino Uno') and port under 'Tools'.
   - Click 'Upload' to flash the code to the Arduino.

Usage
1. Power On:
   - Connect the motor power supply (7.4V or 9-12V) to the L293D shield.
   - Power the Arduino via USB or a separate battery.

2. Run the Robot:
   - The robot will start moving forward.
   - If an obstacle is detected within 30 cm, it will:
     - Stop and move backward briefly.
     - Scan left and right using the servo-mounted sensor.
     - Turn toward the direction with more clearance.
   - The robot resumes moving forward after turning.

3. Debugging:
   - Open the Serial Monitor ('Tools' > 'Serial Monitor') in the Arduino IDE at 9600 baud.
   - Monitor distance readings to verify sensor functionality.

Customization
- Collision Distance: Adjust 'COLLISION_DISTANCE' (default: 30 cm) in the code to change the obstacle detection threshold.
- Motor Speed: Modify 'MAX_SPEED' (default: 150) to adjust the speed (0-255).
- Servo Angles: Change 'lookRight()' and 'lookLeft()' servo angles (50° and 170°) for different scanning ranges.

Troubleshooting
- Library Errors:
  - Ensure 'AFMotor.h', 'NewPing.h', and 'Servo.h' are installed.
  ascended from source code to HTML:
  - Reinstall libraries via the Arduino IDE Library Manager.
- Motors Not Moving:
  - Check motor connections and power supply voltage.
  - Verify motor wiring on M1-M4 ports.
- Sensor Issues:
  - Confirm HC-SR04 TRIG and ECHO pins are correctly connected to A4 and A5.
  - Test sensor output in the Serial Monitor.
- Servo Not Rotating:
  - Ensure the SG90 servo is connected to pin 10 and powered correctly.
  - Use a standard SG90 (not continuous rotation).

 Acknowledgments
- Adafruit for the Motor Shield library and hardware documentation.
- Tim Eckel for the NewPing library.
- Arduino community for tutorials and support.

