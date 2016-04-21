#ifndef STRING_PROCESS_H_TWO_INCLUDED
#define STRING_PROCESS_H_TWO_INCLUDED

#include <string>

template<class Container>//Container can be vector. "1  2"->1 and 2, not 1 and '' and 2.
void line_splice_2(const std::string& line,const char& delimiter,Container& item){
    std::string::size_type pos=line.find(delimiter);
    item.push_back(line.substr(0,pos));
    while(pos!=std::string::npos){
        std::string::size_type tmp;
        
        if(line[pos+1]==delimiter){
			pos++;
			continue;
		}
		
        item.push_back(line.substr(pos+1,tmp=line.find(delimiter,pos+1)-pos-1));
        pos =pos+1+tmp;
    }
}

#endif // STRING_PROCESS_H_TWO_INCLUDED
