/**
 * @file volansys_ex2.cpp
 * @author rohit S
 * @brief Challenge 11 of C++ Advance
 * @version 0.1
 * @date 2023-12-28
 *
 * @copyright Copyright (c) 2023 Volansys Technologies
 *
 * @paragraph Challenge 11
 *
 * Using std::list

    In this challenge you will create a menu driven application that
    will simulate a user playing songs from a playlist of songs.

    We will use a list to simulate the user selecting the the first song in the playlist and
    then selecting next and previous to play forward of backwards through the
    playlist.

    Please refer to the video demo run.

    We will also allow users to add new song to the playlist and they
    will be added prior to the currently playing song.
    The menu looks as follows:

    F - Play First Song
    N - Play Next song
    P - Play Previous song
    A - Add and play a new Song at current location
    L - List the current playlist
    ========================
    Enter a selection (Q to quit):

    And the available playlist is modeled as a std::list<Song>
    I will provide the Song class. Following are the songs in the playlist.
    I grabbed these from the pop charts, you can use them or change
    them to any songs you wish.

    God's Plan                  Drake                                       5
    Never Be The Same   Camila Cabello                         5
    Pray For Me               The Weekend and K. Lamar      4
    The Middle                Zedd, Maren Morris & Grey     5
    Wait                           Maroone 5                                4
    Whatever It Takes      Imagine Dragons                      3

    I have provided the starting project.
    Have fun!

    Note:
    If you have trouble reading input, you can clear std::cin and
    ignore everything in the buffer with:

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

    Make sure you #include <limits> to use it.
 *
 */

#include <iostream>
#include <list>
#include <string>
#include <cctype>
#include <iomanip>
#include <limits>

// For delay
#include <unistd.h>

class Song
{
    friend std::ostream &operator<<(std::ostream &os, const Song &s);
    std::string name;
    std::string artist;
    int rating;

public:
    Song() = default;
    Song(std::string name, std::string artist, int rating)
        : name{name}, artist{artist}, rating{rating} {}
    std::string get_name() const
    {
        return name;
    }
    std::string get_artist() const
    {
        return artist;
    }
    int get_rating() const
    {
        return rating;
    }

    bool operator<(const Song &rhs) const
    {
        return this->name < rhs.name;
    }

    bool operator==(const Song &rhs) const
    {
        return this->name == rhs.name;
    }
};

std::ostream &operator<<(std::ostream &os, const Song &s)
{
    os << std::setw(20) << std::left << s.name
       << std::setw(30) << std::left << s.artist
       << std::setw(2) << std::left << s.rating;
    return os;
}

void display_menu()
{
    std::cout << "\nF - Play First Song" << std::endl;
    std::cout << "N - Play Next song" << std::endl;
    std::cout << "P - Play Previous song" << std::endl;
    std::cout << "A - Add and play a new Song at current location" << std::endl;
    std::cout << "L - List the current playlist" << std::endl;
    std::cout << "===============================================" << std::endl;
    std::cout << "Enter a selection (Q to quit): ";
}

void play_current_song(const Song &song)
{
    // This function should display
    // Playing: followed by the song that is playing

    // std::cout << "You implement this function"<< std::endl;

    std::cout << "Playing: " << song << std::endl;
    // Introduce a delay of 2 seconds
    usleep(3 * 1000000); // sleeps for 3 second
}

void display_playlist(const std::list<Song> &playlist, const Song &current_song)
{
    // This function should display the current playlist
    // and then the current song playing.
    std::cout << std::setw(30) << std::left << "SONG"
            << std::setw(30) << std::left << "ARTIST" 
            << std::setw(5) << std::left << "RATING"
            << std::endl;  
    for(const Song& s: playlist)
    {
        if(s == current_song)
        {
            std::cout << "*";
        }
        std::cout << std::setw(30) << std::left << s.get_name()
            << std::setw(30) << std::left << s.get_artist()
            << std::setw(5) << std::left << s.get_rating()
            << std::endl;
        
    }

    //std::cout << "You implement this function" << std::endl;
}

Song get_song()
{
    std::string song_name;
    std::string artist;
    int rating;

    std::cout << "Enter Song name: ";
    std::getline(std::cin >> std::ws, song_name);
    std::cout << "\nEnter Artist name: ";
    std::getline(std::cin >> std::ws, artist);
    std::cout << "\nenter rating of song: ";
    std::cin >> rating;

    Song new_song(song_name, artist, rating);

    return new_song;
}

int main()
{

    std::list<Song> playlist{
        {"God's Plan", "Drake", 5},
        {"Never Be The Same", "Camila Cabello", 5},
        {"Pray For Me", "The Weekend and K. Lamar", 4},
        {"The Middle", "Zedd, Maren Morris & Grey", 5},
        {"Wait", "Maroone 5", 4},
        {"Whatever It Takes", "Imagine Dragons", 3}};

    std::list<Song>::iterator current_song = playlist.begin();

    // std::cout << "To be implemented" << std::endl;
    //  Your program logic goes here

    char choice = 0x00;
    std::list<Song>::iterator endsong = playlist.end();
    endsong = --endsong;
    do
    {
        // Display menu
        display_menu();

        std::cin >> choice;

        choice = toupper(choice);

        if (choice == 'F')
        {

            // Play first song
            // Take iterator to begi
            current_song = playlist.begin();
            // Play current song
            play_current_song(*current_song);
        }
        else if (choice == 'N')
        {

            if (current_song == endsong)
            {
                current_song = playlist.begin(); // repeat
            }
            else
            {
                ++current_song;
            }
            play_current_song(*current_song);
        }
        else if (choice == 'P')
        {
            if (current_song == playlist.begin())
            {
                current_song = endsong; // repeat
            }
            else
            {
                --current_song;
            }
            play_current_song(*current_song);
        }
        else if (choice == 'A')
        {
            // Add the song at current position
            std::string song_name;
            std::string artist;
            int rating;

            std::cout << "Enter Song name: ";
            std::getline(std::cin >> std::ws, song_name);
            std::cout << "\nEnter Artist name: ";
            std::getline(std::cin >> std::ws, artist);
            std::cout << "\nenter rating of song: ";
            std::cin >> rating;

            Song new_song(song_name, artist, rating);
            playlist.emplace(current_song, new_song);
            std::cout << "Song added!\n";
        }
        else if (choice == 'L')
        {
            display_playlist(playlist, *current_song);
        }
        else if (choice == 'Q')
        {
        }
        else
            std::cout << "Invalid choice!\n";

    } while (choice != 'Q');

    std::cout << "Thanks for listening!" << std::endl;
    return 0;
}