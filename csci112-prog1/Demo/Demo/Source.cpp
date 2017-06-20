#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

const int maxbook = 50;

struct booktype {
	int id, num;
	string title, author, genre;
	double price, value;
};
const booktype initrec = { -1, -1, "No Title", "No Author", "No Genre", 0.0, 0.0 };
void initem(booktype b[], int &numbook);
void readem(booktype b[], int &numbook);
void calcem(booktype b[], int numbook);
void sortbyid(booktype b[], int numbook);
void sortbytitle(booktype b[], int numbook);
void printem(booktype b[], int numbook);
void searchem(booktype b[], int numbook);

int main() {
	booktype book[maxbook];
	int numbook;
	initem(book, numbook);
	readem(book, numbook);
	calcem(book, numbook);
	sortbyid(book, numbook);
	sortbytitle(book, numbook);
	printem(book, numbook);
	searchem(book, numbook);
	cin.get(book, numbook);
	return 0;
}
