# Tachometer
A tachometer that uses a line following sensor.

This is a simple tachometer that uses a SparkFun line sensor to count the time between revolutions on a shaft. Tape a black line onto a shaft and aim the sensor at it and this library will calculate the rotational velocity of the shaft. Measured speed is written to a 16x2 segment LCD or the tach library can be used independantly.

Use the following sensor or similar:
https://www.sparkfun.com/products/11769

A fun side project was meauring the speed of a three speed drill and observing the powertrain losses. In the 1:1 gear the drill spun at almost exactly the rated speed. In gear "two" the drill only got up to the 95% of the rated speed and in gear "one" it only got up to 85% of the rated speed. This confirms two things. First, the universal truth of gearboxes that the farther your ratio is from 1:1 the higher the losses. At 1:1 a gearbox is typically almost 100% efficient. Second, the drill manufacturer calculated the speed ratings by multiplying motor speed by the ratio without acounting for losses. At 1:1 this works but in the real world at the higher reduction gearbox losses bog down the motor a bit so it cannot acheieve the ratings.

This was created to measure the speed of a motor controlled by https://github.com/vs2048/MotorTestStand
