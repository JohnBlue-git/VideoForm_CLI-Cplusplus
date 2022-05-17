## Videoform_CLI-Cplusplus

A is form project with MDI and video stream functions, which is supported by WinForm and OpenCV.

## Confriguration of coding

MDI.cpp works as the main function in where MainForm object is allocated and run as an form application.

MainForm class can dynamically allocate multiple MyForm objects in which each MyForm object can handle one video thread

, and MainForm object will be set as parent for each MyForm object. (However, ...)

Additionally, template linkedlist class is made and has been employed fully over this project.
