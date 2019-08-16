import serial
node_counter=0
temp=0
run = True

ser=serial.Serial('/dev/ttyUSB0',baudrate=9600)

while(run):
    temp=0
    if node_counter==0:
        ser.write('f'.encode())
        ser.flushInput()
        temp=ser.readline()
        print(temp)
        node_counter+=temp
    
    elif( node_counter==1):
        ser.write('l'.encode())
        ser.flushInput()
        for i in range(3):
            ser.write('f'.encode())
            ser.flushInput()
            temp=ser.readline()
            print(temp)
            node_counter+=temp
        ser.flushInput()
        
    elif node++counter==4:
        ser.write('u'.encode())
        ser.flushIput()
        ser.flushOutput()
        ser.write('f'.encode())
        ser.flushIput()
        temp=ser.readline()
        print(temp)
        node_counter+=temp
    elif node_counter==5:
        for i in range(5):
            ser.write('f'.encode())
            ser.flushInput()
            temp=ser.readline()
            print(temp)
            node_counter+=temp
    elif node_counter==10:
        ser.write('u'.encode())
        ser.flushInput()
        ser.flushOutput()
        ser.write('f'.encode())
        temp=ser.readline()
        print(temp)
        node_counter+=temp
    
    elif node_counter==11:
        for i in range(2):
            ser.write('f'.encode())
            ser.flushInput()
            temp=ser.readline()
            print(temp)
            node_counter+=temp
            
    elif node_counter==13:
        ser.write('r'.encode())
        ser.flushOutput()
        ser.write('f'.encode())
        ser.flushInput()
        temp=ser.readline()
        print(temp)
        node_counter+=1
        
            
        
    
    
            
            
            
    


