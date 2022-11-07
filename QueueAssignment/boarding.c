/*
	Name: Max Fyall
	Matric Number: 180011724
	Module Code: AC21008
*/

#include "boarding.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// initialise a new Boarding Queue
// Parameters:
// qPtr - will receive a pointer to a new Double Ended Queue
int createBoardingQueue(BoardingQueue **qPtr)
{
	// checks if the queue pointer is empty
	if(qPtr == NULL)
	{
		return INVALID_INPUT_PARAMETER;
	}
	// checks if the queue has already been initialsed
	if (*qPtr != NULL)
	{
		return INVALID_INPUT_PARAMETER;
	}
	// Allocating memory for a new queue
	(*qPtr) = (BoardingQueue*)myMalloc(sizeof(BoardingQueue));

	// Checks for any errors after allocating memory
	if ((*qPtr) == NULL)
	{
		return MEMORY_ALLOCATION_ERROR;
	}

	// initialse head and tail of the new queue to null
	(*qPtr)->head = NULL;
	(*qPtr)->tail = NULL;

	return SUCCESS;
}

// add a new passenger to the tail/end of the queue
// Parameters:
// qPtr - a pointer to the Double Ended Queue
// name - stores the name of the passenger
// passportNumber - stores the passenger's passport number
// seatNumber - stores the passenger's seat number
int addPassenger(BoardingQueue *qPtr, char name[], double passportNumber, int seatNumber)
{
	// check the variables are valid
	if(qPtr == NULL || name == NULL || passportNumber == 0 || seatNumber == 0)
	{
		return INVALID_INPUT_PARAMETER;
	}

	// checks if the variables are within their ranges defined in the documentation
	if (strlen(name) > 29 || passportNumber > 88000 || passportNumber < 1 || seatNumber > 150 || seatNumber < 1)
	{
		return INVALID_INPUT_PARAMETER;
	}

	// create a new passenger to be added to the tail of the queue
	Passenger *newPassenger = (Passenger*)myMalloc(sizeof(Passenger));

	// checks if new passenger was allocated memory
	if(newPassenger == NULL)
	{
		return MEMORY_ALLOCATION_ERROR;
	}

	// initialise variables for the new passenger
	strncpy(newPassenger->name, name, 29);
	newPassenger->passportNumber = passportNumber;
	newPassenger->seatNumber = seatNumber;
	newPassenger->next = NULL;

	// checks if the queue is empty
	if(qPtr->head == NULL)
	{
		// if queue is empty, set the new passenger as
		// head and tail of the queue
		qPtr->head = newPassenger;
		qPtr->tail = newPassenger;
	}
	else // otherwise, i.e. the queue is not empty
	{
		// add the new passenger the tail of the queue
		// ensuring that the previous tail is connnected
		// to the new tail
		qPtr->tail->next = newPassenger;
		qPtr->tail = newPassenger;

	}

	return SUCCESS;
}

// add a new passenger to the head of the queue because they have priority
// Parameters:
// qPtr - a pointer to the Double Ended Queue
// name - stores the name of the passenger
// passportNumber - stores the passenger's passport number
// seatNumber - stores the passenger's seat number
int addPriorityPassenger(BoardingQueue *qPtr, char name[], double passportNumber, int seatNumber)
{
	// check the variables are valid
	if(qPtr == NULL || name == NULL || passportNumber == 0 || seatNumber == 0)
	{
		return INVALID_INPUT_PARAMETER;
	}

	// checks if the variables are within their ranges defined in the documentation
	if (strlen(name) > 29 || passportNumber > 88000 || passportNumber < 1 || seatNumber > 150 || seatNumber < 1)
	{
		return INVALID_INPUT_PARAMETER;
	}

	// create a new passenger to be added to the head of the queue
	Passenger *newPassenger = (Passenger*)myMalloc(sizeof(Passenger));

	// checks if new passenger was allocated memory
	if(newPassenger == NULL)
	{
		return MEMORY_ALLOCATION_ERROR;
	}

	// initialise variables for the new passenger
	strncpy(newPassenger->name, name, 29);
	newPassenger->passportNumber = passportNumber;
	newPassenger->seatNumber = seatNumber;
	newPassenger->next = NULL;

	// checks if queue is empty
	if(qPtr-> head == NULL)
	{
		// if queue is empty, set the new passenger as
		// head and tail of the queue
		qPtr->head = newPassenger;
		qPtr->tail = newPassenger;
	}
	else // otherwise, i.e. the queue is not empty
	{
		// add the new passenger the head of the queue
		// ensuring that the previous head is connnected
		// to the new head
		newPassenger->next = qPtr->head;
		qPtr->head = newPassenger;
	}

	return SUCCESS;
}

// removes a passenger from the head of the queue as they have been processed
// and are ready to board the plane
// Parameters:
// qPtr - a pointer to the queue
// p - stores the data of the passenger being removed
int removePassenger(BoardingQueue *qPtr, Passenger *p)
{
	// validate the queue pointer
	if (qPtr == NULL)
	{
		return INVALID_INPUT_PARAMETER;
	}

	// validate the passenger pointer
	if (p == NULL)
	{
		return INVALID_INPUT_PARAMETER;
	}

	// checks if the queue is empty, removing from an empty queue is not possible
	if (qPtr->head == NULL || qPtr->tail == NULL)
	{
		return INVALID_QUEUE_OPERATION;
	}

	// creates a temporary passenger variable to store the passenger to be deleted
	Passenger *passengerToRemove = qPtr->head;

	// stores the data of the passenger to be removed in the p variable
	strncpy(p->name, passengerToRemove->name, 29);
	p->passportNumber = passengerToRemove->passportNumber;
	p->seatNumber = passengerToRemove->seatNumber;
	p->next = passengerToRemove->next;

	// set the the new head
	qPtr->head = qPtr->head->next;

	// // clears the memory of the temporary variable
	free(passengerToRemove);

	return SUCCESS;

}

// get the details of the passenger at the head of the queue
// without removing them from the queue
// Parameters:
// qPtr - a pointer to the Queue
// p - will receive the details of the peeked passenger
int peekAtHeadPassenger(BoardingQueue *qPtr, Passenger *p)
{
	// validate the queue pointer
	if(qPtr == NULL)
	{
		return INVALID_INPUT_PARAMETER;
	}

	// validate the passenger pointer
	if (p == NULL)
	{
		return INVALID_INPUT_PARAMETER;
	}

	// checks if peekingf location is empty
	if (qPtr->head == NULL)
	{
		return INVALID_QUEUE_OPERATION;
	}

	// Stores the data of the passenger at the head in
	// the variables in p
	strncpy(p->name, qPtr->head->name, 29);
	p->passportNumber = qPtr->head->passportNumber;
	p->seatNumber = qPtr->head->seatNumber;
	p->next = qPtr->head->next;

	return SUCCESS;
}

// get the details of the passenger at the tail of the queue
// without removing them from the queue
// Parameters:
// qPtr - a pointer to the Queue
// p - will receive the details of the peeked passenger
int peekAtTailPassenger(BoardingQueue *qPtr, Passenger *P)
{
	// validate the queue pointer
	if(qPtr == NULL)
	{
		return INVALID_INPUT_PARAMETER;
	}

	// validate the passenger pointer
	if (P == NULL)
	{
		return INVALID_INPUT_PARAMETER;
	}
	// checks if peeking location is empty
	if (qPtr->tail == NULL)
	{
		return INVALID_QUEUE_OPERATION;
	}

	// Stores the data of the passenger at the head in
	// the variables in p
	strncpy(P->name, qPtr->tail->name, 29);
	P->passportNumber = qPtr->tail->passportNumber;
	P->seatNumber = qPtr->tail->seatNumber;
	P->next = qPtr->tail->next;

	return SUCCESS;
}

// empty the whole queue and free all the memory used
// Parameters:
// qPtr - a pointer to the Queue we want to free/empty
int clearBoardingQueue(BoardingQueue *qPtr)
{
	// checks the pointer is pointing to a valid queue
	if (qPtr == NULL)
	{
		return INVALID_INPUT_PARAMETER;
	}

	// while the queue is still not empty
	while(qPtr->head != NULL)
	{
		// get a pointer to the head of the queue
		Passenger *temp = qPtr->head;

		// move the current head to the next passenger down
		qPtr->head = qPtr->head->next;

		// free the current top of it's memory
		free(temp);
	}

	// free the queue itself once all the passengers have been freed
	free(qPtr);
	
	return SUCCESS;
}

// Extra Marks Method

// checks if the queue needs to be sorted
// Parameters:
// qPtr - a pointer to the queue
int checkSort(BoardingQueue *qPtr)
{
	// create pointers to move through the queue
	Passenger *current = qPtr->head;
	Passenger *afterCurrent = qPtr->head->next;

	// while the queue is not empty
	while(afterCurrent != NULL)
	{
		// check if the seat's numbers are not ordered
		if (current->seatNumber > afterCurrent->seatNumber)
		{
			return 1; // if so then return 1
		}

		// move to the next passengers in the queue
		current = current->next;
		afterCurrent = afterCurrent->next;
	}

	// if the queue does not need sorted then return 0
	return 0; 
}

// print the seat numbers of the queue after the queue has been sorted
// Parameters:
// qPtr - a pointer to the queue
int printOrderedQueue(BoardingQueue *qPtr)
{
	// create new pointer to head of queue
	Passenger *current = qPtr->head;

	// while current is not null
	while(current != NULL)
	{
		// print the seat number of the current passenger
		printf("Seat Number:%d\n", current->seatNumber);

		// move to the next passenger
		current = current->next;

	}

	return 0;
}

// sorts the queue in order of seat number from smallest to largest
// Parameters:
// qPtr - a pointer to the queue
int sortBoardingQueue(BoardingQueue *qPtr)
{
	// validate the queue pointer
	if (qPtr == NULL)
	{
		return INVALID_INPUT_PARAMETER;
	}

	// check if the queue is empty
	if (qPtr->head == NULL || qPtr->tail == NULL)
	{
		return INVALID_QUEUE_OPERATION;
	}

	// create variables for method.
	// 2 pointers to passengers in the queue
	// an integer that stores a value that determines if the queue still needs to be sorted
	Passenger *current;
	Passenger *afterCurrent;
	int result;

	// store result of check sort in variable, while be either 1 or 0
	result = checkSort(qPtr);

	// while the queue needs sorting
	while(result == 1)
	{

		// set pointers to the start of the queue
		current = qPtr->head;
		afterCurrent = qPtr->head->next;

		// while not reached end of the list
		while(afterCurrent != NULL)
		{
			
			// check if the seat number on the current passenger is bigger than the seat number of the passenger
			// next to them in the queue
			if (current->seatNumber > afterCurrent->seatNumber)
			{
				// create passenger variables to store data
				Passenger tempCurrent;
				Passenger tempAfterCurrent;

				// store data of the passengers
				tempCurrent = (*current);
				tempAfterCurrent = (*afterCurrent);

				// swap data of first passenger
				strncpy(current->name, tempAfterCurrent.name, 29);
				current->passportNumber = tempAfterCurrent.passportNumber;
				current->seatNumber = tempAfterCurrent.seatNumber;

				// swap data of the second passenger
				strncpy(afterCurrent->name, tempCurrent.name, 29);
				afterCurrent->passportNumber = tempCurrent.passportNumber;
				afterCurrent->seatNumber = tempCurrent.seatNumber;

			}

			// move the pointers along the queue
			current = afterCurrent;
			afterCurrent = afterCurrent->next;

		}

		// check if the queue still needs to be sorted
		result = checkSort(qPtr);

	}

	// print confirmation message, call function to print the queue in numerical order of seat number
	printf("Queue Sorted\n");
	printOrderedQueue(qPtr);
	
	return SUCCESS;

}