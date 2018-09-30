#pragma once
#ifndef __mplDocRanking__
#define __mplDocRanking__

#include <filesystem>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

typedef std::vector<std::string> stringvec;

struct path_leaf_string
{
	std::string operator()(const std::filesystem::directory_entry& entry) const
	{
		return entry.path().leaf().string();
	}
};

void read_directory(const std::string& name, stringvec& v)
{
	std::filesystem::path p(name);
	std::filesystem::directory_iterator start(p);
	std::filesystem::directory_iterator end;
	std::transform(start, end, std::back_inserter(v), path_leaf_string());
}

class Doc {
private:

public:
	Doc() {}
	bool read(std::string path);
};

class DocCollection {
private:
	std::vector<std::unique_ptr<Doc>> docs;
public:
	DocCollection(std::string path);
	bool addDoc(std::string path);
	bool remDoc(std::string name);
	void sort(std::string phrase);

	friend std::ostream& operator<<(std::ostream&, DocCollection&);

};

#endif // __mplDocRanking__