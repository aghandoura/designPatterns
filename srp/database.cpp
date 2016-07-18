#include <string>
#include <vector>
#include <fstream>

//single responsability principle
//exp: save is moved outside of Database
class Database
{
public:
	friend class DatabaseManager;
	explicit Database(const std::string& title)
		:title {title}
	{}
	void add(const std::string entrie) {
		entries.push_back(entrie);
	}

private:
	std::string title;
	std::vector<std::string> entries;

};

// save is moved outside of Database
class DatabaseManager
{
public:
	static void save(const Database& d, const std::string filename) {
		std::ofstream ofs(filename);

		for (auto& e : d.entries) {
			ofs << e <<std::endl;
		}
	}

};

