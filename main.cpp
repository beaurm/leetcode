#include "solution.h"

// Usage:
//   leetcode               run the most recently edited solution
//   leetcode <query>       run the solution whose name contains <query> (e.g. "two-sum", "0004")
//   leetcode --list        list all solutions
int main(int argc, char** argv) {
    auto& all = registry::entries();
    if (all.empty()) {
        cerr << "No solutions registered." << endl;
        return 1;
    }
    ranges::sort(all, {}, &registry::Entry::name);

    if (argc > 1 && string(argv[1]) == "--list") {
        for (auto& e : all) cout << e.name << endl;
        return 0;
    }

    const registry::Entry* chosen = nullptr;

    if (argc > 1) {
        string query = argv[1];
        vector<const registry::Entry*> matches;
        for (auto& e : all) {
            if (e.name == query || e.name.ends_with("/" + query)) {
                matches = {&e};
                break;
            }
            if (e.name.find(query) != string::npos) matches.push_back(&e);
        }
        if (matches.size() != 1) {
            cerr << (matches.empty() ? "No solution matches \"" : "Ambiguous query \"") << query << "\"" << endl;
            for (auto* m : matches) cerr << "  " << m->name << endl;
            return 1;
        }
        chosen = matches[0];
    } else {
        auto mtime = [](const registry::Entry& e) {
            error_code ec;
            return filesystem::last_write_time(e.path, ec);
        };
        chosen = &*ranges::max_element(all, {}, mtime);
    }

    cout << "=== " << chosen->name << " ===" << endl;
    chosen->run();
    cout << endl;
    return 0;
}
