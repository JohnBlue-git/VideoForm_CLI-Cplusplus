## VideoForm_CLI-Cplusplus

A is form project with MDI and video stream functions, which is supported by WinForm and OpenCV.

## Confriguration of coding
1.
MDI.cpp works as the main function in which MainForm object is allocated and run as form application.

where

MainForm class in MainForm.h

MyForm class in MyForm.h

2.
MainForm class can allocate multiple MyForm objects (allocated in Overhead.h : Base class) where each MyForm object can handle one video thread

, and MainForm object will be set as parent for each MyForm object.

(Note that, in this project, we create threads to allocate multiple MyForm objects.

Therefore, Base class in Overhead.h is used, and MyForm objects will be called though Application.Run in Base class.

Then we will have several UI threads: One is the thread of MainForm class, and others are the threads of MyForm class.)

3.
Additionally, template linkedlist class (in likedlist.h) is made and has been employed fully over this project.

## Declaration

In this project, several UI threads are created by creating Threads in MyForm class.

Though, it could be unnecessary to create several UI threads in one application, we have shown it is possible to thread a childern form.   

## Video Demonstration

There is a Demonstration_MDI_VideoForm.mp4 for demonstration
