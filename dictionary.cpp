#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;

/*
 * Simple database with a class based interface.
 * This dictionary class stores each definition as a pair of strings into a file.
 * Each string in the pair cannot contain a newline character.
 */
class dictionary {
public:
	dictionary() {}

	explicit dictionary(const string& filename)
	{
		this->open(filename);
	}

	~dictionary()
	{
		if (this->is_open()) this->close();
	}

	void open(const string& filename)
	{
		string term, explanation;

		this->file.open(filename.c_str(), fstream::in);
		if (this->file.is_open()) {
			while (getline(this->file, term) && getline(this->file,
								explanation)) {
				this->definitions[term] = explanation;
			}
			this->file.close();
		}
		this->file.open(filename.c_str(), fstream::out);
			
	}

	bool is_open() const
	{
		return this->file.is_open();
	}

	void close()
	{
		this->sync();	
		this->file.close();
		this->definitions.clear();
	}

	void insert(const string& term, const string& explanation)
	{
		this->definitions[term] = explanation;	
	}

	string find(const string& term) const
	{
		string result;
		map<string, string>::const_iterator it;

		it = this->definitions.find(term);
		if (it != this->definitions.end())
			result = it->second;
		return result;
	}

protected:
	void sync()
	{
		map<string, string>::const_iterator it;
	
		if (!this->is_open()) return;
		for (it = this->definitions.begin(); it != 
				this->definitions.end(); ++it) {
			this->file << it->first << endl;
			this->file << it->second << endl;	
		}
	}

private:
	map<string, string> definitions;
	fstream file;
};

int main(int argc, char* argv[])
{
	dictionary d("definitions.txt");

	if (!d.is_open()) return 1;
	if (argc == 2) {
		cout << d.find(argv[1]) << endl;
	} else if (argc == 3) {
		d.insert(argv[1], argv[2]);
	}
	return 0;
}