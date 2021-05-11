#pragma once
//#include "stdafx.h"
// C++
#include <iostream>// for basic i/o
#include <iomanip>// for fixed and setprecision
#include <stdexcept>// for deermined exception
#include <string>
// file
#include <fstream>
#include <ctime>
#include "stdio.h"
#include <io.h>
// opencv
#include "opencv2\opencv.hpp"



// 需要先宣告,為了將class LinkedList設成class ListNode的friend
template<class T>
class LinkedList;    

template<class T>
class ListNode {
private:
	//public:
		// data
	T data;
	ListNode* next;
	// constructor
	ListNode(const ListNode& copy) {}
	// operator
	ListNode& operator=(const ListNode& copy) { return *this; };
public:
	// constructor
	ListNode() :data(0), next(0) {};
	ListNode(T a) :data(a), next(0) {};
	~ListNode() {}
	// friend class
	friend class LinkedList<T>;
	friend class StringList;
};

template<class T>
class LinkedList {
protected:
	//public:
	// int size;	              // size是用來記錄Linked list的長度, 非必要
	ListNode<T>* first;
	ListNode<T>* end;
public:
	// constructor
	LinkedList() :first(0), end(0) {};
	LinkedList(const LinkedList& copy);
	virtual ~LinkedList();
	// operator
	LinkedList& operator=(const LinkedList& copy);
	T& operator[](const unsigned int x);
	// function
	bool isEmpty();
	void PrintList() const;
	void Push_front(T x);
	void Push_back(T x);
	T Pop_front();
	void Delete(const unsigned int x);         // clear the x th in the list
	void Clear();                              // clear entire list
	// exception class
	class bad_empty : public std::logic_error
	{
	public:
		explicit bad_empty(const std::string & s = " ") :std::logic_error(s + ", Empty error in List object\n") {};
		virtual ~bad_empty() throw() {}
	};
	class bad_index : public std::logic_error
	{
	private:
		int index; // bad index value
	public:
		explicit bad_index(int ix = 0, const std::string & s = " ") :index(ix), std::logic_error(s + ", Index error in List object\n") {};
		int get_index() const { return index; }
		virtual ~bad_index() throw() {}
	};
};

template<class T>
LinkedList<T>::LinkedList(const LinkedList<T>& copy) {
	ListNode<T>* current = copy.first;
	while (current != 0) {
		LinkedList<T>::Push_back(current->data);
		current = current->next;
	}
}

template<class T>
LinkedList<T>::~LinkedList() {
	this->LinkedList<T>::Clear();
}

template<class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& copy) {
	if (&copy == this) {
		return *this;
	}
	this->Clear();
	this->LinkedList<T>::LinkedList(copy);
	return *this;
}

template<class T>
T& LinkedList<T>::operator[](const unsigned int x) {
	ListNode<T>* current = first;             // point to first
	unsigned int i = 0;
	while (i < x) {
		if (first == 0) {                     // id list list is empty
			throw bad_empty("[] operation");
		}
		current = current->next;              // point to ? th in the list
		i++;
		if (current == 0 || x < 0) {          // bad index
			throw bad_index(x, "[] operation");
		}
	}
	return current->data;
}

template<class T>
bool LinkedList<T>::isEmpty() {
	if (first == 0) {                      // if list is empty
		return true;
	}
	else {
		return false;
	}
}

template<class T>
void LinkedList<T>::PrintList() const {
	if (first == 0) {                         // if list is empty
		throw bad_empty("PrintList()");
	}
	ListNode<T>* current = first;             // point to first
	while (current != 0) {                    // execute to last NULL
		if (typeid(T) == typeid(double)) {
			std::cout << std::fixed << std::setprecision(3) << current->data << " ";
		}
		else if (typeid(T) == typeid(int) || typeid(T) == typeid(float) || typeid(T) == typeid(std::string)) {
			std::cout << current->data << " ";
		}
		current = current->next;
	}
	std::cout << std::endl;
}

template<class T>
void LinkedList<T>::Push_front(T x) {
	ListNode<T>* newNode = new ListNode<T>(x); // new node
	newNode->next = first;                     // link first to back of new node
	if (first == 0 && end == 0) {              // indicate list is empty now
		first = newNode;                       // first and end are all point to new node
		end = newNode;
	}
	else {                                     // new node become first pointer
		first = newNode;
	}
}

template<class T>
void LinkedList<T>::Push_back(T x) {
	ListNode<T>* newNode = new ListNode<T>(x); // new node
	if (first == 0 && end == 0) {              // indicate list is empty now
		first = newNode;                       // fist and end are all point to new node
		end = newNode;
	}
	else {                                     // link new node to end pointer
		end->next = newNode;
		end = newNode;
	}
}

template<class T>
T LinkedList<T>::Pop_front() {
	ListNode<T>* current = first;
	T out = current->data;
	if (current == 0) {                        // list is empty
		throw bad_empty("pop operation");
	}
	first = first->next;
	delete current;
	current = 0;
	return out;
}

template<class T>
void LinkedList<T>::Delete(const unsigned int x) {
	ListNode<T>* current = first;
	ListNode<T>* previous = 0;
	unsigned int i = 0;
	while (i < x) {
		if (first == 0) {
			throw bad_empty("Delete(const unsigned int x)");
		}
		previous = current;
		current = current->next;
		i++;
		if (current == 0 || x < 0) {
			throw bad_index(x, "Delete(const unsigned int x)");
		}
	}
	if (current == first) {             // if the node that are going to be deleted is the first one
		first = current->next;          // let first point to next node firstly
		// !!! delete and prevent bug
		delete current;              
		current = 0;              
	}
	else {                              // other deleting condition (note that previous node is not NULL)
		previous->next = current->next;
		// !!! delete and prevent bug
		delete current;
		current = 0;
	}
}

template<class T>
void LinkedList<T>::Clear() {
	ListNode<T>* current;
	while (first != 0) {
		current = first;
		first = first->next;
		// !!! delete and prevent bug
		delete current;
		current = 0;
	}
	end = 0;                           // !!! remembr to 0 pointer
}

// derived class
class StringList : public LinkedList<std::string>
{
public:
	// constructor
	StringList() :LinkedList() {};
	StringList(const StringList& copy) :LinkedList(copy) {};
	virtual ~StringList() {};
	// operator
	//
	// function
	std::string ConnectAllString();
};

std::string StringList::ConnectAllString() {
	if (first == 0) {
		std::cout << "List is empty.\n";
		return "ListEmpty";
	}
	ListNode<std::string>* current = first;
	std::string allString;
	while (current != 0) {
		allString = allString + current->data + "\n";
		current = current->next;
	}
	return allString;
}


// the data struct that we need
struct ALLdata {
public:
	//// constructor
	ALLdata(std::string name) {
		// MyForm name
		form_name = name;
		// speed
		speed = 1;
		//
		frameCount = 0;
		framePos = 0;
		fps = 1;
	}

	ALLdata(const ALLdata& copy) {
		// name of MyForm
		form_name = copy.form_name;
		video_path = copy.video_path;
		video_filename = copy.video_filename;
		// frame
		frame = copy.frame;
		cap = copy.cap;
		fps = copy.fps;
		// zoom
		imagen = copy.imagen;
		zoom_W = copy.zoom_W;
		zoom_H = copy.zoom_H;
		mousex = copy.mousex;
		mousey = copy.mousey;
		time = copy.time;
		prev = copy.prev;
		// video speed
		speed = copy.speed;
		//
		frameCount = copy.frameCount;
		framePos = copy.framePos;
			
	}

	~ALLdata() {}

	ALLdata& operator=(const ALLdata& copy) {
		if (&copy == this) {
			return *this;
		}
		this->ALLdata::ALLdata(copy);
		return *this;
	}
	
	//// var
	// for MyForm name
	std::string form_name;
	std::string video_path;
	std::string video_filename;
	// for frame
	cv::Mat frame;
	cv::VideoCapture cap;
	double fps;
	int speed;
	double frameCount;
	double framePos;
	// for zoom
	cv::Mat imagen;
	int zoom_W, zoom_H;
	int mousex, mousey;
	int time;
	LinkedList<cv::Mat> prev;
};

