#include <string>
#include <vector>
#include <utility>

#include <iostream>

namespace cli {
using std::pair;
using std::vector;
using std::string;
using Flag = pair<string, string>;

static
pair<vector<Flag>, vector<string>>
cli_parse(const vector<string>& args){
	vector<Flag> flags;
	vector<string> regular;

	auto is_flag = [](const string& s) -> bool {
		if(s.size() < 2){ return false; }
		return s[0] == '-';
	};

	auto split_flag = [](const string& s) -> Flag {
		auto flag_end = s.find(':');
		if(flag_end != string::npos){
			return pair<string, string>(s.substr(1, flag_end - 1), s.substr(flag_end + 1, string::npos));
		} else {
			return pair<string, string>(s.substr(1), string{});
		}
	};

	for(auto&& arg : args){
		if(is_flag(arg)){
			std::cout << "'tis a flag: " << arg << '\n';
			flags.push_back(split_flag(arg));
		} else {
			std::cout << "'tis NOT a flag: " << arg << '\n';
			regular.push_back(arg);
		}
	}
	return pair<vector<Flag>, vector<string>>(std::move(flags), std::move(regular));
}
}

