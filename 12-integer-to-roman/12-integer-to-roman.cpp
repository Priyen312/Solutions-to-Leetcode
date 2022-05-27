class Solution {
public:
    string intToRoman(int num) {
    stack<pair<string,int>> s;
    s.push({"I",1});
    s.push({"IV",4});
    s.push({"V",5});
    s.push({"IX",9});
    s.push({"X",10});
    s.push({"XL",40});
    s.push({"L",50});
    s.push({"XC",90});
    s.push({"C",100});
    s.push({"CD",400});
    s.push({"D",500});
    s.push({"CM",900});
    s.push({"M",1000});
    string rom = "";
    int a = num;
    while(s.size())
    {
        auto t = s.top(); s.pop();
        string c = t.first;
        int n = t.second;

        if(a/n)
        {
            for(int i=0;i<(a/n);i++)
            {
                rom = rom + c;
            }
        }

        a = a%n;


    }
    return rom;

}
};