#include <iostream>
#include<string>
#include<list>
#include <fstream>
using namespace std;

string sep[100][500];
int state;
string reserveWords[50];

int codeBreaker(string input, int count, int line) {
	//int state = 1;
	//string sep[100];
	//int count = 0;

	for (int i = 0; i < input.length(); i++) {
		if (state == 3 || state == 4 || state == 5) {
			count++;
			state = 1;
		}

		if (state == 1) {
			if (input.at(i) == ' ') {
				state = 4;
				continue;
			}

			else if (input.at(i) == ',' || input.at(i) == '(' || input.at(i) == ')' || input.at(i) == '[' || input.at(i) == ']' || input.at(i) == '{' || input.at(i) == '}' || input.at(i) == ';' || input.at(i) == '.') {
				if (i > 0) {

					if (input.at(i - 1) != ' ') {
						count++;
					}
				}
				sep[line][count].push_back(input.at(i));
				state = 4;
				continue;
			}

			

			else if (input.at(i) == '!' ) {
				if (i > 0) {

					if (input.at(i - 1) != ' ') {
						count++;
					}
				}
				if (input.length() - i > 1) {
					if (input.at(i + 1) == '=') {
						sep[line][count].push_back(input.at(i));
						sep[line][count].push_back(input.at(i + 1));
						i++;
						state = 4;
						continue;
					}
				}

				else {
					sep[line][count].push_back(input.at(i));
					state = 4;
					continue;
				}
			}

			else if (input.at(i) == '+') {

				if (i > 0) {

					if (input.at(i - 1) != ' ') {
						count++;
					}
				}
				if (input.length() - i > 1) {
					if (input.at(i + 1) == '+' || input.at(i + 1) == '=') {
						sep[line][count].push_back(input.at(i));
						sep[line][count].push_back(input.at(i + 1));
						i++;
						state = 4;
						continue;
					}
				}

				else {
					sep[line][count].push_back(input.at(i));
					state = 4;
					continue;
				}
			}

			else if (input.at(i) == '-') {

				if (i > 0) {

					if (input.at(i - 1) != ' ') {
						count++;
					}
				}

				if (input.length() - i > 1) {
					if (input.at(i + 1) == '-' || input.at(i + 1) == '=') {
						sep[line][count].push_back(input.at(i));
						sep[line][count].push_back(input.at(i + 1));
						i++;
						state = 4;
						continue;
					}
				}

				else {
					sep[line][count].push_back(input.at(i));
					state = 4;
					continue;
				}
			}

			else if (input.at(i) == '*') {

				if (i > 0) {

					if (input.at(i - 1) != ' ') {
						count++;
					}
				}

				if (input.length() - i > 1) {
					if (input.at(i + 1) == '=') {
						sep[line][count].push_back(input.at(i));
						sep[line][count].push_back(input.at(i + 1));
						i++;
						state = 4;
						continue;
					}
				}

				else {
					sep[line][count].push_back(input.at(i));
					state = 4;
					continue;
				}
			}

			else if (input.at(i) == '%') {

			    if (i > 0) {

				    if (input.at(i - 1) != ' ') {
					    count++;
				    }
			    
				}

				if (input.length() - i > 1) {
					if (input.at(i + 1) == '=') {
						sep[line][count].push_back(input.at(i));
						sep[line][count].push_back(input.at(i + 1));
						i++;
						state = 4;
						continue;
					}
				}

				else {
					sep[line][count].push_back(input.at(i));
					state = 4;
					continue;
				}
			}

			else if (input.at(i) == '<') {

			if (i > 0) {

				if (input.at(i - 1) != ' ') {
					count++;
				}
			}

			if (input.length() - i > 1) {
				if (input.at(i + 1) == '=' || input.at(i + 1) == '<') {
					sep[line][count].push_back(input.at(i));
					sep[line][count].push_back(input.at(i + 1));
					i++;
					state = 4;
					continue;
				}
			}

			else if (input.at(i) == '>') {

				if (i > 0) {

					if (input.at(i - 1) != ' ') {
						count++;
					}
				}

				if (input.length() - i > 1) {
					if (input.at(i + 1) == '=' || input.at(i + 1) == '>') {
						sep[line][count].push_back(input.at(i));
						sep[line][count].push_back(input.at(i + 1));
						i++;
						state = 4;
						continue;
					}
				}

				else {
					sep[line][count].push_back(input.at(i));
					state = 4;
					continue;
				}
			}

			else if (input.at(i) == '=') {

				if (i > 0) {

					if (input.at(i - 1) != ' ') {
						count++;
					}
				}

				if (input.length() - i > 1) {
					if (input.at(i + 1) == '=') {
						sep[line][count].push_back(input.at(i));
						sep[line][count].push_back(input.at(i + 1));
						i++;
						state = 4;
						continue;
					}
				}

				else {
					sep[line][count].push_back(input.at(i));
					state = 4;
					continue;
				}
			}

			else if (input.at(i) == '&') {

				if (i > 0) {

					if (input.at(i - 1) != ' ') {
						count++;
					}
				}

				if (input.length() - i > 1) {
					if (input.at(i + 1) == '&') {
						sep[line][count].push_back(input.at(i));
						sep[line][count].push_back(input.at(i + 1));
						i++;
						state = 4;
						continue;
					}
				}

				else {
					sep[line][count].push_back(input.at(i));
					state = 4;
					continue;
				}
			}

			else if (input.at(i) == '|') {

				if (i > 0) {

					if (input.at(i - 1) != ' ') {
						count++;
					}
				}

				if (input.length() - i > 1) {
					if (input.at(i + 1) == '|') {
						sep[line][count].push_back(input.at(i));
						sep[line][count].push_back(input.at(i + 1));
						i++;
						state = 4;
						continue;
					}
				}

				else {
					sep[line][count].push_back(input.at(i));
					state = 4;
					continue;
				}
			}

			

			    else {
				    sep[line][count].push_back(input.at(i));
				    state = 4;
				    continue;
			    }
			}

			else if (input.at(i) == '"') {
			    if (i > 0) {

				    if (input.at(i - 1) != ' ') {
					count++;
				    }
			    }
				sep[line][count].push_back(input.at(i));
				state = 2;
				continue;
			}

			else if (input.at(i) == '\'') {
			    if (i > 0) {

				    if (input.at(i - 1) != ' ') {
					count++;
				    }
			    }
				sep[line][count].push_back(input.at(i));
				state = 8;
				continue;
			}

			else if (input.at(i) == '/') {
			    if (i > 0) {

				    if (input.at(i - 1) != ' ') {
					count++;
				    }
			    }
			    if (input.at(i + 1) == '=') {
				    sep[line][count].push_back(input.at(i));
				    sep[line][count].push_back(input.at(i + 1));
				    i++;
				    state = 4;
				    continue;
			    }
				
			
			    else if (input.at(i + 1) == '*') {
					i++;
					state = 6;
				}
				else if (input.at(i + 1) == '/') {
					i++;
					state = 7;
				}
				else {
					sep[line][count].push_back(input.at(i));
					state = 4;
					
				}

				continue;
			}



			else {
				sep[line][count].push_back(input.at(i));
				continue;
			}

		}

		if (state == 2) {

			if (input.at(i) == '"') {
				sep[line][count].push_back(input.at(i));
				state = 3;
				continue;
			}
			else {
				sep[line][count].push_back(input.at(i));
				continue;
			}

		}

		if (state == 6) {
			if (input.at(i) == '*') {
				if (input.at(i + 1) == '/') {
					i++;
					state = 1;
				}


				continue;
			}

		}

		if (state == 7) {
			continue;

		}

		if (state == 8) {

			if (input.at(i) == '\'') {
				sep[line][count].push_back(input.at(i));
				state = 3;
				continue;
			}
			else {
				sep[line][count].push_back(input.at(i));
				continue;
			}

		}


	}



	return count;

}


int main() {
	int line = 0;
	cout << "Enter String:\n";
	string input;
	int count = 0;
	state = 1;
	//getline(cin, input);

	ifstream myfile("code.txt");
	while (getline(myfile, input)) {
		line++;
		count = codeBreaker(input, count, line);
		if (state != 2 && state != 8) {
			count++;
		}

		if (state == 7) {
			state = 1;
		}

	}

	cout << "\n";

	for (int j = 0; j < 100; j++) {
		for (int i = 0; i < 500; i++) {
			if (sep[j][i] != "") {
				cout << j << ", "<< sep[j][i] << "\n";
			}
		}
	}


	return 0;

}
