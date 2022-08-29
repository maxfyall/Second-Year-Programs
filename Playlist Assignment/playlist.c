/* 
	Name: Max Fyall
	Matric Number: 180011724
	Module Code: AC21008
*/

#include "playlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// initialise a new Playlist
// Parameters
// listPtr - will receive a pointer to a new playlist
int createPlaylist(Playlist **listPtr)
{
	// checks if the list pointer is empty
	if (listPtr == NULL)
	{
		return INVALID_INPUT_PARAMETER;
	}

	// checks if the list has already been initialsed
	if (*listPtr != NULL)
	{
		return INVALID_INPUT_PARAMETER;
	}

	// Allocating memory for a new list
	(*listPtr) = (Playlist*)myMalloc(sizeof(Playlist));

	// Checks for memory allocation errors
	if ((*listPtr) == NULL)
	{
		return MEMORY_ALLOCATION_ERROR;
	}

	// initialise the head, tail and current pointers to null
	(*listPtr)->head = NULL;
	(*listPtr)->curr = NULL;
	(*listPtr)->tail = NULL;

	return SUCCESS;
}

// insert a new track before the current song in the playlist
// Parameters;
// listPtr - a pointer to the list
// trackName - stores the name of new the track
// trackLength - stores the length of new the track
int insertBeforeCurr(Playlist* listPtr, char trackName[], int trackLength)
{
	// check all variables given are valid
	if (listPtr == NULL || trackName == NULL || trackLength == 0)
	{
		return INVALID_INPUT_PARAMETER;
	}

	// check if data for new track is within it's defined range
	if (strlen(trackName) > 49 || strlen(trackName) < 1 || trackLength < 1)
	{
		return INVALID_INPUT_PARAMETER;
	}

	// create a new track to be added to the list
	MP3Track *newTrack = (MP3Track*)myMalloc(sizeof(MP3Track));

	// checks for memory allocation errors
	if (newTrack == NULL)
	{
		return MEMORY_ALLOCATION_ERROR;
	}

	// initialise variables for the new track
	strncpy(newTrack->trackName, trackName, 49);
	newTrack->trackLength = trackLength;
	newTrack->prev = NULL;
	newTrack->next = NULL;

	//  check if the list is empty
	if (listPtr->head == NULL)
	{
		// set the new track as the first item in the list
		listPtr->head = newTrack;
		listPtr->curr = newTrack;
		listPtr->tail = newTrack;
	}
	else // otherwise, i.e. the list is not empty
	{
		// checks if current is the head of the list
		if (listPtr->curr == listPtr->head)
		{
			// add the new track before the head of the list
			// by settting the new track as the new head of the list,
			// connecting the new track to the previous head
			newTrack->next = listPtr->curr;
			listPtr->curr->prev = newTrack;
			listPtr->head = newTrack;
		}

		// checks if current is not the head of the list
		else if (listPtr->curr != listPtr->head)
		{
			// add the new track before the current song,
			// ensuring nodes are connected to the correct nodes
			newTrack->next = listPtr->curr;
			newTrack->prev = listPtr->curr->prev;

			listPtr->curr->prev->next = newTrack;
			listPtr->curr->prev = newTrack;
		}
		
	}

	return SUCCESS;
}

// insert a new track after the current song in the playlist
// Parameters:
// listPtr - a pointer to the list
// trackName - stores the name of the new track
// trackLength - stores the length of the new track
int insertAfterCurr(Playlist* listPtr, char trackName[], int trackLength)
{
	// check the variables are valid
	if (listPtr == NULL || trackName == NULL || trackLength == 0)
	{
		return INVALID_INPUT_PARAMETER;
	}

	// check if data for new track is within it's defined range
	if (strlen(trackName) > 49 || strlen(trackName) < 1 || trackLength < 1)
	{
		return INVALID_INPUT_PARAMETER;
	}

	// create a new track to be added to the list
	MP3Track *newTrack = (MP3Track*)myMalloc(sizeof(MP3Track));

	// checks for memory allocation errors
	if (newTrack == NULL)
	{
		return MEMORY_ALLOCATION_ERROR;
	}

	// initialise variables for the new track
	strncpy(newTrack->trackName, trackName, 49);
	newTrack->trackLength = trackLength;
	newTrack->prev = NULL;
	newTrack->next = NULL;

	//  check if the list is empty
	if (listPtr->head == NULL)
	{
		// set the new track as the first item in the list
		listPtr->head = newTrack;
		listPtr->curr = newTrack;
		listPtr->tail = newTrack;
	}
	else // otherwise, i.e. the list is not empty
	{
		// check if current is the tail
		if (listPtr->curr == listPtr->tail)
		{
			// insert the new track after the tail
			// by setting the new track as the new tail,
			// connecting the new track to the previous tail
			newTrack->prev = listPtr->curr;
			listPtr->curr->next = newTrack;
			listPtr->tail = newTrack;
		}

		// check if the current is not the tail of the list
		else if (listPtr->curr != listPtr->tail)
		{
			// add the new track after the current song,
			// ensuring nodes are connected to the correct nodes
			newTrack->prev = listPtr->curr;
			newTrack->next = listPtr->curr->next;

			listPtr->curr->next->prev = newTrack;
			listPtr->curr->next = newTrack;
		}
	}

	return SUCCESS;

}

// move the current song to the next song in the playlist
// Parameters:
// listPtr - a pointer to the list
int skipNext(Playlist* listPtr)
{
	// check if there is no current song
	if (listPtr->curr == NULL)
	{
		return INVALID_LIST_OPERATION;
	}

	// check if the song next to current exists
	if (listPtr->curr->next == NULL)
	{
		return INVALID_LIST_OPERATION;
	}

	// set the current song to the next song in the playlist
	listPtr->curr = listPtr->curr->next;

	return SUCCESS;
}

// move the current song to the previous song in the playlist
// Parameters:
// listPtr - a pointer to the list
int skipPrev(Playlist* listPtr)
{
	// check if is no current song
	if (listPtr->curr == NULL)
	{
		return INVALID_LIST_OPERATION;
	}

	// check if the song next to current exists
	if (listPtr->curr->prev == NULL)
	{
		return INVALID_LIST_OPERATION;
	}

	// set the current song to the previous song in the playlist
	listPtr->curr = listPtr->curr->prev;

	return SUCCESS;
}

// gets the current song in the playlist (the song stored as current)
// Parameters:
// listPtr - a pointer to the list
// pTrack - node to store the data of the current track
int getCurrentTrack(Playlist* listPtr, MP3Track *pTrack)
{
	// check if list pointer is valid
	if (listPtr == NULL)
	{
		return INVALID_INPUT_PARAMETER;
	}

	// check if parameter is valid
	if (pTrack == NULL)
	{
		return INVALID_INPUT_PARAMETER;
	}

	// check if current is valid
	if (listPtr->curr == NULL)
	{
		return INVALID_LIST_OPERATION;
	}

	// store the data of the current song in the given
	strncpy(pTrack->trackName, listPtr->curr->trackName, 49);
	pTrack->trackLength = listPtr->curr->trackLength;
	pTrack->next = listPtr->curr->next;
	pTrack->prev = listPtr->curr->prev;

	return SUCCESS;
}

// removes the current track from the playlist
// Parameters:
// listPtr - a pointer to the list
// pTrack - node to store data of song being deleted
// moveForward - integer value to indicate where the next current will be
int removeAtCurr(Playlist *listPtr, MP3Track *pTrack, int moveForward)
{
	// check if list pointer is valid
	if (listPtr == NULL)
	{
		return INVALID_INPUT_PARAMETER;
	}

	// check if parameter is valid
	if (pTrack == NULL)
	{
		return INVALID_INPUT_PARAMETER;
	}

	// check if the list is empty
	if (listPtr->head == NULL || listPtr->tail == NULL || listPtr->curr == NULL)
	{
		return INVALID_LIST_OPERATION;
	}

	// create temporary track variable to store the data of the song to be removed
	MP3Track *trackToRemove = listPtr->curr;

	// store data of song to be removed in pTrack variable
	strncpy(pTrack->trackName, trackToRemove->trackName, 49);
	pTrack->trackLength = trackToRemove->trackLength;
	pTrack->next = trackToRemove->next;
	pTrack->prev = trackToRemove->prev;

	// check if there is only one item in the list
	if (listPtr->curr == listPtr->head && listPtr->curr == listPtr->tail)
	{
		// set all pointers to NULL
		listPtr->head = NULL;
		listPtr->tail = NULL;
		listPtr->curr = NULL;
	}
	else // if there is more than one item in the list
	{
		// check if the current song is the head of the list
		if (listPtr->curr == listPtr->head)
		{
			// remove the current song, ensuring
			// the new current is the new head
			listPtr->head = trackToRemove->next;
			listPtr->head->prev = NULL;
			listPtr->curr = listPtr->head;
		}

		// check if the current song is the tail of the list
		// condition only checked if previous if is false
		else if (listPtr->curr == listPtr->tail)
		{
			// remove the current song, ensuring
			// the new current is the new tail
			listPtr->tail = trackToRemove->prev;
			listPtr->tail->next = NULL;
			listPtr->curr = listPtr->tail;
		}

		// check if the current song is not the headand not the tail
		// condition only checked if previous if is false
		else if (listPtr->curr != listPtr->head && listPtr->curr != listPtr->tail)
		{
			// check what happens to the 'current' pointer
			if (moveForward == 1)
			{
				// set the current song to the next song in the playlist
				listPtr->curr = trackToRemove->next;
			}
			else // otherwise
			{
				// set the current song to the previous song in the playlist
				listPtr->curr = trackToRemove->prev;
			}

			// remove the current song, ensuring nodes before and after
			//  the song being removed are pointing to the correct nodes
			trackToRemove->prev->next = trackToRemove->next;
			trackToRemove->next->prev = trackToRemove->prev;
			trackToRemove->next = NULL;
			trackToRemove->prev = NULL;
		}
	}

	// clears the memory of the temorary variable
	free(trackToRemove);

	return SUCCESS;

}

// empty the whole list and free all the memory used
// Parameters:
// listPtr - a pointer to the list we want to free/empty
int clearPlaylist(Playlist* listPtr)
{
	// check if the pointer is pointing to a valid list
	if (listPtr == NULL)
	{
		return INVALID_INPUT_PARAMETER;
	}
	
	// while the list is not empty
	while(listPtr->head != NULL)
	{

		// get a pointer to the head of the list
		MP3Track *temp = listPtr->head;

		// move the head to the next song in the playlist
		listPtr->head = listPtr->head->next;

		// free the pointer of it's memory
		free(temp);
	}

	// free the list itself once all the songs have been free-d from the list
	free(listPtr);

	return SUCCESS;
}

// Additional Marks Methods:

// saves the playlist to a file
// Parameters:
// listPtr - a pointer to the list
// filename - stores the name of the file to save the playlist to
int savePlaylist(Playlist *listPtr, char filename[])
{
	// create pointer to point to a file
	FILE *fp;

	// check if filename is empty
	// cannot create a file with empty variable
	if (filename == NULL)
	{
		return INVALID_INPUT_PARAMETER;
	}

	// create file for writing to
	fp = fopen(filename, "w");

	// check if file pointer is empty
	if (fp != NULL)
	{
		// create pointer to beginning of playlist
		MP3Track *current = listPtr->head;

		// while pointer has not reached end of list
		while(current != NULL)
		{
			// write the data for the song to the file using format defined in documentation
			fprintf(fp, "%s#%d#\n", current->trackName, current->trackLength);

			// move to the next node
			current = current->next;
		}
	}
	else // otherwise
	{
		// return error to indicate something went wrong
		return FILE_IO_ERROR;
	}

	// close the file we were writing to
	fclose(fp);

	return SUCCESS;
}

// creates a new playlist and loads data from file to insert into new list
// Parameters:
// listPtr - will receive a pointer to a new playlist
// filename - stores the name of the file to save the playlist to
int loadPlaylist(Playlist **listPtr, char filename[])
{
	// check if filename given is invalid
	if (filename == NULL)
	{
		return INVALID_INPUT_PARAMETER;
	}

	// create a new empty playlist
	createPlaylist(listPtr);

	// create file pointer
	FILE *fp;

	// open the file to read from
	fp = fopen(filename, "r");

	// check if the file failed to open properly
	if (fp != NULL)
	{
		// create variable to store current line
		char line[256];

		// while the file is not empty
		while(fgets(line, 256, fp) != NULL)
		{
			// get the track name from the current line
			char *songName = strtok(line, "#");

			// get the song length from the current line
			char *songLengthStr = strtok(NULL, "#");

			// convert the track length from a string to an integer
			// as the insertAfterCurrent method takes in an integer
			// rather than a string (a string would cause errors in the method)
			int songLength = atoi(songLengthStr);

			// insert the data from the file into the playlist as a new song
			insertAfterCurr(*listPtr, songName, songLength);

		}
	}

	// close the file we were reading from
	fclose(fp);

	return SUCCESS;
}
