#include "stdafx.h"

#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc,char* argv[])
{
  int result = 0;

  CascadeClassifier face_cascade;
  if(face_cascade.load("/Users/icy-joker/WorkSpace/SimpleUseCase/src/SimpleUseCase/Examples/CPlusPlus/OpenCV/FacialRecognitionDemo/resource/shared/opencv4/lbpcascades/lbpcascade_frontalface_improved.xml"))
  {
    VideoCapture cap(0);
    if(cap.isOpened())
    {
      Mat frame;
      while(cap.read(frame))
      {
        std::vector<Rect> faces;
        face_cascade.detectMultiScale(frame,faces,1.1,2,0,Size(300,300));

        if(faces.size() == 1)
        {
          std::for_each(faces.begin(),faces.end(),[&](Rect& face)
          {
            putText(frame,std::to_string(face.width)+","+std::to_string(face.height),Point(face.x,face.y),FONT_HERSHEY_SIMPLEX,1,Scalar(0,0,255),2);
            rectangle(frame,face,Scalar(255,0,0),2);

            Mat face_area = frame(face).clone();

            cv::resize(face_area,face_area,Size(112,112));

            imshow("Face Detection",face_area);
          });
        }

        //imshow("Face Detection",frame);

        waitKey(100);
      }

      cap.release();
    }
  }

  return result;
}
