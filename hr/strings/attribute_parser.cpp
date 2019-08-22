#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <memory>
using namespace std;

struct Node
{
    map<string, unique_ptr<Node>> children;
    string tag;
    map<string, string> attributes;
    bool closed = false;
    Node *parent = nullptr;
};

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int n, q;
    cin >> n >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    auto split_string = [](string s) {
        s = s.substr(1, s.length() - 2);
        vector<string> splits;
        auto delimiter = ' ';
        size_t i = 0;
        size_t pos = s.find(delimiter);

        while (pos != string::npos)
        {
            splits.push_back(s.substr(i, pos - i));

            i = pos + 1;
            pos = s.find(delimiter, i);
        }

        splits.push_back(s.substr(i, min(pos, s.length()) - i + 1));
        return splits;
    };

    auto root = make_unique<Node>();
    root->tag = "root";

    auto curr = root.get();

    while (n-- > 0)
    {
        string s;
        getline(cin, s);

        const auto &splits = split_string(s);
        const auto &tag = splits[0];
        if (tag[0] == '/') // closing tag.
        {
            curr->closed = true;
            curr = curr->parent;
        }
        else // opening tag
        {
            auto new_node = make_unique<Node>();
            auto new_node_ptr = new_node.get();
            new_node->tag = tag;

            for (int i = 1; i < splits.size(); i += 3)
            {
                const auto &name = splits[i];
                const auto &value = splits[i + 2];
                new_node->attributes[name] = value.substr(1, value.length() - 2);
            }
            new_node->parent = curr;

            curr->children[tag] = move(new_node);
            curr = new_node_ptr;
        }
    }

    while (q-- > 0)
    {
        string s;
        getline(cin, s);

        auto att_pos = s.find('~');

        auto tags_str = s.substr(0, att_pos);
        auto attribute = s.substr(att_pos + 1);

        size_t i = 0;
        size_t pos = tags_str.find('.');
        vector<string> tags;
        while (pos != string::npos)
        {
            tags.push_back(tags_str.substr(i, pos - i));
            i = pos + 1;
            pos = tags_str.find('.', i);
        }
        tags.push_back(tags_str.substr(i, min(pos, tags_str.length()) - i + 1));

        curr = root.get();
        bool not_found = false;
        for (const auto &tag : tags)
        {
            auto child_itr = curr->children.find(tag);
            if (child_itr == curr->children.end())
            {
                not_found = true;
                break;
            }
            curr = child_itr->second.get();
        }

        auto attr_itr = curr->attributes.find(attribute);
        if (!not_found && attr_itr != curr->attributes.end())
        {
            cout << attr_itr->second << endl;
        }
        else
        {
            cout << "Not Found!" << endl;
        }
    }

    return 0;
}
