#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

static vector<char> ReadAllBytes(const string filename){
	
	ifstream ifs(filename, ios::binary|ios::ate);
	ifstream::pos_type pos = ifs.tellg();

	vector<char>  result(pos);

	ifs.seekg(0, ios::beg);
	ifs.read(&result[0], pos);

	return result;
}

void Output(vector<int> bytes, string out){
	
	int c;
	string s;

	if(out == "ascend"){
		for(int i = 0; i < 256; i++){
                	c = count(bytes.begin(), bytes.end(), i);
			s = to_string(c);
                	cout << setfill('0') << setw(2) <<  hex << uppercase << i << " : ";
			cout <<	s << endl;
		}
	}
	else if(out == "desc"){
		for(int i = 255; i >= 0; i--){
                        c = count(bytes.begin(), bytes.end(), i);
                        s = to_string(c);
			cout << setfill('0') << setw(2) <<  hex << uppercase << i << " : ";
			cout << s << endl;
                }
	}
}

int main(int args, char *argv[]){
	if(args > 3 || (args == 2 && string(argv[1]) != "--help") || args == 1){
		cout << "use --help to get information about program";
                return 0;
	}
	else if(args == 2 && string(argv[1]) == "--help"){
		cout << "Example :  ./my.prog FILENAME OUTPUTMETHOD" << endl;
		cout << "Output methods : desc, ascend" << endl;
		return 0;
	}
	else{
		string output;
                string fl;
                output = argv[2];
                fl = argv[1];
                vector<char> chars = ReadAllBytes(fl);
                vector<int> bytes;
                for(int i = 0; i < chars.size(); i++){
                        bytes.push_back(int(chars[i]));
                }
                Output(bytes, output);
		return 0;
	}

}
