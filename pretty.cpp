#include <iostream>
#include <sstream>

std::string pretty(std::string& in) {
	std::stringstream out;
	if(in.empty()) return out.str();	
	char c = in[0];
	int indent = 0;
	int pos = 0;
	bool linebreak = true;
	while(pos < in.size()) {
		switch(c) {
			case '<': {
				out << " " << c;	//append < 
				//check if we should keep on going for short templates
				//find next > and <
				size_t next_end = in.find(">", pos);
				size_t next_start = in.find("<", (pos+1));
				//decide
				bool cond = ((next_start < next_end) || ((next_end - pos)>100));
				if(cond) {
					out << std::endl; 	//break line and increase indent
					++indent;
					for(int i=0; i<indent; ++i) out << "\t"; // indent n times
				} else {
					linebreak = false;
				}
				break;
			}; 
			case '>': {
				if(linebreak) {
					out << std::endl; 	//break line and decrease indent
					--indent;
					for(int i=0; i<indent; ++i) out << "\t"; // indent n times
				}	
				out << c;		//append >
				linebreak = true;
				break;
			};
			case ',': {
				out << c;
				if(linebreak) {
					out << std::endl;
					for(int i=0; i<indent; ++i) out << "\t"; // indent n times
				}
				break;
			};
			default : {
				out << c;		//just append 
				break;
			};
		}
		c = in[++pos];
	}
	return out.str();
}

int main() {
	std::string str;
	std::cout << "give me some templated type:\n";
	// lines
	std::string line;
	bool empty = false;
	while (!empty)
	{
		getline(std::cin, line);
		str += line;
		empty |= line.empty();
	}
	std::cout << "\n#####STARTING#####\n";
	std::cout << pretty(str) << std::endl;
	std::cout << "\n#####FINISHED#####\n"; 
	return 0;
}
