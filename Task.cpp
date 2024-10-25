#include<iostream>
#include<string>

using namespace std;
class Book {
	string title;
	string author;
	string publisher;
	int pub_year;
	float price;
	int* numberOfPages;  
	static int numPublications;
public:
	Book(string t, string a, string pub, int p_year, float pr,int pages ) {
		this->title = t;
		this->author = a;
		this->publisher = pub;
		this->pub_year = p_year;
		this->price = pr;
		
		numberOfPages = new int (pages);
		numPublications++;
	}
	void Set_title(string t) {
		title = t;
	}
	string Get_title() {
		return title;
	}
	void Set_Author(string a) {
		author = a;
	}
	string Get_Author() {
		return author;
	}
	void Set_Publisher(string pub) {
		publisher= pub;
	}
	string Get_Publisher() {
		return publisher;
	}
	void Set_pubyear(int p_y) {
		pub_year = p_y;
	}
	int Get_pub_year() {
		return pub_year;
	}
	void Set_Price(float p) {
		price = p;
	}
	float Get_price() {
		return price;
	}

	float pricePerPage() {
		return price / *numberOfPages;
	}

	static int num_publications() {
		return numPublications;
	}

	void Print_details() {
		cout << "Title : " << title << endl;
		cout << "Author : " << author << endl;
		cout << "Publisher : " << publisher << endl;
		cout << "Publication Year: " << pub_year<< endl;
		cout << "Price: $" << price << endl;
		cout << "Number of Pages: " << *numberOfPages << endl;
		cout << "Price per Page: $" << pricePerPage() << endl;
	}
	~Book() {
		delete numberOfPages;
	}
};
 int Book::numPublications=0;

int main() {
	cout << "Number of Publications : "<<Book::num_publications();

	string title, author, publisher;
	int year, pages;
	float price;

	cout << "\nEnter Book Title: ";
	getline(cin, title);
	cout << "Enter Author Name: ";
	getline(cin, author);
	cout << "Enter Publisher Name: ";
	getline(cin, publisher);
	cout << "Enter Publication Year: ";
	cin >> year;
	cout << "Enter Price $ : ";
	cin >> price;
	cout << "Enter Number of Pages: ";
	cin >> pages;

	Book B(title, author, publisher, year, price, pages);
	cout << "\n";
	B.Print_details();
  cout<<"\n";
	cout<<"Number Of Publications :" << Book::num_publications();
	return 0;
}
