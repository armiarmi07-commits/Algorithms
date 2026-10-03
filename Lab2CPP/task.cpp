#include <iostream>
#include <fstream>
#include "stack.h"
using namespace std;

string tip_tag(const string& tag) {
    string tag_name = "";
    size_t start = 0;

    if (!tag.empty() && tag[0] == '/') {
        start = 1;
    }

    for (size_t i = start; i < tag.size(); i++) {
        if (tag[i] == ' ' || tag[i] == '\t') {
            break;
        }
        tag_name += tag[i];
    }
    return tag_name;
}


int main(int argc, char* argv[]) {
    if (argc < 3) {
        return 1;
    }

    ifstream input(argv[1]);
    ofstream output(argv[2]);
    if (!input.is_open() || !output.is_open()) {
        return 1;
    }

    Stack* stack = stack_create();
    char ch;
    string current_tag = "";
    bool f = false;
    while (input.get(ch)) {
        if (ch == '<') {
            f = true;
            current_tag = "";
        }
        else if (ch == '>' && f) {
            f = false;
            if (!current_tag.empty() &&  current_tag[0] == '/') {
                if (stack_empty(stack) || (tip_tag(current_tag) != stack_get(stack)) ) {
                    output << "NO" << endl;
                    stack_delete(stack);
                    return 0;
                }
                stack_pop(stack);
            }
            else if (!current_tag.empty()) {
                stack_push(stack,tip_tag(current_tag));
            }

        }
        else if (f) {
            current_tag += ch;
        }
    }

    if (stack_empty(stack)) {
        output << "YES" << endl;
    }
    else {
        output << "NO" << endl;
    }
    stack_delete(stack);
}

