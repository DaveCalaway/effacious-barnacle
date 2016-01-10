*Powering your DC motors:*

You can't run motors off of a 9V battery so don't even waste your time/batteries!

The DC motors are powered off of a 'high voltage supply' and NOT the regulated 5V. Don't connect the motor power supply to the 5V line.


There are two places you can get your motor 'high voltage supply' from. One is the DC jack on the Arduino board and the other is the 2-terminal block on the shield that is labeled EXT_PWR.
https://goo.gl/AziEpn

**Single DC power supply for the Arduino and motors**, simply plug it into the DC jack on the Arduino or the 2-pin PWR_EXT block on the shield. Place the power jumper on the motor shield.


**Arduino powered off of USB and the motors powered off of a DC power supply***, plug in the USB cable. Then connect the motor supply to the PWR_EXT block on the shield. Do not place the jumper on the shield. 


**2 seperate DC power supplies for the Arduino and motors**. Plug in the supply for the Arduino into the DC jack, and connect the motor supply to the PWR_EXT block. Make sure the jumper is removed from the motor shield.

Either way, if you want to use the DC motor/Stepper system the motor shield LED should be lit indicating good motor power.


Status: beta

*DaveCalaway*
