import cv2
import numpy as np
img = cv2.imread('Image1.jpg')
bilateral_filtered_image = cv2.bilateralFilter(img, 5, 175, 175)
edge_detected_image = cv2.Canny(bilateral_filtered_image, 75, 200)
_, contours,_ = cv2.findContours(edge_detected_image, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
contour_list = []
for contour in contours:
    approx = cv2.approxPolyDP(contour,0.01*cv2.arcLength(contour,True),True)
    area = cv2.contourArea(contour)
    if len(approx)== 3:
        contour_list.append(contour)
        
        cv2.drawContours(img, contour_list,  -1, (255,0,0), 25)
        cv2.imshow('Objects Detected',img)
                              
