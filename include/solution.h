#pragma once

#include <bits/stdc++.h>
using namespace std;

// Every solution file registers a run() function here at static-init time,
// so main.cpp never needs to know about individual solutions.
namespace registry {

struct Entry {
    string name;   // e.g. "leetcode/0001-two-sum"
    string path;   // absolute source path, used to find the most recently edited file
    void (*run)();
};

inline vector<Entry>& entries() {
    static vector<Entry> all;
    return all;
}

inline bool add(const char* file, void (*run)()) {
    filesystem::path p(file);
    entries().push_back({p.parent_path().filename().string() + "/" + p.stem().string(), p.string(), run});
    return true;
}

}  // namespace registry

#define REGISTER_SOLUTION(fn) static const bool registered_ = registry::add(__FILE__, fn)
