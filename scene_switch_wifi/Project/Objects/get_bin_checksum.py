sum = 0;
with open("HC-MCU-XBR.bin","rb") as f:
    while True:
            current_byte = f.read(1)
            sum += current_byte[0]
            print(hex(current_byte[0]))
            print(hex(sum))