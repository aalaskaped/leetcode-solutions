class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> record;
        for (string op : operations)
{
    if (op == "C")
        record.pop_back();

    else if (op == "D")
        record.push_back(2 * record.back());

    else if (op == "+")
        record.push_back(record[record.size()-1] +
                         record[record.size()-2]);

    else
        record.push_back(stoi(op));
}

int sum = 0;
for(int i:record)
{
    sum += i;
}
   return sum; }
};
