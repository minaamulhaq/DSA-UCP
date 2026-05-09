#include "SongNode.h"

class PlaylistDLL
{
private:
    SongNode *head;
    SongNode *tail;
    SongNode *current;

public:
    PlaylistDLL()
    {
        head = NULL;
        tail = NULL;
        current = NULL;
    }

    void addSongAtEnd(int id, string name, float duration)
    {
        SongNode *newSong = new SongNode(id, name, duration);

        if (head == NULL)
        {
            head = newSong;
            tail = newSong;
            current = newSong;
        }
        else
        {
            tail->next = newSong;
            newSong->prev = tail;
            tail = newSong;
        }

        cout << "Song added successfully.\n";
    }

    void deleteSongByName(string name)
    {
        if (head == NULL)
        {
            cout << "Playlist is empty.\n";
            return;
        }

        SongNode *temp = head;

        while (temp != NULL && temp->songName != name)
        {
            temp = temp->next;
        }

        if (temp == NULL)
        {
            cout << "Song not found.\n";
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
        cout << "Song deleted successfully.\n";
    }

    void playNext()
    {
        if (current == NULL)
        {
            cout << "No song is currently selected.\n";
            return;
        }

        if (current->next == NULL)
        {
            cout << "You are already at the last song.\n";
            return;
        }

        current = current->next;

        cout << "Now playing next song:\n";
        printSong(current);
    }

    void playPrevious()
    {
        if (current == NULL)
        {
            cout << "No song is currently selected.\n";
            return;
        }

        if (current->prev == NULL)
        {
            cout << "You are already at the first song.\n";
            return;
        }

        current = current->prev;

        cout << "Now playing previous song:\n";
        printSong(current);
    }

    void reversePlaylist()
    {
        if (head == NULL || head->next == NULL)
        {
            cout << "Playlist does not need reversing.\n";
            return;
        }

        SongNode *temp = NULL;
        SongNode *curr = head;

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

        cout << "Playlist reversed successfully.\n";
    }

    void displayPlaylist()
    {
        if (head == NULL)
        {
            cout << "Playlist is empty.\n";
            return;
        }

        SongNode *temp = head;

        cout << "\n----- Playlist -----\n";

        while (temp != NULL)
        {
            cout << "Song ID: " << temp->songID << endl;
            cout << "Song Name: " << temp->songName << endl;
            cout << "Duration: " << temp->duration << " minutes" << endl;
            cout << "--------------------\n";

            temp = temp->next;
        }
    }

    void printSong(SongNode *song)
    {
        if (song == NULL)
        {
            cout << "No song to display.\n";
            return;
        }

        cout << "Song ID: " << song->songID << endl;
        cout << "Song Name: " << song->songName << endl;
        cout << "Duration: " << song->duration << " minutes" << endl;
    }
};
