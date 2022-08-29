#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "playlist.h"

/* A function (and global) that can trigger malloc fails on demand. */
int mallocFail = 0;

void* myMalloc(size_t size) {
	if (mallocFail) { return NULL; }
	else { return malloc(size); }
}

// Returns if the playlist is empty
bool isListEmpty(Playlist *listPtr)
{
    // Checks if the list is empty
    if (listPtr->head == NULL && listPtr->tail == NULL && listPtr->curr == NULL)
        return true;
    return false;
}

void displayTrack(MP3Track *track) {
    printf("Name: %s\tLength: %d", track->trackName, track->trackLength);
}

void displayValid(int valid) {
    printf("\tDisplay Code: ");
    if (valid == SUCCESS) {
        printf("SUCCESS");
    }
    else if (valid == INVALID_INPUT_PARAMETER) {
        printf("INVALID_INPUT_PARAMETER");
    }
    else if (valid == MEMORY_ALLOCATION_ERROR) {
        printf("MEMORY_ALLOCATION_ERROR");
    }
    else if (valid == INVALID_LIST_OPERATION) {
        printf("INVALID_LIST_OPERATION");
    }
    else if (valid == NOT_IMPLEMENTED) {
        printf("NOT_IMPLEMENTED");
    }
    else if (valid == FILE_IO_ERROR) {
        printf("FILE_IO_ERROR");
    }
    else {
        printf("WTF: %d", valid);
    }
    printf("\n");
}

void displayPlaylist(Playlist *listPtr, int valid) {
    if (listPtr == NULL) {
        printf("List is uninitalised\n");
        return;
    }

    // Used to store the current track we're displaying
    MP3Track track;
    // Moves the current track to the head so we can display the entire playlist
    while(skipPrev(listPtr) == SUCCESS) {}
    do {
        if (!isListEmpty(listPtr)) {
            // Gets the current track 
            getCurrentTrack(listPtr, &track);
            // Displays the current track
            displayTrack(&track);
            displayValid(valid);
        }
    } while (skipNext(listPtr) == SUCCESS);
}

// int dummy(int result) {
//     return 1;
// }

int main() {
    // a variable to store an MP3 track popped from the list
	MP3Track track;

	// a pointer to our doubly-linked list
	Playlist *listPtr = NULL;
    //
    int result;

    result = createPlaylist(&listPtr);
    result = insertAfterCurr(listPtr, "First track", 1);
    result = insertAfterCurr(listPtr, "Second track", 2);
    result = insertAfterCurr(listPtr, "Third track", 3);
    result = insertBeforeCurr(listPtr, "First track", 1);
    result = insertBeforeCurr(listPtr, "Second track", 2);
    result = insertBeforeCurr(listPtr, "Third track", 3);
    result = getCurrentTrack(listPtr, &track);
    result = removeAtCurr(listPtr, &track, 1);
    result = loadPlaylist(&listPtr, "test_playlist.txt");
    result = savePlaylist(listPtr, "out.txt");
    result = skipNext(listPtr);
    displayTrack(listPtr->curr);
    printf("\n");
    result = skipPrev(listPtr);
    result = clearPlaylist(listPtr);
    displayPlaylist(listPtr, result);
    // dummy(result);
    return 0;
}