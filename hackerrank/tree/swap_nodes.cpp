// https://www.hackerrank.com/challenges/swap-nodes-algo/problem
// tree, medium

#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int left = -1;
    int right = -1;
    int value;
};

void swapNode(int k, int node, int cur_depth, const unique_ptr<Node[]> &nodes)
{

    if (node < 1)
        return;

    if (cur_depth % k == 0)
    {
        // swap
        auto left = nodes[node].left;
        nodes[node].left = nodes[node].right;
        nodes[node].right = left;
    }

    swapNode(k, nodes[node].left, cur_depth + 1, nodes);
    swapNode(k, nodes[node].right, cur_depth + 1, nodes);
}

void in_order(vector<int> &result, const unique_ptr<Node[]> &nodes, int node)
{
    if (node < 1)
        return;

    in_order(result, nodes, nodes[node].left);
    result.push_back(node);
    in_order(result, nodes, nodes[node].right);
}

/*
 * Complete the swapNodes function below.
 */
vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries)
{
    /*
     * Write your code here.
     */

    const auto num_nodes = indexes.size();

    unique_ptr<Node[]> nodes(new Node[num_nodes + 1]);
    for (size_t i = 1; i < num_nodes + 1; ++i)
    {
        nodes[i].value = i;
        nodes[i].left = indexes[i - 1][0];
        nodes[i].right = indexes[i - 1][1];
    }

    vector<vector<int>> result;

    for (auto query : queries)
    {
        swapNode(query, 1, 1, nodes);
        vector<int> order;
        order.reserve(num_nodes);
        in_order(order, nodes, 1);
        result.emplace_back(order);
    }

    return result;
}

int main()
{
    // ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> indexes(n);
    for (int indexes_row_itr = 0; indexes_row_itr < n; indexes_row_itr++)
    {
        indexes[indexes_row_itr].resize(2);

        for (int indexes_column_itr = 0; indexes_column_itr < 2; indexes_column_itr++)
        {
            cin >> indexes[indexes_row_itr][indexes_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int queries_count;
    cin >> queries_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> queries(queries_count);

    for (int queries_itr = 0; queries_itr < queries_count; queries_itr++)
    {
        int queries_item;
        cin >> queries_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        queries[queries_itr] = queries_item;
    }

    vector<vector<int>> result = swapNodes(indexes, queries);

    for (int result_row_itr = 0; result_row_itr < result.size(); result_row_itr++)
    {
        for (int result_column_itr = 0; result_column_itr < result[result_row_itr].size(); result_column_itr++)
        {
            cout << result[result_row_itr][result_column_itr];

            if (result_column_itr != result[result_row_itr].size() - 1)
            {
                cout << " ";
            }
        }

        if (result_row_itr != result.size() - 1)
        {
            cout << "\n";
        }
    }

    cout << "\n";

    // fout.close();

    return 0;
}

// https://www.hackerrank.com/challenges/swap-nodes-algo/problem