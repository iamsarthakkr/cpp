string to_string(const bool& b);

string to_string(const char* s);

string to_string(const char& c);

string to_string(const string& str);

template <typename A, typename B>
string to_string(const pair<A, B>& p);

template <typename T>
string to_string(const vector<T>& a);

template<size_t t>
string to_string(const bitset<t>& a);

template <typename A>
string to_string(const A& a);

template <typename T, size_t sz>
string to_string(const array<T, sz>& a);

template <typename T, size_t sz>
string to_string(const array<T, sz>& a) {
   string res = "{";
	bool first = true;
	for (int i = 0; i < (int)sz; i++) {
		if (!first) res += ", ";
		first = false;
		res += to_string(a[i]);
	}
	res += "}";
	return res;
}

string to_string(const bool& b) {
	return (b ? "True" : "False");
}

string to_string(const string& str) {
	return '"' + str + '"';
}

string to_string(const char& c) {
	string res = "'";
	res.push_back(c);
	res += "'";
	return res;
}


string to_string(const char* s) {
	return to_string((string)s);
}

template<size_t t>
string to_string(const bitset<t>& a) {
   string res = "";
	for (int i = 0; i < (int)t; i++) {
      res += a[i] ? "1" : "0";
	}
	return '"' + res + '"';
}

template <typename T>
string to_string(const vector<T>& a) {
	string res = "{";
	bool first = true;
	for (int i = 0; i < (int)a.size(); i++) {
		if (!first) res += ", ";
		first = false;
		res += to_string(a[i]);
	}
	res += "}";
	return res;
}

template <typename A>
string to_string(const A& a) {
	string res = "{";
	bool first = true;
	for (const auto& x : a) {
		if (!first) res += ", ";
		first = false;
		res += to_string(x);
	}
	res += "}";
	return res;
}

template <typename A, typename B>
string to_string(const pair<A, B>& p) {
	return '(' + to_string(p.first) + ", " + to_string(p.second) + ")";
}


vector<string> vec_splitter(string s) {
	s += ',';
	vector<string> res;
	while(!s.empty()) {
		res.push_back(s.substr(0, s.find(',')));
		s = s.substr(s.find(',') + 1);
	}
	return res;
}

void debug_out(
vector<string> __attribute__ ((unused)) args,
__attribute__ ((unused)) int idx, 
__attribute__ ((unused)) int LINE_NUM) { cerr << endl; } 

template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
	if(idx > 0) cerr << ", "; else cerr << "Line(" << LINE_NUM << "): ";
	cerr << args[idx] << " = " << to_string(H);
	debug_out(args, idx + 1, LINE_NUM, T...);
}

#define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
