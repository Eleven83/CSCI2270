#ifndef MOVIETREE_HPP
#define MOVIETREE_HPP
#include <string>
struct MovieNode
{
  int ranking;
  std::string title;
  int year;
  int quantity;

  MovieNode *parent;
  MovieNode *leftChild;
  MovieNode *rightChild;

  MovieNode(){
    parent = leftChild = rightChild = nullptr;
  }

  MovieNode(int r, std::string t, int y, int q) {
    ranking = r;
    title = t;
    year = y;
    quantity = q;
    parent = leftChild = rightChild = nullptr;
  }
};

class MovieTree
{
public:
  MovieTree();
  ~MovieTree();
  void printMovieInventory();
  void addMovieNode(int ranking, std::string title, int year, int quantity);
  void findMovie(std::string title);
  void rentMovie(std::string title);
  void deleteMovie(std::string title);
  void countMovies();
private:
  MovieNode *search(std::string title);
  MovieNode *root;
};
#endif
