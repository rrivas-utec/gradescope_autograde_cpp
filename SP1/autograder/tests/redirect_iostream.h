#ifndef REDIRECT_IOSTREAM_H
#define REDIRECT_IOSTREAM_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class redirect_iostream_t {
  ifstream in;
  stringstream out;
  streambuf* stream_buffer_cout; 
  streambuf* stream_buffer_cin;
  stringstream result;
  bool is_redirected = false;
public:
  explicit redirect_iostream_t(const string& in_filename): in{in_filename} { redirect(); }

  stringstream& operator >> (string& result) {
    getline(out, result);
    return out;
  }

  void redirect() {
    // Check if files cannot be oponed
    if (!in.is_open())
      throw runtime_error("in file cannot be opened");
    // Backup buffer
    stream_buffer_cin = cin.rdbuf();
    stream_buffer_cout = cout.rdbuf();
    // Redirect to file buffer
    cin.rdbuf(in.rdbuf());
    cout.rdbuf(out.rdbuf());
    // Flagged as redirected
    is_redirected = true;
  }
  void restore() {
    // Check if it was not redirected before
    if (!is_redirected) return;

    // Restore Buffers
    cin.rdbuf(stream_buffer_cin);
    cout.rdbuf(stream_buffer_cout);
    is_redirected = false;
  }

  ~redirect_iostream_t() {
    if (is_redirected) restore();
  }
};

#endif