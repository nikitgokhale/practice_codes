#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <sstream>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, q;
    string tmp = "", attr_name;
    map<string, string> mp;
    cin >> n >> q;
    cin.ignore();
    for(int i = 0; i < n; i++){
        string line, tag, extract;
        getline(cin, line);
        stringstream ss(line);
        // Process the HRML Lines
        while(getline(ss, extract, ' ')) {  // ' ' delimiter
            if (extract[0] == '<') {
                if (extract[1] != '/') {  // If it's an opening tag
                    tag = extract.substr(1);
                    // For tags without attribute
                    if(tag[tag.length() - 1] == '>'){
                        tag.pop_back();
                    }
                    // Check if any nesting is needed
                    if(tmp.size() > 0){ // Nest this tag
                        tmp += "." + tag;
                    }
                    else{
                        tmp = tag;
                    }
                }
                // If it's a closing tag
                else{
                    tag = extract.substr(2, (extract.find('>') - 2));
                    // Check if the nested tag has been closed
                    size_t pos = tmp.find("." + tag);
                    if (pos != string::npos) { // Remove the nested tag
                        tmp = tmp.substr(0, pos);
                    }
                    else{
                        tmp = "";
                    }
                }
            }
            // If it is an attribute value
            else if (extract[0] == '"') {
                size_t pos = extract.find_last_of('"');
                string attr_value = extract.substr(1, pos-1);
                // Add to the map
                mp[attr_name] = attr_value;
            }
            
            else {
                if(extract != "=") {
                    attr_name = tmp + "~" + extract;
                }
            }
        }
    }
    // Get the values of the query
    string query;
    for (int i = 0; i < q; i++) {
        getline(cin, query);
        // Search in map
        map<string, string>:: iterator it = mp.find(query);
        if (it != mp.end()) {
            cout << it->second << endl;
        }
        else {
            cout << "Not Found!" << endl;
        }
    }
    
    return 0;
}
 