  Simple sketch to manually test 3D touch/BL touch XXtouch sensor using arduino
  consisting on a servo or servo-like controlled coil as effector, 
  controlled by servo library on ìn 9
  and a position sensor (limit switch, optical, etc), connected to analog pin A0,
  to deploy the probe open serial terminal and send a "1", then touch manually the probe
  when probe detects the touch, the onboard led (if using arduino UNO) will be toggled
  and the probe will be retracted. Then you can repeat the test sending "1" again.
  To retract with code, just send a "0" with the terminal
  also you can see in the serial monitor the analog reading of the probe pin so you can know
  if it is 3v3 or 5v logic (typ. are 5v, but on some 3d printer boards you will need to convert it to 3v3)