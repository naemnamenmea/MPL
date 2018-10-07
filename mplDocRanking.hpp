#pragma once
#ifndef __mplDocRanking__
#define __mplDocRanking__

#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <memory>
#include <fstream>
#include <map>
#include <unordered_map>

#include "mplAux.hpp"

typedef std::unordered_map<std::string, size_t> wordsFrequencyList;

struct FileRecord {
	std::string path;
	std::string hash;
	wordsFrequencyList wordsFreq;
};

class FileCollection {

public:	
	typedef std::map<std::size_t, std::string> SERP;

	void addFile(const std::string& pathToFile) {
		std::cout << SLS + "processing " << '\"' << pathToFile << '\"' << ". Please wait..." << std::endl;
		FileRecord wfl = parse(pathToFile);
		fileRecordList.push_back(wfl);
		std::cout << SLS + "done." << std::endl;
	}

	void addFilesInDir(const std::string& pathToDir) {
		std::vector<std::string> files = getDirectoryFiles(pathToDir);
		for (const auto& path : files) {
			addFile(path);
		}
	}

	SERP search(std::vector<std::string> keys) {
		SERP files;

		for (auto& doc : fileRecordList) {
			files.insert(std::make_pair(getValue(keys, doc.wordsFreq),doc.path));
		}

		return files;
	};

	//friend std::ostream& operator<<(std::ostream&, FileCollection&);

private:
	std::vector<std::string> words;
	std::vector<FileRecord> fileRecordList;
	//std::vector<FileRecord> wordsFrequencyTable;

	FileRecord parse(const std::string& path) {
		std::string word;
		std::ifstream ifs(path);
		FileRecord fr;
		wordsFrequencyList wfl;

		while (ifs >> word) {
			std::transform(word.begin(), word.end(), word.begin(), ::tolower);
			if (wfl.find(word) != wfl.end()) {
				++wfl[word];
			} else {
				wfl.insert(std::make_pair(word, 1));
			}
		}
		ifs.close();

		fr.path = path;
		fr.wordsFreq = wfl;

		return fr;
	}

	size_t getValue(std::vector < std::string > keys, wordsFrequencyList& wfl) {
		size_t value = 0;
		for (auto& word : keys) {
			value += wfl[word];
		}
		return value;
	}

	void Serialize(std::vector<FileRecord>& vfr) {
		std::ofstream os("mpl_words_frequency_table.csv");
		std::set<std::string> uniqueWords;

		os << "doc_name, hash";

		for (auto& fr : vfr) {
			for (auto& it = fr.wordsFreq.begin(); it != fr.wordsFreq.end(); ++it) {
				uniqueWords.insert(it->first);
			}
		}

		for (auto& word : uniqueWords) {
			os << ", " << word;
		}
		os << std::endl;

		for (auto& record : vfr) {
			os << record.path << ", " << record.hash;
			for (auto& word : uniqueWords) {
				os << ", " << record.wordsFreq[word];
			}
			os << std::endl;
		}

		os.close();
	}

	void deSerialize();

	//void Serialize(FileRecord& fr) {
	//	std::string path = dirnameOf(fr.path) + "\\" + filenameof(fr.path) + ".csv";
	//	std::ofstream os(fr.path);
	//}
	//
	//void deSerialize();

	//bool remDoc(std::string name);
	//void sort(std::string phrase);
};

#endif // __mplDocRanking__