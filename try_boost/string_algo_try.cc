#include <boost/algorithm/string.hpp>
#include <string>
#include <list>

using namespace boost;

class WordsCounter {
public:
	enum{
		kNullResultListError,
		kNullInputStringError
	};
	
	WordsCounter(std::string* in) : _pString(in){
		;
	}
	
	int words(std::list<std::string>* resultList = NULL){
		
		if(_pString == NULL){
			return kNullInputStringError;
		}
		
		std::list<iterator_range<std::string::iterator> > l;
		split(l, *_pString, is_any_of(", ."));

		if(resultList != NULL){
			resultList->clear();
			for(std::list<iterator_range<std::string::iterator> >::iterator i = l.begin();
				i != l.end();
				i++){
				resultList->push_back(std::string((*i).begin(), (*i).end()));
			}
		}		
		return l.size();	
	}
	
	int reset(std::string* ps){
		_pString = ps;
	}
private:
	WordsCounter(const WordsCounter&);
	WordsCounter& operator=(const WordsCounter&);
	
	std::string* 	_pString;
};



int main(int argc, char* argv[]){
	
	using namespace std;
	
	string s("a,b,c d e");
	WordsCounter wc(&s);
	
	list<string> resultList;
	cout << wc.words(&resultList) << endl;
	
	list< string >::iterator i = resultList.begin();
	for(; i != resultList.end(); i++){
		cout << *i << endl;
	}
	
	return 0;
}
