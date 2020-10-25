The proposed mask and temperature detection control system uses the combination of deep learning and sensor technologies that open the gate only if the system detects if the
person is wearing masks and if their body temperature is less than a set threshold value. There are two phases of the face mask detection process, Training mask detection being
the first phase, & and applying it using the computer vision technique is the second phase. In the first part, we need to load the data set which has two classes with_mask and 
without_mask respectively and train the face mask classifier in a Tensorflow background using the MobileNetV2 which is a 53 layer convolution neural network. Phase two of the mask
detection starts with loading the model which was trained earlier. Next, we need to detect faces in video stream which can be done using the Haar cascade classifier package 
available in computer vision, The Region of Interest(ROI) (i.e) detected face is extracted, and face mask classifier is applied to each ROI to determine if the person is wearing
a mask or not. If the person detected is wearing a mask a binary bit ‘1’ is sent to the Arduino from python via the serial port using pyserial, Similarly, a binary bit ‘0’ is 
sent if the person is not wearing a mask. A Contactless Temperature Sensor (MLX90614ESF) to measure the body temperature at the entrance. The MLX90614ESF is connected to the
Arduino and temperature is displayed in a 16*2 LCD display. If the system detects the presence of a mask and the temperature measured by the sensor is less than 100.4o C then 
the control system will open the gate, thus allowing the person to enter. A  servo motor is connected to the Arduino which acts as a gate and is rotated by 90o when the set 
conditions satisfy.
