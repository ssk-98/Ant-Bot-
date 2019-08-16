# import the necessary packages
from picamera.array import PiRGBArray
from picamera import PiCamera
import time
import cv2
import cv2.aruco as aruco
 
# initialize the camera and grab a reference to the raw camera capture
camera = PiCamera()
camera.resolution = (640, 480)
camera.framerate = 64
rawCapture = PiRGBArray(camera, size=(640, 480))
 
# allow the camera to warmup
time.sleep(0.1)
idlist = []
run = True
 
# capture frames from the camera
for frame in camera.capture_continuous(rawCapture, format="bgr", use_video_port=True):
	# grab the raw NumPy array representing the image, then initialize the timestamp
	# and occupied/unoccupied text
    if run:
        image = frame.array

            

            #operations on frame

        gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
        aruco_dict = aruco.Dictionary_get(aruco.DICT_7X7_1000)
            
        parameters = aruco.DetectorParameters_create()
        corners, ids, _ = aruco.detectMarkers(gray,aruco_dict , parameters = parameters)
        font = cv2.FONT_HERSHEY_SIMPLEX
        cv2.putText(gray, "id = "+str(ids), (100,200), font, 1, (255,0,255), 2, cv2.LINE_AA)
            
     
            # show the frame
        cv2.imshow("Frame", gray)
        key = cv2.waitKey(1) & 0xFF
     
            # clear the stream in preparation for the next frame
        rawCapture.truncate(0)
        if len(corners):
            for i in range(len(corners)):
                if ids[i][0] not in idlist:
                    idlist.append(ids[i][0])
                    if len(idlist) == 4:
                        run = False
       
            # if the `q` key was pressed, break from the loop
    else:
        break




cv2.destroyAllWindows()
print(idlist)
