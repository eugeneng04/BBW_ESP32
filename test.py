import serial, time

ser = serial.Serial("/dev/tty.usbserial-564E0556751", baudrate = 9600)
time.sleep(2)
while True:
    ser.write('3.3'.encode())
    print("turning led on")
    time.sleep(1)

    ser.write('0'.encode())
    print("turning led off")
    time.sleep(1)