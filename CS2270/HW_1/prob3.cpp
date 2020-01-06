/*
CSCI 2270 Fall 2018, Professor Gupta
TA: Saumya Sinha
Assignment 1
Author: Ryan Hoffman
9-5-2018
*/
#include <iostream>
#include <string>

using namespace std;

class Movie
{
public:
    Movie()
    {
        title="unknown";
        year=2018;
        rating=0.0;
    }
    Movie(string _title, int _year, float _rating)
    {
        title=_title;
        year=_year;
        rating=_rating;
    }
    string getTitle()
    {
        cout<<"Please enter the movie title: "<<endl;
        getline(cin, title);
        return title;
    }
    int getYear()
    {
        cout<<"Please enter the year: "<<endl;
        string y;
        getline(cin, y);
        int year=stoi(y);
        return year;
    }
    float getRating()
    {
        cout<<"Please enter the rating: "<<endl;
        string r;
        getline(cin, r);
        float rating=stof(r);
        return rating;
    }
    void setTitle(string setTitle)
    {
        title=setTitle;
    }
    void setYear(int setYear)
    {
        year=setYear;
    }
    void setRating(float setRating)
    {
        rating=setRating;
    }
    void printMovie();
private:
    string title;
    int year;
    float rating;
};
void Movie::printMovie()
{
    cout<<"Title: "<<title<<" Year: "<<year<<" Rating: "<<rating<<endl;
}
int main()
{
    Movie m1, m2, m3;
    // int mYear=stoi(argv[2]);
    // float mRating=stof(argv[3]);
    // m1.setTitle(argv[1]);
    string title1=m1.getTitle();
    int year1=m1.getYear();
    float rating1=m1.getRating();
    m1.setTitle(title1);
    m1.setYear(year1);
    m1.setRating(rating1);

    string title2=m2.getTitle();
    int year2=m2.getYear();
    float rating2=m2.getRating();
    m2.setTitle(title2);
    m2.setYear(year2);
    m2.setRating(rating2);

    string title3=m3.getTitle();
    int year3=m3.getYear();
    float rating3=m3.getRating();
    m3.setTitle(title3);
    m3.setYear(year3);
    m3.setRating(rating3);

    m1.printMovie();
    m2.printMovie();
    m3.printMovie();

    return 0;
}
