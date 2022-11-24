#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <Windows.h>
using namespace std;
class Book;
class Article;
class OnlineResource;
class Edition
{
	friend vector<Edition> findEditionByAuthor(Edition *editions, string author, int n);
	int countOfBooks;
	int countOfArticles;
	int countOfOnlines;
	vector<Book> books_;
	vector<Article> articles_;
	vector<OnlineResource> onlines_;
	protected:
		string name_;
	public:
		void setName(string name)
		{
			name_ = name;
		}

	void addBook(string a[5], int year);
	void addArticle(string a[5], int year, int number);
	void addOnline(string a[5]);
	void getInfo(ofstream & out);
	Edition()
	{
		countOfBooks = 0;
		countOfArticles = 0;
		countOfOnlines = 0;
	}

	vector<Book> getBooks()
	{
		return books_;
	}

	vector<Article> getArticles()
	{
		return articles_;
	}

	vector<OnlineResource> getOnline()
	{
		return onlines_;
	}

	string getName()
	{
		return name_;
	}
};

class Book: Edition
{
	friend vector<Edition> findEditionByAuthor(Edition *editions, string author, int n);
	friend Edition;
	string title_, author_;
	string edition_;
	int year_;
	void setParameters(string a[5], int year)
	{
		title_ = a[0];
		author_ = a[1];
		year_ = year;
	}

	Book()
	{
		title_ = "Название";
		author_ = "Автор";
		edition_ = name_;
		year_ = 1970;
	}
};

class Article: Edition
{
	friend vector<Edition> findEditionByAuthor(Edition *editions, string author, int n);
	friend vector<Edition> findEditionByName(Edition *editions, string name, int n);
	friend Edition;
	string title_, author_, nameOfMagazine_;
	int number_, year_;
	void setParameters(string a[5], int number, int year)
	{
		title_ = a[0];
		nameOfMagazine_ = a[1];
		author_ = a[2];
		number_ = number;
		year_ = year;
	}

	Article()
	{
		title_ = "Название";
		author_ = "Автор";
		nameOfMagazine_ = "Название журнала";
		number_ = 0;
		year_ = 1970;
	}
};

class OnlineResource: Edition
{
	friend vector<Edition> findEditionByAuthor(Edition *editions, string author, int n);
	friend Edition;
	string title_, author_, link_, annotation_;
	void setParameters(string a[5])
	{
		title_ = a[0];
		author_ = a[1];
		link_ = a[2];
		annotation_ = a[3];
	}

	OnlineResource()
	{
		title_ = "Название";
		author_ = "Автор";
		link_ = "example.org";
		annotation_ = "Аннотация";
	}
};

void Edition::getInfo(ofstream & out)
{
	out << "Название издательства: " << name_ << '\n';
	out << "Количество изданных книг: " << countOfBooks << '\n';
	out << "Количество изданных статей: " << countOfArticles << '\n';
	out << "Количество онлайн-ресурсов: " << countOfOnlines << '\n' << '\n';
	out << "|Авторы книг издательства:|\n";
	out << "---------------------------\n";
	out << "|Изданные книги:|\n";
	out << "---------------------------";
	for (int i = 0; i < books_.size(); i++)
	{
		out << books_[i].title_ << " - " << books_[i].author_ << ", " <<
			books_[i].year_;
	}

	///////////////////////////////////////
	out << "\n\n|Изданные статьи:|\n";
	out << "---------------------------";
	for (int i = 0; i < articles_.size(); i++)
	{
		out << articles_[i].title_ << " - " << articles_[i].nameOfMagazine_ << " -
		" << articles_[i].author_;
	}

	///////////////////////////////////////
	out << "\n\n|Онлайн-ресурсы:|\n";
	out << "---------------------------";
	for (int i = 0; i < onlines_.size(); i++)
	{
		out << onlines_[i].title_ << " - " << onlines_[i].author_ << " - " <<
			onlines_[i].link_;
		out << "\n\n";
		out << onlines_[i].annotation_;
		out << "\n\n";
	}

	out << "\n|==========================|";
	out << '\n' << '\n';
}

void Edition::addBook(string a[5], int year)
{
	Book book;
	book.setParameters(a, year);
	books_.push_back(book);
	countOfBooks++;
}

void Edition::addArticle(string a[5], int year, int number)
{
	Article article;
	article.setParameters(a, number, year);
	articles_.push_back(article);
	countOfArticles++;
}

void Edition::addOnline(string a[5])
{
	OnlineResource online;
	online.setParameters(a);
	onlines_.push_back(online);
	countOfOnlines++;
}

vector<Edition> findEditionByAuthor(Edition *editions, string author, int n)
{
	vector<Edition> foundEditions;
	vector<Book> books;
	vector<Article> articles;
	vector<OnlineResource> online;
	for (int i = 0; i < n; i++)
	{
		books = editions[i].getBooks();
		for (int j = 0; j < editions[i].countOfBooks; j++)
		{
			if (books[j].author_ == author)
			{
				foundEditions.push_back(editions[i]);
			}
		}

		articles = editions[i].getArticles();
		for (int j = 0; j < editions[i].countOfArticles; j++)
		{
			if (articles[j].author_ == author)
			{
				foundEditions.push_back(editions[i]);
			}
		}

		online = editions[i].getOnline();
		for (int j = 0; j < editions[i].countOfOnlines; j++)
		{
			if (online[j].author_ == author)
			{
				foundEditions.push_back(editions[i]);
			}
		}
	}

	return foundEditions;
}

vector<Edition> findEditionByName(Edition *editions, string name, int n)
{
	vector<Edition> foundEditions;
	string nameOfEdition;
	for (int i = 0; i < n; i++)
	{
		nameOfEdition = editions[i].getName();
		if (nameOfEdition == name)
		{
			foundEditions.push_back(editions[i]);
		}
	}

	return foundEditions;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ifstream in ; in .open("input.txt");
	int n; in >> n;
	Edition *editions = new Edition[n];
	string s;
	int number;
	int year;
	string a[5];
	for (int i = 0; i < n; i++)
	{
		in >> s;
		editions[i].setName(s);
		while (! in .eof())
		{
			getline(in, s, '|');
			if (s != "\n-")
			{
				for (int i = 0; i < 2; i++)
				{
					a[i] = s;
					getline(in, s, '|');
				}

				year = stoi(s);
				editions[i].addBook(a, year);
			}
			else
			{
				break;
			}
		}

		while (! in .eof())
		{
			getline(in, s, '|');
			if (s != "\n-")
			{
				for (int i = 0; i < 3; i++)
				{
					a[i] = s;
					getline(in, s, '|');
				}

				number = stoi(s);
				getline(in, s, '|');
				year = stoi(s);
				editions[i].addArticle(a, year, number);
			}
			else
			{
				break;
			}
		}

		while (! in .eof())
		{
			getline(in, s, '|');
			if (s != "\n-")
			{
				for (int i = 0; i < 3; i++)
				{
					a[i] = s;
					getline(in, s, '|');
				}

				a[3] = s;
				editions[i].addOnline(a);
			}
			else
			{
				break;
			}
		}
	} in .close();
	ofstream out("output.txt");
	for (int i = 0; i < n; i++)
	{
		editions[i].getInfo(out);
	}

	string surname = "Мортенсон";
	vector<Edition> foundEdition = findEditionByAuthor(editions, surname, n);
	out << "Найденные издательства по фамилии автора (" << surname << "): ";
	for (int i = 0; i < foundEdition.size(); i++)
	{
		out << foundEdition[i].getName() << ' ';
	}

	string name = "Бомбора";
	foundEdition = findEditionByName(editions, name, n);
	out << '\n';
	out << "Найденные издательства по названию (" << name << "): ";
	for (int i = 0; i < foundEdition.size(); i++)
	{
		out << foundEdition[i].getName() << ' ';
	}

	out.close();
	return 0;
}