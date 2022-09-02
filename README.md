# Computer-vision-MPEG-and-Frame-Capture-with-Edge-Detection-
canny and sobel edge detection

In this code, we have built the opencv code for toggling between 3 filters: 1) 
the Canny edge detection system, 2) Sobel edge detection system, 3) and the 
normal window of the image. These 3 filters can be accessed by pressing 
‘c’,’s’,’n’ respectively. First, we read the frame from the webcam and then 
send it to the normal window and the video is shown by the use of webcam. 
After that the posix gettime function is used to get the start and end time of 
each frame and is stored in a variable. For every frame the required amount 
of time is stored in this variable. After that if the user presses input either ‘c’
or ’s’, then the average frame rate for the normal window with no filter is 
shown and then the frame is applied with the filter that user presses the key 
accordingly. If the user presses the key and the function of Sobel edge 
detection is called, the frame image is applied with Sobel edge detection filter 
and that video is shown with that filter through the webcam. And if the user 
presses another key then the frame is transformed to other filter accordingly. 
Every filter shows its own frame rate for that specific period of time for 
which the video is in motion. For the no filter video, we get the frame rate of 
around 25-27 fps if the camera is objected to good light or the fps do drop 
down. Similarly, the Sobel edge detection filter gains the frame rate of about 
17-22 fps if the video is in good lighting conditions. And the Canny edge 
detection filter gains the frame rate of 13-17 fps for video in good lighting 
conditions. Every filter has its own power of getting the frame rate for a live 
video capturing.
