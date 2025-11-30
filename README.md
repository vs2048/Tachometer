# Tachometer
A tachometer that uses any type of sensor that sends a pulse once a revolution.

I used SparkFun line following sensor and a piece of white tape on the drill chuck. As the tachometer detects pulses it continuously calibrates. It can output to a standard 16x2 LCD or this can be used as a library in larger projects.

Use the following sensor or similar:
https://www.sparkfun.com/products/11769

A fun side project was measuring the speed of a three speed drill and observing the powertrain losses. In the 1:1 gear the drill spun at almost exactly the rated speed. In gear "two" the drill only got up to the 95% of the rated speed and in gear "one" it only got up to 85% of the rated speed. This confirms two things. First, the universal truth of gearboxes that the farther your ratio is from 1:1 the higher the losses. At 1:1 a gearbox is typically almost 100% efficient. Second, the drill manufacturer calculated the speed ratings by multiplying motor speed by the ratio without accounting for losses. At 1:1 this works but in the real world at the higher reduction gearbox losses bog down the motor a bit so it cannot achieve the ratings.

This was created to measure the speed of a motor controlled by https://github.com/vs2048/MotorTestStand
