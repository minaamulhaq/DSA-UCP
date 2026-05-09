#include "MovieNode.h"
#include <iostream>
#include <string>
using namespace std;

class Watchlist
{
protected:
    MovieNode *head;
    MovieNode *tail;
    MovieNode *current;

public:
    Watchlist()
    {
        head = NULL;
        tail = NULL;
        current = NULL;
    }

    void addMovieAtEnd(int id, string name, float rating);
    void removeMovieByName(string name);
    void playNext();
    void playPrevious();
    void reverseWatchlist();
    void displayWatchlist();
    void findHighestRatedMovie();
    void printMovie(MovieNode *movie);
};

// 1. Add Movie at End
void Watchlist::addMovieAtEnd(int id, string name, float rating)
{
    MovieNode *newMovie = new MovieNode(id, name, rating);

    if (head == NULL)
    {
        head = newMovie;
        tail = newMovie;
        current = newMovie;
    }
    else
    {
        tail->next = newMovie;
        newMovie->prev = tail;
        tail = newMovie;
    }

    cout << "Movie added successfully.\n";
}

// 2. Remove Movie by Name
void Watchlist::removeMovieByName(string name)
{
    if (head == NULL)
    {
        cout << "Watchlist is empty.\n";
        return;
    }

    MovieNode *temp = head;

    while (temp != NULL && temp->movieName != name)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Movie not found.\n";
        return;
    }

    if (temp == head)
    {
        head = head->next;

        if (head != NULL)
        {
            head->prev = NULL;
        }
        else
        {
            tail = NULL;
        }
    }
    else if (temp == tail)
    {
        tail = tail->prev;

        if (tail != NULL)
        {
            tail->next = NULL;
        }
    }
    else
    {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }

    if (current == temp)
    {
        if (temp->next != NULL)
        {
            current = temp->next;
        }
        else
        {
            current = temp->prev;
        }
    }

    delete temp;
    cout << "Movie removed successfully.\n";
}

// 3. Play Next
void Watchlist::playNext()
{
    if (current == NULL)
    {
        cout << "No movie is currently selected.\n";
        return;
    }

    if (current->next == NULL)
    {
        cout << "You are already at the last movie.\n";
        return;
    }

    current = current->next;
    cout << "Now playing next movie:\n";
    printMovie(current);
}

// 3. Play Previous
void Watchlist::playPrevious()
{
    if (current == NULL)
    {
        cout << "No movie is currently selected.\n";
        return;
    }

    if (current->prev == NULL)
    {
        cout << "You are already at the first movie.\n";
        return;
    }

    current = current->prev;
    cout << "Now playing previous movie:\n";
    printMovie(current);
}

// 4. Reverse Watchlist
void Watchlist::reverseWatchlist()
{
    if (head == NULL || head->next == NULL)
    {
        cout << "Watchlist does not need reversing.\n";
        return;
    }

    MovieNode *temp = NULL;
    MovieNode *curr = head;

    while (curr != NULL)
    {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;

        curr = curr->prev;
    }

    temp = head;
    head = tail;
    tail = temp;

    current = head;

    cout << "Watchlist reversed successfully.\n";
}

// 5. Display Watchlist
void Watchlist::displayWatchlist()
{
    if (head == NULL)
    {
        cout << "Watchlist is empty.\n";
        return;
    }

    MovieNode *temp = head;

    cout << "\n----- Watchlist -----\n";

    while (temp != NULL)
    {
        cout << "Movie ID: " << temp->movieID << endl;
        cout << "Movie Name: " << temp->movieName << endl;
        cout << "Rating: " << temp->rating << endl;
        cout << "---------------------\n";

        temp = temp->next;
    }
}

// 6. Find Highest Rated Movie
void Watchlist::findHighestRatedMovie()
{
    if (head == NULL)
    {
        cout << "Watchlist is empty.\n";
        return;
    }

    MovieNode *temp = head;
    MovieNode *highest = head;

    while (temp != NULL)
    {
        if (temp->rating > highest->rating)
        {
            highest = temp;
        }

        temp = temp->next;
    }

    cout << "\nHighest Rated Movie:\n";
    printMovie(highest);
}

// Helper function
void Watchlist::printMovie(MovieNode *movie)
{
    if (movie == NULL)
    {
        cout << "No movie to display.\n";
        return;
    }

    cout << "Movie ID: " << movie->movieID << endl;
    cout << "Movie Name: " << movie->movieName << endl;
    cout << "Rating: " << movie->rating << endl;
}