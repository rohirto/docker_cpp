/******************************************************************
 * Challenge 1
 * Movies.h
 * 
 * Models a collection of Movies as a std::vector
 * 
 * ***************************************************************/
#include <iostream>
#include "Movies.h"
#include <algorithm>  // for std::for_each
#include <vector>
#include <limits>

 /*************************************************************************
    Movies no-args constructor
**************************************************************************/
Movies::Movies() {
}

/*************************************************************************
    Movies destructor
**************************************************************************/
Movies::~Movies() {
}

  /*************************************************************************
    add_movie expects the name of the move, rating and watched count
    
    It will search the movies vector to see if a movie object already exists
    with the same name. 
    
    If it does then return false since the movie already exists
    Otherwise, create a movie object from the provided information
    and add that movie object to the movies vector and return true
    *********************************************************************/
bool Movies::add_movie(const std::string& name,const std::string& rating, int watched) {
    // you implement this method
   if(find_movie(name) == std::numeric_limits<size_t>::max())
   {
        //Add the movie
        Movie newMov(name,rating,watched);
        movies.push_back(newMov);
        return true;
   }
   else
   {
        //Movie already exists, no need to add
        return false;
   }
}

 /*************************************************************************
    increment_watched expects the name of the move to increment the
    watched count
    
    It will search the movies vector to see if a movie object already exists
    with the same name. 
    If it does then increment that objects watched by 1 and return true.

    Otherwise, return false since then no movies object with the movie name
    provided exists to increment
    *********************************************************************/
bool Movies::increment_watched(const std::string& name) {
   // you implement this method
   size_t index = find_movie(name);
   if(index == std::numeric_limits<size_t>::max())
   {
        //no such movie
        return false;
   }
   else
   {
        //Movie there in database, increment the count
        movies[index].increment_watched();
        return true;

   }
}

/*************************************************************************
    display
    
    display all the movie objects in the movies vector.
    for each movie call the movie.display method so the movie
    object displays itself
    *********************************************************************/
void Movies::display() const
{
    // You implement this method
    if (!movies.empty())
    {
        std::for_each(movies.begin(), movies.end(), [](const Movie &m)
                      { m.display(); });
    }
    else
    {
        std::cout << "Sorry, no movies to display\n";
    }
}

size_t Movies::find_movie(std::string_view name)
{
    auto it = std::find_if(movies.begin(), movies.end(), [&name](const Movie& m){return m.get_name() == name;});

    if (it != movies.end()) 
    {
        // Calculate the index using std::distance
        return std::distance(movies.begin(), it);
    } 
    else 
    {
        // Return a value indicating "not found"
        return std::numeric_limits<size_t>::max();
    }

}